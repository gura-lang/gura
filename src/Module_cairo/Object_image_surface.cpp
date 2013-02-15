#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_image_surface implementation
//-----------------------------------------------------------------------------
bool Object_image_surface::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object_surface::DoDirProp(sig, symbols)) return false;
	//symbols.insert(Gura_UserSymbol(image));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_image_surface::DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		return Value(::cairo_image_surface_get_width(_surface));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(::cairo_image_surface_get_height(_surface));
	}
	evaluatedFlag = false;
	return Object_surface::DoGetProp(sig, pSymbol, evaluatedFlag);
}

//-----------------------------------------------------------------------------
// Gura interfaces for image_surface
//-----------------------------------------------------------------------------
//#cairo_surface_t *cairo_image_surface_create(cairo_format_t format, int width, int height);

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
