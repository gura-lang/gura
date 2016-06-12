//=============================================================================
// Gura module: doxygen
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(doxygen)

bool ParseStream(Environment &env, SimpleStream &stream)
{
	Signal &sig = env.GetSignal();
	CommandFormat::Initialize();
	Parser parser;
	for (;;) {
		int chRaw;
		if ((chRaw = stream.GetChar(sig)) < 0) chRaw = 0;
		char ch = static_cast<char>(static_cast<UChar>(chRaw));
		parser.FeedChar(env, ch);
		if (ch == '\0') break;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// doxygen.test(stream:stream):void:map
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(test)
{
	ParseStream(env, arg.GetStream(0));
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

Gura_EndModuleBody(doxygen, doxygen)

Gura_RegisterModule(doxygen)
