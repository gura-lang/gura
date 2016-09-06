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
// Parser
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Parser {
private:
	enum Stat {
		STAT_BOF, STAT_BOF_2nd, STAT_BOF_3rd,
		STAT_Start,
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
	enum Precedence {
		PREC_LT,
		PREC_EQ,
		PREC_GT,
		PREC_Error,
	};
	enum TokenType {
		ETYPE_Begin,
		ETYPE_Assign,
		ETYPE_AssignAdd,
		ETYPE_AssignSub,
		ETYPE_AssignMul,
		ETYPE_AssignDiv,
		ETYPE_AssignMod,
		ETYPE_AssignPow,
		ETYPE_AssignOr,
		ETYPE_AssignAnd,
		ETYPE_AssignXor,
		ETYPE_AssignShl,
		ETYPE_AssignShr,
		ETYPE_Pair,
		ETYPE_OrOr,
		ETYPE_AndAnd,
		ETYPE_Not,
		ETYPE_Contains,
		ETYPE_Lt,
		ETYPE_Gt,
		ETYPE_Le,
		ETYPE_Ge,
		ETYPE_Cmp,
		ETYPE_Eq,
		ETYPE_Ne,
		ETYPE_Seq,
		ETYPE_Or,
		ETYPE_Xor,
		ETYPE_And,
		ETYPE_Shl,
		ETYPE_Shr,
		ETYPE_Add,
		ETYPE_Sub,
		ETYPE_Mul,
		ETYPE_Div,
		ETYPE_Mod,
		ETYPE_ModMod,
		ETYPE_Question,
		ETYPE_Inv,
		ETYPE_Pow,
		ETYPE_Quote,
		ETYPE_Colon,
		ETYPE_ColonAfterSuffix,
		ETYPE_Dot,
		ETYPE_ColonColon,
		ETYPE_ColonAsterisk,
		ETYPE_ColonAnd,
		ETYPE_LParenthesis,		// open token
		ETYPE_RParenthesis,		// close token
		ETYPE_LBrace,			// open token
		ETYPE_RBrace,			// close token
		ETYPE_LBracket,			// open token
		ETYPE_RBracket,			// close token
		ETYPE_LBlockParam,		// open token
		ETYPE_RBlockParam,		// close token
		ETYPE_Comma,
		ETYPE_Semicolon,
		ETYPE_EOL,
		ETYPE_Number,
		ETYPE_NumberSuffixed,
		ETYPE_String,
		ETYPE_StringSuffixed,
		ETYPE_Binary,
		ETYPE_EmbedString,
		ETYPE_Symbol,
		ETYPE_EOF,
		ETYPE_Expr,
		ETYPE_Unknown,
		ETYPE_DoubleChars,		// only used in tokenizing process
		ETYPE_TripleChars,		// only used in tokenizing process
	};
	struct TokenTypeInfo {
		TokenType tokenType;
		int index;
		const char *name;
		const char *symbol;
		OpType opType;
	};
	typedef std::map<TokenType, int> TokenTypeToIndexMap;
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
	class GURA_DLLDECLARE Token {
	private:
		TokenType _tokenType;
		int _lineNo;
		String _str;
		String _suffix;
		// _pExpr is only available for the following token types.
		// ETYPE_Expr          (Expr)
		// ETYPE_LParenthesis  (Expr_Lister)
		// ETYPE_LBrace        (Expr_Block)
		// ETYPE_LBracket      (Expr_Lister)
		// ETYPE_LBlockParam   (Expr_BlockParam)
		Expr *_pExpr;
	public:
		static const Token Unknown;
	public:
		inline Token() : _tokenType(ETYPE_Unknown), _lineNo(0), _pExpr(nullptr) {}
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
		inline TokenType GetType() const { return _tokenType; }
		inline int GetLineNo() const { return _lineNo; }
		inline bool IsType(TokenType tokenType) const { return _tokenType == tokenType; }
		inline bool IsOpenToken() const {
			return IsType(ETYPE_LParenthesis) || IsType(ETYPE_LBrace) ||
					IsType(ETYPE_LBracket) || IsType(ETYPE_LBlockParam);
		}
		inline bool IsCloseToken() const {
			return IsType(ETYPE_RParenthesis) || IsType(ETYPE_RBrace) ||
					IsType(ETYPE_RBracket) || IsType(ETYPE_RBlockParam);
		}
		inline bool IsSeparatorToken() const {
			return IsType(ETYPE_EOL) || IsType(ETYPE_EOF) ||
								IsType(ETYPE_Comma) || IsType(ETYPE_Semicolon);
		}
		inline bool IsSuffixToken() const {
			return IsType(ETYPE_Add) ||
						IsType(ETYPE_Mul) || IsType(ETYPE_Question);
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
	};
	class GURA_DLLDECLARE TokenStack : public std::vector<Token> {
	public:
		~TokenStack();
		reverse_iterator SeekTerminal(reverse_iterator p);
		Token &Peek(int offset) { return *(rbegin() + offset); }
		void Clear();
		String ToString() const;
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
	int _lineNoOfTokenPrev;
	TokenStack _tokenStack;
	StringInfo _stringInfo;
	TokenTypeToIndexMap _tokenTypeToIndexMap;
	CharConverter _charConverter;
	String _strIndent;
	bool _enablePreparatorFlag;
	bool _interactiveFlag;
	static const TokenTypeInfo _tokenTypeInfoTbl[];
public:
	Parser(Signal &sig, const String &sourceName,
		   int cntLineStart = 0, bool enablePreparatorFlag = true);
	~Parser();
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
	inline int TokenTypeToIndex(TokenType tokenType) { return _tokenTypeToIndexMap[tokenType]; }
	static const TokenTypeInfo *LookupTokenTypeInfo(TokenType tokenType);
	static const TokenTypeInfo *LookupTokenTypeInfoByOpType(OpType opType);
	static Precedence LookupPrec(TokenType tokenTypeLeft, TokenType tokenTypeRight);
	static int CompareOpTypePrec(OpType opType1, OpType opType2);
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
	static Precedence _LookupPrec(int indexLeft, int indexRight);
	inline  Precedence LookupPrecFast(TokenType tokenTypeLeft, TokenType tokenTypeRight) {
		return _LookupPrec(TokenTypeToIndex(tokenTypeLeft), TokenTypeToIndex(tokenTypeRight));
	}
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
