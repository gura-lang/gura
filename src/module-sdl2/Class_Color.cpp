#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Color implementation
//-----------------------------------------------------------------------------
Object_Color::~Object_Color()
{
}

Object *Object_Color::Clone() const
{
	return NULL;
}

String Object_Color::ToString(bool exprFlag)
{
	return String("<sdl2.Color>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Color
//-----------------------------------------------------------------------------
// implementation of class Color
Gura_ImplementUserClass(Color)
{
}

Gura_EndModuleScope(sdl2)
