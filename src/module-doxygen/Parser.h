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
		STAT_LineDoxygenFirst,
		STAT_LineDoxygen,
		STAT_LineComment,
		STAT_BlockCommentBgn,
		STAT_BlockCommentBgn_Asterisk,
		STAT_BlockDoxygenFirst,
		STAT_BlockDoxygen,
		STAT_BlockDoxygen_Asterisk,
		STAT_BlockDoxygen_Indent,
		STAT_BlockDoxygen_IndentAsterisk,
		STAT_BlockDoxygen_IndentAfterAsterisk,
		STAT_BlockComment,
		STAT_BlockComment_Asterisk,
		STAT_Slash,
		STAT_ExIndent,
		STAT_ExDoxygen,
	};
private:
	Stat _stat;
	std::unique_ptr<Decomposer> _pDecomposer;
public:
	Parser(Object_parser *pObjParser);
	bool FeedChar(Environment &env, char ch);
	const char *ParseStream(Environment &env, SimpleStream &stream);
	void SetExtractedMode() { _stat = STAT_ExIndent; }
};

//-----------------------------------------------------------------------------
// Decomposer
//-----------------------------------------------------------------------------
class Decomposer {
public:
	enum Stat {
		STAT_Init,
		STAT_Text,
		STAT_AcceptCommandInText,
		STAT_AcceptCommandInArgLine,
		STAT_AcceptCommandInArgPara,
		STAT_AcceptCommandInArgCustom,
		STAT_CommandSpecial,
		STAT_CommandCustom,
		STAT_NextArg,
		STAT_BranchArg,
		STAT_ArgWord,
		STAT_ArgWord_Punctuation,
		STAT_ArgWordQuote,
		STAT_ArgBracket,
		STAT_ArgLine,
		STAT_ArgQuote,
		STAT_ArgBrace,
		STAT_ArgPara,
		STAT_ArgParaNewline,
		STAT_ArgCustom,
		STAT_ArgCustom_Backslash,
		STAT_Complete,
	};
private:
	Object_parser *_pObjParser;
	Decomposer *_pDecomposerParent;
	Stat _stat;
	String _text;
	String _result;
	String _strArg;
	String _strAhead;
	String _cmdName;
	StringList _strArgs;
	const CommandFormat *_pCmdFmtCur;
	int _pushbackLevel;
	char _pushbackBuff[16];
	char _chPunctuation;
	char _chPrev;
	bool _aheadFlag;
	AutoPtr<Elem_Container> _pElemResult;
	std::unique_ptr<CommandFormat> _pCmdFmtCustom;
	std::unique_ptr<Decomposer> _pDecomposerChild;
public:
	Decomposer(Object_parser *pObjParser, Decomposer *pDecomposerParent = nullptr);
	void SetCommandSpecial(const CommandFormat *pCmdFmt);
	void SetCommandCustom(const char *cmdName);
	bool FeedChar(Environment &env, char ch);
	bool FeedString(Environment &env, const char *str);
	const char *GetResult() const;
	bool EvaluateCommand();
	static bool ContainsCommand(const char *str);
	inline bool IsTopLevel() const { return _pDecomposerParent == nullptr; }
	inline bool IsComplete() const { return _stat == STAT_Complete; }
	inline void Pushback(char ch) {
		if (_pDecomposerParent == nullptr) {
			_pushbackBuff[_pushbackLevel++] = ch;
		} else {
			_pDecomposerParent->Pushback(ch);
		}
	}
	inline void SetAheadFlag(bool aheadFlag) { _aheadFlag = aheadFlag; }
	inline static bool IsCommandEnd(const String &cmdName, char ch) {
		return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' ||
			(!(cmdName == "f" || cmdName.empty()) && (ch == '[' || ch == '{'));
	}
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
