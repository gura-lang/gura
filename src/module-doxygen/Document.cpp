//=============================================================================
// Document.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
Document::Document() : _cntRef(1), _cntContLineDoxygen(0), _col(0), _colAsterisk(-1),
	_stat(STAT_Indent), _tabSize(4), _commentLineFlag(false), _regionPrev(RGN_Other),
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
			NewLine();
			_regionPrev = RGN_Other;
		} else if (ch == ' ') {
			AdvanceColChar();
		} else if (ch == '\t') {
			AdvanceColTab();
		} else if (ch == '/') {
			// parsed "/" after indentation
			AdvanceColChar();
			_commentLineFlag = true;
			_stat = STAT_Slash;
		} else {
			_stat = STAT_Source;
			Gura_Pushback();
		}
		break;
	}
	case STAT_Source: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '/') {
			// parsed "/" after some source code
			AdvanceColChar();
			_commentLineFlag = false;
			_stat = STAT_Slash;
		} else if (ch == '\n') {
			_colAsterisk = -1;
			NewLine();
			_regionPrev = RGN_Other;
			_stat = STAT_Indent;
		} else if (ch == '\t') {
			AdvanceColTab();
		} else {
			AdvanceColChar();
		}
		break;
	}
	case STAT_Slash: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '/') {
			// parsed "//"
			AdvanceColChar();
			_stat = STAT_LineCommentBgn;
		} else if (ch == '*') {
			// parsed "/*"
			if (_colAsterisk < 0) {
				_colAsterisk = _col;
			}
			AdvanceColChar();
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
			AdvanceColChar();
			_stat = STAT_LineCommentBgn_Slash;
		} else if (ch == '!') {
			// parsed "//!"
			AdvanceColChar();
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
			AdvanceColChar();
		} else {
			Gura_Pushback();
			_stat = STAT_LineDoxygenFirstChar;
		}
		break;
	}
	case STAT_LineDoxygenFirstChar: {
		bool afterMemberFlag = false;
		if (ch == '<') {
			AdvanceColChar();
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
		_stat = STAT_LineDoxygen_Indent;
		break;
	}
	case STAT_LineDoxygen: {
		if (ch == '\0') {
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!FlushLines(env)) return false;
		} else if (ch == '\n') {
			// a line comment ends with newline.
			_strLine += '\n';
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!FlushLines(env)) return false;
			_stat = (_regionPrev == RGN_LineDoxygen && _cntContLineDoxygen == 0)?
				STAT_LineDoxygenPost : STAT_Indent;
		} else {
			_strLine += ch;
		}
		break;
	}
	case STAT_LineDoxygen_Indent: {
		if (ch == ' ') {
			AdvanceColChar();
		} else if (ch == '\t') {
			AdvanceColTab();
		} else {
			Gura_Pushback();
			_stat = STAT_LineDoxygen;
		}
		break;
	}
	case STAT_LineDoxygenPost: {
		if (ch == '\n') {
			// blank line is detected
			NewLine();
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
			NewLine();
			_stat = STAT_Indent;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_BlockCommentBgn: {
		if (ch == '\0') {
			_colAsterisk = -1;
		} else if (ch == '*') {
			// parsed "/**"
			AdvanceColChar();
			_stat = STAT_BlockCommentBgn_Asterisk;
		} else if (ch == '!') {
			// parsed "/*!"
			AdvanceColChar();
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
			AdvanceColChar();
			_stat = STAT_Source;
		} else if (ch == '*') {
			AdvanceColChar();
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
			AdvanceColChar();
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
		_stat = STAT_BlockDoxygen_Indent;
		break;
	}
	case STAT_BlockDoxygen: {
		if (ch == '\0') {
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!FlushLines(env)) return false;
		} else if (ch == '*') {
			_strAhead.clear();
			_strAhead += ch;
			_stat = STAT_BlockDoxygen_Asterisk;
		} else if (ch == '\n') {
			_strLine += '\n';
			_lineOwner.push_back(new Line(_col, _strLine));
			NewLine();
			_stat = STAT_BlockDoxygen_Indent;
		} else {
			_strLine += ch;
		}
		break;
	}
	case STAT_BlockDoxygen_Asterisk: {
		if (ch == '/') {
			// parsed "***.../"
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!FlushLines(env)) return false;
			_stat = STAT_Source;
		} else if (ch == '*') {
			// parsed "***..."
			_strAhead += ch;
		} else { // including '\0'
			// parsed "***...?"
			_strLine += _strAhead;
			Gura_Pushback();
			_stat = STAT_BlockDoxygen;
		}
		break;
	}
	case STAT_BlockDoxygen_Indent: {
		if (ch == ' ') {
			AdvanceColChar();
		} else if (ch == '\t') {
			AdvanceColTab();
		} else if (ch == '*' && _col == _colAsterisk) {
			AdvanceColChar();
			_stat = STAT_BlockDoxygen_IndentAsterisk;
		} else {
			Gura_Pushback();
			_stat = STAT_BlockDoxygen;
		}
		break;
	}
	case STAT_BlockDoxygen_IndentAsterisk: {
		if (ch == '/') {
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!FlushLines(env)) return false;
			_stat = STAT_Source;
		} else {
			Gura_Pushback();
			_stat = STAT_BlockDoxygen_Indent;
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
		if (ch == ' ') {
			AdvanceColChar();
		} else if (ch == '\t') {
			AdvanceColTab();
		} else {
			_stat = STAT_ExDoxygen;
			Gura_Pushback();
		}
		break;
	}
	case STAT_ExDoxygen: {
		if (ch == '\0') {
			_lineOwner.push_back(new Line(_col, _strLine));
			if (!FlushLines(env)) return false;
		} else if (ch == '\n') {
			_strLine += '\n';
			_lineOwner.push_back(new Line(_col, _strLine));
			NewLine();
			_stat = STAT_ExIndent;
		} else {
			_strLine += ch;
		}
		break;
	}
	}
	Gura_EndPushbackRegion();
	return true;
}

