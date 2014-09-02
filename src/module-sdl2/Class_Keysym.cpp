#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Keysym implementation
//-----------------------------------------------------------------------------
Object_Keysym::~Object_Keysym()
{
}

Object *Object_Keysym::Clone() const
{
	return NULL;
}

String Object_Keysym::ToString(bool exprFlag)
{
	return String("<sdl2.Keysym>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Keysym
//-----------------------------------------------------------------------------
// implementation of class Keysym
Gura_ImplementUserClass(Keysym)
{
}

Gura_EndModuleScope(sdl2)
