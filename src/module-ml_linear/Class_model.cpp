#include "stdafx.h"
#include "Class_model.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_model implementation
//-----------------------------------------------------------------------------
Object_model::Object_model(struct model *pModel) :
					Object(Gura_UserClass(model)), _pModel(pModel)
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

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.linear.model.predict(feature:feature)
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
	struct model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	Feature *pFeature = Object_feature::GetObject(arg, 0)->GetEntity();
	double label = ::predict(pModel, pFeature->GetNodes());
	return Value(label);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(model)
{
	// Assignment of methods
	Gura_AssignMethod(model, predict);
	// Assignment of value
	Gura_AssignValue(model, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
