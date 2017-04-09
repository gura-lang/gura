#include "stdafx.h"
#include "Class_parameter.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
double GetRecommendedEPS(int solver_type)
{
	double eps = 0.1;
	// these recommended values come from parse_command_line() in train.c.
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
	// these default values come from parse_command_line() in train.c.
	_param.solver_type	= L2R_L2LOSS_SVC_DUAL;
	_param.eps = _eps	= HUGE_VAL;
	_param.C			= 1;
	_param.p			= 0.1;
	_param.nr_weight	= 0;
	_param.weight_label	= nullptr;
	_param.weight		= nullptr;
	_param.init_sol		= nullptr;
}

Object_parameter::~Object_parameter()
{
	delete[] _param.weight_label;
	delete[] _param.weight;
}

String Object_parameter::ToString(bool exprFlag)
{
	return String("<ml.linear.parameter>");
}

void Object_parameter::AddWeight(int label, double weight)
{
	_weightOwner.push_back(Weight(label, weight));
}

struct parameter &Object_parameter::UpdateEntity()
{
	_param.eps = (_eps == HUGE_VAL)? GetRecommendedEPS(_param.solver_type) : _eps;
	delete[] _param.weight_label;
	delete[] _param.weight;
	_param.nr_weight = static_cast<int>(_weightOwner.size());
	_param.weight_label = new int[_param.nr_weight];
	_param.weight = new double[_param.nr_weight];
	size_t i = 0;
	foreach_const (WeightOwner, pWeight, _weightOwner) {
		_param.weight_label[i] = pWeight->label;
		_param.weight[i] = pWeight->weight;
		i++;
	}
	return _param;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.linear.parameter#solver_type
Gura_DeclareProperty_RW(parameter, solver_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(parameter, solver_type)
{
	struct parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.solver_type);
}

Gura_ImplementPropertySetter(parameter, solver_type)
{
	struct parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.solver_type = value.GetInt();
	return Value(param.solver_type);
}

// ml.linear.parameter#eps
Gura_DeclareProperty_RW(parameter, eps)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(parameter, eps)
{
	struct parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.eps);
}

Gura_ImplementPropertySetter(parameter, eps)
{
	struct parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.eps = value.GetDouble();
	return Value(param.eps);
}

// ml.linear.parameter#C
Gura_DeclareProperty_RW(parameter, C)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(parameter, C)
{
	struct parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.C);
}

Gura_ImplementPropertySetter(parameter, C)
{
	struct parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.C = value.GetDouble();
	return Value(param.C);
}

// ml.linear.parameter#p
Gura_DeclareProperty_RW(parameter, p)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementPropertyGetter(parameter, p)
{
	struct parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.p);
}

Gura_ImplementPropertySetter(parameter, p)
{
	struct parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.p = value.GetDouble();
	return Value(param.p);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// ml.linear.parameter.add_weight(label:number, weight:number):reduce
Gura_DeclareMethod(parameter, add_weight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "label", VTYPE_number);
	DeclareArg(env, "weight", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(parameter, add_weight)
{
	Object_parameter *pObjParam = Object_parameter::GetObjectThis(arg);
	pObjParam->AddWeight(arg.GetInt(0), arg.GetDouble(1));
	return arg.GetValueThis();
}

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
	Gura_AssignProperty(parameter, solver_type);
	Gura_AssignProperty(parameter, eps);
	Gura_AssignProperty(parameter, C);
	Gura_AssignProperty(parameter, p);
	// Assignment of method
	Gura_AssignMethod(parameter, add_weight);
	// Assignment of function
	Gura_AssignFunction(parameter);
}

Gura_EndModuleScope(ml_linear)
