#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_pdf_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for pdf_surface
//-----------------------------------------------------------------------------
// cairo.pdf_surface.create(stream:stream:w, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareClassMethod(pdf_surface, create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(pdf_surface, create)
{
	Signal &sig = env.GetSignal();
	double width = arg.GetDouble(1);
	double height = arg.GetDouble(2);
	Writer_Stream *pWriter = new Writer_Stream(sig, width, height,
									arg.GetStream(0).Reference());
	cairo_surface_t *surface = ::cairo_pdf_surface_create_for_stream(
					Writer_Stream::write_func, pWriter, width, height);
	Object_surface *pObjSurface = new Object_pdf_surface(surface, pWriter);
	return ReturnValue(env, arg, Value(pObjSurface));
}

// cairo.pdf_surface#restrict_to_version(version:number):reduce
Gura_DeclareMethod(pdf_surface, restrict_to_version)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "version", VTYPE_number);
}

Gura_ImplementMethod(pdf_surface, restrict_to_version)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(arg);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_pdf_version_t version = static_cast<cairo_pdf_version_t>(arg.GetInt(0));
	::cairo_pdf_surface_restrict_to_version(surface, version);
	if (Is_error(sig, surface)) return Value::Nil;
	return arg.GetValueThis();
}

// cairo.pdf_surface#set_size(width_in_points:number, height_in_points:number)
Gura_DeclareMethod(pdf_surface, set_size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
}

Gura_ImplementMethod(pdf_surface, set_size)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetObjectThis(arg);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_pdf_surface_set_size(surface, arg.GetDouble(0), arg.GetDouble(1));
	if (Is_error(sig, surface)) return Value::Nil;
	return arg.GetValueThis();
}

Gura_ImplementUserClass(pdf_surface)
{
	Gura_AssignMethod(pdf_surface, create);
	Gura_AssignMethod(pdf_surface, restrict_to_version);
	Gura_AssignMethod(pdf_surface, set_size);
}

Gura_EndModuleScope(cairo)
