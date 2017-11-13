//=============================================================================
// Token
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const Token::Precedence
	LT = Token::PREC_LT,
	EQ = Token::PREC_EQ,
	GT = Token::PREC_GT,
	xx = Token::PREC_Error;

//-----------------------------------------------------------------------------
// Token
//-----------------------------------------------------------------------------
OpTypeToTokenInfoMap *Token::_pOpTypeToTokenInfoMap = nullptr;

const TokenInfo TOKEN_Begin =			{  1, "Begin",			"[Bgn]",OPTYPE_None	};		// B
const TokenInfo TOKEN_Assign =			{  2, "Assign",			"=",	OPTYPE_None	};		// =
const TokenInfo &TOKEN_SourceSymbolMin = TOKEN_Assign;
const TokenInfo TOKEN_AssignAdd =		{  2, "AssignAdd",		"+=",	OPTYPE_None	};
const TokenInfo TOKEN_AssignSub =		{  2, "AssignSub",		"-=",	OPTYPE_None	};
const TokenInfo TOKEN_AssignMul =		{  2, "AssignMul",		"*=",	OPTYPE_None	};
const TokenInfo TOKEN_AssignDiv =		{  2, "AssignDiv",		"/=",	OPTYPE_None	};
const TokenInfo TOKEN_AssignMod =		{  2, "AssignMod",		"%=",	OPTYPE_None	};
const TokenInfo TOKEN_AssignPow =		{  2, "AssignPow",		"**=",	OPTYPE_None	};
const TokenInfo TOKEN_AssignOr =		{  2, "AssignOr",		"|=",	OPTYPE_None	};
const TokenInfo TOKEN_AssignAnd =		{  2, "AssignAnd",		"&=",	OPTYPE_None	};
const TokenInfo TOKEN_AssignXor =		{  2, "AssignXor",		"^=",	OPTYPE_None	};
const TokenInfo TOKEN_AssignShl =		{  2, "AssignShl",		"<<=",	OPTYPE_None	};
const TokenInfo TOKEN_AssignShr =		{  2, "AssignShr",		">>=",	OPTYPE_None	};
const TokenInfo TOKEN_Pair =			{  2, "Pair",			"=>",	OPTYPE_Pair	};
const TokenInfo TOKEN_OrOr =			{  4, "OrOr",			"||",	OPTYPE_OrOr	};		// ||
const TokenInfo TOKEN_AndAnd =			{  5, "AndAnd",			"&&",	OPTYPE_AndAnd };	// &&
const TokenInfo TOKEN_Not =				{  6, "Not",			"!",	OPTYPE_Not	};		// !
const TokenInfo TOKEN_Contains =		{  7, "Contains",		"in",	OPTYPE_Contains };	// in
const TokenInfo TOKEN_Lt =				{  8, "Lt",				"<",	OPTYPE_Lt	};		// <
const TokenInfo TOKEN_Gt =				{  8, "Gt",				">",	OPTYPE_Gt	};
const TokenInfo TOKEN_Le =				{  8, "Le",				"<=",	OPTYPE_Le	};
const TokenInfo TOKEN_Ge =				{  8, "Ge",				">=",	OPTYPE_Ge	};
const TokenInfo TOKEN_Cmp =				{  8, "Cmp",			"<=>",	OPTYPE_Cmp	};
const TokenInfo TOKEN_Eq =				{  8, "Eq",				"==",	OPTYPE_Eq	};
const TokenInfo TOKEN_Ne =				{  8, "Ne",				"!=",	OPTYPE_Ne	};
const TokenInfo TOKEN_Seq =				{  9, "Seq",			"..",	OPTYPE_Seq	};		// ..
const TokenInfo TOKEN_Or =				{ 10, "Or",				"|",	OPTYPE_Or	};		// |
const TokenInfo TOKEN_Xor =				{ 11, "Xor",			"^",	OPTYPE_Xor	};		// ^
const TokenInfo TOKEN_And =				{ 12, "And",			"&",	OPTYPE_And	};		// &
const TokenInfo TOKEN_Shl =				{ 13, "Shl",			"<<",	OPTYPE_Shl	};		// <<
const TokenInfo TOKEN_Shr =				{ 13, "Shr",			">>",	OPTYPE_Shr	};
const TokenInfo TOKEN_Add =				{ 14, "Add",			"+",	OPTYPE_Add	};		// +
const TokenInfo TOKEN_Sub =				{ 14, "Sub",			"-",	OPTYPE_Sub	};
const TokenInfo TOKEN_Mul =				{ 15, "Mul",			"*",	OPTYPE_Mul	};		// *
const TokenInfo TOKEN_Div =				{ 15, "Div",			"/",	OPTYPE_Div	};
const TokenInfo TOKEN_Mod =				{ 15, "Mod",			"%",	OPTYPE_Mod	};
const TokenInfo TOKEN_ModMod =			{ 15, "ModMod",			"%%",	OPTYPE_ModMod };
const TokenInfo TOKEN_Dot =				{ 15, "Dot",			"|.|",	OPTYPE_Dot	};
const TokenInfo TOKEN_Cross =			{ 15, "Cross",			"|^|",	OPTYPE_Cross };
const TokenInfo TOKEN_Gear =			{ 15, "Gear",			"|*|",	OPTYPE_Gear };
const TokenInfo TOKEN_Concat =			{  3, "Concat",			"|+|",	OPTYPE_Concat };
const TokenInfo TOKEN_Difference =		{  3, "Difference",		"|-|",	OPTYPE_Difference };
const TokenInfo TOKEN_Intersection =	{  3, "Intersection",	"|&|",	OPTYPE_Intersection };
const TokenInfo TOKEN_Union =			{  3, "Union",			"|||",	OPTYPE_Union };
const TokenInfo TOKEN_Question =		{ 15, "Question",		"?",	OPTYPE_None	};
const TokenInfo TOKEN_Inv =				{ 16, "Inv",			"~",	OPTYPE_Inv	};		// ~
const TokenInfo TOKEN_Pow =				{ 17, "Pow",			"**",	OPTYPE_Pow	};		// **
const TokenInfo TOKEN_Quote =			{ 18, "Quote",			"`",	OPTYPE_None	};		// `
const TokenInfo TOKEN_Colon =			{ 19, "Colon",			":",	OPTYPE_None	};		// :
const TokenInfo TOKEN_ColonAfterSuffix ={ 20, "ColonAfterSuffix",":",	OPTYPE_None	};		// *:
const TokenInfo TOKEN_Period =			{ 21, "Period",			".",	OPTYPE_None	};		// .
const TokenInfo TOKEN_ColonColon =		{ 21, "ColonColon",		"::",	OPTYPE_None	};
const TokenInfo TOKEN_ColonAsterisk =	{ 21, "ColonAsterisk",	":*",	OPTYPE_None	};
const TokenInfo TOKEN_ColonAnd =		{ 21, "ColonAnd",		":&",	OPTYPE_None	};
const TokenInfo TOKEN_LParenthesis =	{ 22, "LParenthesis",	"(",	OPTYPE_None	};		// (
const TokenInfo TOKEN_RParenthesis =	{ 23, "RParenthesis",	")",	OPTYPE_None	};		// )
const TokenInfo TOKEN_LBrace =			{ 22, "LBrace",			"{",	OPTYPE_None	};
const TokenInfo TOKEN_RBrace =			{ 23, "RBrace",			"}",	OPTYPE_None	};
const TokenInfo TOKEN_LBlockParam =		{ 22, "LBlockParam",	"|",	OPTYPE_None	};
const TokenInfo TOKEN_RBlockParam =		{ 23, "RBlockParam",	"|",	OPTYPE_None	};
const TokenInfo TOKEN_LBracket =		{ 24, "LBracket",		"[",	OPTYPE_None	};		// [
const TokenInfo TOKEN_RBracket =		{ 25, "RBracket",		"]",	OPTYPE_None	};		// ]
const TokenInfo TOKEN_Comma =			{ 26, "Comma",			",",	OPTYPE_None	};		// ,
const TokenInfo TOKEN_Semicolon =		{ 26, "Semicolon",		";",	OPTYPE_None	};
const TokenInfo &TOKEN_SourceSymbolMax = TOKEN_Semicolon;
const TokenInfo TOKEN_EOL =				{ 27, "EOL",			"[EOL]",OPTYPE_None	};		// \n
const TokenInfo TOKEN_Number =			{ 28, "Number",			"[Num]",OPTYPE_None	};		// V
const TokenInfo TOKEN_NumberSuffixed =	{ 28, "NumberSuffixed",	"[NmS]",OPTYPE_None	};
const TokenInfo TOKEN_String =			{ 28, "String",			"[Str]",OPTYPE_None	};
const TokenInfo TOKEN_StringSuffixed =	{ 28, "StringSuffixed",	"[StS]",OPTYPE_None	};
const TokenInfo TOKEN_Binary =			{ 28, "Binary",			"[Bin]",OPTYPE_None	};
const TokenInfo TOKEN_EmbedString =		{ 28, "EmbedString",	"[EmS]",OPTYPE_None	};
const TokenInfo TOKEN_Symbol =			{ 29, "Symbol",			"[Sym]",OPTYPE_None	};		// S
const TokenInfo TOKEN_EOF =				{ 30, "EOF",			"[EOF]",OPTYPE_None	};		// E
const TokenInfo TOKEN_Expr =			{  0, "Expr",			"[Exp]",OPTYPE_None	};
const TokenInfo TOKEN_Space =			{  0, "Space",			"[Spc]",OPTYPE_None	};
const TokenInfo TOKEN_Escape =			{  0, "Escape",			"[Esc]",OPTYPE_None	};
const TokenInfo TOKEN_CommentLine =		{  0, "CommentLine",	"[CmL]",OPTYPE_None	};
const TokenInfo TOKEN_CommentBlock =	{  0, "CommentBlock",	"[CmB]",OPTYPE_None	};
const TokenInfo TOKEN_DoubleChars =		{  0, "DoubleChars",	"[DbC]",OPTYPE_None	};
const TokenInfo TOKEN_TripleChars =		{  0, "TripleChars",	"[TrC]",OPTYPE_None	};
const TokenInfo TOKEN_Unknown =			{  0, "Unknown",		"[unk]",OPTYPE_None	};

