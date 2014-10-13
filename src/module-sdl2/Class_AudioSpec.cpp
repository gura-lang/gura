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

bool Object_AudioSpec::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_AudioSpec::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_AudioSpec::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for AudioSpec
//-----------------------------------------------------------------------------
// implementation of class AudioSpec
Gura_ImplementUserClass(AudioSpec)
{
}

Gura_EndModuleScope(sdl2)
