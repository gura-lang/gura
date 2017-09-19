//=============================================================================
// Gura module: ml.cifar
// https://www.cs.toronto.edu/~kriz/cifar.html
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(ml_cifar)

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ml.cifar.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"This function adds two numbers and returns the result.\n");
}

Gura_ImplementFunction(test)
{
	return Value(arg.GetNumber(0) + arg.GetNumber(1));
}

//-----------------------------------------------------------------------------
// Module Entry
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// Assignment of function
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ml_cifar, cifar)

Gura_RegisterModule(ml_cifar)