const Token::Precedence Token::_precMatrix[][31] = {
	/*         e   B   =  |+| ||  &&   !  in   <  ..   |   ^   &  <<   +   *   ~  **   `   :  *:   .   (   )   [   ]   ,  \n   V   S   E */
	/* e */ { xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx },
	/* B */ { xx, xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, xx, LT, xx, EQ, EQ, LT, LT, EQ },
	/* = */ { xx, xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* |+|*/{ xx, xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* ||*/ { xx, xx, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* &&*/ { xx, xx, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* ! */ { xx, xx, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* in*/ { xx, xx, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* < */ { xx, xx, LT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* ..*/ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* | */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* ^ */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* & */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* <<*/ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* + */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, GT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* * */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, GT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* ~ */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* ***/ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* ` */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* : */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, GT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* *:*/ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, GT, GT, LT, GT, GT, GT, LT, LT, GT },
	/* . */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, GT },
	/* ( */ { xx, xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, EQ, LT, EQ, EQ, EQ, LT, LT, xx },
	/* ) */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT },
	/* [ */ { xx, xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, EQ, LT, EQ, EQ, EQ, LT, LT, xx },
	/* ] */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT },
	/* , */ { xx, xx, LT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, xx, GT, GT, GT, GT },
	/* \n*/ { xx, xx, LT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT },
	/* V */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, xx, GT },
	/* S */ { xx, xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, xx, xx, GT },
};

Token::~Token()
{
}

void Token::Bootup()
{
	static const TokenInfo *const tokenInfoTbl[] = {
		&TOKEN_Begin,
		&TOKEN_Assign,
		&TOKEN_AssignAdd,
		&TOKEN_AssignSub,
		&TOKEN_AssignMul,
		&TOKEN_AssignDiv,
		&TOKEN_AssignMod,
		&TOKEN_AssignPow,
		&TOKEN_AssignOr,
		&TOKEN_AssignAnd,
		&TOKEN_AssignXor,
		&TOKEN_AssignShl,
		&TOKEN_AssignShr,
		&TOKEN_Pair,
		&TOKEN_OrOr,
		&TOKEN_AndAnd,
		&TOKEN_Not,
		&TOKEN_Contains,
		&TOKEN_Lt,
		&TOKEN_Gt,
		&TOKEN_Le,
		&TOKEN_Ge,
		&TOKEN_Cmp,
		&TOKEN_Eq,
		&TOKEN_Ne,
		&TOKEN_Seq,
		&TOKEN_Or,
		&TOKEN_Xor,
		&TOKEN_And,
		&TOKEN_Shl,
		&TOKEN_Shr,
		&TOKEN_Add,
		&TOKEN_Sub,
		&TOKEN_Mul,
		&TOKEN_Div,
		&TOKEN_Mod,
		&TOKEN_ModMod,
		&TOKEN_Dot,
		&TOKEN_Cross,
		&TOKEN_Gear,
		&TOKEN_Concat,
		&TOKEN_Difference,
		&TOKEN_Intersection,
		&TOKEN_Union,
		&TOKEN_Question,
		&TOKEN_Inv,
		&TOKEN_Pow,
		&TOKEN_Quote,
		&TOKEN_Colon,
		&TOKEN_ColonAfterSuffix,
		&TOKEN_Period,
		&TOKEN_ColonColon,
		&TOKEN_ColonAsterisk,
		&TOKEN_ColonAnd,
		&TOKEN_LParenthesis,	// open token
		&TOKEN_RParenthesis,	// close token
		&TOKEN_LBrace,			// open token
		&TOKEN_RBrace,			// close token
		&TOKEN_LBracket,		// open token
		&TOKEN_RBracket,		// close token
		&TOKEN_LBlockParam,		// open token
		&TOKEN_RBlockParam,		// close token
		&TOKEN_Comma,
		&TOKEN_Semicolon,
		&TOKEN_EOL,
		&TOKEN_Number,
		&TOKEN_NumberSuffixed,
		&TOKEN_String,
		&TOKEN_StringSuffixed,
		&TOKEN_Binary,
		&TOKEN_EmbedString,
		&TOKEN_Symbol,
		&TOKEN_EOF,
		&TOKEN_Expr,
		&TOKEN_Space,			// for watcher
		&TOKEN_Escape,			// for watcher
		&TOKEN_CommentLine,		// for watcher
		&TOKEN_CommentBlock,	// for watcher
		&TOKEN_DoubleChars,		// only used in tokenizing process
		&TOKEN_TripleChars,		// only used in tokenizing process
		&TOKEN_Unknown,
	};
	_pOpTypeToTokenInfoMap = new OpTypeToTokenInfoMap();
	for (size_t i = 0; i < ArraySizeOf(tokenInfoTbl); i++) {
		const TokenInfo *pTokenInfo = tokenInfoTbl[i];
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

const char *Token::GetSource() const
{
	int category = GetCategory();
	if (TOKEN_SourceSymbolMin.category <= category && category <= TOKEN_SourceSymbolMax.category) {
		return GetSymbol();
	} else if (IsType(TOKEN_EOL)) {
		return "\n";
	} else if (_strSource.empty()) {
		return _str.c_str();
	} else {
		return _strSource.c_str();
	}
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
