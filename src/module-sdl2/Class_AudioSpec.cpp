#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_AudioSpec implementation
//-----------------------------------------------------------------------------
Object_AudioSpec::~Object_AudioSpec()
{
}

Object *Object_AudioSpec::Clone() const
{
	return NULL;
}

String Object_AudioSpec::ToString(bool exprFlag)
{
	return String("<sdl2.AudioSpec>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for AudioSpec
//-----------------------------------------------------------------------------
// implementation of class AudioSpec
Gura_ImplementUserClass(AudioSpec)
{
}

Gura_EndModuleScope(sdl2)
