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

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.Keysym#mod
Gura_DeclareProperty_R(Keysym, mod)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Keysym, mod)
{
	const SDL_Keysym &keysym = *Object_Keysym::GetObject(valueThis)->GetEntity();
	return Value(keysym.mod);
}

// sdl2.Keysym#scancode
Gura_DeclareProperty_R(Keysym, scancode)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Keysym, scancode)
{
	const SDL_Keysym &keysym = *Object_Keysym::GetObject(valueThis)->GetEntity();
	return Value(keysym.scancode);
}

// sdl2.Keysym#sym
Gura_DeclareProperty_R(Keysym, sym)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Keysym, sym)
{
	const SDL_Keysym &keysym = *Object_Keysym::GetObject(valueThis)->GetEntity();
	return Value(keysym.sym);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Keysym
//-----------------------------------------------------------------------------
// implementation of class Keysym
Gura_ImplementUserClass(Keysym)
{
	// Assignment of properties
	Gura_AssignProperty(Keysym, mod);
	Gura_AssignProperty(Keysym, scancode);
	Gura_AssignProperty(Keysym, sym);
	// Assignment of value
	Gura_AssignValue(Keysym, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
