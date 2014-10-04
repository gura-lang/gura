#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_HapticEffect implementation
//-----------------------------------------------------------------------------
Object_HapticEffect::~Object_HapticEffect()
{
	//::SDL_HapticEffectClose(_pHapticEffect);
}

Object *Object_HapticEffect::Clone() const
{
	return NULL;
}

String Object_HapticEffect::ToString(bool exprFlag)
{
	return String("<sdl2.HapticEffect>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for HapticEffect
//-----------------------------------------------------------------------------
// implementation of class HapticEffect
Gura_ImplementUserClass(HapticEffect)
{
}

Gura_EndModuleScope(sdl2)
