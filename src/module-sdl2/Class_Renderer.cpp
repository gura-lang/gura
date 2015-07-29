#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Renderer implementation
//-----------------------------------------------------------------------------
Object_Renderer::~Object_Renderer()
{
	::SDL_DestroyRenderer(_pRenderer);
}

Object *Object_Renderer::Clone() const
{
	return nullptr;
}

String Object_Renderer::ToString(bool exprFlag)
{
	return String("<sdl2.Renderer>");
}

bool Object_Renderer::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Object_Renderer::DoGetProp(Environment &env, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Renderer::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Renderer
//-----------------------------------------------------------------------------
// implementation of class Renderer
Gura_ImplementUserClass(Renderer)
{
	Gura_AssignValue(Renderer, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
