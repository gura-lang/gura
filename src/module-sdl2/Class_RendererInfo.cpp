#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_RendererInfo implementation
//-----------------------------------------------------------------------------
Object_RendererInfo::~Object_RendererInfo()
{
}

Object *Object_RendererInfo::Clone() const
{
	return nullptr;
}

String Object_RendererInfo::ToString(bool exprFlag)
{
	return String("<sdl2.RendererInfo>");
}

bool Object_RendererInfo::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Object_RendererInfo::DoGetProp(Environment &env, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_RendererInfo::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for RendererInfo
//-----------------------------------------------------------------------------
// implementation of class RendererInfo
Gura_ImplementUserClass(RendererInfo)
{
	Gura_AssignValue(RendererInfo, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
