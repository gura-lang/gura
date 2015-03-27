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
Gura_DeclareUserSymbol(edits);
Gura_DeclareUserSymbol(lineno_at_org);
Gura_DeclareUserSymbol(lineno_at_new);
Gura_DeclareUserSymbol(mark);
Gura_DeclareUserSymbol(nlines_at_org);
Gura_DeclareUserSymbol(nlines_at_new);
Gura_DeclareUserSymbol(source);
Gura_DeclareUserSymbol(type);

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
	String MakeRangeText() const;
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
};

//-----------------------------------------------------------------------------
// DiffEngine
//-----------------------------------------------------------------------------
class DiffEngine {
private:
	int _cntRef;
	DiffString _diffString;
public:
	Gura_DeclareReferenceAccessor(DiffEngine);
public:
	inline DiffEngine() : _cntRef(1) {}
protected:
	inline ~DiffEngine() {}
public:
	bool DiffStream(Signal sig, Stream &src1, Stream &src2);
	void DiffString(const char *src1, const char *src2);
	bool PrintEdits(Signal sig, Stream &stream) const;
	bool PrintHunk(Signal sig, Stream &stream, const Hunk &hunk) const;
	bool NextHunk(size_t *pIdxEdit, size_t nLinesCommon, Hunk *pHunk) const;
	inline size_t CountEdits() const {
		return _diffString.GetEditList().size();
	}
	inline const DiffString::Edit &GetEdit(size_t idxEdit) const {
		return _diffString.GetEditList()[idxEdit];
	}
	inline static const char *GetEditMark(const DiffString::Edit &edit) {
		return
			(edit.second.type == dtl::SES_ADD)? "+" :
			(edit.second.type == dtl::SES_DELETE)? "-" : " ";
	}
	inline static bool PrintEdit(Signal sig, Stream &stream,
								 const DiffString::Edit &edit) {
		stream.Print(sig, GetEditMark(edit));
		if (sig.IsSignalled()) return false;
		stream.Println(sig, edit.first.c_str());
		return !sig.IsSignalled();
	}
private:
	static bool ReadLines(Signal sig, Stream &stream, std::vector<String> &seq);
	static void SplitLines(const char *src, std::vector<String> &seq);
};

//-----------------------------------------------------------------------------
// Class declaration for diff.edit
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(edit);

class Object_edit : public Object {
private:
	AutoPtr<DiffEngine> _pDiffEngine;
	size_t _idxEdit;
public:
	Gura_DeclareObjectAccessor(edit)
public:
	inline Object_edit(DiffEngine *pDiffEngine, size_t idxEdit) :
		Object(Gura_UserClass(edit)), _pDiffEngine(pDiffEngine), _idxEdit(idxEdit) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for diff.hunk
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(hunk);

class Object_hunk : public Object {
private:
	AutoPtr<DiffEngine> _pDiffEngine;
	Hunk _hunk;
public:
	Gura_DeclareObjectAccessor(hunk)
public:
	inline Object_hunk(DiffEngine *pDiffEngine, const Hunk &hunk) :
		Object(Gura_UserClass(hunk)), _pDiffEngine(pDiffEngine), _hunk(hunk) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// IteratorEdit
//-----------------------------------------------------------------------------
class IteratorEdit : public Iterator {
private:
	AutoPtr<DiffEngine> _pDiffEngine;
	size_t _idxEdit;
	size_t _idxEditBegin;
	size_t _idxEditEnd;
public:
	IteratorEdit(DiffEngine *pDiffEngine);
	IteratorEdit(DiffEngine *pDiffEngine, const Hunk &hunk);
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
	AutoPtr<DiffEngine> _pDiffEngine;
	size_t _idxEdit;
	size_t _nLinesCommon;
public:
	IteratorHunk(DiffEngine *pDiffEngine, size_t nLinesCommon);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleHeader(diff)

#endif
