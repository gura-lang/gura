#include "stdafx.h"

Gura_BeginModuleScope(sdl2)

//-----------------------------------------------------------------------------
// Object_Surface implementation
//-----------------------------------------------------------------------------
Object_Surface::~Object_Surface()
{
	::SDL_FreeSurface(_pSurface);
}

Object *Object_Surface::Clone() const
{
	return nullptr;
}

String Object_Surface::ToString(bool exprFlag)
{
	return String("<sdl2.Surface>");
}

Object_Surface *Object_Surface::CreateSurfaceFromImage(Signal &sig, Image *pImage)
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
		return nullptr;
	}
	SDL_Surface *pSurface = ::SDL_CreateRGBSurfaceFrom(
				pixels, width, height, depth, pitch, Rmask, Gmask, Bmask, Amask);
	if (pSurface == nullptr) {
		SetError_SDL(sig);
		return nullptr;
	}
	Object_Surface *pObj = new Object_Surface(pSurface, Image::Reference(pImage));
	return pObj;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// sdl2.Surface#clip_rect
Gura_DeclareProperty_R(Surface, clip_rect)
{
	SetPropAttr(VTYPE_Rect);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Surface, clip_rect)
{
	const SDL_Surface *pSurface = Object_Surface::GetObject(valueThis)->GetEntity();
	return Value(new Object_Rect(pSurface->clip_rect));
}

// sdl2.Surface#flags
Gura_DeclareProperty_R(Surface, flags)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Surface, flags)
{
	const SDL_Surface *pSurface = Object_Surface::GetObject(valueThis)->GetEntity();
	return Value(pSurface->flags);
}

// sdl2.Surface#format
Gura_DeclareProperty_R(Surface, format)
{
	SetPropAttr(VTYPE_PixelFormat);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Surface, format)
{
	const SDL_Surface *pSurface = Object_Surface::GetObject(valueThis)->GetEntity();
	return Value(new Object_PixelFormat(pSurface->format));
}

// sdl2.Surface#h
Gura_DeclareProperty_R(Surface, h)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Surface, h)
{
	const SDL_Surface *pSurface = Object_Surface::GetObject(valueThis)->GetEntity();
	return Value(pSurface->h);
}

// sdl2.Surface#pitch
Gura_DeclareProperty_R(Surface, pitch)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Surface, pitch)
{
	const SDL_Surface *pSurface = Object_Surface::GetObject(valueThis)->GetEntity();
	return Value(pSurface->pitch);
}

// sdl2.Surface#pixels
Gura_DeclareProperty_R(Surface, pixels)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Surface, pixels)
{
	return Value::Nil;
}

// sdl2.Surface#refcount
Gura_DeclareProperty_R(Surface, refcount)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Surface, refcount)
{
	const SDL_Surface *pSurface = Object_Surface::GetObject(valueThis)->GetEntity();
	return Value(pSurface->refcount);
}

// sdl2.Surface#w
Gura_DeclareProperty_R(Surface, w)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(Surface, w)
{
	const SDL_Surface *pSurface = Object_Surface::GetObject(valueThis)->GetEntity();
	return Value(pSurface->w);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Surface
//-----------------------------------------------------------------------------
// implementation of class Surface
Gura_ImplementUserClassWithCast(Surface)
{
	// Assignment of properties
	Gura_AssignProperty(Surface, clip_rect);
	Gura_AssignProperty(Surface, flags);
	Gura_AssignProperty(Surface, format);
	Gura_AssignProperty(Surface, h);
	Gura_AssignProperty(Surface, pitch);
	Gura_AssignProperty(Surface, pixels);
	Gura_AssignProperty(Surface, refcount);
	Gura_AssignProperty(Surface, w);
	// Assignment of value
	Gura_AssignValue(Surface, Value(Reference()));
}

Gura_ImplementCastFrom(Surface)
{
	Signal &sig = GetSignal();
	if (value.Is_image()) {
		Image *pImage = Object_image::GetObject(value)->GetImage();
		Object_Surface *pObjSurface =
					Object_Surface::CreateSurfaceFromImage(sig, pImage);
		if (pObjSurface == nullptr) return false;
		value = Value(pObjSurface);
		return true;
	}
	return false;
}

Gura_ImplementCastTo(Surface)
{
	return false;
}

Gura_EndModuleScope(sdl2)
