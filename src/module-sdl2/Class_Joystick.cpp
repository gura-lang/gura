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
	return NULL;
}

String Object_Joystick::ToString(bool exprFlag)
{
	return String("<sdl2.Joystick>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Joystick
//-----------------------------------------------------------------------------
// implementation of class Joystick
Gura_ImplementUserClass(Joystick)
{
}

Gura_EndModuleScope(sdl2)
