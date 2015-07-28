#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Finger implementation
//-----------------------------------------------------------------------------
Object_Finger::~Object_Finger()
{
	//::SDL_DestroyFinger(_pFinger);
}

Object *Object_Finger::Clone() const
{
	return nullptr;
}

String Object_Finger::ToString(bool exprFlag)
{
	return String("<sdl2.Finger>");
}

bool Object_Finger::DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(id));
	symbols.insert(Gura_UserSymbol(x));
	symbols.insert(Gura_UserSymbol(y));
	symbols.insert(Gura_UserSymbol(pressure));
	return true;
}

Value Object_Finger::DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(id))) {
		return Value(_pFinger->id);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(x))) {
		return Value(_pFinger->x);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(y))) {
		return Value(_pFinger->y);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(pressure))) {
		return Value(_pFinger->pressure);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_Finger::DoSetProp(Environment &env, Signal &__to_delete__,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Finger
//-----------------------------------------------------------------------------
// implementation of class Finger
Gura_ImplementUserClass(Finger)
{
	Gura_AssignValue(Finger, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
