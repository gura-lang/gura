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
// ml.linear.model.predict(x[]:number)
Gura_DeclareMethod(model, predict)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(model, predict)
{
	struct model *pModel = Object_model::GetObjectThis(arg)->GetEntity();
	const ValueList &valListX = arg.GetList(0);
	Sample *pSample = Sample::Create(valListX, nullptr);
	double label = ::predict(pModel, pSample->nodes);
	return Value::Nil;
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
