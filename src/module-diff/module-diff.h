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
Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(unified);

class DiffChar;

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
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
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
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
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
	bool PrintHunk(Signal sig, SimpleStream &stream, const Hunk &hunk) const;
	bool PrintHunks(Signal sig, SimpleStream &stream, Format format, size_t nLinesCommon) const;
	bool NextHunk(size_t *pIdxEdit, Format format, size_t nLinesCommon, Hunk *pHunk) const;
	void FeedString(size_t iSeq, const char *src);
	bool FeedStream(Signal sig, size_t iSeq, Stream &stream);
	bool FeedIterator(Environment &env, Signal sig, size_t iSeq, Iterator *pIterator);
	void FeedList(size_t iSeq, const ValueList &valList);
	DiffChar *CreateDiffChar(size_t idxEditBegin, size_t idxEditEnd);
	static String TextizeEdit_Normal(const Edit &edit);
	static String TextizeEdit_Unified(const Edit &edit);
	static Format SymbolToFormat(Signal sig, const Symbol *pSymbol);
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
		EditType _editType;
		String _str;
	public:
		inline Edit(EditType editType, const String &str) : _editType(editType), _str(str) {}
		inline EditType GetEditType() const { return _editType; }
		inline const char *GetSource() const { return _str.c_str(); }
		inline bool IsEOL() const { return _str == "\n"; }
	};
	typedef std::vector<Edit> EditList;
	class IteratorEdit : public Iterator {
	private:
		AutoPtr<DiffChar> _pDiffChar;
		FilterType _filterType;
		size_t _idxEdit;
		size_t _idxEditBegin;
		size_t _idxEditEnd;
	public:
		IteratorEdit(DiffChar *pDiffChar, FilterType filterType);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
private:
	int _cntRef;
	EditList _editList;
public:
	Gura_DeclareReferenceAccessor(DiffChar);
public:
	inline DiffChar(bool ignoreCaseFlag) : _cntRef(1) {
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
	inline const EditList &GetEditList() const { return _editList; }
	inline const Edit &GetEdit(size_t idxEdit) const {
		return GetEditList()[idxEdit];
	}
};

//-----------------------------------------------------------------------------
// DiffCharList
//-----------------------------------------------------------------------------
class DiffCharList : public std::vector<DiffChar *> {
};

//-----------------------------------------------------------------------------
// DiffCharOwner
//-----------------------------------------------------------------------------
class DiffCharOwner : public DiffCharList {
public:
	~DiffCharOwner();
	void Clear();
};

//-----------------------------------------------------------------------------
// Sync
//-----------------------------------------------------------------------------
class Sync {
private:
	int _cntRef;
	DiffCharOwner _diffCharOwner;
public:
	Gura_DeclareReferenceAccessor(Sync);
public:
	inline Sync() : _cntRef(1) {}
protected:
	inline ~Sync() {}
public:
	inline DiffCharOwner &GetDiffCharOwner() { return _diffCharOwner; }
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
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
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
	AutoPtr<DiffChar> _pDiffChar;
	size_t _idxEdit;
public:
	Gura_DeclareObjectAccessor(edit_at_char)
public:
	inline Object_edit_at_char(DiffChar *pDiffChar, size_t idxEdit) :
		Object(Gura_UserClass(edit_at_char)), _pDiffChar(pDiffChar), _idxEdit(idxEdit) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	DiffChar *GetDiffChar() { return _pDiffChar.get(); }
	size_t GetEditIndex() const { return _idxEdit; }
};

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
const char *GetEditMark_Normal(EditType editType);
const char *GetEditMark_Context(EditType editType);
const char *GetEditMark_Unified(EditType editType);

Gura_EndModuleHeader(diff)

#endif
