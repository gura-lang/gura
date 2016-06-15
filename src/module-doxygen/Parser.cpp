//=============================================================================
// Parser.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
Parser::Parser() : _stat(STAT_Indent), _pDecomposer(new Decomposer())
{
}

bool Parser::FeedChar(Environment &env, char ch)
{
	Gura_BeginPushbackRegion();
	switch (_stat) {
	case STAT_Indent: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '\n') {
			// nothing to do
		} else if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else {
			_stat = STAT_Source;
			Gura_Pushback();
		}
		break;
	}
	case STAT_Source: {
		if (ch == '/') {
			_stat = STAT_Slash;
		} else if (ch == '\n') {
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
			_stat = STAT_LineCommentBgn;
		} else if (ch == '*') {
			_stat = STAT_BlockCommentBgn;
		} else {
			_stat = STAT_Source;
			Gura_Pushback();
		}
		break;
	}
	case STAT_LineCommentBgn: {
		if (ch == '\0') {
			// nothing to do
		} else if (ch == '/' || ch == '!') {
			_stat = STAT_LineDoxygen;
		} else {
			_stat = STAT_LineComment;
		}
		break;
	}
	case STAT_LineDoxygen: {
		if (ch == '\n') {
			// a line comment ends with newline.
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
			_stat = STAT_BlockCommentBgn_Asterisk;
		} else if (ch == '!') {
			_stat = STAT_BlockDoxygen;
		} else {
			_stat = STAT_BlockComment;
		}
		break;
	}
	case STAT_BlockCommentBgn_Asterisk: {
		if (ch == '/') {
			_stat = STAT_Source;
		} else {
			Gura_Pushback();
			_stat = STAT_BlockDoxygen;
		}
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
			// nothing to do
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
	}
	Gura_EndPushbackRegion();
	return true;
}

const Elem *Parser::ParseStream(Environment &env, SimpleStream &stream)
{
	Signal &sig = env.GetSignal();
	for (;;) {
		int chRaw;
		if ((chRaw = stream.GetChar(sig)) < 0) chRaw = 0;
		char ch = static_cast<char>(static_cast<UChar>(chRaw));
		if (!FeedChar(env, ch)) return nullptr;
		if (ch == '\0') break;
	}
	return _pDecomposer->GetResult();
}

//-----------------------------------------------------------------------------
// Decomposer
//-----------------------------------------------------------------------------
Decomposer::Decomposer() : _stat(STAT_Init), _pElemRoot(new Elem_Container())
{
}

