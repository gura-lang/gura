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

bool Object_AudioCVT::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_AudioCVT::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_AudioCVT::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for AudioCVT
//-----------------------------------------------------------------------------
// implementation of class AudioCVT
Gura_ImplementUserClass(AudioCVT)
{
}

Gura_EndModuleScope(sdl2)
