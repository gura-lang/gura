#include "stdafx.h"
#include "Class_feature_node.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_feature_node implementation
//-----------------------------------------------------------------------------
Object_feature_node::Object_feature_node() : Object(Gura_UserClass(feature_node))
{
}

String Object_feature_node::ToString(bool exprFlag)
{
	return String("<ml.linear.feature_node>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(feature_node)
{
	// Assignment of properties
	// Assignment of value
	Gura_AssignValue(feature_node, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
