//-----------------------------------------------------------------------------
// Gura guri module
//-----------------------------------------------------------------------------
#include "Module_guri.h"

Gura_BeginModule(guri)

//-----------------------------------------------------------------------------
// Gura module functions: guri
//-----------------------------------------------------------------------------
// guri.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
	SetHelp("adds two numbers and returns the result.");
}

Gura_ImplementFunction(test)
{
	return Value(args.GetNumber(0) + args.GetNumber(1));
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(guri, guri)

Gura_RegisterModule(guri)
