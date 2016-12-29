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
	return nullptr;
}

String Object_DisplayMode::ToString(bool exprFlag)
{
	return String("<sdl2.DisplayMode>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.DisplayMode#format
Gura_DeclareProperty_RW(DisplayMode, format)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(DisplayMode, format)
{
	const SDL_DisplayMode &mode = *Object_DisplayMode::GetObject(valueThis)->GetEntity();
	return Value(mode.format);
}

Gura_ImplementPropertySetter(DisplayMode, format)
{
	SDL_DisplayMode &mode = *Object_DisplayMode::GetObject(valueThis)->GetEntity();
	mode.format = value.GetLong();
	return Value(mode.format);
}

// sdl2.DisplayMode#h
Gura_DeclareProperty_RW(DisplayMode, h)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(DisplayMode, h)
{
	const SDL_DisplayMode &mode = *Object_DisplayMode::GetObject(valueThis)->GetEntity();
	return Value(mode.h);
}

Gura_ImplementPropertySetter(DisplayMode, h)
{
	SDL_DisplayMode &mode = *Object_DisplayMode::GetObject(valueThis)->GetEntity();
	mode.h = value.GetInt();
	return Value(mode.h);
}

// sdl2.DisplayMode#refresh_rate
Gura_DeclareProperty_RW(DisplayMode, refresh_rate)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(DisplayMode, refresh_rate)
{
	const SDL_DisplayMode &mode = *Object_DisplayMode::GetObject(valueThis)->GetEntity();
	return Value(mode.refresh_rate);
}

Gura_ImplementPropertySetter(DisplayMode, refresh_rate)
{
	SDL_DisplayMode &mode = *Object_DisplayMode::GetObject(valueThis)->GetEntity();
	mode.refresh_rate = value.GetInt();
	return Value(mode.refresh_rate);
}

// sdl2.DisplayMode#w
Gura_DeclareProperty_RW(DisplayMode, w)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(DisplayMode, w)
{
	const SDL_DisplayMode &mode = *Object_DisplayMode::GetObject(valueThis)->GetEntity();
	return Value(mode.w);
}

Gura_ImplementPropertySetter(DisplayMode, w)
{
	SDL_DisplayMode &mode = *Object_DisplayMode::GetObject(valueThis)->GetEntity();
	mode.w = value.GetInt();
	return Value(mode.w);
}

//-----------------------------------------------------------------------------
// Gura interfaces for DisplayMode
//-----------------------------------------------------------------------------
// sdl2.DisplayMode()
Gura_DeclareFunction(DisplayMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(DisplayMode));
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementFunction(DisplayMode)
{
	SDL_DisplayMode mode;
	::memset(&mode, 0x00, sizeof(mode));
	return Value(new Object_DisplayMode(mode));
}

// implementation of class DisplayMode
Gura_ImplementUserClass(DisplayMode)
{
	// Assignment of function
	Gura_AssignFunction(DisplayMode);
	// Assignment of properties
	Gura_AssignProperty(DisplayMode, format);
	Gura_AssignProperty(DisplayMode, h);
	Gura_AssignProperty(DisplayMode, refresh_rate);
	Gura_AssignProperty(DisplayMode, w);
}

Gura_EndModuleScope(sdl2)
