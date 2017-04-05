//=============================================================================
// Gura module: ml.linear
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(ml_linear)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// ml.linear.train()
Gura_DeclareFunction(train)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "num1", VTYPE_number);
	//DeclareArg(env, "num2", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"This function adds two numbers and returns the result.\n");
}

Gura_ImplementFunction(train)
{
	//::train(nullptr, nullptr);
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
	Gura_AssignFunction(train);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ml_linear, linear)

Gura_RegisterModule(ml_linear)
