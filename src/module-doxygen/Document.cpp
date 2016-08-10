//=============================================================================
// Document.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
Document::Document() : _cntRef(1), _cntContLineDoxygen(0), _col(0), _stat(STAT_Indent),
	_tabSize(4), _commentLineFlag(false), _regionPrev(RGN_Other),
	_pStructureOwner(new StructureOwner())
{
}

bool Document::ReadStream(Environment &env, SimpleStream &stream,
						  const Aliases *pAliases, bool extractedFlag)
{
	Signal &sig = env.GetSignal();
	_pParser.reset(new Parser(pAliases));
	if (extractedFlag) {
		AddStructure(false);
		_stat = STAT_ExIndent;
	} else {
		_stat = STAT_Indent;
	}
	for (;;) {
		int chRaw;
		if ((chRaw = stream.GetChar(sig)) < 0) chRaw = 0;
		char ch = static_cast<char>(static_cast<UChar>(chRaw));
		if (!FeedChar(env, ch)) return false;
		if (ch == '\0') break;
	}
	_sourceName = stream.GetName();
	_pParser.reset();
	return true;
}

bool Document::FeedChar(Environment &env, char ch)
{
	Gura_BeginPushbackRegion();
	//::printf("ch=%c, stat=%d\n", ch, _stat);
	switch (_stat) {
	case STAT_Indent: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '\n') {
			ClearCol();
			_strLine.clear();
			_regionPrev = RGN_Other;
		} else if (ch == ' ' || ch == '\t') {
			AdvanceCol(ch);
		} else if (ch == '/') {
			// parsed "/" after indentation
			AdvanceCol();
			_commentLineFlag = true;
			_stat = STAT_Slash;
		} else {
			_stat = STAT_Source;
			Gura_Pushback();
		}
		break;
	}
	case STAT_Source: {
		if (ch == '/') {
			// parsed "/" after some source code
			AdvanceCol();
			_commentLineFlag = false;
			_stat = STAT_Slash;
		} else if (ch == '\n') {
			ClearCol();
			_strLine.clear();
			_regionPrev = RGN_Other;
			_stat = STAT_Indent;
		} else { // including '\0'
			AdvanceCol();
		}
		break;
	}
	case STAT_Slash: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '/') {
			// parsed "//"
			AdvanceCol();
			_stat = STAT_LineCommentBgn;
		} else if (ch == '*') {
			// parsed "/*"
			AdvanceCol();
			_stat = STAT_BlockCommentBgn;
		} else {
			// parsed "/."
			_commentLineFlag = false;
			Gura_Pushback();
			_stat = STAT_Source;
		}
		break;
	}
	case STAT_LineCommentBgn: {
		if (ch == '/') {
			// parsed "///"
			AdvanceCol();
			_stat = STAT_LineCommentBgn_Slash;
		} else if (ch == '!') {
			// parsed "//!"
			AdvanceCol();
			_stat = STAT_LineDoxygenFirstChar;
		} else { // including '\0'
			// parsed "//."
			_regionPrev = RGN_Other;
			Gura_Pushback();
			_stat = STAT_LineComment;
		}
		break;
	}
	case STAT_LineCommentBgn_Slash: {
		if (ch == '/') {
			AdvanceCol();
		} else {
			Gura_Pushback();
			_stat = STAT_LineDoxygenFirstChar;
		}
		break;
	}
	case STAT_LineDoxygenFirstChar: {
		bool afterMemberFlag = false;
		if (ch == '<') {
			AdvanceCol();
			afterMemberFlag = !_commentLineFlag;
		} else {
			Gura_Pushback();
		}
		if (_regionPrev == RGN_LineDoxygen) {
			_cntContLineDoxygen++;
		} else if (_regionPrev == RGN_LineDoxygenAndBlankLine) {
			ConvertToBrief();
			_cntContLineDoxygen++;
		} else {
			AddStructure(afterMemberFlag);
			_cntContLineDoxygen = 0;
		}
		_regionPrev = _commentLineFlag? RGN_LineDoxygen : RGN_LineDoxygenTrail;
		_stat = STAT_LineDoxygen;
		break;
	}
	case STAT_LineDoxygen: {
		if (ch == '\0') {
			if (!_pParser->FeedChar(env, '\0')) return false;
		} else if (ch == '\n') {
			// a line comment ends with newline.
			_strLine += '\n';
			//_lineOwner.push_back(new Line(_col, _strLine));
			if (!_pParser->FeedChar(env, '\n')) return false;
			if (!_pParser->FeedChar(env, '\0')) return false;
			ClearCol();
			_strLine.clear();
			_stat = (_regionPrev == RGN_LineDoxygen && _cntContLineDoxygen == 0)?
				STAT_LineDoxygenPost : STAT_Indent;
		} else {
			_strLine += ch;
			if (!_pParser->FeedChar(env, ch)) return false;
		}
		break;
	}
	case STAT_LineDoxygenPost: {
		if (ch == '\n') {
			// blank line is detected
			ClearCol();
			_strLine.clear();
			_regionPrev = RGN_LineDoxygenAndBlankLine;
			_stat = STAT_Indent;
		} else if (ch == ' ') {
			// nothing to do
		} else if (ch == '\t') {
			// nothing to do
		} else {
			Gura_Pushback();
			_stat = STAT_Indent;
		}
		break;
	}
	case STAT_LineComment: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '\n') {
			// a line comment ends with newline.
			ClearCol();
			_strLine.clear();
			_stat = STAT_Indent;
		} else {
			AdvanceCol(ch);
		}
		break;
	}
	case STAT_BlockCommentBgn: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '*') {
			// parsed "/**"
			AdvanceCol();
			_stat = STAT_BlockCommentBgn_Asterisk;
		} else if (ch == '!') {
			// parsed "/*!"
			AdvanceCol();
			_stat = STAT_BlockDoxygenFirstChar;
		} else {
			// parsed "/*."
			Gura_Pushback();
			_regionPrev = RGN_Other;
			_stat = STAT_BlockComment;
		}
		break;
	}
	case STAT_BlockCommentBgn_Asterisk: {
		if (ch == '/') {
			// parsed "/***...**/"
			AdvanceCol();
			_stat = STAT_Source;
		} else if (ch == '*') {
			AdvanceCol();
		} else {
			// parsed "/**."
			Gura_Pushback();
			_stat = STAT_BlockDoxygenFirstChar;
		}
		break;
	}
	case STAT_BlockDoxygenFirstChar: {
		bool afterMemberFlag = false;
		if (ch == '<') {
			AdvanceCol();
			afterMemberFlag = !_commentLineFlag;
		} else {
			Gura_Pushback();
		}
		if (_regionPrev == RGN_LineDoxygen) {
			if (_cntContLineDoxygen == 0) ConvertToBrief();
		} else {
			AddStructure(afterMemberFlag);
		}
		_regionPrev = _commentLineFlag? RGN_BlockDoxygen : RGN_BlockDoxygenTrail;
		_stat = STAT_BlockDoxygen;
		break;
	}
	case STAT_BlockDoxygen: {
		if (ch == '\0') {
			if (!_pParser->FeedChar(env, '\0')) return false;
		} else if (ch == '*') {
			_strAhead.clear();
			_strAhead += ch;
			_stat = STAT_BlockDoxygen_Asterisk;
		} else if (ch == '\n') {
			_strLine += '\n';
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!_pParser->FeedChar(env, ch)) return false;
			ClearCol();
			_strLine.clear();
			_stat = STAT_BlockDoxygen_Indent;
		} else {
			_strLine += ch;
			if (!_pParser->FeedChar(env, ch)) return false;
		}
		break;
	}
	case STAT_BlockDoxygen_Asterisk: {
		if (ch == '/') {
			// parsed "***.../"
			if (!_pParser->FeedChar(env, '\0')) return false;
			_stat = STAT_Source;
		} else if (ch == '*') {
			// parsed "***..."
			_strAhead += ch;
		} else { // including '\0'
			// parsed "***...?"
			if (!_pParser->FeedString(env, _strAhead.c_str())) return false;
			Gura_Pushback();
			_stat = STAT_BlockDoxygen;
		}
		break;
	}
	case STAT_BlockDoxygen_Indent: {
		if (ch == '\0') {
			if (!_pParser->FeedChar(env, '\0')) return false;
		} else if (ch == '\n') {
			_strLine += '\n';
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!_pParser->FeedChar(env, ch)) return false;
			ClearCol();
			_strLine.clear();
		} else if (ch == ' ') {
			// nothing to do
		} else if (ch == '\t') {
			// nothing to do
		} else if (ch == '*') {
			_stat = STAT_BlockDoxygen_IndentAsterisk;
		} else {
			Gura_Pushback();
			_stat = STAT_BlockDoxygen;
		}
		break;
	}
	case STAT_BlockDoxygen_IndentAsterisk: {
		if (ch == '/') {
			if (!_pParser->FeedChar(env, '\0')) return false;
			_stat = STAT_Source;
		} else {
			Gura_Pushback();
			_stat = STAT_BlockDoxygen_IndentAfterAsterisk;
		}
		break;
	}
	case STAT_BlockDoxygen_IndentAfterAsterisk: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '\n') {
			_strLine += '\n';
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!_pParser->FeedChar(env, ch)) return false;
			ClearCol();
			_strLine.clear();
			_stat = STAT_BlockDoxygen_Indent;
		} else if (ch == ' ') {
			// nothing to do
		} else if (ch == '\t') {
			// nothing to do
		} else {
			Gura_Pushback();
			_stat = STAT_BlockDoxygen;
		}
		break;
	}
	case STAT_BlockComment: {
		if (ch == '*') {
			_stat = STAT_BlockComment_Asterisk;
		} else { // including '\0'
			// nothing to do
		}
		break;
	}
	case STAT_BlockComment_Asterisk: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '/') {
			_stat = STAT_Source;
		} else {
			_stat = STAT_BlockComment;
		}
		break;
	}
	case STAT_ExIndent: {
		if (ch == '\0') {
			if (!_pParser->FeedChar(env, '\0')) return false;
		} else if (ch == '\n') {
			_strLine += '\n';
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!_pParser->FeedChar(env, ch)) return false;
			ClearCol();
			_strLine.clear();
		} else if (ch == ' ') {
			// nothing to do
		} else if (ch == '\t') {
			// nothing to do
		} else {
			_stat = STAT_ExDoxygen;
			Gura_Pushback();
		}
		break;
	}
	case STAT_ExDoxygen: {
		if (ch == '\0') {
			if (!_pParser->FeedChar(env, '\0')) return false;
		} else if (ch == '\n') {
			_strLine += '\n';
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!_pParser->FeedChar(env, ch)) return false;
			ClearCol();
			_strLine.clear();
			_stat = STAT_ExIndent;
		} else {
			_strLine += ch;
			if (!_pParser->FeedChar(env, ch)) return false;
		}
		break;
	}
	}
	Gura_EndPushbackRegion();
	return true;
}

