#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Keysym implementation
//-----------------------------------------------------------------------------
Object_Keysym::~Object_Keysym()
{
}

Object *Object_Keysym::Clone() const
{
	return nullptr;
}

String Object_Keysym::ToString(bool exprFlag)
{
	return String("<sdl2.Keysym>");
}

bool Object_Keysym::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(scancode));
	symbols.insert(Gura_UserSymbol(sym));
	symbols.insert(Gura_UserSymbol(mod));
	return true;
}

Value Object_Keysym::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(scancode))) {
		return Value(_keysym.scancode);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(sym))) {
		return Value(_keysym.sym);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(mod))) {
		return Value(_keysym.mod);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Keysym::DoSetProp(Environment &env, Signal sig,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Keysym
//-----------------------------------------------------------------------------
// implementation of class Keysym
Gura_ImplementUserClass(Keysym)
{
	Gura_AssignValue(Keysym, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
