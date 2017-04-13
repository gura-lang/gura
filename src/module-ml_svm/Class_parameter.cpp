#include "stdafx.h"
#include "Class_parameter.h"

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Object_parameter implementation
//-----------------------------------------------------------------------------
Object_parameter::Object_parameter() : Object(Gura_UserClass(parameter))
{
	::memset(&_param, 0x00, sizeof(_param));
	// these default values come from parse_command_line() in svm_train.c.
	_param.svm_type			= C_SVC;
	_param.kernel_type		= RBF;
	_param.degree			= 3;
	_param.gamma = _gamma	= HUGE_VAL;	// 1 / num_features
	_param.coef0			= 0;
	_param.nu				= 0.5;
	_param.cache_size		= 100;
	_param.C				= 1;
	_param.eps				= 1e-3;
	_param.p				= 0.1;
	_param.shrinking		= 1;
	_param.probability		= 0;
	_param.nr_weight		= 0;
	_param.weight_label		= nullptr;
	_param.weight			= nullptr;
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

struct svm_parameter &Object_parameter::UpdateEntity(int num_features)
{
	_param.gamma = (_gamma != HUGE_VAL)? _gamma : (num_features > 0)? 1. / num_features : 0;
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
// ml.svm.parameter#svm_type
Gura_DeclareProperty_RW(parameter, svm_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Type of SVM:\n"
		"- 0 .. C-SVC (multi-class classification)\n"
		"- 1 .. nu-SVC (multi-class classification)\n"
		"- 2 .. one-class SVM\n"
		"- 3 .. epsilon-SVR (regression)\n"
		"- 4 .. nu-SVR (regression)\n");
}

Gura_ImplementPropertyGetter(parameter, svm_type)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.svm_type);
}

Gura_ImplementPropertySetter(parameter, svm_type)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.svm_type = value.GetInt();
	return Value(param.svm_type);
}

// ml.svm.parameter#kernel_type
Gura_DeclareProperty_RW(parameter, kernel_type)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Type of kernel function:\n"
		"- 0 .. linear: u'*v\n"
		"- 1 .. polynomial: (gamma*u'*v + coef0)^degree\n"
		"- 2 .. radial basis function: exp(-gamma*|u-v|^2)\n"
		"- 3 .. sigmoid: tanh(gamma*u'*v + coef0)\n"
		"- 4 .. precomputed kernel (kernel values in training_set_file)\n");
}

Gura_ImplementPropertyGetter(parameter, kernel_type)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.kernel_type);
}

Gura_ImplementPropertySetter(parameter, kernel_type)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.kernel_type = value.GetInt();
	return Value(param.kernel_type);
}

// ml.svm.parameter#degree
Gura_DeclareProperty_RW(parameter, degree)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Degree in kernel function.");
}

Gura_ImplementPropertyGetter(parameter, degree)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.degree);
}

Gura_ImplementPropertySetter(parameter, degree)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.degree = value.GetInt();
	return Value(param.degree);
}

// ml.svm.parameter#gamma
Gura_DeclareProperty_RW(parameter, gamma)
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"Gamma in kernel function.");
}

Gura_ImplementPropertyGetter(parameter, gamma)
{
	Object_parameter *pObjParam = Object_parameter::GetObject(valueThis);
	double gamma = pObjParam->GetGamma();
	return (gamma == HUGE_VAL)? Value::Nil : Value(gamma);
}

Gura_ImplementPropertySetter(parameter, gamma)
{
	Object_parameter *pObjParam = Object_parameter::GetObject(valueThis);
	double gamma = value.IsValid()? value.GetDouble() : HUGE_VAL;
	pObjParam->SetGamma(gamma);
	return (gamma == HUGE_VAL)? Value::Nil : Value(gamma);
}

// ml.svm.parameter#coef0
Gura_DeclareProperty_RW(parameter, coef0)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"coef0 in kernel function.");
}

Gura_ImplementPropertyGetter(parameter, coef0)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.coef0);
}

Gura_ImplementPropertySetter(parameter, coef0)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.coef0 = value.GetDouble();
	return Value(param.coef0);
}

// ml.svm.parameter#nu
Gura_DeclareProperty_RW(parameter, nu)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Parameter nu of nu-SVC, one-class SVM, and nu-SVR.");
}

Gura_ImplementPropertyGetter(parameter, nu)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.nu);
}

Gura_ImplementPropertySetter(parameter, nu)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.nu = value.GetDouble();
	return Value(param.nu);
}

// ml.svm.parameter#cache_size
Gura_DeclareProperty_RW(parameter, cache_size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Cache memory size in MB.");
}

Gura_ImplementPropertyGetter(parameter, cache_size)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.cache_size);
}

Gura_ImplementPropertySetter(parameter, cache_size)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.cache_size = value.GetDouble();
	return Value(param.cache_size);
}

// ml.svm.parameter#C
Gura_DeclareProperty_RW(parameter, C)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Parameter C of C-SVC, epsilon-SVR, and nu-SVR.");
}

Gura_ImplementPropertyGetter(parameter, C)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.C);
}

Gura_ImplementPropertySetter(parameter, C)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.C = value.GetDouble();
	return Value(param.C);
}

// ml.svm.parameter#eps
Gura_DeclareProperty_RW(parameter, eps)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Tolerance of termination criterion.");
}

Gura_ImplementPropertyGetter(parameter, eps)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.eps);
}

Gura_ImplementPropertySetter(parameter, eps)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.eps = value.GetDouble();
	return Value(param.eps);
}

// ml.svm.parameter#p
Gura_DeclareProperty_RW(parameter, p)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Epsilon in loss function of epsilon-SVR.");
}

Gura_ImplementPropertyGetter(parameter, p)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.p);
}

Gura_ImplementPropertySetter(parameter, p)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.p = value.GetDouble();
	return Value(param.p);
}

// ml.svm.parameter#shrinking
Gura_DeclareProperty_RW(parameter, shrinking)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Whether to use the shrinking heuristics, 0 or 1.");
}

Gura_ImplementPropertyGetter(parameter, shrinking)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.shrinking);
}

Gura_ImplementPropertySetter(parameter, shrinking)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.shrinking = value.GetInt();
	return Value(param.shrinking);
}

// ml.svm.parameter#probability
Gura_DeclareProperty_RW(parameter, probability)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Whether to train a SVC or SVR model for probability estimates.");
}

Gura_ImplementPropertyGetter(parameter, probability)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	return Value(param.probability);
}

Gura_ImplementPropertySetter(parameter, probability)
{
	struct svm_parameter &param = Object_parameter::GetObject(valueThis)->GetEntity();
	param.probability = value.GetInt();
	return Value(param.probability);
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
	Gura_AssignProperty(parameter, svm_type);
	Gura_AssignProperty(parameter, kernel_type);
	Gura_AssignProperty(parameter, degree);
	Gura_AssignProperty(parameter, gamma);
	Gura_AssignProperty(parameter, coef0);
	Gura_AssignProperty(parameter, nu);
	Gura_AssignProperty(parameter, cache_size);
	Gura_AssignProperty(parameter, C);
	Gura_AssignProperty(parameter, eps);
	Gura_AssignProperty(parameter, p);
	Gura_AssignProperty(parameter, shrinking);
	Gura_AssignProperty(parameter, probability);
	// Assignment of method
	Gura_AssignMethod(parameter, add_weight);
	// Assignment of function
	Gura_AssignFunction(parameter);
}

Gura_EndModuleScope(ml_svm)
