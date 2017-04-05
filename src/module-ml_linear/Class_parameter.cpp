#include "stdafx.h"
#include "Class_parameter.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_parameter implementation
//-----------------------------------------------------------------------------
Object_parameter::Object_parameter() : Object(Gura_UserClass(parameter))
{
}

String Object_parameter::ToString(bool exprFlag)
{
	return String("<ml.linear.parameter>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(parameter)
{
	// Assignment of properties
	// Assignment of value
}

Gura_EndModuleScope(ml_linear)
