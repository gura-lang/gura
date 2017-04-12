#include "stdafx.h"
#include "Class_sample.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_sample implementation
//-----------------------------------------------------------------------------
Object_sample::Object_sample(Sample *pSample) :
					Object(Gura_UserClass(sample)), _pSample(pSample)
{
}

String Object_sample::ToString(bool exprFlag)
{
	return String("<ml.linear.sample>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(sample)
{
	// Assignment of properties
	// Assignment of function
	//Gura_AssignFunction(sample);
}

Gura_EndModuleScope(ml_linear)
