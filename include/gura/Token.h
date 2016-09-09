//=============================================================================
// Token
//=============================================================================
#ifndef __GURA_TOKEN_H__
#define __GURA_TOKEN_H__

#include "Expr.h"

namespace Gura {

#if 0
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
	TOKEN_White,			// for watcher
	TOKEN_CommentLine,		// for watcher
	TOKEN_CommentBlock,		// for watcher
	TOKEN_DoubleChars,		// only used in tokenizing process
	TOKEN_TripleChars,		// only used in tokenizing process
	TOKEN_Unknown,
};
#endif

//-----------------------------------------------------------------------------
// TokenInfo
//-----------------------------------------------------------------------------
struct TokenInfo {
	//TokenType tokenType;
	int category;
	const char *name;
	const char *symbol;
	OpType opType;
	bool IsIdentical(const TokenInfo &tokenInfo) const { return this == &tokenInfo; }
};

extern const TokenInfo TOKENI_Begin;
extern const TokenInfo TOKENI_Assign;
extern const TokenInfo TOKENI_AssignAdd;
extern const TokenInfo TOKENI_AssignSub;
extern const TokenInfo TOKENI_AssignMul;
extern const TokenInfo TOKENI_AssignDiv;
extern const TokenInfo TOKENI_AssignMod;
extern const TokenInfo TOKENI_AssignPow;
extern const TokenInfo TOKENI_AssignOr;
extern const TokenInfo TOKENI_AssignAnd;
extern const TokenInfo TOKENI_AssignXor;
extern const TokenInfo TOKENI_AssignShl;
extern const TokenInfo TOKENI_AssignShr;
extern const TokenInfo TOKENI_Pair;
extern const TokenInfo TOKENI_OrOr;
extern const TokenInfo TOKENI_AndAnd;
extern const TokenInfo TOKENI_Not;
extern const TokenInfo TOKENI_Contains;
extern const TokenInfo TOKENI_Lt;
extern const TokenInfo TOKENI_Gt;
extern const TokenInfo TOKENI_Le;
extern const TokenInfo TOKENI_Ge;
extern const TokenInfo TOKENI_Cmp;
extern const TokenInfo TOKENI_Eq;
extern const TokenInfo TOKENI_Ne;
extern const TokenInfo TOKENI_Seq;
extern const TokenInfo TOKENI_Or;
extern const TokenInfo TOKENI_Xor;
extern const TokenInfo TOKENI_And;
extern const TokenInfo TOKENI_Shl;
extern const TokenInfo TOKENI_Shr;
extern const TokenInfo TOKENI_Add;
extern const TokenInfo TOKENI_Sub;
extern const TokenInfo TOKENI_Mul;
extern const TokenInfo TOKENI_Div;
extern const TokenInfo TOKENI_Mod;
extern const TokenInfo TOKENI_ModMod;
extern const TokenInfo TOKENI_Question;
extern const TokenInfo TOKENI_Inv;
extern const TokenInfo TOKENI_Pow;
extern const TokenInfo TOKENI_Quote;
extern const TokenInfo TOKENI_Colon;
extern const TokenInfo TOKENI_ColonAfterSuffix;
extern const TokenInfo TOKENI_Dot;
extern const TokenInfo TOKENI_ColonColon;
extern const TokenInfo TOKENI_ColonAsterisk;
extern const TokenInfo TOKENI_ColonAnd;
extern const TokenInfo TOKENI_LParenthesis;		// open toke
extern const TokenInfo TOKENI_RParenthesis;		// close toke
extern const TokenInfo TOKENI_LBrace;				// open toke
extern const TokenInfo TOKENI_RBrace;				// close toke
extern const TokenInfo TOKENI_LBracket;			// open toke
extern const TokenInfo TOKENI_RBracket;			// close toke
extern const TokenInfo TOKENI_LBlockParam;			// open toke
extern const TokenInfo TOKENI_RBlockParam;			// close toke
extern const TokenInfo TOKENI_Comma;
extern const TokenInfo TOKENI_Semicolon;
extern const TokenInfo TOKENI_EOL;
extern const TokenInfo TOKENI_Number;
extern const TokenInfo TOKENI_NumberSuffixed;
extern const TokenInfo TOKENI_String;
extern const TokenInfo TOKENI_StringSuffixed;
extern const TokenInfo TOKENI_Binary;
extern const TokenInfo TOKENI_EmbedString;
extern const TokenInfo TOKENI_Symbol;
extern const TokenInfo TOKENI_EOF;
extern const TokenInfo TOKENI_Expr;
extern const TokenInfo TOKENI_White;				// for watcher
extern const TokenInfo TOKENI_CommentLine;			// for watcher
extern const TokenInfo TOKENI_CommentBlock;		// for watcher
extern const TokenInfo TOKENI_DoubleChars;			// only used in tokenizing process
extern const TokenInfo TOKENI_TripleChars;			// only used in tokenizing process
extern const TokenInfo TOKENI_Unknown;

