#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Finger implementation
//-----------------------------------------------------------------------------
Object_Finger::~Object_Finger()
{
	//::SDL_DestroyFinger(_pFinger);
}

Object *Object_Finger::Clone() const
{
	return NULL;
}

String Object_Finger::ToString(bool exprFlag)
{
	return String("<sdl2.Finger>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Finger
//-----------------------------------------------------------------------------
// implementation of class Finger
Gura_ImplementUserClass(Finger)
{
}

Gura_EndModuleScope(sdl2)
