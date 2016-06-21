//=============================================================================
// Parser.h
//=============================================================================
#ifndef __GURA_DOXYGEN_PARSER_H__
#define __GURA_DOXYGEN_PARSER_H__
#include "Elem.h"

Gura_BeginModuleScope(doxygen)

class Decomposer;
class Object_parser;

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
class Parser {
public:
	enum Stat {
		STAT_Indent,
		STAT_Source,
		STAT_LineCommentBgn,
		STAT_LineDoxygen,
		STAT_LineComment,
		STAT_BlockCommentBgn,
		STAT_BlockCommentBgn_Asterisk,
		STAT_BlockDoxygen,
		STAT_BlockDoxygen_Asterisk,
		STAT_BlockDoxygen_Indent,
		STAT_BlockDoxygen_IndentAsterisk,
		STAT_BlockDoxygen_IndentAfterAsterisk,
		STAT_BlockComment,
		STAT_BlockComment_Asterisk,
		STAT_Slash,
	};
private:
	Stat _stat;
	std::unique_ptr<Decomposer> _pDecomposer;
public:
	Parser(Object_parser *pObjParser);
	bool FeedChar(Environment &env, char ch);
	const char *ParseStream(Environment &env, SimpleStream &stream);
};

//-----------------------------------------------------------------------------
// Decomposer
//-----------------------------------------------------------------------------
class Decomposer {
public:
	enum Stat {
		STAT_Init,
		STAT_Text,
		STAT_Command,
		STAT_CommandInArgPara,
		STAT_CommandInArgCustom,
		STAT_NextArg,
		STAT_NextArgSpecial,
		STAT_ArgWord,
		STAT_ArgWord_Period,
		STAT_ArgBracket,
		STAT_ArgLine,
		STAT_ArgQuote,
		STAT_ArgBrace,
		STAT_ArgPara,
		STAT_ArgParaNewline,
		STAT_NextArgCustom,
		STAT_NextArgCustom_Backslash,
		STAT_Complete,
	};
private:
	Object_parser *_pObjParser;
	bool _depthLevel;
	Stat _stat;
	String _result;
	String _str;
	String _strAhead;
	String _cmdName;
	StringList _args;
	const CommandFormat *_pCmdFmtCur;
	std::unique_ptr<CommandFormat> _pCmdFmtCustom;
	std::unique_ptr<Decomposer> _pDecomposerSub;
public:
	Decomposer(Object_parser *pObjParser, int depthLevel = 0);
	bool FeedChar(Environment &env, char ch);
	bool FeedString(Environment &env, const char *str);
	bool EvaluateSpecialCommand(
		Environment &env, const CommandFormat *pCmdFmt, const StringList &args);
	bool EvaluateCustomCommand(
		Environment &env, const char *cmdName, const StringList &args);
	const char *GetResult() const;
	inline bool IsComplete() const { return _stat == STAT_Complete; }
};

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
inline static bool IsCommandMark(char ch)
{
	return ch == '@' || ch == '\\';
}

inline static bool IsWordChar(char ch)
{
	return IsAlpha(ch) || IsDigit(ch) || ch == '_';
}

Gura_EndModuleScope(doxygen)

#endif