void Document::AddStructure(bool afterMemberFlag)
{
	Structure *pStructure = new Structure(afterMemberFlag);
	_pStructureOwner->push_back(pStructure);
	_pParser->SetElemOwner(pStructure->GetElemOwner().Reference());
}

void Document::ConvertToBrief()
{
	ElemOwner &elemOwner = _pStructureOwner->back()->GetElemOwner();
	if (elemOwner.size() != 1) return;
	Elem *pElemOrg = elemOwner.front();
	if (pElemOrg->GetType() != Elem::TYPE_Text) return;
	Elem_Command *pElemNew = new Elem_Command(CommandFormat::Brief);
	pElemNew->GetElemArgs().push_back(pElemOrg->ReduceContent()->Reference());
	elemOwner[0] = pElemNew;
	Elem::Delete(pElemOrg);
}

//-----------------------------------------------------------------------------
// Document::Line
//-----------------------------------------------------------------------------
bool Document::Line::FeedToParser(Environment &env, Parser *pParser) const
{
	for (int i = 0; i < _col; i++) {
		if (!pParser->FeedChar(env, ' ')) return false;
	}
	return pParser->FeedString(env, _str.c_str());
}

//-----------------------------------------------------------------------------
// Document::LineList
//-----------------------------------------------------------------------------
void Document::LineList::AdjustCol()
{
	int colMin = 0;
	foreach (LineList, ppLine, *this) {
		Line *pLine = *ppLine;
		int col = pLine->GetCol();
		if (ppLine == begin() || colMin < col) colMin = col;
	}
	foreach (LineList, ppLine, *this) {
		Line *pLine = *ppLine;
		pLine->SetCol(pLine->GetCol() - colMin);
	}
}

bool Document::LineList::FeedToParser(Environment &env, Parser *pParser, bool flushFlag) const
{
	foreach_const (LineList, ppLine, *this) {
		const Line *pLine = *ppLine;
		if (!pLine->FeedToParser(env, pParser)) return false;
	}
	if (flushFlag && !pParser->FeedChar(env, '\0')) return false;
	return true;
}

//-----------------------------------------------------------------------------
// Document::LineOwner
//-----------------------------------------------------------------------------
Document::LineOwner::~LineOwner()
{
	Clear();
}

void Document::LineOwner::Clear()
{
	foreach (LineOwner, ppLine, *this) {
		delete *ppLine;
	}
	clear();
}

Gura_EndModuleScope(doxygen)
