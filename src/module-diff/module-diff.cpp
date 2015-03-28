//=============================================================================
// Gura module: diff
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(diff)

//-----------------------------------------------------------------------------
// Hunk
//-----------------------------------------------------------------------------
String Hunk::MakeRangeText() const
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
// Processor
//-----------------------------------------------------------------------------
bool Processor::ProcessStream(Signal sig, Stream &src1, Stream &src2)
{
	if (!ReadLines(sig, src1, _diffString.getA())) return false;
	if (!ReadLines(sig, src2, _diffString.getB())) return false;
	_diffString.init();
	_diffString.onHuge();
	_diffString.compose();
	return true;
}

void Processor::ProcessString(const char *src1, const char *src2)
{
	SplitLines(src1, _diffString.getA());
	SplitLines(src2, _diffString.getB());
	_diffString.init();
	_diffString.onHuge();
	_diffString.compose();
}

bool Processor::PrintEdit(Signal sig, Stream &stream, const DiffString::Edit &edit)
{
	stream.Print(sig, GetEditMark(edit));
	if (sig.IsSignalled()) return false;
	stream.Println(sig, edit.first.c_str());
	return !sig.IsSignalled();
}

bool Processor::PrintEdits(Signal sig, Stream &stream) const
{
	foreach_const (DiffString::EditList, pEdit, _diffString.GetEditList()) {
		if (!PrintEdit(sig, stream, *pEdit)) return false;
	}
	return true;
}

bool Processor::PrintHunk(Signal sig, Stream &stream, const Hunk &hunk) const
{
	const DiffString::EditList &edits = _diffString.GetEditList();
	DiffString::EditList::const_iterator pEdit = edits.begin() + hunk.idxEditBegin;
	DiffString::EditList::const_iterator pEditEnd = edits.begin() + hunk.idxEditEnd;
	stream.Printf(sig, "@@ %s @@\n", hunk.MakeRangeText().c_str());
	for ( ; pEdit != pEditEnd; pEdit++) {
		if (!PrintEdit(sig, stream, *pEdit)) return false;
	}
	return true;
}

bool Processor::PrintHunks(Signal sig, Stream &stream, size_t nLinesCommon) const
{
	size_t idxEdit = 0;
	Hunk hunk;
	while (NextHunk(&idxEdit, nLinesCommon, &hunk)) {
		if (!PrintHunk(sig, stream, hunk)) return false;
	}
	return true;
}

bool Processor::NextHunk(size_t *pIdxEdit, size_t nLinesCommon, Hunk *pHunk) const
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

bool Processor::ReadLines(Signal sig, Stream &src, std::vector<String> &seq)
{
	bool includeEOLFlag = false;
	for (;;) {
		String str;
		if (!src.ReadLine(sig, str, includeEOLFlag)) break;
		seq.push_back(str);
	}
	return !sig.IsSignalled();
}

void Processor::SplitLines(const char *src, std::vector<String> &seq)
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
// Object_processor
//-----------------------------------------------------------------------------
Object *Object_processor::Clone() const
{
	return NULL;
}

bool Object_processor::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	return true;
}

Value Object_processor::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

