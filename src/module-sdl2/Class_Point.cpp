#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Point implementation
//-----------------------------------------------------------------------------
Object_Point::~Object_Point()
{
}

Object *Object_Point::Clone() const
{
	return nullptr;
}

String Object_Point::ToString(bool exprFlag)
{
	char buff[80];
	::sprintf(buff, "<sdl2.Point:x=%d,y=%d>", _point.x, _point.y);
	return String(buff);
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.Point#x
Gura_DeclareProperty_RW(Point, x)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Point, x)
{
	const SDL_Point &point = *Object_Point::GetObject(valueThis)->GetEntity();
	return Value(point.x);
}

Gura_ImplementPropertySetter(Point, x)
{
	SDL_Point &point = *Object_Point::GetObject(valueThis)->GetEntity();
	point.x = value.GetShort();
	return Value(point.x);
}

// sdl2.Point#y
Gura_DeclareProperty_RW(Point, y)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Point, y)
{
	const SDL_Point &point = *Object_Point::GetObject(valueThis)->GetEntity();
	return Value(point.y);
}

Gura_ImplementPropertySetter(Point, y)
{
	SDL_Point &point = *Object_Point::GetObject(valueThis)->GetEntity();
	point.y = value.GetShort();
	return Value(point.y);
}

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------
// sdl2.Point(x?:number, y?:number)
Gura_DeclareFunction(Point)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	DeclareArg(env, "y", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_None);
	SetClassToConstruct(Gura_UserClass(Point));
	AddHelp(
		Gura_Symbol(en),
		"Creates an instance of `sdl2.Point` with the specified position `[x, y]`.\n"
		"If  the argument `x` or `y` is omitted, they are set to zero.\n");
}

Gura_ImplementFunction(Point)
{
	SDL_Point point;
	point.x = arg.IsValid(0)? arg.GetInt(0) : 0;
	point.y = arg.IsValid(1)? arg.GetInt(1) : 0;
	return Value(new Object_Point(point));
}

//-----------------------------------------------------------------------------
// Gura interfaces for Point
//-----------------------------------------------------------------------------
// implementation of class Point
Gura_ImplementUserClass(Point)
{
	// Assinment of function
	Gura_AssignFunction(Point);
	// Assignment of properties
	Gura_AssignProperty(Point, x);
	Gura_AssignProperty(Point, y);
}

Gura_EndModuleScope(sdl2)
