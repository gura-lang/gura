//=============================================================================
// Parser.h
//=============================================================================
#ifndef __GURA_DOXYGEN_PARSER_H__
#define __GURA_DOXYGEN_PARSER_H__

#define BeginPushbackRegion(var) \
_pushbackBuff[_pushbackLevel++] = var; \
while (_pushbackLevel > 0) { \
var = _pushbackBuff[--_pushbackLevel];

#define EndPushbackRegion() \
}

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
		STAT_DecomposeInArgPara,
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
	Decomposer *_pDecomposerParent;
	Stat _stat;
	String _result;
	String _strArg;
	String _strAhead;
	String _cmdName;
	StringList _strArgs;
	const CommandFormat *_pCmdFmtCur;
	int _pushbackLevel;
	char _pushbackBuff[16];
	std::unique_ptr<CommandFormat> _pCmdFmtCustom;
	std::unique_ptr<Decomposer> _pDecomposerChild;
public:
	Decomposer(Object_parser *pObjParser, Decomposer *pDecomposerParent = nullptr);
	void SetCommandFormat(const CommandFormat *pCmdFmt);
	bool FeedChar(Environment &env, char ch);
	bool FeedString(Environment &env, const char *str);
	const char *GetResult() const;
	inline bool IsComplete() const { return _stat == STAT_Complete; }
	inline void Pushback(char ch) { _pushbackBuff[_pushbackLevel++] = ch; }

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
