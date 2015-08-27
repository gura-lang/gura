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

bool DiffLine::PrintHunk(Signal &sig, SimpleStream &stream, const Hunk &hunk) const
{
	const EditList &edits = GetEditList();
	EditList::const_iterator pEdit = edits.begin() + hunk.idxEditBegin;
	EditList::const_iterator pEditEnd = edits.begin() + hunk.idxEditEnd;
	if (hunk.format == FORMAT_Normal) {
		stream.Printf(sig, "%s\n", hunk.TextizeRange_Normal().c_str());
		for ( ; pEdit != pEditEnd; pEdit++) {
			stream.Println(sig, TextizeEdit_Normal(*pEdit).c_str());
			if (sig.IsSignalled()) return false;
		}
	} else if (hunk.format == FORMAT_Context) {

	} else if (hunk.format == FORMAT_Unified) {
		stream.Printf(sig, "@@ %s @@\n", hunk.TextizeRange_Unified().c_str());
		if (sig.IsSignalled()) return false;
		for ( ; pEdit != pEditEnd; pEdit++) {
			stream.Println(sig, TextizeEdit_Unified(*pEdit).c_str());
			if (sig.IsSignalled()) return false;
		}
	}
	return true;
}

bool DiffLine::PrintHunks(Signal &sig, SimpleStream &stream,
						  DiffLine::Format format, size_t nLinesCommon) const
{
	size_t idxEdit = 0;
	Hunk hunk;
	while (NextHunk(&idxEdit, format, nLinesCommon, &hunk)) {
		if (!PrintHunk(sig, stream, hunk)) return false;
	}
	return true;
}

