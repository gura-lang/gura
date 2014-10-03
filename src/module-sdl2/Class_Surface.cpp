#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Surface implementation
//-----------------------------------------------------------------------------
Object_Surface::~Object_Surface()
{
	::SDL_DestroySurface(_pSurface);
}

Object *Object_Surface::Clone() const
{
	return NULL;
}

String Object_Surface::ToString(bool exprFlag)
{
	return String("<sdl2.Surface>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Surface
//-----------------------------------------------------------------------------
// implementation of class Surface
Gura_ImplementUserClass(Surface)
{
}

Gura_EndModuleScope(sdl2)
