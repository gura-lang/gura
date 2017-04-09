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
Gura_ImplementUserClassWithCast(feature)
{
	// Assignment of properties
	// Assignment of value
	Gura_AssignValue(feature, Value(Reference()));
}

Gura_ImplementCastFrom(feature)
{
	if (value.Is_list()) {
		AutoPtr<Feature> pFeature(Feature::Create(env, value.GetList()));
		if (pFeature.IsNull()) return false;
		return true;
	}
	return false;
}

Gura_ImplementCastTo(feature)
{
	return false;
}

Gura_EndModuleScope(ml_linear)
