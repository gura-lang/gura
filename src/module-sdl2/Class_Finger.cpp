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

bool Object_Finger::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_Finger::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Finger::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Finger
//-----------------------------------------------------------------------------
// implementation of class Finger
Gura_ImplementUserClass(Finger)
{
}

Gura_EndModuleScope(sdl2)
