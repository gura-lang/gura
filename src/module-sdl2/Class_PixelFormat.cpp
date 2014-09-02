#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_PixelFormat implementation
//-----------------------------------------------------------------------------
Object_PixelFormat::~Object_PixelFormat()
{
	//::SDL_DestroyPixelFormat(_pPixelFormat);
}

Object *Object_PixelFormat::Clone() const
{
	return NULL;
}

String Object_PixelFormat::ToString(bool exprFlag)
{
	return String("<sdl2.PixelFormat>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for PixelFormat
//-----------------------------------------------------------------------------
// implementation of class PixelFormat
Gura_ImplementUserClass(PixelFormat)
{
}

Gura_EndModuleScope(sdl2)