//-----------------------------------------------------------------------------
// TokenTypeToTokenInfoMap
//-----------------------------------------------------------------------------
//typedef std::map<TokenType, const TokenInfo *> TokenTypeToTokenInfoMap;

//-----------------------------------------------------------------------------
// OpTypeToTokenInfoMap
//-----------------------------------------------------------------------------
typedef std::map<OpType, const TokenInfo *> OpTypeToTokenInfoMap;

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
	const TokenInfo *_pTokenInfo;
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
public:
	//static const TokenInfo _tokenInfoTbl[];
	static const TokenInfo *const _tokenInfoTbl[];
	//static TokenTypeToTokenInfoMap *_pTokenTypeToTokenInfoMap;
	static OpTypeToTokenInfoMap *_pOpTypeToTokenInfoMap;
public:
	inline Token(const Token &token) :
		_pTokenInfo(token._pTokenInfo), _lineNo(token._lineNo), _str(token._str),
		_suffix(token._suffix), _pExpr(token._pExpr) {}
	inline Token(const TokenInfo &tokenInfo, int lineNo) :
		_pTokenInfo(&tokenInfo), _lineNo(lineNo), _pExpr(nullptr) {}
	inline Token(const TokenInfo &tokenInfo, int lineNo, const String &str) :
		_pTokenInfo(&tokenInfo), _lineNo(lineNo), _str(str), _pExpr(nullptr) {}
	inline Token(const TokenInfo &tokenInfo, int lineNo, const String &str, const String &suffix) :
		_pTokenInfo(&tokenInfo), _lineNo(lineNo), _str(str), _suffix(suffix), _pExpr(nullptr) {}
	inline Token(const TokenInfo &tokenInfo, Expr *pExpr) :
		_pTokenInfo(&tokenInfo), _lineNo(pExpr->GetLineNoTop()), _pExpr(pExpr) {}
	inline Token &operator=(const Token &token) {
		_pTokenInfo = token._pTokenInfo, _lineNo = token._lineNo, _pExpr = token._pExpr;
		_str = token._str, _suffix = token._suffix;
		return *this;
	}
	~Token();
	static void Initialize();
	inline const TokenInfo &GetTokenInfo() const { return *_pTokenInfo; }
	//inline TokenType GetType() const { return _pTokenInfo->tokenType; }
	inline int GetCategory() const { return _pTokenInfo->category; }
	inline const char *GetName() const { return _pTokenInfo->name; }
	inline const char *GetSymbol() const { return _pTokenInfo->symbol; }
	inline OpType GetOpType() const { return _pTokenInfo->opType; }
	inline int GetLineNo() const { return _lineNo; }
	//inline bool IsType(TokenType tokenType) const { return GetType() == tokenType; }
	inline bool IsType(const TokenInfo &tokenInfo) const {
		return _pTokenInfo->IsIdentical(tokenInfo);
	}
	inline bool IsOpenToken() const {
		return IsType(TOKENI_LParenthesis) || IsType(TOKENI_LBrace) ||
			IsType(TOKENI_LBracket) || IsType(TOKENI_LBlockParam);
	}
	inline bool IsCloseToken() const {
		return IsType(TOKENI_RParenthesis) || IsType(TOKENI_RBrace) ||
			IsType(TOKENI_RBracket) || IsType(TOKENI_RBlockParam);
	}
	inline bool IsSeparatorToken() const {
		return IsType(TOKENI_EOL) || IsType(TOKENI_EOF) ||
			IsType(TOKENI_Comma) || IsType(TOKENI_Semicolon);
	}
	inline bool IsSuffixToken() const {
		return IsType(TOKENI_Add) ||
			IsType(TOKENI_Mul) || IsType(TOKENI_Question);
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
	//inline static const TokenInfo *LookupTokenInfo(TokenType tokenType) {
	//	return (*_pTokenTypeToTokenInfoMap)[tokenType];
	//}
	inline static const TokenInfo *LookupTokenInfoByOpType(OpType opType) {
		OpTypeToTokenInfoMap::iterator iter = _pOpTypeToTokenInfoMap->find(opType);
		return (iter == _pOpTypeToTokenInfoMap->end())? nullptr : iter->second;
	}
	inline static Precedence LookupPrec(const Token &tokenLeft, const Token &tokenRight) {
		return _LookupPrec(tokenLeft.GetCategory(), tokenRight.GetCategory());
	}
	static int CompareOpTypePrec(OpType opTypeLeft, OpType opTypeRight);
	static Precedence _LookupPrec(int categoryLeft, int categoryRight);
};

//-----------------------------------------------------------------------------
// TokenStack
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE TokenStack : public std::vector<Token> {
public:
	~TokenStack();
	reverse_iterator SeekTerminal(reverse_iterator p);
	Token &Peek(int offset) { return *(rbegin() + offset); }
	void Clear();
	bool CheckBlockParamEnd() const;
	String ToString() const;
	inline bool IsEmpty() const { return size() <= 1; }
};

}

#endif
