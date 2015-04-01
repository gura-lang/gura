//=============================================================================
// Gura module: diff
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(diff)

//-----------------------------------------------------------------------------
// DiffLine
//-----------------------------------------------------------------------------
void DiffLine::Compose()
{
	init();
	onHuge();
	compose();
}

bool DiffLine::PrintEdit(Signal sig, SimpleStream &stream, const DiffLine::Edit &edit)
{
	stream.Println(sig, TextizeUnifiedEdit(edit).c_str());
	return !sig.IsSignalled();
}

bool DiffLine::PrintEdit(Signal sig, SimpleStream &stream, size_t idxEdit)
{
	const Edit &edit = GetEditList()[idxEdit];
	return PrintEdit(sig, stream, edit);
}

bool DiffLine::PrintEdits(Signal sig, SimpleStream &stream) const
{
	foreach_const (EditList, pEdit, GetEditList()) {
		if (!PrintEdit(sig, stream, *pEdit)) return false;
	}
	return true;
}

bool DiffLine::PrintHunk(Signal sig, SimpleStream &stream,
					   DiffLine::Format format, const Hunk &hunk) const
{
	const EditList &edits = GetEditList();
	EditList::const_iterator pEdit = edits.begin() + hunk.idxEditBegin;
	EditList::const_iterator pEditEnd = edits.begin() + hunk.idxEditEnd;
	stream.Printf(sig, "@@ %s @@\n", hunk.TextizeUnifiedRange().c_str());
	for ( ; pEdit != pEditEnd; pEdit++) {
		if (!PrintEdit(sig, stream, *pEdit)) return false;
	}
	return true;
}

bool DiffLine::PrintHunks(Signal sig, SimpleStream &stream,
						DiffLine::Format format, size_t nLinesCommon) const
{
	size_t idxEdit = 0;
	Hunk hunk;
	while (NextHunk(&idxEdit, nLinesCommon, &hunk)) {
		if (!PrintHunk(sig, stream, format, hunk)) return false;
	}
	return true;
}

bool DiffLine::NextHunk(size_t *pIdxEdit, size_t nLinesCommon, Hunk *pHunk) const
{
	::memset(pHunk, 0x00, sizeof(Hunk));
	size_t idxEdit = *pIdxEdit;
	size_t idxEditTop = idxEdit;
	size_t nEdits = CountEdits();
	if (idxEdit >= nEdits) return false;
	size_t nLines = 0;
	for ( ; idxEdit < nEdits; idxEdit++) {
		const Edit &edit = GetEdit(idxEdit);
		if (edit.second.type == dtl::SES_COMMON) continue;
		pHunk->idxEditBegin = (idxEdit > idxEditTop + nLinesCommon)?
			idxEdit - nLinesCommon : idxEditTop;
		idxEdit++;
		for ( ; idxEdit < nEdits; idxEdit++) {
			const Edit &edit = GetEdit(idxEdit);
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
		for (size_t idxEdit = pHunk->idxEditBegin; idxEdit < pHunk->idxEditEnd; idxEdit++) {
			const Edit &edit = GetEdit(idxEdit);
			if (edit.second.beforeIdx > 0) {
				pHunk->linenoOrg = edit.second.beforeIdx;
				break;
			}
		}
		for (size_t idxEdit = pHunk->idxEditBegin; idxEdit < pHunk->idxEditEnd; idxEdit++) {
			const Edit &edit = GetEdit(idxEdit);
			if (edit.second.afterIdx > 0) {
				pHunk->linenoNew = edit.second.afterIdx;
				break;
			}
		}
		do {
			const Edit &edit = GetEdit(pHunk->idxEditBegin);
			if (pHunk->linenoOrg == 0 && pHunk->idxEditBegin > 0) {
				const Edit &edit = GetEdit(pHunk->idxEditBegin - 1);
				pHunk->linenoOrg = edit.second.beforeIdx;
			}
			if (pHunk->linenoNew == 0 && pHunk->idxEditBegin > 0) {
				const Edit &edit = GetEdit(pHunk->idxEditBegin - 1);
				pHunk->linenoNew = edit.second.afterIdx;
			}
		} while (0);
		for (size_t idxEdit = pHunk->idxEditBegin; idxEdit < pHunk->idxEditEnd; idxEdit++) {
			const Edit &edit = GetEdit(idxEdit);
			if (edit.second.type != dtl::SES_ADD) pHunk->nLinesOrg++;
			if (edit.second.type != dtl::SES_DELETE) pHunk->nLinesNew++;
		}
		return true;
	}
	*pIdxEdit = idxEdit;
	return false;
}

void DiffLine::FeedString(Sequence &seq, const char *src)
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

bool DiffLine::FeedStream(Signal sig, Sequence &seq, Stream &src)
{
	bool includeEOLFlag = false;
	for (;;) {
		String str;
		if (!src.ReadLine(sig, str, includeEOLFlag)) break;
		seq.push_back(str);
	}
	return !sig.IsSignalled();
}

bool DiffLine::FeedIterator(Environment &env, Signal sig, Sequence &seq, Iterator *pIterator)
{
	Value value;
	while (pIterator->Next(env, sig, value)) {
		seq.push_back(value.ToString());
	}
	return !sig.IsSignalled();
}

void DiffLine::FeedList(Sequence &seq, const ValueList &valList)
{
	foreach_const (ValueList, pValue, valList) {
		seq.push_back(pValue->ToString());
	}
}

String DiffLine::TextizeUnifiedEdit(const DiffLine::Edit &edit)
{
	String str;
	str += GetEditMark(edit);
	str += edit.first;
	return str;
}

DiffLine::Format DiffLine::SymbolToFormat(Signal sig, const Symbol *pSymbol)
{
	if (pSymbol->IsIdentical(Gura_UserSymbol(normal))) {
		return FORMAT_Normal;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(context))) {
		return FORMAT_Context;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(unified))) {
		return FORMAT_Unified;
	} else {		
		sig.SetError(ERR_ValueError, "invalid symbol for the format");
		return FORMAT_None;
	}
}

