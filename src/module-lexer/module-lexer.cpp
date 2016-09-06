//-----------------------------------------------------------------------------
// Gura module: lexer
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(lexer)

//-----------------------------------------------------------------------------
// Gura module functions
//-----------------------------------------------------------------------------
// lexer.tokens(stream:stream):map
Gura_DeclareFunction(tokens)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementFunction(tokens)
{
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
	Gura_AssignFunction(tokens);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------

Gura_EndModuleBody(lexer, lexer)

Gura_RegisterModule(lexer)
