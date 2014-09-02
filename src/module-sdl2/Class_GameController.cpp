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

//-----------------------------------------------------------------------------
// Gura interfaces for GameController
//-----------------------------------------------------------------------------
// implementation of class GameController
Gura_ImplementUserClass(GameController)
{
}

Gura_EndModuleScope(sdl2)