//-----------------------------------------------------------------------------
// DiffLine::Hunk
//-----------------------------------------------------------------------------
String DiffLine::Hunk::TextizeUnifiedRange() const
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
// DiffLine::IteratorHunk
//-----------------------------------------------------------------------------
DiffLine::IteratorHunk::IteratorHunk(DiffLine *pDiffLine, size_t nLinesCommon) :
	Iterator(false), _pDiffLine(pDiffLine), _idxEdit(0), _nLinesCommon(nLinesCommon)
{
}

Iterator *DiffLine::IteratorHunk::GetSource()
{
	return NULL;
}

bool DiffLine::IteratorHunk::DoNext(Environment &env, Signal sig, Value &value)
{
	DiffLine::Hunk hunk;
	if (_pDiffLine->NextHunk(&_idxEdit, _nLinesCommon, &hunk)) {
		value = Value(new Object_hunk_at_line(_pDiffLine->Reference(), hunk));
		return true;
	}
	return false;
}

String DiffLine::IteratorHunk::ToString() const
{
	String str;
	str += "diff.hunk@line";
	return str;
}

void DiffLine::IteratorHunk::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// DiffLine::IteratorEdit
//-----------------------------------------------------------------------------
DiffLine::IteratorEdit::IteratorEdit(DiffLine *pDiffLine) :
	Iterator(false), _pDiffLine(pDiffLine),
	_idxEdit(0), _idxEditBegin(0), _idxEditEnd(pDiffLine->CountEdits())
{
}

DiffLine::IteratorEdit::IteratorEdit(DiffLine *pDiffLine, const DiffLine::Hunk &hunk) :
	Iterator(false), _pDiffLine(pDiffLine),
	_idxEdit(hunk.idxEditBegin), _idxEditBegin(hunk.idxEditBegin), _idxEditEnd(hunk.idxEditEnd)
{
}

Iterator *DiffLine::IteratorEdit::GetSource()
{
	return NULL;
}

bool DiffLine::IteratorEdit::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idxEdit >= _idxEditEnd) return false;
	value = Value(new Object_edit_at_line(_pDiffLine->Reference(), _idxEdit));
	_idxEdit++;
	return true;
}

String DiffLine::IteratorEdit::ToString() const
{
	String str;
	str += "diff.edit";
	return str;
}

void DiffLine::IteratorEdit::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_diff_at_line
//-----------------------------------------------------------------------------
Object *Object_diff_at_line::Clone() const
{
	return NULL;
}

