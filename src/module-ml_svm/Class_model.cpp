#include "stdafx.h"
#include "Class_model.h"

Gura_BeginModuleScope(ml_svm)

//-----------------------------------------------------------------------------
// Object_model implementation
//-----------------------------------------------------------------------------
Object_model::Object_model(struct svm_model *pModel) :
					Object(Gura_UserClass(model)), _pModel(pModel)
{
}

Object_model::~Object_model()
{
	::svm_free_and_destroy_model(&_pModel);
}

String Object_model::ToString(bool exprFlag)
{
	return String("<ml.svm.model>");
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// ml.svm.model.predict(feature:feature)
Gura_DeclareMethod(model, predict)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "feature", VTYPE_feature);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, predict)
{
	struct svm_model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	Feature *pFeature = Object_feature::GetObject(arg, 0)->GetEntity();
	double label = ::svm_predict(pModel, pFeature->GetNodes());
	return Value(label);
}

// ml.svm.model.get_svm_type()
Gura_DeclareMethod(model, get_svm_type)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, get_svm_type)
{
	struct svm_model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	return Value(::svm_get_svm_type(pModel));
}

// ml.svm.model.get_nr_class()
Gura_DeclareMethod(model, get_nr_class)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, get_nr_class)
{
	struct svm_model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	return Value(::svm_get_nr_class(pModel));
}

// ml.svm.model.get_labels()
Gura_DeclareMethod(model, get_labels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, get_labels)
{
	struct svm_model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	int nClasses = ::svm_get_nr_class(pModel);
	std::unique_ptr<int[]> labels(new int[nClasses]);
	::svm_get_labels(pModel, labels.get());
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	for (int i = 0; i < nClasses; i++) {
		pObjList->Add(Value(labels[i]));
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(model)
{
	// Assignment of methods
	Gura_AssignMethod(model, predict);
	Gura_AssignMethod(model, get_svm_type);
	Gura_AssignMethod(model, get_nr_class);
	Gura_AssignMethod(model, get_labels);
	// Assignment of value
	Gura_AssignValue(model, Value(Reference()));
}

Gura_EndModuleScope(ml_svm)
