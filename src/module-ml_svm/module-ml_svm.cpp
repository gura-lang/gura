//=============================================================================
// Gura module: ml.svm
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(ml_svm)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// ml.svm.train(prob:ml.svm.problem, param:ml.svm.parameter) {block?}
Gura_DeclareFunction(train)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "prob", VTYPE_problem);
	DeclareArg(env, "param", VTYPE_parameter);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(train)
{
	struct svm_problem &prob = Object_problem::GetObject(arg, 0)->UpdateEntity();
	struct svm_parameter &param = Object_parameter::GetObject(arg, 1)->UpdateEntity();
	const char *errorMsg = ::svm_check_parameter(&prob, &param);
	if (errorMsg != nullptr) {
		env.SetError(ERR_RuntimeError, "%s", errorMsg);
		return Value::Nil;
	}
	struct svm_model *pModel = ::svm_train(&prob, &param);
	return ReturnValue(env, arg, Value(new Object_model(pModel)));
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

void print_func(const char *)
{
}

Gura_ModuleEntry()
{
	// suppress messages
	::svm_set_print_string_function(&print_func);
	// class realization
	Gura_RealizeAndPrepareUserClass(feature, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(sample, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(problem, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(parameter, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(model, env.LookupClass(VTYPE_object));
	// Assignment of function
	Gura_AssignFunction(train);
	// Assignment of values
	// svm_type
	Gura_AssignValueEx("C_SVC",			C_SVC);
	Gura_AssignValueEx("NU_SVC",		NU_SVC);
	Gura_AssignValueEx("ONE_CLASS",		ONE_CLASS);
	Gura_AssignValueEx("EPSILON_SVR",	EPSILON_SVR);
	Gura_AssignValueEx("NU_SVR",		NU_SVR);
	// kernel_type
	Gura_AssignValueEx("LINEAR",		LINEAR);
	Gura_AssignValueEx("POLY",			POLY);
	Gura_AssignValueEx("RBF",			RBF);
	Gura_AssignValueEx("SIGMOID",		SIGMOID);
	Gura_AssignValueEx("PRECOMPUTED",	PRECOMPUTED);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(ml_svm, svm)

Gura_RegisterModule(ml_svm)
