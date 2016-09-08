//=============================================================================
// Token
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Token
//-----------------------------------------------------------------------------
TokenTypeToTokenInfoMap *Token::_pTokenTypeToTokenInfoMap = nullptr;
OpTypeToTokenInfoMap *Token::_pOpTypeToTokenInfoMap = nullptr;

const TokenInfo Token::_tokenInfoTbl[] = {
	{ TOKEN_Begin,				 1, "Begin",			"[Bgn]",	OPTYPE_None		},	// B
	{ TOKEN_Assign,				 2, "Assign",			"=",		OPTYPE_None		},	// =
	{ TOKEN_AssignAdd,			 2, "AssignAdd",		"+=",		OPTYPE_None		},
	{ TOKEN_AssignSub,			 2, "AssignSub",		"-=",		OPTYPE_None		},
	{ TOKEN_AssignMul,			 2, "AssignMul",		"*=",		OPTYPE_None		},
	{ TOKEN_AssignDiv,			 2, "AssignDiv",		"/=",		OPTYPE_None		},
	{ TOKEN_AssignMod,			 2, "AssignMod",		"%=",		OPTYPE_None		},
	{ TOKEN_AssignPow,			 2, "AssignPow",		"**=",		OPTYPE_None		},
	{ TOKEN_AssignOr,			 2, "AssignOr",			"|=",		OPTYPE_None		},
	{ TOKEN_AssignAnd,			 2, "AssignAnd",		"&=",		OPTYPE_None		},
	{ TOKEN_AssignXor,			 2, "AssignXor",		"^=",		OPTYPE_None		},
	{ TOKEN_AssignShl,			 2, "AssignShl",		"<<=",		OPTYPE_None		},
	{ TOKEN_AssignShr,			 2, "AssignShr",		">>=",		OPTYPE_None		},
	{ TOKEN_Pair,				 2, "Pair",				"=>",		OPTYPE_Pair		},
	{ TOKEN_OrOr,				 3, "OrOr",				"||",		OPTYPE_OrOr		},	// ||
	{ TOKEN_AndAnd,				 4, "AndAnd",			"&&",		OPTYPE_AndAnd	},	// &&
	{ TOKEN_Not,				 5, "Not",				"!",		OPTYPE_Not		},	// !
	{ TOKEN_Contains,			 6, "Contains",			"in",		OPTYPE_Contains	},	// in
	{ TOKEN_Lt,					 7, "Lt",				"<",		OPTYPE_Lt		},	// <
	{ TOKEN_Gt,					 7, "Gt",				">",		OPTYPE_Gt		},
	{ TOKEN_Le,	 				 7, "Le",				"<=",		OPTYPE_Le		},
	{ TOKEN_Ge,					 7, "Ge",				">=",		OPTYPE_Ge		},
	{ TOKEN_Cmp,				 7, "Cmp",				"<=>",		OPTYPE_Cmp		},
	{ TOKEN_Eq,					 7, "Eq",				"==",		OPTYPE_Eq		},
	{ TOKEN_Ne,					 7, "Ne",				"!=",		OPTYPE_Ne		},
	{ TOKEN_Seq,			 	 8, "Seq",				"..",		OPTYPE_Seq		},	// ..
	{ TOKEN_Or,					 9, "Or",				"|",		OPTYPE_Or		},	// |
	{ TOKEN_Xor,				10, "Xor",				"^",		OPTYPE_Xor		},	// ^
	{ TOKEN_And,				11, "And",				"&",		OPTYPE_And		},	// &
	{ TOKEN_Shl,				12, "Shl",				"<<",		OPTYPE_Shl		},	// <<
	{ TOKEN_Shr,				12, "Shr",				">>",		OPTYPE_Shr		},
	{ TOKEN_Add,				13, "Add",				"+",		OPTYPE_Add		},	// +
	{ TOKEN_Sub,				13, "Sub",				"-",		OPTYPE_Sub		},
	{ TOKEN_Mul,				14, "Mul",				"*",		OPTYPE_Mul		},	// *
	{ TOKEN_Div,				14, "Div",				"/",		OPTYPE_Div		},
	{ TOKEN_Mod,				14, "Mod",				"%",		OPTYPE_Mod		},
	{ TOKEN_ModMod,				14, "ModMod",			"%%",		OPTYPE_None		},
	{ TOKEN_Question,			14, "Question",			"?",		OPTYPE_None		},
	{ TOKEN_Inv,				15, "Inv",				"~",		OPTYPE_Inv		},	// ~
	{ TOKEN_Pow,				16, "Pow",				"**",		OPTYPE_Pow		},	// **
	{ TOKEN_Quote,				17, "Quote",			"`",		OPTYPE_None		},	// `
	{ TOKEN_Colon,				18, "Colon",			":",		OPTYPE_None		},	// :
	{ TOKEN_ColonAfterSuffix,	19, "ColonAfterSuffix",	":",		OPTYPE_None		},	// *:
	{ TOKEN_Dot,				20, "Dot",				".",		OPTYPE_None		},	// .
	{ TOKEN_ColonColon,			20, "ColonColon",		"::",		OPTYPE_None		},
	{ TOKEN_ColonAsterisk,		20, "ColonAsterisk",	":*",		OPTYPE_None		},
	{ TOKEN_ColonAnd,			20, "ColonAnd",			":&",		OPTYPE_None		},
	{ TOKEN_LParenthesis,		21, "LParenthesis",		"(",		OPTYPE_None		},	// (
	{ TOKEN_RParenthesis,		22, "RParenthesis",		")",		OPTYPE_None		},	// )
	{ TOKEN_LBrace,				21, "LBrace",			"{",		OPTYPE_None		},
	{ TOKEN_RBrace,				22, "RBrace",			"}",		OPTYPE_None		},
	{ TOKEN_LBlockParam,		21, "LBlockParam",		"|",		OPTYPE_None		},
	{ TOKEN_RBlockParam,		22, "RBlockParam",		"|",		OPTYPE_None		},
	{ TOKEN_LBracket,			23, "LBracket",			"[",		OPTYPE_None		},	// [
	{ TOKEN_RBracket,			24, "RBracket",			"]",		OPTYPE_None		},	// ]
	{ TOKEN_Comma,				25, "Comma",			",",		OPTYPE_None		},	// ,
	{ TOKEN_Semicolon,			25, "Semicolon",		";",		OPTYPE_None		},
	{ TOKEN_EOL,				26, "EOL",				"[EOL]",	OPTYPE_None		},	// \n
	{ TOKEN_Number,				27, "Number",			"[Num]",	OPTYPE_None		},	// V
	{ TOKEN_NumberSuffixed,		27, "NumberSuffixed",	"[NmS]",	OPTYPE_None		},
	{ TOKEN_String,				27, "String",			"[Str]",	OPTYPE_None		},
	{ TOKEN_StringSuffixed,		27, "StringSuffixed",	"[StS]",	OPTYPE_None		},
	{ TOKEN_Binary,				27, "Binary",			"[Bin]",	OPTYPE_None		},
	{ TOKEN_EmbedString,		27, "EmbedString",		"[EmS]",	OPTYPE_None		},
	{ TOKEN_Symbol,				28, "Symbol",			"[Sym]",	OPTYPE_None		},	// S
	{ TOKEN_EOF,				29, "EOF",				"[EOF]",	OPTYPE_None		},	// E
	{ TOKEN_Expr,				 0, "Expr",				"[Exp]",	OPTYPE_None		},
	{ TOKEN_White,				 0, "White",			"[Wht]",	OPTYPE_None		},
	{ TOKEN_CommentLine,		 0, "CommentLine",		"[CmL]",	OPTYPE_None		},
	{ TOKEN_CommentBlock,		 0, "CommentBlock",		"[CmB]",	OPTYPE_None		},
	{ TOKEN_DoubleChars,		 0, "DoubleChars",		"[DbC]",	OPTYPE_None		},
	{ TOKEN_TripleChars,		 0, "TripleChars",		"[TrC]",	OPTYPE_None		},
	{ TOKEN_Unknown,			 0, "Unknown",			"[unk]",	OPTYPE_None		},
};

