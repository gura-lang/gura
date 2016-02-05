//=============================================================================
// Gura module: model.obj
// Specification: http://www.martinreddy.net/gfx/3d/OBJ.spec
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
			} else if (ch == '#') {
				_stat = STAT_SkipToNextLine;
			} else {
				Gura_Pushback();
				_stat = STAT_Field;
			}
			break;
		}
		case STAT_SkipToNextLine: {
			if (ch == '\n') {
				_stat = STAT_LineTop;
			} else {
				// nothing to do
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
// model.obj.test(stream:stream)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(test)
{
	enum {
		STAT_keyword,
	} stat = STAT_keyword;
	Stream &stream = arg.GetStream(0);
	Tokenizer tokenizer;
	for (;;) {
		TokenId tokenId = tokenizer.Tokenize(env, stream);
		switch (stat) {
		case STAT_keyword: {
			if (tokenId == TOKEN_Field) {
				const char *field = tokenizer.GetField();
				::printf("%s\n", field);
				if (::strcmp(field, "v") == 0) {			// v x y z w
				} else if (::strcmp(field, "vt") == 0) {	// vt u v w
				} else if (::strcmp(field, "vn") == 0) {	// vn i j k
				} else if (::strcmp(field, "vp") == 0) {	// vp u v w
				} else if (::strcmp(field, "cstype") == 0) {// cstype rat type
				} else if (::strcmp(field, "deg") == 0) {	// deg degu degv
				} else if (::strcmp(field, "bmat") == 0) {	// bmat u|v matrix
				} else if (::strcmp(field, "step") == 0) {	// step stepu stepv
				} else if (::strcmp(field, "p") == 0) {
				} else if (::strcmp(field, "l") == 0) {
				} else if (::strcmp(field, "f") == 0) {
				} else if (::strcmp(field, "curv") == 0) {
				} else if (::strcmp(field, "curv2") == 0) {
				} else if (::strcmp(field, "surf") == 0) {
				} else if (::strcmp(field, "parm") == 0) {
				} else if (::strcmp(field, "trim") == 0) {
				} else if (::strcmp(field, "hole") == 0) {
				} else if (::strcmp(field, "scrv") == 0) {
				} else if (::strcmp(field, "sp") == 0) {
				} else if (::strcmp(field, "end") == 0) {
				} else if (::strcmp(field, "con") == 0) {
				} else if (::strcmp(field, "g") == 0) {
				} else if (::strcmp(field, "s") == 0) {
				} else if (::strcmp(field, "mg") == 0) {
				} else if (::strcmp(field, "o") == 0) {
				} else if (::strcmp(field, "bavel") == 0) {
				} else if (::strcmp(field, "c_interp") == 0) {
				} else if (::strcmp(field, "d_interp") == 0) {
				} else if (::strcmp(field, "lod") == 0) {
				} else if (::strcmp(field, "usemtl") == 0) {
				} else if (::strcmp(field, "mtllib") == 0) {
				} else if (::strcmp(field, "shadow_obj") == 0) {
				} else if (::strcmp(field, "trace_obj") == 0) {
				} else if (::strcmp(field, "ctech") == 0) {
				} else if (::strcmp(field, "stech") == 0) {
				}
			}
			break;
		}
		}
		if (tokenId == TOKEN_EOF) break;
	}
	return Value::Nil;
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
