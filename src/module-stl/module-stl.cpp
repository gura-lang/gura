//=============================================================================
// Gura module: stl
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(stl)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// stl.test(stream:stream)
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
		STAT_FileTop, STAT_LineTop, STAT_Token, STAT_SkipWhite,
	} stat = STAT_FileTop;
	String token;
	Signal &sig = env.GetSignal();
	Stream &stream = arg.GetStream(0);
	for (;;) {
		int chRaw = stream.GetChar(sig);
		if (sig.IsSignalled()) break;
		char ch = (chRaw < 0)? '\0' : static_cast<char>(static_cast<UChar>(chRaw));
		Gura_BeginPushbackRegion();
		switch (stat) {
		case STAT_FileTop: {
			if (ch == 's') {
				Gura_Pushback();
				stat = STAT_Token;
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
			}
		}
		case STAT_Token: {
			if (ch == ' ' || ch == '\t') {
				::printf("%s\n", token.c_str());
				token.clear();
				stat = STAT_SkipWhite;
			} else if (ch == '\n' || ch == '\0') {
				::printf("%s\n", token.c_str());
				token.clear();
				stat = STAT_LineTop;
			} else {
				token += ch;
			}
			break;
		}
		case STAT_SkipWhite: {
			if (ch == ' ' || ch == '\t') {
				// nothing to do
			} else if (ch == '\n' || ch == '\0') {
				stat = STAT_LineTop;
			} else {
				Gura_Pushback();
				stat = STAT_Token;
			}
			break;
		}
		}
		Gura_EndPushbackRegion();
		if (ch == '\0') break;
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

Gura_EndModuleBody(stl, stl)

Gura_RegisterModule(stl)
