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
};

//-----------------------------------------------------------------------------
// Decomposer
//-----------------------------------------------------------------------------
class Decomposer {
public:
	enum Stat {
		STAT_Text,
		STAT_Command,
		STAT_NextArg,
		STAT_ArgWord,
		STAT_ArgBracket,
		STAT_ArgLine,
		STAT_ArgQuoted,
		STAT_ArgPara,
		STAT_ArgParaNewline,
		STAT_SeekOpenBrace,
	};
private:
	Stat _stat;
	String _str;
	String _strAhead;
	Elem_Command *_pElemCmd;
public:
	Decomposer();
	bool FeedChar(Environment &env, char ch);
public:
	inline static bool IsCommandMark(char ch) { return ch == '@' || ch == '\\'; }
};

Gura_EndModuleScope(doxygen)

#endif