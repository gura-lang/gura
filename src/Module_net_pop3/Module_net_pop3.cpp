//-----------------------------------------------------------------------------
// Gura net.pop3 module
//-----------------------------------------------------------------------------
#include "Module_net_pop3.h"

Gura_BeginModule(net_pop3)

//-----------------------------------------------------------------------------
// Gura module functions: net.pop3
//-----------------------------------------------------------------------------
// net.pop3.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
	AddHelp(Gura_Symbol(en), "adds two numbers and returns the result.");
}

Gura_ImplementFunction(test)
{
	return Value(args.GetNumber(0) + args.GetNumber(1));
}

// Module entry
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(net_pop3, pop3)

Gura_RegisterModule(net_pop3)
