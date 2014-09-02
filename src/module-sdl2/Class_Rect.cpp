#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Rect implementation
//-----------------------------------------------------------------------------
Object_Rect::~Object_Rect()
{
}

Object *Object_Rect::Clone() const
{
	return NULL;
}

String Object_Rect::ToString(bool exprFlag)
{
	return String("<sdl2.Rect>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Rect
//-----------------------------------------------------------------------------
// implementation of class Rect
Gura_ImplementUserClass(Rect)
{
}

Gura_EndModuleScope(sdl2)