bool Decomposer::FeedChar(Environment &env, char ch)
{
	Gura_BeginPushbackRegion();
	switch (_stat) {
	case STAT_Init: {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0') {
			// nothing to do
		} else {
			Gura_Pushback();
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_Text: {
		if (ch == '\0') {
			if (!_str.empty()) {
				_pElemRoot->AddElem(new Elem_Text(_str));
			}
			_str.clear();
		} else if (IsCommandMark(ch)) {
			if (!_str.empty()) {
				_pElemRoot->AddElem(new Elem_Text(_str));
			}
			_name.clear();
			_stat = STAT_Command;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_Command: {
		if (ch == '\0' || ch == ' ' || ch == '\t' || ch == '\n' ||
			(_name != "f" && (ch == '[' || ch == '{'))) {
			if (_name.empty()) {
				env.SetError(ERR_SyntaxError, "command name is not specified");
				return false;
			}
			if (ch == '[' || ch == '{') Gura_Pushback();
			const CommandFormat *pCmdFmt = CommandFormat::Lookup(_name.c_str());
			if (pCmdFmt == nullptr) {
				//_stat = STAT_SeekOpenBrace;
			} else {
				_pElemCmd.reset(new Elem_Command(pCmdFmt));
				_pElemRoot->AddElem(_pElemCmd->Reference());
				_str.clear();
				_stat = STAT_NextArg;
			}
		} else {
			_name += ch;
		}
		break;
	}
	case STAT_CommandInArgPara: {
		if (ch == '\0' || ch == ' ' || ch == '\t' || ch == '\n' ||
			(_name != "f" && (ch == '[' || ch == '{'))) {
			if (ch == '[' || ch == '{') Gura_Pushback();
			const CommandFormat *pCmdFmt = CommandFormat::Lookup(_strAhead.c_str() + 1);
			if (pCmdFmt == nullptr || !pCmdFmt->IsSection()) {
				Gura_Pushback();
				_str += _strAhead;
				_stat = STAT_ArgPara;
			} else {
				_pElemCmd->SetArgElem(new Elem_Text(_str)); // last argument
				_pElemCmd.reset(new Elem_Command(pCmdFmt));
				_pElemRoot->AddElem(_pElemCmd->Reference());
				_str.clear();
				_stat = STAT_NextArg;
			}
		} else {
			_strAhead += ch;
		}
		break;
	}
	case STAT_NextArg: {
		if (_pElemCmd->NextArg()) {
			Gura_Pushback();
			_stat = STAT_BranchArg;
		} else {
			_str.clear();
			Gura_Pushback();
			_stat = STAT_Init;
		}
		break;
	}
	case STAT_BranchArg: {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
			break;
		}
		const CommandFormat::Arg *pArg = _pElemCmd->GetArgCur();
		if (pArg->IsWord() || pArg->IsWordOpt()) {
			if (ch == '\n' || ch == '\0' || IsCommandMark(ch)) {
				if (pArg->IsWord()) {
					env.SetError(ERR_SyntaxError, "argument %s doesn't exist", pArg->GetName());
					return false;
				}
			} else {
				_str.clear();
				Gura_Pushback();
				_stat = STAT_ArgWord;
			}
		} else if (pArg->IsBracket()) {
			if (ch == '[') {
				_str.clear();
				_stat = STAT_ArgBracket;
			} else { // including '\0'
				Gura_Pushback();
			}
		} else if (pArg->IsLine() || pArg->IsLineOpt()) {
			Gura_Pushback();
			_str.clear();
			_stat = STAT_ArgLine;
		} else if (pArg->IsQuote() || pArg->IsQuoteOpt()) {
			if (ch == '"') {
				_str.clear();
				_stat = STAT_ArgQuote;
			} else { // including '\0'
				if (pArg->IsQuote()) {
					env.SetError(ERR_SyntaxError, "quoted string is expected");
					return false;
				}
				Gura_Pushback();
			}
		} else if (pArg->IsBrace() || pArg->IsBraceOpt()) {
			if (ch == '{') {
				_str.clear();
				_stat = STAT_ArgBrace;
			} else { // include '\0'
				if (pArg->IsBrace()) {
					env.SetError(ERR_SyntaxError, "braced string is expected");
					return false;
				}
				Gura_Pushback();
			}
		} else if (pArg->IsPara() || pArg->IsParaOpt()) {
			Gura_Pushback();
			_str.clear();
			_stat = STAT_ArgPara;
		}
		break;
	}
	case STAT_ArgWord: {
		if (IsWordChar(ch)) {
			_str += ch;
		} else {
			Gura_Pushback();
			_pElemCmd->SetArgElem(new Elem_Text(_str));
			_stat = STAT_NextArg;
		}
		break;
	}
	case STAT_ArgBracket: {
		if (ch == '\n' || ch == '\0' || IsCommandMark(ch)) {
			env.SetError(ERR_SyntaxError, "unmatched brakcet mark");
			return false;
		} else if (ch == ']') {
			_pElemCmd->SetArgElem(new Elem_Text(_str));
			_stat = STAT_NextArg;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_ArgLine: {
		if (ch == '\n' || ch == '\0') {
			Gura_Pushback();
			_pElemCmd->SetArgElem(new Elem_Text(_str));
			_stat = STAT_NextArg;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_ArgQuote: {
		if (ch == '\n' || ch == '\0') {
			env.SetError(ERR_SyntaxError, "quoted string doesn't end correctly");
			return false;
		} else if (ch == '"') {
			_pElemCmd->SetArgElem(new Elem_Text(_str));
			_stat = STAT_NextArg;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_ArgBrace: {
		if (ch == '\n' || ch == '\0') {
			env.SetError(ERR_SyntaxError, "braced string doesn't end correctly");
			return false;
		} else if (ch == '}') {
			_pElemCmd->SetArgElem(new Elem_Text(_str));
			_stat = STAT_NextArg;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_ArgPara: {
		if (ch == '\n') {
			_str += ch;
			_strAhead.clear();
			_stat = STAT_ArgParaNewline;
		} else if (ch == '\0') {
			Gura_Pushback();
			_pElemCmd->SetArgElem(new Elem_Text(_str));
			_stat = STAT_NextArg;
		} else if (IsCommandMark(ch)) {
			_strAhead.clear();
			_strAhead += ch;
			_stat = STAT_CommandInArgPara;
		} else {
			_str += ch;
		}
		break;
	}
	case STAT_ArgParaNewline: {
		if (ch == '\n') {
			// detected a blank line
			_pElemCmd->SetArgElem(new Elem_Text(_str));
			_stat = STAT_NextArg;
		} else if (ch == ' ' || ch == '\t') {
			_strAhead += ch;
		} else { // including '\0'
			_str += _strAhead;
			Gura_Pushback();
			_stat = STAT_ArgPara;
		}
		break;
	}
	case STAT_SeekOpenBrace: {
		if (ch == '{') {
			
		} else { // including '\0'
			
		}
		break;
	}
	}
	Gura_EndPushbackRegion();
	return true;
}

const Elem *Decomposer::DecomposeString(Environment &env, const char *str)
{
	for (const char *p = str; *p != '\0'; p++) {
		if (!FeedChar(env, *p)) return nullptr;
	}
	return GetResult();
}

const Elem *Decomposer::GetResult()
{
	return (_pElemRoot->GetElemOwner().size() == 1)?
		_pElemRoot->GetElemOwner().front() : _pElemRoot.get();
}

Gura_EndModuleScope(doxygen)
