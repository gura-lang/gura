#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Event implementation
//-----------------------------------------------------------------------------
Object_Event::~Object_Event()
{
}

Object *Object_Event::Clone() const
{
	return NULL;
}

String Object_Event::ToString(bool exprFlag)
{
	return String("<sdl2.Event>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Event
//-----------------------------------------------------------------------------
// implementation of class Event
Gura_ImplementUserClass(Event)
{
}

Gura_EndModuleScope(sdl2)
