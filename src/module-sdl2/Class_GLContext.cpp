#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_GLContext implementation
//-----------------------------------------------------------------------------
Object_GLContext::~Object_GLContext()
{
	::SDL_GL_DeleteContext(_context);
}

Object *Object_GLContext::Clone() const
{
	return NULL;
}

String Object_GLContext::ToString(bool exprFlag)
{
	return String("<sdl2.GLContext>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for GLContext
//-----------------------------------------------------------------------------
// implementation of class GLContext
Gura_ImplementUserClass(GLContext)
{
}

Gura_EndModuleScope(sdl2)
