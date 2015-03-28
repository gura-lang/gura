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
// Processor
//-----------------------------------------------------------------------------
class Processor {
private:
	int _cntRef;
	DiffString _diffString;
public:
	Gura_DeclareReferenceAccessor(Processor);
public:
	inline Processor() : _cntRef(1) {}
protected:
	inline ~Processor() {}
public:
	bool ProcessStream(Signal sig, Stream &src1, Stream &src2);
	void ProcessString(const char *src1, const char *src2);
	static bool PrintEdit(Signal sig, Stream &stream, const DiffString::Edit &edit);
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
	inline static const char *GetEditMark(const DiffString::Edit &edit) {
		return
			(edit.second.type == dtl::SES_ADD)? "+" :
			(edit.second.type == dtl::SES_DELETE)? "-" : " ";
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
	AutoPtr<Processor> _pProcessor;
	size_t _idxEdit;
public:
	Gura_DeclareObjectAccessor(edit)
public:
	inline Object_edit(Processor *pProcessor, size_t idxEdit) :
		Object(Gura_UserClass(edit)), _pProcessor(pProcessor), _idxEdit(idxEdit) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

//-----------------------------------------------------------------------------
// Class declaration for diff.processor
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(processor);

class Object_processor : public Object {
private:
	AutoPtr<Processor> _pProcessor;
public:
	Gura_DeclareObjectAccessor(processor)
public:
	inline Object_processor(Processor *pProcessor) :
		Object(Gura_UserClass(processor)), _pProcessor(pProcessor) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Processor *GetProcessor() { return _pProcessor.get(); }
};

//-----------------------------------------------------------------------------
// Class declaration for diff.hunk
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(hunk);

class Object_hunk : public Object {
private:
	AutoPtr<Processor> _pProcessor;
	Hunk _hunk;
public:
	Gura_DeclareObjectAccessor(hunk)
public:
	inline Object_hunk(Processor *pProcessor, const Hunk &hunk) :
		Object(Gura_UserClass(hunk)), _pProcessor(pProcessor), _hunk(hunk) {}
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
	AutoPtr<Processor> _pProcessor;
	size_t _idxEdit;
	size_t _idxEditBegin;
	size_t _idxEditEnd;
public:
	IteratorEdit(Processor *pProcessor);
	IteratorEdit(Processor *pProcessor, const Hunk &hunk);
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
	AutoPtr<Processor> _pProcessor;
	size_t _idxEdit;
	size_t _nLinesCommon;
public:
	IteratorHunk(Processor *pProcessor, size_t nLinesCommon);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleHeader(diff)

#endif
