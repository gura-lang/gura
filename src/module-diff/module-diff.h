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
// SequenceLine
//-----------------------------------------------------------------------------
typedef std::vector<String> SequenceLine;

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
// HunkLine
//-----------------------------------------------------------------------------
struct HunkLine {
public:
	enum Format {
		FORMAT_None,
		FORMAT_Normal,
		FORMAT_Context,
		FORMAT_Unified,
	};
public:
	size_t idxEditBegin;
	size_t idxEditEnd;
	size_t linenoOrg;
	size_t linenoNew;
	size_t nLinesOrg;
	size_t nLinesNew;
public:
	String TextizeUnifiedRange() const;
	static Format SymbolToFormat(Signal sig, const Symbol *pSymbol);
};

//-----------------------------------------------------------------------------
// DiffLine
//-----------------------------------------------------------------------------
class DiffLine : public dtl::Diff<String, SequenceLine, ComparatorLine> {
public:
	typedef sesElem Edit;
	typedef sesElemVec EditList;
public:
	inline DiffLine(bool ignoreCaseFlag) {
		cmp.SetIgnoreCaseFlag(ignoreCaseFlag);
	}
	inline const EditList &GetEditList() const { return getSes().getSequence(); }
	static void FeedString(SequenceLine &seq, const char *src);
	static bool FeedStream(Signal sig, SequenceLine &seq, Stream &stream);
	static bool FeedIterator(Environment &env, Signal sig,
							 SequenceLine &seq, Iterator *pIterator);
	static void FeedList(SequenceLine &seq, const ValueList &valList);
	static String TextizeUnifiedEdit(const Edit &edit);
	static bool PrintEdit(Signal sig, SimpleStream &stream, const Edit &edit);
	inline static const char *GetEditMark(const Edit &edit) {
		return
			(edit.second.type == dtl::SES_ADD)? "+" :
			(edit.second.type == dtl::SES_DELETE)? "-" : " ";
	}
};

//-----------------------------------------------------------------------------
// ResultLine
//-----------------------------------------------------------------------------
class ResultLine {
private:
	int _cntRef;
	DiffLine _diffLine;
public:
	Gura_DeclareReferenceAccessor(ResultLine);
public:
	inline ResultLine(bool ignoreCaseFlag) : _cntRef(1), _diffLine(ignoreCaseFlag) {}
protected:
	inline ~ResultLine() {}
public:
	inline long long GetEditDistance() const { return _diffLine.getEditDistance(); }
	inline SequenceLine &GetSeq(size_t idx) {
		return (idx == 0)? _diffLine.getA() : _diffLine.getB();
	}
	void Compose();
	bool PrintEdit(Signal sig, SimpleStream &stream, size_t idxEdit);
	bool PrintEdits(Signal sig, SimpleStream &stream) const;
	bool PrintHunkLine(Signal sig, SimpleStream &stream,
				   HunkLine::Format format, const HunkLine &hunkLine) const;
	bool PrintHunkLines(Signal sig, SimpleStream &stream,
					HunkLine::Format format, size_t nLinesCommon) const;
	bool NextHunkLine(size_t *pIdxEdit, size_t nLinesCommon, HunkLine *pHunkLine) const;
	inline size_t CountEdits() const {
		return _diffLine.GetEditList().size();
	}
	inline const DiffLine::Edit &GetEdit(size_t idxEdit) const {
		return _diffLine.GetEditList()[idxEdit];
	}
};

//-----------------------------------------------------------------------------
// Class declaration for diff.edit
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(edit);

class Object_edit : public Object {
private:
	AutoPtr<ResultLine> _pResultLine;
	size_t _idxEdit;
public:
	Gura_DeclareObjectAccessor(edit)
public:
	inline Object_edit(ResultLine *pResultLine, size_t idxEdit) :
		Object(Gura_UserClass(edit)), _pResultLine(pResultLine), _idxEdit(idxEdit) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	ResultLine *GetResultLine() { return _pResultLine.get(); }
	size_t GetEditIndex() const { return _idxEdit; }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.result
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(result);

class Object_result : public Object {
private:
	AutoPtr<ResultLine> _pResultLine;
public:
	Gura_DeclareObjectAccessor(result)
public:
	inline Object_result(ResultLine *pResultLine) :
		Object(Gura_UserClass(result)), _pResultLine(pResultLine) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline ResultLine *GetResultLine() { return _pResultLine.get(); }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.hunk
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(hunk);

class Object_hunk : public Object {
private:
	AutoPtr<ResultLine> _pResultLine;
	HunkLine _hunkLine;
public:
	Gura_DeclareObjectAccessor(hunk)
public:
	inline Object_hunk(ResultLine *pResultLine, const HunkLine &hunkLine) :
		Object(Gura_UserClass(hunk)), _pResultLine(pResultLine), _hunkLine(hunkLine) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline ResultLine *GetResultLine() { return _pResultLine.get(); }
	inline const HunkLine &GetHunkLine() const { return _hunkLine; }
};

//-----------------------------------------------------------------------------
// IteratorEdit
//-----------------------------------------------------------------------------
class IteratorEdit : public Iterator {
private:
	AutoPtr<ResultLine> _pResultLine;
	size_t _idxEdit;
	size_t _idxEditBegin;
	size_t _idxEditEnd;
public:
	IteratorEdit(ResultLine *pResultLine);
	IteratorEdit(ResultLine *pResultLine, const HunkLine &hunkLine);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// IteratorHunkLine
//-----------------------------------------------------------------------------
class IteratorHunkLine : public Iterator {
private:
	AutoPtr<ResultLine> _pResultLine;
	size_t _idxEdit;
	size_t _nLinesCommon;
public:
	IteratorHunkLine(ResultLine *pResultLine, size_t nLinesCommon);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleHeader(diff)

#endif