bool Object_diff_at_line::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(distance));
	symbols.insert(Gura_UserSymbol(nlines_at_org));
	symbols.insert(Gura_UserSymbol(nlines_at_new));
	return true;
}

Value Object_diff_at_line::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(distance))) {
		return Value(_pDiffLine->GetEditDistance());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(nlines_at_org))) {
		return Value(_pDiffLine->GetSeq(0).size());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(nlines_at_new))) {
		return Value(_pDiffLine->GetSeq(1).size());
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_diff_at_line::ToString(bool exprFlag)
{
	char buff[80];
	String str;
	str += "<diff.diff@line:";
	::sprintf(buff, "dist=%lld", _pDiffLine->GetEditDistance());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Methods of diff.diff@line
//-----------------------------------------------------------------------------
// diff.diff@line#eachedit() {block?}
Gura_DeclareMethod(diff_at_line, eachedit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that returns `diff.edit@line` instance stored in the result.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(diff_at_line, eachedit)
{
	DiffLine *pDiffLine = Object_diff_at_line::GetThisObj(args)->GetDiffLine();
	AutoPtr<DiffLine::IteratorEdit> pIterator(new DiffLine::IteratorEdit(pDiffLine->Reference()));
	return ReturnIterator(env, sig, args, pIterator.release());
}

// diff.diff@line#eachhunk(lines?:number) {block?}
Gura_DeclareMethod(diff_at_line, eachhunk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that returns `diff.hunk@line` instance stored in the result.\n"
		"\n"
		"The argument `lines` specifies a number of common lines appended before and after\n"
		"different lines\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(diff_at_line, eachhunk)
{
	DiffLine *pDiffLine = Object_diff_at_line::GetThisObj(args)->GetDiffLine();
	size_t nLinesCommon = args.IsValid(0)? args.GetSizeT(0) : 3;
	AutoPtr<DiffLine::IteratorHunk> pIterator(
		new DiffLine::IteratorHunk(pDiffLine->Reference(), nLinesCommon));
	return ReturnIterator(env, sig, args, pIterator.release());
}

// diff.diff@line#render(out?:stream:w, format?:symbol, lines?:number)
Gura_DeclareMethodAlias(diff_at_line, render, "render")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Renders diff result to the specified stream.\n"
		"\n"
		"If the argument `out` is omitted, this method returns a string of the rendered text.\n"
		"Otherwise, it returns `nil`.\n"
		"\n"
		"The argument `format` takes one of the symbols that specifies the rendering format:\n"
		"\n"
		"- `` `normal`` .. Normal format (not supported yet).\n"
		"- `` `context`` .. Context format (not supported yet).\n"
		"- `` `unified`` .. Unified format. This is the default.\n"
		"\n"
		"The argument `lines` specifies a number of common lines appended before and after\n"
		"different lines\n");
}

Gura_ImplementMethod(diff_at_line, render)
{
	DiffLine *pDiffLine = Object_diff_at_line::GetThisObj(args)->GetDiffLine();
	DiffLine::Format format = DiffLine::FORMAT_Unified;
	if (args.IsValid(1)) {
		format = DiffLine::SymbolToFormat(sig, args.GetSymbol(1));
		if (format == DiffLine::FORMAT_None) return Value::Null;
	}
	size_t nLinesCommon = args.IsValid(2)? args.GetSizeT(2) : 3;
	if (args.IsValid(0)) {
		Stream &streamOut = args.GetStream(0);
		pDiffLine->PrintHunks(sig, streamOut, format, nLinesCommon);
		return Value::Null;
	} else {
		String strOut;
		SimpleStream_StringWriter streamOut(strOut);
		pDiffLine->PrintHunks(sig, streamOut, format, nLinesCommon);
		return Value(strOut);
	}
}

//-----------------------------------------------------------------------------
// Class implementation for diff.diff@line
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(diff_at_line)
{
	Gura_AssignValueEx("diff@line", Value(Reference()));
	Gura_AssignMethod(diff_at_line, eachedit);
	Gura_AssignMethod(diff_at_line, eachhunk);
	Gura_AssignMethod(diff_at_line, render);
}

//-----------------------------------------------------------------------------
// Object_hunk_at_line
//-----------------------------------------------------------------------------
Object *Object_hunk_at_line::Clone() const
{
	return NULL;
}

bool Object_hunk_at_line::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(edits));
	symbols.insert(Gura_UserSymbol(lineno_at_org));
	symbols.insert(Gura_UserSymbol(lineno_at_new));
	symbols.insert(Gura_UserSymbol(nlines_at_org));
	symbols.insert(Gura_UserSymbol(nlines_at_new));
	return true;
}

