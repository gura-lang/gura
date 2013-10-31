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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(pdf_surface, create)
{
	double width = args.GetDouble(1);
	double height = args.GetDouble(2);
	Writer_Stream *pWriter = new Writer_Stream(sig, width, height,
									args.GetStream(0).Reference());
	cairo_surface_t *surface = ::cairo_pdf_surface_create_for_stream(
					Writer_Stream::write_func, pWriter, width, height);
	Object_surface *pObjSurface = new Object_pdf_surface(surface, pWriter);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

// cairo.pdf_surface#restrict_to_version(version:number):reduce
Gura_DeclareMethod(pdf_surface, restrict_to_version)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "version", VTYPE_number);
}

Gura_ImplementMethod(pdf_surface, restrict_to_version)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_pdf_version_t version = static_cast<cairo_pdf_version_t>(args.GetInt(0));
	::cairo_pdf_surface_restrict_to_version(surface, version);
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

// cairo.pdf_surface#set_size(width_in_points:number, height_in_points:number)
Gura_DeclareMethod(pdf_surface, set_size)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
}

Gura_ImplementMethod(pdf_surface, set_size)
{
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_pdf_surface_set_size(surface, args.GetDouble(0), args.GetDouble(1));
	if (IsError(sig, surface)) return Value::Null;
	return args.GetThis();
}

Gura_ImplementUserClass(pdf_surface)
{
	Gura_AssignMethod(pdf_surface, create);
	Gura_AssignMethod(pdf_surface, restrict_to_version);
	Gura_AssignMethod(pdf_surface, set_size);
}

Gura_EndModuleScope(cairo)
