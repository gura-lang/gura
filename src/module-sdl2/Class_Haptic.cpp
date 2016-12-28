#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Haptic implementation
//-----------------------------------------------------------------------------
Object_Haptic::~Object_Haptic()
{
	::SDL_HapticClose(_pHaptic);
}

Object *Object_Haptic::Clone() const
{
	return nullptr;
}

String Object_Haptic::ToString(bool exprFlag)
{
	return String("<sdl2.Haptic>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Haptic
//-----------------------------------------------------------------------------
// implementation of class Haptic
Gura_ImplementUserClass(Haptic)
{
	Gura_AssignValue(Haptic, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
