#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Color implementation
//-----------------------------------------------------------------------------
Object_Color::~Object_Color()
{
}

Object *Object_Color::Clone() const
{
	return nullptr;
}

String Object_Color::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl2.Color:r=%d,g=%d,b=%d>", _color.r, _color.g, _color.b);
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.Color#b
Gura_DeclareProperty_RW(Color, b)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Color, b)
{
	const SDL_Color &color = *Object_Color::GetObject(valueThis)->GetEntity();
	return Value(color.b);
}

Gura_ImplementPropertySetter(Color, b)
{
	SDL_Color &color = *Object_Color::GetObject(valueThis)->GetEntity();
	color.b = value.GetUChar();
	return Value(color.b);
}

// sdl2.Color#g
Gura_DeclareProperty_RW(Color, g)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Color, g)
{
	const SDL_Color &color = *Object_Color::GetObject(valueThis)->GetEntity();
	return Value(color.g);
}

Gura_ImplementPropertySetter(Color, g)
{
	SDL_Color &color = *Object_Color::GetObject(valueThis)->GetEntity();
	color.g = value.GetUChar();
	return Value(color.g);
}

// sdl2.Color#r
Gura_DeclareProperty_RW(Color, r)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Color, r)
{
	const SDL_Color &color = *Object_Color::GetObject(valueThis)->GetEntity();
	return Value(color.r);
}

Gura_ImplementPropertySetter(Color, r)
{
	SDL_Color &color = *Object_Color::GetObject(valueThis)->GetEntity();
	color.r = value.GetUChar();
	return Value(color.r);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Color
//-----------------------------------------------------------------------------
// sdl2.Color(r?:number, g?:number, b?:number)
Gura_DeclareFunction(Color)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "r", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	DeclareArg(env, "g", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	DeclareArg(env, "b", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	SetClassToConstruct(Gura_UserClass(Color));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(Color)
{
	SDL_Color color;
	color.r = arg.IsValid(0)? arg.GetInt(0) : 0;
	color.g = arg.IsValid(1)? arg.GetInt(1) : 0;
	color.b = arg.IsValid(2)? arg.GetInt(2) : 0;
	return Value(new Object_Color(color));
}

// implementation of class Color
Gura_ImplementUserClass(Color)
{
	// Assignment of function
	Gura_AssignFunction(Color);
	// Assignment of properties
	Gura_AssignProperty(Color, b);
	Gura_AssignProperty(Color, g);
	Gura_AssignProperty(Color, r);
}

Gura_EndModuleScope(sdl2)
