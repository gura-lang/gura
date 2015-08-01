//=============================================================================
// Gura module: diff
//=============================================================================
#ifndef __GURA_MODULE_DIFF_H__
#define __GURA_MODULE_DIFF_H__
#include <gura.h>
#include "dtl/dtl.hpp"

Gura_BeginModuleHeader(diff)

Gura_DeclareUserSymbol(add);
Gura_DeclareUserSymbol(change);
Gura_DeclareUserSymbol(context);
Gura_DeclareUserSymbol(copy);
Gura_DeclareUserSymbol(delete);
Gura_DeclareUserSymbol(diff_at_char);
Gura_DeclareUserSymbol(diff_at_line);
Gura_DeclareUserSymbol(distance);
Gura_DeclareUserSymbol(edits);
Gura_DeclareUserSymbol(edits_at_org);
Gura_DeclareUserSymbol(edits_at_new);
Gura_DeclareUserSymbol(lineno_at_org);
Gura_DeclareUserSymbol(lineno_at_new);
Gura_DeclareUserSymbol(mark_at_normal);
Gura_DeclareUserSymbol(mark_at_context);
Gura_DeclareUserSymbol(mark_at_unified);
Gura_DeclareUserSymbol(nlines_at_org);
Gura_DeclareUserSymbol(nlines_at_new);
Gura_DeclareUserSymbol(normal);
Gura_DeclareUserSymbol(source);
Gura_DeclareUserSymbol(sync);
Gura_DeclareUserSymbol(synclines_at_org);
Gura_DeclareUserSymbol(synclines_at_new);
Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(unified);

class DiffChar;

enum Target { TARGET_Org, TARGET_New };

//-----------------------------------------------------------------------------
// EditType
//-----------------------------------------------------------------------------
typedef dtl::edit_t EditType;

const EditType EDITTYPE_Delete	= dtl::SES_DELETE;	// -1
const EditType EDITTYPE_Copy	= dtl::SES_COMMON; 	// 0
const EditType EDITTYPE_Add		= dtl::SES_ADD;		// 1;
const EditType EDITTYPE_Change	= 2;

//-----------------------------------------------------------------------------
// FilterType
//-----------------------------------------------------------------------------
enum FilterType {
	FILTERTYPE_None,
	FILTERTYPE_Original,
	FILTERTYPE_New,
};

//-----------------------------------------------------------------------------
// ComparatorLine
//-----------------------------------------------------------------------------
class ComparatorLine {
private:
	bool _ignoreCaseFlag;
public:
	inline ComparatorLine() : _ignoreCaseFlag(false) {}
	inline void SetIgnoreCaseFlag(bool ignoreCaseFlag) { _ignoreCaseFlag = ignoreCaseFlag; }
	inline bool GetIgnoreCaseFlag() const { return _ignoreCaseFlag; }
	inline bool impl(const String &str1, const String &str2) const {
		return _ignoreCaseFlag?
			::strcasecmp(str1.c_str(), str2.c_str()) == 0 : str1 == str2;
	}
};

//-----------------------------------------------------------------------------
// ComparatorChar
//-----------------------------------------------------------------------------
class ComparatorChar {
private:
	bool _ignoreCaseFlag;
public:
	inline ComparatorChar() : _ignoreCaseFlag(false) {}
	inline void SetIgnoreCaseFlag(bool ignoreCaseFlag) { _ignoreCaseFlag = ignoreCaseFlag; }
	inline bool GetIgnoreCaseFlag() const { return _ignoreCaseFlag; }
	inline bool impl(UInt64 ch1, UInt64 ch2) const {
		if (_ignoreCaseFlag) {
			if ('a' <= ch1 && ch1 <= 'z') ch1 = ch1 - 'a' + 'A';
			if ('a' <= ch2 && ch2 <= 'z') ch2 = ch2 - 'a' + 'A';
		}
		return ch1 == ch2;
	}
};

