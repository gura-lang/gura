#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_ps_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for ps_surface
//-----------------------------------------------------------------------------
// cairo.ps_surface.create(stream:stream:w, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareClassMethod(ps_surface, create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(ps_surface, create)
{
	double width = args.GetDouble(1), height = args.GetDouble(2);
	Writer_Stream *pWriter = new Writer_Stream(sig, width, height,
									Stream::Reference(&args.GetStream(0)));
	cairo_surface_t *surface = ::cairo_ps_surface_create_for_stream(
					Writer_Stream::write_func, pWriter, width, height);
	Object_surface *pObjSurface = new Object_ps_surface(surface, pWriter);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

//#void cairo_ps_surface_restrict_to_level(cairo_surface_t *surface, cairo_ps_level_t level);
//#void cairo_ps_surface_set_eps(cairo_surface_t *surface, cairo_bool_t eps);
//#cairo_bool_t cairo_ps_surface_get_eps(cairo_surface_t *surface);
//#void cairo_ps_surface_set_size(cairo_surface_t *surface, double width_in_points, double height_in_points);
//#void cairo_ps_surface_dsc_begin_setup(cairo_surface_t *surface);
//#void cairo_ps_surface_dsc_begin_page_setup(cairo_surface_t *surface);
//#void cairo_ps_surface_dsc_comment(cairo_surface_t *surface, const char *comment);

Gura_ImplementUserClass(ps_surface)
{
	Gura_AssignMethod(ps_surface, create);
}

}}