bool Document::FlushLines(Environment &env)
{
	Structure *pStructure = _pStructureOwner->back();
	_lineOwner.AlignCol();
	foreach_const (LineOwner, ppLine, _lineOwner) {
		const Line *pLine = *ppLine;
		if (!pLine->IsBlank()) {
			for (int i = 0; i < pLine->GetCol(); i++) {
				if (!_pParser->FeedChar(env, ' ')) return false;
				pStructure->AddSourceChar(' ');
			}
		}
		if (!_pParser->FeedString(env, pLine->GetString())) return false;
		pStructure->AddSourceString(pLine->GetString());
	}
	if (!_pParser->FeedChar(env, '\0')) return false;
	_lineOwner.Clear();
	NewLine();
	return true;
}

void Document::NewLine()
{
	_col = 0;
	_strLine.clear();
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
void Document::Line::Print() const
{
	::printf("%*s%s", _col, "", _str.c_str());
}

//-----------------------------------------------------------------------------
// Document::LineList
//-----------------------------------------------------------------------------
void Document::LineList::AlignCol()
{
	int colMin = 0;
	bool firstFlag = true;
	foreach (LineList, ppLine, *this) {
		Line *pLine = *ppLine;
		if (!pLine->IsBlank()) {
			int col = pLine->GetCol();
			if (firstFlag || colMin > col) colMin = col;
			firstFlag = false;
		}
	}
	foreach (LineList, ppLine, *this) {
		Line *pLine = *ppLine;
		pLine->SetCol(ChooseMax(pLine->GetCol() - colMin, 0));
	}
}

void Document::LineList::Print() const
{
	foreach_const (LineList, ppLine, *this) {
		const Line *pLine = *ppLine;
		pLine->Print();
	}
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
