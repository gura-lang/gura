//=============================================================================
// Gura module: diff
//=============================================================================
#ifndef __GURA_MODULE_DIFF_H__
#define __GURA_MODULE_DIFF_H__
#include <gura.h>
#include "dtl/dtl.hpp"

Gura_BeginModuleHeader(diff)

Gura_DeclareUserSymbol(add);
Gura_DeclareUserSymbol(copy);
Gura_DeclareUserSymbol(delete);
Gura_DeclareUserSymbol(distance);
Gura_DeclareUserSymbol(edits);
Gura_DeclareUserSymbol(lineno_at_org);
Gura_DeclareUserSymbol(lineno_at_new);
Gura_DeclareUserSymbol(mark);
Gura_DeclareUserSymbol(nlines_at_org);
Gura_DeclareUserSymbol(nlines_at_new);
Gura_DeclareUserSymbol(source);
Gura_DeclareUserSymbol(type);
Gura_DeclareUserSymbol(unified);

//-----------------------------------------------------------------------------
// Hunk
//-----------------------------------------------------------------------------
struct Hunk {
	size_t idxEditBegin;
	size_t idxEditEnd;
	size_t linenoOrg;
	size_t linenoNew;
	size_t nLinesOrg;
	size_t nLinesNew;
	String TextizeUnifiedRange() const;
};

//-----------------------------------------------------------------------------
// DiffString
//-----------------------------------------------------------------------------
class DiffString : public dtl::Diff<String> {
public:
	typedef sesElem Edit;
	typedef sesElemVec EditList;
public:
	inline DiffString() {}
	inline const EditList &GetEditList() const { return getSes().getSequence(); }
	static bool ReadLines(Signal sig, Stream &stream, std::vector<String> &seq);
	static void SplitLines(const char *src, std::vector<String> &seq);
	static String TextizeUnifiedEdit(const Edit &edit);
	static bool PrintEdit(Signal sig, Stream &stream, const Edit &edit);
	inline static const char *GetEditMark(const Edit &edit) {
		return
			(edit.second.type == dtl::SES_ADD)? "+" :
			(edit.second.type == dtl::SES_DELETE)? "-" : " ";
	}
};

//-----------------------------------------------------------------------------
// Result
//-----------------------------------------------------------------------------
class Result {
private:
	int _cntRef;
	DiffString _diffString;
public:
	Gura_DeclareReferenceAccessor(Result);
public:
	inline Result() : _cntRef(1) {}
protected:
	inline ~Result() {}
public:
	inline std::vector<String> &GetSeqA() { return _diffString.getA(); }
	inline std::vector<String> &GetSeqB() { return _diffString.getB(); }
	inline long long GetEditDistance() const { return _diffString.getEditDistance(); }
	void Process();
	bool PrintEdit(Signal sig, Stream &stream, size_t idxEdit);
	bool PrintEdits(Signal sig, Stream &stream) const;
	bool PrintHunk(Signal sig, Stream &stream, const Hunk &hunk) const;
	bool PrintHunks(Signal sig, Stream &stream, size_t nLinesCommon) const;
	bool NextHunk(size_t *pIdxEdit, size_t nLinesCommon, Hunk *pHunk) const;
	inline size_t CountEdits() const {
		return _diffString.GetEditList().size();
	}
	inline const DiffString::Edit &GetEdit(size_t idxEdit) const {
		return _diffString.GetEditList()[idxEdit];
	}
};

//-----------------------------------------------------------------------------
// Class declaration for diff.edit
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(edit);

class Object_edit : public Object {
private:
	AutoPtr<Result> _pResult;
	size_t _idxEdit;
public:
	Gura_DeclareObjectAccessor(edit)
public:
	inline Object_edit(Result *pResult, size_t idxEdit) :
		Object(Gura_UserClass(edit)), _pResult(pResult), _idxEdit(idxEdit) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	Result *GetResult() { return _pResult.get(); }
	size_t GetEditIndex() const { return _idxEdit; }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.result
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(result);

class Object_result : public Object {
private:
	AutoPtr<Result> _pResult;
public:
	Gura_DeclareObjectAccessor(result)
public:
	inline Object_result(Result *pResult) :
		Object(Gura_UserClass(result)), _pResult(pResult) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Result *GetResult() { return _pResult.get(); }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.hunk
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(hunk);

class Object_hunk : public Object {
private:
	AutoPtr<Result> _pResult;
	Hunk _hunk;
public:
	Gura_DeclareObjectAccessor(hunk)
public:
	inline Object_hunk(Result *pResult, const Hunk &hunk) :
		Object(Gura_UserClass(hunk)), _pResult(pResult), _hunk(hunk) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Result *GetResult() { return _pResult.get(); }
	inline const Hunk &GetHunk() const { return _hunk; }
};

//-----------------------------------------------------------------------------
// IteratorEdit
//-----------------------------------------------------------------------------
class IteratorEdit : public Iterator {
private:
	AutoPtr<Result> _pResult;
	size_t _idxEdit;
	size_t _idxEditBegin;
	size_t _idxEditEnd;
public:
	IteratorEdit(Result *pResult);
	IteratorEdit(Result *pResult, const Hunk &hunk);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// IteratorHunk
//-----------------------------------------------------------------------------
class IteratorHunk : public Iterator {
private:
	AutoPtr<Result> _pResult;
	size_t _idxEdit;
	size_t _nLinesCommon;
public:
	IteratorHunk(Result *pResult, size_t nLinesCommon);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleHeader(diff)

#endif
