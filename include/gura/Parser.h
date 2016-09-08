//=============================================================================
// Parser
//=============================================================================
#ifndef __GURA_PARSER_H__
#define __GURA_PARSER_H__

#include "Expr.h"

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
// TokenType
//-----------------------------------------------------------------------------
enum TokenType {
	TOKEN_Begin,
	TOKEN_Assign,
	TOKEN_AssignAdd,
	TOKEN_AssignSub,
	TOKEN_AssignMul,
	TOKEN_AssignDiv,
	TOKEN_AssignMod,
	TOKEN_AssignPow,
	TOKEN_AssignOr,
	TOKEN_AssignAnd,
	TOKEN_AssignXor,
	TOKEN_AssignShl,
	TOKEN_AssignShr,
	TOKEN_Pair,
	TOKEN_OrOr,
	TOKEN_AndAnd,
	TOKEN_Not,
	TOKEN_Contains,
	TOKEN_Lt,
	TOKEN_Gt,
	TOKEN_Le,
	TOKEN_Ge,
	TOKEN_Cmp,
	TOKEN_Eq,
	TOKEN_Ne,
	TOKEN_Seq,
	TOKEN_Or,
	TOKEN_Xor,
	TOKEN_And,
	TOKEN_Shl,
	TOKEN_Shr,
	TOKEN_Add,
	TOKEN_Sub,
	TOKEN_Mul,
	TOKEN_Div,
	TOKEN_Mod,
	TOKEN_ModMod,
	TOKEN_Question,
	TOKEN_Inv,
	TOKEN_Pow,
	TOKEN_Quote,
	TOKEN_Colon,
	TOKEN_ColonAfterSuffix,
	TOKEN_Dot,
	TOKEN_ColonColon,
	TOKEN_ColonAsterisk,
	TOKEN_ColonAnd,
	TOKEN_LParenthesis,		// open token
	TOKEN_RParenthesis,		// close token
	TOKEN_LBrace,			// open token
	TOKEN_RBrace,			// close token
	TOKEN_LBracket,			// open token
	TOKEN_RBracket,			// close token
	TOKEN_LBlockParam,		// open token
	TOKEN_RBlockParam,		// close token
	TOKEN_Comma,
	TOKEN_Semicolon,
	TOKEN_EOL,
	TOKEN_Number,
	TOKEN_NumberSuffixed,
	TOKEN_String,
	TOKEN_StringSuffixed,
	TOKEN_Binary,
	TOKEN_EmbedString,
	TOKEN_Symbol,
	TOKEN_EOF,
	TOKEN_Expr,
	TOKEN_Unknown,
	TOKEN_White,			// for watcher
	TOKEN_CommentLine,		// for watcher
	TOKEN_CommentBlock,		// for watcher
	TOKEN_DoubleChars,		// only used in tokenizing process
	TOKEN_TripleChars,		// only used in tokenizing process
};

//-----------------------------------------------------------------------------
// TokenTypeInfo
//-----------------------------------------------------------------------------
struct TokenTypeInfo {
	TokenType tokenType;
	int index;
	const char *name;
	const char *symbol;
	OpType opType;
};

//-----------------------------------------------------------------------------
// TokenTypeToIndexMap
//-----------------------------------------------------------------------------
typedef std::map<TokenType, int> TokenTypeToIndexMap;

