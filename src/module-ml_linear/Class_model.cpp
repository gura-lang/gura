#include "stdafx.h"
#include "Class_model.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_model implementation
//-----------------------------------------------------------------------------
Object_model::Object_model(struct model *pModel) :
		Object(Gura_UserClass(model)), _pModel(pModel), _sizeProbabilityBuff(0)
{
}

Object_model::~Object_model()
{
	::free_and_destroy_model(&_pModel);
}

String Object_model::ToString(bool exprFlag)
{
	return String("<ml.linear.model>");
}

double *Object_model::GetProbabilityBuff(int *pSizeProbabilityBuff)
{
	int nClasses = ::get_nr_class(_pModel);
	if (_sizeProbabilityBuff < nClasses) {
		_sizeProbabilityBuff = nClasses;
		_prob_estimates.reset(new double [_sizeProbabilityBuff]);
	}
	*pSizeProbabilityBuff = _sizeProbabilityBuff;
	return _prob_estimates.get();
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// ml.linear.model.predict(feature:feature):map
Gura_DeclareMethod(model, predict)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "feature", VTYPE_feature);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, predict)
{
	struct model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	Feature *pFeature = Object_feature::GetObject(arg, 0)->GetEntity();
	double label = ::predict(pModel, pFeature->GetNodes());
	return Value(label);
}

// ml.linear.model.predict_probability(feature:feature):map
Gura_DeclareMethod(model, predict_probability)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "feature", VTYPE_feature);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, predict_probability)
{
	Object_model *pObjModel = Object_model::GetObjectThis(arg);
	struct model *pModel = pObjModel->GetEntity();
	Feature *pFeature = Object_feature::GetObject(arg, 0)->GetEntity();
	int sizeProbabilityBuff = 0;
	double *prob_estimates = pObjModel->GetProbabilityBuff(&sizeProbabilityBuff);
	double label = ::predict_probability(pModel, pFeature->GetNodes(), prob_estimates);
	return Value::CreateList(env, Value(label),
							 Value::CreateList(env, prob_estimates, sizeProbabilityBuff));
}

// ml.linear.model.get_nr_feature()
Gura_DeclareMethod(model, get_nr_feature)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, get_nr_feature)
{
	struct model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	return Value(::get_nr_feature(pModel));
}

// ml.linear.model.get_nr_class()
Gura_DeclareMethod(model, get_nr_class)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, get_nr_class)
{
	struct model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	return Value(::get_nr_class(pModel));
}

// ml.linear.model.get_labels()
Gura_DeclareMethod(model, get_labels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, get_labels)
{
	struct model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	int nClasses = ::get_nr_class(pModel);
	std::unique_ptr<int []> labels(new int [nClasses]);
	::get_labels(pModel, labels.get());
	return Value::CreateList(env, labels.get(), nClasses);
}

// ml.linear.model.get_decfun_coef(feat_idx:number, label_idx:number)
Gura_DeclareMethod(model, get_decfun_coef)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "feat_idx", VTYPE_number);
	DeclareArg(env, "label_idx", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, get_decfun_coef)
{
	struct model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	int feat_idx = arg.GetInt(0);
	int label_idx = arg.GetInt(1);
	return Value(::get_decfun_coef(pModel, feat_idx, label_idx));
}

// ml.linear.model.get_decfun_bias(label_idx:number)
Gura_DeclareMethod(model, get_decfun_bias)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "label_idx", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, get_decfun_bias)
{
	struct model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	int label_idx = arg.GetInt(0);
	return Value(::get_decfun_bias(pModel, label_idx));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(model)
{
	// Assignment of methods
	Gura_AssignMethod(model, predict);
	Gura_AssignMethod(model, predict_probability);
	Gura_AssignMethod(model, get_nr_feature);
	Gura_AssignMethod(model, get_nr_class);
	Gura_AssignMethod(model, get_labels);
	Gura_AssignMethod(model, get_decfun_coef);
	Gura_AssignMethod(model, get_decfun_bias);
	// Assignment of value
	Gura_AssignValue(model, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
