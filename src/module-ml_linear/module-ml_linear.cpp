//=============================================================================
// Gura module: ml.linear
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(ml_linear)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// ml.linear.train(prob:ml.linear.problem, param:ml.linear.parameter) {block?}
Gura_DeclareFunction(train)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "prob", VTYPE_problem);
	DeclareArg(env, "param", VTYPE_parameter);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"This function adds two numbers and returns the result.\n");
}

Gura_ImplementFunction(train)
{
	struct problem &prob = Object_problem::GetObject(arg, 0)->UpdateEntity();
	struct parameter &param = Object_parameter::GetObject(arg, 1)->UpdateEntity();
	const char *errorMsg = ::check_parameter(&prob, &param);
	if (errorMsg != nullptr) {
		env.SetError(ERR_RuntimeError, "%s", errorMsg);
		return Value::Nil;
	}
	struct model *pModel = ::train(&prob, &param);
	return ReturnValue(env, arg, Value(new Object_model(pModel)));
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
	Gura_RealizeAndPrepareUserClass(feature, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(problem, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(parameter, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(model, env.LookupClass(VTYPE_object));
	// Assignment of function
	Gura_AssignFunction(train);
	// Assignment of values
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ml_linear, linear)

Gura_RegisterModule(ml_linear)
