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

bool Object_Finger::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(id));
	symbols.insert(Gura_UserSymbol(x));
	symbols.insert(Gura_UserSymbol(y));
	symbols.insert(Gura_UserSymbol(pressure));
	return true;
}

Value Object_Finger::DoGetProp(Environment &env, const Symbol *pSymbol,
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
	return Value::Nil;
}

Value Object_Finger::DoSetProp(Environment &env,
							  const Symbol *pSymbol, const Value &value,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.Finger#id
Gura_DeclareProperty_R(Finger, id)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Finger, id)
{
	return Value::Nil;
}

// sdl2.Finger#pressure
Gura_DeclareProperty_R(Finger, pressure)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Finger, pressure)
{
	return Value::Nil;
}

// sdl2.Finger#x
Gura_DeclareProperty_R(Finger, x)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Finger, x)
{
	return Value::Nil;
}

// sdl2.Finger#y
Gura_DeclareProperty_R(Finger, y)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Finger, y)
{
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Finger
//-----------------------------------------------------------------------------
// implementation of class Finger
Gura_ImplementUserClass(Finger)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(Finger, id);
	Gura_AssignProperty(Finger, pressure);
	Gura_AssignProperty(Finger, x);
	Gura_AssignProperty(Finger, y);
#endif
	// Assignment of value
	Gura_AssignValue(Finger, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