bool DiffLine::NextHunk(size_t *pIdxEdit, Format format, size_t nLinesCommon, Hunk *pHunk) const
{
	pHunk->Clear();
	pHunk->format = format;
	if (format == FORMAT_Normal) nLinesCommon = 0;
	size_t idxEdit = *pIdxEdit;
	size_t idxEditTop = idxEdit;
	size_t nEdits = GetEditList().size();
	if (idxEdit >= nEdits) return false;
	size_t nLines = 0;
	for ( ; idxEdit < nEdits; idxEdit++) {
		const Edit &edit = GetEdit(idxEdit);
		if (edit.second.type == EDITTYPE_Copy) continue;
		pHunk->idxEditBegin = (idxEdit > idxEditTop + nLinesCommon)?
			idxEdit - nLinesCommon : idxEditTop;
		idxEdit++;
		for ( ; idxEdit < nEdits; idxEdit++) {
			const Edit &edit = GetEdit(idxEdit);
			if (edit.second.type == EDITTYPE_Copy) {
				if (nLinesCommon == 0) break;
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
			if (edit.second.type != EDITTYPE_Add) pHunk->nLinesOrg++;
			if (edit.second.type != EDITTYPE_Delete) pHunk->nLinesNew++;
		}
		return true;
	}
	*pIdxEdit = idxEdit;
	return false;
}

void DiffLine::FeedString(size_t iSeq, const char *src)
{
	Sequence &seq = GetSequence(iSeq);
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

bool DiffLine::FeedStream(Signal &sig, size_t iSeq, Stream &src)
{
	Sequence &seq = GetSequence(iSeq);
	bool includeEOLFlag = false;
	for (;;) {
		String str;
		if (!src.ReadLine(sig, str, includeEOLFlag)) break;
		seq.push_back(str);
	}
	return !sig.IsSignalled();
}

bool DiffLine::FeedIterator(Environment &env, Signal &sig, size_t iSeq, Iterator *pIterator)
{
	Sequence &seq = GetSequence(iSeq);
	Value value;
	while (pIterator->Next(env, value)) {
		seq.push_back(value.ToString());
	}
	return !sig.IsSignalled();
}

void DiffLine::FeedList(size_t iSeq, const ValueList &valList)
{
	Sequence &seq = GetSequence(iSeq);
	foreach_const (ValueList, pValue, valList) {
		seq.push_back(pValue->ToString());
	}
}

DiffChar *DiffLine::CreateDiffChar(EditList::const_iterator pEditBegin,
								   EditList::const_iterator pEditEnd)
{
	AutoPtr<DiffChar> pDiffChar(new DiffChar(GetIgnoreCaseFlag()));
	for (EditList::const_iterator pEdit = pEditBegin; pEdit != pEditEnd; pEdit++) {
		EditType editType = pEdit->second.type;
		if (editType == EDITTYPE_Copy || editType == EDITTYPE_Delete) {
			pDiffChar->FeedString(0, pEdit->first.c_str());
			pDiffChar->FeedChar(0, '\n');
		}
		if (editType == EDITTYPE_Copy || editType == EDITTYPE_Add) {
			pDiffChar->FeedString(1, pEdit->first.c_str());
			pDiffChar->FeedChar(1, '\n');
		}
	}
	pDiffChar->Compose();
	return pDiffChar.release();
}

DiffChar *DiffLine::CreateDiffChar(size_t idxEditBegin, size_t idxEditEnd)
{
	const EditList &editList = GetEditList();
	EditList::const_iterator pEditBegin = editList.begin() + idxEditBegin;
	EditList::const_iterator pEditEnd = editList.begin() + idxEditEnd;
	return CreateDiffChar(pEditBegin, pEditEnd);
}

String DiffLine::TextizeEdit_Normal(const DiffLine::Edit &edit)
{
	String str;
	str += GetEditMark_Normal(edit.second.type);
	str += GetEditSource(edit);
	return str;
}

String DiffLine::TextizeEdit_Unified(const DiffLine::Edit &edit)
{
	String str;
	str += GetEditMark_Unified(edit.second.type);
	str += GetEditSource(edit);
	return str;
}

DiffLine::Format DiffLine::SymbolToFormat(Signal &sig, const Symbol *pSymbol)
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
String DiffLine::Hunk::TextizeRange_Normal() const
{
	String str;
	char buff[80];
	::sprintf(buff, "%lu", linenoOrg);
	str += buff;
	if (nLinesOrg > 1) {
		::sprintf(buff, ",%lu", linenoOrg + nLinesOrg - 1);
		str += buff;
	}
	str += IsAdd()? "a" : IsDelete()? "d" : IsChange()? "c" : "?";
	::sprintf(buff, "%lu", linenoNew);
	str += buff;
	if (nLinesNew > 1) {
		::sprintf(buff, ",%lu", linenoNew + nLinesNew - 1);
		str += buff;
	}
	return str;
}

String DiffLine::Hunk::TextizeRange_Context() const
{
	String str;
	return str;
}

String DiffLine::Hunk::TextizeRange_Unified() const
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
DiffLine::IteratorHunk::IteratorHunk(DiffLine *pDiffLine,
									 Format format, size_t nLinesCommon) :
	Iterator(false), _pDiffLine(pDiffLine), _idxEdit(0),
	_format(format), _nLinesCommon(nLinesCommon)
{
}

Iterator *DiffLine::IteratorHunk::GetSource()
{
	return nullptr;
}

bool DiffLine::IteratorHunk::DoNext(Environment &env, Value &value)
{
	DiffLine::Hunk hunk;
	if (_pDiffLine->NextHunk(&_idxEdit, _format, _nLinesCommon, &hunk)) {
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
	_idxEdit(0), _idxEditBegin(0), _idxEditEnd(pDiffLine->GetEditList().size())
{
}

DiffLine::IteratorEdit::IteratorEdit(DiffLine *pDiffLine, const DiffLine::Hunk &hunk) :
	Iterator(false), _pDiffLine(pDiffLine),
	_idxEdit(hunk.idxEditBegin), _idxEditBegin(hunk.idxEditBegin), _idxEditEnd(hunk.idxEditEnd)
{
}

Iterator *DiffLine::IteratorEdit::GetSource()
{
	return nullptr;
}

bool DiffLine::IteratorEdit::DoNext(Environment &env, Value &value)
{
	if (_idxEdit >= _idxEditEnd) return false;
	value = Value(new Object_edit_at_line(_pDiffLine->Reference(), _idxEdit));
	_idxEdit++;
	return true;
}

String DiffLine::IteratorEdit::ToString() const
{
	String str;
	str += "diff.edit@line";
	return str;
}

void DiffLine::IteratorEdit::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// DiffChar
//-----------------------------------------------------------------------------
void DiffChar::Compose()
{
	init();
	onHuge();
	compose();
	String str;
	EditType editTypePrev = EDITTYPE_Copy;
	foreach_const (sesElemVec, pSesElem, getSes().getSequence()) {
		UInt64 ch = pSesElem->first;
		EditType editType = pSesElem->second.type;
		if (ch == '\n') {
			if (!str.empty()) {
				_pEditOwner->push_back(new Edit(editTypePrev, str));
				str.clear();
			}
			_pEditOwner->push_back(new Edit(editType, "\n"));
			editTypePrev = editType;
		} else {
			if (str.empty()) {
				editTypePrev = editType;
			} else if (editTypePrev != editType) {
				_pEditOwner->push_back(new Edit(editTypePrev, str));
				str.clear();
				editTypePrev = editType;
			}
			AppendUTF8(str, ch);
		}
	}
	if (!str.empty()) {
		_pEditOwner->push_back(new Edit(editTypePrev, str));
	}
}

void DiffChar::FeedChar(size_t iSeq, char ch)
{
	Sequence &seq = GetSequence(iSeq);
	seq.push_back(ch);
}

void DiffChar::FeedString(size_t iSeq, const char *src)
{
	UInt64 codeUTF8 = 0;
	Sequence &seq = GetSequence(iSeq);
	for (const char *p = src; *p != '\0'; ) {
		p = NextUTF8(p, codeUTF8);
		seq.push_back(codeUTF8);
	}
}

//-----------------------------------------------------------------------------
// DiffChar::IteratorEdit
//-----------------------------------------------------------------------------
DiffChar::IteratorEdit::IteratorEdit(EditOwner *pEditOwner, FilterType filterType) :
	Iterator(false), _pEditOwner(pEditOwner), _filterType(filterType),
	_idxEdit(0), _idxEditBegin(0), _idxEditEnd(pEditOwner->size())
{
}

Iterator *DiffChar::IteratorEdit::GetSource()
{
	return nullptr;
}

bool DiffChar::IteratorEdit::DoNext(Environment &env, Value &value)
{
	for ( ; _idxEdit < _idxEditEnd; _idxEdit++) {
		EditType editType = (*_pEditOwner)[_idxEdit]->GetEditType();
		if (editType == EDITTYPE_Copy || _filterType == FILTERTYPE_None ||
			(_filterType == FILTERTYPE_Original && editType == EDITTYPE_Delete) ||
			(_filterType == FILTERTYPE_New && editType == EDITTYPE_Add)) {
			value = Value(new Object_edit_at_char((*_pEditOwner)[_idxEdit]->Reference()));
			_idxEdit++;
			return true;
		}
	}
	return false;
}

String DiffChar::IteratorEdit::ToString() const
{
	String str;
	str += "diff.edit@char";
	return str;
}

void DiffChar::IteratorEdit::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// DiffChar::EditOwner
//-----------------------------------------------------------------------------
DiffChar::EditOwner::~EditOwner()
{
	Clear();
}

void DiffChar::EditOwner::Clear()
{
	foreach (EditOwner, ppEdit, *this) {
		Edit::Delete(*ppEdit);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Sync
//-----------------------------------------------------------------------------
void Sync::Compose(DiffLine *pDiffLine)
{
	enum Region {
		REGION_Copy,
		REGION_Add,
		REGION_Delete,
		REGION_Change,
	} region = REGION_Copy;
	const DiffLine::EditList &editList = pDiffLine->GetEditList();
	DiffLine::EditList::const_iterator pEditLineBegin = editList.end();
	foreach_const (DiffLine::EditList, pEditLine, editList) {
		const String &str = pEditLine->first;
		const EditType editType = pEditLine->second.type;
		Gura_BeginPushbackRegion();
		switch (region) {
		case REGION_Copy: {
			if (editType == EDITTYPE_Copy) {
				SyncLine *pSyncLine = new SyncLine(EDITTYPE_Copy);
				pSyncLine->AddEditChar(new DiffChar::Edit(EDITTYPE_Copy, str));
				_syncLinesOrg.push_back(pSyncLine);
				_syncLinesNew.push_back(pSyncLine->Reference());
			} else if (editType == EDITTYPE_Add) {
				pEditLineBegin = pEditLine;
				Gura_Pushback();
				region = REGION_Add;
			} else if (editType == EDITTYPE_Delete) {
				pEditLineBegin = pEditLine;
				Gura_Pushback();
				region = REGION_Delete;
			}
			break;
		}
		case REGION_Add: {
			if (editType == EDITTYPE_Copy) {
				DiffLine::EditList::const_iterator pEditLineEnd = pEditLine;
				for (DiffLine::EditList::const_iterator pEditLine = pEditLineBegin;
					 pEditLine != pEditLineEnd; pEditLine++) {
					SyncLine *pSyncLineOrg = new SyncLine(EDITTYPE_Add);
					SyncLine *pSyncLineNew = new SyncLine(EDITTYPE_Add);
					pSyncLineNew->AddEditChar(new DiffChar::Edit(EDITTYPE_Copy, str));
					_syncLinesOrg.push_back(pSyncLineOrg);
					_syncLinesNew.push_back(pSyncLineNew);
				}
				Gura_Pushback();
				region = REGION_Copy;
			} else if (editType == EDITTYPE_Add) {
				// nothing to do
			} else if (editType == EDITTYPE_Delete) {
				region = REGION_Change;
			}
			break;
		}
		case REGION_Delete: {
			if (editType == EDITTYPE_Copy) {
				DiffLine::EditList::const_iterator pEditLineEnd = pEditLine;
				for (DiffLine::EditList::const_iterator pEditLine = pEditLineBegin;
					 pEditLine != pEditLineEnd; pEditLine++) {
					SyncLine *pSyncLineOrg = new SyncLine(EDITTYPE_Delete);
					SyncLine *pSyncLineNew = new SyncLine(EDITTYPE_Delete);
					_syncLinesOrg.push_back(pSyncLineOrg);
					_syncLinesNew.push_back(pSyncLineNew);
					pSyncLineOrg->AddEditChar(new DiffChar::Edit(EDITTYPE_Delete, str));
				}
				Gura_Pushback();
				region = REGION_Copy;
			} else if (editType == EDITTYPE_Add) {
				region = REGION_Change;
			} else if (editType == EDITTYPE_Delete) {
				// nothing to do
			}
			break;
		}
		case REGION_Change: {
			if (editType == EDITTYPE_Copy) {
				DiffLine::EditList::const_iterator pEditLineEnd = pEditLine;
				AutoPtr<DiffChar> pDiffChar(pDiffLine->CreateDiffChar(
												pEditLineBegin, pEditLineEnd));
				SyncLine *pSyncLineOrg = nullptr;
				SyncLine *pSyncLineNew = nullptr;
				foreach_const (DiffChar::EditOwner, ppEditChar, pDiffChar->GetEditOwner()) {
					const DiffChar::Edit *pEditChar = *ppEditChar;
					if (pSyncLineOrg == nullptr) {
						pSyncLineOrg = new SyncLine(EDITTYPE_Change);
						pSyncLineNew = new SyncLine(EDITTYPE_Change);
						_syncLinesOrg.push_back(pSyncLineOrg);
						_syncLinesNew.push_back(pSyncLineNew);
					}
					if (pEditChar->IsEOL()) {
						pSyncLineOrg = nullptr;
						pSyncLineNew = nullptr;
					} else if (pEditChar->GetEditType() == EDITTYPE_Copy) {
						pSyncLineOrg->AddEditChar(pEditChar->Reference());
						pSyncLineNew->AddEditChar(pEditChar->Reference());
					} else if (pEditChar->GetEditType() == EDITTYPE_Add) {
						pSyncLineNew->AddEditChar(pEditChar->Reference());
					} else if (pEditChar->GetEditType() == EDITTYPE_Delete) {
						pSyncLineOrg->AddEditChar(pEditChar->Reference());
					}
				}
				Gura_Pushback();
				region = REGION_Copy;
			} else if (editType == EDITTYPE_Add) {
				// nothing to do
			} else if (editType == EDITTYPE_Delete) {
				// nothing to do
			}
			break;
		}
		}
		Gura_EndPushbackRegion();
	}
}

//-----------------------------------------------------------------------------
// SyncLineOwner
//-----------------------------------------------------------------------------
SyncLineOwner::~SyncLineOwner()
{
	Clear();
}

void SyncLineOwner::Clear()
{
	foreach (SyncLineOwner, ppSyncLine, *this) {
		SyncLine::Delete(*ppSyncLine);
	}
	clear();
}

//-----------------------------------------------------------------------------
// IteratorSyncLine
//-----------------------------------------------------------------------------
IteratorSyncLine::IteratorSyncLine(Sync *pSync, Target target) :
	Iterator(false), _pSync(pSync), _idxSyncLine(0), _idxSyncLineBegin(0),
	_syncLines(pSync->GetSyncLines(target))
{
	_idxSyncLineEnd = _syncLines.size();
}

Iterator *IteratorSyncLine::GetSource()
{
	return nullptr;
}

bool IteratorSyncLine::DoNext(Environment &env, Value &value)
{
	if (_idxSyncLine >= _idxSyncLineEnd) return false;
	value = Value(new Object_syncline(_syncLines[_idxSyncLine]->Reference()));
	_idxSyncLine++;
	return true;
}

String IteratorSyncLine::ToString() const
{
	String str;
	str += "diff.syncline";
	return str;
}

void IteratorSyncLine::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Object_diff_at_line
//-----------------------------------------------------------------------------
Object *Object_diff_at_line::Clone() const
{
	return nullptr;
}

bool Object_diff_at_line::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(distance));
	symbols.insert(Gura_UserSymbol(edits));
	symbols.insert(Gura_UserSymbol(nlines_at_org));
	symbols.insert(Gura_UserSymbol(nlines_at_new));
	return true;
}

Value Object_diff_at_line::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(distance))) {
		return Value(_pDiffLine->GetEditDistance());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(edits))) {
		AutoPtr<DiffLine::IteratorEdit> pIterator(
			new DiffLine::IteratorEdit(_pDiffLine->Reference()));
		return Value(new Object_iterator(env, pIterator.release()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(nlines_at_org))) {
		return Value(_pDiffLine->GetSequence(0).size());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(nlines_at_new))) {
		return Value(_pDiffLine->GetSequence(1).size());
	}
	evaluatedFlag = false;
	return Value::Nil;
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
// diff.diff@line#eachhunk(format?:symbol, lines?:number) {block?}
Gura_DeclareMethod(diff_at_line, eachhunk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "lines", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an iterator that returns `diff.hunk@line` instance stored in the result.\n"
		"\n"
		"The argument `format` takes one of the symbols that specifies the hunk format:\n"
		"\n"
		"- `` `normal`` .. Normal format (not supported yet).\n"
		"- `` `context`` .. Context format (not supported yet).\n"
		"- `` `unified`` .. Unified format. This is the default.\n"
		"\n"
		"The argument `lines` specifies a number of common lines appended before and after\n"
		"different lines\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(diff_at_line, eachhunk)
{
	Signal &sig = env.GetSignal();
	DiffLine *pDiffLine = Object_diff_at_line::GetObjectThis(args)->GetDiffLine();
	DiffLine::Format format = DiffLine::FORMAT_Unified;
	if (args.IsValid(0)) {
		format = DiffLine::SymbolToFormat(sig, args.GetSymbol(0));
		if (format == DiffLine::FORMAT_None) return Value::Nil;
	}
	size_t nLinesCommon = args.IsValid(1)? args.GetSizeT(1) : 3;
	AutoPtr<DiffLine::IteratorHunk> pIterator(
		new DiffLine::IteratorHunk(pDiffLine->Reference(), format, nLinesCommon));
	return ReturnIterator(env, args, pIterator.release());
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
	Signal &sig = env.GetSignal();
	DiffLine *pDiffLine = Object_diff_at_line::GetObjectThis(args)->GetDiffLine();
	DiffLine::Format format = DiffLine::FORMAT_Unified;
	if (args.IsValid(1)) {
		format = DiffLine::SymbolToFormat(sig, args.GetSymbol(1));
		if (format == DiffLine::FORMAT_None) return Value::Nil;
	}
	size_t nLinesCommon = args.IsValid(2)? args.GetSizeT(2) : 3;
	if (args.IsValid(0)) {
		Stream &streamOut = args.GetStream(0);
		pDiffLine->PrintHunks(sig, streamOut, format, nLinesCommon);
		return Value::Nil;
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
	Gura_AssignMethod(diff_at_line, eachhunk);
	Gura_AssignMethod(diff_at_line, render);
}

//-----------------------------------------------------------------------------
// Object_hunk_at_line
//-----------------------------------------------------------------------------
Object *Object_hunk_at_line::Clone() const
{
	return nullptr;
}

bool Object_hunk_at_line::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(edits));
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(lineno_at_org));
	symbols.insert(Gura_UserSymbol(lineno_at_new));
	symbols.insert(Gura_UserSymbol(nlines_at_org));
	symbols.insert(Gura_UserSymbol(nlines_at_new));
	symbols.insert(Gura_UserSymbol(diff_at_char));
	return true;
}

