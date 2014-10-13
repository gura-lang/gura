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

bool Object_HapticEffect::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_HapticEffect::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_HapticEffect::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for HapticEffect
//-----------------------------------------------------------------------------
// implementation of class HapticEffect
Gura_ImplementUserClass(HapticEffect)
{
}

Gura_EndModuleScope(sdl2)
