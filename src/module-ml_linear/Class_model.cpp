#include "stdafx.h"
#include "Class_model.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_model implementation
//-----------------------------------------------------------------------------
Object_model::Object_model() : Object(Gura_UserClass(model))
{
}

String Object_model::ToString(bool exprFlag)
{
	return String("<ml.linear.model>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(model)
{
	// Assignment of properties
	// Assignment of value
	Gura_AssignValue(model, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
