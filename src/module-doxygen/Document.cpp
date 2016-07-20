//=============================================================================
// Document.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Document
//-----------------------------------------------------------------------------
Document::Document() : _cntRef(1), _stat(STAT_Indent),
	_commentLineFlag(false), _regionPrev(RGN_Other),
	_pStructureOwner(new StructureOwner()), _pElemTop(Elem::Empty->Reference())
{
}

bool Document::ReadStream(Environment &env, SimpleStream &stream,
						  const Aliases *pAliases, bool extractedFlag)
{
	Signal &sig = env.GetSignal();
	_stat = extractedFlag? STAT_ExIndent : STAT_Indent;
	_pDecomposer.reset(new Decomposer(pAliases));
	for (;;) {
		int chRaw;
		if ((chRaw = stream.GetChar(sig)) < 0) chRaw = 0;
		char ch = static_cast<char>(static_cast<UChar>(chRaw));
		if (!FeedChar(env, ch)) return false;
		if (ch == '\0') break;
	}
	_sourceName = stream.GetName();
	AutoPtr<Elem_Container> pElemResult(
		new Elem_Container(_pDecomposer->GetElemOwner().Reference()));
	_pElemTop.reset(pElemResult->ReduceContent()->Reference());
	_pDecomposer.reset();
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
			_regionPrev = RGN_Other;
		} else if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (ch == '/') {
			// parsed "/" after indentation
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
			_commentLineFlag = false;
			_stat = STAT_Slash;
		} else if (ch == '\n') {
			_regionPrev = RGN_Other;
			_stat = STAT_Indent;
		} else { // including '\0'
			// nothing to do
		}
		break;
	}
	case STAT_Slash: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '/') {
			// parsed "//"
			_stat = STAT_LineCommentBgn;
		} else if (ch == '*') {
			// parsed "/*"
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
		if (ch == '/' || ch == '!') {
			// parsed "///" or "//!"
			_stat = STAT_LineDoxygenFirstChar;
		} else { // including '\0'
			// parsed "//."
			_regionPrev = RGN_Other;
			Gura_Pushback();
			_stat = STAT_LineComment;
		}
		break;
	}
	case STAT_LineDoxygenFirstChar: {
		if (ch == '<') {
			_pDecomposer->SetAheadFlag(!_commentLineFlag);
		} else {
			_pDecomposer->SetAheadFlag(false);
			Gura_Pushback();
		}
		if (_regionPrev != RGN_LineDoxygen) {
			_pDecomposer->AddElemStructure();
			AddStructure();
		}
		_regionPrev = _commentLineFlag? RGN_LineDoxygen : RGN_LineDoxygenMixed;
		_stat = STAT_LineDoxygen;
		break;
	}
	case STAT_LineDoxygen: {
		if (ch == '\n') {
			// a line comment ends with newline.
			if (!_pDecomposer->FeedChar(env, '\n')) return false;
			if (!_pDecomposer->FeedChar(env, '\0')) return false;
			_stat = STAT_Indent;
		} else { // including '\0'
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		}
		break;
	}
	case STAT_LineComment: {
		if (ch == '\n') {
			// a line comment ends with newline.
			_stat = STAT_Indent;
		} else { // including '\0'
			// nothing to do
		}
		break;
	}
	case STAT_BlockCommentBgn: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '*') {
			// parsed "/**"
			_stat = STAT_BlockCommentBgn_Asterisk;
		} else if (ch == '!') {
			// parsed "/*!"
			_stat = STAT_BlockDoxygenFirstChar;
		} else {
			// parsed "/*."
			_regionPrev = RGN_Other;
			_stat = STAT_BlockComment;
		}
		break;
	}
	case STAT_BlockCommentBgn_Asterisk: {
		if (ch == '/') {
			// parsed "/**/"
			_stat = STAT_Source;
		} else {
			// parsed "/**."
			Gura_Pushback();
			_stat = STAT_BlockDoxygenFirstChar;
		}
		break;
	}
	case STAT_BlockDoxygenFirstChar: {
		if (ch == '<') {
			_pDecomposer->SetAheadFlag(!_commentLineFlag);
		} else {
			_pDecomposer->SetAheadFlag(false);
			Gura_Pushback();
		}
		if (_regionPrev != RGN_LineDoxygen) {
			_pDecomposer->AddElemStructure();
			AddStructure();
		}
		_regionPrev = _commentLineFlag? RGN_BlockDoxygen : RGN_BlockDoxygenMixed;
		_stat = STAT_BlockDoxygen;
		break;
	}
	case STAT_BlockDoxygen: {
		if (ch == '*') {
			_stat = STAT_BlockDoxygen_Asterisk;
		} else if (ch == '\n') {
			if (!_pDecomposer->FeedChar(env, ch)) return false;
			_stat = STAT_BlockDoxygen_Indent;
		} else { // including '\0'
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		}
		break;
	}
	case STAT_BlockDoxygen_Asterisk: {
		if (ch == '/') {
			if (!_pDecomposer->FeedChar(env, '\0')) return false;
			_stat = STAT_Source;
		} else { // including '\0'
			if (!_pDecomposer->FeedChar(env, '*')) return false;
			if (!_pDecomposer->FeedChar(env, ch)) return false;
			_stat = STAT_BlockDoxygen;
		}
		break;
	}
	case STAT_BlockDoxygen_Indent: {
		if (ch == '\0') {
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		} else if (ch == '\n') {
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		} else if (ch == ' ' || ch == '\t') {
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
			if (!_pDecomposer->FeedChar(env, '\0')) return false;
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
			if (!_pDecomposer->FeedChar(env, ch)) return false;
			_stat = STAT_BlockDoxygen_Indent;
		} else if (ch == ' ' || ch == '\t') {
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
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		} else if (ch == '\n') {
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		} else if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			_stat = STAT_ExDoxygen;
			Gura_Pushback();
		}
		break;
	}
	case STAT_ExDoxygen: {
		if (ch == '\0') {
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		} else if (ch == '\n') {
			if (!_pDecomposer->FeedChar(env, ch)) return false;
			_stat = STAT_ExIndent;
		} else {
			if (!_pDecomposer->FeedChar(env, ch)) return false;
		}
		break;
	}
	}
	Gura_EndPushbackRegion();
	return true;
}

