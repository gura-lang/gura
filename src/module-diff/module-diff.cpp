//=============================================================================
// Gura module: diff
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(diff)

//-----------------------------------------------------------------------------
// DiffEngine
//-----------------------------------------------------------------------------
bool DiffEngine::DiffStream(Signal sig, Stream &src1, Stream &src2)
{
	if (!ReadLines(sig, src1, _diffString.getA())) return false;
	if (!ReadLines(sig, src2, _diffString.getB())) return false;
	_diffString.init();
	_diffString.onHuge();
	_diffString.compose();
	return true;
}

bool DiffEngine::PrintEdits(Signal sig, Stream &stream) const
{
	foreach_const (DiffString::EditList, pEdit, _diffString.GetEditList()) {
		if (!PrintEdit(sig, stream, *pEdit)) return false;
	}
	return true;
}

bool DiffEngine::PrintEditsInHunk(Signal sig, Stream &stream, const Hunk &hunk) const
{
	const DiffString::EditList &edits = _diffString.GetEditList();
	DiffString::EditList::const_iterator pEdit = edits.begin() + hunk.idxEditBegin;
	DiffString::EditList::const_iterator pEditEnd = edits.begin() + hunk.idxEditEnd;
	for ( ; pEdit != pEditEnd; pEdit++) {
		if (!PrintEdit(sig, stream, *pEdit)) return false;
	}
	return true;
}

bool DiffEngine::ReadLines(Signal sig, Stream &src, std::vector<String> &seq)
{
	bool includeEOLFlag = true;
	for (;;) {
		String str;
		if (!src.ReadLine(sig, str, includeEOLFlag)) break;
		seq.push_back(str);
	}
	return !sig.IsSignalled();
}

bool DiffEngine::NextHunk(size_t *pIdxEdit, size_t nLinesCommon, Hunk *pHunk) const
{
	size_t &idxEdit = *pIdxEdit;
	size_t nEdits = CountEdits();
	if (idxEdit >= nEdits) return false;
	size_t nLines = 0;
	size_t idxEditTop = idxEdit;
	for ( ; idxEdit < nEdits; idxEdit++) {
		const DiffString::Edit &edit = GetEdit(idxEdit);
		if (edit.second.type == dtl::SES_COMMON) continue;
		pHunk->idxEditBegin = (idxEdit > idxEditTop + nLinesCommon)?
			idxEdit - nLinesCommon : idxEditTop;
		idxEdit++;
		for ( ; idxEdit < nEdits; idxEdit++) {
			const DiffString::Edit &edit = GetEdit(idxEdit);
			if (edit.second.type == dtl::SES_COMMON) {
				nLines++;
				if (nLines >= nLinesCommon * 2) {
					idxEdit = idxEdit + 1 - nLinesCommon;
					break;
				}
			} else {
				nLines = 0;
			}
		}
		pHunk->idxEditEnd = idxEdit;
		pHunk->linenoOrg = pHunk->linenoNew = 0;
		pHunk->nLinesOrg = pHunk->nLinesNew = 0;
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
// Object_edit
//-----------------------------------------------------------------------------
Object *Object_edit::Clone() const
{
	return NULL;
}

bool Object_edit::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(mark));
	symbols.insert(Gura_UserSymbol(lineno_at_org));
	symbols.insert(Gura_UserSymbol(lineno_at_new));
	symbols.insert(Gura_UserSymbol(source));
	return false;
}

Value Object_edit::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	const DiffString::Edit &edit = _pDiffEngine->GetEdit(_idxEdit);
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		if (edit.second.type == dtl::SES_ADD) {
			return Value(Gura_UserSymbol(add));
		} else if (edit.second.type == dtl::SES_DELETE) {
			return Value(Gura_UserSymbol(delete));
		} else {
			return Value(Gura_UserSymbol(copy));
		}
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mark))) {
		return Value(DiffEngine::GetEditMark(edit));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lineno_at_org))) {
		return Value(edit.second.beforeIdx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lineno_at_new))) {
		return Value(edit.second.afterIdx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(source))) {
		return Value(edit.first);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_edit::ToString(bool exprFlag)
{
	String str;
	str += "<diff.edit>";
	return str;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.edit
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(edit)
{
}

//-----------------------------------------------------------------------------
// Object_hunk
//-----------------------------------------------------------------------------
Object *Object_hunk::Clone() const
{
	return NULL;
}

bool Object_hunk::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(edits));
	return false;
}

