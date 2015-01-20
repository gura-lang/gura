#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_GameController implementation
//-----------------------------------------------------------------------------
Object_GameController::~Object_GameController()
{
	::SDL_GameControllerClose(_pGameController);
}

Object *Object_GameController::Clone() const
{
	return NULL;
}

String Object_GameController::ToString(bool exprFlag)
{
	return String("<sdl2.GameController>");
}

bool Object_GameController::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_GameController::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_GameController::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for GameController
//-----------------------------------------------------------------------------
// implementation of class GameController
Gura_ImplementUserClass(GameController)
{
	Gura_AssignValue(GameController, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
