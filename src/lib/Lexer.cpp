//=============================================================================
// Lexer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Lexer
//-----------------------------------------------------------------------------
const Lexer::ElemTypeInfo Lexer::_elemTypeInfoTbl[] = {
	{ ETYPE_Begin,				 1, "Begin",			"[Bgn]",	OPTYPE_None		},	// B
	{ ETYPE_Assign,				 2, "Assign",			"=",		OPTYPE_None		},	// =
	{ ETYPE_AssignAdd,			 2, "AssignAdd",		"+=",		OPTYPE_None		},
	{ ETYPE_AssignSub,			 2, "AssignSub",		"-=",		OPTYPE_None		},
	{ ETYPE_AssignMul,			 2, "AssignMul",		"*=",		OPTYPE_None		},
	{ ETYPE_AssignDiv,			 2, "AssignDiv",		"/=",		OPTYPE_None		},
	{ ETYPE_AssignMod,			 2, "AssignMod",		"%=",		OPTYPE_None		},
	{ ETYPE_AssignPow,			 2, "AssignPow",		"**=",		OPTYPE_None		},
	{ ETYPE_AssignOr,			 2, "AssignOr",			"|=",		OPTYPE_None		},
	{ ETYPE_AssignAnd,			 2, "AssignAnd",		"&=",		OPTYPE_None		},
	{ ETYPE_AssignXor,			 2, "AssignXor",		"^=",		OPTYPE_None		},
	{ ETYPE_AssignShl,			 2, "AssignShl",		"<<=",		OPTYPE_None		},
	{ ETYPE_AssignShr,			 2, "AssignShr",		">>=",		OPTYPE_None		},
	{ ETYPE_Pair,				 2, "Pair",				"=>",		OPTYPE_Pair		},
	{ ETYPE_OrOr,				 3, "OrOr",				"||",		OPTYPE_OrOr		},	// ||
	{ ETYPE_AndAnd,				 4, "AndAnd",			"&&",		OPTYPE_AndAnd	},	// &&
	{ ETYPE_Not,				 5, "Not",				"!",		OPTYPE_Not		},	// !
	{ ETYPE_Contains,			 6, "Contains",			"in",		OPTYPE_Contains	},	// in
	{ ETYPE_Lt,					 7, "Lt",				"<",		OPTYPE_Lt		},	// <
	{ ETYPE_Gt,					 7, "Gt",				">",		OPTYPE_Gt		},
	{ ETYPE_Le,	 				 7, "Le",				"<=",		OPTYPE_Le		},
	{ ETYPE_Ge,					 7, "Ge",				">=",		OPTYPE_Ge		},
	{ ETYPE_Cmp,				 7, "Cmp",				"<=>",		OPTYPE_Cmp		},
	{ ETYPE_Eq,					 7, "Eq",				"==",		OPTYPE_Eq		},
	{ ETYPE_Ne,					 7, "Ne",				"!=",		OPTYPE_Ne		},
	{ ETYPE_Seq,			 	 8, "Seq",				"..",		OPTYPE_Seq		},	// ..
	{ ETYPE_Or,					 9, "Or",				"|",		OPTYPE_Or		},	// |
	{ ETYPE_Xor,				10, "Xor",				"^",		OPTYPE_Xor		},	// ^
	{ ETYPE_And,				11, "And",				"&",		OPTYPE_And		},	// &
	{ ETYPE_Shl,				12, "Shl",				"<<",		OPTYPE_Shl		},	// <<
	{ ETYPE_Shr,				12, "Shr",				">>",		OPTYPE_Shr		},
	{ ETYPE_Add,				13, "Add",				"+",		OPTYPE_Add		},	// +
	{ ETYPE_Sub,				13, "Sub",				"-",		OPTYPE_Sub		},
	{ ETYPE_Mul,				14, "Mul",				"*",		OPTYPE_Mul		},	// *
	{ ETYPE_Div,				14, "Div",				"/",		OPTYPE_Div		},
	{ ETYPE_Mod,				14, "Mod",				"%",		OPTYPE_Mod		},
	{ ETYPE_ModMod,				14, "ModMod",			"%%",		OPTYPE_None		},
	{ ETYPE_Question,			14, "Question",			"?",		OPTYPE_None		},
	{ ETYPE_Inv,				15, "Inv",				"~",		OPTYPE_Inv		},	// ~
	{ ETYPE_Pow,				16, "Pow",				"**",		OPTYPE_Pow		},	// **
	{ ETYPE_Quote,				17, "Quote",			"`",		OPTYPE_None		},	// `
	{ ETYPE_Colon,				18, "Colon",			":",		OPTYPE_None		},	// :
	{ ETYPE_ColonAfterSuffix,	19, "ColonAfterSuffix",	":",		OPTYPE_None		},	// *:
	{ ETYPE_Dot,				20, "Dot",				".",		OPTYPE_None		},	// .
	{ ETYPE_ColonColon,			20, "ColonColon",		"::",		OPTYPE_None		},
	{ ETYPE_ColonAsterisk,		20, "ColonAsterisk",	":*",		OPTYPE_None		},
	{ ETYPE_ColonAnd,			20, "ColonAnd",			":&",		OPTYPE_None		},
	{ ETYPE_LParenthesis,		21, "LParenthesis",		"(",		OPTYPE_None		},	// (
	{ ETYPE_RParenthesis,		22, "RParenthesis",		")",		OPTYPE_None		},	// )
	{ ETYPE_LBrace,				21, "LBrace",			"{",		OPTYPE_None		},
	{ ETYPE_RBrace,				22, "RBrace",			"}",		OPTYPE_None		},
	{ ETYPE_LBlockParam,		21, "LBlockParam",		"|",		OPTYPE_None		},
	{ ETYPE_RBlockParam,		22, "RBlockParam",		"|",		OPTYPE_None		},
	{ ETYPE_LBracket,			23, "LBracket",			"[",		OPTYPE_None		},	// [
	{ ETYPE_RBracket,			24, "RBracket",			"]",		OPTYPE_None		},	// ]
	{ ETYPE_Comma,				25, "Comma",			",",		OPTYPE_None		},	// ,
	{ ETYPE_Semicolon,			25, "Semicolon",		";",		OPTYPE_None		},
	{ ETYPE_EOL,				26, "EOL",				"[EOL]",	OPTYPE_None		},	// \n
	{ ETYPE_Number,				27, "Number",			"[Num]",	OPTYPE_None		},	// V
	{ ETYPE_NumberSuffixed,		27, "NumberSuffixed",	"[NmS]",	OPTYPE_None		},
	{ ETYPE_String,				27, "String",			"[Str]",	OPTYPE_None		},
	{ ETYPE_StringSuffixed,		27, "StringSuffixed",	"[StS]",	OPTYPE_None		},
	{ ETYPE_Binary,				27, "Binary",			"[Bin]",	OPTYPE_None		},
	{ ETYPE_EmbedString,		27, "EmbedString",		"[EmS]",	OPTYPE_None		},
	{ ETYPE_Symbol,				28, "Symbol",			"[Sym]",	OPTYPE_None		},	// S
	{ ETYPE_EOF,				29, "EOF",				"[EOF]",	OPTYPE_None		},	// E
	{ ETYPE_Expr,				-1, "Expr",				"[Exp]",	OPTYPE_None		},
	{ ETYPE_Unknown,			-1, "Unknown",			"[unk]",	OPTYPE_None		},
};