void Document::AddStructure()
{
	Structure *pStructure = new Structure();
	_pStructureOwner->push_back(pStructure);
	//_pDecomposer->SetElemOwner(pStructure->GetElemOwner().Reference());
}

//-----------------------------------------------------------------------------
// Decomposer
//-----------------------------------------------------------------------------
Decomposer::Decomposer(const Aliases *pAliases, Decomposer *pDecomposerParent) :
	_pAliases(pAliases), _pDecomposerParent(pDecomposerParent), _stat(STAT_Init),
	_pushbackLevel(0), _chAhead('\0'), _chPrev('\0'), _aheadFlag(false),
	_pElemOwner(new ElemOwner())
{
}

void Decomposer::SetCommandSpecial(const CommandFormat *pCmdFmt)
{
	_pElemCmdCur.reset(new Elem_Command(pCmdFmt));
	_stat = STAT_CommandSpecial;
}

void Decomposer::SetCommandCustom(const String &cmdName)
{
	_cmdName = cmdName;
	_stat = STAT_CommandCustom;
}

bool Decomposer::FeedChar(Environment &env, char ch)
{
	BeginPushbackRegion(ch);
	//::printf("%p ch=%c, stat=%d\n", this, ch, _stat);
	switch (_stat) {
	case STAT_Init: {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0') {
			// nothing to do
		} else {
			Pushback(ch);
			_text.clear();
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_Text: {
		if (ch == '\0') {
			if (!_text.empty()) {
				AddElemToResult(new Elem_Text(_text));
				_text.clear();
			}
		} else if (IsCommandMark(ch)) {
			if (!_text.empty()) {
				AddElemToResult(new Elem_Text(_text));
				_text.clear();
			}
			_cmdName.clear();
			_stat = STAT_AcceptCommandInText;
		} else {
			_text += ch;
		}
		break;
	}
	case STAT_AcceptCommandInText: {
		if (IsCommandEnd(_cmdName, ch)) {
			if (_cmdName.empty()) {
				env.SetError(ERR_SyntaxError, "command name is not specified");
				return false;
			}
			const CommandFormat *pCmdFmt = CommandFormat::Lookup(_cmdName.c_str());
			if (pCmdFmt == nullptr) {
				// custom command
				_stat = STAT_CommandCustom;
			} else {
				// special command
				_stat = STAT_CommandSpecial;
				_pElemCmdCur.reset(new Elem_Command(pCmdFmt));
			}
			Pushback(ch);
		} else {
			_cmdName += ch;
		}
		break;
	}
	case STAT_AcceptCommandInArgLine:
	case STAT_AcceptCommandInArgPara: {
		if (_pDecomposerChild.get() != nullptr) {
			if (!_pDecomposerChild->FeedChar(env, ch)) return false;
			if (_pDecomposerChild->IsComplete()) {
				//_pElemArg->AddElem(_pDecomposerChild->GetElem()->Reference());
				AutoPtr<Elem_Container> pElemResult(
					new Elem_Container(_pDecomposerChild->GetElemOwner().Reference()));
				_pElemArg->AddElem(pElemResult->ReduceContent()->Reference());
				_pDecomposerChild.reset();
				_stat = (_stat == STAT_AcceptCommandInArgLine)? STAT_ArgLine : STAT_ArgPara;
			}
		} else if (IsCommandEnd(_cmdName, ch)) {
			if (_cmdName.empty()) {
				env.SetError(ERR_SyntaxError, "command name is not specified");
				return false;
			}
			const CommandFormat *pCmdFmt = CommandFormat::Lookup(_cmdName.c_str());
			if (pCmdFmt == nullptr) {
				// custom command
				_pDecomposerChild.reset(new Decomposer(_pAliases, this));
				_pDecomposerChild->SetCommandCustom(_cmdName.c_str());
				Pushback(ch);
			} else if (pCmdFmt->IsSectionIndicator()) {
				if (_stat == STAT_AcceptCommandInArgLine ||
					_stat == STAT_AcceptCommandInArgCustom) {
					env.SetError(ERR_SyntaxError,
								 "section indicator can not appear in line argument");
					return false;
				}
				// finish the previous command
				if (!_strArg.empty()) {
					_pElemArg->AddElem(new Elem_Text(_strArg));
					_strArg.clear();
				}
				_pElemCmdCur->AddArg(_pElemArg->ReduceContent()->Reference());
				AddElemToResult(_pElemCmdCur.release());
				// special command (section indicator)
				_pElemCmdCur.reset(new Elem_Command(pCmdFmt));
				Pushback(ch);
				_stat = STAT_CommandSpecial;
			} else {
				// special command (not section indicator)
				_pDecomposerChild.reset(new Decomposer(_pAliases, this));
				_pDecomposerChild->SetCommandSpecial(pCmdFmt);
			}
		} else {
			_cmdName += ch;
		}
		break;
	}
	case STAT_AcceptCommandInArgCustom: {
		if (_pDecomposerChild.get() != nullptr) {
			if (!_pDecomposerChild->FeedChar(env, ch)) return false;
			if (_pDecomposerChild->IsComplete()) {
				_strArg += _pDecomposerChild->GetText();
				_pDecomposerChild.reset();
				_stat = STAT_ArgCustom;
			}
		} else if (IsCommandEnd(_cmdName, ch)) {
			if (_cmdName.empty()) {
				env.SetError(ERR_SyntaxError, "command name is not specified");
				return false;
			}
			const CommandFormat *pCmdFmt = CommandFormat::Lookup(_cmdName.c_str());
			if (pCmdFmt == nullptr) {
				// custom command
				_pDecomposerChild.reset(new Decomposer(_pAliases, this));
				_pDecomposerChild->SetCommandCustom(_cmdName);
				Pushback(ch);
			} else {
				// special command
				_strArg += _chAhead;
				_strArg += _cmdName;
				_stat = STAT_ArgCustom;
			}
		} else {
			_cmdName += ch;
		}
		break;
	}
	case STAT_CommandSpecial: {
		Pushback(ch);
		_strArg.clear();
		_stat = STAT_NextArg;
		break;
	}
	case STAT_NextArg: {
		const ElemOwner &elemArgs = _pElemCmdCur->GetElemArgs();
		const CommandFormat::ArgOwner &argOwner = _pElemCmdCur->GetCommandFormat()->GetArgOwner();
		size_t iArg = elemArgs.size();
		if (iArg < argOwner.size()) {
			Pushback(ch);
			_stat = STAT_BranchArg;
		} else {
			AddElemToResult(_pElemCmdCur.release());
			Pushback(ch);
			_text.clear();
			_stat = IsTopLevel()? STAT_Text : STAT_Complete;
		}
		break;
	}
	case STAT_BranchArg: {
		const ElemOwner &elemArgs = _pElemCmdCur->GetElemArgs();
		const CommandFormat::ArgOwner &argOwner = _pElemCmdCur->GetCommandFormat()->GetArgOwner();
		size_t iArg = elemArgs.size();
		const CommandFormat::Arg *pArg = argOwner[iArg];
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (pArg->IsWord() || pArg->IsWordOpt()) {
			if (ch == '\n' || ch == '\0' || IsCommandMark(ch)) {
				if (pArg->IsWord()) {
					env.SetError(ERR_SyntaxError, "argument %s doesn't exist", pArg->GetName());
					return false;
				}
				Pushback(ch);
				_pElemCmdCur->AddArg(new Elem_Empty());
				_stat = STAT_NextArg;
			} else if (ch == '"') {
				_strArg.clear();
				_stat = STAT_ArgWordQuote;
			} else {
				_strArg.clear();
				Pushback(ch);
				_stat = STAT_ArgWord;
			}
		} else if (pArg->IsBracket()) {
			if (ch == '[') {
				_strArg.clear();
				_stat = STAT_ArgBracket;
			} else { // including '\0'
				Pushback(ch);
				_pElemCmdCur->AddArg(new Elem_Empty());
				_stat = STAT_NextArg;
			}
		} else if (pArg->IsLine() || pArg->IsLineOpt()) {
			_pElemArg.reset(new Elem_Container());
			Pushback(ch);
			_strArg.clear();
			_stat = STAT_ArgLine;
		} else if (pArg->IsQuote() || pArg->IsQuoteOpt()) {
			if (ch == '"') {
				_strArg.clear();
				_stat = STAT_ArgQuote;
			} else { // including '\0'
				if (pArg->IsQuote()) {
					env.SetError(ERR_SyntaxError, "quoted string is expected");
					return false;
				}
				Pushback(ch);
				if (_chPrev == ' ' || _chPrev == '\t') Pushback(_chPrev);
				_pElemCmdCur->AddArg(new Elem_Empty());
				_stat = STAT_NextArg;
			}
		} else if (pArg->IsBrace() || pArg->IsBraceOpt()) {
			if (ch == '{') {
				_strArg.clear();
				_stat = STAT_ArgBrace;
			} else { // include '\0'
				if (pArg->IsBrace()) {
					env.SetError(ERR_SyntaxError, "braced string is expected");
					return false;
				}
				Pushback(ch);
				_pElemCmdCur->AddArg(new Elem_Empty());
				_stat = STAT_NextArg;
			}
		} else if (pArg->IsPara()) {
			_pElemArg.reset(new Elem_Container());
			Pushback(ch);
			_strArg.clear();
			_stat = STAT_ArgPara;
		}
		break;
	}
	case STAT_ArgWord: {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' || IsCommandMark(ch)) {
			Pushback(ch);
			_pElemCmdCur->AddArg(new Elem_Text(_strArg));
			_strArg.clear();
			_stat = STAT_NextArg;
		} else if (ch == '.' || ch == ',' || ch == ';' || ch == '?' || ch == '!') {
			_chAhead = ch;
			_stat = STAT_ArgWord_Punctuation;
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgWord_Punctuation: {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' || IsCommandMark(ch)) {
			Pushback(ch);
			Pushback(_chAhead);
			_pElemCmdCur->AddArg(new Elem_Text(_strArg));
			_strArg.clear();
			_stat = STAT_NextArg;
		} else {
			Pushback(ch);
			_strArg += _chAhead;
			_stat = STAT_ArgWord;
		}
		break;
	}
	case STAT_ArgWordQuote: {
		if (ch == '\n' || ch == '\0') {
			Pushback(ch);
			_pElemCmdCur->AddArg(new Elem_Text(_strArg));
			_strArg.clear();
			_stat = STAT_NextArg;
		} else if (ch == '"') {
			_pElemCmdCur->AddArg(new Elem_Text(_strArg));
			_strArg.clear();
			_stat = STAT_NextArg;
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgBracket: {
		if (ch == '\n' || ch == '\0' || IsCommandMark(ch)) {
			env.SetError(ERR_SyntaxError, "unmatched brakcet mark");
			return false;
		} else if (ch == ']') {
			_pElemCmdCur->AddArg(new Elem_Text(_strArg));
			_strArg.clear();
			_stat = STAT_NextArg;
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgLine: {
		if (ch == '\n' || ch == '\0') {
			if (ch == '\0') Pushback(ch);
			String str = Strip(_strArg.c_str());
			if (!str.empty()) {
				_pElemArg->AddElem(new Elem_Text(str));
			}
			_strArg.clear();
			_pElemCmdCur->AddArg(_pElemArg->ReduceContent()->Reference());
			_stat = STAT_NextArg;
		} else if (IsCommandMark(ch)) {
			String str = Strip(_strArg.c_str());
			if (!str.empty()) {
				_pElemArg->AddElem(new Elem_Text(str));
			}
			_strArg.clear();
			_cmdName.clear();
			_stat = STAT_AcceptCommandInArgLine;
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgQuote: {
		if (ch == '\n' || ch == '\0') {
			env.SetError(ERR_SyntaxError, "quoted string doesn't end correctly");
			return false;
		} else if (ch == '"') {
			_pElemCmdCur->AddArg(new Elem_Text(_strArg));
			_strArg.clear();
			_stat = STAT_NextArg;
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgBrace: {
		if (ch == '\n' || ch == '\0') {
			env.SetError(ERR_SyntaxError, "braced string doesn't end correctly");
			return false;
		} else if (ch == '}') {
			_pElemCmdCur->AddArg(new Elem_Text(_strArg));
			_strArg.clear();
			_stat = STAT_NextArg;
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgPara: {
		if (ch == '\n') {
			_strArg += ch;
			_strAhead.clear();
			_stat = STAT_ArgParaNewline;
		} else if (ch == '\0') {
			Pushback(ch);
			if (!_strArg.empty()) {
				_pElemArg->AddElem(new Elem_Text(_strArg));
				_strArg.clear();
			}
			_pElemCmdCur->AddArg(_pElemArg->ReduceContent()->Reference());
			_stat = STAT_NextArg;
		} else if (IsCommandMark(ch)) {
			if (!_strArg.empty()) {
				_pElemArg->AddElem(new Elem_Text(_strArg));
				_strArg.clear();
			}
			_cmdName.clear();
			_stat = STAT_AcceptCommandInArgPara;
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgParaNewline: {
		if (ch == '\n') {
			// detected a blank line
			if (!_strArg.empty()) {
				_pElemArg->AddElem(new Elem_Text(_strArg));
				_strArg.clear();
			}
			_pElemCmdCur->AddArg(_pElemArg->ReduceContent()->Reference());
			_stat = STAT_NextArg;
		} else if (ch == ' ' || ch == '\t') {
			_strAhead += ch;
		} else { // including '\0'
			_strArg += _strAhead;
			Pushback(ch);
			_stat = STAT_ArgPara;
		}
		break;
	}
	case STAT_CommandCustom: {
		if (ch == '{') {
			_strArg.clear();
			_stat = STAT_ArgCustom;
		} else {
			_strArg.clear();
			String rtn = EvaluateCustomCommand(env);
			if (env.IsSignalled()) return false;
			Pushback(ch);
			_strArgs.clear();
			_text.clear();
			_stat = STAT_Text;
			foreach (String, p, rtn) {
				if (!FeedChar(env, *p)) return false;
			}
			if (!IsTopLevel()) _stat = STAT_Complete;
		}
		break;
	}
	case STAT_ArgCustom: {
		if (ch == '}') {
			_strArgs.push_back(_strArg);
			String rtn = EvaluateCustomCommand(env);
			if (env.IsSignalled()) return false;
			_strArgs.clear();
			_strArg.clear();
			_text.clear();
			_stat = STAT_Text;
			foreach (String, p, rtn) {
				if (!FeedChar(env, *p)) return false;
			}
			if (!IsTopLevel()) _stat = STAT_Complete;
		} else if (ch == ',') {
			_strArgs.push_back(_strArg);
			_strArg.clear();
		} else if (ch == '\\') {
			_stat = STAT_ArgCustom_Backslash;
		} else if (IsCommandMark(ch)) {
			_cmdName.clear();
			_chAhead = ch;
			_stat = STAT_AcceptCommandInArgCustom;
		} else if (ch == '\0') {
			// nothing to do
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgCustom_Backslash: {
		if (ch == '\0') {
			Pushback(ch);
			_stat = STAT_ArgCustom;
		} else if (ch == ',') {
			_strArg += ch;
			_stat = STAT_ArgCustom;
		} else {
			Pushback(ch);
			_cmdName.clear();
			_chAhead = '\\';
			_stat = STAT_AcceptCommandInArgCustom;
		}
		break;
	}
	case STAT_Complete: {
		break;
	}
	}
	EndPushbackRegion();
	if (IsTopLevel() && ch == '\0') _stat = STAT_Init;
	_chPrev = ch;
	return true;
}

bool Decomposer::FeedString(Environment &env, const char *str)
{
	for (const char *p = str; ; p++) {
		if (!FeedChar(env, *p)) return false;
		if (*p == '\0') break;
	}
	return true;
}

void Decomposer::AddElemStructure()
{
	_pElemOwner->push_back(new Elem_Structure());
}

void Decomposer::AddElemToResult(Elem *pElem)
{
	if (!_pElemOwner->empty()) {
		Elem *pElemLast = _pElemOwner->back();
		if (pElemLast->GetType() == Elem::TYPE_Structure) {
			dynamic_cast<Elem_Structure *>(pElemLast)->AddElem(pElem);
		}
	}
}

String Decomposer::EvaluateCustomCommand(Environment &env) const
{
	String rtn;
	if (_pAliases != nullptr) {
		const Alias *pAlias = _pAliases->Lookup(_cmdName.c_str(), _strArgs.size());
		if (pAlias == nullptr || !pAlias->Evaluate(env, rtn, _strArgs)) return "";
	}
	return rtn;
}

bool Decomposer::ContainsCommand(const char *str)
{
	for (const char *p = str; *p != '\0'; p++) {
		char ch = *p;
		if (IsCommandMark(ch)) return true;
	}
	return false;
}

Gura_EndModuleScope(doxygen)
