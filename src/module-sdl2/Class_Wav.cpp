#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Wav implementation
//-----------------------------------------------------------------------------
Object_Wav::~Object_Wav()
{
}

Object *Object_Wav::Clone() const
{
	return nullptr;
}

String Object_Wav::ToString(bool exprFlag)
{
	return String("<sdl2.Wav>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Wav
//-----------------------------------------------------------------------------
// implementation of class Wav
Gura_ImplementUserClass(Wav)
{
	Gura_AssignValue(Wav, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
