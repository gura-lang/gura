#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Point implementation
//-----------------------------------------------------------------------------
Object_Point::~Object_Point()
{
}

Object *Object_Point::Clone() const
{
	return NULL;
}

String Object_Point::ToString(bool exprFlag)
{
	return String("<sdl2.Point>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Point
//-----------------------------------------------------------------------------
// implementation of class Point
Gura_ImplementUserClass(Point)
{
}

Gura_EndModuleScope(sdl2)
