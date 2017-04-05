#include "stdafx.h"
#include "Class_problem.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_problem implementation
//-----------------------------------------------------------------------------
Object_problem::Object_problem() : Object(Gura_UserClass(problem))
{
}

String Object_problem::ToString(bool exprFlag)
{
	return String("<ml.linear.problem>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(problem)
{
	// Assignment of properties
	// Assignment of value
}

Gura_EndModuleScope(ml_linear)
