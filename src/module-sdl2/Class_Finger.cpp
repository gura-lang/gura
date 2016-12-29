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

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.Finger#id
Gura_DeclareProperty_R(Finger, id)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Finger, id)
{
	const SDL_Finger *pFinger = Object_Finger::GetObject(valueThis)->GetEntity();
	return Value(pFinger->id);
}

// sdl2.Finger#pressure
Gura_DeclareProperty_R(Finger, pressure)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Finger, pressure)
{
	const SDL_Finger *pFinger = Object_Finger::GetObject(valueThis)->GetEntity();
	return Value(pFinger->pressure);
}

// sdl2.Finger#x
Gura_DeclareProperty_R(Finger, x)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Finger, x)
{
	const SDL_Finger *pFinger = Object_Finger::GetObject(valueThis)->GetEntity();
	return Value(pFinger->x);
}

// sdl2.Finger#y
Gura_DeclareProperty_R(Finger, y)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Finger, y)
{
	const SDL_Finger *pFinger = Object_Finger::GetObject(valueThis)->GetEntity();
	return Value(pFinger->y);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Finger
//-----------------------------------------------------------------------------
// implementation of class Finger
Gura_ImplementUserClass(Finger)
{
	// Assignment of properties
	Gura_AssignProperty(Finger, id);
	Gura_AssignProperty(Finger, pressure);
	Gura_AssignProperty(Finger, x);
	Gura_AssignProperty(Finger, y);
	// Assignment of value
	Gura_AssignValue(Finger, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
