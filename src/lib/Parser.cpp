//=============================================================================
// Parser
//=============================================================================
#include "stdafx.h"

#define DBGPARSER(x)

namespace Gura {

//-----------------------------------------------------------------------------
// Parser
//-----------------------------------------------------------------------------
Parser::Parser(Signal &sig, const String &sourceName, int cntLineStart, bool enablePreparatorFlag) :
	_sig(sig), _stat(STAT_BOF), _lineHeadFlag(true),
	_appearShebangFlag(false), _blockParamFlag(false),
	_cntLine(cntLineStart), _cntCol(0), _commentNestLevel(0),
	_pSourceName(new StringShared(sourceName)),
	_pExprOwner(nullptr), _pExprParent(nullptr),
	_pTokenInfoPrev(&TOKEN_Unknown), _lineNoTop(0), _lineNoOfTokenPrev(0),
	_enablePreparatorFlag(enablePreparatorFlag), _interactiveFlag(false),
	_pTokenWatcher(nullptr)
{
	InitStack();
}

Parser::~Parser()
{
}

void Parser::Initialize()
{
}

void Parser::InitStack()
{
	_tokenStack.Clear();
	_tokenStack.push_back(Token(TOKEN_Begin, 0));
}

bool Parser::ParseChar(Environment &env, char ch)
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
	Gura_BeginPushbackRegionEx(char, 8, ch);
	switch (_stat) {
	case STAT_BOF: {
		if (ch == '\xef') {
			_field.clear();
			_field.push_back(ch);
			_stat = STAT_BOF_2nd;
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_Start;
		}
		break;
	}
	case STAT_BOF_2nd: {
		if (ch == '\xbb') {
			_field.push_back(ch);
			_stat = STAT_BOF_3rd;
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_Symbol;
		}
		break;
	}
	case STAT_BOF_3rd: {
		if (ch == '\xbf') {
			_stat = STAT_Start;
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_Symbol;
		}
		break;
	}
	case STAT_Start: {
		if (ch == '0') {
			_field.clear();
			_field.push_back(ch);
			_stat = STAT_NumberPre;
		} else if (IsDigit(ch)) {
			_field.clear();
			_field.push_back(ch);
			_stat = STAT_Number;
		} else if (ch == '.') {
			_field.clear();
			_field.push_back(ch);
			_stat = STAT_NumberAfterDot;
		} else if (IsWhite(ch) || ch == '\x0c') { // code 0x0c is page-break
			if (IsTokenWatched()) {
				_field.clear();
				_field.push_back(ch);
				_stat = STAT_White;
			}
		} else if (IsSymbolFirstChar(ch)) {
			_field.clear();
			_field.push_back(ch);
			_stat = STAT_Symbol;
		} else if (ch == '"' || ch == '\'') {
			_stringInfo.chBorder = ch;
			_stringInfo.rawFlag = false;
			_stringInfo.binaryFlag = false;
			_stringInfo.wiseFlag = false;
			_stringInfo.embedFlag = false;
			_field.clear();
			if (IsTokenWatched()) {
				_strSource.clear();
				_strSource.push_back(ch);
			}
			_stat = STAT_StringFirst;
		} else if (ch == '\\') {
			if (IsTokenWatched()) {
				_field.clear();
				_field.push_back(ch);
			}
			_stat = STAT_Escape;
		} else if (ch == '\n') {
			FeedToken(env, Token(TOKEN_EOL, GetLineNo()));
			if (sig.IsSignalled()) _stat = STAT_Error;
		} else if (ch == '#') {
			if (IsTokenWatched()) {
				_field.clear();
				_field.push_back(ch);
			}
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
			FeedToken(env, Token(TOKEN_LBrace, GetLineNo()));
			if (IsTokenWatched()) {
				_field.clear();
				_lineNoTop = GetLineNo();
			}
			_stat = sig.IsSignalled()? STAT_Error : STAT_AfterLBrace;
		} else if (ch == '(') {
			FeedToken(env, Token(TOKEN_LParenthesis, GetLineNo()));
			if (sig.IsSignalled()) _stat = STAT_Error;
		} else if (ch == '[') {
			FeedToken(env, Token(TOKEN_LBracket, GetLineNo()));
			if (sig.IsSignalled()) _stat = STAT_Error;
		} else if (ch == '|' && _blockParamFlag && _tokenStack.CheckBlockParamEnd()) {
			_blockParamFlag = false;
			FeedToken(env, Token(TOKEN_RBlockParam, GetLineNo()));
			if (sig.IsSignalled()) _stat = STAT_Error;
		} else if (ch == '`') {
			FeedToken(env, Token(TOKEN_Quote, GetLineNo()));
			_stat = STAT_Start;
		} else if (ch == ':') {
			_stat = STAT_Colon;
		} else {
			size_t i = 0;
			static const struct {
				int ch;
				const TokenInfo *pTokenInfo;
			} tbl[] = {
				{ '?',	&TOKEN_Question,	},
				{ '+',	&TOKEN_DoubleChars,	},
				{ '-',	&TOKEN_DoubleChars,	},
				{ '*',	&TOKEN_DoubleChars,	},
				{ '/',	&TOKEN_DoubleChars,	},
				{ '%',	&TOKEN_DoubleChars,	},
				{ '=',	&TOKEN_DoubleChars,	},
				{ '<',	&TOKEN_DoubleChars,	},
				{ '>',	&TOKEN_DoubleChars,	},
				{ '!',	&TOKEN_DoubleChars,	}, // see also STAT_Symbol
				{ '|',	&TOKEN_DoubleChars,	},
				{ '&',	&TOKEN_DoubleChars,	},
				{ '^',	&TOKEN_DoubleChars,	},
				{ '~',	&TOKEN_Inv,			},
				{ ',',	&TOKEN_Comma,		},
				{ ';',	&TOKEN_Semicolon,	},
				{ ')',	&TOKEN_RParenthesis,},
				{ '}',	&TOKEN_RBrace,		},
				{ ']',	&TOKEN_RBracket,	},
				{ '\0',	&TOKEN_EOF,			},
			};
			for (i = 0; i < ArraySizeOf(tbl); i++) {
				if (tbl[i].ch == ch) break;
			}
			if (i >= ArraySizeOf(tbl)) {
				SetError(ERR_SyntaxError, "unexpected character '%c' (%d)", ch, ch);
				_stat = STAT_Error;
			} else if (tbl[i].pTokenInfo->IsIdentical(TOKEN_DoubleChars)) {
				_field.clear();
				_field.push_back(ch);
				_stat = STAT_DoubleChars;
			} else if (_tokenStack.back().IsType(TOKEN_Quote)) {
				_field.clear();
				_field.push_back(ch);
				FeedToken(env, Token(TOKEN_Symbol, GetLineNo(), _field));
				if (sig.IsSignalled()) _stat = STAT_Error;
			} else {
				FeedToken(env, Token(*tbl[i].pTokenInfo, GetLineNo()));
				if (sig.IsSignalled()) _stat = STAT_Error;
			}
		}
		break;
	}
	case STAT_White: {
		if (IsWhite(ch) || ch == '\x0c') { // code 0x0c is page-break
			_field.push_back(ch);
		} else {
			_pTokenWatcher->FeedToken(env, Token(TOKEN_Space, GetLineNo(), _field));
			Gura_PushbackEx(ch);
			_stat = STAT_Start;
		}
		break;
	}
	case STAT_DoubleChars: {
		// this state comes from STAT_Start and STAT_Symbol
		static const struct {
			int chFirst;
			const TokenInfo *pTokenInfo;
			struct {
				int chSecond;
				const TokenInfo *pTokenInfo;
			} tblCand[5];
		} tbl[] = {
			{ '+', &TOKEN_Add, {
				{ '=', &TOKEN_AssignAdd		},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '-', &TOKEN_Sub, {
				{ '=', &TOKEN_AssignSub		},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '*', &TOKEN_Mul, {
				{ '=', &TOKEN_AssignMul		},
				{ '*', &TOKEN_TripleChars	},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '/', &TOKEN_Div, {
				{ '=', &TOKEN_AssignDiv		},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '%', &TOKEN_Mod, {
				{ '=', &TOKEN_AssignMod		},
				{ '%', &TOKEN_ModMod		},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '=', &TOKEN_Assign, {
				{ '=', &TOKEN_Eq 			},
				{ '>', &TOKEN_Pair			},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '<', &TOKEN_Lt, {
				{ '=', &TOKEN_TripleChars	},
				{ '<', &TOKEN_TripleChars	},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '>', &TOKEN_Gt, {
				{ '=', &TOKEN_Ge			},
				{ '>', &TOKEN_TripleChars	},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '!', &TOKEN_Not, {
				{ '=', &TOKEN_Ne			},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '|', &TOKEN_Or, {
				{ '=', &TOKEN_AssignOr 		},
				{ '|', &TOKEN_OrOr			},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '&', &TOKEN_And, {
				{ '=', &TOKEN_AssignAnd		},
				{ '&', &TOKEN_AndAnd		},
				{ '\0', &TOKEN_Unknown		}, } },
			{ '^', &TOKEN_Xor, {
				{ '=', &TOKEN_AssignXor		},
				{ '\0', &TOKEN_Unknown		}, } },
		};
		int chFirst = _field[0];
		if (chFirst == '/' && ch == '*') {
			if (IsTokenWatched()) {
				_field.clear();
				_field.push_back(chFirst);
				_field.push_back(ch);
				_lineNoTop = GetLineNo();
			}
			_commentNestLevel = 1;
			_stat = STAT_CommentBlock;
		} else if (chFirst == '/' && ch == '/') {
			if (IsTokenWatched()) {
				_field.clear();
				_field.push_back(chFirst);
				_field.push_back(ch);
			}
			if (_cntLine == 0 || (_cntLine == 1 && _appearShebangFlag)) {
				_stat = STAT_MagicCommentLine;
			} else {
				_stat = STAT_CommentLine;
			}
		} else if (chFirst == '*' && ch == '/') {
			SetError(ERR_SyntaxError, "unmatching comment description");
			_stat = STAT_Error;
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_Start;
			for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
				if (tbl[i].chFirst != chFirst) continue;
				const TokenInfo *pTokenInfo = tbl[i].pTokenInfo;
				for (size_t j = 0; j < ArraySizeOf(tbl[i].tblCand); j++) {
					if (tbl[i].tblCand[j].chSecond == '\0') break;
					if (tbl[i].tblCand[j].chSecond != ch) continue;
					_field.push_back(ch);
					pTokenInfo = tbl[i].tblCand[j].pTokenInfo;
					Gura_PushbackCancelEx();
					break;
				}
				if (pTokenInfo->IsIdentical(TOKEN_TripleChars)) {
					_stat = STAT_TripleChars;
				} else if (_tokenStack.back().IsType(TOKEN_Quote)) {
					FeedToken(env, Token(TOKEN_Symbol, GetLineNo(), _field));
					if (sig.IsSignalled()) _stat = STAT_Error;
				} else {
					FeedToken(env, Token(*pTokenInfo, GetLineNo()));
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
			const TokenInfo *pTokenInfo;
			struct {
				int chThird;
				const TokenInfo *pTokenInfo;
			} tblCand[5];
		} tbl[] = {
			{ "**", &TOKEN_Pow, {
				{ '=', &TOKEN_AssignPow		},
				{ '\0', &TOKEN_Unknown		}, } },
			{ "<=", &TOKEN_Le, {
				{ '>', &TOKEN_Cmp			},
				{ '\0', &TOKEN_Unknown		}, } },
			{ "<<", &TOKEN_Shl, {
				{ '=', &TOKEN_AssignShl		},
				{ '\0', &TOKEN_Unknown		}, } },
			{ ">>", &TOKEN_Shr, {
				{ '=', &TOKEN_AssignShr		},
				{ '\0', &TOKEN_Unknown		}, } },
		};
		Gura_PushbackEx(ch);
		_stat = STAT_Start;
		for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
			if (_field.compare(tbl[i].strFirst) != 0) continue;
			const TokenInfo *pTokenInfo = tbl[i].pTokenInfo;
			for (size_t j = 0; j < ArraySizeOf(tbl[i].tblCand); j++) {
				if (tbl[i].tblCand[j].chThird == '\0') break;
				if (tbl[i].tblCand[j].chThird != ch) continue;
				_field.push_back(ch);
				pTokenInfo = tbl[i].tblCand[j].pTokenInfo;
				Gura_PushbackCancelEx();
				break;
			}
			if (_tokenStack.back().IsType(TOKEN_Quote)) {
				FeedToken(env, Token(TOKEN_Symbol, GetLineNo(), _field));
				if (sig.IsSignalled()) _stat = STAT_Error;
			} else {
				FeedToken(env, Token(*pTokenInfo, GetLineNo()));
				if (sig.IsSignalled()) _stat = STAT_Error;
			}
			break;
		}
		// tables have a bug if i reaches at ArraySizeOf(tbl)
		break;
	}
	case STAT_Escape: {
		if (ch == '\0') {
			if (IsTokenWatched()) {
				_pTokenWatcher->FeedToken(env, Token(TOKEN_Escape, GetLineNo(), _field));
			}
			Gura_PushbackEx(ch);
			_stat = STAT_Start;
		} else if (ch == '\n') {
			if (IsTokenWatched()) {
				_field.push_back(ch);
				_pTokenWatcher->FeedToken(env, Token(TOKEN_Escape, GetLineNo(), _field));
			}
			_stat = STAT_Start;
		} else if (IsWhite(ch)) {
			if (IsTokenWatched()) {
				_field.push_back(ch);
			}
		} else {
			SetError(ERR_SyntaxError, "invalid escape character");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_Colon: {
		if (ch == ':') {
			FeedToken(env, Token(TOKEN_ColonColon, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else if (ch == '*') {
			FeedToken(env, Token(TOKEN_ColonAsterisk, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else if (ch == '&') {
			FeedToken(env, Token(TOKEN_ColonAnd, GetLineNo()));
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else {
			const TokenInfo *pTokenInfo = _tokenStack.back().IsSuffixToken()?
									&TOKEN_ColonAfterSuffix : &TOKEN_Colon;
			FeedToken(env, Token(*pTokenInfo, GetLineNo()));
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_Error: {
		InitStack();
		_blockParamFlag = false;
		Gura_PushbackEx(ch);
		_stat = STAT_ErrorRecovery;
		break;
	}
	case STAT_ErrorRecovery: {
		if (ch == '\n' || ch == '\0') {
			Gura_PushbackEx(ch);
			_stat = STAT_Start;
		} else {
			// nothing to do
		}
		break;
	}
	case STAT_AfterLBrace: {
		if (ch == '|') {
			if (IsTokenWatched() && !_field.empty()) {
				_pTokenWatcher->FeedToken(env, Token(TOKEN_Space, _lineNoTop, _field));
			}
			FeedToken(env, Token(TOKEN_LBlockParam, GetLineNo()));
			if (sig.IsSignalled()) {
				_stat = STAT_Error;
			} else {
				_blockParamFlag = true;
				_stat = STAT_Start;
			}
		} else if (ch == '\n' || IsWhite(ch)) {
			if (IsTokenWatched()) _field.push_back(ch);
		} else {
			if (IsTokenWatched() && !_field.empty()) {
				_pTokenWatcher->FeedToken(env, Token(TOKEN_Space, _lineNoTop, _field));
			}
			Gura_PushbackEx(ch);
			_stat = STAT_Start;
		}
		break;
	}
	case STAT_NumberPre: {
		if (ch == 'x' || ch == 'X') {
			_field.push_back(ch);
			_stat = STAT_NumberHex;
		} else if (ch == 'b' || ch == 'B') {
			_field.push_back(ch);
			_stat = STAT_NumberBin;
		} else if(IsOctDigit(ch)) {
			_field.push_back(ch);
			_stat = STAT_NumberOct;
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_Number;
		}
		break;
	}
	case STAT_NumberHex: {
		if (IsHexDigit(ch)) {
			_field.push_back(ch);
		} else if (_field.size() <= 2) {
			SetError(ERR_SyntaxError, "wrong format of hexadecimal number");
			Gura_PushbackEx(ch);
			_stat = STAT_Error;
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_NumberSuffixed;
		} else {
			FeedToken(env, Token(TOKEN_Number, GetLineNo(), _field));
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberOct: {
		if (IsOctDigit(ch)) {
			_field.push_back(ch);
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_NumberSuffixed;
		} else {
			FeedToken(env, Token(TOKEN_Number, GetLineNo(), _field));
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberBin: {
		if (IsBinDigit(ch)) {
			_field.push_back(ch);
		} else if (_field.size() <= 2) {
			SetError(ERR_SyntaxError, "wrong format of binary number");
			Gura_PushbackEx(ch);
			_stat = STAT_Error;
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_NumberSuffixed;
		} else {
			FeedToken(env, Token(TOKEN_Number, GetLineNo(), _field));
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberAfterDot: {
		if (ch == '.') {
			if (_tokenStack.back().IsType(TOKEN_Quote)) {
				_field.push_back(ch);
				FeedToken(env, Token(TOKEN_Symbol, GetLineNo(), _field));
			} else {
				FeedToken(env, Token(TOKEN_Seq, GetLineNo()));
			}
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		} else if (IsDigit(ch)) {
			_field.push_back(ch);
			_stat = STAT_Number;
		} else {
			FeedToken(env, Token(TOKEN_Dot, GetLineNo()));
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_Number: {
		if (IsDigit(ch)) {
			_field.push_back(ch);
		} else if (ch == '.') {
			size_t pos = _field.find('.');
			if (pos == _field.length() - 1) {
				_field.resize(pos);
				FeedToken(env, Token(TOKEN_Number, GetLineNo(), _field));
				if (!sig.IsSignalled()) {
					FeedToken(env, Token(TOKEN_Seq, GetLineNo()));
				}
				_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
			} else if (pos == String::npos) {
				_field.push_back(ch);
			} else {
				SetError(ERR_SyntaxError, "dot has already been scanned");
				_stat = STAT_Error;
			}
		} else if (ch == 'e' || ch == 'E') {
			_field.push_back(ch);
			_stat = STAT_NumberExpAfterE;
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_NumberSuffixed;
		} else {
			FeedToken(env, Token(TOKEN_Number, GetLineNo(), _field));
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberExpAfterE: {
		if (IsDigit(ch)) {
			_field.push_back(ch);
			_stat = STAT_NumberExp;
		} else if (ch == '+' || ch == '-') {
			_field.push_back(ch);
			_stat = STAT_NumberExpAfterSign;
		} else {
			SetError(ERR_SyntaxError, "wrong exponential expression");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_NumberExpAfterSign: {
		if (IsDigit(ch)) {
			_field.push_back(ch);
			_stat = STAT_NumberExp;
		} else {
			SetError(ERR_SyntaxError, "wrong exponential expression");
			_stat = STAT_Error;
		}
		break;
	}
	case STAT_NumberExp: {
		if (IsDigit(ch)) {
			_field.push_back(ch);
		} else if (IsSymbolFirstChar(ch)) {
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_NumberSuffixed;
		} else {
			FeedToken(env, Token(TOKEN_Number, GetLineNo(), _field));
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_NumberSuffixed: {
		if (IsSymbolChar(ch)) {
			_suffix.push_back(ch);
		} else {
			if (IsTokenWatched()) {
				FeedToken(env, Token(TOKEN_NumberSuffixed, GetLineNo(),
									 _field, _suffix, _field + _suffix));
			} else {
				FeedToken(env, Token(TOKEN_NumberSuffixed, GetLineNo(), _field, _suffix));
			}
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_Symbol: {
		if (IsSymbolChar(ch)) {
			_field.push_back(ch);
		} else if (ch == '!') {
			_stat = STAT_SymbolExclamation;
		} else if ((ch == '"' || ch == '\'') && CheckStringPrefix(_stringInfo, _field)) {
			_stringInfo.chBorder = ch;
			if (IsTokenWatched()) {
				_strSource.clear();
				_strSource += _field;
				_strSource.push_back(ch);
			}
			_field.clear();
			_stat = STAT_StringFirst;
		} else {
			if (_field == "in" && !_tokenStack.back().IsType(TOKEN_Quote)) {
				FeedToken(env, Token(TOKEN_Contains, GetLineNo()));
			} else {
				FeedToken(env, Token(TOKEN_Symbol, GetLineNo(), _field));
			}
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_SymbolExclamation: {
		if (ch == '=' || ch == '!') {
			FeedToken(env, Token(TOKEN_Symbol, GetLineNo(), _field));
			if (sig.IsSignalled()) {
				_stat = STAT_Error;
			} else {
				_field.clear();
				_field.push_back('!');
				Gura_PushbackEx(ch);
				_stat = STAT_DoubleChars;
			}
		} else {
			_field.push_back('!');
			Gura_PushbackEx(ch);
			_stat = STAT_Symbol;
		}
		break;
	}
	case STAT_CommentLineTop: {
		if (ch == '!') {
			if (IsTokenWatched()) _field.push_back(ch);
			_appearShebangFlag = true;
			_stat = STAT_ShebangLine;
		} else {
			_stat = STAT_MagicCommentLine;
			Gura_PushbackEx(ch);
		}
		break;
	}
	case STAT_MagicCommentLine: {
		if (_magicCommentParser.ParseChar(ch)) {
			const char *encoding = _magicCommentParser.GetEncoding();
			sig.SetSignal(SIGTYPE_DetectEncoding, Value(encoding));
		}
		if (ch == '\n' || ch == '\0') {
			if (IsTokenWatched()) {
				_pTokenWatcher->FeedToken(
					env, Token(TOKEN_CommentLine, GetLineNo(), _field));
			}
			if (ch == '\n') FeedToken(env, Token(TOKEN_EOL, GetLineNo()));
			_stat = STAT_Start;
		} else {
			if (IsTokenWatched()) _field.push_back(ch);
		}
		break;
	}
	case STAT_ShebangLine: {
		if (ch == '\n' || ch == '\0') {
			if (IsTokenWatched()) {
				_pTokenWatcher->FeedToken(
					env, Token(TOKEN_CommentLine, GetLineNo(), _field));
			}
			if (ch == '\n') FeedToken(env, Token(TOKEN_EOL, GetLineNo()));
			_stat = STAT_Start;
		} else {
			if (IsTokenWatched()) _field.push_back(ch);
		}
		break;
	}
	case STAT_CommentLine: {
		if (ch == '\n' || ch == '\0') {
			if (IsTokenWatched()) {
				_pTokenWatcher->FeedToken(
					env, Token(TOKEN_CommentLine, GetLineNo(), _field));
			}
			if (ch == '\n') FeedToken(env, Token(TOKEN_EOL, GetLineNo()));
			_stat = STAT_Start;
		} else {
			if (IsTokenWatched()) _field.push_back(ch);
		}
		break;
	}
	case STAT_CommentBlock: {
		if (ch == '*') {
			if (IsTokenWatched()) _field.push_back(ch);
			_stat = STAT_CommentBlockEnd;
		} else if (ch == '/') {
			if (IsTokenWatched()) _field.push_back(ch);
			_stat = STAT_CommentBlockNest;
		} else {
			if (IsTokenWatched()) _field.push_back(ch);
		}
		break;
	}
	case STAT_CommentBlockEnd: {
		if (ch == '/') {
			if (IsTokenWatched()) _field.push_back(ch);
			_commentNestLevel--;
			if (_commentNestLevel > 0) {
				_stat = STAT_CommentBlock;
			} else {
				if (IsTokenWatched()) {
					_pTokenWatcher->FeedToken(
						env, Token(TOKEN_CommentBlock, _lineNoTop, _field));
				}
				_stat = STAT_Start;
			}
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_CommentBlock;
		}
		break;
	}
	case STAT_CommentBlockNest: {
		if (ch == '*') {
			if (IsTokenWatched()) _field.push_back(ch);
			_commentNestLevel++;
			_stat = STAT_CommentBlock;
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_CommentBlock;
		}
		break;
	}
	case STAT_StringFirst: {
		if (ch == _stringInfo.chBorder) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stat = STAT_StringSecond;
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_String;
		}
		break;
	}
	case STAT_StringSecond: {
		if (ch == _stringInfo.chBorder) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			if (_stringInfo.wiseFlag) {
				_stringInfo.strIndentRef = _strIndent;
				_stat = STAT_MStringWise;
			} else {
				_stat = STAT_MString;
			}
		} else if (IsSymbolFirstChar(ch)) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_StringSuffixed;
		} else {
			const TokenInfo *pTokenInfo = GetTokenInfoForString(_stringInfo);
			FeedToken(env, Token(*pTokenInfo, GetLineNo(), _field, "", _strSource));
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_String: {
		if (ch == _stringInfo.chBorder) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stat = STAT_StringPost;
		} else if (ch == '\\') {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stringInfo.statRtn = STAT_String;
			_stat = STAT_StringEsc;
		} else if (ch == '\0' || ch == '\n') {
			SetError(ERR_SyntaxError, "string is not terminated correctly");
			_stat = STAT_Error;
		} else {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_field.push_back(ch);
		}
		break;
	}
	case STAT_MStringWise: {
		if (ch == '\n') {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stat = STAT_MStringLineHead;
		} else {
			Gura_PushbackEx(ch);
			_stat = STAT_MString;
		}
		break;
	}
	case STAT_MString: {
		if (ch == _stringInfo.chBorder) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stat = STAT_MStringEndFirst;
		} else if (ch == '\\') {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stringInfo.statRtn = STAT_MString;
			_stat = STAT_StringEsc;
		} else if (ch == '\0') {
			SetError(ERR_SyntaxError, "string is not terminated correctly");
			_stat = STAT_Error;
		} else if (ch == '\n' && _stringInfo.wiseFlag) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_field.push_back(ch);
			_stat = STAT_MStringLineHead;
		} else {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_field.push_back(ch);
		}
		break;
	}
	case STAT_MStringLineHead: {
		if (IsWhite(ch)) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			if (_strIndent.size() == _stringInfo.strIndentRef.size()) {
				if (_strIndent != _stringInfo.strIndentRef) {
					_field += _strIndent;
				}
				_stat = STAT_MString;
			}
		} else {
			_field += _strIndent;
			Gura_PushbackEx(ch);
			_stat = STAT_MString;
		}
		break;
	}
	case STAT_StringEsc: {
		if (_stringInfo.rawFlag) {
			if (IsTokenWatched()) {
				_strSource.push_back(ch);
			}
			_field.push_back('\\');
			_field.push_back(ch);
			_stat = _stringInfo.statRtn;
		} else {
			if (IsTokenWatched()) _strSource.push_back(ch);
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
				_field.push_back(GetEscaped(ch));
				_stat = _stringInfo.statRtn;
			}
		}
		break;
	}
	case STAT_StringEscHex: {
		if (IsHexDigit(ch)) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stringInfo.accum = (_stringInfo.accum << 4) + ConvHexDigit(ch);
			_stringInfo.cntRest--;
			if (_stringInfo.cntRest <= 0) {
				_field.push_back(static_cast<char>(_stringInfo.accum));
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
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stringInfo.accum = (_stringInfo.accum << 3) + ConvOctDigit(ch);
			_stringInfo.cntRest--;
			if (_stringInfo.cntRest <= 0) {
				_field.push_back(static_cast<char>(_stringInfo.accum));
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
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stringInfo.accum = (_stringInfo.accum << 4) + ConvHexDigit(ch);
			_stringInfo.cntRest--;
			if (_stringInfo.cntRest <= 0) {
				AppendUTF32(_field, _stringInfo.accum);
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
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stat = STAT_CommentBlock;
		} else if (ch == '\\') {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stat = STAT_StringEscInCommentBlock;
		} else {
			if (IsTokenWatched()) _strSource.push_back(ch);
		}
		break;
	}
	case STAT_StringEscInCommentBlock: {
		if (IsTokenWatched()) _strSource.push_back(ch);
		_stat = STAT_StringInCommentBlock;
		break;
	}
	case STAT_MStringEndFirst: {
		if (ch == _stringInfo.chBorder) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stat = STAT_MStringEndSecond;
		} else {
			if (IsTokenWatched()) _strSource.push_back(_stringInfo.chBorder);
			_field.push_back(_stringInfo.chBorder);
			Gura_PushbackEx(ch);
			_stat = STAT_MString;
		}
		break;
	}
	case STAT_MStringEndSecond: {
		if (ch == _stringInfo.chBorder) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_stat = STAT_StringPost;
		} else {
			if (IsTokenWatched()) {
				_strSource.push_back(_stringInfo.chBorder);
				_strSource.push_back(_stringInfo.chBorder);
			}
			_field.push_back(_stringInfo.chBorder);
			_field.push_back(_stringInfo.chBorder);
			Gura_PushbackEx(ch);
			_stat = STAT_MString;
		}
		break;
	}
	case STAT_StringPost: {
		if (IsSymbolFirstChar(ch)) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_suffix.clear();
			_suffix.push_back(ch);
			_stat = STAT_StringSuffixed;
		} else {
			const TokenInfo *pTokenInfo = GetTokenInfoForString(_stringInfo);
			FeedToken(env, Token(*pTokenInfo, GetLineNo(), _field, "", _strSource));
			Gura_PushbackEx(ch);
			_stat = sig.IsSignalled()? STAT_Error : STAT_Start;
		}
		break;
	}
	case STAT_StringSuffixed: {
		if (IsSymbolChar(ch)) {
			if (IsTokenWatched()) _strSource.push_back(ch);
			_suffix.push_back(ch);
		} else {
			FeedToken(env, Token(TOKEN_StringSuffixed, GetLineNo(), _field, _suffix, _strSource));
			Gura_PushbackEx(ch);
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
	Gura_EndPushbackRegionEx();
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

Expr_Caller *Parser::CreateCaller(
	Environment &env, Expr *pExprCar, Expr_Lister *pExprLister,
	Expr_Block *pExprBlock, const Expr_Caller *pExprLeader)
{
	ULong flags = FLAG_None;
	if (pExprCar->IsIdentifier()) {
		const Symbol *pSymbol = dynamic_cast<Expr_Identifier *>(pExprCar)->GetSymbol();
		const Function *pFunc = env.LookupFunction(pSymbol, ENVREF_Escalate);
		if (pFunc != nullptr) {
			AutoPtr<Expr_Caller> pExpr(
				pFunc->GenerateStatement(
					this, pExprCar, pExprLister, pExprBlock, pExprLeader));
			if (env.IsSignalled()) return nullptr;
			if (!pExpr.IsNull()) return pExpr.release();
			flags = pFunc->GetFlags() & (FLAG_Leader | FLAG_Trailer);
		}
	}
	return new Expr_Caller(pExprCar, pExprLister, pExprBlock, flags);
}


const TokenInfo *Parser::GetTokenInfoForString(const StringInfo &stringInfo)
{
	return stringInfo.binaryFlag? &TOKEN_Binary :
		stringInfo.embedFlag? &TOKEN_EmbedString : &TOKEN_String;
}

bool Parser::CheckStringPrefix(StringInfo &stringInfo, const String &field)
{
	stringInfo.rawFlag = false;
	stringInfo.binaryFlag = false;
	stringInfo.wiseFlag = false;
	stringInfo.embedFlag = false;
	foreach_const (String, p, field) {
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

Expr_Root *Parser::ParseStream(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	Value result;
	AutoPtr<Expr_Root> pExprRoot(new Expr_Root());
	_pExprOwner = &pExprRoot->GetExprOwner();
	_pExprParent = pExprRoot.get();
	for (;;) {
		int chRaw = stream.GetChar(sig);
		if (sig.IsSignalled()) {
			SetError(ERR_CodecError, "stream can not be recognized as %s encoded string",
										stream.GetCodec()->GetEncoding());
			return nullptr;
		}
		char ch = (chRaw < 0)? '\0' : static_cast<UChar>(chRaw);
		if (!ParseChar(env, ch)) {
			if (!sig.IsDetectEncoding()) return nullptr;
			sig.ClearSignal();
			Value value = sig.GetValue();
			if (value.Is_string()) {
				const char *encoding = value.GetString();
				AutoPtr<Codec> pCodec(Codec::CreateCodec(sig, encoding, true, false));
				if (sig.IsSignalled()) return nullptr;
				stream.SetCodec(pCodec.release());
			}
		}
		if (chRaw < 0) break;
	}
	return pExprRoot.release();
}

Expr_Root *Parser::ParseStream(Environment &env, const char *pathName, const char *encoding)
{
	Signal &sig = env.GetSignal();
	String pathNameMod;
	do {
		bool zippedFlag = false;
		String fileName;
		PathMgr::SplitFileName(pathName, nullptr, &fileName);
		const char *extName = PathMgr::SeekExtName(fileName.c_str());
		std::string baseName = std::string(fileName.c_str(), extName);
		if (::strcasecmp(extName, EXTNAME_Compound) == 0) {
			pathNameMod = OAL::JoinPathName(pathName, baseName.c_str());
			pathNameMod += EXTNAME_Script;
			zippedFlag = true;
		} else if (::strcasecmp(extName, EXTNAME_CompoundWin) == 0) {
			pathNameMod = OAL::JoinPathName(pathName, baseName.c_str());
			pathNameMod += EXTNAME_ScriptWin;
			zippedFlag = true;
		} else {
			pathNameMod = pathName;
		}
		if (zippedFlag && !env.ImportModules("zip", false, false)) return nullptr;
	} while (0);
	AutoPtr<Stream> pStream(Stream::Open(env,
									pathNameMod.c_str(), Stream::ATTR_Readable));
	if (sig.IsSignalled()) return nullptr;
	AutoPtr<Codec> pCodec(Codec::CreateCodec(sig, encoding, true, false));
	if (sig.IsSignalled()) return nullptr;
	pStream->SetCodec(pCodec.release());
	return ParseStream(env, *pStream);
}

bool Parser::ParseString(Environment &env, ExprOwner &exprOwner,
									const char *str, size_t len, bool parseNullFlag)
{
	Signal &sig = env.GetSignal();
	_pExprOwner = &exprOwner;
	_pExprParent = nullptr;
	for ( ; ; str++, len--) {
		if (!parseNullFlag && len == 0) break;
		char ch = (len == 0)? '\0' : *str;
		if (!ParseChar(env, ch)) {
			if (sig.IsDetectEncoding()) {
				sig.ClearSignal();
			} else {
				return false;
			}
		}
		if (len == 0) break;
	}
	return true;
}

void Parser::EvalConsoleChar(Environment &env,
						Expr_Root *pExprRoot, Stream *pConsole, char ch)
{
	Signal &sig = env.GetSignal();
	char chConv = '\0';
	Codec::Decoder *pDecoder = pConsole->GetCodec()->GetDecoder();
	Codec::Result rtn = pDecoder->FeedChar(ch, chConv);
	if (rtn != Codec::RESULT_Complete) return;
	_pExprOwner = &pExprRoot->GetExprOwner();
	_pExprParent = pExprRoot;
	_interactiveFlag = true;
	do {
		size_t cntExprPrev = _pExprOwner->size();
		if (!ParseChar(env, chConv)) {
			if (sig.IsDetectEncoding()) {
				sig.ClearSignal();
			} else {
				sig.PrintSignal(*pConsole);
				sig.ClearSignal();
				_stat = STAT_BOF;
				_lineHeadFlag = true;
				InitStack();
				//_stat = STAT_RecoverConsole;
			}
		} else if (_pExprOwner->size() > cntExprPrev) {
			for (ExprOwner::iterator ppExpr = _pExprOwner->begin() + cntExprPrev;
				 ppExpr != _pExprOwner->end(); ppExpr++) {
				const Expr *pExpr = *ppExpr;
				bool evalSymFuncFlag = true;
				Value result = pExpr->Exec(env, evalSymFuncFlag);
				if (sig.IsSignalled()) {
					if (sig.IsReqSaveHistory()) {
						// t.b.d
					} else {
						sig.PrintSignal(*pConsole);
					}
					sig.ClearSignal();
				} else if (!pExpr->GetSilentFlag() &&
						   env.GetGlobal()->GetEchoFlag() && result.IsValid()) {
					pConsole->Println(sig, result.ToString().c_str());
				}
			}
		}
	} while (pDecoder->FollowChar(chConv));
	_interactiveFlag = false;
}

bool Parser::FeedToken(Environment &env, const Token &token)
{
	if (IsTokenWatched()) {
		_pTokenWatcher->FeedToken(env, token);
	}
	if (_interactiveFlag || _pTokenInfoPrev->IsIdentical(TOKEN_RBrace)) {
		_pTokenInfoPrev = &token.GetTokenInfo();
		_lineNoOfTokenPrev = token.GetLineNo();
	} else {
		// Ignores EOL before a left brace-bracket so the bracket character appears to
		// be joined with the content in the previous line without a line break.
		if (_pTokenInfoPrev->IsIdentical(TOKEN_EOL)) {
			if (!token.IsType(TOKEN_LBrace) &&
				!_FeedToken(env, Token(*_pTokenInfoPrev, _lineNoOfTokenPrev))) {
				_pTokenInfoPrev = &token.GetTokenInfo();
				_lineNoOfTokenPrev = token.GetLineNo();
				return false;
			}
		}
		_pTokenInfoPrev = &token.GetTokenInfo();
		_lineNoOfTokenPrev = token.GetLineNo();
		if (token.IsType(TOKEN_EOL)) return true;
	}
	return _FeedToken(env, token);
}

bool Parser::_FeedToken(Environment &env, const Token &token)
{
	//::printf("FeedToken(%s)\n", token.GetSymbol());
	for (;;) {
		TokenStack::reverse_iterator pTokenTop =
								_tokenStack.SeekTerminal(_tokenStack.rbegin());
		//::printf("%s  << %s\n",
		//				_tokenStack.ToString().c_str(), token.GetTypeSymbol());
		Token::Precedence prec = Token::LookupPrec(*pTokenTop, token);
		if (pTokenTop->IsType(TOKEN_Begin) && token.IsSeparatorToken()) {
			size_t cntToken = _tokenStack.size();
			if (cntToken == 1) {
				// nothing to do
			} else if (cntToken == 2 && _tokenStack[1].IsType(TOKEN_Expr)) {
				Expr *pExpr = _tokenStack[1].GetExpr();
				if (_enablePreparatorFlag && !pExpr->Prepare(env)) {
					InitStack();
				} else {
					_tokenStack.pop_back();
					if (token.IsType(TOKEN_Semicolon)) pExpr->SetSilentFlag(true);
					if (_pExprOwner == nullptr) {
						Expr::Delete(pExpr);
					} else if (!EmitExpr(*_pExprOwner, _pExprParent, pExpr)) {
						InitStack();
					}
				}
			} else {
				// something's wrong
				SetError_InvalidToken(__LINE__);
				InitStack();
			}
			break;
		} else if (prec == Token::PREC_LT || prec == Token::PREC_EQ) {
			Token &tokenLast = _tokenStack.back();
			// concatenation of two sequences of string, binary and embed-string
			if (tokenLast.IsType(TOKEN_String) && token.IsType(TOKEN_String)) {
				tokenLast.AddString(token.GetStringSTL());
			} else if (tokenLast.IsType(TOKEN_Binary) && token.IsType(TOKEN_Binary)) {
				tokenLast.AddString(token.GetStringSTL());
			} else if (tokenLast.IsType(TOKEN_EmbedString) && token.IsType(TOKEN_EmbedString)) {
				tokenLast.AddString(token.GetStringSTL());
			} else {
				_tokenStack.push_back(token);
			}
			break;
		} else if (prec == Token::PREC_GT) {
			TokenStack::reverse_iterator pTokenLeft;
			TokenStack::reverse_iterator pTokenRight = pTokenTop;
			while (1) {
				pTokenLeft = _tokenStack.SeekTerminal(pTokenRight + 1);
				if (Token::LookupPrec(*pTokenLeft, *pTokenRight) == Token::PREC_LT) {
					pTokenLeft--;
					break;
				}
				pTokenRight = pTokenLeft;
			}
			size_t cntToken = std::distance(_tokenStack.rbegin(), pTokenLeft) + 1;
			bool rtn;
			if (cntToken == 1) {
				rtn = ReduceOneToken(env);
			} else if (cntToken == 2) {
				rtn = ReduceTwoTokens(env);
			} else if (cntToken == 3) {
				rtn = ReduceThreeTokens(env);
			} else if (cntToken == 4) {
				rtn = ReduceFourTokens(env);
			} else if (cntToken == 5) {
				rtn = ReduceFiveTokens(env);
			} else {
				SetError_InvalidToken(__LINE__);
				rtn = false;
			}
			if (!rtn) {
				InitStack();
				break;
			}
		} else if (token.IsCloseToken()) {
			SetError(ERR_SyntaxError, "unmatched closing character");
			InitStack();
			break;
		} else {
			SetError_InvalidToken(__LINE__);
			InitStack();
			break;
		}
	}
	return env.IsNoSignalled();
}

bool Parser::EmitExpr(ExprOwner &exprOwner, const Expr *pExprParent, Expr *pExpr)
{
	if (pExpr->IsCaller()) {
		Expr_Caller *pExprCaller = dynamic_cast<Expr_Caller *>(pExpr);
		if (!pExprCaller->IsTrailer()) {
			// nothing to do
		} else if (exprOwner.empty()) {
			// nothing to do
		} else if (exprOwner.back()->IsCaller()) {
			Expr_Caller *pExprLeader = dynamic_cast<Expr_Caller *>(exprOwner.back());
			pExprLeader->GetLastTrailer()->SetTrailer(pExprCaller);
			return true;
		} else {
			SetError(ERR_SyntaxError, "trailer must be placed after a caller expression");
			return false;
		}
	}
	pExpr->SetParent(pExprParent);
	exprOwner.push_back(pExpr);
	return true;
}

bool Parser::ReduceOneToken(Environment &env)
{
	Expr *pExpr;
	Token &token1 = _tokenStack.Peek(0);
	int lineNoTop = token1.GetLineNo();
	int lineNoBtm = token1.GetLineNo();
	if (token1.IsType(TOKEN_Number)) {
		DBGPARSER(::printf("Reduce: Expr -> Number\n"));
		Expr_Value *pExprEx = new Expr_Value(Value(ToNumber(token1.GetString())));
		pExprEx->SetScript(token1.GetStringSTL());
		pExpr = pExprEx;
	} else if (token1.IsType(TOKEN_String)) {
		DBGPARSER(::printf("Reduce: Expr -> String\n"));
		pExpr = new Expr_Value(Value(token1.GetStringSTL()));
	} else if (token1.IsType(TOKEN_Binary)) {
		DBGPARSER(::printf("Reduce: Expr -> Binary\n"));
		pExpr = new Expr_Value(Value(new Object_binary(env,
						   Binary(token1.GetString(), token1.GetStringSize()), false)));
	} else if (token1.IsType(TOKEN_EmbedString)) {
		DBGPARSER(::printf("Reduce: Expr -> EmbedString\n"));
		AutoPtr<Template> pTemplate(new Template());
		bool autoIndentFlag = true;
		bool appendLastEOLFlag = false;
		if (!pTemplate->Parse(env, token1.GetString(), nullptr,
							  autoIndentFlag, appendLastEOLFlag)) goto error_done;
		pExpr = new Expr_EmbedString(pTemplate.release(), token1.GetStringSTL());
	} else if (token1.IsType(TOKEN_Symbol)) {
		DBGPARSER(::printf("Reduce: Expr -> Symbol\n"));
		const Symbol *pSymbol = Symbol::Add(token1.GetString());
		pExpr = new Expr_Identifier(pSymbol);
	} else if (token1.IsType(TOKEN_NumberSuffixed)) {
		DBGPARSER(::printf("Reduce: Expr -> Suffixed\n"));
		pExpr = new Expr_Suffixed(token1.GetStringSTL(), true, Symbol::Add(token1.GetSuffix()));
	} else if (token1.IsType(TOKEN_StringSuffixed)) {
		DBGPARSER(::printf("Reduce: Expr -> Suffixed\n"));
		pExpr = new Expr_Suffixed(token1.GetStringSTL(), false, Symbol::Add(token1.GetSuffix()));
	} else if (token1.IsType(TOKEN_Add)) {
		DBGPARSER(::printf("Reduce: Expr -> '+'\n"));
		pExpr = new Expr_Identifier(Symbol::Plus);
	} else if (token1.IsType(TOKEN_Mul)) {
		DBGPARSER(::printf("Reduce: Expr -> '*'\n"));
		pExpr = new Expr_Identifier(Symbol::Ast);
	} else if (token1.IsType(TOKEN_Question)) {
		DBGPARSER(::printf("Reduce: Expr -> '?'\n"));
		pExpr = new Expr_Identifier(Symbol::Quest);
	} else if (token1.IsType(TOKEN_Sub)) {
		DBGPARSER(::printf("Reduce: Expr -> '-'\n"));
		pExpr = new Expr_Identifier(Symbol::Hyphen);
	} else {
		SetError_InvalidToken(__LINE__);
		goto error_done;
	}
	_tokenStack.pop_back();
	pExpr->SetSourceInfo(_pSourceName->Reference(), lineNoTop, lineNoBtm);
	_tokenStack.push_back(Token(TOKEN_Expr, pExpr));
	return true;
error_done:
	_tokenStack.pop_back();
	return false;
}

bool Parser::ReduceTwoTokens(Environment &env)
{
	Expr *pExpr;
	Token &token1 = _tokenStack.Peek(1);
	Token &token2 = _tokenStack.Peek(0);
	int lineNoTop = token1.GetLineNo();
	int lineNoBtm = token2.GetLineNo();
	if (token1.IsType(TOKEN_LParenthesis)) {
		if (token2.IsType(TOKEN_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> '(' ')'\n"));
			Expr_Iterer *pExprIterer =
						dynamic_cast<Expr_Iterer *>(token1.GetExpr());
			if (pExprIterer == nullptr) {
				pExprIterer = new Expr_Iterer();
			}
			pExpr = pExprIterer;
		} else if (token2.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '(' -> '(' EOL\n"));
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_LBracket)) {
		if (token2.IsType(TOKEN_RBracket)) {
			DBGPARSER(::printf("Reduce: Expr -> '[' ']'\n"));
			Expr_Lister *pExprLister =
						dynamic_cast<Expr_Lister *>(token1.GetExpr());
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
			}
			pExpr = pExprLister;
		} else if (token2.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '[' -> '[' EOL\n"));
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_LBrace)) {
		if (token2.IsType(TOKEN_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> '{' '}'\n"));
			Expr_Block *pExprBlock =
						dynamic_cast<Expr_Block *>(token1.GetExpr());
			if (pExprBlock == nullptr) {
				pExprBlock = new Expr_Block();
			}
			pExpr = pExprBlock;
		} else if (token2.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '{' -> '{' EOL\n"));
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_LBlockParam)) {
		if (token2.IsType(TOKEN_RBlockParam)) {
			// this is a special case of reducing
			DBGPARSER(::printf("do (Reduce: Expr -> '|' '|') "
					"and then attach the Expr to the preceeding LBrace\n"));
			Expr_Lister *pExprBlockParam = dynamic_cast<Expr_Lister *>(token1.GetExpr());
			if (pExprBlockParam == nullptr) {
				pExprBlockParam = new Expr_Lister();
			}
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			Token &tokenPrev = _tokenStack.Peek(0);
			if (tokenPrev.IsType(TOKEN_LBrace)) {
				Expr_Block *pExprBlock =
							dynamic_cast<Expr_Block *>(tokenPrev.GetExpr());
				if (pExprBlock == nullptr) {
					pExprBlock = new Expr_Block();
					tokenPrev.SetExpr(pExprBlock);
				}
				pExprBlock->SetExprOwnerParam(pExprBlockParam->GetExprOwner().Reference());
				Expr::Delete(pExprBlockParam);
			} else {
				Expr::Delete(pExprBlockParam);
				SetError(ERR_SyntaxError, "invalid placement of block parameter");
				goto error_done;
			}
			return true;
		} else if (token2.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '|' -> '|' EOL\n"));
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr) && token2.IsType(TOKEN_Symbol)) {
		// this is a special case of reducing
		DBGPARSER(::printf("Reduce: Expr Expr -> Expr Symbol\n"));
		const Symbol *pSymbol = Symbol::Add(token2.GetString());
		pExpr = new Expr_Identifier(pSymbol);
		int lineNoTop = _tokenStack.Peek(0).GetLineNo();
		_tokenStack.pop_back();
		pExpr->SetSourceInfo(_pSourceName->Reference(), lineNoTop, lineNoBtm);
		_tokenStack.push_back(Token(TOKEN_Expr, pExpr));
		return true;
	} else if (token2.IsType(TOKEN_Expr)) {
		if (token1.IsType(TOKEN_Quote)) {
			DBGPARSER(::printf("Reduce: Expr -> '`' Expr\n"));
			pExpr = new Expr_Quote(token2.GetExpr());
		} else if (token1.IsType(TOKEN_Add)) {
			DBGPARSER(::printf("Reduce: Expr -> '+' Expr\n"));
			pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_Pos), token2.GetExpr());
		} else if (token1.IsType(TOKEN_Sub)) {
			DBGPARSER(::printf("Reduce: Expr -> '-' Expr\n"));
			pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_Neg), token2.GetExpr());
		} else if (token1.IsType(TOKEN_Inv)) {
			DBGPARSER(::printf("Reduce: Expr -> '~' Expr\n"));
			pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_Inv), token2.GetExpr());
		} else if (token1.IsType(TOKEN_Not)) {
			DBGPARSER(::printf("Reduce: Expr -> '!' Expr\n"));
			pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_Not), token2.GetExpr());
		} else if (token1.IsType(TOKEN_Mod)) {
			DBGPARSER(::printf("Reduce: Expr -> '%%%%' Expr\n"));
			if (token2.GetExpr()->IsBlock()) {
				// %{..}
				Expr *pExprCar = new Expr_Identifier(Symbol::Percnt);
				Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(token2.GetExpr());
				pExpr = CreateCaller(env, pExprCar, nullptr, pExprBlock, nullptr);
				if (pExpr == nullptr) goto error_done;
			} else {
				pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_Mod), token2.GetExpr());
			}
		} else if (token1.IsType(TOKEN_ModMod)) {
			DBGPARSER(::printf("Reduce: Expr -> '%%%%' Expr\n"));
			if (token2.GetExpr()->IsBlock()) {
				// %%{..}
				Expr *pExprCar = new Expr_Identifier(Symbol::PercntPercnt);
				Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(token2.GetExpr());
				pExpr = CreateCaller(env, pExprCar, nullptr, pExprBlock, nullptr);
				if (pExpr == nullptr) goto error_done;
			} else {
				SetError_InvalidToken(__LINE__);
				goto error_done;
			}
		} else if (token1.IsType(TOKEN_And)) {
			DBGPARSER(::printf("Reduce: Expr -> '&' Expr\n"));
			if (token2.GetExpr()->IsBlock()) {
				// &{..}
				Expr *pExprCar = new Expr_Identifier(Symbol::Amp);
				Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(token2.GetExpr());
				pExpr = CreateCaller(env, pExprCar, nullptr, pExprBlock, nullptr);
				if (pExpr == nullptr) goto error_done;
			} else {
				pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_And), token2.GetExpr());
			}
		} else if (token1.IsType(TOKEN_Mul)) {
			DBGPARSER(::printf("Reduce: Expr -> '*' Expr\n"));
			pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_Mul), token2.GetExpr());
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr)) {
		if (token2.IsType(TOKEN_Add)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '+'\n"));
			pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_PostPos), token1.GetExpr());
		} else if (token2.IsType(TOKEN_Mul)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '*'\n"));
			pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_Each), token1.GetExpr());
		} else if (token2.IsType(TOKEN_Question)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '?'\n"));
			pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_Question), token1.GetExpr());
		} else if (token2.IsType(TOKEN_Mod)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '%%'\n"));
			pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_PostMod), token1.GetExpr());
		} else if (token2.IsType(TOKEN_Seq)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr ..\n"));
			pExpr = new Expr_UnaryOp(env.GetOperator(OPTYPE_SeqInf), token1.GetExpr());
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else {
		SetError_InvalidToken(__LINE__);
		goto error_done;
	}
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	pExpr->SetSourceInfo(_pSourceName->Reference(), lineNoTop, lineNoBtm);
	_tokenStack.push_back(Token(TOKEN_Expr, pExpr));
	return true;
error_done:
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	return false;
}

bool Parser::ReduceThreeTokens(Environment &env)
{
	Signal &sig = env.GetSignal();
	Expr *pExpr;
	Token &token1 = _tokenStack.Peek(2);
	Token &token2 = _tokenStack.Peek(1);
	Token &token3 = _tokenStack.Peek(0);
	int lineNoTop = token1.GetLineNo();
	int lineNoBtm = token3.GetLineNo();
	if (token1.IsType(TOKEN_LParenthesis) && token2.IsType(TOKEN_Expr)) {
		Expr_Iterer *pExprIterer = dynamic_cast<Expr_Iterer *>(token1.GetExpr());
		if (token3.IsType(TOKEN_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> '(' Expr ')'\n"));
			if (pExprIterer == nullptr) {
				pExpr = token2.GetExpr();	// treat expr as non-list
			} else {
				if (!EmitExpr(pExprIterer->GetExprOwner(), pExprIterer, token2.GetExpr())) return false;
				pExpr = pExprIterer;
			}
		} else if (token3.IsType(TOKEN_Comma) || token3.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '(' -> '(' Expr ','\n"));
			if (pExprIterer == nullptr) {
				pExprIterer = new Expr_Iterer();
				token1.SetExpr(pExprIterer);
			}
			if (!EmitExpr(pExprIterer->GetExprOwner(), pExprIterer, token2.GetExpr())) return false;
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_LBracket) && token2.IsType(TOKEN_Expr)) {
		Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(token1.GetExpr());
		if (token3.IsType(TOKEN_RBracket)) {
			DBGPARSER(::printf("Reduce: Expr -> '[' Expr ']'\n"));
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
			}
			if (!EmitExpr(pExprLister->GetExprOwner(), pExprLister, token2.GetExpr())) return false;
			pExpr = pExprLister;
		} else if (token3.IsType(TOKEN_Comma) || token3.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '[' -> '[' Expr ','\n"));
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
				token1.SetExpr(pExprLister);
			}
			if (!EmitExpr(pExprLister->GetExprOwner(), pExprLister, token2.GetExpr())) return false;
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr) && token2.IsType(TOKEN_LParenthesis)) {
		if (token3.IsType(TOKEN_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '(' ')'\n"));
			Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(token2.GetExpr());
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
			}
			Expr_Caller *pExprCaller =
				CreateCaller(env, token1.GetExpr(), pExprLister, nullptr, nullptr);
			if (pExprCaller == nullptr) goto error_done;
			pExpr = pExprCaller;
		} else if (token3.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '(' -> Expr '(' EOL\n"));
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr) && token2.IsType(TOKEN_LBrace)) {
		if (token3.IsType(TOKEN_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '{' '}'\n"));
			Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(token2.GetExpr());
			if (token1.GetExpr()->IsCaller()) {
				Expr_Caller *pExprCaller = dynamic_cast<Expr_Caller *>(token1.GetExpr());
				if (pExprBlock == nullptr) {
					pExprBlock = new Expr_Block();
				}
				pExprCaller->GetLastTrailer()->SetBlock(pExprBlock);
				pExpr = pExprCaller;
			} else {
				if (pExprBlock == nullptr) {
					pExprBlock = new Expr_Block();
				}
				Expr_Caller *pExprCaller =
					CreateCaller(env, token1.GetExpr(), nullptr, pExprBlock, nullptr);
				if (pExprCaller == nullptr) goto error_done;
				pExpr = pExprCaller;
			}
		} else if (token3.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '{' -> Expr '{' EOL\n"));
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr) && token2.IsType(TOKEN_LBracket)) {
		if (token3.IsType(TOKEN_RBracket)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '[' ']'\n"));
			Expr *pExprTgt = token1.GetExpr();
			Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(token2.GetExpr());
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
			}
			pExpr = new Expr_Indexer(pExprTgt, pExprLister);
		} else if (token3.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '[' -> Expr '[' EOL\n"));
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_LBrace) && token2.IsType(TOKEN_Expr)) {
		Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(token1.GetExpr());
		if (token3.IsType(TOKEN_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> '{' Expr '}'\n"));
			if (pExprBlock == nullptr) {
				pExprBlock = new Expr_Block();
			}
			if (!EmitExpr(pExprBlock->GetExprOwner(), pExprBlock, token2.GetExpr())) return false;
			pExpr = pExprBlock;
		} else if (token3.IsType(TOKEN_Comma) ||
					token3.IsType(TOKEN_Semicolon) || token3.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '{' -> '{' Expr ','\n"));
			if (pExprBlock == nullptr) {
				pExprBlock = new Expr_Block();
				token1.SetExpr(pExprBlock);
			}
			if (!EmitExpr(pExprBlock->GetExprOwner(), pExprBlock, token2.GetExpr())) return false;
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_LBlockParam) && token2.IsType(TOKEN_Expr)) {
		Expr_Lister *pExprBlockParam = dynamic_cast<Expr_Lister *>(token1.GetExpr());
		if (token3.IsType(TOKEN_RBlockParam)) {
			// this is a special case of reducing
			DBGPARSER(::printf("do (Reduce: Expr -> '|' Expr '|') "
					"and then attach the Expr to the preceeding LBrace\n"));
			if (pExprBlockParam == nullptr) {
				pExprBlockParam = new Expr_Lister();
			}
			if (!EmitExpr(pExprBlockParam->GetExprOwner(), pExprBlockParam, token2.GetExpr())) return false;
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			Token &tokenPrev = _tokenStack.Peek(0);
			if (tokenPrev.IsType(TOKEN_LBrace)) {
				Expr_Block *pExprBlock =
							dynamic_cast<Expr_Block *>(tokenPrev.GetExpr());
				if (pExprBlock == nullptr) {
					pExprBlock = new Expr_Block();
					tokenPrev.SetExpr(pExprBlock);
				}
				pExprBlock->SetExprOwnerParam(pExprBlockParam->GetExprOwner().Reference());
				Expr::Delete(pExprBlockParam);
			} else {
				Expr::Delete(pExprBlockParam);
				SetError(ERR_SyntaxError, "invalid placement of block parameter");
				goto error_done;
			}
			return true;
		} else if (token3.IsType(TOKEN_Comma) ||
					token3.IsType(TOKEN_Semicolon) || token3.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: '|' -> '|' Expr ','\n"));
			if (pExprBlockParam == nullptr) {
				pExprBlockParam = new Expr_Lister();
				token1.SetExpr(pExprBlockParam);
			}
			if (!EmitExpr(pExprBlockParam->GetExprOwner(), pExprBlockParam, token2.GetExpr())) return false;
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr) && token3.IsType(TOKEN_Expr)) {
		Expr *pExprLeft = token1.GetExpr();
		Expr *pExprRight = token3.GetExpr();
		if (token2.IsType(TOKEN_Add)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr + Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Add), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Sub)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr - Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Sub), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Mul)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr * Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Mul), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Div)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr / Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Div), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Mod)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr %% Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Mod), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_ModMod)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr %%%% Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_ModMod), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_DotProd)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr <.> Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_DotProd), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_CrossProd)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr <*> Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_CrossProd), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Pow)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr ** Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Pow), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Eq)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr == Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Eq), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Ne)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr != Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Ne), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Lt)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr < Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Lt), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Gt)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr > Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Gt), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Le)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr <= Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Le), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Ge)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr >= Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Ge), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Cmp)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr <=> Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Cmp), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Contains)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr in Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Contains), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Assign)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr = Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, nullptr);
		} else if (token2.IsType(TOKEN_AssignAdd)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr += Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_Add));
		} else if (token2.IsType(TOKEN_AssignSub)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr -= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_Sub));
		} else if (token2.IsType(TOKEN_AssignMul)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr *= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_Mul));
		} else if (token2.IsType(TOKEN_AssignDiv)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr /= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_Div));
		} else if (token2.IsType(TOKEN_AssignMod)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr %%= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_Mod));
		} else if (token2.IsType(TOKEN_AssignPow)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr **= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_Pow));
		} else if (token2.IsType(TOKEN_AssignOr)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr |= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_Or));
		} else if (token2.IsType(TOKEN_AssignAnd)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr &= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_And));
		} else if (token2.IsType(TOKEN_AssignXor)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr ^= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_Xor));
		} else if (token2.IsType(TOKEN_AssignShl)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr <<= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_Shl));
		} else if (token2.IsType(TOKEN_AssignShr)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr >>= Expr\n"));
			pExpr = new Expr_Assign(pExprLeft, pExprRight, env.GetOperator(OPTYPE_Shr));
		} else if (token2.IsType(TOKEN_Pair)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr => Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Pair), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Colon) || token2.IsType(TOKEN_ColonAfterSuffix)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr : Expr\n"));
			Expr *pExprDst = pExprLeft;
			if (pExprDst->IsUnaryOpSuffix()) {
				pExprDst = dynamic_cast<Expr_UnaryOp *>(pExprDst)->GetChild();
			}
			if (pExprDst->IsIndexer()) {
				pExprDst = dynamic_cast<Expr_Indexer *>(pExprDst)->GetCar();
			}
			if (pExprRight->IsIdentifier()) {
				const Symbol *pSymbol = dynamic_cast<Expr_Identifier *>(pExprRight)->GetSymbol();
				bool optAttrFlag = false;
				SymbolList *pAttrFront = nullptr;
				if (pExprDst->IsIdentifier()) {
					Expr_Identifier *pExprIdentifier =
									dynamic_cast<Expr_Identifier *>(pExprDst);
					optAttrFlag = pExprIdentifier->AddAttr(pSymbol);
					pAttrFront = &pExprIdentifier->GetAttrFront();
				} else if (pExprDst->IsCaller()) {
					Expr_Caller *pExprCaller = dynamic_cast<Expr_Caller *>(pExprDst);
					Expr_Caller *pExprTrailer = pExprCaller->GetLastTrailer();
					optAttrFlag = pExprTrailer->AddAttr(pSymbol);
					pAttrFront = &pExprTrailer->GetAttrFront();
				} else {
					SetError_InvalidToken(__LINE__);
					goto error_done;
				}
				if (optAttrFlag && pAttrFront->empty()) pAttrFront->push_back(pSymbol);
				pExpr = pExprLeft;
				Expr::Delete(pExprRight);
			} else if (pExprRight->IsMember()) {
				Expr_Member *pExprMember = dynamic_cast<Expr_Member *>(pExprRight);
				SymbolList *pAttrFront = nullptr;
				if (pExprDst->IsIdentifier()) {
					Expr_Identifier *pExprIdentifierDst =
									dynamic_cast<Expr_Identifier *>(pExprDst);
					pAttrFront = &pExprIdentifierDst->GetAttrFront();
					const Expr_Identifier *pExprIdentifier = pExprMember->GetSelector();
					pExprIdentifierDst->AddAttrs(pExprIdentifier->GetAttrs());
					pExprIdentifierDst->AddAttrsOpt(pExprIdentifier->GetAttrsOpt());
				} else if (pExprDst->IsCaller()) {
					Expr_Caller *pExprCaller = dynamic_cast<Expr_Caller *>(pExprDst);
					Expr_Caller *pExprTrailer = pExprCaller->GetLastTrailer();
					pAttrFront = &pExprTrailer->GetAttrFront();
					const Expr_Identifier *pExprIdentifier = pExprMember->GetSelector();
					pExprTrailer->AddAttrs(pExprIdentifier->GetAttrs());
					pExprTrailer->AddAttrsOpt(pExprIdentifier->GetAttrsOpt());
				} else {
					SetError_InvalidToken(__LINE__);
					goto error_done;
				}
				if (!pAttrFront->empty()) {
					sig.SetError(ERR_SyntaxError,
							"value type must be specified as a first attribute");
					goto error_done;
				}
				if (!pAttrFront->AddFromExpr(pExprRight)) {
					sig.SetError(ERR_SyntaxError, "invalid declaration of value type");
					goto error_done;
				}
				pExpr = pExprLeft;
				Expr::Delete(pExprRight);
			} else if (pExprRight->IsLister()) {
				ExprList &exprList =
							dynamic_cast<Expr_Lister *>(pExprRight)->GetExprOwner();
				if (pExprDst->IsIdentifier()) {
					sig.SetError(ERR_TypeError,
									"identifiers cannot declare optional attributes");
					goto error_done;
				} else if (pExprDst->IsCaller()) {
					Expr_Caller *pExprCaller = dynamic_cast<Expr_Caller *>(pExprDst);
					pExprCaller = pExprCaller->GetLastTrailer();
					foreach (ExprList, ppExpr, exprList) {
						Expr *pExpr = *ppExpr;
						if (!pExpr->IsIdentifier()) {
							SetError_InvalidToken(__LINE__);
							goto error_done;
						}
						const Symbol *pSymbol =
								dynamic_cast<Expr_Identifier *>(pExpr)->GetSymbol();
						pExprCaller->AddAttrOpt(pSymbol);
					}
				} else {
					SetError_InvalidToken(__LINE__);
					goto error_done;
				}
				pExpr = pExprLeft;
				Expr::Delete(pExprRight);
			} else {
				SetError_InvalidToken(__LINE__);
				goto error_done;
			}
		} else if (token2.IsType(TOKEN_Dot)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr . Expr\n"));
			if (!pExprRight->IsIdentifier()) {
				SetError_InvalidToken(__LINE__);
				goto error_done;
			}
			pExpr = new Expr_Member(pExprLeft, dynamic_cast<Expr_Identifier *>(pExprRight),
									Expr_Member::MODE_Normal);
		} else if (token2.IsType(TOKEN_ColonColon)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr :: Expr\n"));
			if (!pExprRight->IsIdentifier()) {
				SetError_InvalidToken(__LINE__);
				goto error_done;
			}
			pExpr = new Expr_Member(pExprLeft, dynamic_cast<Expr_Identifier *>(pExprRight),
									Expr_Member::MODE_MapToList);
		} else if (token2.IsType(TOKEN_ColonAsterisk)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr :* Expr\n"));
			if (!pExprRight->IsIdentifier()) {
				SetError_InvalidToken(__LINE__);
				goto error_done;
			}
			pExpr = new Expr_Member(pExprLeft, dynamic_cast<Expr_Identifier *>(pExprRight),
									Expr_Member::MODE_MapToIter);
		} else if (token2.IsType(TOKEN_ColonAnd)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr :& Expr\n"));
			if (!pExprRight->IsIdentifier()) {
				SetError_InvalidToken(__LINE__);
				goto error_done;
			}
			pExpr = new Expr_Member(pExprLeft, dynamic_cast<Expr_Identifier *>(pExprRight),
									Expr_Member::MODE_MapAlong);
		} else if (token2.IsType(TOKEN_OrOr)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr || Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_OrOr), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_AndAnd)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr && Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_AndAnd), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Or)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr | Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Or), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_And)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr & Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_And), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Xor)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr ^ Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Xor), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Shl)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr << Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Shl), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Shr)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr >> Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Shr), pExprLeft, pExprRight);
		} else if (token2.IsType(TOKEN_Seq)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr .. Expr\n"));
			pExpr = new Expr_BinaryOp(env.GetOperator(OPTYPE_Seq), pExprLeft, pExprRight);
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else {
		SetError_InvalidToken(__LINE__);
		goto error_done;
	}
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	pExpr->SetSourceInfo(_pSourceName->Reference(), lineNoTop, lineNoBtm);
	_tokenStack.push_back(Token(TOKEN_Expr, pExpr));
	return true;
error_done:
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	return false;
}

