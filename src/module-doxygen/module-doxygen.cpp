//=============================================================================
// Gura module: doxygen
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(doxygen)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// doxygen.test(num1:number, num2:number)
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

Gura_EndModuleBody(doxygen, doxygen)

Gura_RegisterModule(doxygen)
