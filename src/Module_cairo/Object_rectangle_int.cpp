#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_rectangle_int implementation
//-----------------------------------------------------------------------------
Object_rectangle_int::~Object_rectangle_int()
{
}

Object *Object_rectangle_int::Clone() const
{
	return NULL;
}

String Object_rectangle_int::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.rectangle_int>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for rectangle_int
//-----------------------------------------------------------------------------
// implementation of class rectangle_int
Gura_ImplementUserClass(rectangle_int)
{
}

}}
