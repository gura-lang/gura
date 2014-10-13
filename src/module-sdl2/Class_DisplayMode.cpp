#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_DisplayMode implementation
//-----------------------------------------------------------------------------
Object_DisplayMode::~Object_DisplayMode()
{
}

Object *Object_DisplayMode::Clone() const
{
	return NULL;
}

String Object_DisplayMode::ToString(bool exprFlag)
{
	return String("<sdl2.DisplayMode>");
}

bool Object_DisplayMode::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_DisplayMode::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_DisplayMode::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for DisplayMode
//-----------------------------------------------------------------------------
// implementation of class DisplayMode
Gura_ImplementUserClass(DisplayMode)
{
}

Gura_EndModuleScope(sdl2)
