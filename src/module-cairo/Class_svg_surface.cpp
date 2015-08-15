#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_svg_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for svg_surface
//-----------------------------------------------------------------------------
// cairo.svg_surface.create(stream:stream:w, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareClassMethod(svg_surface, create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(svg_surface, create)
{
	Signal &sig = env.GetSignal();
	double width = args.GetDouble(1);
	double height = args.GetDouble(2);
	Writer_Stream *pWriter = new Writer_Stream(sig, width, height,
									args.GetStream(0).Reference());
	cairo_surface_t *surface = ::cairo_svg_surface_create_for_stream(
					Writer_Stream::write_func, pWriter, width, height);
	Object_surface *pObjSurface = new Object_svg_surface(surface, pWriter);
	return ReturnValue(env, args, Value(pObjSurface));
}

// cairo.svg_surface#restrict_to_version(version:number):reduce
Gura_DeclareMethod(svg_surface, restrict_to_version)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "version", VTYPE_number);
}

Gura_ImplementMethod(svg_surface, restrict_to_version)
{
	Signal &sig = env.GetSignal();
	Object_surface *pThis = Object_surface::GetThisObj(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_svg_version_t version = static_cast<cairo_svg_version_t>(args.GetInt(0));
	::cairo_svg_surface_restrict_to_version(surface, version);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetThis();
}

Gura_ImplementUserClass(svg_surface)
{
	Gura_AssignMethod(svg_surface, create);
	Gura_AssignMethod(svg_surface, restrict_to_version);
}

Gura_EndModuleScope(cairo)
