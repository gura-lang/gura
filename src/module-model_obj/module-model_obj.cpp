//=============================================================================
// Gura module: model.obj
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(model_obj)

//-----------------------------------------------------------------------------
// Tokenizer
//-----------------------------------------------------------------------------
TokenId Tokenizer::Tokenize(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	_iChar = 0;
	if (_tokenIdPending != TOKEN_None) {
		TokenId tokenId = _tokenIdPending;
		_tokenIdPending = TOKEN_None;
		return tokenId;
	}
	for (;;) {
		int chRaw = stream.GetChar(sig);
		if (sig.IsSignalled()) break;
		char ch = (chRaw < 0)? '\0' : static_cast<char>(static_cast<UChar>(chRaw));
		Gura_BeginPushbackRegion();
		switch (_stat) {
		case STAT_LineTop: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '\n' || ch == '\0') {
				// nothing to do
			} else {
				Gura_Pushback();
				_stat = STAT_Field;
			}
			break;
		}
		case STAT_Field: {
			if (ch == ' ' || ch == '\t') {
				_stat = STAT_SkipWhite;
				_field[_iChar] = '\0';
				return TOKEN_Field;
			} else if (ch == '\n') {
				_tokenIdPending = TOKEN_EOL;
				_stat = STAT_LineTop;
				_field[_iChar] = '\0';
				return TOKEN_Field;
			} else if (ch == '\0') {
				_tokenIdPending = TOKEN_EOF;
				_stat = STAT_FileEnd;
				_field[_iChar] = '\0';
				return TOKEN_Field;
			} else {
				_field[_iChar++] = ch;
				if (_iChar >= ArraySizeOf(_field)) {
					SetError_FormatError(env);
					return TOKEN_EOF;
				}
			}
			break;
		}
		case STAT_SkipWhite: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '\n') {
				_stat = STAT_LineTop;
			} else if (ch == '\0') {
				_stat = STAT_LineTop;
			} else {
				Gura_Pushback();
				_stat = STAT_Field;
			}
			break;
		}
		case STAT_FileEnd: {
			// nothing to do
			break;
		}
		}
		Gura_EndPushbackRegion();
		if (ch == '\0') break;
	}
	return TOKEN_EOF;
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// model.obj.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function adds two numbers and returns the result.\n");
}

Gura_ImplementFunction(test)
{
	return Value(arg.GetNumber(0) + arg.GetNumber(1));
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_FormatError(Environment &env)
{
	env.SetError(ERR_FormatError, "invalid format of OBJ file");
}

Gura_EndModuleBody(model_obj, obj)

Gura_RegisterModule(model_obj)
