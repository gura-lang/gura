//=============================================================================
// Parser.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
Parser::Parser(Object_parser *pObjParser) :
	_stat(STAT_Indent), _pDecomposer(new Decomposer(pObjParser))
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

const char *Parser::ParseStream(Environment &env, SimpleStream &stream)
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
Decomposer::Decomposer(Object_parser *pObjParser, int depthLevel) :
	_pObjParser(pObjParser), _depthLevel(depthLevel), _stat(STAT_Init),
	_pCmdFmtCur(nullptr), _pCmdFmtCustom(new CommandFormat(CommandFormat::CMDTYPE_Custom)),
	_pushbackLevel(0)
{
}

bool Decomposer::FeedChar(Environment &env, char ch)
{
	BeginPushbackRegion(ch);
	//::printf("stat=%d\n", _stat);
	switch (_stat) {
	case STAT_Init: {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0') {
			// nothing to do
		} else {
			Pushback(ch);
			_stat = STAT_Text;
		}
		break;
	}
	case STAT_Text: {
		if (ch == '\0') {
			// nothing to do
		} else if (IsCommandMark(ch)) {
			_cmdName.clear();
			_stat = STAT_Command;
		} else {
			_result += ch;
		}
		break;
	}
	case STAT_Command: {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' ||
			(!(_cmdName == "f" || _cmdName.empty()) && (ch == '[' || ch == '{'))) {
			if (_cmdName.empty()) {
				env.SetError(ERR_SyntaxError, "command name is not specified");
				return false;
			}
			const CommandFormat *pCmdFmt = CommandFormat::Lookup(_cmdName.c_str());
			if (pCmdFmt == nullptr) {
				// custom commands
				_pCmdFmtCustom->SetName(_cmdName.c_str());
				_pCmdFmtCur = _pCmdFmtCustom.get();
				if (ch == '{') {
					_strArg.clear();
					_stat = STAT_NextArgCustom;
				} else {
					_result += _pCmdFmtCur->Evaluate(_pObjParser, _strArgs);
					if (env.IsSignalled()) return false;
					_strArg.clear();
					Pushback(ch);
					_stat = (_depthLevel == 0)? STAT_Text : STAT_Complete;
				}
			} else {
				// special commands
				_pCmdFmtCur = pCmdFmt;
				Pushback(ch);
				_strArgs.clear();
				_strArg.clear();
				_stat = STAT_NextArgSpecial;
			}
		} else {
			_cmdName += ch;
		}
		break;
	}
	case STAT_CommandInArgPara: {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' ||
			(!(_cmdName == "f" || _cmdName.empty()) && (ch == '[' || ch == '{'))) {
			const CommandFormat *pCmdFmt = CommandFormat::Lookup(_cmdName.c_str());
			if (pCmdFmt == nullptr) {
				// custom command
				Pushback(ch);
				_stat = STAT_ArgPara;
			} else if (pCmdFmt->IsSectionIndicator()) {
				_strArgs.push_back(_strArg);
				_result += _pCmdFmtCur->Evaluate(_pObjParser, _strArgs);
				if (env.IsSignalled()) return false;
				// special commands
				_pCmdFmtCur = pCmdFmt;
				Pushback(ch);
				_strArgs.clear();
				_strArg.clear();
				_stat = STAT_NextArg;
			} else {
				_pDecomposerSub.reset(new Decomposer(_pObjParser, _depthLevel + 1));
				Pushback(ch);
				_stat = STAT_DecomposeInArgPara;
			}
		} else {
			_cmdName += ch;
		}
		break;
	}
	case STAT_DecomposeInArgPara: {
		if (!_pDecomposerSub->FeedChar(env, ch)) {
			return false;
		} else if (_pDecomposerSub->IsComplete()) {
			_pDecomposerSub->GetResult();
			_pDecomposerSub.reset(nullptr);
			_stat = STAT_ArgPara;
		}
		break;
	}
	case STAT_CommandInArgCustom: {
		
		break;
	}
	case STAT_NextArg: {
		if (_pCmdFmtCur->IsCustom()) {
			Pushback(ch);
			_stat = STAT_NextArgCustom;
		} else {
			const CommandFormat::ArgOwner &argOwner = _pCmdFmtCur->GetArgOwner();
			size_t iArg = _strArgs.size();
			if (iArg < argOwner.size()) {
				Pushback(ch);
				_stat = STAT_NextArgSpecial;
			} else {
				_result += _pCmdFmtCur->Evaluate(_pObjParser, _strArgs);
				if (env.IsSignalled()) return false;
				Pushback(ch);
				_stat = (_depthLevel == 0)? STAT_Text : STAT_Complete;
			}
		}
		break;
	}
	case STAT_NextArgSpecial: {
		const CommandFormat::ArgOwner &argOwner = _pCmdFmtCur->GetArgOwner();
		size_t iArg = _strArgs.size();
		const CommandFormat::Arg *pArg = argOwner[iArg];
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (pArg->IsWord() || pArg->IsWordOpt()) {
			if (ch == '\n' || ch == '\0' || IsCommandMark(ch)) {
				if (pArg->IsWord()) {
					env.SetError(ERR_SyntaxError, "argument %s doesn't exist", pArg->GetName());
					return false;
				}
				_strArgs.push_back("");
				_stat = STAT_NextArg;
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
				_strArgs.push_back("");
				_stat = STAT_NextArg;
			}
		} else if (pArg->IsLine() || pArg->IsLineOpt()) {
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
				_strArgs.push_back("");
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
				_strArgs.push_back("");
				_stat = STAT_NextArg;
			}
		} else if (pArg->IsPara()) {
			Pushback(ch);
			_strArg.clear();
			_stat = STAT_ArgPara;
		}
		break;
	}
	case STAT_ArgWord: {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' || IsCommandMark(ch)) {
			Pushback(ch);
			_strArgs.push_back(_strArg);
			_stat = STAT_NextArg;
		} else if (ch == '.') {
			_stat = STAT_ArgWord_Period;
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgWord_Period: {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' || IsCommandMark(ch)) {
			Pushback(ch);
			Pushback('.');
			_strArgs.push_back(_strArg);
			_stat = STAT_NextArg;
		} else {
			Pushback(ch);
			_strArg += '.';
			_stat = STAT_ArgWord;
		}
		break;
	}
	case STAT_ArgBracket: {
		if (ch == '\n' || ch == '\0' || IsCommandMark(ch)) {
			env.SetError(ERR_SyntaxError, "unmatched brakcet mark");
			return false;
		} else if (ch == ']') {
			_strArgs.push_back(_strArg);
			_stat = STAT_NextArg;
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgLine: {
		if (ch == '\n' || ch == '\0') {
			if (ch == '\0') Pushback(ch);
			_strArgs.push_back(_strArg);
			_stat = STAT_NextArg;
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
			_strArgs.push_back(_strArg);
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
			_strArgs.push_back(_strArg);
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
			_strArgs.push_back(_strArg);
			_stat = STAT_NextArg;
		} else if (IsCommandMark(ch)) {
			_cmdName.clear();
			_stat = STAT_CommandInArgPara;
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_ArgParaNewline: {
		if (ch == '\n') {
			// detected a blank line
			_strArgs.push_back(_strArg);
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
	case STAT_NextArgCustom: {
		if (ch == '}') {
			_strArgs.push_back(_strArg);
			_result += _pCmdFmtCur->Evaluate(_pObjParser, _strArgs);
			if (env.IsSignalled()) return false;
			_strArg.clear();
			_stat = (_depthLevel == 0)? STAT_Text : STAT_Complete;
		} else if (ch == ',') {
			_strArgs.push_back(_strArg);
			_strArg.clear();
		} else if (ch == '\\') {
			_stat = STAT_NextArgCustom_Backslash;
		} else if (IsCommandMark(ch)) {
			_cmdName.clear();
			_stat = STAT_CommandInArgCustom;
		} else if (ch == '\0') {
			// nothing to do
		} else {
			_strArg += ch;
		}
		break;
	}
	case STAT_NextArgCustom_Backslash: {
		if (ch == '\0') {
			// nothing to do
			_stat = STAT_NextArgCustom;
		} else {
			_strArg += ch;
			_stat = STAT_NextArgCustom;
		}
		break;
	}
	case STAT_Complete: {
		break;
	}
	}
	EndPushbackRegion();
	if (ch == '\0') _stat = STAT_Complete;
	return true;
}

bool Decomposer::FeedString(Environment &env, const char *str)
{
	for (const char *p = str; *p != '\0'; p++) {
		if (!FeedChar(env, *p)) return false;
	}
	return true;
}

#if 0
bool Decomposer::EvaluateSpecialCommand(
	Environment &env, const CommandFormat *pCmdFmt, const StringList &strArgs)
{
	String funcName = "@";
	funcName += pCmdFmt->GetName();
	const Function *pFunc = _pObjParser->LookupFunction(
		Symbol::Add(funcName.c_str()), ENVREF_Escalate);
	if (pFunc == nullptr) {
		env.SetError(ERR_ValueError, "method not found: %s", funcName.c_str());
		return false;
	}
	AutoPtr<Argument> pArg(new Argument(pFunc));
	foreach_const (StringList, pStrArg, strArgs) {
		if (!pArg->StoreValue(env, Value(*pStrArg))) return false;
	}
	if (!pArg->Complete(env)) {
		env.SetError(ERR_ArgumentError, "expected handler is %s",
					 pCmdFmt->MakeHandlerDeclaration().c_str());
		return false;
	}
	Value rtn = pFunc->Eval(env, *pArg);
	if (!rtn.Is_string()) {
		env.SetError(ERR_ValueError, "function must return a string value");
		return false;
	}
	_result += rtn.GetStringSTL();
	return true;
}

bool Decomposer::EvaluateCustomCommand(
	Environment &env, const char *cmdName, const StringList &strArgs)
{
	String funcName = "@";
	funcName += cmdName;
	if (!strArgs.empty()) {
		char buff[32];
		::sprintf(buff, "_%lu", strArgs.size());
		funcName += buff;
	}
	const Function *pFunc = _pObjParser->LookupFunction(
		Symbol::Add(funcName.c_str()), ENVREF_Escalate);
	if (pFunc == nullptr) {
		env.SetError(ERR_ValueError, "method not found: %s", funcName.c_str());
		return false;
	}
	AutoPtr<Argument> pArg(new Argument(pFunc));
	foreach_const (StringList, pStrArg, strArgs) {
		if (!pArg->StoreValue(env, Value(*pStrArg))) return false;
	}
	if (!pArg->Complete(env)) return false;
	Value rtn = pFunc->Eval(env, *pArg);
	if (!rtn.Is_string()) {
		env.SetError(ERR_ValueError, "function must return a string value");
		return false;
	}
	_result += rtn.GetStringSTL();
	return true;
}
#endif

const char *Decomposer::GetResult() const
{
	return _result.c_str();
}

Gura_EndModuleScope(doxygen)
