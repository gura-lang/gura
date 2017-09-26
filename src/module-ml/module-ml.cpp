//=============================================================================
// Gura module: ml
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(ml)

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ml.he(n:number)
Gura_DeclareFunction(he)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a sigma value to initialize neural network based on He.\n");
}

Gura_ImplementFunction(he)
{
	Double num = arg.GetDouble(0);
	if (num == 0) {
		env.SetError(ERR_ValueError, "zero can not be specified");
		return Value::Nil;
	}
	return Value(::sqrt(2 / num));
}

// ml.xavier(n:number)
Gura_DeclareFunction(xavier)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "n", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a sigma value to initialize neural network based on Xavier.\n");
}

Gura_ImplementFunction(xavier)
{
	Double num = arg.GetDouble(0);
	if (num == 0) {
		env.SetError(ERR_ValueError, "zero can not be specified");
		return Value::Nil;
	}
	return Value(::sqrt(1 / num));
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
	Gura_AssignFunction(he);
	Gura_AssignFunction(xavier);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ml, ml)

Gura_RegisterModule(ml)
