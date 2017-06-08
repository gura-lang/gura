#include "stdafx.h"

Gura_BeginModuleScope(fftw)

//-----------------------------------------------------------------------------
// Object_plan implementation
//-----------------------------------------------------------------------------
Object_plan::~Object_plan()
{
	::fftw_destroy_plan(_plan);
}

Object *Object_plan::Clone() const
{
	return nullptr;
}

String Object_plan::ToString(bool exprFlag)
{
	return String("<fftw.plan>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for plan
//-----------------------------------------------------------------------------
// implementation of class plan
Gura_ImplementUserClass(plan)
{
	Gura_AssignValue(plan, Value(Reference()));
}

Gura_EndModuleScope(fftw)