Token::~Token()
{
}

void Token::Initialize()
{
	_pTokenTypeToTokenInfoMap = new TokenTypeToTokenInfoMap();
	_pOpTypeToTokenInfoMap = new OpTypeToTokenInfoMap();
	for (size_t i = 0; i < ArraySizeOf(_tokenInfoTbl); i++) {
		const TokenInfo *pTokenInfo = &_tokenInfoTbl[i];
		(*_pTokenTypeToTokenInfoMap)[pTokenInfo->tokenType] = pTokenInfo;
		if (pTokenInfo->opType != OPTYPE_None) {
			(*_pOpTypeToTokenInfoMap)[pTokenInfo->opType] = pTokenInfo;
		}
	}
}

int Token::CompareOpTypePrec(OpType opTypeLeft, OpType opTypeRight)
{
	const TokenInfo *pTokenInfoLeft = LookupTokenInfoByOpType(opTypeLeft);
	const TokenInfo *pTokenInfoRight = LookupTokenInfoByOpType(opTypeRight);
	if (pTokenInfoLeft == nullptr || pTokenInfoRight == nullptr) return 0;
	return pTokenInfoLeft->category - pTokenInfoRight->category;
}

Token::Precedence Token::_LookupPrec(int categoryLeft, int categoryRight)
{
	const Precedence LT = PREC_LT, EQ = PREC_EQ, GT = PREC_GT, xx = PREC_Error;
	const static Precedence precTbl[][30] = {
		/*         e   B   =  ||  &&   !  in   <  ..   |   ^   &  <<   +   *   ~  **   `   :  *:   .   (   )   [   ]   ,  \n   V   S   E */
		/* e */ { xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx },
		/* B */ { xx, xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, xx, LT, xx, EQ, EQ, LT, LT, EQ },
		/* = */ { xx, xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ||*/ { xx, xx, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* &&*/ { xx, xx, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ! */ { xx, xx, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* in*/ { xx, xx, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* < */ { xx, xx, LT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ..*/ { xx, xx, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* | */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ^ */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* & */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* <<*/ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* + */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, GT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* * */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, GT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ~ */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ***/ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ` */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* : */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, GT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* *:*/ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, GT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* . */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, GT },
		/* ( */ { xx, xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, EQ, LT, EQ, EQ, EQ, LT, LT, xx },
		/* ) */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT },
		/* [ */ { xx, xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, EQ, LT, EQ, EQ, EQ, LT, LT, xx },
		/* ] */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT },
		/* , */ { xx, xx, LT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, xx, GT, GT, GT, GT },
		/* \n*/ { xx, xx, LT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT },
		/* V */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, xx, GT },
		/* S */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, xx, xx, GT },
	};                                  
	return precTbl[categoryLeft][categoryRight];
}

//-----------------------------------------------------------------------------
// TokenStack
//-----------------------------------------------------------------------------
TokenStack::~TokenStack()
{
}

TokenStack::reverse_iterator TokenStack::SeekTerminal(reverse_iterator p)
{
	for ( ; p->IsType(TOKEN_Expr); p++) ;
	return p;
}

void TokenStack::Clear()
{
	foreach (TokenStack, pToken, *this) {
		Expr::Delete(pToken->GetExpr());
	}
	clear();
}

bool TokenStack::CheckBlockParamEnd() const
{
	int parLevel = 0;
	foreach_const_reverse (TokenStack, pToken, *this) {
		const Token &token = *pToken;
		if (token.IsType(TOKEN_LBlockParam)) break;
		if (token.IsCloseToken()) parLevel++;
		if (token.IsOpenToken()) {
			parLevel--;
			if (parLevel < 0) return false;
		}
	}
	return true;
}

String TokenStack::ToString() const
{
	String rtn;
	foreach_const (TokenStack, pToken, *this) {
		if (pToken != begin()) rtn.append(" ");
		rtn.append(pToken->GetSymbol());
	}
	return rtn;
}

}
