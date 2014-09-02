#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Palette implementation
//-----------------------------------------------------------------------------
Object_Palette::~Object_Palette()
{
	::SDL_FreePalette(_pPalette);
}

Object *Object_Palette::Clone() const
{
	return NULL;
}

String Object_Palette::ToString(bool exprFlag)
{
	return String("<sdl2.Palette>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Palette
//-----------------------------------------------------------------------------
// implementation of class Palette
Gura_ImplementUserClass(Palette)
{
}

Gura_EndModuleScope(sdl2)
