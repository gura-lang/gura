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

//-----------------------------------------------------------------------------
// Gura interfaces for JoystickGUID
//-----------------------------------------------------------------------------
// implementation of class JoystickGUID
Gura_ImplementUserClass(JoystickGUID)
{
}

Gura_EndModuleScope(sdl2)
