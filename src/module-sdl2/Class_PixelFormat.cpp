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

bool Object_PixelFormat::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(palette));
	symbols.insert(Gura_UserSymbol(BitsPerPixel));
	symbols.insert(Gura_UserSymbol(BytesPerPixel));
	symbols.insert(Gura_UserSymbol(Rmask));
	symbols.insert(Gura_UserSymbol(Gmask));
	symbols.insert(Gura_UserSymbol(Bmask));
	symbols.insert(Gura_UserSymbol(Amask));
	return true;
}

Value Object_PixelFormat::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
									const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(palette))) {
		if (_pPixelFormat->palette == nullptr) return Value::Null;
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
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Gura interfaces for PixelFormat
//-----------------------------------------------------------------------------
// implementation of class PixelFormat
Gura_ImplementUserClass(PixelFormat)
{
	Gura_AssignValue(PixelFormat, Value(Reference()));
}

Gura_EndModuleScope(sdl2)
