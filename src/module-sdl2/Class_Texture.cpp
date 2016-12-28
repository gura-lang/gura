#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Texture implementation
//-----------------------------------------------------------------------------
Object_Texture::~Object_Texture()
{
	::SDL_DestroyTexture(_pTexture);
}

Object *Object_Texture::Clone() const
{
	return nullptr;
}

String Object_Texture::ToString(bool exprFlag)
{
	return String("<sdl2.Texture>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Texture
//-----------------------------------------------------------------------------
// implementation of class Texture
Gura_ImplementUserClass(Texture)
{
	Gura_AssignValue(Texture, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