Value Object_hunk_at_line::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(edits))) {
		AutoPtr<Iterator> pIterator(new DiffLine::IteratorEdit(_pDiffLine->Reference(), _hunk));
		return Value(new Object_iterator(env, pIterator.release()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		const Symbol *pSymbol =
			_hunk.IsAdd()? Gura_UserSymbol(add) :
			_hunk.IsDelete()? Gura_UserSymbol(delete) :
			Gura_UserSymbol(change);
		return Value(pSymbol);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lineno_at_org))) {
		return Value(_hunk.linenoOrg);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lineno_at_new))) {
		return Value(_hunk.linenoNew);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(nlines_at_org))) {
		return Value(_hunk.nLinesOrg);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(nlines_at_new))) {
		return Value(_hunk.nLinesNew);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(diff_at_char))) {
		return Value(new Object_diff_at_char(GetDiffChar()->Reference()));
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_hunk_at_line::ToString(bool exprFlag)
{
	char buff[80];
	String str;
	str += "<diff.hunk@line:";
	str += _hunk.TextizeRange_Unified();
	str += ">";
	return str;
}

const DiffChar *Object_hunk_at_line::GetDiffChar()
{
	if (_pDiffChar.IsNull()) {
		_pDiffChar.reset(_pDiffLine->CreateDiffChar(_hunk.idxEditBegin, _hunk.idxEditEnd));
	}
	return _pDiffChar.get();
}

//-----------------------------------------------------------------------------
// Methods of diff.hunk@line
//-----------------------------------------------------------------------------
// diff.hunk@line#print(out?:stream:w):void
Gura_DeclareMethod(hunk_at_line, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Prints the content of the `diff.hunk` instance to the specified stream.\n");
}

Gura_ImplementMethod(hunk_at_line, print)
{
	Signal &sig = env.GetSignal();
	Object_hunk_at_line *pThis = Object_hunk_at_line::GetObjectThis(args);
	Stream &stream = args.IsValid(0)? args.GetStream(0) : *env.GetConsole();
	pThis->GetDiffLine()->PrintHunk(sig, stream, pThis->GetHunk());
	return Value::Nil;
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
	return nullptr;
}

bool Object_edit_at_line::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(mark_at_normal));
	symbols.insert(Gura_UserSymbol(mark_at_context));
	symbols.insert(Gura_UserSymbol(mark_at_unified));
	symbols.insert(Gura_UserSymbol(lineno_at_org));
	symbols.insert(Gura_UserSymbol(lineno_at_new));
	symbols.insert(Gura_UserSymbol(source));
	symbols.insert(Gura_UserSymbol(unified));
	return true;
}

