#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_AudioCVT implementation
//-----------------------------------------------------------------------------
Object_AudioCVT::~Object_AudioCVT()
{
}

Object *Object_AudioCVT::Clone() const
{
	return NULL;
}

String Object_AudioCVT::ToString(bool exprFlag)
{
	return String("<sdl2.AudioCVT>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for AudioCVT
//-----------------------------------------------------------------------------
// implementation of class AudioCVT
Gura_ImplementUserClass(AudioCVT)
{
}

Gura_EndModuleScope(sdl2)