//-----------------------------------------------------------------------------
// DiffLine
//-----------------------------------------------------------------------------
class DiffLine : public dtl::Diff<String, std::vector<String>, ComparatorLine> {
public:
	enum Format {
		FORMAT_None,
		FORMAT_Normal,
		FORMAT_Context,
		FORMAT_Unified,
	};
	struct Hunk {
	public:
		Format format;
		size_t idxEditBegin;
		size_t idxEditEnd;
		size_t linenoOrg;
		size_t linenoNew;
		size_t nLinesOrg;
		size_t nLinesNew;
	public:
		inline void Clear() { ::memset(this, 0x00, sizeof(Hunk)); }
		String TextizeRange_Normal() const;
		String TextizeRange_Context() const;
		String TextizeRange_Unified() const;
		inline bool IsAdd() const { return nLinesOrg == 0 && nLinesNew > 0; }
		inline bool IsDelete() const { return nLinesOrg > 0 && nLinesNew == 0; }
		inline bool IsChange() const { return nLinesOrg > 0 && nLinesNew > 0; }
	};
	typedef std::vector<String> Sequence;
	typedef sesElem Edit;
	typedef sesElemVec EditList;
public:
	class IteratorHunk : public Iterator {
	private:
		AutoPtr<DiffLine> _pDiffLine;
		size_t _idxEdit;
		Format _format;
		size_t _nLinesCommon;
	public:
		IteratorHunk(DiffLine *pDiffLine, Format format, size_t nLinesCommon);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorEdit : public Iterator {
	private:
		AutoPtr<DiffLine> _pDiffLine;
		size_t _idxEdit;
		size_t _idxEditBegin;
		size_t _idxEditEnd;
	public:
		IteratorEdit(DiffLine *pDiffLine);
		IteratorEdit(DiffLine *pDiffLine, const DiffLine::Hunk &hunk);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(DiffLine);
public:
	inline DiffLine(bool ignoreCaseFlag) : _cntRef(1) {
		cmp.SetIgnoreCaseFlag(ignoreCaseFlag);
	}
protected:
	inline ~DiffLine() {}
public:
	void Compose();
	bool PrintHunk(Signal &sig, SimpleStream &stream, const Hunk &hunk) const;
	bool PrintHunks(Signal &sig, SimpleStream &stream, Format format, size_t nLinesCommon) const;
	bool NextHunk(size_t *pIdxEdit, Format format, size_t nLinesCommon, Hunk *pHunk) const;
	void FeedString(size_t iSeq, const char *src);
	bool FeedStream(Signal &sig, size_t iSeq, Stream &stream);
	bool FeedIterator(Environment &env, Signal &sig, size_t iSeq, Iterator *pIterator);
	void FeedList(size_t iSeq, const ValueList &valList);
	DiffChar *CreateDiffChar(EditList::const_iterator pEditBegin,
							 EditList::const_iterator pEditEnd);
	DiffChar *CreateDiffChar(size_t idxEditBegin, size_t idxEditEnd);
	static String TextizeEdit_Normal(const Edit &edit);
	static String TextizeEdit_Unified(const Edit &edit);
	static Format SymbolToFormat(Signal &sig, const Symbol *pSymbol);
	inline bool GetIgnoreCaseFlag() const { return cmp.GetIgnoreCaseFlag(); }
	inline Sequence &GetSequence(size_t iSeq) { return (iSeq == 0)? getA() : getB(); }
	inline long long GetEditDistance() const { return getEditDistance(); }
	inline const EditList &GetEditList() const { return getSes().getSequence(); }
	inline const Edit &GetEdit(size_t idxEdit) const {
		return GetEditList()[idxEdit];
	}
	inline static const String &GetEditSource(const Edit &edit) {
		return edit.first;
	}
};

//-----------------------------------------------------------------------------
// DiffChar
//-----------------------------------------------------------------------------
class DiffChar : public dtl::Diff<UInt64, std::vector<UInt64>, ComparatorChar> {
public:
	typedef std::vector<UInt64> Sequence;
	class Edit {
	private:
		int _cntRef;
		EditType _editType;
		String _str;
	public:
		Gura_DeclareReferenceAccessor(Edit);
	public:
		inline Edit(EditType editType, const String &str) :
								_cntRef(1), _editType(editType), _str(str) {}
	protected:
		inline ~Edit() {}
	public:
		inline EditType GetEditType() const { return _editType; }
		inline const char *GetSource() const { return _str.c_str(); }
		inline bool IsEOL() const { return _str == "\n"; }
	};
	class EditList : public std::vector<Edit *> {
	};
	class EditOwner : public EditList {
	private:
		int _cntRef;
	public:
		Gura_DeclareReferenceAccessor(EditOwner);
	public:
		inline EditOwner() : _cntRef(1) {}
	protected:
		~EditOwner();
	public:
		void Clear();
	};
	class IteratorEdit : public Iterator {
	private:
		AutoPtr<EditOwner> _pEditOwner;
		FilterType _filterType;
		size_t _idxEdit;
		size_t _idxEditBegin;
		size_t _idxEditEnd;
	public:
		IteratorEdit(EditOwner *pEditOwner, FilterType filterType);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
private:
	int _cntRef;
	AutoPtr<EditOwner> _pEditOwner;
public:
	Gura_DeclareReferenceAccessor(DiffChar);
public:
	inline DiffChar(bool ignoreCaseFlag) : _cntRef(1), _pEditOwner(new EditOwner()) {
		cmp.SetIgnoreCaseFlag(ignoreCaseFlag);
	}
protected:
	inline ~DiffChar() {}
public:
	void Compose();
	void FeedChar(size_t iSeq, char ch);
	void FeedString(size_t iSeq, const char *src);
	inline bool GetIgnoreCaseFlag() const { return cmp.GetIgnoreCaseFlag(); }
	inline Sequence &GetSequence(size_t iSeq) { return (iSeq == 0)? getA() : getB(); }
	inline long long GetEditDistance() const { return getEditDistance(); }
	inline const EditOwner &GetEditOwner() const { return *_pEditOwner; }
	inline const Edit *GetEdit(size_t idxEdit) const {
		return GetEditOwner()[idxEdit];
	}
};

//-----------------------------------------------------------------------------
// SyncLine
//-----------------------------------------------------------------------------
class SyncLine {
private:
	int _cntRef;
	EditType _editType;
	AutoPtr<DiffChar::EditOwner> _pEditOwner;
public:
	Gura_DeclareReferenceAccessor(SyncLine);
public:
	inline SyncLine(EditType editType) : _cntRef(1),
		_editType(editType), _pEditOwner(new DiffChar::EditOwner()) {}
protected:
	inline ~SyncLine() {}
public:
	inline void AddEditChar(DiffChar::Edit *pEdit) { _pEditOwner->push_back(pEdit); }
	inline DiffChar::EditOwner &GetEditOwner() { return *_pEditOwner; }
};

class SyncLineList : public std::vector<SyncLine *> {
};

class SyncLineOwner : public SyncLineList {
public:
	~SyncLineOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Sync
//-----------------------------------------------------------------------------
class Sync {
public:
private:
	int _cntRef;
	SyncLineOwner _syncLinesOrg;
	SyncLineOwner _syncLinesNew;
public:
	Gura_DeclareReferenceAccessor(Sync);
public:
	inline Sync() : _cntRef(1) {}
protected:
	inline ~Sync() {}
public:
	void Compose(DiffLine *pDiffLine);
	SyncLineOwner &GetSyncLines(Target target) {
		return (target == TARGET_Org)? _syncLinesOrg : _syncLinesNew;
	}
};

//-----------------------------------------------------------------------------
// IteratorSyncLine
//-----------------------------------------------------------------------------
class IteratorSyncLine : public Iterator {
private:
	AutoPtr<Sync> _pSync;
	SyncLineOwner &_syncLines;
	size_t _idxSyncLine;
	size_t _idxSyncLineBegin;
	size_t _idxSyncLineEnd;
public:
	IteratorSyncLine(Sync *pSync, Target target);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Class declaration for diff.diff@line
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(diff_at_line);

class Object_diff_at_line : public Object {
private:
	AutoPtr<DiffLine> _pDiffLine;
public:
	Gura_DeclareObjectAccessor(diff_at_line)
public:
	inline Object_diff_at_line(DiffLine *pDiffLine) :
		Object(Gura_UserClass(diff_at_line)), _pDiffLine(pDiffLine) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline DiffLine *GetDiffLine() { return _pDiffLine.get(); }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.hunk@line
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(hunk_at_line);

class Object_hunk_at_line : public Object {
private:
	AutoPtr<DiffLine> _pDiffLine;
	DiffLine::Hunk _hunk;
	AutoPtr<DiffChar> _pDiffChar;
public:
	Gura_DeclareObjectAccessor(hunk_at_line)
public:
	inline Object_hunk_at_line(DiffLine *pDiffLine, const DiffLine::Hunk &hunk) :
		Object(Gura_UserClass(hunk_at_line)), _pDiffLine(pDiffLine), _hunk(hunk) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	const DiffChar *GetDiffChar();
	inline DiffLine *GetDiffLine() { return _pDiffLine.get(); }
	inline const DiffLine::Hunk &GetHunk() const { return _hunk; }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.edit@line
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(edit_at_line);

class Object_edit_at_line : public Object {
private:
	AutoPtr<DiffLine> _pDiffLine;
	size_t _idxEdit;
public:
	Gura_DeclareObjectAccessor(edit_at_line)
public:
	inline Object_edit_at_line(DiffLine *pDiffLine, size_t idxEdit) :
		Object(Gura_UserClass(edit_at_line)), _pDiffLine(pDiffLine), _idxEdit(idxEdit) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	DiffLine *GetDiffLine() { return _pDiffLine.get(); }
	const DiffLine::Edit &GetEdit() const { return _pDiffLine->GetEdit(_idxEdit); }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.diff@char
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(diff_at_char);

class Object_diff_at_char : public Object {
private:
	AutoPtr<DiffChar> _pDiffChar;
public:
	Gura_DeclareObjectAccessor(diff_at_char)
public:
	inline Object_diff_at_char(DiffChar *pDiffChar) :
		Object(Gura_UserClass(diff_at_char)), _pDiffChar(pDiffChar) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline DiffChar *GetDiffChar() { return _pDiffChar.get(); }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.edit@char
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(edit_at_char);

class Object_edit_at_char : public Object {
private:
	AutoPtr<DiffChar::Edit> _pEdit;
public:
	Gura_DeclareObjectAccessor(edit_at_char)
public:
	inline Object_edit_at_char(DiffChar::Edit *pEdit) :
		Object(Gura_UserClass(edit_at_char)), _pEdit(pEdit) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	DiffChar::Edit *GetEdit() { return _pEdit.get(); }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.sync
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(sync);

class Object_sync : public Object {
private:
	AutoPtr<Sync> _pSync;
public:
	Gura_DeclareObjectAccessor(sync)
public:
	inline Object_sync(Sync *pSync) : Object(Gura_UserClass(sync)), _pSync(pSync) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	Sync *GetSync() { return _pSync.get(); }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.syncline
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(syncline);

class Object_syncline : public Object {
private:
	AutoPtr<SyncLine> _pSyncLine;
public:
	Gura_DeclareObjectAccessor(syncline)
public:
	inline Object_syncline(SyncLine *pSyncLine) :
			Object(Gura_UserClass(syncline)), _pSyncLine(pSyncLine) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	SyncLine *GetSyncLine() { return _pSyncLine.get(); }
};

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
const char *GetEditMark_Normal(EditType editType);
const char *GetEditMark_Context(EditType editType);
const char *GetEditMark_Unified(EditType editType);

Gura_EndModuleHeader(diff)

#endif
