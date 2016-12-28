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

bool Object_Keysym::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(scancode));
	symbols.insert(Gura_UserSymbol(sym));
	symbols.insert(Gura_UserSymbol(mod));
	return true;
}

Value Object_Keysym::DoGetProp(Environment &env, const Symbol *pSymbol,
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
	return Value::Nil;
}

Value Object_Keysym::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.Keysym#mod
Gura_DeclareProperty_R(Keysym, mod)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Keysym, mod)
{
	return Value::Nil;
}

// sdl2.Keysym#scancode
Gura_DeclareProperty_R(Keysym, scancode)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Keysym, scancode)
{
	return Value::Nil;
}

// sdl2.Keysym#sym
Gura_DeclareProperty_R(Keysym, sym)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Keysym, sym)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Keysym
//-----------------------------------------------------------------------------
// implementation of class Keysym
Gura_ImplementUserClass(Keysym)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(Keysym, mod);
	Gura_AssignProperty(Keysym, scancode);
	Gura_AssignProperty(Keysym, sym);
#endif
	// Assignment of value
	Gura_AssignValue(Keysym, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