Lexer::Lexer(int cntLineStart) :
	_stat(STAT_BOF), _lineHeadFlag(true),
	_appearShebangFlag(false), _blockParamFlag(false),
	_cntLine(cntLineStart), _cntCol(0), _commentNestLevel(0)
{
}

Lexer::ElemType Lexer::ElemTypeForString(const StringInfo &stringInfo)
{
	return stringInfo.binaryFlag? ETYPE_Binary :
		stringInfo.embedFlag? ETYPE_EmbedString : ETYPE_String;
}

bool Lexer::CheckStringPrefix(StringInfo &stringInfo, const String &token)
{
	stringInfo.rawFlag = false;
	stringInfo.binaryFlag = false;
	stringInfo.wiseFlag = false;
	stringInfo.embedFlag = false;
	foreach_const (String, p, token) {
		char ch = *p;
		if (ch == 'r') {
			if (stringInfo.rawFlag) return false;
			stringInfo.rawFlag = true;
		} else if (ch == 'R') {
			if (stringInfo.rawFlag) return false;
			stringInfo.rawFlag = true;
			stringInfo.wiseFlag = true;
		} else if (ch == 'b') {
			if (stringInfo.binaryFlag) return false;
			stringInfo.binaryFlag = true;
		} else if (ch == 'B') {
			if (stringInfo.binaryFlag) return false;
			stringInfo.binaryFlag = true;
			stringInfo.wiseFlag = true;
		} else if (ch == 'e') {
			if (stringInfo.embedFlag) return false;
			stringInfo.embedFlag = true;
		} else {
			return false;
		}
	}
	return true;
}

void Lexer::InitStack()
{
}

void Lexer::SetError(ErrorType errType, const char *format, ...)
{
}

bool Lexer::CheckBlockParamEnd() const
{
	int parLevel = 0;
	foreach_const_reverse (ElementStack, pElem, _elemStack) {
		const Element &elem = *pElem;
		if (elem.IsType(ETYPE_LBlockParam)) break;
		if (elem.IsCloseElement()) parLevel++;
		if (elem.IsOpenElement()) {
			parLevel--;
			if (parLevel < 0) return false;
		}
	}
	return true;
}

