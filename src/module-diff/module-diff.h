//=============================================================================
// Gura module: diff
//=============================================================================
#ifndef __GURA_MODULE_DIFF_H__
#define __GURA_MODULE_DIFF_H__
#include <gura.h>
#include "dtl/dtl.hpp"

Gura_BeginModuleHeader(diff)

Gura_DeclareUserSymbol(add);
Gura_DeclareUserSymbol(context);
Gura_DeclareUserSymbol(copy);
Gura_DeclareUserSymbol(delete);
Gura_DeclareUserSymbol(distance);
Gura_DeclareUserSymbol(edits);
Gura_DeclareUserSymbol(lineno_at_org);
Gura_DeclareUserSymbol(lineno_at_new);
Gura_DeclareUserSymbol(mark);
Gura_DeclareUserSymbol(nlines_at_org);
Gura_DeclareUserSymbol(nlines_at_new);
Gura_DeclareUserSymbol(normal);
Gura_DeclareUserSymbol(source);
Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(unified);

//-----------------------------------------------------------------------------
// ComparatorLine
//-----------------------------------------------------------------------------
class ComparatorLine {
private:
	bool _ignoreCaseFlag;
public:
	inline ComparatorLine() : _ignoreCaseFlag(false) {}
	inline void SetIgnoreCaseFlag(bool ignoreCaseFlag) { _ignoreCaseFlag = ignoreCaseFlag; }
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
	inline bool impl(UInt64 ch1, UInt64 ch2) const {
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
		size_t idxEditBegin;
		size_t idxEditEnd;
		size_t linenoOrg;
		size_t linenoNew;
		size_t nLinesOrg;
		size_t nLinesNew;
	public:
		String TextizeUnifiedRange() const;
	};
	typedef std::vector<String> Sequence;
	typedef sesElem Edit;
	typedef sesElemVec EditList;
public:
	class IteratorHunk : public Iterator {
	private:
		AutoPtr<DiffLine> _pDiffLine;
		size_t _idxEdit;
		size_t _nLinesCommon;
	public:
		IteratorHunk(DiffLine *pDiffLine, size_t nLinesCommon);
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
	static bool PrintEdit(Signal sig, SimpleStream &stream, const Edit &edit);
	bool PrintEdit(Signal sig, SimpleStream &stream, size_t idxEdit);
	bool PrintEdits(Signal sig, SimpleStream &stream) const;
	bool PrintHunk(Signal sig, SimpleStream &stream,
				   Format format, const Hunk &hunk) const;
	bool PrintHunks(Signal sig, SimpleStream &stream,
					Format format, size_t nLinesCommon) const;
	bool NextHunk(size_t *pIdxEdit, size_t nLinesCommon, Hunk *pHunk) const;
	void FeedString(size_t idx, const char *src);
	bool FeedStream(Signal sig, size_t idx, Stream &stream);
	bool FeedIterator(Environment &env, Signal sig, size_t idx, Iterator *pIterator);
	void FeedList(size_t idx, const ValueList &valList);
	static String TextizeUnifiedEdit(const Edit &edit);
	static Format SymbolToFormat(Signal sig, const Symbol *pSymbol);
	inline Sequence &GetSequence(size_t idx) { return (idx == 0)? getA() : getB(); }
	inline long long GetEditDistance() const { return getEditDistance(); }
	inline const EditList &GetEditList() const { return getSes().getSequence(); }
	inline const Edit &GetEdit(size_t idxEdit) const {
		return GetEditList()[idxEdit];
	}
	inline static const char *GetEditMark(const Edit &edit) {
		return
			(edit.second.type == dtl::SES_ADD)? "+" :
			(edit.second.type == dtl::SES_DELETE)? "-" : " ";
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
	enum FilterType {
		FILTER_None,
		FILTER_Original,
		FILTER_New,
	};
	typedef std::vector<UInt64> Sequence;
	class Edit {
	private:
		dtl::edit_t _type;
		String _str;
	public:
		inline Edit(dtl::edit_t type, const String &str) : _type(type), _str(str) {}
		inline dtl::edit_t GetType() const { return _type; }
		inline const char *GetSource() const { return _str.c_str(); }
		inline const char *GetMark() const {
			return
				(_type == dtl::SES_ADD)? "+" :
				(_type == dtl::SES_DELETE)? "-" : " ";
		}
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
	void FeedString(size_t idx, const char *src);
	inline Sequence &GetSequence(size_t idx) { return (idx == 0)? getA() : getB(); }
	inline long long GetEditDistance() const { return getEditDistance(); }
	inline const EditList &GetEditList() const { return _editList; }
	inline const Edit &GetEdit(size_t idxEdit) const {
		return GetEditList()[idxEdit];
	}
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
	size_t GetEditIndex() const { return _idxEdit; }
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

Gura_EndModuleHeader(diff)

#endif