String Object_processor::ToString(bool exprFlag)
{
	char buff[80];
	String str;
	str += "<diff.processor:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Methods of diff.processor
//-----------------------------------------------------------------------------
// diff.processor#edits() {block?}
Gura_DeclareMethod(processor, edits)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(processor, edits)
{
	Processor *pProcessor = Object_processor::GetThisObj(args)->GetProcessor();
	AutoPtr<IteratorEdit> pIterator(new IteratorEdit(pProcessor->Reference()));
	return ReturnIterator(env, sig, args, pIterator.release());
}

// diff.processor#hunks(lines?:number) {block?}
Gura_DeclareMethod(processor, hunks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(processor, hunks)
{
	Processor *pProcessor = Object_processor::GetThisObj(args)->GetProcessor();
	size_t nLinesCommon = args.IsValid(0)? args.GetSizeT(0) : 3;
	AutoPtr<IteratorHunk> pIterator(new IteratorHunk(pProcessor->Reference(), nLinesCommon));
	return ReturnIterator(env, sig, args, pIterator.release());
}

// diff.processor#output@unified(out?:stream:w, lines?:number):void
Gura_DeclareMethodAlias(processor, output_at_unified, "output@unified")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(processor, output_at_unified)
{
	Processor *pProcessor = Object_processor::GetThisObj(args)->GetProcessor();
	Stream &stream = args.IsValid(0)? args.GetStream(0) : *env.GetConsole();
	size_t nLinesCommon = args.IsValid(1)? args.GetSizeT(1) : 3;
	pProcessor->PrintHunks(sig, stream, nLinesCommon);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.processor
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(processor)
{
	Gura_AssignValue(processor, Value(Reference()));
	Gura_AssignMethod(processor, edits);
	Gura_AssignMethod(processor, hunks);
	Gura_AssignMethod(processor, output_at_unified);
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
	const DiffString::Edit &edit = _pProcessor->GetEdit(_idxEdit);
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
		return Value(Processor::GetEditMark(edit));
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
	const DiffString::Edit &edit = _pProcessor->GetEdit(_idxEdit);
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
		AutoPtr<Iterator> pIterator(new IteratorEdit(_pProcessor->Reference(), _hunk));
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
	str += _hunk.MakeRangeText();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Methods of diff.hunk
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for diff.hunk
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(hunk)
{
}

//-----------------------------------------------------------------------------
// IteratorEdit
//-----------------------------------------------------------------------------
IteratorEdit::IteratorEdit(Processor *pProcessor) :
	Iterator(false), _pProcessor(pProcessor),
	_idxEdit(0), _idxEditBegin(0), _idxEditEnd(pProcessor->CountEdits())
{
}

IteratorEdit::IteratorEdit(Processor *pProcessor, const Hunk &hunk) :
	Iterator(false), _pProcessor(pProcessor),
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
	value = Value(new Object_edit(_pProcessor->Reference(), _idxEdit));
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
IteratorHunk::IteratorHunk(Processor *pProcessor, size_t nLinesCommon) :
	Iterator(false), _pProcessor(pProcessor), _idxEdit(0), _nLinesCommon(nLinesCommon)
{
}

Iterator *IteratorHunk::GetSource()
{
	return NULL;
}

bool IteratorHunk::DoNext(Environment &env, Signal sig, Value &value)
{
	Hunk hunk;
	if (_pProcessor->NextHunk(&_idxEdit, _nLinesCommon, &hunk)) {
		value = Value(new Object_hunk(_pProcessor->Reference(), hunk));
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
// diff.processStream(src1:stream, src2:stream) {block?}
Gura_DeclareFunction(processStream)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src1", VTYPE_stream);
	DeclareArg(env, "src2", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(processStream)
{
	AutoPtr<Processor> pProcessor(new Processor());
	if (!pProcessor->ProcessStream(sig, args.GetStream(0), args.GetStream(1))) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_processor(pProcessor.release())));
}

// diff.processString(src1:string, src2:string) {block?}
Gura_DeclareFunction(processString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src1", VTYPE_string);
	DeclareArg(env, "src2", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(processString)
{
	AutoPtr<Processor> pProcessor(new Processor());
	pProcessor->ProcessString(args.GetString(0), args.GetString(1));
	return ReturnValue(env, sig, args, Value(new Object_processor(pProcessor.release())));
}

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
	AutoPtr<Processor> pProcessor(new Processor());
	if (!pProcessor->ProcessStream(sig, args.GetStream(0), args.GetStream(1))) return Value::Null;
	if (args.IsValid(2)) {
		pProcessor->PrintEdits(sig, args.GetStream(2));
		return Value::Null;
	}
	AutoPtr<IteratorEdit> pIterator(new IteratorEdit(pProcessor->Reference()));
	return ReturnIterator(env, sig, args, pIterator.release());
}

// diff.diff@string(src1:string, src2:string, out?:stream:w) {block?}
Gura_DeclareFunctionAlias(diff_at_string, "diff@string")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src1", VTYPE_string);
	DeclareArg(env, "src2", VTYPE_string);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(diff_at_string)
{
	AutoPtr<Processor> pProcessor(new Processor());
	pProcessor->ProcessString(args.GetString(0), args.GetString(1));
	if (args.IsValid(2)) {
		pProcessor->PrintEdits(sig, args.GetStream(2));
		return Value::Null;
	}
	AutoPtr<IteratorEdit> pIterator(new IteratorEdit(pProcessor->Reference()));
	return ReturnIterator(env, sig, args, pIterator.release());
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
	AutoPtr<Processor> pProcessor(new Processor());
	if (!pProcessor->ProcessStream(sig, args.GetStream(0), args.GetStream(1))) return Value::Null;
	size_t nLinesCommon = args.IsValid(3)? args.GetSizeT(3) : 3;
	if (args.IsValid(2)) {
		pProcessor->PrintHunks(sig, args.GetStream(2), nLinesCommon);
		return Value::Null;
	}
	AutoPtr<IteratorHunk> pIterator(new IteratorHunk(pProcessor->Reference(), nLinesCommon));
	return ReturnIterator(env, sig, args, pIterator.release());
}

// diff.unidiff@string(src1:string, src2:string, out?:stream:w, lines?:number) {block?}
Gura_DeclareFunctionAlias(unidiff_at_string, "unidiff@string")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src1", VTYPE_string);
	DeclareArg(env, "src2", VTYPE_string);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(unidiff_at_string)
{
	AutoPtr<Processor> pProcessor(new Processor());
	pProcessor->ProcessString(args.GetString(0), args.GetString(1));
	size_t nLinesCommon = args.IsValid(3)? args.GetSizeT(3) : 3;
	if (args.IsValid(2)) {
		pProcessor->PrintHunks(sig, args.GetStream(2), nLinesCommon);
		return Value::Null;
	}
	AutoPtr<IteratorHunk> pIterator(new IteratorHunk(pProcessor->Reference(), nLinesCommon));
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
	Gura_RealizeUserSymbolAlias(nlines_at_org, "nlines@org");
	Gura_RealizeUserSymbolAlias(nlines_at_new, "nlines@new");
	Gura_RealizeUserSymbol(source);
	Gura_RealizeUserSymbol(type);
	// class realization
	Gura_RealizeUserClass(processor, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(edit, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(hunk, env.LookupClass(VTYPE_object));
	// class preparation
	Gura_PrepareUserClass(processor);
	Gura_PrepareUserClass(edit);
	Gura_PrepareUserClass(hunk);
	// function assignment
	Gura_AssignFunction(processStream);
	Gura_AssignFunction(processString);
	Gura_AssignFunction(diff_at_stream);
	Gura_AssignFunction(diff_at_string);
	Gura_AssignFunction(unidiff_at_stream);
	Gura_AssignFunction(unidiff_at_string);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(diff, diff)

Gura_RegisterModule(diff)