Value Object_hunk_at_line::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(edits))) {
		AutoPtr<Iterator> pIterator(new DiffLine::IteratorEdit(_pDiffLine->Reference(), _hunk));
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

String Object_hunk_at_line::ToString(bool exprFlag)
{
	char buff[80];
	String str;
	str += "<diff.hunk@line:";
	str += _hunk.TextizeUnifiedRange();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Methods of diff.hunk@line
//-----------------------------------------------------------------------------
// diff.hunk@line#print(out?:stream:w, format?:symbol):void
Gura_DeclareMethod(hunk_at_line, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints the content of the `diff.hunk` instance to the specified stream.\n"
		"\n"
		"The argument `format` takes one of the symbols that specifies the rendering format:\n"
		"\n"
		"- `` `normal`` .. Normal format (not supported yet).\n"
		"- `` `context`` .. Context format (not supported yet).\n"
		"- `` `unified`` .. Unified format. This is the default.\n");
}

Gura_ImplementMethod(hunk_at_line, print)
{
	Object_hunk_at_line *pThis = Object_hunk_at_line::GetThisObj(args);
	Stream &stream = args.IsValid(0)? args.GetStream(0) : *env.GetConsole();
	DiffLine::Format format = DiffLine::FORMAT_Unified;
	if (args.IsValid(1)) {
		format = DiffLine::SymbolToFormat(sig, args.GetSymbol(1));
		if (format == DiffLine::FORMAT_None) return Value::Null;
	}
	pThis->GetDiffLine()->PrintHunk(sig, stream, format, pThis->GetHunk());
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.hunk@line
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(hunk_at_line)
{
	Gura_AssignValueEx("hunk@line", Value(Reference()));
	Gura_AssignMethod(hunk_at_line, print);
}

//-----------------------------------------------------------------------------
// Object_edit_at_line
//-----------------------------------------------------------------------------
Object *Object_edit_at_line::Clone() const
{
	return NULL;
}

bool Object_edit_at_line::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(mark));
	symbols.insert(Gura_UserSymbol(lineno_at_org));
	symbols.insert(Gura_UserSymbol(lineno_at_new));
	symbols.insert(Gura_UserSymbol(source));
	symbols.insert(Gura_UserSymbol(unified));
	return true;
}