Value Object_hunk::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(edits))) {
		AutoPtr<Iterator> pIterator(new IteratorEdit(_pDiffEngine->Reference(), _hunk));
		return Value(new Object_iterator(env, pIterator.release()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_hunk::ToString(bool exprFlag)
{
	String str;
	str += "<diff.hunk>";
	return str;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.hunk
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(hunk)
{
}

//-----------------------------------------------------------------------------
// IteratorEdit
//-----------------------------------------------------------------------------
IteratorEdit::IteratorEdit(DiffEngine *pDiffEngine) :
	Iterator(false), _pDiffEngine(pDiffEngine),
	_idxEdit(0), _idxEditBegin(0), _idxEditEnd(pDiffEngine->CountEdits())
{
}

IteratorEdit::IteratorEdit(DiffEngine *pDiffEngine, const Hunk &hunk) :
	Iterator(false), _pDiffEngine(pDiffEngine),
	_idxEdit(hunk.idxEditBegin), _idxEditBegin(hunk.idxEditBegin), _idxEditEnd(hunk.idxEditEnd)
{
}

Iterator *IteratorEdit::GetSource()
{
	return NULL;
}

bool IteratorEdit::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idxEdit >= _idxEditEnd) return false;
	value = Value(new Object_edit(_pDiffEngine->Reference(), _idxEdit));
	_idxEdit++;
	return true;
}

String IteratorEdit::ToString() const
{
	String str;
	str += "diff.edit";
	return str;
}

void IteratorEdit::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// IteratorHunk
//-----------------------------------------------------------------------------
IteratorHunk::IteratorHunk(DiffEngine *pDiffEngine, size_t nLinesCommon) :
	Iterator(false), _pDiffEngine(pDiffEngine), _idxEdit(0), _nLinesCommon(nLinesCommon)
{
}

Iterator *IteratorHunk::GetSource()
{
	return NULL;
}

bool IteratorHunk::DoNext(Environment &env, Signal sig, Value &value)
{
	Hunk hunk;
	if (_pDiffEngine->NextHunk(&_idxEdit, _nLinesCommon, &hunk)) {
		value = Value(new Object_hunk(_pDiffEngine->Reference(), hunk));
		return true;
	}
	return false;
}

String IteratorHunk::ToString() const
{
	String str;
	str += "diff.hunk";
	return str;
}

void IteratorHunk::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// diff.diff@stream(src1:stream, src2:stream, out?:stream:w) {block?}
Gura_DeclareFunctionAlias(diff_at_stream, "diff@stream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src1", VTYPE_stream);
	DeclareArg(env, "src2", VTYPE_stream);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(diff_at_stream)
{
	AutoPtr<DiffEngine> pDiffEngine(new DiffEngine());
	if (!pDiffEngine->DiffStream(sig, args.GetStream(0), args.GetStream(1))) return Value::Null;
	if (args.IsValid(2)) {
		pDiffEngine->PrintEdits(sig, args.GetStream(2));
		return Value::Null;
	} else {
		AutoPtr<IteratorEdit> pIterator(new IteratorEdit(pDiffEngine->Reference()));
		return ReturnIterator(env, sig, args, pIterator.release());
	}
}

// diff.unidiff@stream(src1:stream, src2:stream, out?:stream:w, lines?:number) {block?}
Gura_DeclareFunctionAlias(unidiff_at_stream, "unidiff@stream")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src1", VTYPE_stream);
	DeclareArg(env, "src2", VTYPE_stream);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(unidiff_at_stream)
{
	AutoPtr<DiffEngine> pDiffEngine(new DiffEngine());
	if (!pDiffEngine->DiffStream(sig, args.GetStream(0), args.GetStream(1))) return Value::Null;
	size_t nLinesCommon = args.IsValid(3)? args.GetSizeT(3) : 3;
	if (args.IsValid(2)) {
		Stream &streamOut = args.GetStream(2);
		size_t idxEdit = 0;
		Hunk hunk;
		while (pDiffEngine->NextHunk(&idxEdit, nLinesCommon, &hunk)) {
			::printf("********\n");
			if (!pDiffEngine->PrintEditsInHunk(sig, streamOut, hunk)) {
				break;
			}
		}
		return Value::Null;
	}
	AutoPtr<IteratorHunk> pIterator(new IteratorHunk(pDiffEngine->Reference(), nLinesCommon));
	return ReturnIterator(env, sig, args, pIterator.release());
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(add);
	Gura_RealizeUserSymbol(copy);
	Gura_RealizeUserSymbol(delete);
	Gura_RealizeUserSymbol(edits);
	Gura_RealizeUserSymbolAlias(lineno_at_org, "lineno@org");
	Gura_RealizeUserSymbolAlias(lineno_at_new, "lineno@new");
	Gura_RealizeUserSymbol(mark);
	Gura_RealizeUserSymbol(source);
	Gura_RealizeUserSymbol(type);
	// class realization
	Gura_RealizeUserClass(edit, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(hunk, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(diff_at_stream);
	Gura_AssignFunction(unidiff_at_stream);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(diff, diff)

Gura_RegisterModule(diff)
