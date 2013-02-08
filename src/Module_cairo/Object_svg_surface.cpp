#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_svg_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for svg_surface
//-----------------------------------------------------------------------------
// cairo.svg_surface.create(stream:stream:w, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareClassMethod(svg_surface, create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(svg_surface, create)
{
	double width = args.GetDouble(1);
	double height = args.GetDouble(2);
	Writer_Stream *pWriter = new Writer_Stream(sig, width, height,
									Stream::Reference(&args.GetStream(0)));
	cairo_surface_t *surface = ::cairo_svg_surface_create_for_stream(
					Writer_Stream::write_func, pWriter, width, height);
	Object_surface *pObjSurface = new Object_svg_surface(surface, pWriter);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

//#cairo_surface_t *cairo_svg_surface_create(const char *filename, double width_in_points, double height_in_points);
//#cairo_surface_t *cairo_svg_surface_create_for_stream (cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points);
//#void cairo_svg_surface_restrict_to_version(cairo_surface_t *surface, cairo_svg_version_t version);
//#void cairo_svg_get_versions(cairo_svg_version_t const **versions, int *num_versions);
//#const char *cairo_svg_version_to_string(cairo_svg_version_t version);

Gura_ImplementUserClass(svg_surface)
{
	Gura_AssignMethod(svg_surface, create);
}

}}
