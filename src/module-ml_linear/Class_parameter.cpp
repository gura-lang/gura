#include "stdafx.h"
#include "Class_parameter.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
double GetRecommendedEPS(int solver_type)
{
	double eps = 0.1;
	// this code has been extracted from train.c.
	switch (solver_type) {
	case L2R_LR:
	case L2R_L2LOSS_SVC:
		eps = 0.01;
		break;
	case L2R_L2LOSS_SVR:
		eps = 0.001;
		break;
	case L2R_L2LOSS_SVC_DUAL:
	case L2R_L1LOSS_SVC_DUAL:
	case MCSVM_CS:
	case L2R_LR_DUAL:
		eps = 0.1;
		break;
	case L1R_L2LOSS_SVC:
	case L1R_LR:
		eps = 0.01;
		break;
	case L2R_L1LOSS_SVR_DUAL:
	case L2R_L2LOSS_SVR_DUAL:
		eps = 0.1;
		break;
	default:
		break;
	}
	return eps;
}
	
//-----------------------------------------------------------------------------
// Object_parameter implementation
//-----------------------------------------------------------------------------
Object_parameter::Object_parameter() : Object(Gura_UserClass(parameter))
{
	::memset(&_param, 0x00, sizeof(_param));
	_param.solver_type = L2R_L2LOSS_SVC_DUAL;
	_param.eps = HUGE_VAL;
	_param.C = 1;
	_param.nr_weight = 0;
	_param.weight_label = nullptr;
	_param.weight = nullptr;
	_param.p = .1;
	_param.init_sol = nullptr;
}

String Object_parameter::ToString(bool exprFlag)
{
	return String("<ml.linear.parameter>");
}

bool Object_parameter::HasValidEntity() const
{
	return false;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// ml.linear.parameter() {block?}
Gura_DeclareFunction(parameter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(parameter));
	AddHelp(
		Gura_Symbol(en),
		"Creates an instance of ml.linear.parameter.\n");
}

Gura_ImplementFunction(parameter)
{
	return ReturnValue(env, arg, Value(new Object_parameter()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(parameter)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(parameter);
	// Assignment of value
	Gura_AssignValue(parameter, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
