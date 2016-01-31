//=============================================================================
// Gura module: model.stl
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(model_stl)

//-----------------------------------------------------------------------------
// Tokenizer
//-----------------------------------------------------------------------------
class Tokenizer {
public:
	enum Stat {
		STAT_FileTop, STAT_LineTop, STAT_Token, STAT_SkipWhite,
	};
private:
	Stat _stat;
	String _token;
public:
	inline Tokenizer() : _stat(STAT_FileTop) {}
	const String &Tokenize(Environment &env, Stream &stream);
};

const String &Tokenizer::Tokenize(Environment &env, Stream &stream)
{
	Signal &sig = env.GetSignal();
	_token.clear();
	for (;;) {
		int chRaw = stream.GetChar(sig);
		if (sig.IsSignalled()) break;
		char ch = (chRaw < 0)? '\0' : static_cast<char>(static_cast<UChar>(chRaw));
		Gura_BeginPushbackRegion();
		switch (_stat) {
		case STAT_FileTop: {
			if (ch == 's') {
				Gura_Pushback();
				_stat = STAT_Token;
			}
			break;
		}
		case STAT_LineTop: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '\n' || ch == '\0') {
				// nothing to do
			} else {
				Gura_Pushback();
				_stat = STAT_Token;
			}
			break;
		}
		case STAT_Token: {
			if (ch == ' ' || ch == '\t') {
				_stat = STAT_SkipWhite;
				return _token;
			} else if (ch == '\n' || ch == '\0') {
				_stat = STAT_LineTop;
				return _token;
			} else {
				_token += ch;
			}
			break;
		}
		case STAT_SkipWhite: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '\n' || ch == '\0') {
				_stat = STAT_LineTop;
			} else {
				Gura_Pushback();
				_stat = STAT_Token;
			}
			break;
		}
		}
		Gura_EndPushbackRegion();
		if (ch == '\0') break;
	}
	return _token;
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// model.stl.test(stream:stream)
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
	Tokenizer tokenizer;
	Stream &stream = arg.GetStream(0);
	for (;;) {
		const String &token = tokenizer.Tokenize(env, stream);
		if (token.empty()) break;
		::printf("%s\n", token.c_str());
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

Gura_EndModuleBody(model_stl, stl)

Gura_RegisterModule(model_stl)
