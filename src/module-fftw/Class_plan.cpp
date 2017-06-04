#include "stdafx.h"

Gura_BeginModuleScope(fftw)

//-----------------------------------------------------------------------------
// Object_plan implementation
//-----------------------------------------------------------------------------
Object_plan::~Object_plan()
{
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
}

Gura_EndModuleScope(fftw)
