#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_GameControllerButtonBind implementation
//-----------------------------------------------------------------------------
Object_GameControllerButtonBind::~Object_GameControllerButtonBind()
{
}

Object *Object_GameControllerButtonBind::Clone() const
{
	return nullptr;
}

String Object_GameControllerButtonBind::ToString(bool exprFlag)
{
	return String("<sdl2.GameControllerButtonBind>");
}

bool Object_GameControllerButtonBind::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Object_GameControllerButtonBind::DoGetProp(Environment &env, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_GameControllerButtonBind::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for GameControllerButtonBind
//-----------------------------------------------------------------------------
// implementation of class GameControllerButtonBind
Gura_ImplementUserClass(GameControllerButtonBind)
{
	Gura_AssignValue(GameControllerButtonBind, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