bool Lexer::FeedElement(Environment &env, const Element &elem)
{
	return true;
}

const Lexer::ElemTypeInfo *Lexer::LookupElemTypeInfo(ElemType elemType)
{
	for (const ElemTypeInfo *p = _elemTypeInfoTbl;
										p->elemType != ETYPE_Unknown; p++) {
		if (p->elemType == elemType) return p;
	}
	return nullptr;
}

bool Lexer::ParseChar(Environment &env, char ch)
{
	Signal &sig = env.GetSignal();
	if (ch == '\r') return true;
	if (_lineHeadFlag) {
		if (IsWhite(ch)) {
			_strIndent.push_back(ch);
		} else {
			_lineHeadFlag = false;
		}
	}
	Gura_BeginPushbackRegion();
	switch (_stat) {
	case STAT_BOF: {
		if (ch == '\xef') {
			_token.clear();
			_token.push_back(ch);
			_stat = STAT_BOF_2nd;
		} else {
			Gura_Pushback();
			_stat = STAT_Start;
		}
		break;
	}
	case STAT_BOF_2nd: {
		if (ch == '\xbb') {
			_token.push_back(ch);
			_stat = STAT_BOF_3rd;
		} else {
			Gura_Pushback();
			_stat = STAT_Symbol;
		}
		break;
	}
	case STAT_BOF_3rd: {
		if (ch == '\xbf') {
			_stat = STAT_Start;
		} else {
			Gura_Pushback();
			_stat = STAT_Symbol;
		}
		break;
	}
	case STAT_Start: {
		if (ch == '0') {
			_token.clear();
			_token.push_back(ch);
			_stat = STAT_NumberPre;
		} else if (IsDigit(ch)) {
			_token.clear();
			_token.push_back(ch);
			_stat = STAT_Number;
		} else if (ch == '.') {
			_token.clear();
			_token.push_back(ch);
			_stat = STAT_NumberAfterDot;
		} else if (IsWhite(ch)) {
			// nothing to do
		} else if (ch == '\x0c') { // page-break
			// nothing to do
		} else if (IsSymbolFirstChar(ch)) {
			_token.clear();
			_token.push_back(ch);
			_stat = STAT_Symbol;
		} else if (ch == '"' || ch == '\'') {
			_stringInfo.chBorder = ch;
			_stringInfo.rawFlag = false;
			_stringInfo.binaryFlag = false;
			_stringInfo.wiseFlag = false;
			_stringInfo.embedFlag = false;
			_token.clear();
			_stat = STAT_StringFirst;
		} else if (ch == '\\') {
			_stat = STAT_Escape;
		} else if (ch == '\n') {
			FeedElement(env, Element(ETYPE_EOL, GetLineNo()));
			if (sig.IsSignalled()) _stat = STAT_Error;
		} else if (ch == '#') {
			FeedElement(env, Element(ETYPE_EOL, GetLineNo()));
			if (sig.IsSignalled()) {
				_stat = STAT_Error;
			} else if (_cntLine == 0) {
				_stat = STAT_CommentLineTop;
			} else if (_cntLine == 1 && _appearShebangFlag) {
				_stat = STAT_MagicCommentLine;
			} else {
				_stat = STAT_CommentLine;
			}
		} else if (ch == '{') {
			FeedElement(env, Element(ETYPE_LBrace, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_AfterLBrace;
		} else if (ch == '(') {
			FeedElement(env, Element(ETYPE_LParenthesis, GetLineNo()));
			if (sig.IsSignalled()) _stat = STAT_Error;
		} else if (ch == '[') {
			FeedElement(env, Element(ETYPE_LBracket, GetLineNo()));
			if (sig.IsSignalled()) _stat = STAT_Error;
		} else if (ch == '|' && _blockParamFlag && CheckBlockParamEnd()) {
			_blockParamFlag = false;
			FeedElement(env, Element(ETYPE_RBlockParam, GetLineNo()));
			if (sig.IsSignalled()) _stat = STAT_Error;
		} else if (ch == '`') {
			FeedElement(env, Element(ETYPE_Quote, GetLineNo()));
			_stat = STAT_Start;
		} else if (ch == ':') {
			_stat = STAT_Colon;
		} else {
			size_t i = 0;
			static const struct {
				int ch;
				ElemType elemType;
			} tbl[] = {
				{ '?',	ETYPE_Question,		},
				{ '+',	ETYPE_DoubleChars,	},
				{ '-',	ETYPE_DoubleChars,	},
				{ '*',	ETYPE_DoubleChars,	},
				{ '/',	ETYPE_DoubleChars,	},
				{ '%',	ETYPE_DoubleChars,	},
				{ '=',	ETYPE_DoubleChars,	},
				{ '<',	ETYPE_DoubleChars,	},
				{ '>',	ETYPE_DoubleChars,	},
				{ '!',	ETYPE_DoubleChars,	}, // see also STAT_Symbol
				{ '|',	ETYPE_DoubleChars,	},
				{ '&',	ETYPE_DoubleChars,	},
				{ '^',	ETYPE_DoubleChars,	},
				{ '~',	ETYPE_Inv,			},
				{ ',',	ETYPE_Comma,		},
				{ ';',	ETYPE_Semicolon,	},
				{ ')',	ETYPE_RParenthesis,	},
				{ '}',	ETYPE_RBrace,		},
				{ ']',	ETYPE_RBracket,		},
				{ '\0',	ETYPE_EOF,			},
			};
			for (i = 0; i < ArraySizeOf(tbl); i++) {
				if (tbl[i].ch == ch) break;
			}
			if (i >= ArraySizeOf(tbl)) {
				SetError(ERR_SyntaxError, "unexpected character '%c' (%d)", ch, ch);
				_stat = STAT_Error;
			} else if (tbl[i].elemType == ETYPE_DoubleChars) {
				_token.clear();
				_token.push_back(ch);
				_stat = STAT_DoubleChars;
			} else if (_elemStack.back().IsType(ETYPE_Quote)) {
				_token.clear();
				_token.push_back(ch);
				FeedElement(env, Element(ETYPE_Symbol, GetLineNo(), _token));
				if (sig.IsSignalled()) _stat = STAT_Error;
			} else {
				FeedElement(env, Element(tbl[i].elemType, GetLineNo()));
				if (sig.IsSignalled()) _stat = STAT_Error;
			}
		}
		break;
	}
	case STAT_DoubleChars: {
		// this state comes from STAT_Start and STAT_Symbol
		static const struct {
			int chFirst;
			ElemType elemType;
			struct {
				int chSecond;
				ElemType elemType;
			} tblCand[5];
		} tbl[] = {
			{ '+', ETYPE_Add, {
				{ '=', ETYPE_AssignAdd		},
				{ '\0', ETYPE_Unknown		}, } },
			{ '-', ETYPE_Sub, {
				{ '=', ETYPE_AssignSub		},
				{ '\0', ETYPE_Unknown		}, } },
			{ '*', ETYPE_Mul, {
				{ '=', ETYPE_AssignMul		},
				{ '*', ETYPE_TripleChars	},
				{ '\0', ETYPE_Unknown		}, } },
			{ '/', ETYPE_Div, {
				{ '=', ETYPE_AssignDiv		},
				{ '\0', ETYPE_Unknown		}, } },
			{ '%', ETYPE_Mod, {
				{ '=', ETYPE_AssignMod		},
				{ '%', ETYPE_ModMod		},
				{ '\0', ETYPE_Unknown		}, } },
			{ '=', ETYPE_Assign, {
				{ '=', ETYPE_Eq 			},
				{ '>', ETYPE_Pair			},
				{ '\0', ETYPE_Unknown		}, } },
			{ '<', ETYPE_Lt, {
				{ '=', ETYPE_TripleChars	},
				{ '<', ETYPE_TripleChars	},
				{ '\0', ETYPE_Unknown		}, } },
			{ '>', ETYPE_Gt, {
				{ '=', ETYPE_Ge				},
				{ '>', ETYPE_TripleChars	},
				{ '\0', ETYPE_Unknown		}, } },
			{ '!', ETYPE_Not, {
				{ '=', ETYPE_Ne				},
				{ '\0', ETYPE_Unknown		}, } },
			{ '|', ETYPE_Or, {
				{ '=', ETYPE_AssignOr 		},
				{ '|', ETYPE_OrOr			},
				{ '\0', ETYPE_Unknown		}, } },
			{ '&', ETYPE_And, {
				{ '=', ETYPE_AssignAnd		},
				{ '&', ETYPE_AndAnd			},
				{ '\0', ETYPE_Unknown		}, } },
			{ '^', ETYPE_Xor, {
				{ '=', ETYPE_AssignXor		},
				{ '\0', ETYPE_Unknown		}, } },
		};
		int chFirst = _token[0];
		if (chFirst == '/' && ch == '*') {
			_commentNestLevel = 1;
			_stat = STAT_CommentBlock;
		} else if (chFirst == '/' && ch == '/') {
			FeedElement(env, Element(ETYPE_EOL, GetLineNo()));
			if (_cntLine == 0 || (_cntLine == 1 && _appearShebangFlag)) {
				_stat = STAT_MagicCommentLine;
			} else {
				_stat = STAT_CommentLine;
			}
		} else if (chFirst == '*' && ch == '/') {
			SetError(ERR_SyntaxError, "unmatching comment description");
			_stat = STAT_Error;
		} else {
			Gura_Pushback();
			_stat = STAT_Start;
			for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
				if (tbl[i].chFirst != chFirst) continue;
				ElemType elemType = tbl[i].elemType;
				for (size_t j = 0; j < ArraySizeOf(tbl[i].tblCand); j++) {
					if (tbl[i].tblCand[j].chSecond == '\0') break;
					if (tbl[i].tblCand[j].chSecond != ch) continue;
					_token.push_back(ch);
					elemType = tbl[i].tblCand[j].elemType;
					Gura_PushbackCond(false);
					break;
				}
				if (elemType == ETYPE_TripleChars) {
					_stat = STAT_TripleChars;
				} else if (_elemStack.back().IsType(ETYPE_Quote)) {
					FeedElement(env, Element(ETYPE_Symbol, GetLineNo(), _token));
					if (sig.IsSignalled()) _stat = STAT_Error;
				} else {
					FeedElement(env, Element(elemType, GetLineNo()));
					if (sig.IsSignalled()) _stat = STAT_Error;
				}
				break;
			}
			// tables have a bug if i reaches at ArraySizeOf(tbl)
		}
		break;
	}
	case STAT_TripleChars: {
		static const struct {
			const char *strFirst;
			ElemType elemType;
			struct {
				int chThird;
				ElemType elemType;
			} tblCand[5];
		} tbl[] = {
			{ "**", ETYPE_Pow, {
				{ '=', ETYPE_AssignPow		},
				{ '\0', ETYPE_Unknown		}, } },
			{ "<=", ETYPE_Le, {
				{ '>', ETYPE_Cmp			},
				{ '\0', ETYPE_Unknown		}, } },
			{ "<<", ETYPE_Shl, {
				{ '=', ETYPE_AssignShl		},
				{ '\0', ETYPE_Unknown		}, } },
			{ ">>", ETYPE_Shr, {
				{ '=', ETYPE_AssignShr		},
				{ '\0', ETYPE_Unknown		}, } },
		};
		Gura_Pushback();
		_stat = STAT_Start;
		for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
			if (_token.compare(tbl[i].strFirst) != 0) continue;
			ElemType elemType = tbl[i].elemType;
			for (size_t j = 0; j < ArraySizeOf(tbl[i].tblCand); j++) {
				if (tbl[i].tblCand[j].chThird == '\0') break;
				if (tbl[i].tblCand[j].chThird != ch) continue;
				_token.push_back(ch);
				elemType = tbl[i].tblCand[j].elemType;
				Gura_PushbackCond(false);
				break;
			}
			if (_elemStack.back().IsType(ETYPE_Quote)) {
				FeedElement(env, Element(ETYPE_Symbol, GetLineNo(), _token));
				if (sig.IsSignalled()) _stat = STAT_Error;
			} else {
				FeedElement(env, Element(elemType, GetLineNo()));
				if (sig.IsSignalled()) _stat = STAT_Error;
			}
			break;
		}
		// tables have a bug if i reaches at ArraySizeOf(tbl)
		break;
	}
	case STAT_Escape: {
		if (ch == '\0') {
			Gura_Pushback();
			_stat = STAT_Start;
		} else if (ch == '\n') {
			_stat = STAT_Start;
		} else if (IsWhite(ch)) {
			// nothing to do
		} else {
			SetError(ERR_SyntaxError, "invalid escape character");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_Colon: {
		if (ch == ':') {
			FeedElement(env, Element(ETYPE_ColonColon, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else if (ch == '*') {
			FeedElement(env, Element(ETYPE_ColonAsterisk, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else if (ch == '&') {
			FeedElement(env, Element(ETYPE_ColonAnd, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else {
			ElemType elemType = _elemStack.back().IsSuffixElement()?
									ETYPE_ColonAfterSuffix : ETYPE_Colon;
			FeedElement(env, Element(elemType, GetLineNo()));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_Error: {
		InitStack();
		_blockParamFlag = false;
		Gura_Pushback();
		_stat = STAT_ErrorRecovery;
		break;
	}
	case STAT_ErrorRecovery: {
		if (ch == '\n' || ch == '\0') {
			Gura_Pushback();
			_stat = STAT_Start;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_AfterLBrace: {
		if (ch == '|') {
			FeedElement(env, Element(ETYPE_LBlockParam, GetLineNo()));
			if (sig.IsSignalled()) {
				_stat = STAT_Error;
			} else {
				_blockParamFlag = true;
				_stat = STAT_Start;
			}
		} else if (ch == '\n' || IsWhite(ch)) {
			// nothing to do
		} else {
			Gura_Pushback();
			_stat = STAT_Start;
		}
		break;
	}
	case STAT_NumberPre: {
		if (ch == 'x' || ch == 'X') {
			_token.push_back(ch);
			_stat = STAT_NumberHex;
		} else if (ch == 'b' || ch == 'B') {
			_token.push_back(ch);
			_stat = STAT_NumberBin;
		} else if(IsOctDigit(ch)) {
			_token.push_back(ch);
			_stat = STAT_NumberOct;
		} else {
			Gura_Pushback();
			_stat = STAT_Number;
		}
		break;
	}
	case STAT_NumberHex: {
		if (IsHexDigit(ch)) {
			_token.push_back(ch);
		} else if (_token.size() <= 2) {
			SetError(ERR_SyntaxError, "wrong format of hexadecimal number");
			Gura_Pushback();
			_stat = STAT_Error;
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_NumberSuffixed;
		} else {
			FeedElement(env, Element(ETYPE_Number, GetLineNo(), _token));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberOct: {
		if (IsOctDigit(ch)) {
			_token.push_back(ch);
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_NumberSuffixed;
		} else {
			FeedElement(env, Element(ETYPE_Number, GetLineNo(), _token));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberBin: {
		if (IsBinDigit(ch)) {
			_token.push_back(ch);
		} else if (_token.size() <= 2) {
			SetError(ERR_SyntaxError, "wrong format of binary number");
			Gura_Pushback();
			_stat = STAT_Error;
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_NumberSuffixed;
		} else {
			FeedElement(env, Element(ETYPE_Number, GetLineNo(), _token));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberAfterDot: {
		if (ch == '.') {
			if (_elemStack.back().IsType(ETYPE_Quote)) {
				_token.push_back(ch);
				FeedElement(env, Element(ETYPE_Symbol, GetLineNo(), _token));
			} else {
				FeedElement(env, Element(ETYPE_Seq, GetLineNo()));
			}
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else if (IsDigit(ch)) {
			_token.push_back(ch);
			_stat = STAT_Number;
		} else {
			FeedElement(env, Element(ETYPE_Dot, GetLineNo()));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_Number: {
		if (IsDigit(ch)) {
			_token.push_back(ch);
		} else if (ch == '.') {
			size_t pos = _token.find('.');
			if (pos == _token.length() - 1) {
				_token.resize(pos);
				FeedElement(env, Element(ETYPE_Number, GetLineNo(), _token));
				if (!sig.IsSignalled()) {
					FeedElement(env, Element(ETYPE_Seq, GetLineNo()));
				}
				_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
			} else if (pos == String::npos) {
				_token.push_back(ch);
			} else {
				SetError(ERR_SyntaxError, "dot has already been scanned");
				_stat = STAT_Error;
			}
		} else if (ch == 'e' || ch == 'E') {
			_token.push_back(ch);
			_stat = STAT_NumberExpAfterE;
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_NumberSuffixed;
		} else {
			FeedElement(env, Element(ETYPE_Number, GetLineNo(), _token));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberExpAfterE: {
		if (IsDigit(ch)) {
			_token.push_back(ch);
			_stat = STAT_NumberExp;
		} else if (ch == '+' || ch == '-') {
			_token.push_back(ch);
			_stat = STAT_NumberExpAfterSign;
		} else {
			SetError(ERR_SyntaxError, "wrong exponential expression");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_NumberExpAfterSign: {
		if (IsDigit(ch)) {
			_token.push_back(ch);
			_stat = STAT_NumberExp;
		} else {
			SetError(ERR_SyntaxError, "wrong exponential expression");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_NumberExp: {
		if (IsDigit(ch)) {
			_token.push_back(ch);
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_NumberSuffixed;
		} else {
			FeedElement(env, Element(ETYPE_Number, GetLineNo(), _token));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberSuffixed: {
		if (IsSymbolChar(ch)) {
			_suffix.push_back(ch);
		} else {
			FeedElement(env, Element(ETYPE_NumberSuffixed,
											 GetLineNo(), _token, _suffix));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_Symbol: {
		if (IsSymbolChar(ch)) {
			_token.push_back(ch);
		} else if (ch == '!') {
			_stat = STAT_SymbolExclamation;
		} else if ((ch == '"' || ch == '\'') && CheckStringPrefix(_stringInfo, _token)) {
			_stringInfo.chBorder = ch;
			_token.clear();
			_stat = STAT_StringFirst;
		} else {
			if (_token == "in" && !_elemStack.back().IsType(ETYPE_Quote)) {
				FeedElement(env, Element(ETYPE_Contains, GetLineNo()));
			} else {
				FeedElement(env, Element(ETYPE_Symbol, GetLineNo(), _token));
			}
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_SymbolExclamation: {
		if (ch == '=' || ch == '!') {
			FeedElement(env, Element(ETYPE_Symbol, GetLineNo(), _token));
			if (sig.IsSignalled()) {
				_stat = STAT_Error;
			} else {
				_token.clear();
				_token.push_back('!');
				_stat = STAT_DoubleChars;
			}
		} else {
			_token.push_back('!');
			Gura_Pushback();
			_stat = STAT_Symbol;
		}
		break;
	}
	case STAT_CommentLineTop: {
		if (ch == '!') {
			_appearShebangFlag = true;
			_stat = STAT_ShebangLine;
		} else {
			_stat = STAT_MagicCommentLine;
			Gura_Pushback();
		}
		break;
	}
	case STAT_MagicCommentLine: {
		if (_magicCommentParser.ParseChar(ch)) {
			const char *encoding = _magicCommentParser.GetEncoding();
			sig.SetSignal(SIGTYPE_DetectEncoding, Value(encoding));
		}
		if (ch == '\n') {
			_stat = STAT_Start;
		} else if (ch == '\0') {
			_stat = STAT_Start;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_ShebangLine: {
		if (ch == '\n' || ch == '\0') {
			_stat = STAT_Start;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_CommentLine: {
		if (ch == '\n' || ch == '\0') {
			_stat = STAT_Start;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_CommentBlock: {
		if (ch == '*') {
			_stat = STAT_CommentBlockEnd;
		} else if (ch == '/') {
			_stat = STAT_CommentBlockNest;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_CommentBlockEnd: {
		if (ch == '/') {
			_commentNestLevel--;
			if (_commentNestLevel > 0) {
				_stat = STAT_CommentBlock;
			} else {
				_stat = STAT_Start;
			}
		} else {
			Gura_Pushback();
			_stat = STAT_CommentBlock;
		}
		break;
	}
	case STAT_CommentBlockNest: {
		if (ch == '*') {
			_commentNestLevel++;
			_stat = STAT_CommentBlock;
		} else {
			Gura_Pushback();
			_stat = STAT_CommentBlock;
		}
		break;
	}
	case STAT_StringFirst: {
		if (ch == _stringInfo.chBorder) {
			_stat = STAT_StringSecond;
		} else {
			Gura_Pushback();
			_stat = STAT_String;
		}
		break;
	}
	case STAT_StringSecond: {
		if (ch == _stringInfo.chBorder) {
			if (_stringInfo.wiseFlag) {
				_stringInfo.strIndentRef = _strIndent;
				_stat = STAT_MStringWise;
			} else {
				_stat = STAT_MString;
			}
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_StringSuffixed;
		} else {
			ElemType elemType = ElemTypeForString(_stringInfo);
			FeedElement(env, Element(elemType, GetLineNo(), _token));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_String: {
		if (ch == _stringInfo.chBorder) {
			_stat = STAT_StringPost;
		} else if (ch == '\\') {
			_stringInfo.statRtn = STAT_String;
			_stat = STAT_StringEsc;
		} else if (ch == '\0' || ch == '\n') {
			SetError(ERR_SyntaxError, "string is not terminated correctly");
			_stat = STAT_Error;
		} else {
			_token.push_back(ch);
		}
		break;
	}
	case STAT_MStringWise: {
		if (ch == '\n') {
			_stat = STAT_MStringLineHead;
		} else {
			Gura_Pushback();
			_stat = STAT_MString;
		}
		break;
	}
	case STAT_MString: {
		if (ch == _stringInfo.chBorder) {
			_stat = STAT_MStringEndFirst;
		} else if (ch == '\\') {
			_stringInfo.statRtn = STAT_MString;
			_stat = STAT_StringEsc;
		} else if (ch == '\0') {
			SetError(ERR_SyntaxError, "string is not terminated correctly");
			_stat = STAT_Error;
		} else if (ch == '\n' && _stringInfo.wiseFlag) {
			_token.push_back(ch);
			_stat = STAT_MStringLineHead;
		} else {
			_token.push_back(ch);
		}
		break;
	}
	case STAT_MStringLineHead: {
		if (IsWhite(ch)) {
			if (_strIndent.size() == _stringInfo.strIndentRef.size()) {
				if (_strIndent != _stringInfo.strIndentRef) {
					_token += _strIndent;
				}
				_stat = STAT_MString;
			}
		} else {
			_token += _strIndent;
			Gura_Pushback();
			_stat = STAT_MString;
		}
		break;
	}
	case STAT_StringEsc: {
		if (_stringInfo.rawFlag) {
			_token.push_back('\\');
			_token.push_back(ch);
			_stat = _stringInfo.statRtn;
		} else {
			if (ch == '\n') {
				_stat = _stringInfo.statRtn;
			} else if (ch == 'x') {
				_stringInfo.accum = 0x00;
				_stringInfo.cntRest = 2;
				_stat = STAT_StringEscHex;
			} else if (IsOctDigit(ch)) {
				_stringInfo.accum = ConvOctDigit(ch);
				_stringInfo.cntRest = 2;
				_stat = STAT_StringEscOct;
			} else if (ch == 'u') {
				_stringInfo.accum = 0x0000;
				_stringInfo.cntRest = 4;
				_stat = STAT_StringEscUnicode;
			} else if (ch == 'U') {
				_stringInfo.accum = 0x00000000;
				_stringInfo.cntRest = 8;
				_stat = STAT_StringEscUnicode;
			} else {
				_token.push_back(GetEscaped(ch));
				_stat = _stringInfo.statRtn;
			}
		}
		break;
	}
	case STAT_StringEscHex: {
		if (IsHexDigit(ch)) {
			_stringInfo.accum = (_stringInfo.accum << 4) + ConvHexDigit(ch);
			_stringInfo.cntRest--;
			if (_stringInfo.cntRest <= 0) {
				_token.push_back(static_cast<char>(_stringInfo.accum));
				_stat = _stringInfo.statRtn;
			}
		} else {
			SetError(ERR_SyntaxError, "invalid hex expression in string");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_StringEscOct: {
		if (IsOctDigit(ch)) {
			_stringInfo.accum = (_stringInfo.accum << 3) + ConvOctDigit(ch);
			_stringInfo.cntRest--;
			if (_stringInfo.cntRest <= 0) {
				_token.push_back(static_cast<char>(_stringInfo.accum));
				_stat = _stringInfo.statRtn;
			}
		} else {
			SetError(ERR_SyntaxError, "invalid oct expression in string");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_StringEscUnicode: {
		if (IsHexDigit(ch)) {
			_stringInfo.accum = (_stringInfo.accum << 4) + ConvHexDigit(ch);
			_stringInfo.cntRest--;
			if (_stringInfo.cntRest <= 0) {
				AppendUTF32(_token, _stringInfo.accum);
				_stat = _stringInfo.statRtn;
			}
		} else {
			SetError(ERR_SyntaxError, "invalid Unicode code point in string");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_StringInCommentBlock: {
		if (ch == _stringInfo.chBorder) {
			_stat = STAT_CommentBlock;
		} else if (ch == '\\') {
			_stat = STAT_StringEscInCommentBlock;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_StringEscInCommentBlock: {
		_stat = STAT_StringInCommentBlock;
		break;
	}
	case STAT_MStringEndFirst: {
		if (ch == _stringInfo.chBorder) {
			_stat = STAT_MStringEndSecond;
		} else {
			_token.push_back(_stringInfo.chBorder);
			Gura_Pushback();
			_stat = STAT_MString;
		}
		break;
	}
	case STAT_MStringEndSecond: {
		if (ch == _stringInfo.chBorder) {
			_stat = STAT_StringPost;
		} else {
			_token.push_back(_stringInfo.chBorder);
			_token.push_back(_stringInfo.chBorder);
			Gura_Pushback();
			_stat = STAT_MString;
		}
		break;
	}
	case STAT_StringPost: {
		if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_StringSuffixed;
		} else {
			ElemType elemType = ElemTypeForString(_stringInfo);
			FeedElement(env, Element(elemType, GetLineNo(), _token));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_StringSuffixed: {
		if (IsSymbolChar(ch)) {
			_suffix.push_back(ch);
		} else {
			FeedElement(env, Element(ETYPE_StringSuffixed,
												GetLineNo(), _token, _suffix));
			Gura_Pushback();
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_RecoverConsole: {
		if (ch == '\n') {
			_stat = STAT_BOF;
			_lineHeadFlag = true;
			InitStack();
		}
		break;
	}
	}
	Gura_EndPushbackRegion();
	if (ch == '\n') {
		_lineHeadFlag = true;
		_strIndent.clear();
		_cntLine++;
		_cntCol = 0;
	} else {
		_cntCol++;
	}
	return sig.IsNoSignalled();
}

//-----------------------------------------------------------------------------
// Lexer::ElementStack
//-----------------------------------------------------------------------------
Lexer::ElementStack::~ElementStack()
{
}

Lexer::ElementStack::reverse_iterator
					Lexer::ElementStack::SeekTerminal(reverse_iterator p)
{
	for ( ; p->IsType(ETYPE_Expr); p++) ;
	return p;
}

void Lexer::ElementStack::Clear()
{
	foreach (ElementStack, pElem, *this) {
		Expr::Delete(pElem->GetExpr());
	}
	clear();
}

String Lexer::ElementStack::ToString() const
{
	String rtn;
	foreach_const (ElementStack, pElement, *this) {
		if (pElement != begin()) rtn.append(" ");
		rtn.append(pElement->GetTypeSymbol());
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// Lexer::Element
//-----------------------------------------------------------------------------
const Lexer::Element Lexer::Element::Unknown;

Lexer::Element::~Element()
{
}

const char *Lexer::Element::GetTypeSymbol() const
{
	const ElemTypeInfo *p = LookupElemTypeInfo(_elemType);
	return (p == nullptr)? "[unk]" : p->symbol;
}

}
