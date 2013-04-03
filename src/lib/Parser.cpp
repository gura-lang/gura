#include "stdafx.h"

#define DBGPARSER(x)

namespace Gura {

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
Parser::Parser() : _stat(STAT_Start),
		_appearShebangFlag(false), _blockParamFlag(false), _quoteFlag(false),
		_cntLine(0), _commentNestLevel(0)
{
	InitStack();
	for (const ElemTypeInfo *p = _elemTypeInfoTbl;
										p->elemType != ETYPE_Unknown; p++) {
		_elemTypeToIndexMap[p->elemType] = p->index;
	}
}

Parser::~Parser()
{
}

void Parser::Reset()
{
	_stat = STAT_Start;
	InitStack();
}

void Parser::InitStack()
{
	_elemStack.Clear();
	_elemStack.push_back(Element(ETYPE_Begin, 0));
}

Expr *Parser::ParseChar(Environment &env, Signal sig, char ch)
{
	if (ch == '\r') return NULL;
	bool continueFlag;
	Expr *pExpr = NULL;
	do {
	continueFlag = false;
	switch (_stat) {
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
		} else if (IsSymbolFirstChar(ch)) {
			_token.clear();
			_token.push_back(ch);
			_stat = STAT_Symbol;
		} else if (ch == '"' || ch == '\'') {
			_stringInfo.chBorder = ch;
			_stringInfo.rawFlag = false;
			_stringInfo.binaryFlag = false;
			_stringInfo.skipFirstEOLFlag = false;
			_token.clear();
			_stat = STAT_StringFirst;
		} else if (ch == '\\') {
			_stat = STAT_Escape;
		} else if (ch == '\n') {
			pExpr = FeedElement(env, sig, Element(ETYPE_EOL, GetLineNo()));
			if (sig.IsSignalled()) _stat = STAT_Error;
		} else if (ch == '#') {
			pExpr = FeedElement(env, sig, Element(ETYPE_EOL, GetLineNo()));
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
			pExpr = FeedElement(env, sig, Element(ETYPE_LBrace, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_AfterLBrace;
		} else if (ch == '|' && _blockParamFlag && CheckBlockParamEnd()) {
			_blockParamFlag = false;
			pExpr = FeedElement(env, sig, Element(ETYPE_RBlockParam, GetLineNo()));
			if (sig.IsSignalled()) _stat = STAT_Error;
		} else if (ch == '`') {
			_stat = STAT_Quote;
		} else if (ch == ':') {
			_stat = STAT_Colon;
		} else {
			int i;
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
				{ '~',	ETYPE_Invert,		},
				{ ',',	ETYPE_Comma,		},
				{ ';',	ETYPE_Semicolon,	},
				{ '(',	ETYPE_LParenthesis,	},
				{ ')',	ETYPE_RParenthesis,	},
				{ '}',	ETYPE_RBrace,		},
				{ '[',	ETYPE_LBracket,		},
				{ ']',	ETYPE_RBracket,		},
				{ '\0',	ETYPE_EOF,			},
			};
			for (i = 0; i < ArraySizeOf(tbl); i++) {
				if (tbl[i].ch == ch) break;
			}
			if (i >= ArraySizeOf(tbl)) {
				SetError(sig, ERR_SyntaxError, "unexpected character '%c' (%d)", ch, ch);
				_stat = STAT_Error;
			} else if (tbl[i].elemType == ETYPE_DoubleChars) {
				_token.clear();
				_token.push_back(ch);
				_stat = STAT_DoubleChars;
			} else if (_quoteFlag) {
				_quoteFlag = false;
				_token.clear();
				_token.push_back('`');
				_token.push_back(ch);
				pExpr = FeedElement(env, sig, Element(ETYPE_Symbol, GetLineNo(), _token));
				if (sig.IsSignalled()) _stat = STAT_Error;
			} else {
				pExpr = FeedElement(env, sig, Element(tbl[i].elemType, GetLineNo()));
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
			{ '+', ETYPE_Plus, {
						{ '=', ETYPE_AssignPlus		},
						{ '\0', ETYPE_Unknown		}, } },
			{ '-', ETYPE_Minus, {
						{ '=', ETYPE_AssignMinus	},
						{ '\0', ETYPE_Unknown		}, } },
			{ '*', ETYPE_Multiply, {
						{ '=', ETYPE_AssignMultiply	},
						{ '*', ETYPE_TripleChars	},
						{ '\0', ETYPE_Unknown		}, } },
			{ '/', ETYPE_Divide, {
						{ '=', ETYPE_AssignDivide	},
						{ '\0', ETYPE_Unknown		}, } },
			{ '%', ETYPE_Modulo, {
						{ '=', ETYPE_AssignModulo	},
						{ '%', ETYPE_ModuloModulo	},
						{ '\0', ETYPE_Unknown		}, } },
			{ '=', ETYPE_Assign, {
						{ '=', ETYPE_Equal 			},
						{ '>', ETYPE_DictAssign		},
						{ '\0', ETYPE_Unknown		}, } },
			{ '<', ETYPE_Less, {
						{ '=', ETYPE_TripleChars	},
						{ '<', ETYPE_TripleChars	},
						{ '\0', ETYPE_Unknown		}, } },
			{ '>', ETYPE_Greater, {
						{ '=', ETYPE_GreaterEq		},
						{ '>', ETYPE_TripleChars	},
						{ '\0', ETYPE_Unknown		}, } },
			{ '!', ETYPE_Not, {
						{ '=', ETYPE_NotEqual		},
						{ '!', ETYPE_Force			},
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
			pExpr = FeedElement(env, sig, Element(ETYPE_EOL, GetLineNo()));
			if (_cntLine == 0 || (_cntLine == 1 && _appearShebangFlag)) {
				_stat = STAT_MagicCommentLine;
			} else {
				_stat = STAT_CommentLine;
			}
		} else if (chFirst == '*' && ch == '/') {
			SetError(sig, ERR_SyntaxError, "unmatching comment description");
			_stat = STAT_Error;
		} else {
			_stat = STAT_Start;
			continueFlag = true;
			for (int i = 0; i < ArraySizeOf(tbl); i++) {
				if (tbl[i].chFirst != chFirst) continue;
				ElemType elemType = tbl[i].elemType;
				for (int j = 0; j < ArraySizeOf(tbl[i].tblCand); j++) {
					if (tbl[i].tblCand[j].chSecond == '\0') break;
					if (tbl[i].tblCand[j].chSecond != ch) continue;
					_token.push_back(ch);
					elemType = tbl[i].tblCand[j].elemType;
					continueFlag = false;
					break;
				}
				if (elemType == ETYPE_TripleChars) {
					_stat = STAT_TripleChars;
				} else if (_quoteFlag) {
					_quoteFlag = false;
					_token.insert(0, "`");
					pExpr = FeedElement(env, sig, Element(ETYPE_Symbol, GetLineNo(), _token));
					if (sig.IsSignalled()) _stat = STAT_Error;
				} else {
					pExpr = FeedElement(env, sig, Element(elemType, GetLineNo()));
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
			{ "**", ETYPE_Power, {
						{ '=', ETYPE_AssignPower	},
						{ '\0', ETYPE_Unknown		}, } },
			{ "<=", ETYPE_LessEq, {
						{ '>', ETYPE_Compare		},
						{ '\0', ETYPE_Unknown		}, } },
			{ "<<", ETYPE_ShiftL, {
						{ '=', ETYPE_AssignShiftL	},
						{ '\0', ETYPE_Unknown		}, } },
			{ ">>", ETYPE_ShiftR, {
						{ '=', ETYPE_AssignShiftR	},
						{ '\0', ETYPE_Unknown		}, } },
		};
		_stat = STAT_Start;
		continueFlag = true;
		for (int i = 0; i < ArraySizeOf(tbl); i++) {
			if (_token.compare(tbl[i].strFirst) != 0) continue;
			ElemType elemType = tbl[i].elemType;
			for (int j = 0; j < ArraySizeOf(tbl[i].tblCand); j++) {
				if (tbl[i].tblCand[j].chThird == '\0') break;
				if (tbl[i].tblCand[j].chThird != ch) continue;
				_token.push_back(ch);
				elemType = tbl[i].tblCand[j].elemType;
				continueFlag = false;
				break;
			}
			if (_quoteFlag) {
				_quoteFlag = false;
				_token.insert(0, "`");
				pExpr = FeedElement(env, sig, Element(ETYPE_Symbol, GetLineNo(), _token));
				if (sig.IsSignalled()) _stat = STAT_Error;
			} else {
				pExpr = FeedElement(env, sig, Element(elemType, GetLineNo()));
				if (sig.IsSignalled()) _stat = STAT_Error;
			}
			break;
		}
		// tables have a bug if i reaches at ArraySizeOf(tbl)
		break;
	}
	case STAT_Escape: {
		if (ch == '\0') {
			continueFlag = true;
			_stat = STAT_Start;
		} else if (ch == '\n') {
			_stat = STAT_Start;
		} else if (IsWhite(ch)) {
			// nothing to do
		} else {
			SetError(sig, ERR_SyntaxError, "invalid escape character");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_Quote: {
		// the following characters must be contained in the table in STAT_Start
		static const char chTbl[] = {
			'+', '-', '*', '/',
			'%', '=', '<', '>',
			'!', '|', '&', '^',
			'~',
		};
		int i = 0;
		for (i = 0; i < ArraySizeOf(chTbl); i++) {
			if (chTbl[i] == ch) break;
		}
		if (i < ArraySizeOf(chTbl)) {
			_quoteFlag = true;
			continueFlag = true;
			_stat = STAT_Start;
		} else {
			pExpr = FeedElement(env, sig, Element(ETYPE_Quote, GetLineNo()));
			continueFlag = true;
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_Colon: {
		if (ch == ':') {
			pExpr = FeedElement(env, sig,
								Element(ETYPE_ColonColon, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else if (ch == '*') {
			pExpr = FeedElement(env, sig,
								Element(ETYPE_ColonAsterisk, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else if (ch == '&') {
			pExpr = FeedElement(env, sig,
								Element(ETYPE_ColonAnd, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else {
			ElemType elemType = _elemStack.back().IsSuffixElement()?
									ETYPE_ColonAfterSuffix : ETYPE_Colon;
			pExpr = FeedElement(env, sig, Element(elemType, GetLineNo()));
			continueFlag = true;
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_Error: {
		InitStack();
		_blockParamFlag = false;
		continueFlag = true;
		_stat = STAT_ErrorRecovery;
		break;
	}
	case STAT_ErrorRecovery: {
		if (ch == '\n' || ch == '\0') {
			continueFlag = true;
			_stat = STAT_Start;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_AfterLBrace: {
		if (ch == '|') {
			pExpr = FeedElement(env, sig, Element(ETYPE_LBlockParam, GetLineNo()));
			if (sig.IsSignalled()) {
				_stat = STAT_Error;
			} else {
				_blockParamFlag = true;
				_stat = STAT_Start;
			}
		} else if (ch == '\n' || IsWhite(ch)) {
			// nothing to do
		} else {
			continueFlag = true;
			_stat = STAT_Start;
		}
		break;
	}
	case STAT_NumberPre: {
		if (ch == 'x' || ch == 'X') {
			_token.push_back(ch);
			_stat = STAT_NumberHex;
		} else if(IsOctDigit(ch)) {
			_token.push_back(ch);
			_stat = STAT_NumberOct;
		} else {
			continueFlag = true;
			_stat = STAT_Number;
		}
		break;
	}
	case STAT_NumberHex: {
		if (IsHexDigit(ch)) {
			_token.push_back(ch);
		} else if (_token.size() > 2) {
			pExpr = FeedElement(env, sig, Element(ETYPE_Number, GetLineNo(), _token));
			continueFlag = true;
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else {
			SetError(sig, ERR_SyntaxError, "wrong format of hexadecimal number");
			continueFlag = true;
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_NumberOct: {
		if (IsOctDigit(ch)) {
			_token.push_back(ch);
		} else {
			pExpr = FeedElement(env, sig, Element(ETYPE_Number, GetLineNo(), _token));
			continueFlag = true;
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberAfterDot: {
		if (ch == '.') {
			pExpr = FeedElement(env, sig, Element(ETYPE_Sequence, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else if (IsDigit(ch)) {
			_token.push_back(ch);
			_stat = STAT_Number;
		} else {
			pExpr = FeedElement(env, sig, Element(ETYPE_Dot, GetLineNo()));
			continueFlag = true;
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
				pExpr = FeedElement(env, sig, Element(ETYPE_Number, GetLineNo(), _token));
				if (!sig.IsSignalled()) {
					pExpr = FeedElement(env, sig, Element(ETYPE_Sequence, GetLineNo()));
				}
				_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
			} else if (pos == String::npos) {
				_token.push_back(ch);
			} else {
				SetError(sig, ERR_SyntaxError, "dot has already been scanned");
				_stat = STAT_Error;
			}
		} else if (ch == 'e' || ch == 'E') {
			_token.push_back(ch);
			_stat = STAT_NumberExpAfterE;
		} else if (ch == 'j') {
			_stat = STAT_ImagNumber;
		} else {
			pExpr = FeedElement(env, sig, Element(ETYPE_Number, GetLineNo(), _token));
			continueFlag = true;
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
			SetError(sig, ERR_SyntaxError, "wrong exponential expression");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_NumberExpAfterSign: {
		if (IsDigit(ch)) {
			_token.push_back(ch);
			_stat = STAT_NumberExp;
		} else {
			SetError(sig, ERR_SyntaxError, "wrong exponential expression");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_NumberExp: {
		if (IsDigit(ch)) {
			_token.push_back(ch);
		} else if (ch == 'j') {
			_stat = STAT_ImagNumber;
		} else {
			pExpr = FeedElement(env, sig, Element(ETYPE_Number, GetLineNo(), _token));
			continueFlag = true;
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_ImagNumber: {
		if (IsSymbolChar(ch)) {
			SetError(sig, ERR_SyntaxError, "wrong format of number");
			_stat = STAT_Error;
		} else {
			pExpr = FeedElement(env, sig, Element(ETYPE_ImagNumber, GetLineNo(), _token));
			continueFlag = true;
			_stat = STAT_Start;
		}
		break;
	}
	case STAT_Symbol: {
		if (IsSymbolChar(ch)) {
			_token.push_back(ch);
		} else if (ch == '!') {
			_stat = STAT_SymbolExclamation;
		} else if ((ch == '"' || ch == '\'') &&
									CheckStringPrefix(_stringInfo, _token)) {
			_stringInfo.chBorder = ch;
			_token.clear();
			_stat = STAT_StringFirst;
		} else {
			if (_token == "in") {
				pExpr = FeedElement(env, sig, Element(ETYPE_ContainCheck, GetLineNo()));
			} else {
				pExpr = FeedElement(env, sig, Element(ETYPE_Symbol, GetLineNo(), _token));
			}
			continueFlag = true;
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_SymbolExclamation: {
		if (ch == '=' || ch == '!') {
			pExpr = FeedElement(env, sig, Element(ETYPE_Symbol, GetLineNo(), _token));
			if (sig.IsSignalled()) {
				_stat = STAT_Error;
			} else {
				_token.clear();
				_token.push_back('!');
				_stat = STAT_DoubleChars;
			}
		} else {
			_token.push_back('!');
			continueFlag = true;
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
			continueFlag = true;
		}
		break;
	}
	case STAT_MagicCommentLine: {
		if (_magicCommentParser.ParseChar(ch)) {
			const char *encoding = _magicCommentParser.GetEncoding();
			sig.SetSignal(SIGTYPE_DetectEncoding, Value(env, encoding));
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
		} else if (ch == '"' || ch == '\'') {
			_stringInfo.chBorder = ch;
			_stat = STAT_StringInCommentBlock;
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
			continueFlag = true;
			_stat = STAT_CommentBlock;
		}
		break;
	}
	case STAT_CommentBlockNest: {
		if (ch == '*') {
			_commentNestLevel++;
			_stat = STAT_CommentBlock;
		} else {
			continueFlag = true;
			_stat = STAT_CommentBlock;
		}
		break;
	}
	case STAT_StringFirst: {
		if (ch == _stringInfo.chBorder) {
			_stat = STAT_StringSecond;
		} else {
			continueFlag = true;
			_stat = STAT_String;
		}
		break;
	}
	case STAT_StringSecond: {
		if (ch == _stringInfo.chBorder) {
			_stat = _stringInfo.skipFirstEOLFlag? STAT_MStringFirst : STAT_MString;
		} else {
			ElemType elemType = ElemTypeForString(_stringInfo);
			pExpr = FeedElement(env, sig, Element(elemType, GetLineNo(), _token));
			continueFlag = true;
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_String: {
		if (ch == _stringInfo.chBorder) {
			ElemType elemType = ElemTypeForString(_stringInfo);
			pExpr = FeedElement(env, sig, Element(elemType, GetLineNo(), _token));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else if (ch == '\\') {
			_stringInfo.statRtn = STAT_String;
			_stat = STAT_StringEsc;
		} else if (ch == '\0' || ch == '\n') {
			SetError(sig, ERR_SyntaxError, "string is not terminated correctly");
			_stat = STAT_Error;
		} else {
			_token.push_back(ch);
		}
		break;
	}
	case STAT_MStringFirst: {
		if (ch == '\n') {
			// nothing to do
		} else {
			continueFlag = true;
		}
		_stat = STAT_MString;
		break;
	}
	case STAT_MString: {
		if (ch == _stringInfo.chBorder) {
			_stat = STAT_MStringEndFirst;
		} else if (ch == '\\') {
			_stringInfo.statRtn = STAT_MString;
			_stat = STAT_StringEsc;
		} else if (ch == '\0') {
			SetError(sig, ERR_SyntaxError, "string is not terminated correctly");
			_stat = STAT_Error;
		} else {
			_token.push_back(ch);
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
			SetError(sig, ERR_SyntaxError, "invalid hex expression in string");
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
			SetError(sig, ERR_SyntaxError, "invalid oct expression in string");
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
			continueFlag = true;
			_stat = STAT_MString;
		}
		break;
	}
	case STAT_MStringEndSecond: {
		if (ch == _stringInfo.chBorder) {
			ElemType elemType = ElemTypeForString(_stringInfo);
			pExpr = FeedElement(env, sig, Element(elemType, GetLineNo(), _token));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else {
			_token.push_back(_stringInfo.chBorder);
			_token.push_back(_stringInfo.chBorder);
			continueFlag = true;
			_stat = STAT_MString;
		}
		break;
	}
	} } while (continueFlag);
	if (ch == '\n') _cntLine++;
	return pExpr;
}

bool Parser::CheckBlockParamEnd() const
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

Parser::ElemType Parser::ElemTypeForString(const StringInfo &stringInfo)
{
	return stringInfo.binaryFlag? ETYPE_Binary : ETYPE_String;
}

bool Parser::CheckStringPrefix(StringInfo &stringInfo, const String &token)
{
	stringInfo.rawFlag = false;
	stringInfo.binaryFlag = false;
	stringInfo.skipFirstEOLFlag = false;
	foreach_const (String, p, token) {
		char ch = *p;
		if (ch == 'r') {
			if (stringInfo.rawFlag) return false;
			stringInfo.rawFlag = true;
		} else if (ch == 'R') {
			if (stringInfo.rawFlag) return false;
			stringInfo.rawFlag = true;
			stringInfo.skipFirstEOLFlag = true;
		} else if (ch == 'b' || ch == 'B') {
			if (stringInfo.binaryFlag) return false;
			stringInfo.binaryFlag = true;
		} else {
			return false;
		}
	}
	return true;
}

Expr *Parser::ParseStream(Environment &env, Signal sig, Stream &stream)
{
	Value result;
	bool processEOLFlag = true;
	AutoPtr<Expr_Root> pExprRoot(new Expr_Root(stream.GetName()));
	SetSourceName(stream.GetName());
	for (;;) {
		int chRaw = stream.GetChar(sig);
		if (sig.IsSignalled()) {
			SetError(sig, ERR_CodecError, "stream can not be recognized as %s encoded string",
												stream.GetEncoding());
			return NULL;
		}
		char ch = (chRaw < 0)? '\0' : static_cast<unsigned char>(chRaw);
		Expr *pExpr = ParseChar(env, sig, ch);
		if (sig.IsSignalled()) {
			if (!sig.IsDetectEncoding()) return NULL;
			Value value = sig.GetValue();
			if (value.IsString()) {
				const char *encoding = value.GetString();
				AutoPtr<Object_codec> pObjCodec(new Object_codec(env));
				if (!pObjCodec->InstallCodec(sig, encoding, processEOLFlag)) {
					return NULL;
				}
				stream.SetCodec(pObjCodec.release());
			}
			sig.ClearSignal();
		} else if (pExpr != NULL) {
			pExprRoot->AddExpr(pExpr);
		}
		if (chRaw < 0) break;
	}
	return pExprRoot.release();
}

Expr *Parser::ParseStream(Environment &env, Signal sig, const char *pathName, const char *encoding)
{
	String pathNameMod;
	do {
		bool zippedFlag = false;
		std::string fileName;
		Directory::SplitFileName(pathName, NULL, &fileName);
		const char *extName = Directory::SeekExtName(fileName.c_str());
		std::string baseName = std::string(fileName.c_str(), extName);
		if (::strcasecmp(extName, ".gurc") == 0) {
			pathNameMod = OAL::JoinPathName(pathName, baseName.c_str());
			pathNameMod += ".gura";
			zippedFlag = true;
		} else if (::strcasecmp(extName, ".gurcw") == 0) {
			pathNameMod = OAL::JoinPathName(pathName, baseName.c_str());
			pathNameMod += ".guraw";
			zippedFlag = true;
		} else {
			pathNameMod = pathName;
		}
		if (zippedFlag && !env.ImportModules(sig, "zip", false, false)) return NULL;
	} while (0);
	AutoPtr<Stream> pStream(Directory::OpenStream(env, sig,
									pathNameMod.c_str(), Stream::ATTR_Readable));
	if (sig.IsSignalled()) return NULL;
	
	// encoding
	
	Expr *pExpr = ParseStream(env, sig, *pStream);
	return pExpr;
}

bool Parser::ParseString(Environment &env, Signal sig, ExprOwner &exprOwner,
							const char *sourceName, const char *str, size_t len)
{
	SetSourceName(sourceName);
	for ( ; ; str++, len--) {
		char ch = (len == 0)? '\0' : *str;
		Expr *pExpr = ParseChar(env, sig, ch);
		if (sig.IsSignalled()) {
			if (sig.IsDetectEncoding()) {
				sig.ClearSignal();
			} else {
				return false;
			}
		} else if (pExpr != NULL) {
			exprOwner.push_back(pExpr);
		}
		if (len == 0) break;
	}
	return true;
}

void Parser::EvalConsoleChar(Environment &env, Signal sig,
					ExprOwner &exprOwner, Stream *pConsole, char ch)
{
	char chConv = '\0';
	Codec_Decoder *pDecoder = pConsole->GetDecoder();
	Codec::Result rtn = pDecoder->FeedChar(ch, chConv);
	if (rtn != Codec::RESULT_Complete) return;
	do {
		Expr *pExpr = ParseChar(env, sig, chConv);
		if (sig.IsSignalled()) {
			if (sig.IsDetectEncoding()) {
				sig.ClearSignal();
			} else {
				pConsole->PrintSignal(sig, sig);
				sig.ClearSignal();
				Reset();
			}
		} else if (pExpr != NULL) {
			Value result = pExpr->Exec(env, sig);
			if (sig.IsSignalled()) {
				if (sig.IsReqSaveHistory()) {
					
				} else {
					pConsole->PrintSignal(sig, sig);
				}
				sig.ClearSignal();
				Expr::Delete(pExpr);
			} else {
				if (env.GetEchoFlag() && result.IsValid()) {
					pConsole->Println(sig, result.ToString(sig).c_str());
				}
				exprOwner.push_back(pExpr);
			}
		}
	} while (pDecoder->FollowChar(chConv));
}

const Parser::ElemTypeInfo Parser::_elemTypeInfoTbl[] = {
	{ ETYPE_Begin,				 1, "Begin",			"[Bgn]"		},	// B
	{ ETYPE_Assign,				 2, "Assign",			"="			},	// =
	{ ETYPE_AssignPlus,			 2, "AssignPlus",		"+="		},
	{ ETYPE_AssignMinus,		 2, "AssignMinus",		"-="		},
	{ ETYPE_AssignMultiply,		 2, "AssignMultiply",	"*="		},
	{ ETYPE_AssignDivide,		 2, "AssignDivide",		"/="		},
	{ ETYPE_AssignModulo,		 2, "AssignModulo",		"%="		},
	{ ETYPE_AssignPower,		 2, "AssignPower",		"**="		},
	{ ETYPE_AssignOr,			 2, "AssignOr",			"|="		},
	{ ETYPE_AssignAnd,			 2, "AssignAnd",		"&="		},
	{ ETYPE_AssignXor,			 2, "AssignXor",		"^="		},
	{ ETYPE_AssignShiftL,		 2, "AssignShiftL",		"<<="		},
	{ ETYPE_AssignShiftR,		 2, "AssignShiftR",		">>="		},
	{ ETYPE_DictAssign,			 2, "DictAssign",		"=>"		},
	{ ETYPE_OrOr,				 3, "OrOr",				"||"		},	// ||
	{ ETYPE_AndAnd,				 4, "AndAnd",			"&&"		},	// &&
	{ ETYPE_Not,				 5, "Not",				"!"			},	// !
	{ ETYPE_ContainCheck,		 6, "ContainCheck",		"in"		},	// in
	{ ETYPE_Less,				 7, "Less",				"<"			},	// <
	{ ETYPE_Greater,			 7, "Greater",			">"			},
	{ ETYPE_LessEq,	 			 7, "LessEq",			"<="		},
	{ ETYPE_GreaterEq,			 7, "GreaterEq",		">="		},
	{ ETYPE_Compare,			 7, "Compare",			"<=>"		},
	{ ETYPE_Equal,				 7, "Equal",			"=="		},
	{ ETYPE_NotEqual,			 7, "NotEqual",			"!="		},
	{ ETYPE_Sequence,			 8, "Sequence",			".."		},	// ..
	{ ETYPE_Or,					 9, "Or",				"|"			},	// |
	{ ETYPE_Xor,				10, "Xor",				"^"			},	// ^
	{ ETYPE_And,				11, "And",				"&"			},	// &
	{ ETYPE_ShiftL,				12, "ShiftL",			"<<"		},	// <<
	{ ETYPE_ShiftR,				12, "ShiftR",			">>"		},
	{ ETYPE_Plus,				13, "Plus",				"+"			},	// +
	{ ETYPE_Minus,				13, "Minus",			"-"			},
	{ ETYPE_Multiply,			14, "Multiply",			"*"			},	// *
	{ ETYPE_Divide,				14, "Divide",			"/"			},
	{ ETYPE_Modulo,				14, "Modulo",			"%"			},
	{ ETYPE_ModuloModulo,		14, "ModuloModulo",		"%%"		},
	{ ETYPE_Question,			14, "Question",			"?"			},
	{ ETYPE_Invert,				15, "Invert",			"~"			},	// ~
	{ ETYPE_Power,				16, "Power",			"**"		},	// **
	{ ETYPE_Quote,				17, "Quote",			"`"			},	// `
	{ ETYPE_Force,				17, "Force",			"!!"		},
	{ ETYPE_Colon,				18, "Colon",			":"			},	// :
	{ ETYPE_ColonAfterSuffix,	19, "ColonAfterSuffix",	":"			},	// *:
	{ ETYPE_Dot,				20, "Dot",				"."			},	// .
	{ ETYPE_ColonColon,			20, "ColonColon",		"::"		},
	{ ETYPE_ColonAsterisk,		20, "ColonAsterisk",	":*"		},
	{ ETYPE_ColonAnd,			20, "ColonAnd",			":&"		},
	{ ETYPE_LParenthesis,		21, "LParenthesis",		"("			},	// (
	{ ETYPE_RParenthesis,		22, "RParenthesis",		")"			},	// )
	{ ETYPE_LBrace,				21, "LBrace",			"{"			},
	{ ETYPE_RBrace,				22, "RBrace",			"}"			},
	{ ETYPE_LBlockParam,		21, "LBlockParam",		"|"			},
	{ ETYPE_RBlockParam,		22, "RBlockParam",		"|"			},
	{ ETYPE_LBracket,			23, "LBracket",			"["			},	// [
	{ ETYPE_RBracket,			24, "RBracket",			"]"			},	// ]
	{ ETYPE_Comma,				25, "Comma",			","			},	// ,
	{ ETYPE_Semicolon,			25, "Semicolon",		";"			},
	{ ETYPE_EOL,				26, "EOL",				"[EOL]"		},	// \n
	{ ETYPE_Number,				27, "Number",			"[Num]"		},	// V
	{ ETYPE_ImagNumber,			27, "ImagNumber",		"[iNm]"		},
	{ ETYPE_String,				27, "String",			"[Str]"		},
	{ ETYPE_Binary,				27, "Binary",			"[Bin]"		},
	{ ETYPE_Symbol,				28, "Symbol",			"[Sym]"		},	// S
	{ ETYPE_EOF,				29, "EOF",				"[EOF]"		},	// E
	{ ETYPE_Expr,				-1, "Expr",				"[Exp]"		},
	{ ETYPE_Unknown,			-1, "Unknown",			"[unk]"		},
};

Parser::Precedence Parser::LookupPrec(ElemType elemTypeLeft, ElemType elemTypeRight)
{
	const ElemTypeInfo *pInfoLeft = LookupElemTypeInfo(elemTypeLeft);
	const ElemTypeInfo *pInfoRight = LookupElemTypeInfo(elemTypeRight);
	if (pInfoLeft == NULL || pInfoRight == NULL) return PREC_Error;
	return _LookupPrec(pInfoLeft->index, pInfoRight->index);
}

Parser::Precedence Parser::_LookupPrec(int indexLeft, int indexRight)
{
	const Precedence LT = PREC_LT, EQ = PREC_EQ, GT = PREC_GT, xx = PREC_Error;
	const static Precedence precTbl[][29] = {
		/*         B   =  ||  &&   !  in   <  ..   |   ^   &  <<   +   *   ~  **   `   :  *:   .   (   )   [   ]   ,  \n   V   S   E */
		/* e */ { xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx, xx },
		/* B */ { xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, xx, LT, xx, EQ, EQ, LT, LT, EQ },
		/* = */ { xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ||*/ { xx, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* &&*/ { xx, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ! */ { xx, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* in*/ { xx, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* < */ { xx, LT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ..*/ { xx, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* | */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ^ */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* & */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* <<*/ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* + */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, GT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* * */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, GT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ~ */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ***/ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* ` */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, LT, LT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* : */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, GT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* *:*/ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, GT, GT, LT, GT, GT, GT, LT, LT, GT },
		/* . */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, GT, GT, GT, GT, GT, GT, GT, GT, LT, LT, GT },
		/* ( */ { xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, EQ, LT, EQ, EQ, EQ, LT, LT, xx },
		/* ) */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT },
		/* [ */ { xx, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, LT, EQ, LT, EQ, EQ, EQ, LT, LT, xx },
		/* ] */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT },
		/* , */ { xx, LT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, xx, GT, GT, GT, GT },
		/* \n*/ { xx, LT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT },
		/* V */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, LT, xx, GT },
		/* S */ { xx, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, GT, xx, xx, GT },
	};                                  
	return precTbl[indexLeft][indexRight - 1];
}

Expr *Parser::FeedElement(Environment &env, Signal sig, const Element &elem)
{
	//::printf("FeedElement(%s)\n", elem.GetTypeSymbol());
	Expr *pExpr = NULL;
	for (;;) {
		ElementStack::reverse_iterator pElemTop =
								_elemStack.SeekTerminal(_elemStack.rbegin());
		//::printf("%s  << %s\n",
		//				_elemStack.ToString().c_str(), elem.GetTypeSymbol());
		Precedence prec = LookupPrecFast(pElemTop->GetType(), elem.GetType());
		if (pElemTop->IsType(ETYPE_Begin) && elem.IsSeparatorElement()) {
			size_t cntElem = _elemStack.size();
			if (cntElem == 1) {
				// nothing to do
			} else if (cntElem == 2 && _elemStack[1].IsType(ETYPE_Expr)) {
				pExpr = _elemStack[1].GetExpr();
				_elemStack.pop_back();
			} else {
				// something's wrong
				SetError_InvalidElement(sig, __LINE__);
				InitStack();
			}
			break;
		} else if (prec == PREC_LT || prec == PREC_EQ) {
			Element &elemLast = _elemStack.back();
			if (elemLast.IsType(ETYPE_String) && elem.IsType(ETYPE_String)) {
				elemLast.AddString(elem.GetString());
			} else if (elemLast.IsType(ETYPE_Binary) && elem.IsType(ETYPE_Binary)) {
				elemLast.AddString(elem.GetString());
			} else {
				_elemStack.push_back(elem);
			}
			break;
		} else if (prec == PREC_GT) {
			ElementStack::reverse_iterator pElemLeft;
			ElementStack::reverse_iterator pElemRight = pElemTop;
			while (1) {
				pElemLeft = _elemStack.SeekTerminal(pElemRight + 1);
				if (LookupPrecFast(pElemLeft->GetType(), pElemRight->GetType())
																	== PREC_LT) {
					pElemLeft--;
					break;
				}
				pElemRight = pElemLeft;
			}
			size_t cntElem = std::distance(_elemStack.rbegin(), pElemLeft) + 1;
			bool rtn;
			if (cntElem == 1) {
				rtn = ReduceOneElem(env, sig);
			} else if (cntElem == 2) {
				rtn = ReduceTwoElems(env, sig);
			} else if (cntElem == 3) {
				rtn = ReduceThreeElems(env, sig);
			} else if (cntElem == 4) {
				rtn = ReduceFourElems(env, sig);
			} else if (cntElem == 5) {
				rtn = ReduceFiveElems(env, sig);
			} else {
				SetError_InvalidElement(sig, __LINE__);
				rtn = false;
			}
			if (!rtn) {
				InitStack();
				break;
			}
		} else {
			SetError_InvalidElement(sig, __LINE__);
			InitStack();
			break;
		}
	}
	return pExpr;
}

bool Parser::ReduceOneElem(Environment &env, Signal sig)
{
	Expr *pExpr;
	Element &elem1 = _elemStack.Peek(0);
	if (elem1.IsType(ETYPE_Number)) {
		DBGPARSER(::printf("Reduce: Expr -> Number\n"));
		pExpr = new Expr_Value(elem1.GetNumber());
	} else if (elem1.IsType(ETYPE_ImagNumber)) {
		DBGPARSER(::printf("Reduce: Expr -> ImagNumber\n"));
		pExpr = new Expr_Value(Complex(0, elem1.GetNumber()));
	} else if (elem1.IsType(ETYPE_String)) {
		DBGPARSER(::printf("Reduce: Expr -> String\n"));
		pExpr = new Expr_String(elem1.GetString());
	} else if (elem1.IsType(ETYPE_Binary)) {
		DBGPARSER(::printf("Reduce: Expr -> Binary\n"));
		Value value(new Object_binary(env,
					Binary(elem1.GetString(), elem1.GetStringSize()), false));
		pExpr = new Expr_Value(value);
	} else if (elem1.IsType(ETYPE_Symbol)) {
		DBGPARSER(::printf("Reduce: Expr -> Symbol\n"));
		const Symbol *pSymbol = Symbol::Add(elem1.GetString());
		pExpr = new Expr_Symbol(pSymbol);
	} else if (elem1.IsType(ETYPE_Multiply)) {
		DBGPARSER(::printf("Reduce: Expr -> '*'\n"));
		pExpr = new Expr_Symbol(Gura_Symbol(Char_Multiply));
	} else if (elem1.IsType(ETYPE_Question)) {
		DBGPARSER(::printf("Reduce: Expr -> '?'\n"));
		pExpr = new Expr_Symbol(Gura_Symbol(Char_Question));
	} else {
		SetError_InvalidElement(sig, __LINE__);
		return false;
	}
	int lineNoTop = elem1.GetLineNo();
	_elemStack.pop_back();
	pExpr->SetLineNo(lineNoTop, GetLineNo());
	_elemStack.push_back(Element(ETYPE_Expr, pExpr));
	return true;
}

bool Parser::ReduceTwoElems(Environment &env, Signal sig)
{
	Expr *pExpr;
	Element &elem1 = _elemStack.Peek(1);
	Element &elem2 = _elemStack.Peek(0);
	if (elem1.IsType(ETYPE_LParenthesis)) {
		if (elem2.IsType(ETYPE_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> '(' ')'\n"));
			Expr_Lister *pExprLister =
						dynamic_cast<Expr_Lister *>(elem1.GetExpr());
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
			}
			pExpr = pExprLister;
		} else if (elem2.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '(' -> '(' EOL\n"));
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_LBracket)) {
		if (elem2.IsType(ETYPE_RBracket)) {
			DBGPARSER(::printf("Reduce: Expr -> '[' ']'\n"));
			Expr_Lister *pExprLister =
						dynamic_cast<Expr_Lister *>(elem1.GetExpr());
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
			}
			pExpr = pExprLister;
		} else if (elem2.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '[' -> '[' EOL\n"));
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_LBrace)) {
		if (elem2.IsType(ETYPE_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> '{' '}'\n"));
			Expr_Block *pExprBlock =
						dynamic_cast<Expr_Block *>(elem1.GetExpr());
			if (pExprBlock == NULL) {
				pExprBlock = new Expr_Block();
			}
			pExpr = pExprBlock;
		} else if (elem2.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '{' -> '{' EOL\n"));
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_LBlockParam)) {
		if (elem2.IsType(ETYPE_RBlockParam)) {
			// this is a special case of reducing
			DBGPARSER(::printf("do (Reduce: Expr -> '|' '|') "
					"and then attach the Expr to the preceeding LBrace\n"));
			Expr_BlockParam *pExprBlockParam =
						dynamic_cast<Expr_BlockParam *>(elem1.GetExpr());
			if (pExprBlockParam == NULL) {
				pExprBlockParam = new Expr_BlockParam();
			}
			_elemStack.pop_back();
			_elemStack.pop_back();
			Element &elemPrev = _elemStack.Peek(0);
			if (elemPrev.IsType(ETYPE_LBrace)) {
				Expr_Block *pExprBlock =
							dynamic_cast<Expr_Block *>(elemPrev.GetExpr());
				if (pExprBlock == NULL) {
					pExprBlock = new Expr_Block();
					elemPrev.SetExpr(pExprBlock);
				}
				pExprBlock->SetParam(pExprBlockParam);
			} else {
				Expr::Delete(pExprBlockParam);
				SetError(sig, ERR_SyntaxError, "invalid placement of block parameter");
				return false;
			}
			return true;
		} else if (elem2.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '|' -> '|' EOL\n"));
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr) && elem2.IsType(ETYPE_Symbol)) {
		// this is a special case of reducing
		DBGPARSER(::printf("Reduce: Expr Expr -> Expr Symbol\n"));
		const Symbol *pSymbol = Symbol::Add(elem2.GetString());
		pExpr = new Expr_Symbol(pSymbol);
		int lineNoTop = _elemStack.Peek(0).GetLineNo();
		_elemStack.pop_back();
		pExpr->SetLineNo(lineNoTop, GetLineNo());
		_elemStack.push_back(Element(ETYPE_Expr, pExpr));
		return true;
	} else if (elem2.IsType(ETYPE_Expr)) {
		if (elem1.IsType(ETYPE_Quote)) {
			DBGPARSER(::printf("Reduce: Expr -> ''' Expr\n"));
			pExpr = new Expr_Quote(elem2.GetExpr());
		} else if (elem1.IsType(ETYPE_Force)) {
			DBGPARSER(::printf("Reduce: Expr -> '!!' Expr\n"));
			pExpr = new Expr_Force(elem2.GetExpr());
		} else if (elem1.IsType(ETYPE_Plus)) {
			DBGPARSER(::printf("Reduce: Expr -> '+' Expr\n"));
			pExpr = new Expr_UnaryOp(env.GetOpFunc(OPTYPE_Pos), elem2.GetExpr(), false);
		} else if (elem1.IsType(ETYPE_Minus)) {
			DBGPARSER(::printf("Reduce: Expr -> '-' Expr\n"));
			pExpr = new Expr_UnaryOp(env.GetOpFunc(OPTYPE_Neg), elem2.GetExpr(), false);
		} else if (elem1.IsType(ETYPE_Invert)) {
			DBGPARSER(::printf("Reduce: Expr -> '~' Expr\n"));
			pExpr = new Expr_UnaryOp(env.GetOpFunc(OPTYPE_Invert), elem2.GetExpr(), false);
		} else if (elem1.IsType(ETYPE_Not)) {
			DBGPARSER(::printf("Reduce: Expr -> '!' Expr\n"));
			pExpr = new Expr_UnaryOp(env.GetOpFunc(OPTYPE_Not), elem2.GetExpr(), false);
		} else if (elem1.IsType(ETYPE_Modulo)) {
			DBGPARSER(::printf("Reduce: Expr -> '%' Expr\n"));
			if (elem2.GetExpr()->IsBlock()) {
				Expr *pExprCar = new Expr_Symbol(Gura_Symbol(Char_Modulo));
				Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(elem2.GetExpr());
				Expr_Caller *pExprCaller =
								new Expr_Caller(pExprCar, NULL, pExprBlock);
				pExpr = pExprCaller;
			} else {
				SetError_InvalidElement(sig, __LINE__);
				return false;
			}
		} else if (elem1.IsType(ETYPE_ModuloModulo)) {
			DBGPARSER(::printf("Reduce: Expr -> '%%' Expr\n"));
			if (elem2.GetExpr()->IsBlock()) {
				Expr *pExprCar = new Expr_Symbol(Gura_Symbol(Char_ModuloModulo));
				Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(elem2.GetExpr());
				Expr_Caller *pExprCaller =
								new Expr_Caller(pExprCar, NULL, pExprBlock);
				pExpr = pExprCaller;
			} else {
				SetError_InvalidElement(sig, __LINE__);
				return false;
			}
		} else if (elem1.IsType(ETYPE_And)) {
			DBGPARSER(::printf("Reduce: Expr -> '&' Expr\n"));
			if (elem2.GetExpr()->IsBlock()) {
				Expr *pExprCar = new Expr_Symbol(Gura_Symbol(Char_And));
				Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(elem2.GetExpr());
				Expr_Caller *pExprCaller =
								new Expr_Caller(pExprCar, NULL, pExprBlock);
				pExpr = pExprCaller;
			} else if (elem2.GetExpr()->IsSymbol()) {
				pExpr = new Expr_Prefix(elem2.GetExpr(), Gura_Symbol(Char_And));
			} else {
				SetError_InvalidElement(sig, __LINE__);
				return false;
			}
		} else if (elem1.IsType(ETYPE_Multiply)) {
			DBGPARSER(::printf("Reduce: Expr -> '*' Expr\n"));
			pExpr = new Expr_Prefix(elem2.GetExpr(), Gura_Symbol(Char_Multiply));
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr)) {
		if (elem2.IsType(ETYPE_Plus)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '+'\n"));
			pExpr = new Expr_Suffix(elem1.GetExpr(), Gura_Symbol(Char_Plus));
		} else if (elem2.IsType(ETYPE_Multiply)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '*'\n"));
			pExpr = new Expr_Suffix(elem1.GetExpr(), Gura_Symbol(Char_Multiply));
		} else if (elem2.IsType(ETYPE_Question)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '?'\n"));
			pExpr = new Expr_Suffix(elem1.GetExpr(), Gura_Symbol(Char_Question));
		} else if (elem2.IsType(ETYPE_Modulo)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '%'\n"));
			pExpr = new Expr_Suffix(elem1.GetExpr(), Gura_Symbol(Char_Modulo));
		} else if (elem2.IsType(ETYPE_Sequence)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr ..\n"));
			pExpr = new Expr_UnaryOp(env.GetOpFunc(OPTYPE_SequenceInf), elem1.GetExpr(), true);
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else {
		SetError_InvalidElement(sig, __LINE__);
		return false;
	}
	int lineNoTop = elem1.GetLineNo();
	_elemStack.pop_back();
	_elemStack.pop_back();
	pExpr->SetLineNo(lineNoTop, GetLineNo());
	_elemStack.push_back(Element(ETYPE_Expr, pExpr));
	return true;
}

bool Parser::ReduceThreeElems(Environment &env, Signal sig)
{
	Expr *pExpr;
	Element &elem1 = _elemStack.Peek(2);
	Element &elem2 = _elemStack.Peek(1);
	Element &elem3 = _elemStack.Peek(0);
	if (elem1.IsType(ETYPE_LParenthesis) && elem2.IsType(ETYPE_Expr)) {
		Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(elem1.GetExpr());
		if (elem3.IsType(ETYPE_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> '(' Expr ')'\n"));
			if (pExprLister == NULL) {
				pExpr = elem2.GetExpr();	// treat expr as non-list
			} else {
				pExprLister->AddExpr(elem2.GetExpr());
				pExpr = pExprLister;
			}
		} else if (elem3.IsType(ETYPE_Comma) || elem3.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '(' -> '(' Expr ','\n"));
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
				elem1.SetExpr(pExprLister);
			}
			pExprLister->AddExpr(elem2.GetExpr());
			_elemStack.pop_back();
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_LBracket) && elem2.IsType(ETYPE_Expr)) {
		Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(elem1.GetExpr());
		if (elem3.IsType(ETYPE_RBracket)) {
			DBGPARSER(::printf("Reduce: Expr -> '[' Expr ']'\n"));
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
			}
			pExprLister->AddExpr(elem2.GetExpr());
			pExpr = pExprLister;
		} else if (elem3.IsType(ETYPE_Comma) || elem3.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '[' -> '[' Expr ','\n"));
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
				elem1.SetExpr(pExprLister);
			}
			pExprLister->AddExpr(elem2.GetExpr());
			_elemStack.pop_back();
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr) && elem2.IsType(ETYPE_LParenthesis)) {
		if (elem3.IsType(ETYPE_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '(' ')'\n"));
			Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(elem2.GetExpr());
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
			}
			Expr_Caller *pExprCaller = 
						new Expr_Caller(elem1.GetExpr(), pExprLister, NULL);
			pExpr = pExprCaller;
		} else if (elem3.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '(' -> Expr '(' EOL\n"));
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr) && elem2.IsType(ETYPE_LBrace)) {
		if (elem3.IsType(ETYPE_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '{' '}'\n"));
			Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(elem2.GetExpr());
			if (elem1.GetExpr()->IsCaller()) {
				Expr_Caller *pExprCaller =
								dynamic_cast<Expr_Caller *>(elem1.GetExpr());
				if (pExprBlock == NULL) {
					pExprBlock = new Expr_Block();
				}
				pExprCaller->GetLastTrailer()->SetBlock(pExprBlock);
				pExpr = pExprCaller;
			} else {
				if (pExprBlock == NULL) {
					pExprBlock = new Expr_Block();
				}
				Expr_Caller *pExprCaller =
							new Expr_Caller(elem1.GetExpr(), NULL, pExprBlock);
				pExpr = pExprCaller;
			}
		} else if (elem3.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '{' -> Expr '{' EOL\n"));
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr) && elem2.IsType(ETYPE_LBracket)) {
		if (elem3.IsType(ETYPE_RBracket)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '[' ']'\n"));
			Expr *pExprTgt = elem1.GetExpr();
			Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(elem2.GetExpr());
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
			}
			pExpr = new Expr_Indexer(pExprTgt, pExprLister);
		} else if (elem3.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '[' -> Expr '[' EOL\n"));
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_LBrace) && elem2.IsType(ETYPE_Expr)) {
		Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(elem1.GetExpr());
		if (elem3.IsType(ETYPE_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> '{' Expr '}'\n"));
			if (pExprBlock == NULL) {
				pExprBlock = new Expr_Block();
			}
			pExprBlock->AddExpr(elem2.GetExpr());
			pExpr = pExprBlock;
		} else if (elem3.IsType(ETYPE_Comma) ||
					elem3.IsType(ETYPE_Semicolon) || elem3.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '{' -> '{' Expr ','\n"));
			if (pExprBlock == NULL) {
				pExprBlock = new Expr_Block();
				elem1.SetExpr(pExprBlock);
			}
			pExprBlock->AddExpr(elem2.GetExpr());
			_elemStack.pop_back();
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_LBlockParam) && elem2.IsType(ETYPE_Expr)) {
		Expr_BlockParam *pExprBlockParam = dynamic_cast<Expr_BlockParam *>(elem1.GetExpr());
		if (elem3.IsType(ETYPE_RBlockParam)) {
			// this is a special case of reducing
			DBGPARSER(::printf("do (Reduce: Expr -> '|' Expr '|') "
					"and then attach the Expr to the preceeding LBrace\n"));
			if (pExprBlockParam == NULL) {
				pExprBlockParam = new Expr_BlockParam();
			}
			pExprBlockParam->AddExpr(elem2.GetExpr());
			_elemStack.pop_back();
			_elemStack.pop_back();
			_elemStack.pop_back();
			Element &elemPrev = _elemStack.Peek(0);
			if (elemPrev.IsType(ETYPE_LBrace)) {
				Expr_Block *pExprBlock =
							dynamic_cast<Expr_Block *>(elemPrev.GetExpr());
				if (pExprBlock == NULL) {
					pExprBlock = new Expr_Block();
					elemPrev.SetExpr(pExprBlock);
				}
				pExprBlock->SetParam(pExprBlockParam);
			} else {
				Expr::Delete(pExprBlockParam);
				SetError(sig, ERR_SyntaxError, "invalid placement of block parameter");
				return false;
			}
			return true;
		} else if (elem3.IsType(ETYPE_Comma) ||
					elem3.IsType(ETYPE_Semicolon) || elem3.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '|' -> '|' Expr ','\n"));
			if (pExprBlockParam == NULL) {
				pExprBlockParam = new Expr_BlockParam();
				elem1.SetExpr(pExprBlockParam);
			}
			pExprBlockParam->AddExpr(elem2.GetExpr());
			_elemStack.pop_back();
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr) && elem3.IsType(ETYPE_Expr)) {
		Expr *pExprLeft = elem1.GetExpr();
		Expr *pExprRight = elem3.GetExpr();
		if (elem2.IsType(ETYPE_Plus)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr + Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Plus), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Minus)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr - Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Minus), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Multiply)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr * Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Multiply), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Divide)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr / Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Divide), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Modulo)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr % Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Modulo), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Power)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr ** Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Power), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Equal)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr == Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Equal), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_NotEqual)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr != Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_NotEqual), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Less)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr < Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Less), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Greater)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr > Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Greater), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_LessEq)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr <= Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_LessEq), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_GreaterEq)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr >= Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_GreaterEq), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Compare)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr <=> Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Compare), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_ContainCheck)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr in Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_ContainCheck), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Assign)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr = Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, NULL);
		} else if (elem2.IsType(ETYPE_AssignPlus)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr += Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_Plus));
		} else if (elem2.IsType(ETYPE_AssignMinus)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr -= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_Minus));
		} else if (elem2.IsType(ETYPE_AssignMultiply)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr *= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_Multiply));
		} else if (elem2.IsType(ETYPE_AssignDivide)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr /= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_Divide));
		} else if (elem2.IsType(ETYPE_AssignModulo)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr %= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_Modulo));
		} else if (elem2.IsType(ETYPE_AssignPower)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr **= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_Power));
		} else if (elem2.IsType(ETYPE_AssignOr)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr |= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_Or));
		} else if (elem2.IsType(ETYPE_AssignAnd)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr &= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_And));
		} else if (elem2.IsType(ETYPE_AssignXor)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr ^= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_Xor));
		} else if (elem2.IsType(ETYPE_AssignShiftL)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr <<= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_ShiftL));
		} else if (elem2.IsType(ETYPE_AssignShiftR)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr >>= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOpFunc(OPTYPE_ShiftR));
		} else if (elem2.IsType(ETYPE_DictAssign)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr => Expr\n"));
			pExpr = new Expr_DictAssign(pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Colon) || elem2.IsType(ETYPE_ColonAfterSuffix)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr : Expr\n"));
			Expr *pExprDst = pExprLeft;
			if (pExprDst->IsSuffix()) {
				pExprDst = dynamic_cast<Expr_Suffix *>(pExprDst)->GetChild();
			}
			if (pExprDst->IsIndexer()) {
				pExprDst = dynamic_cast<Expr_Indexer *>(pExprDst)->GetCar();
			}
			if (pExprRight->IsSymbol()) {
				const Symbol *pSymbol =
						dynamic_cast<Expr_Symbol *>(pExprRight)->GetSymbol();
				SymbolList *pAttrFront = NULL;
				if (pExprDst->IsSymbol()) {
					Expr_Symbol *pExprSymbol =
									dynamic_cast<Expr_Symbol *>(pExprDst);
					pExprSymbol->AddAttr(pSymbol);
					pAttrFront = &pExprSymbol->GetAttrFront();
				} else if (pExprDst->IsCaller()) {
					Expr_Caller *pExprCaller =
									dynamic_cast<Expr_Caller *>(pExprDst);
					Expr_Caller *pExprTrailer =
									pExprCaller->GetLastTrailer();
					pExprTrailer->AddAttr(pSymbol);
					pAttrFront = &pExprTrailer->GetAttrFront();
				} else {
					SetError_InvalidElement(sig, __LINE__);
					return false;
				}
				if (pAttrFront->empty()) pAttrFront->push_back(pSymbol);
				pExpr = pExprLeft;
				Expr::Delete(pExprRight);
			} else if (pExprRight->IsMember()) {
				SymbolList *pAttrFront = NULL;
				if (pExprDst->IsSymbol()) {
					Expr_Symbol *pExprSymbol =
									dynamic_cast<Expr_Symbol *>(pExprDst);
					pAttrFront = &pExprSymbol->GetAttrFront();
				} else if (pExprDst->IsCaller()) {
					Expr_Caller *pExprCaller =
									dynamic_cast<Expr_Caller *>(pExprDst);
					Expr_Caller *pExprTrailer =
									pExprCaller->GetLastTrailer();
					pAttrFront = &pExprTrailer->GetAttrFront();
				} else {
					SetError_InvalidElement(sig, __LINE__);
					return false;
				}
				if (!pAttrFront->empty()) {
					sig.SetError(ERR_SyntaxError,
							"value type must be specified as a first attribute");
					return false;
				}
				if (!pExprRight->GetChainedSymbolList(*pAttrFront)) {
					sig.SetError(ERR_SyntaxError, "invalid declaration of value type");
					return false;
				}
				pExpr = pExprLeft;
				Expr::Delete(pExprRight);
			} else if (pExprRight->IsLister()) {
				ExprList &exprList =
							dynamic_cast<Expr_Lister *>(pExprRight)->GetExprOwner();
				if (pExprDst->IsSymbol()) {
					sig.SetError(ERR_TypeError,
									"symbols cannot declare optional attributes");
					return false;
				} else if (pExprDst->IsCaller()) {
					Expr_Caller *pExprCaller =
									dynamic_cast<Expr_Caller *>(pExprDst);
					pExprCaller = pExprCaller->GetLastTrailer();
					foreach (ExprList, ppExpr, exprList) {
						Expr *pExpr = *ppExpr;
						if (!pExpr->IsSymbol()) {
							SetError_InvalidElement(sig, __LINE__);
							return false;
						}
						const Symbol *pSymbol =
								dynamic_cast<Expr_Symbol *>(pExpr)->GetSymbol();
						pExprCaller->AddAttrOpt(pSymbol);
					}
				} else {
					SetError_InvalidElement(sig, __LINE__);
					return false;
				}
				pExpr = pExprLeft;
				Expr::Delete(pExprRight);
			} else {
				SetError_InvalidElement(sig, __LINE__);
				return false;
			}
		} else if (elem2.IsType(ETYPE_Dot)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr . Expr\n"));
			pExpr = new Expr_Member(pExprLeft, pExprRight, Expr_Member::MODE_Normal);
		} else if (elem2.IsType(ETYPE_ColonColon)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr :: Expr\n"));
			pExpr = new Expr_Member(pExprLeft, pExprRight, Expr_Member::MODE_MapToList);
		} else if (elem2.IsType(ETYPE_ColonAsterisk)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr :* Expr\n"));
			pExpr = new Expr_Member(pExprLeft, pExprRight, Expr_Member::MODE_MapToIter);
		} else if (elem2.IsType(ETYPE_ColonAnd)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr :& Expr\n"));
			pExpr = new Expr_Member(pExprLeft, pExprRight, Expr_Member::MODE_MapAlong);
		} else if (elem2.IsType(ETYPE_OrOr)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr || Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_OrOr), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_AndAnd)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr && Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_AndAnd), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Or)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr | Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Or), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_And)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr & Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_And), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Xor)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr ^ Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Xor), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_ShiftL)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr << Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_ShiftL), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_ShiftR)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr >> Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_ShiftR), pExprLeft, pExprRight);
		} else if (elem2.IsType(ETYPE_Sequence)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr .. Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOpFunc(OPTYPE_Sequence), pExprLeft, pExprRight);
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else {
		SetError_InvalidElement(sig, __LINE__);
		return false;
	}
	int lineNoTop = elem1.GetLineNo();
	_elemStack.pop_back();
	_elemStack.pop_back();
	_elemStack.pop_back();
	pExpr->SetLineNo(lineNoTop, GetLineNo());
	_elemStack.push_back(Element(ETYPE_Expr, pExpr));
	return true;
}

bool Parser::ReduceFourElems(Environment &env, Signal sig)
{
	Expr *pExpr;
	Element &elem1 = _elemStack.Peek(3);
	Element &elem2 = _elemStack.Peek(2);
	Element &elem3 = _elemStack.Peek(1);
	Element &elem4 = _elemStack.Peek(0);
	if (elem1.IsType(ETYPE_Expr) && elem2.IsType(ETYPE_Expr) &&
											elem3.IsType(ETYPE_LParenthesis)) {
		if (elem4.IsType(ETYPE_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr Expr '(' ')'\n"));
			Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(elem3.GetExpr());
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
			}
			Expr_Caller *pExprCaller = 
						new Expr_Caller(elem2.GetExpr(), pExprLister, NULL);
			if (!elem1.GetExpr()->IsCaller()) {
				SetError_InvalidElement(sig, __LINE__);
				return false;
			}
			Expr_Caller *pExprCallerPrev =
							dynamic_cast<Expr_Caller *>(elem1.GetExpr());
			pExprCallerPrev->GetLastTrailer()->SetTrailer(pExprCaller);
			pExpr = pExprCallerPrev;
		} else if (elem4.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr Expr '(' -> Expr Expr '(' EOL\n"));
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr) && elem2.IsType(ETYPE_Expr) &&
												elem3.IsType(ETYPE_LBrace)) {
		if (elem4.IsType(ETYPE_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr Expr '{' '}'\n"));
			Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(elem3.GetExpr());
			if (pExprBlock == NULL) {
				pExprBlock = new Expr_Block();
			}
			Expr_Caller *pExprCaller;
			if (elem2.GetExpr()->IsCaller()) {
				pExprCaller = dynamic_cast<Expr_Caller *>(elem2.GetExpr());
				pExprCaller->GetLastTrailer()->SetBlock(pExprBlock);
			} else {
				pExprCaller = new Expr_Caller(elem2.GetExpr(), NULL, pExprBlock);
			}
			if (!elem1.GetExpr()->IsCaller()) {
				SetError_InvalidElement(sig, __LINE__);
				return false;
			}
			Expr_Caller *pExprCallerPrev =
							dynamic_cast<Expr_Caller *>(elem1.GetExpr());
			pExprCallerPrev->GetLastTrailer()->SetTrailer(pExprCaller);
			pExpr = pExprCallerPrev;
		} else if (elem4.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr Expr '{' -> Expr Expr '{' EOL\n"));
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr) &&
				elem2.IsType(ETYPE_LParenthesis) && elem3.IsType(ETYPE_Expr)) {
		Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(elem2.GetExpr());
		if (elem4.IsType(ETYPE_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '(' Expr ')'\n"));
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
			}
			pExprLister->AddExpr(elem3.GetExpr());
			Expr_Caller *pExprCaller =
						new Expr_Caller(elem1.GetExpr(), pExprLister, NULL);
			pExpr = pExprCaller;
		} else if (elem4.IsType(ETYPE_Comma) || elem4.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '(' -> Expr '(' Expr ','\n"));
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
				elem2.SetExpr(pExprLister);
			}
			pExprLister->AddExpr(elem3.GetExpr());
			_elemStack.pop_back();
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr) &&
				elem2.IsType(ETYPE_LBrace) && elem3.IsType(ETYPE_Expr)) {
		Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(elem2.GetExpr());
		if (elem4.IsType(ETYPE_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '{' Expr '}'\n"));
			if (pExprBlock == NULL) {
				pExprBlock = new Expr_Block();
			}
			pExprBlock->AddExpr(elem3.GetExpr());
			if (elem1.GetExpr()->IsCaller()) {
				Expr_Caller *pExprCaller =
								dynamic_cast<Expr_Caller *>(elem1.GetExpr());
				pExprCaller->GetLastTrailer()->SetBlock(pExprBlock);
				pExpr = pExprCaller;
			} else {
				Expr_Caller *pExprCaller =
							new Expr_Caller(elem1.GetExpr(), NULL, pExprBlock);
				pExpr = pExprCaller;
			}
		} else if (elem4.IsType(ETYPE_Comma) ||
					elem4.IsType(ETYPE_Semicolon) || elem4.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '{' -> Expr '{' Expr ','\n"));
			if (pExprBlock == NULL) {
				pExprBlock = new Expr_Block();
				elem2.SetExpr(pExprBlock);
			}
			pExprBlock->AddExpr(elem3.GetExpr());
			_elemStack.pop_back();
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr) &&
				elem2.IsType(ETYPE_LBracket) && elem3.IsType(ETYPE_Expr)) {
		Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(elem2.GetExpr());
		if (elem4.IsType(ETYPE_RBracket)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '[' Expr ']'\n"));
			Expr *pExprTgt = elem1.GetExpr();
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
			}
			pExprLister->AddExpr(elem3.GetExpr());
			pExpr = new Expr_Indexer(pExprTgt, pExprLister);
		} else if (elem4.IsType(ETYPE_Comma) || elem4.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '[' -> Expr '[' Expr ','\n"));
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
				elem2.SetExpr(pExprLister);
			}
			pExprLister->AddExpr(elem3.GetExpr());
			_elemStack.pop_back();
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else {
		SetError_InvalidElement(sig, __LINE__);
		return false;
	}
	int lineNoTop = elem1.GetLineNo();
	_elemStack.pop_back();
	_elemStack.pop_back();
	_elemStack.pop_back();
	_elemStack.pop_back();
	pExpr->SetLineNo(lineNoTop, GetLineNo());
	_elemStack.push_back(Element(ETYPE_Expr, pExpr));
	return true;
}

bool Parser::ReduceFiveElems(Environment &env, Signal sig)
{
	Expr *pExpr;
	Element &elem1 = _elemStack.Peek(4);
	Element &elem2 = _elemStack.Peek(3);
	Element &elem3 = _elemStack.Peek(2);
	Element &elem4 = _elemStack.Peek(1);
	Element &elem5 = _elemStack.Peek(0);
	if (elem1.IsType(ETYPE_Expr) && elem2.IsType(ETYPE_Expr) &&
				elem3.IsType(ETYPE_LParenthesis) && elem4.IsType(ETYPE_Expr)) {
		Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(elem3.GetExpr());
		if (elem5.IsType(ETYPE_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr Expr '(' Expr ')'\n"));
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
			}
			pExprLister->AddExpr(elem4.GetExpr());
			Expr_Caller *pExprCaller =
						new Expr_Caller(elem2.GetExpr(), pExprLister, NULL);
			if (!elem1.GetExpr()->IsCaller()) {
				SetError_InvalidElement(sig, __LINE__);
				return false;
			}
			Expr_Caller *pExprCallerPrev =
							dynamic_cast<Expr_Caller *>(elem1.GetExpr());
			pExprCallerPrev->GetLastTrailer()->SetTrailer(pExprCaller);
			pExpr = pExprCallerPrev;
		} else if (elem5.IsType(ETYPE_Comma) || elem5.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr Expr '(' -> Expr Expr '(' Expr ','\n"));
			if (pExprLister == NULL) {
				pExprLister = new Expr_Lister();
				elem3.SetExpr(pExprLister);
			}
			pExprLister->AddExpr(elem4.GetExpr());
			_elemStack.pop_back();
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else if (elem1.IsType(ETYPE_Expr) && elem2.IsType(ETYPE_Expr) &&
				elem3.IsType(ETYPE_LBrace) && elem4.IsType(ETYPE_Expr)) {
		Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(elem3.GetExpr());
		if (elem5.IsType(ETYPE_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr Expr '{' Expr '}'\n"));
			if (pExprBlock == NULL) {
				pExprBlock = new Expr_Block();
			}
			pExprBlock->AddExpr(elem4.GetExpr());
			Expr_Caller *pExprCaller;
			if (elem2.GetExpr()->IsCaller()) {
				pExprCaller = dynamic_cast<Expr_Caller *>(elem2.GetExpr());
				pExprCaller->GetLastTrailer()->SetBlock(pExprBlock);
			} else {
				pExprCaller = new Expr_Caller(elem2.GetExpr(), NULL, pExprBlock);
			}
			if (!elem1.GetExpr()->IsCaller()) {
				SetError_InvalidElement(sig, __LINE__);
				return false;
			}
			Expr_Caller *pExprCallerPrev =
							dynamic_cast<Expr_Caller *>(elem1.GetExpr());
			pExprCallerPrev->GetLastTrailer()->SetTrailer(pExprCaller);
			pExpr = pExprCallerPrev;
		} else if (elem5.IsType(ETYPE_Comma) ||
					elem5.IsType(ETYPE_Semicolon) || elem5.IsType(ETYPE_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr Expr '{' -> Expr Expr '{' Expr ','\n"));
			if (pExprBlock == NULL) {
				pExprBlock = new Expr_Block();
				elem3.SetExpr(pExprBlock);
			}
			pExprBlock->AddExpr(elem4.GetExpr());
			_elemStack.pop_back();
			_elemStack.pop_back();
			return true;
		} else {
			SetError_InvalidElement(sig, __LINE__);
			return false;
		}
	} else {
		SetError_InvalidElement(sig, __LINE__);
		return false;
	}
	int lineNoTop = elem1.GetLineNo();
	_elemStack.pop_back();
	_elemStack.pop_back();
	_elemStack.pop_back();
	_elemStack.pop_back();
	_elemStack.pop_back();
	pExpr->SetLineNo(lineNoTop, GetLineNo());
	_elemStack.push_back(Element(ETYPE_Expr, pExpr));
	return true;
}

void Parser::SetError(Signal sig, ErrorType errType, const char *format, ...)
{
	String textPre(" at ");
	if (!_sourceName.empty()) {
		String fileName;
		Directory::SplitFileName(_sourceName.c_str(), NULL, &fileName);
		textPre += fileName;
	}
	do {
		char buff[64];
		::sprintf(buff, ":%d: ", GetLineNo());
		textPre += buff;
	} while (0);
	va_list list;
	va_start(list, format);
	sig.SetErrorV(errType, format, list, textPre.c_str());
	va_end(list);
}

void Parser::SetError_InvalidElement(Signal sig)
{
	SetError(sig, ERR_SyntaxError, "invalid element");
}

void Parser::SetError_InvalidElement(Signal sig, int lineno)
{
	SetError(sig, ERR_SyntaxError, "invalid element (%d) .. %s", lineno,
										_elemStack.ToString().c_str());
}

const Parser::ElemTypeInfo *Parser::LookupElemTypeInfo(ElemType elemType)
{
	for (const ElemTypeInfo *p = _elemTypeInfoTbl;
										p->elemType != ETYPE_Unknown; p++) {
		if (p->elemType == elemType) return p;
	}
	return NULL;
}

//-----------------------------------------------------------------------------
// Parser::ElementStack
//-----------------------------------------------------------------------------
Parser::ElementStack::~ElementStack()
{
}

Parser::ElementStack::reverse_iterator
					Parser::ElementStack::SeekTerminal(reverse_iterator p)
{
	for ( ; p->IsType(ETYPE_Expr); p++) ;
	return p;
}

void Parser::ElementStack::Clear()
{
	foreach (ElementStack, pElem, *this) {
		Expr::Delete(pElem->GetExpr());
	}
	clear();
}

String Parser::ElementStack::ToString() const
{
	String rtn;
	foreach_const (ElementStack, pElement, *this) {
		if (pElement != begin()) rtn.append(" ");
		rtn.append(pElement->GetTypeSymbol());
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// Parser::Element
//-----------------------------------------------------------------------------
Parser::Element::~Element()
{
}

Number Parser::Element::GetNumber() const
{
	if (_str.size() > 2 && _str[0] == '0' &&
			(_str[1] == 'x' || _str[1] == 'X' || IsOctDigit(_str[1]))) {
		return ::strtoul(_str.c_str(), NULL, 0);
	} else {
		return ::strtod(_str.c_str(), NULL);
	}
}

const char *Parser::Element::GetTypeSymbol() const
{
	const ElemTypeInfo *p = LookupElemTypeInfo(_elemType);
	return (p == NULL)? "[unk]" : p->symbol;
}

//-----------------------------------------------------------------------------
// MagicCommentParser
//-----------------------------------------------------------------------------
MagicCommentParser::MagicCommentParser() : _stat(STAT_Start)
{
}

MagicCommentParser::~MagicCommentParser()
{
}

bool MagicCommentParser::ParseChar(char ch)
{
	bool rtn = false;
	if (_stat == STAT_Idle) {
		// nothing to do
	} else if (_stat == STAT_Start) {
		if (IsAlpha(ch)) {
			_field.push_back(ch);
		} else if (ch == ':' || ch == '=') {
			if (_field.size() >= 6 &&
					::strcmp(_field.c_str() + _field.size() - 6, "coding") == 0) {
				_stat = STAT_SkipSpace;
			} else {
				_field.clear();
			}
		} else {
			_field.clear();
		}
	} else if (_stat == STAT_SkipSpace) {
		if (ch == ' ' || ch == '\t') {
			// nothing to do
		} else if (IsAlpha(ch) || IsDigit(ch) || ch == '.' || ch == '-' || ch == '_') {
			_field = ch;
			_stat = STAT_CodingName;
		} else {
			_stat = STAT_Start;
		}
	} else if (_stat == STAT_CodingName) {
		if (IsAlpha(ch) || IsDigit(ch) || ch == '.' || ch == '-' || ch == '_') {
			_field.push_back(ch);
		} else {
			rtn = true;
			_stat = STAT_Idle;
		}
	}
	return rtn;
}

}
