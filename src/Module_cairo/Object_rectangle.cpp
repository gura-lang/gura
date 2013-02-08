#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_rectangle implementation
//-----------------------------------------------------------------------------
Object_rectangle::~Object_rectangle()
{
}

Object *Object_rectangle::Clone() const
{
	return NULL;
}

String Object_rectangle::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.rectangle>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for rectangle
//-----------------------------------------------------------------------------
// implementation of class rectangle
Gura_ImplementUserClass(rectangle)
{
}

}}
