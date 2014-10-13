#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Texture implementation
//-----------------------------------------------------------------------------
Object_Texture::~Object_Texture()
{
	::SDL_DestroyTexture(_pTexture);
}

Object *Object_Texture::Clone() const
{
	return NULL;
}

String Object_Texture::ToString(bool exprFlag)
{
	return String("<sdl2.Texture>");
}

bool Object_Texture::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	return true;
}

Value Object_Texture::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Texture::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Texture
//-----------------------------------------------------------------------------
// implementation of class Texture
Gura_ImplementUserClass(Texture)
{
}

Gura_EndModuleScope(sdl2)
