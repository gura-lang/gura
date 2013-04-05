#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_image_surface implementation
//-----------------------------------------------------------------------------
bool Object_image_surface::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object_surface::DoDirProp(env, sig, symbols)) return false;
	//symbols.insert(Gura_UserSymbol(image));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_image_surface::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		return Value(::cairo_image_surface_get_width(_surface));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(::cairo_image_surface_get_height(_surface));
	}
	evaluatedFlag = false;
	return Object_surface::DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

//-----------------------------------------------------------------------------
// Gura interfaces for image_surface
//-----------------------------------------------------------------------------
// cairo.image_surface.create(image:image) {block?}
Gura_DeclareClassMethod(image_surface, create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "image", VTYPE_image);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(image_surface, create)
{
	Image *pImage = Image::Reference(Object_image::GetObject(args, 0)->GetImage());
	cairo_surface_t *surface = CreateSurfaceFromImage(sig, pImage);
	if (sig.IsSignalled()) {
		Image::Delete(pImage);
		return Value::Null;
	}
	Object_image_surface *pObjSurface = new Object_image_surface(surface, pImage);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

// cairo.image_surface.create_from_png(stream:stream:r) {block?}
Gura_DeclareClassMethod(image_surface, create_from_png)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(image_surface, create_from_png)
{
	std::auto_ptr<Reader_Stream> pReader(new Reader_Stream(sig,
							Stream::Reference(&args.GetStream(0))));
	cairo_surface_t *surface = ::cairo_image_surface_create_from_png_stream(
										Reader_Stream::read_func, pReader.get());
	Object_image_surface *pObjSurface = new Object_image_surface(surface, NULL);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

//#unsigned char *cairo_image_surface_get_data(cairo_surface_t *surface);

// cairo.image_surface#get_format()
Gura_DeclareMethod(image_surface, get_format)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image_surface, get_format)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_format_t rtn = ::cairo_image_surface_get_format(surface);
	return Value(rtn);
}

// cairo.image_surface#get_width()
Gura_DeclareMethod(image_surface, get_width)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image_surface, get_width)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	int rtn = ::cairo_image_surface_get_width(surface);
	return Value(rtn);
}

// cairo.image_surface#get_height()
Gura_DeclareMethod(image_surface, get_height)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image_surface, get_height)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	int rtn = ::cairo_image_surface_get_height(surface);
	return Value(rtn);
}

// cairo.image_surface#get_stride()
Gura_DeclareMethod(image_surface, get_stride)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image_surface, get_stride)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	int rtn = ::cairo_image_surface_get_stride(surface);
	return Value(rtn);
}

Gura_ImplementUserClass(image_surface)
{
	Gura_AssignMethod(image_surface, create);
	Gura_AssignMethod(image_surface, create_from_png);
	Gura_AssignMethod(image_surface, get_format);
	Gura_AssignMethod(image_surface, get_width);
	Gura_AssignMethod(image_surface, get_height);
	Gura_AssignMethod(image_surface, get_stride);
}

}}
