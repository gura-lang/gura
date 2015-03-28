//=============================================================================
// Gura module: diff
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(diff)

//-----------------------------------------------------------------------------
// Hunk
//-----------------------------------------------------------------------------
String Hunk::MakeUnifiedRange() const
{
	String str;
	char buff[80];
	::sprintf(buff, "-%lu", linenoOrg);
	str += buff;
	if (nLinesOrg != 1) {
		::sprintf(buff, ",%lu", nLinesOrg);
		str += buff;
	}
	::sprintf(buff, " +%lu", linenoNew);
	str += buff;
	if (nLinesNew != 1) {
		::sprintf(buff, ",%lu", nLinesNew);
		str += buff;
	}
	return str;
}

//-----------------------------------------------------------------------------
// DiffString
//-----------------------------------------------------------------------------
bool DiffString::ReadLines(Signal sig, Stream &src, std::vector<String> &seq)
{
	bool includeEOLFlag = false;
	for (;;) {
		String str;
		if (!src.ReadLine(sig, str, includeEOLFlag)) break;
		seq.push_back(str);
	}
	return !sig.IsSignalled();
}

void DiffString::SplitLines(const char *src, std::vector<String> &seq)
{
	String str;
	for (const char *p = src; *p != '\0'; p++) {
		char ch = *p;
		if (ch == '\n') {
			seq.push_back(str);
			str.clear();
		} else {
			str += ch;
		}
	}
	if (!str.empty()) seq.push_back(str);
}

//-----------------------------------------------------------------------------
// Result
//-----------------------------------------------------------------------------
void Result::Process()
{
	_diffString.init();
	_diffString.onHuge();
	_diffString.compose();
}

bool Result::PrintEdit(Signal sig, Stream &stream, const DiffString::Edit &edit)
{
	stream.Print(sig, GetEditMark(edit));
	if (sig.IsSignalled()) return false;
	stream.Println(sig, edit.first.c_str());
	return !sig.IsSignalled();
}

bool Result::PrintEdit(Signal sig, Stream &stream, size_t idxEdit)
{
	const DiffString::Edit &edit = _diffString.GetEditList()[idxEdit];
	return PrintEdit(sig, stream, edit);
}

bool Result::PrintEdits(Signal sig, Stream &stream) const
{
	foreach_const (DiffString::EditList, pEdit, _diffString.GetEditList()) {
		if (!PrintEdit(sig, stream, *pEdit)) return false;
	}
	return true;
}

bool Result::PrintHunk(Signal sig, Stream &stream, const Hunk &hunk) const
{
	const DiffString::EditList &edits = _diffString.GetEditList();
	DiffString::EditList::const_iterator pEdit = edits.begin() + hunk.idxEditBegin;
	DiffString::EditList::const_iterator pEditEnd = edits.begin() + hunk.idxEditEnd;
	stream.Printf(sig, "@@ %s @@\n", hunk.MakeUnifiedRange().c_str());
	for ( ; pEdit != pEditEnd; pEdit++) {
		if (!PrintEdit(sig, stream, *pEdit)) return false;
	}
	return true;
}

bool Result::PrintHunks(Signal sig, Stream &stream, size_t nLinesCommon) const
{
	size_t idxEdit = 0;
	Hunk hunk;
	while (NextHunk(&idxEdit, nLinesCommon, &hunk)) {
		if (!PrintHunk(sig, stream, hunk)) return false;
	}
	return true;
}

bool Result::NextHunk(size_t *pIdxEdit, size_t nLinesCommon, Hunk *pHunk) const
{
	::memset(pHunk, 0x00, sizeof(Hunk));
	size_t idxEdit = *pIdxEdit;
	size_t idxEditTop = idxEdit;
	size_t nEdits = CountEdits();
	if (idxEdit >= nEdits) return false;
	size_t nLines = 0;
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
		*pIdxEdit = idxEdit;
		pHunk->idxEditEnd = idxEdit;
		do {
			const DiffString::Edit &edit = GetEdit(pHunk->idxEditBegin);
			pHunk->linenoOrg = edit.second.beforeIdx;
			pHunk->linenoNew = edit.second.afterIdx;
			if (pHunk->linenoOrg == 0 && pHunk->idxEditBegin > 0) {
				const DiffString::Edit &edit = GetEdit(pHunk->idxEditBegin - 1);
				pHunk->linenoOrg = edit.second.beforeIdx;
			}
			if (pHunk->linenoNew == 0 && pHunk->idxEditBegin > 0) {
				const DiffString::Edit &edit = GetEdit(pHunk->idxEditBegin - 1);
				pHunk->linenoNew = edit.second.afterIdx;
			}
		} while (0);
		for (size_t idxEdit = pHunk->idxEditBegin; idxEdit < pHunk->idxEditEnd; idxEdit++) {
			const DiffString::Edit &edit = GetEdit(idxEdit);
			if (edit.second.type != dtl::SES_ADD) pHunk->nLinesOrg++;
			if (edit.second.type != dtl::SES_DELETE) pHunk->nLinesNew++;
		}
		return true;
	}
	*pIdxEdit = idxEdit;
	return false;
}

