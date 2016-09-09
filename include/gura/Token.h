//=============================================================================
// Token
//=============================================================================
#ifndef __GURA_TOKEN_H__
#define __GURA_TOKEN_H__

#include "Expr.h"

namespace Gura {

//-----------------------------------------------------------------------------
// TokenInfo
//-----------------------------------------------------------------------------
struct TokenInfo {
	int category;
	const char *name;
	const char *symbol;
	OpType opType;
	bool IsIdentical(const TokenInfo &tokenInfo) const { return this == &tokenInfo; }
};

extern const TokenInfo TOKEN_Begin;
extern const TokenInfo TOKEN_Assign;
extern const TokenInfo TOKEN_AssignAdd;
extern const TokenInfo TOKEN_AssignSub;
extern const TokenInfo TOKEN_AssignMul;
extern const TokenInfo TOKEN_AssignDiv;
extern const TokenInfo TOKEN_AssignMod;
extern const TokenInfo TOKEN_AssignPow;
extern const TokenInfo TOKEN_AssignOr;
extern const TokenInfo TOKEN_AssignAnd;
extern const TokenInfo TOKEN_AssignXor;
extern const TokenInfo TOKEN_AssignShl;
extern const TokenInfo TOKEN_AssignShr;
extern const TokenInfo TOKEN_Pair;
extern const TokenInfo TOKEN_OrOr;
extern const TokenInfo TOKEN_AndAnd;
extern const TokenInfo TOKEN_Not;
extern const TokenInfo TOKEN_Contains;
extern const TokenInfo TOKEN_Lt;
extern const TokenInfo TOKEN_Gt;
extern const TokenInfo TOKEN_Le;
extern const TokenInfo TOKEN_Ge;
extern const TokenInfo TOKEN_Cmp;
extern const TokenInfo TOKEN_Eq;
extern const TokenInfo TOKEN_Ne;
extern const TokenInfo TOKEN_Seq;
extern const TokenInfo TOKEN_Or;
extern const TokenInfo TOKEN_Xor;
extern const TokenInfo TOKEN_And;
extern const TokenInfo TOKEN_Shl;
extern const TokenInfo TOKEN_Shr;
extern const TokenInfo TOKEN_Add;
extern const TokenInfo TOKEN_Sub;
extern const TokenInfo TOKEN_Mul;
extern const TokenInfo TOKEN_Div;
extern const TokenInfo TOKEN_Mod;
extern const TokenInfo TOKEN_ModMod;
extern const TokenInfo TOKEN_Question;
extern const TokenInfo TOKEN_Inv;
extern const TokenInfo TOKEN_Pow;
extern const TokenInfo TOKEN_Quote;
extern const TokenInfo TOKEN_Colon;
extern const TokenInfo TOKEN_ColonAfterSuffix;
extern const TokenInfo TOKEN_Dot;
extern const TokenInfo TOKEN_ColonColon;
extern const TokenInfo TOKEN_ColonAsterisk;
extern const TokenInfo TOKEN_ColonAnd;
extern const TokenInfo TOKEN_LParenthesis;		// open toke
extern const TokenInfo TOKEN_RParenthesis;		// close toke
extern const TokenInfo TOKEN_LBrace;			// open toke
extern const TokenInfo TOKEN_RBrace;			// close toke
extern const TokenInfo TOKEN_LBracket;			// open toke
extern const TokenInfo TOKEN_RBracket;			// close toke
extern const TokenInfo TOKEN_LBlockParam;		// open toke
extern const TokenInfo TOKEN_RBlockParam;		// close toke
extern const TokenInfo TOKEN_Comma;
extern const TokenInfo TOKEN_Semicolon;
extern const TokenInfo TOKEN_EOL;
extern const TokenInfo TOKEN_Number;
extern const TokenInfo TOKEN_NumberSuffixed;
extern const TokenInfo TOKEN_String;
extern const TokenInfo TOKEN_StringSuffixed;
extern const TokenInfo TOKEN_Binary;
extern const TokenInfo TOKEN_EmbedString;
extern const TokenInfo TOKEN_Symbol;
extern const TokenInfo TOKEN_EOF;
extern const TokenInfo TOKEN_Expr;
extern const TokenInfo TOKEN_White;				// for watcher
extern const TokenInfo TOKEN_CommentLine;		// for watcher
extern const TokenInfo TOKEN_CommentBlock;		// for watcher
extern const TokenInfo TOKEN_DoubleChars;		// only used in tokenizing process
extern const TokenInfo TOKEN_TripleChars;		// only used in tokenizing process
extern const TokenInfo TOKEN_Unknown;

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
	static const TokenInfo *const _tokenInfoTbl[];
	static OpTypeToTokenInfoMap *_pOpTypeToTokenInfoMap;
public:
	inline Token() :
		_pTokenInfo(&TOKEN_Unknown), _lineNo(0) {}
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
	inline int GetCategory() const { return _pTokenInfo->category; }
	inline const char *GetName() const { return _pTokenInfo->name; }
	inline const char *GetSymbol() const { return _pTokenInfo->symbol; }
	inline OpType GetOpType() const { return _pTokenInfo->opType; }
	inline int GetLineNo() const { return _lineNo; }
	inline bool IsType(const TokenInfo &tokenInfo) const {
		return _pTokenInfo->IsIdentical(tokenInfo);
	}
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
