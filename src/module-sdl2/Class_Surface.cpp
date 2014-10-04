#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Surface implementation
//-----------------------------------------------------------------------------
Object_Surface::~Object_Surface()
{
	//::SDL_DestroySurface(_pSurface);
}

Object *Object_Surface::Clone() const
{
	return NULL;
}

String Object_Surface::ToString(bool exprFlag)
{
	return String("<sdl2.Surface>");
}

bool Object_Surface::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(flags));
	symbols.insert(Gura_UserSymbol(format));
	symbols.insert(Gura_UserSymbol(w));
	symbols.insert(Gura_UserSymbol(h));
	symbols.insert(Gura_UserSymbol(pitch));
	symbols.insert(Gura_UserSymbol(pixels));
	symbols.insert(Gura_UserSymbol(clip_rect));
	symbols.insert(Gura_UserSymbol(refcount));
	return true;
}

Value Object_Surface::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(flags))) {
		return Value(_pSurface->flags);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(format))) {
		return Value(new Object_PixelFormat(_pSurface->format));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(w))) {
		return Value(_pSurface->w);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(h))) {
		return Value(_pSurface->h);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(pitch))) {
		return Value(_pSurface->pitch);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(pixels))) {
		return Value::Null;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(clip_rect))) {
		return Value(new Object_Rect(_pSurface->clip_rect));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(refcount))) {
		return Value(_pSurface->refcount);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Object_Surface *Object_Surface::CreateSurfaceFromImage(Signal sig, Image *pImage)
{
	void *pixels = pImage->GetBuffer();
	int width = static_cast<int>(pImage->GetWidth());
	int height = static_cast<int>(pImage->GetHeight());
	int depth = static_cast<int>(pImage->GetBitsPerPixel());
	int pitch = static_cast<int>(pImage->GetBytesPerLine());
	Uint32 Rmask, Gmask, Bmask, Amask;
	Image::Format fmt = pImage->GetFormat();
	if (fmt == Image::FORMAT_RGB) {
		Rmask = 0x00ff0000;
		Gmask = 0x0000ff00;
		Bmask = 0x000000ff;
		Amask = 0x00000000;
	} else if (fmt == Image::FORMAT_RGBA) {
		Rmask = 0x00ff0000;
		Gmask = 0x0000ff00;
		Bmask = 0x000000ff;
		Amask = 0xff000000;
	} else {
		sig.SetError(ERR_ValueError, "unsupported image type");
		return NULL;
	}
	SDL_Surface *pSurface = ::SDL_CreateRGBSurfaceFrom(
				pixels, width, height, depth, pitch, Rmask, Gmask, Bmask, Amask);
	Object_Surface *pObj = new Object_Surface(pSurface, Image::Reference(pImage));
	return pObj;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Surface
//-----------------------------------------------------------------------------
// implementation of class Surface
Gura_ImplementUserClass(Surface)
{
}

Gura_EndModuleScope(sdl2)