//-----------------------------------------------------------------------------
// Object_result
//-----------------------------------------------------------------------------
Object *Object_result::Clone() const
{
	return NULL;
}

bool Object_result::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(distance));
	return true;
}

Value Object_result::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(distance))) {
		return Value(_pResult->GetEditDistance());
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_result::ToString(bool exprFlag)
{
	char buff[80];
	String str;
	str += "<diff.result:";
	::sprintf(buff, "dist=%lld", _pResult->GetEditDistance());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Methods of diff.result
//-----------------------------------------------------------------------------
// diff.result#eachedit() {block?}
Gura_DeclareMethod(result, eachedit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(result, eachedit)
{
	Result *pResult = Object_result::GetThisObj(args)->GetResult();
	AutoPtr<IteratorEdit> pIterator(new IteratorEdit(pResult->Reference()));
	return ReturnIterator(env, sig, args, pIterator.release());
}

// diff.result#eachhunk(lines?:number) {block?}
Gura_DeclareMethod(result, eachhunk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(result, eachhunk)
{
	Result *pResult = Object_result::GetThisObj(args)->GetResult();
	size_t nLinesCommon = args.IsValid(0)? args.GetSizeT(0) : 3;
	AutoPtr<IteratorHunk> pIterator(new IteratorHunk(pResult->Reference(), nLinesCommon));
	return ReturnIterator(env, sig, args, pIterator.release());
}

// diff.result#output@unified(out?:stream:w, lines?:number):void
Gura_DeclareMethodAlias(result, output_at_unified, "output@unified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(result, output_at_unified)
{
	Result *pResult = Object_result::GetThisObj(args)->GetResult();
	Stream &stream = args.IsValid(0)? args.GetStream(0) : *env.GetConsole();
	size_t nLinesCommon = args.IsValid(1)? args.GetSizeT(1) : 3;
	pResult->PrintHunks(sig, stream, nLinesCommon);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.result
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(result)
{
	Gura_AssignValue(result, Value(Reference()));
	Gura_AssignMethod(result, eachedit);
	Gura_AssignMethod(result, eachhunk);
	Gura_AssignMethod(result, output_at_unified);
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
	return true;
}

Value Object_edit::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	const DiffString::Edit &edit = _pResult->GetEdit(_idxEdit);
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
		return Value(Result::GetEditMark(edit));
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
	const DiffString::Edit &edit = _pResult->GetEdit(_idxEdit);
	String str;
	str += "<diff.edit:";
	if (edit.second.type == dtl::SES_ADD) {
		str += "add";
	} else if (edit.second.type == dtl::SES_DELETE) {
		str += "delete";
	} else {
		str += "copy";
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Methods of diff.edit
//-----------------------------------------------------------------------------
// diff.edit#print(out?:stream:w):void
Gura_DeclareMethod(edit, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(edit, print)
{
	Object_edit *pThis = Object_edit::GetThisObj(args);
	Stream &stream = args.IsValid(0)? args.GetStream(0) : *env.GetConsole();
	pThis->GetResult()->PrintEdit(sig, stream, pThis->GetEditIndex());
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.edit
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(edit)
{
	Gura_AssignMethod(edit, print);
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
	symbols.insert(Gura_UserSymbol(lineno_at_org));
	symbols.insert(Gura_UserSymbol(lineno_at_new));
	symbols.insert(Gura_UserSymbol(nlines_at_org));
	symbols.insert(Gura_UserSymbol(nlines_at_new));
	return true;
}

Value Object_hunk::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(edits))) {
		AutoPtr<Iterator> pIterator(new IteratorEdit(_pResult->Reference(), _hunk));
		return Value(new Object_iterator(env, pIterator.release()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lineno_at_org))) {
		return Value(_hunk.linenoOrg);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lineno_at_new))) {
		return Value(_hunk.linenoNew);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(nlines_at_org))) {
		return Value(_hunk.nLinesOrg);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(nlines_at_new))) {
		return Value(_hunk.nLinesNew);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_hunk::ToString(bool exprFlag)
{
	char buff[80];
	String str;
	str += "<diff.hunk:";
	str += _hunk.MakeUnifiedRange();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Methods of diff.hunk
//-----------------------------------------------------------------------------
// diff.hunk#print(out?:stream:w):void
Gura_DeclareMethod(hunk, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(hunk, print)
{
	Object_hunk *pThis = Object_hunk::GetThisObj(args);
	Stream &stream = args.IsValid(0)? args.GetStream(0) : *env.GetConsole();
	pThis->GetResult()->PrintHunk(sig, stream, pThis->GetHunk());
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.hunk
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(hunk)
{
	Gura_AssignMethod(hunk, print);
}

//-----------------------------------------------------------------------------
// IteratorEdit
//-----------------------------------------------------------------------------
IteratorEdit::IteratorEdit(Result *pResult) :
	Iterator(false), _pResult(pResult),
	_idxEdit(0), _idxEditBegin(0), _idxEditEnd(pResult->CountEdits())
{
}

IteratorEdit::IteratorEdit(Result *pResult, const Hunk &hunk) :
	Iterator(false), _pResult(pResult),
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
	value = Value(new Object_edit(_pResult->Reference(), _idxEdit));
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
IteratorHunk::IteratorHunk(Result *pResult, size_t nLinesCommon) :
	Iterator(false), _pResult(pResult), _idxEdit(0), _nLinesCommon(nLinesCommon)
{
}

Iterator *IteratorHunk::GetSource()
{
	return NULL;
}

bool IteratorHunk::DoNext(Environment &env, Signal sig, Value &value)
{
	Hunk hunk;
	if (_pResult->NextHunk(&_idxEdit, _nLinesCommon, &hunk)) {
		value = Value(new Object_hunk(_pResult->Reference(), hunk));
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
// diff.diff(src1, src2) {block?}
Gura_DeclareFunction(diff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src1", VTYPE_any);
	DeclareArg(env, "src2", VTYPE_any);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(diff)
{
	AutoPtr<Result> pResult(new Result());
	if (args.IsType(0, VTYPE_string)) {
		DiffString::SplitLines(args.GetString(0), pResult->GetSeqA());
	} else if (args.IsType(0, VTYPE_stream)) {
		if (!DiffString::ReadLines(sig, args.GetStream(0), pResult->GetSeqA())) {
			return Value::Null;
		}
	} else {
		sig.SetError(ERR_TypeError, "difference source must be string or stream");
		return Value::Null;
	}
	if (args.IsType(1, VTYPE_string)) {
		DiffString::SplitLines(args.GetString(1), pResult->GetSeqB());
	} else if (args.IsType(1, VTYPE_stream)) {
		if (!DiffString::ReadLines(sig, args.GetStream(1), pResult->GetSeqB())) {
			return Value::Null;
		}
	} else {
		sig.SetError(ERR_TypeError, "difference source must be string or stream");
		return Value::Null;
	}
	pResult->Process();
	return ReturnValue(env, sig, args, Value(new Object_result(pResult.release())));
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
	Gura_RealizeUserSymbol(distance);
	Gura_RealizeUserSymbol(edits);
	Gura_RealizeUserSymbolAlias(lineno_at_org, "lineno@org");
	Gura_RealizeUserSymbolAlias(lineno_at_new, "lineno@new");
	Gura_RealizeUserSymbol(mark);
	Gura_RealizeUserSymbolAlias(nlines_at_org, "nlines@org");
	Gura_RealizeUserSymbolAlias(nlines_at_new, "nlines@new");
	Gura_RealizeUserSymbol(source);
	Gura_RealizeUserSymbol(type);
	// class realization
	Gura_RealizeUserClass(result, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(edit, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(hunk, env.LookupClass(VTYPE_object));
	// class preparation
	Gura_PrepareUserClass(result);
	Gura_PrepareUserClass(edit);
	Gura_PrepareUserClass(hunk);
	// function assignment
	Gura_AssignFunction(diff);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(diff, diff)

Gura_RegisterModule(diff)
