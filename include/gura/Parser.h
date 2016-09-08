//=============================================================================
// Parser
//=============================================================================
#ifndef __GURA_PARSER_H__
#define __GURA_PARSER_H__

#include "Token.h"

namespace Gura {

//-----------------------------------------------------------------------------
// MagicCommentParser
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE MagicCommentParser {
private:
	enum Stat {
		STAT_Idle, STAT_Start, STAT_SkipSpace, STAT_CodingName,
	};
private:
	Stat _stat;
	String _field;
public:
	MagicCommentParser();
	~MagicCommentParser();
	bool ParseChar(char ch);
	inline const char *GetEncoding() const { return _field.c_str(); }
};


//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Parser {
private:
	enum Stat {
		STAT_BOF, STAT_BOF_2nd, STAT_BOF_3rd,
		STAT_Start,
		STAT_White,
		STAT_DoubleChars, STAT_TripleChars, STAT_Escape,
		STAT_Colon,
		STAT_Error, STAT_ErrorRecovery,
		STAT_AfterLBrace,
		STAT_NumberPre, STAT_NumberHex, STAT_NumberOct, STAT_NumberBin,
		STAT_NumberAfterDot, STAT_Number,
		STAT_NumberExpAfterE, STAT_NumberExpAfterSign, STAT_NumberExp,
		STAT_NumberSuffixed,
		STAT_Symbol, STAT_SymbolExclamation,
		STAT_CommentLineTop, STAT_CommentLine, STAT_MagicCommentLine,
		STAT_ShebangLine,
		STAT_CommentBlock, STAT_CommentBlockEnd, STAT_CommentBlockNest,
		STAT_StringFirst, STAT_StringSecond,
		STAT_String, STAT_MString, STAT_MStringWise, STAT_MStringLineHead,
		STAT_StringEsc, STAT_StringEscHex, STAT_StringEscOct, STAT_StringEscUnicode,
		STAT_StringInCommentBlock, STAT_StringEscInCommentBlock,
		STAT_MStringEndFirst, STAT_MStringEndSecond,
		STAT_StringPost, STAT_StringSuffixed,
		STAT_RecoverConsole,
	};
public:
	struct StringInfo {
		char chBorder;
		bool rawFlag;		// prefixed by 'r' or 'R'
		bool binaryFlag;	// prefixed by 'b' or 'B'
		bool wiseFlag;		// prefixed by 'R'
		bool embedFlag;		// prefixed by 'e'
		Stat statRtn;
		int cntRest;
		ULong accum;
		String strIndentRef;
	};
	class GURA_DLLDECLARE TokenWatcher {
	public:
		virtual void FeedToken(Environment &env, const Token &token) = 0;
	};
private:
	Signal &_sig;
	Stat _stat;
	bool _lineHeadFlag;
	MagicCommentParser _magicCommentParser;
	bool _appearShebangFlag;
	bool _blockParamFlag;
	int _cntLine;
	int _cntCol;
	int _commentNestLevel;
	AutoPtr<StringShared> _pSourceName;
	String _field;
	String _suffix;
	ExprOwner *_pExprOwner;
	const Expr *_pExprParent;
	TokenType _tokenTypePrev;
	int _lineNoTop;
	int _lineNoOfTokenPrev;
	TokenStack _tokenStack;
	StringInfo _stringInfo;
	CharConverter _charConverter;
	String _strIndent;
	bool _enablePreparatorFlag;
	bool _interactiveFlag;
	TokenWatcher *_pTokenWatcher;
public:
	Parser(Signal &sig, const String &sourceName,
		   int cntLineStart = 0, bool enablePreparatorFlag = true);
	~Parser();
	static void Initialize();
	void InitStack();
	bool ParseChar(Environment &env, char ch);
	Expr_Root *ParseStream(Environment &env, Stream &stream);
	Expr_Root *ParseStream(Environment &env, const char *pathName, const char *encoding);
	bool ParseString(Environment &env, ExprOwner &exprOwner,
							const char *str, size_t len, bool parseNullFlag);
	inline bool ParseString(Environment &env, ExprOwner &exprOwner,
							const char *str, bool parseNullFlag) {
		return ParseString(env, exprOwner, str, ::strlen(str), parseNullFlag);
	}
	void EvalConsoleChar(Environment &env, Expr_Root *pExprRoot, Stream *pConsole, char ch);
	inline bool IsContinued() const {
		return !_tokenStack.IsEmpty() || !(_stat == STAT_Start || _stat == STAT_BOF);
	}
	inline int GetLineNo() const { return _cntLine + 1; }
	inline int GetColPos() const { return _cntCol; }
	inline void SetTokenWatcher(TokenWatcher *pTokenWatcher) { _pTokenWatcher = pTokenWatcher; }
	inline bool IsTokenWatched() const { return _pTokenWatcher != nullptr; }
	static bool ParseDottedIdentifier(const char *moduleName, SymbolList &symbolList);
	static bool ParseDottedIdentifier(const Expr *pExpr, SymbolList &symbolList);
	void SetError(ErrorType errType, const char *format, ...);
private:
	Expr_Caller *CreateCaller(
		Environment &env, Expr *pExprCar, Expr_Lister *pExprLister,
		Expr_Block *pExprBlock, const Expr_Caller *pExprLeader);
	bool CheckBlockParamEnd() const;
	static TokenType TokenTypeForString(const StringInfo &stringInfo);
	static bool CheckStringPrefix(StringInfo &stringInfo, const String &field);
	void SetError_InvalidToken();
	void SetError_InvalidToken(int lineno);
	bool FeedToken(Environment &env, const Token &token);
	bool _FeedToken(Environment &env, const Token &token);
	bool EmitExpr(ExprOwner &exprOwner, const Expr *pExprParent, Expr *pExpr);
	bool ReduceOneToken(Environment &env);
	bool ReduceTwoTokens(Environment &env);
	bool ReduceThreeTokens(Environment &env);
	bool ReduceFourTokens(Environment &env);
	bool ReduceFiveTokens(Environment &env);
};

}

#endif
