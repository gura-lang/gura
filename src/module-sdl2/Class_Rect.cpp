#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Rect implementation
//-----------------------------------------------------------------------------
Object_Rect::~Object_Rect()
{
}

Object *Object_Rect::Clone() const
{
	return nullptr;
}

String Object_Rect::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl2.Rect:x=%d,y=%d,w=%d,h=%d>",
			  					_rect.x, _rect.y, _rect.w, _rect.h);
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.Rect#h
Gura_DeclareProperty_RW(Rect, h)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Rect, h)
{
	const SDL_Rect &rect = *Object_Rect::GetObject(valueThis)->GetEntity();
	return Value(rect.h);
}

Gura_ImplementPropertySetter(Rect, h)
{
	SDL_Rect &rect = *Object_Rect::GetObject(valueThis)->GetEntity();
	rect.h = value.GetUShort();
	return Value(rect.h);
}

// sdl2.Rect#w
Gura_DeclareProperty_RW(Rect, w)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Rect, w)
{
	const SDL_Rect &rect = *Object_Rect::GetObject(valueThis)->GetEntity();
	return Value(rect.w);
}

Gura_ImplementPropertySetter(Rect, w)
{
	SDL_Rect &rect = *Object_Rect::GetObject(valueThis)->GetEntity();
	rect.w = value.GetUShort();
	return Value(rect.w);
}

// sdl2.Rect#x
Gura_DeclareProperty_RW(Rect, x)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Rect, x)
{
	const SDL_Rect &rect = *Object_Rect::GetObject(valueThis)->GetEntity();
	return Value(rect.x);
}

Gura_ImplementPropertySetter(Rect, x)
{
	SDL_Rect &rect = *Object_Rect::GetObject(valueThis)->GetEntity();
	rect.x = value.GetShort();
	return Value(rect.x);
}

// sdl2.Rect#y
Gura_DeclareProperty_RW(Rect, y)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Rect, y)
{
	const SDL_Rect &rect = *Object_Rect::GetObject(valueThis)->GetEntity();
	return Value(rect.y);
}

Gura_ImplementPropertySetter(Rect, y)
{
	SDL_Rect &rect = *Object_Rect::GetObject(valueThis)->GetEntity();
	rect.y = value.GetShort();
	return Value(rect.y);
}

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
// sdl2.Rect(x?:number, y?:number, w?:number, h?:number)
Gura_DeclareFunction(Rect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	DeclareArg(env, "w", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	DeclareArg(env, "h", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	SetClassToConstruct(Gura_UserClass(Rect));
	AddHelp(
		Gura_Symbol(en),
		"Creates an instance of `sdl2.Rect` with the specified position `[x, y]`\n"
		"and size `[w, h]`\n"
		"If the argument `x`, `y`, `w` or `h` is omitted, they are set to zero.\n");
}

Gura_ImplementFunction(Rect)
{
	SDL_Rect rect;
	rect.x = arg.IsValid(0)? arg.GetInt(0) : 0;
	rect.y = arg.IsValid(1)? arg.GetInt(1) : 0;
	rect.w = arg.IsValid(2)? arg.GetInt(2) : 0;
	rect.h = arg.IsValid(3)? arg.GetInt(3) : 0;
	return Value(new Object_Rect(rect));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Rect
//-----------------------------------------------------------------------------
// implementation of class Rect
Gura_ImplementUserClass(Rect)
{
	// Assignment of properties
	Gura_AssignProperty(Rect, h);
	Gura_AssignProperty(Rect, w);
	Gura_AssignProperty(Rect, x);
	Gura_AssignProperty(Rect, y);
	// Assignment of function
	Gura_AssignFunction(Rect);
}

Gura_EndModuleScope(sdl2)
