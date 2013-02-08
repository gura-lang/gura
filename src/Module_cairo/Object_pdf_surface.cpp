#include "stdafx.h"

Gura_BeginModule(cairo)

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
									Stream::Reference(&args.GetStream(0)));
	cairo_surface_t *surface = ::cairo_pdf_surface_create_for_stream(
					Writer_Stream::write_func, pWriter, width, height);
	Object_surface *pObjSurface = new Object_pdf_surface(surface, pWriter);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

//#cairo_surface_t *cairo_pdf_surface_create(const char *filename, double width_in_points, double height_in_points);
//#cairo_surface_t *cairo_pdf_surface_create_for_stream (cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points);
//#void cairo_pdf_surface_restrict_to_version(cairo_surface_t *surface, cairo_pdf_version_t version);
//#void cairo_pdf_get_versions(cairo_pdf_version_t const **versions, int *num_versions);
//#const char *cairo_pdf_version_to_string(cairo_pdf_version_t version);
//#void cairo_pdf_surface_set_size(cairo_surface_t *surface, double width_in_points, double height_in_points);

//#cairo_status_t cairo_surface_write_to_png(cairo_surface_t *surface, const char *filename);
//#cairo_status_t cairo_surface_write_to_png_stream(cairo_surface_t *surface, cairo_write_func_t write_func, void *closure);

Gura_ImplementUserClass(pdf_surface)
{
	Gura_AssignMethod(pdf_surface, create);
}

}}
