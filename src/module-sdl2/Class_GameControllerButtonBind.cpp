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
	return NULL;
}

String Object_GameControllerButtonBind::ToString(bool exprFlag)
{
	return String("<sdl2.GameControllerButtonBind>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for GameControllerButtonBind
//-----------------------------------------------------------------------------
// implementation of class GameControllerButtonBind
Gura_ImplementUserClass(GameControllerButtonBind)
{
}

Gura_EndModuleScope(sdl2)
