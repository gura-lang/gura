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
	return nullptr;
}

String Object_JoystickGUID::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl2.JoystickGUID>");
	return String(buff);
}

bool Object_JoystickGUID::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Object_JoystickGUID::DoGetProp(Environment &env, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_JoystickGUID::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for JoystickGUID
//-----------------------------------------------------------------------------
// implementation of class JoystickGUID
Gura_ImplementUserClass(JoystickGUID)
{
	Gura_AssignValue(JoystickGUID, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
