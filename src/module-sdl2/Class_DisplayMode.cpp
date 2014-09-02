#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_DisplayMode implementation
//-----------------------------------------------------------------------------
Object_DisplayMode::~Object_DisplayMode()
{
}

Object *Object_DisplayMode::Clone() const
{
	return NULL;
}

String Object_DisplayMode::ToString(bool exprFlag)
{
	return String("<sdl2.DisplayMode>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for DisplayMode
//-----------------------------------------------------------------------------
// implementation of class DisplayMode
Gura_ImplementUserClass(DisplayMode)
{
}

Gura_EndModuleScope(sdl2)
