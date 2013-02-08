#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_image_surface implementation
//-----------------------------------------------------------------------------
bool Object_image_surface::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object_surface::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(image));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_image_surface::DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(image))) {
		return Value(Object_image::Reference(_pObjImage.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		return Value(_pObjImage->GetWidth());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(_pObjImage->GetHeight());
	}
	evaluatedFlag = false;
	return Object_surface::DoGetProp(sig, pSymbol, evaluatedFlag);
}

//-----------------------------------------------------------------------------
// Gura interfaces for image_surface
//-----------------------------------------------------------------------------
// cairo.image_surface.create(width:number, height:number, color?:color) {block?}
Gura_DeclareClassMethod(image_surface, create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(image_surface, create)
{
	Object_image *pObjImage = new Object_image(env, Image::FORMAT_RGBA);
	size_t width = args.GetSizeT(0);
	size_t height = args.GetSizeT(1);
	if (!pObjImage->AllocBuffer(sig, width, height, 0xff)) return Value::Null;
	if (args.IsColor(2)) {
		pObjImage->Fill(args.GetColorObj(2));
	}
	cairo_surface_t *surface = ::cairo_image_surface_create_for_data(
				pObjImage->GetBuffer(), CAIRO_FORMAT_ARGB32,
				static_cast<int>(width), static_cast<int>(height),
				static_cast<int>(pObjImage->GetBytesPerLine()));
	Object_image_surface *pObjSurface = new Object_image_surface(surface, pObjImage);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

//#cairo_surface_t *cairo_image_surface_create_from_png(const char *filename);
//#cairo_surface_t *cairo_image_surface_create_from_png_stream(cairo_read_func_t read_func, void *closure);

//#unsigned char *cairo_image_surface_get_data(cairo_surface_t *surface);
//#cairo_format_t cairo_image_surface_get_format(cairo_surface_t *surface);
//#int cairo_image_surface_get_width(cairo_surface_t *surface);
//#int cairo_image_surface_get_height(cairo_surface_t *surface);
//#int cairo_image_surface_get_stride(cairo_surface_t *surface);

Gura_ImplementUserClass(image_surface)
{
	Gura_AssignMethod(image_surface, create);
}

}}
