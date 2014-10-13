#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_JoystickGUID implementation
//-----------------------------------------------------------------------------
Object_JoystickGUID::~Object_JoystickGUID()
{
}

Object *Object_JoystickGUID::Clone() const
{
	return NULL;
}

String Object_JoystickGUID::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl2.JoystickGUID>");
	return String(buff);
}

bool Object_JoystickGUID::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_JoystickGUID::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_JoystickGUID::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for JoystickGUID
//-----------------------------------------------------------------------------
// implementation of class JoystickGUID
Gura_ImplementUserClass(JoystickGUID)
{
}

Gura_EndModuleScope(sdl2)
