#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Window implementation
//-----------------------------------------------------------------------------
Object_Window::~Object_Window()
{
	::SDL_DestroyWindow(_pWindow);
}

Object *Object_Window::Clone() const
{
	return NULL;
}

String Object_Window::ToString(bool exprFlag)
{
	return String("<sdl2.Window>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Window
//-----------------------------------------------------------------------------
// implementation of class Window
Gura_ImplementUserClass(Window)
{
}

Gura_EndModuleScope(sdl2)
