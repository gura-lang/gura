//=============================================================================
// Gura module: ml.linear
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(ml_linear)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// ml.linear.train(prob:ml.linear.problem, param:ml.linear.parameter)
Gura_DeclareFunction(train)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "prob", VTYPE_problem);
	DeclareArg(env, "param", VTYPE_parameter);
	AddHelp(
		Gura_Symbol(en),
		"This function adds two numbers and returns the result.\n");
}

Gura_ImplementFunction(train)
{
	Object_problem::GetObject(arg, 0);
	Object_parameter::GetObject(arg, 1);

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
	// class realization
	Gura_RealizeAndPrepareUserClass(feature_node, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(problem, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(parameter, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(model, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(train);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ml_linear, linear)

Gura_RegisterModule(ml_linear)