//-----------------------------------------------------------------------------
// Token
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Token {
public:
	enum Precedence {
		PREC_LT,
		PREC_EQ,
		PREC_GT,
		PREC_Error,
	};
private:
	TokenType _tokenType;
	int _lineNo;
	String _str;
	String _suffix;
	// _pExpr is only available for the following token types.
	// TOKEN_Expr          (Expr)
	// TOKEN_LParenthesis  (Expr_Lister)
	// TOKEN_LBrace        (Expr_Block)
	// TOKEN_LBracket      (Expr_Lister)
	// TOKEN_LBlockParam   (Expr_BlockParam)
	Expr *_pExpr;
	static TokenTypeToIndexMap *_pTokenTypeToIndexMap;
	static const TokenTypeInfo _tokenTypeInfoTbl[];
public:
	static const Token Unknown;
public:
	inline Token() : _tokenType(TOKEN_Unknown), _lineNo(0), _pExpr(nullptr) {}
	inline Token(const Token &token) :
		_tokenType(token._tokenType), _lineNo(token._lineNo), _str(token._str),
		_suffix(token._suffix), _pExpr(token._pExpr) {}
	inline Token(TokenType tokenType, int lineNo) :
		_tokenType(tokenType), _lineNo(lineNo), _pExpr(nullptr) {}
	inline Token(TokenType tokenType, int lineNo, const String &str) :
		_tokenType(tokenType), _lineNo(lineNo), _str(str), _pExpr(nullptr) {}
	inline Token(TokenType tokenType, int lineNo, const String &str, const String &suffix) :
		_tokenType(tokenType), _lineNo(lineNo), _str(str), _suffix(suffix), _pExpr(nullptr) {}
	inline Token(TokenType tokenType, Expr *pExpr) :
		_tokenType(tokenType), _lineNo(pExpr->GetLineNoTop()), _pExpr(pExpr) {}
	inline Token &operator=(const Token &token) {
		_tokenType = token._tokenType, _lineNo = token._lineNo, _pExpr = token._pExpr;
		_str = token._str, _suffix = token._suffix;
		return *this;
	}
	~Token();
	static void Initialize();
	inline TokenType GetType() const { return _tokenType; }
	inline int GetLineNo() const { return _lineNo; }
	inline bool IsType(TokenType tokenType) const { return _tokenType == tokenType; }
	inline bool IsOpenToken() const {
		return IsType(TOKEN_LParenthesis) || IsType(TOKEN_LBrace) ||
			IsType(TOKEN_LBracket) || IsType(TOKEN_LBlockParam);
	}
	inline bool IsCloseToken() const {
		return IsType(TOKEN_RParenthesis) || IsType(TOKEN_RBrace) ||
			IsType(TOKEN_RBracket) || IsType(TOKEN_RBlockParam);
	}
	inline bool IsSeparatorToken() const {
		return IsType(TOKEN_EOL) || IsType(TOKEN_EOF) ||
			IsType(TOKEN_Comma) || IsType(TOKEN_Semicolon);
	}
	inline bool IsSuffixToken() const {
		return IsType(TOKEN_Add) ||
			IsType(TOKEN_Mul) || IsType(TOKEN_Question);
	}
	inline Expr *GetExpr() const { return _pExpr; }
	inline void SetExpr(Expr *pExpr) { _pExpr = pExpr; }
	inline const String &GetStringSTL() const { return _str; }
	inline const String &GetSuffixSTL() const { return _suffix; }
	inline const char *GetString() const { return _str.c_str(); }
	inline const char *GetSuffix() const { return _suffix.c_str(); }
	inline size_t GetStringSize() const { return _str.size(); }
	inline void AddString(const String &str) { _str.append(str); }
	const char *GetTypeSymbol() const;
public:
	inline static int TokenTypeToIndex(TokenType tokenType) {
		return (*_pTokenTypeToIndexMap)[tokenType];
	}
	static Precedence LookupPrec(TokenType tokenTypeLeft, TokenType tokenTypeRight);
	static int CompareOpTypePrec(OpType opType1, OpType opType2);
	static const TokenTypeInfo *LookupTokenTypeInfo(TokenType tokenType);
	static const TokenTypeInfo *LookupTokenTypeInfoByOpType(OpType opType);
	static Precedence _LookupPrec(int indexLeft, int indexRight);
	inline static Precedence LookupPrecFast(TokenType tokenTypeLeft, TokenType tokenTypeRight) {
		return _LookupPrec(TokenTypeToIndex(tokenTypeLeft), TokenTypeToIndex(tokenTypeRight));
	}
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
	class GURA_DLLDECLARE TokenStack : public std::vector<Token> {
	public:
		~TokenStack();
		reverse_iterator SeekTerminal(reverse_iterator p);
		Token &Peek(int offset) { return *(rbegin() + offset); }
		void Clear();
		String ToString() const;
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
	inline bool IsStackEmpty() const { return _tokenStack.size() <= 1; }
	inline bool IsContinued() const { return !IsStackEmpty() || !(_stat == STAT_Start || _stat == STAT_BOF); }
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
