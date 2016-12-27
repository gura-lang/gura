#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_image_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// cairo.image_surface#height
Gura_DeclareProperty_R(image_surface, height)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(image_surface, height)
{
	const cairo_surface_t &surface =
		Object_image_surface::GetObject(valueThis)->GetEntity();
	return Value(::cairo_image_surface_get_height(surface));
}

// cairo.image_surface#width
Gura_DeclareProperty_R(image_surface, width)
{
	SetPropAttr(VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(image_surface, width)
{
	const cairo_surface_t &surface =
		Object_image_surface::GetObject(valueThis)->GetEntity();
	return Value(::cairo_image_surface_get_width(surface));
}

//-----------------------------------------------------------------------------
// Gura interfaces for image_surface
//-----------------------------------------------------------------------------
// cairo.image_surface.create(image:image) {block?}
Gura_DeclareClassMethod(image_surface, create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "image", VTYPE_image);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(image_surface, create)
{
	Signal &sig = env.GetSignal();
	Image *pImage = Image::Reference(Object_image::GetObject(arg, 0)->GetImage());
	cairo_surface_t *surface = CreateSurfaceFromImage(sig, pImage);
	if (sig.IsSignalled()) {
		Image::Delete(pImage);
		return Value::Nil;
	}
	Object_image_surface *pObjSurface = new Object_image_surface(surface, pImage);
	return ReturnValue(env, arg, Value(pObjSurface));
}

// cairo.image_surface.create_from_png(stream:stream:r) {block?}
Gura_DeclareClassMethod(image_surface, create_from_png)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(image_surface, create_from_png)
{
	Signal &sig = env.GetSignal();
	std::unique_ptr<Reader_Stream> pReader(new Reader_Stream(sig,
										arg.GetStream(0).Reference()));
	cairo_surface_t *surface = ::cairo_image_surface_create_from_png_stream(
										Reader_Stream::read_func, pReader.get());
	Object_image_surface *pObjSurface = new Object_image_surface(surface, nullptr);
	return ReturnValue(env, arg, Value(pObjSurface));
}

//#unsigned char *cairo_image_surface_get_data(cairo_surface_t *surface);

// cairo.image_surface#get_format()
Gura_DeclareMethod(image_surface, get_format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image_surface, get_format)
{
	Object_surface *pThis = Object_surface::GetObjectThis(arg);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_format_t rtn = ::cairo_image_surface_get_format(surface);
	return Value(rtn);
}

// cairo.image_surface#get_width()
Gura_DeclareMethod(image_surface, get_width)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image_surface, get_width)
{
	Object_surface *pThis = Object_surface::GetObjectThis(arg);
	cairo_surface_t *surface = pThis->GetEntity();
	int rtn = ::cairo_image_surface_get_width(surface);
	return Value(rtn);
}

// cairo.image_surface#get_height()
Gura_DeclareMethod(image_surface, get_height)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image_surface, get_height)
{
	Object_surface *pThis = Object_surface::GetObjectThis(arg);
	cairo_surface_t *surface = pThis->GetEntity();
	int rtn = ::cairo_image_surface_get_height(surface);
	return Value(rtn);
}

// cairo.image_surface#get_stride()
Gura_DeclareMethod(image_surface, get_stride)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(image_surface, get_stride)
{
	Object_surface *pThis = Object_surface::GetObjectThis(arg);
	cairo_surface_t *surface = pThis->GetEntity();
	int rtn = ::cairo_image_surface_get_stride(surface);
	return Value(rtn);
}

Gura_ImplementUserClass(image_surface)
{
	// Assignment of properties
	Gura_AssignProperty(image_surface, height);
	Gura_AssignProperty(image_surface, width);
	Gura_AssignMethod(image_surface, create);
	Gura_AssignMethod(image_surface, create_from_png);
	Gura_AssignMethod(image_surface, get_format);
	Gura_AssignMethod(image_surface, get_width);
	Gura_AssignMethod(image_surface, get_height);
	Gura_AssignMethod(image_surface, get_stride);
}

Gura_EndModuleScope(cairo)
