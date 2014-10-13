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

bool Object_GLContext::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_GLContext::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_GLContext::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for GLContext
//-----------------------------------------------------------------------------
// implementation of class GLContext
Gura_ImplementUserClass(GLContext)
{
}

Gura_EndModuleScope(sdl2)
