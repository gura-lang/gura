#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_Problem implementation
//-----------------------------------------------------------------------------
Object_Problem::Object_Problem() : Object(Gura_UserClass(Problem))
{
}

String Object_Problem::ToString(bool exprFlag)
{
	return String("<ceres.Problem>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for ceres.Problem
//-----------------------------------------------------------------------------
// implementation of class ceres.Problem
Gura_ImplementUserClass(Problem)
{
	// Assignment of properties
	// Assignment of value
	Gura_AssignValue(Problem, Value(Reference()));
}

Gura_EndModuleScope(ceres)
