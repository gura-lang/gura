//=============================================================================
// Parser.h
//=============================================================================
#ifndef __GURA_DOXYGEN_PARSER_H__
#define __GURA_DOXYGEN_PARSER_H__
#include "Elem.h"

Gura_BeginModuleScope(doxygen)

class Decomposer;

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
	Parser();
	bool FeedChar(Environment &env, char ch);
	const Elem *ParseStream(Environment &env, SimpleStream &stream);
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
		STAT_BranchArg,
		STAT_ArgWord,
		STAT_ArgWord_Period,
		STAT_ArgBracket,
		STAT_ArgLine,
		STAT_ArgQuote,
		STAT_ArgBrace,
		STAT_ArgPara,
		STAT_ArgParaNewline,
		STAT_ArgCustom,
		STAT_ArgCustom_Backslash,
	};
private:
	Stat _stat;
	String _str;
	String _strAhead;
	String _name;
	AutoPtr<Elem_Container> _pElemRoot;
	AutoPtr<Elem_Command> _pElemCmd;
public:
	Decomposer();
	bool FeedChar(Environment &env, char ch);
	const Elem *DecomposeString(Environment &env, const char *str);
	const Elem *GetResult();
public:
};

//-----------------------------------------------------------------------------
// Command
//-----------------------------------------------------------------------------
class Command {
public:
	enum Stat {
		STAT_Init,
		STAT_Text,
		STAT_Command,
		STAT_CommandInArgPara,
		STAT_CommandInArgCustom,
		STAT_NextArg,
		STAT_BranchArg,
		STAT_ArgWord,
		STAT_ArgWord_Period,
		STAT_ArgBracket,
		STAT_ArgLine,
		STAT_ArgQuote,
		STAT_ArgBrace,
		STAT_ArgPara,
		STAT_ArgParaNewline,
		STAT_ArgCustom,
		STAT_ArgCustom_Backslash,
	};
protected:
	Stat _stat;
	String _str;
	String _strAhead;
	String _name;
	int _iArg;
	StringList _args;
	const CommandFormat *_pCmdFmt;
public:
	Command();
	bool FeedChar(Environment &env, char ch);
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
