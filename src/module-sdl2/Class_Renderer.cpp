#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Renderer implementation
//-----------------------------------------------------------------------------
Object_Renderer::~Object_Renderer()
{
	::SDL_DestroyRenderer(_pRenderer);
}

Object *Object_Renderer::Clone() const
{
	return NULL;
}

String Object_Renderer::ToString(bool exprFlag)
{
	return String("<sdl2.Renderer>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Renderer
//-----------------------------------------------------------------------------
// implementation of class Renderer
Gura_ImplementUserClass(Renderer)
{
}

Gura_EndModuleScope(sdl2)
