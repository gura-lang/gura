//=============================================================================
// Parser.h
//=============================================================================
#ifndef __GURA_DOXYGEN_PARSER_H__
#define __GURA_DOXYGEN_PARSER_H__

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
class Parser {
public:
	enum Stat {
		STAT_Init,
		STAT_String,
		STAT_AcceptCommandInString,
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
	const Aliases *_pAliases;
	Parser *_pParserParent;
	Stat _stat;
	String _str;
	String _strArg;
	String _strAhead;
	String _cmdName;
	StringList _strArgs;
	int _pushbackLevel;
	char _pushbackBuff[16];
	char _chAhead;
	char _chPrev;
	AutoPtr<ElemOwner> _pElemOwner;
	AutoPtr<Elem_Command> _pElemCmdCur;
	AutoPtr<Elem_Composite> _pElemArg;
	std::unique_ptr<Parser> _pParserChild;
public:
	Parser(const Aliases *pAliases, Parser *pParserParent = nullptr);
	void SetCommandSpecial(const CommandFormat *pCmdFmt);
	void SetCommandCustom(const String &cmdName);
	bool FeedChar(Environment &env, char ch);
	bool FeedString(Environment &env, const char *str);
	String EvaluateCustomCommand(Environment &env) const;
	void FlushElemString(ElemOwner &elemOwner, const char *str);
	void FlushElemCommand(Elem_Command *pElem);
	static bool ContainsCommand(const char *str);
	inline void SetElemOwner(ElemOwner *pElemOwner) { _pElemOwner.reset(pElemOwner); }
	inline const ElemOwner &GetElemOwner() const { return *_pElemOwner; }
	inline bool IsTopLevel() const { return _pParserParent == nullptr; }
	inline bool IsComplete() const { return _stat == STAT_Complete; }
	inline const char *GetString() const { return _str.c_str(); }
	inline void Pushback(char ch) {
		if (_pParserParent == nullptr) {
			_pushbackBuff[_pushbackLevel++] = ch;
		} else {
			_pParserParent->Pushback(ch);
		}
	}
	inline static bool IsCommandEnd(const String &cmdName, char ch) {
		return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0' ||
			(!(cmdName == "f" || cmdName.empty()) && (ch == '[' || ch == '{'));
	}
};

Gura_EndModuleScope(doxygen)

#endif
