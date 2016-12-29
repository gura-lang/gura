#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_PixelFormat implementation
//-----------------------------------------------------------------------------
Object_PixelFormat::~Object_PixelFormat()
{
	//::SDL_DestroyPixelFormat(_pPixelFormat);
}

Object *Object_PixelFormat::Clone() const
{
	return nullptr;
}

String Object_PixelFormat::ToString(bool exprFlag)
{
	return String("<sdl2.PixelFormat>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.PixelFormat#Amask
Gura_DeclareProperty_R(PixelFormat, Amask)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(PixelFormat, Amask)
{
	const SDL_PixelFormat *pPixelFormat = Object_PixelFormat::GetObject(valueThis)->GetEntity();
	return Value(pPixelFormat->Amask);
}

// sdl2.PixelFormat#BitsPerPixel
Gura_DeclareProperty_R(PixelFormat, BitsPerPixel)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(PixelFormat, BitsPerPixel)
{
	const SDL_PixelFormat *pPixelFormat = Object_PixelFormat::GetObject(valueThis)->GetEntity();
	return Value(pPixelFormat->BitsPerPixel);
}

// sdl2.PixelFormat#Bmask
Gura_DeclareProperty_R(PixelFormat, Bmask)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(PixelFormat, Bmask)
{
	const SDL_PixelFormat *pPixelFormat = Object_PixelFormat::GetObject(valueThis)->GetEntity();
	return Value(pPixelFormat->Bmask);
}

// sdl2.PixelFormat#BytesPerPixel
Gura_DeclareProperty_R(PixelFormat, BytesPerPixel)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(PixelFormat, BytesPerPixel)
{
	const SDL_PixelFormat *pPixelFormat = Object_PixelFormat::GetObject(valueThis)->GetEntity();
	return Value(pPixelFormat->BytesPerPixel);
}

// sdl2.PixelFormat#Gmask
Gura_DeclareProperty_R(PixelFormat, Gmask)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(PixelFormat, Gmask)
{
	const SDL_PixelFormat *pPixelFormat = Object_PixelFormat::GetObject(valueThis)->GetEntity();
	return Value(pPixelFormat->Gmask);
}

// sdl2.PixelFormat#Rmask
Gura_DeclareProperty_R(PixelFormat, Rmask)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(PixelFormat, Rmask)
{
	const SDL_PixelFormat *pPixelFormat = Object_PixelFormat::GetObject(valueThis)->GetEntity();
	return Value(pPixelFormat->Rmask);
}

// sdl2.PixelFormat#palette
Gura_DeclareProperty_R(PixelFormat, palette)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(PixelFormat, palette)
{
	const SDL_PixelFormat *pPixelFormat = Object_PixelFormat::GetObject(valueThis)->GetEntity();
	if (pPixelFormat->palette == nullptr) return Value::Nil;
	return Value(new Object_Palette(pPixelFormat->palette));
}

//-----------------------------------------------------------------------------
// Gura interfaces for PixelFormat
//-----------------------------------------------------------------------------
// implementation of class PixelFormat
Gura_ImplementUserClass(PixelFormat)
{
	// Assignment of properties
	Gura_AssignProperty(PixelFormat, Amask);
	Gura_AssignProperty(PixelFormat, BitsPerPixel);
	Gura_AssignProperty(PixelFormat, Bmask);
	Gura_AssignProperty(PixelFormat, BytesPerPixel);
	Gura_AssignProperty(PixelFormat, Gmask);
	Gura_AssignProperty(PixelFormat, Rmask);
	Gura_AssignProperty(PixelFormat, palette);
	// Assignment of value
	Gura_AssignValue(PixelFormat, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
