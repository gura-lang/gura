//=============================================================================
// Token
//=============================================================================
#ifndef __GURA_TOKEN_H__
#define __GURA_TOKEN_H__

#include "Expr.h"

namespace Gura {

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
// TokenInfo
//-----------------------------------------------------------------------------
struct TokenInfo {
	TokenType tokenType;
	int index;
	const char *name;
	const char *symbol;
	OpType opType;
};

//-----------------------------------------------------------------------------
// TokenTypeToTokenInfoMap
//-----------------------------------------------------------------------------
typedef std::map<TokenType, const TokenInfo *> TokenTypeToTokenInfoMap;

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
	static const TokenInfo _tokenInfoTbl[];
	static TokenTypeToTokenInfoMap *_pTokenTypeToTokenInfoMap;
	static OpTypeToTokenInfoMap *_pOpTypeToTokenInfoMap;
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
	inline static const TokenInfo *LookupTokenInfo(TokenType tokenType) {
		return (*_pTokenTypeToTokenInfoMap)[tokenType];
	}
	inline static const TokenInfo *LookupTokenInfoByOpType(OpType opType) {
		OpTypeToTokenInfoMap::iterator iter = _pOpTypeToTokenInfoMap->find(opType);
		return (iter == _pOpTypeToTokenInfoMap->end())? nullptr : iter->second;
	}
	static Precedence LookupPrec(TokenType tokenTypeLeft, TokenType tokenTypeRight);
	static int CompareOpTypePrec(OpType opTypeLeft, OpType opTypeRight);
	static Precedence _LookupPrec(int indexLeft, int indexRight);
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
