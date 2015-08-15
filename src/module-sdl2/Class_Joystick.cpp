#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Joystick implementation
//-----------------------------------------------------------------------------
Object_Joystick::~Object_Joystick()
{
	::SDL_JoystickClose(_pJoystick);
}

Object *Object_Joystick::Clone() const
{
	return nullptr;
}

String Object_Joystick::ToString(bool exprFlag)
{
	return String("<sdl2.Joystick>");
}

bool Object_Joystick::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Object_Joystick::DoGetProp(Environment &env, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_Joystick::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Joystick
//-----------------------------------------------------------------------------
// implementation of class Joystick
Gura_ImplementUserClass(Joystick)
{
	Gura_AssignValue(Joystick, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
