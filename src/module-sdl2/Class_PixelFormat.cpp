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

bool Object_PixelFormat::DoDirProp(Environment &env, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(palette));
	symbols.insert(Gura_UserSymbol(BitsPerPixel));
	symbols.insert(Gura_UserSymbol(BytesPerPixel));
	symbols.insert(Gura_UserSymbol(Rmask));
	symbols.insert(Gura_UserSymbol(Gmask));
	symbols.insert(Gura_UserSymbol(Bmask));
	symbols.insert(Gura_UserSymbol(Amask));
	return true;
}

Value Object_PixelFormat::DoGetProp(Environment &env, const Symbol *pSymbol,
									const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(palette))) {
		if (_pPixelFormat->palette == nullptr) return Value::Nil;
		return Value(new Object_Palette(_pPixelFormat->palette));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(BitsPerPixel))) {
		return Value(_pPixelFormat->BitsPerPixel);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(BytesPerPixel))) {
		return Value(_pPixelFormat->BytesPerPixel);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Rmask))) {
		return Value(_pPixelFormat->Rmask);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Gmask))) {
		return Value(_pPixelFormat->Gmask);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Bmask))) {
		return Value(_pPixelFormat->Bmask);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(Amask))) {
		return Value(_pPixelFormat->Amask);
	}
	evaluatedFlag = false;
	return Value::Nil;
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
	return Value::Nil;
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
	return Value::Nil;
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
	return Value::Nil;
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
	return Value::Nil;
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
	return Value::Nil;
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
	return Value::Nil;
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
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Gura interfaces for PixelFormat
//-----------------------------------------------------------------------------
// implementation of class PixelFormat
Gura_ImplementUserClass(PixelFormat)
{
	// Assignment of properties
#if 0
	Gura_AssignProperty(PixelFormat, Amask);
	Gura_AssignProperty(PixelFormat, BitsPerPixel);
	Gura_AssignProperty(PixelFormat, Bmask);
	Gura_AssignProperty(PixelFormat, BytesPerPixel);
	Gura_AssignProperty(PixelFormat, Gmask);
	Gura_AssignProperty(PixelFormat, Rmask);
	Gura_AssignProperty(PixelFormat, palette);
#endif
	// Assignment of value
	Gura_AssignValue(PixelFormat, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