Value Object_edit_at_line::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	const DiffLine::Edit &edit = _pDiffLine->GetEdit(_idxEdit);
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
		return Value(DiffLine::GetEditMark(edit));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lineno_at_org))) {
		return Value(edit.second.beforeIdx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lineno_at_new))) {
		return Value(edit.second.afterIdx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(source))) {
		return Value(edit.first);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(unified))) {
		return Value(DiffLine::TextizeUnifiedEdit(edit));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_edit_at_line::ToString(bool exprFlag)
{
	const DiffLine::Edit &edit = _pDiffLine->GetEdit(_idxEdit);
	String str;
	str += "<diff.edit@line:";
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
// Methods of diff.edit@line
//-----------------------------------------------------------------------------
// diff.edit@line#print(out?:stream:w):void
Gura_DeclareMethod(edit_at_line, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints the content of the `diff.edit` instance to the specified stream.\n");
}

Gura_ImplementMethod(edit_at_line, print)
{
	Object_edit_at_line *pThis = Object_edit_at_line::GetThisObj(args);
	Stream &stream = args.IsValid(0)? args.GetStream(0) : *env.GetConsole();
	pThis->GetDiffLine()->PrintEdit(sig, stream, pThis->GetEditIndex());
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.edit@line
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(edit_at_line)
{
	Gura_AssignValueEx("edit@line", Value(Reference()));
	Gura_AssignMethod(edit_at_line, print);
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// diff.compose(src1, src2):[icase] {block?}
Gura_DeclareFunction(compose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src1", VTYPE_any);
	DeclareArg(env, "src2", VTYPE_any);
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Extracts differences between two sources of strings and returns `diff.diff@line` instance\n"
		"that contains the difference information.\n"
		"\n"
		"You can specify a value of `string`, `stream`, `iterator` or `list`\n"
		"for the argument `src1` and `src2`.\n"
		"In the result, the content of `src1` is referred to as an \"original\" one\n"
		"and that of `src2` as a \"new\" one.\n"
		"\n"
		"Below is an example to compare between two strings:\n"
		"\n"
		"    str1 = '...'\n"
		"    str2 = '...'\n"
		"    result = diff.compose(str1, str2)\n"
		"\n"
		"Below is an example to compare between two files:\n"
		"\n"
		"    file1 = stream('file1.txt')\n"
		"    file2 = stream('file2.txt')\n"
		"    result = diff.compose(file1, file2)\n"
		"\n"
		"Below is an example to compare between two iterators:\n"
		"\n"
		"    chars1 = '...'.each()\n"
		"    chars2 = '...'.each()\n"
		"    result = diff.compose(chars1, chars2)\n"
		"\n"
		"Below is an example to compare between a file and a string:\n"
		"\n"
		"    file = stream('file.txt')\n"
		"    str = '...'\n"
		"    result = diff.compose(file, str)\n"
		"\n"
		"If attribute `:icase` is specified, it wouldn't distinguish\n"
		"upper and lower case of characters.\n");
}

Gura_ImplementFunction(compose)
{
	bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
	AutoPtr<DiffLine> pDiffLine(new DiffLine(ignoreCaseFlag));
	for (size_t i = 0; i < 2; i++) {
		if (args.IsType(i, VTYPE_string)) {
			DiffLine::FeedString(pDiffLine->GetSeq(i), args.GetString(i));
		} else if (args.IsType(i, VTYPE_stream)) {
			if (!DiffLine::FeedStream(sig, pDiffLine->GetSeq(i), args.GetStream(i))) {
				return Value::Null;
			}
		} else if (args.IsType(i, VTYPE_iterator)) {
			AutoPtr<Iterator> pIterator(args.GetIterator(i)->Clone());
			if (!DiffLine::FeedIterator(env, sig, pDiffLine->GetSeq(i), pIterator.get())) {
				return Value::Null;
			}				
		} else if (args.IsType(i, VTYPE_list)) {
			DiffLine::FeedList(pDiffLine->GetSeq(i), args.GetList(i));
		} else {
			sig.SetError(ERR_TypeError, "difference source must be string or stream");
			return Value::Null;
		}
	}
	pDiffLine->Compose();
	return ReturnValue(env, sig, args, Value(new Object_diff_at_line(pDiffLine.release())));
}

// diff.compose@char(src1:string, src2:string):[icase] {block?}
Gura_DeclareFunctionAlias(compose_at_char, "compose@char")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src1", VTYPE_string);
	DeclareArg(env, "src2", VTYPE_string);
	DeclareAttr(Gura_Symbol(icase));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(compose_at_char)
{
	//bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(add);
	Gura_RealizeUserSymbol(context);
	Gura_RealizeUserSymbol(copy);
	Gura_RealizeUserSymbol(delete);
	Gura_RealizeUserSymbol(distance);
	Gura_RealizeUserSymbol(edits);
	Gura_RealizeUserSymbolAlias(lineno_at_org, "lineno@org");
	Gura_RealizeUserSymbolAlias(lineno_at_new, "lineno@new");
	Gura_RealizeUserSymbol(mark);
	Gura_RealizeUserSymbolAlias(nlines_at_org, "nlines@org");
	Gura_RealizeUserSymbolAlias(nlines_at_new, "nlines@new");
	Gura_RealizeUserSymbol(normal);
	Gura_RealizeUserSymbol(source);
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(unified);
	// class realization
	Gura_RealizeUserClassAlias(diff_at_line, "diff@line", env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassAlias(hunk_at_line, "hunk@line", env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassAlias(edit_at_line, "edit@line", env.LookupClass(VTYPE_object));
	// class preparation
	Gura_PrepareUserClass(diff_at_line);
	Gura_PrepareUserClass(hunk_at_line);
	Gura_PrepareUserClass(edit_at_line);
	// function assignment
	Gura_AssignFunction(compose);
	Gura_AssignFunction(compose_at_char);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(diff, diff)

Gura_RegisterModule(diff)