Value Object_edit_at_line::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	const DiffLine::Edit &edit = _pDiffLine->GetEdit(_idxEdit);
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		if (edit.second.type == EDITTYPE_Add) {
			return Value(Gura_UserSymbol(add));
		} else if (edit.second.type == EDITTYPE_Delete) {
			return Value(Gura_UserSymbol(delete));
		} else {
			return Value(Gura_UserSymbol(copy));
		}
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mark_at_normal))) {
		return Value(GetEditMark_Normal(edit.second.type));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mark_at_context))) {
		return Value(GetEditMark_Context(edit.second.type));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mark_at_unified))) {
		return Value(GetEditMark_Unified(edit.second.type));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lineno_at_org))) {
		return Value(edit.second.beforeIdx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(lineno_at_new))) {
		return Value(edit.second.afterIdx);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(source))) {
		return Value(DiffLine::GetEditSource(edit));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(unified))) {
		return Value(DiffLine::TextizeEdit_Unified(edit));
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_edit_at_line::ToString(bool exprFlag)
{
	const DiffLine::Edit &edit = _pDiffLine->GetEdit(_idxEdit);
	String str;
	str += "<diff.edit@line:";
	if (edit.second.type == EDITTYPE_Add) {
		str += "add";
	} else if (edit.second.type == EDITTYPE_Delete) {
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
	Signal &sig = env.GetSignal();
	Object_edit_at_line *pThis = Object_edit_at_line::GetObjectThis(args);
	Stream &stream = args.IsValid(0)? args.GetStream(0) : *env.GetConsole();
	stream.Println(sig, DiffLine::TextizeEdit_Unified(pThis->GetEdit()).c_str());
	return Value::Nil;
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
// Object_diff_at_char
//-----------------------------------------------------------------------------
Object *Object_diff_at_char::Clone() const
{
	return nullptr;
}

bool Object_diff_at_char::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(distance));
	symbols.insert(Gura_UserSymbol(edits));
	symbols.insert(Gura_UserSymbol(edits_at_org));
	symbols.insert(Gura_UserSymbol(edits_at_new));
	return true;
}

Value Object_diff_at_char::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(distance))) {
		return Value(_pDiffChar->GetEditDistance());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(edits))) {
		AutoPtr<DiffChar::IteratorEdit> pIterator(
			new DiffChar::IteratorEdit(_pDiffChar->GetEditOwner().Reference(), FILTERTYPE_None));
		return Value(new Object_iterator(env, pIterator.release()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(edits_at_org))) {
		AutoPtr<DiffChar::IteratorEdit> pIterator(
			new DiffChar::IteratorEdit(_pDiffChar->GetEditOwner().Reference(), FILTERTYPE_Original));
		return Value(new Object_iterator(env, pIterator.release()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(edits_at_new))) {
		AutoPtr<DiffChar::IteratorEdit> pIterator(
			new DiffChar::IteratorEdit(_pDiffChar->GetEditOwner().Reference(), FILTERTYPE_New));
		return Value(new Object_iterator(env, pIterator.release()));
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_diff_at_char::ToString(bool exprFlag)
{
	char buff[80];
	String str;
	str += "<diff.diff@char:";
	::sprintf(buff, "dist=%lld", _pDiffChar->GetEditDistance());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.diff@char
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(diff_at_char)
{
	Gura_AssignValueEx("diff@char", Value(Reference()));
}

//-----------------------------------------------------------------------------
// Object_edit_at_char
//-----------------------------------------------------------------------------
Object *Object_edit_at_char::Clone() const
{
	return nullptr;
}

bool Object_edit_at_char::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(type));
	symbols.insert(Gura_UserSymbol(mark_at_normal));
	symbols.insert(Gura_UserSymbol(mark_at_context));
	symbols.insert(Gura_UserSymbol(mark_at_unified));
	symbols.insert(Gura_UserSymbol(source));
	symbols.insert(Gura_UserSymbol(unified));
	return true;
}

Value Object_edit_at_char::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(type))) {
		if (_pEdit->GetEditType() == EDITTYPE_Add) {
			return Value(Gura_UserSymbol(add));
		} else if (_pEdit->GetEditType() == EDITTYPE_Delete) {
			return Value(Gura_UserSymbol(delete));
		} else {
			return Value(Gura_UserSymbol(copy));
		}
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mark_at_normal))) {
		return Value(GetEditMark_Normal(_pEdit->GetEditType()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mark_at_context))) {
		return Value(GetEditMark_Context(_pEdit->GetEditType()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mark_at_unified))) {
		return Value(GetEditMark_Unified(_pEdit->GetEditType()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(source))) {
		return Value(_pEdit->GetSource());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_edit_at_char::ToString(bool exprFlag)
{
	String str;
	str += "<diff.edit@char:";
	if (_pEdit->GetEditType() == EDITTYPE_Add) {
		str += "add";
	} else if (_pEdit->GetEditType() == EDITTYPE_Delete) {
		str += "delete";
	} else {
		str += "copy";
	}
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.edit@char
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(edit_at_char)
{
	Gura_AssignValueEx("edit@char", Value(Reference()));
}

//-----------------------------------------------------------------------------
// Object_sync
//-----------------------------------------------------------------------------
Object *Object_sync::Clone() const
{
	return nullptr;
}

bool Object_sync::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(synclines_at_org));
	symbols.insert(Gura_UserSymbol(synclines_at_new));
	return true;
}

Value Object_sync::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(synclines_at_org))) {
		AutoPtr<Iterator> pIterator(new IteratorSyncLine(_pSync->Reference(), TARGET_Org));
		return Value(new Object_iterator(env, pIterator.release()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(synclines_at_new))) {
		AutoPtr<Iterator> pIterator(new IteratorSyncLine(_pSync->Reference(), TARGET_New));
		return Value(new Object_iterator(env, pIterator.release()));
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_sync::ToString(bool exprFlag)
{
	String str;
	str += "<diff.sync";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.sync
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(sync)
{
}

//-----------------------------------------------------------------------------
// Object_syncline
//-----------------------------------------------------------------------------
Object *Object_syncline::Clone() const
{
	return nullptr;
}

bool Object_syncline::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(edits));
	return true;
}

Value Object_syncline::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(edits))) {
		AutoPtr<Iterator> pIterator(new DiffChar::IteratorEdit(
										_pSyncLine->GetEditOwner().Reference(), FILTERTYPE_None));
		return Value(new Object_iterator(env, pIterator.release()));
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_syncline::ToString(bool exprFlag)
{
	String str;
	str += "<diff.syncline";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Class implementation for diff.syncline
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(syncline)
{
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// diff.compose(src1, src2):[icase,sync] {block?}
Gura_DeclareFunction(compose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src1", VTYPE_any);
	DeclareArg(env, "src2", VTYPE_any);
	DeclareAttr(Gura_Symbol(icase));
	DeclareAttr(Gura_UserSymbol(sync));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Extracts differences between two sets of line sequence and returns `diff.diff@line` instance\n"
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
		GURA_HELPTEXT_BLOCK_en("d", "diff.diff@line")
		"\n"
		"If attribute `:icase` is specified, it wouldn't distinguish\n"
		"upper and lower case of characters.\n");
}

Gura_ImplementFunction(compose)
{
	Signal &sig = env.GetSignal();
	bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
	bool syncFlag = args.IsSet(Gura_UserSymbol(sync));
	AutoPtr<DiffLine> pDiffLine(new DiffLine(ignoreCaseFlag));
	for (size_t i = 0; i < 2; i++) {
		if (args.IsType(i, VTYPE_string)) {
			pDiffLine->FeedString(i, args.GetString(i));
		} else if (args.IsType(i, VTYPE_stream)) {
			if (!pDiffLine->FeedStream(sig, i, args.GetStream(i))) {
				return Value::Nil;
			}
		} else if (args.IsType(i, VTYPE_iterator)) {
			AutoPtr<Iterator> pIterator(args.GetIterator(i)->Clone());
			if (!pDiffLine->FeedIterator(env, sig, i, pIterator.get())) {
				return Value::Nil;
			}				
		} else if (args.IsType(i, VTYPE_list)) {
			pDiffLine->FeedList(i, args.GetList(i));
		} else {
			sig.SetError(ERR_TypeError, "difference source must be string or stream");
			return Value::Nil;
		}
	}
	pDiffLine->Compose();
	Value value;
	if (syncFlag) {
		AutoPtr<Sync> pSync(new Sync());
		pSync->Compose(pDiffLine.get());
		value = Value(new Object_sync(pSync.release()));
	} else {
		value = Value(new Object_diff_at_line(pDiffLine.release()));
	}
	return ReturnValue(env, args, value);
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
		"Extracts differences between two strings and returns `diff.diff@line` instance\n"
		"that contains the difference information.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("d", "diff.diff@char")
		"\n"
		"If attribute `:icase` is specified, it wouldn't distinguish\n"
		"upper and lower case of characters.\n");
}

Gura_ImplementFunction(compose_at_char)
{
	bool ignoreCaseFlag = args.IsSet(Gura_Symbol(icase));
	AutoPtr<DiffChar> pDiffChar(new DiffChar(ignoreCaseFlag));
	pDiffChar->FeedString(0, args.GetString(0));
	pDiffChar->FeedString(1, args.GetString(1));
	pDiffChar->Compose();
	return ReturnValue(env, args, Value(new Object_diff_at_char(pDiffChar.release())));
}

//-----------------------------------------------------------------------------
// Utilities
//-----------------------------------------------------------------------------
const char *GetEditMark_Normal(EditType editType)
{
	return (editType == EDITTYPE_Add)? ">" : (editType == EDITTYPE_Delete)? "<" : " ";
}

const char *GetEditMark_Context(EditType editType)
{
	return (editType == EDITTYPE_Add)? "+" : (editType == EDITTYPE_Delete)? "-" :
		(editType == EDITTYPE_Change)? "!" : " ";
}

const char *GetEditMark_Unified(EditType editType)
{
	return (editType == EDITTYPE_Add)? "+" : (editType == EDITTYPE_Delete)? "-" : " ";
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(add);
	Gura_RealizeUserSymbol(change);
	Gura_RealizeUserSymbol(context);
	Gura_RealizeUserSymbol(copy);
	Gura_RealizeUserSymbol(delete);
	Gura_RealizeUserSymbolAlias(diff_at_char, "diff@char");
	Gura_RealizeUserSymbolAlias(diff_at_line, "diff@line");
	Gura_RealizeUserSymbol(distance);
	Gura_RealizeUserSymbol(edits);
	Gura_RealizeUserSymbolAlias(edits_at_org, "edits@org");
	Gura_RealizeUserSymbolAlias(edits_at_new, "edits@new");
	Gura_RealizeUserSymbolAlias(lineno_at_org, "lineno@org");
	Gura_RealizeUserSymbolAlias(lineno_at_new, "lineno@new");
	Gura_RealizeUserSymbolAlias(mark_at_normal, "mark@normal");
	Gura_RealizeUserSymbolAlias(mark_at_context, "mark@context");
	Gura_RealizeUserSymbolAlias(mark_at_unified, "mark@unified");
	Gura_RealizeUserSymbolAlias(nlines_at_org, "nlines@org");
	Gura_RealizeUserSymbolAlias(nlines_at_new, "nlines@new");
	Gura_RealizeUserSymbol(normal);
	Gura_RealizeUserSymbol(source);
	Gura_RealizeUserSymbol(sync);
	Gura_RealizeUserSymbolAlias(synclines_at_org, "synclines@org");
	Gura_RealizeUserSymbolAlias(synclines_at_new, "synclines@new");
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(unified);
	// class realization
	Gura_RealizeUserClassAlias(diff_at_line, "diff@line", env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassAlias(hunk_at_line, "hunk@line", env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassAlias(edit_at_line, "edit@line", env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassAlias(diff_at_char, "diff@char", env.LookupClass(VTYPE_object));
	Gura_RealizeUserClassAlias(edit_at_char, "edit@char", env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(sync, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(syncline, env.LookupClass(VTYPE_object));
	// class preparation
	Gura_PrepareUserClass(diff_at_line);
	Gura_PrepareUserClass(hunk_at_line);
	Gura_PrepareUserClass(edit_at_line);
	Gura_PrepareUserClass(diff_at_char);
	Gura_PrepareUserClass(edit_at_char);
	Gura_PrepareUserClass(sync);
	Gura_PrepareUserClass(syncline);
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
