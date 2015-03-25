//=============================================================================
// Gura module: diff
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(diff)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// diff.diff(stream1:stream, stream2:stream)
Gura_DeclareFunction(diff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream1", VTYPE_stream);
	DeclareArg(env, "stream2", VTYPE_stream);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"This function adds two numbers and returns the result.");
}

Gura_ImplementFunction(diff)
{
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(diff);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(diff, diff)

Gura_RegisterModule(diff)
