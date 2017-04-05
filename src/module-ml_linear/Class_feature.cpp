#include "stdafx.h"
#include "Class_feature.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_feature implementation
//-----------------------------------------------------------------------------
Object_feature::Object_feature() : Object(Gura_UserClass(feature))
{
}

String Object_feature::ToString(bool exprFlag)
{
	return String("<ml.linear.feature>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(feature)
{
	// Assignment of properties
	// Assignment of value
	Gura_AssignValue(feature, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
