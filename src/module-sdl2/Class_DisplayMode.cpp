#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_DisplayMode implementation
//-----------------------------------------------------------------------------
Object_DisplayMode::~Object_DisplayMode()
{
}

Object *Object_DisplayMode::Clone() const
{
	return NULL;
}

String Object_DisplayMode::ToString(bool exprFlag)
{
	return String("<sdl2.DisplayMode>");
}

bool Object_DisplayMode::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(format));
	symbols.insert(Gura_UserSymbol(w));
	symbols.insert(Gura_UserSymbol(h));
	symbols.insert(Gura_UserSymbol(refresh_rate));
	return true;
}

Value Object_DisplayMode::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		return Value(_mode.format);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
		return Value(_mode.w);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
		return Value(_mode.h);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(refresh_rate))) {
		return Value(_mode.refresh_rate);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_DisplayMode::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for DisplayMode
//-----------------------------------------------------------------------------
// implementation of class DisplayMode
Gura_ImplementUserClass(DisplayMode)
{
}

Gura_EndModuleScope(sdl2)