bool Parser::ReduceFourTokens(Environment &env)
{
	Expr *pExpr;
	Token &token1 = _tokenStack.Peek(3);
	Token &token2 = _tokenStack.Peek(2);
	Token &token3 = _tokenStack.Peek(1);
	Token &token4 = _tokenStack.Peek(0);
	int lineNoTop = token1.GetLineNo();
	int lineNoBtm = token4.GetLineNo();
	if (token1.IsType(TOKEN_Expr) && token2.IsType(TOKEN_Expr) &&
											token3.IsType(TOKEN_LParenthesis)) {
		if (token4.IsType(TOKEN_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr Expr '(' ')'\n"));
			Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(token3.GetExpr());
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
			}
			if (!token1.GetExpr()->IsCaller()) {
				SetError_InvalidToken(__LINE__);
				goto error_done;
			}
			Expr_Caller *pExprLeader = dynamic_cast<Expr_Caller *>(token1.GetExpr());
			Expr_Caller *pExprCaller =
				CreateCaller(env, token2.GetExpr(), pExprLister, nullptr, pExprLeader);
			if (pExprCaller == nullptr) goto error_done;
			pExprLeader->AddTrailingExpr(pExprCaller);
			pExpr = pExprLeader;
		} else if (token4.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr Expr '(' -> Expr Expr '(' EOL\n"));
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr) && token2.IsType(TOKEN_Expr) &&
												token3.IsType(TOKEN_LBrace)) {
		if (token4.IsType(TOKEN_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr Expr '{' '}'\n"));
			Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(token3.GetExpr());
			if (pExprBlock == nullptr) {
				pExprBlock = new Expr_Block();
			}
			if (!token1.GetExpr()->IsCaller()) {
				SetError_InvalidToken(__LINE__);
				goto error_done;
			}
			Expr_Caller *pExprLeader = dynamic_cast<Expr_Caller *>(token1.GetExpr());
			Expr_Caller *pExprCaller = nullptr;
			if (token2.GetExpr()->IsCaller()) {
				pExprCaller = dynamic_cast<Expr_Caller *>(token2.GetExpr());
				pExprCaller->GetLastTrailer()->SetBlock(pExprBlock);
			} else {
				pExprCaller = CreateCaller(env, token2.GetExpr(), nullptr, pExprBlock, pExprLeader);
				if (pExprCaller == nullptr) goto error_done;
			}
			pExprLeader->AddTrailingExpr(pExprCaller);
			pExpr = pExprLeader;
		} else if (token4.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr Expr '{' -> Expr Expr '{' EOL\n"));
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr) &&
				token2.IsType(TOKEN_LParenthesis) && token3.IsType(TOKEN_Expr)) {
		Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(token2.GetExpr());
		if (token4.IsType(TOKEN_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '(' Expr ')'\n"));
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
			}
			if (!EmitExpr(pExprLister->GetExprOwner(), pExprLister, token3.GetExpr())) return false;
			Expr_Caller *pExprCaller =
				CreateCaller(env, token1.GetExpr(), pExprLister, nullptr, nullptr);
			if (pExprCaller == nullptr) goto error_done;
			pExpr = pExprCaller;
		} else if (token4.IsType(TOKEN_Comma) || token4.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '(' -> Expr '(' Expr ','\n"));
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
				token2.SetExpr(pExprLister);
			}
			if (!EmitExpr(pExprLister->GetExprOwner(), pExprLister, token3.GetExpr())) return false;
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr) &&
				token2.IsType(TOKEN_LBrace) && token3.IsType(TOKEN_Expr)) {
		Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(token2.GetExpr());
		if (token4.IsType(TOKEN_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '{' Expr '}'\n"));
			if (pExprBlock == nullptr) {
				pExprBlock = new Expr_Block();
			}
			if (!EmitExpr(pExprBlock->GetExprOwner(), pExprBlock, token3.GetExpr())) return false;
			if (token1.GetExpr()->IsCaller()) {
				Expr_Caller *pExprCaller = dynamic_cast<Expr_Caller *>(token1.GetExpr());
				pExprCaller->GetLastTrailer()->SetBlock(pExprBlock);
				pExpr = pExprCaller;
			} else {
				Expr_Caller *pExprCaller =
					CreateCaller(env, token1.GetExpr(), nullptr, pExprBlock, nullptr);
				if (pExprCaller == nullptr) goto error_done;
				pExpr = pExprCaller;
			}
		} else if (token4.IsType(TOKEN_Comma) ||
					token4.IsType(TOKEN_Semicolon) || token4.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '{' -> Expr '{' Expr ','\n"));
			if (pExprBlock == nullptr) {
				pExprBlock = new Expr_Block();
				token2.SetExpr(pExprBlock);
			}
			if (!EmitExpr(pExprBlock->GetExprOwner(), pExprBlock, token3.GetExpr())) return false;
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr) &&
				token2.IsType(TOKEN_LBracket) && token3.IsType(TOKEN_Expr)) {
		Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(token2.GetExpr());
		if (token4.IsType(TOKEN_RBracket)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr '[' Expr ']'\n"));
			Expr *pExprTgt = token1.GetExpr();
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
			}
			if (!EmitExpr(pExprLister->GetExprOwner(), pExprLister, token3.GetExpr())) return false;
			pExpr = new Expr_Indexer(pExprTgt, pExprLister);
		} else if (token4.IsType(TOKEN_Comma) || token4.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr '[' -> Expr '[' Expr ','\n"));
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
				token2.SetExpr(pExprLister);
			}
			if (!EmitExpr(pExprLister->GetExprOwner(), pExprLister, token3.GetExpr())) return false;
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else {
		SetError_InvalidToken(__LINE__);
		goto error_done;
	}
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	pExpr->SetSourceInfo(_pSourceName->Reference(), lineNoTop, lineNoBtm);
	_tokenStack.push_back(Token(TOKEN_Expr, pExpr));
	return true;
error_done:
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	return false;
}

bool Parser::ReduceFiveTokens(Environment &env)
{
	Expr *pExpr;
	Token &token1 = _tokenStack.Peek(4);
	Token &token2 = _tokenStack.Peek(3);
	Token &token3 = _tokenStack.Peek(2);
	Token &token4 = _tokenStack.Peek(1);
	Token &token5 = _tokenStack.Peek(0);
	int lineNoTop = token1.GetLineNo();
	int lineNoBtm = token5.GetLineNo();
	if (token1.IsType(TOKEN_Expr) && token2.IsType(TOKEN_Expr) &&
				token3.IsType(TOKEN_LParenthesis) && token4.IsType(TOKEN_Expr)) {
		Expr_Lister *pExprLister = dynamic_cast<Expr_Lister *>(token3.GetExpr());
		if (token5.IsType(TOKEN_RParenthesis)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr Expr '(' Expr ')'\n"));
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
			}
			if (!EmitExpr(pExprLister->GetExprOwner(), pExprLister, token4.GetExpr())) return false;
			if (!token1.GetExpr()->IsCaller()) {
				SetError_InvalidToken(__LINE__);
				goto error_done;
			}
			Expr_Caller *pExprLeader = dynamic_cast<Expr_Caller *>(token1.GetExpr());
			Expr_Caller *pExprCaller =
				CreateCaller(env, token2.GetExpr(), pExprLister, nullptr, pExprLeader);
			if (pExprCaller == nullptr) goto error_done;
			pExprLeader->AddTrailingExpr(pExprCaller);
			pExpr = pExprLeader;
		} else if (token5.IsType(TOKEN_Comma) || token5.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr Expr '(' -> Expr Expr '(' Expr ','\n"));
			if (pExprLister == nullptr) {
				pExprLister = new Expr_Lister();
				token3.SetExpr(pExprLister);
			}
			if (!EmitExpr(pExprLister->GetExprOwner(), pExprLister, token4.GetExpr())) return false;
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else if (token1.IsType(TOKEN_Expr) && token2.IsType(TOKEN_Expr) &&
				token3.IsType(TOKEN_LBrace) && token4.IsType(TOKEN_Expr)) {
		Expr_Block *pExprBlock = dynamic_cast<Expr_Block *>(token3.GetExpr());
		if (token5.IsType(TOKEN_RBrace)) {
			DBGPARSER(::printf("Reduce: Expr -> Expr Expr '{' Expr '}'\n"));
			if (pExprBlock == nullptr) {
				pExprBlock = new Expr_Block();
			}
			if (!EmitExpr(pExprBlock->GetExprOwner(), pExprBlock, token4.GetExpr())) return false;
			if (!token1.GetExpr()->IsCaller()) {
				SetError_InvalidToken(__LINE__);
				goto error_done;
			}
			Expr_Caller *pExprLeader = dynamic_cast<Expr_Caller *>(token1.GetExpr());
			Expr_Caller *pExprCaller = nullptr;
			if (token2.GetExpr()->IsCaller()) {
				pExprCaller = dynamic_cast<Expr_Caller *>(token2.GetExpr());
				pExprCaller->GetLastTrailer()->SetBlock(pExprBlock);
			} else {
				pExprCaller = CreateCaller(env, token2.GetExpr(), nullptr, pExprBlock, pExprLeader);
				if (pExprCaller == nullptr) goto error_done;
			}
			pExprLeader->AddTrailingExpr(pExprCaller);
			pExpr = pExprLeader;
		} else if (token5.IsType(TOKEN_Comma) ||
					token5.IsType(TOKEN_Semicolon) || token5.IsType(TOKEN_EOL)) {
			// this is a special case of reducing
			DBGPARSER(::printf("Reduce: Expr Expr '{' -> Expr Expr '{' Expr ','\n"));
			if (pExprBlock == nullptr) {
				pExprBlock = new Expr_Block();
				token3.SetExpr(pExprBlock);
			}
			if (!EmitExpr(pExprBlock->GetExprOwner(), pExprBlock, token4.GetExpr())) return false;
			_tokenStack.pop_back();
			_tokenStack.pop_back();
			return true;
		} else {
			SetError_InvalidToken(__LINE__);
			goto error_done;
		}
	} else {
		SetError_InvalidToken(__LINE__);
		goto error_done;
	}
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	pExpr->SetSourceInfo(_pSourceName->Reference(), lineNoTop, lineNoBtm);
	_tokenStack.push_back(Token(TOKEN_Expr, pExpr));
	return true;
error_done:
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	_tokenStack.pop_back();
	return false;
}

void Parser::SetError(ErrorType errType, const char *format, ...)
{
	String textPre;
	if (!_pSourceName->GetStringSTL().empty()) {
		String fileName;
		PathMgr::SplitFileName(_pSourceName->GetString(), nullptr, &fileName);
		textPre += fileName;
	}
	do {
		char buff[64];
		::sprintf(buff, ":%d: ", GetLineNo());
		textPre += buff;
	} while (0);
	va_list ap;
	va_start(ap, format);
	_sig.SetErrorV(errType, format, ap, textPre.c_str());
	va_end(ap);
}

void Parser::SetError_InvalidToken()
{
	SetError(ERR_SyntaxError, "invalid token");
}

void Parser::SetError_InvalidToken(int lineno)
{
	SetError(ERR_SyntaxError, "invalid token (%d) .. %s", lineno,
										_tokenStack.ToString().c_str());
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
