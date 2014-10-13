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

bool Object_Keysym::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_Keysym::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Keysym::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Keysym
//-----------------------------------------------------------------------------
// implementation of class Keysym
Gura_ImplementUserClass(Keysym)
{
}

Gura_EndModuleScope(sdl2)
