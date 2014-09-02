#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Cursor implementation
//-----------------------------------------------------------------------------
Object_Cursor::~Object_Cursor()
{
	if (_ownerFlag) ::SDL_FreeCursor(_pCursor);
}

Object *Object_Cursor::Clone() const
{
	return NULL;
}

String Object_Cursor::ToString(bool exprFlag)
{
	return String("<sdl2.Cursor>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for Cursor
//-----------------------------------------------------------------------------
// implementation of class Cursor
Gura_ImplementUserClass(Cursor)
{
}

Gura_EndModuleScope(sdl2)
