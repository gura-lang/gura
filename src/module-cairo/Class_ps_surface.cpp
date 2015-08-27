#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_ps_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for ps_surface
//-----------------------------------------------------------------------------
// cairo.ps_surface.create(stream:stream:w, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareClassMethod(ps_surface, create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_Once, FLAG_Write);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(ps_surface, create)
{
	Signal &sig = env.GetSignal();
	double width = args.GetDouble(1), height = args.GetDouble(2);
	Writer_Stream *pWriter = new Writer_Stream(sig, width, height,
									args.GetStream(0).Reference());
	cairo_surface_t *surface = ::cairo_ps_surface_create_for_stream(
					Writer_Stream::write_func, pWriter, width, height);
	Object_surface *pObjSurface = new Object_ps_surface(surface, pWriter);
	return ReturnValue(env, args, Value(pObjSurface));
}

// cairo.ps_surface#restrict_to_level(level:number):reduce
Gura_DeclareMethod(ps_surface, restrict_to_level)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "level", VTYPE_number);
}

Gura_ImplementMethod(ps_surface, restrict_to_level)
{
	Signal &sig = env.GetSignal();
	Object_ps_surface *pThis = Object_ps_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_ps_level_t level = static_cast<cairo_ps_level_t>(args.GetInt(0));
	::cairo_ps_surface_restrict_to_level(surface, level);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.ps_surface#set_eps(eps:boolean):reduce
Gura_DeclareMethod(ps_surface, set_eps)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "eps", VTYPE_boolean);
}

Gura_ImplementMethod(ps_surface, set_eps)
{
	Signal &sig = env.GetSignal();
	Object_ps_surface *pThis = Object_ps_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_bool_t eps = static_cast<cairo_bool_t>(args.GetBoolean(0));
	::cairo_ps_surface_set_eps(surface, eps);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.ps_surface#get_eps()
Gura_DeclareMethod(ps_surface, get_eps)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(ps_surface, get_eps)
{
	Signal &sig = env.GetSignal();
	Object_ps_surface *pThis = Object_ps_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	cairo_bool_t eps = ::cairo_ps_surface_get_eps(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return Value(eps);
}

// cairo.ps_surface#set_size(width_in_points:number, height_in_points:number)
Gura_DeclareMethod(ps_surface, set_size)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
}

Gura_ImplementMethod(ps_surface, set_size)
{
	Signal &sig = env.GetSignal();
	Object_ps_surface *pThis = Object_ps_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	double width_in_points = args.GetDouble(0);
	double height_in_points = args.GetDouble(1);
	::cairo_ps_surface_set_size(surface, width_in_points, height_in_points);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.ps_surface#dsc_begin_setup()
Gura_DeclareMethod(ps_surface, dsc_begin_setup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(ps_surface, dsc_begin_setup)
{
	Signal &sig = env.GetSignal();
	Object_ps_surface *pThis = Object_ps_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_ps_surface_dsc_begin_setup(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.ps_surface#dsc_begin_page_setup()
Gura_DeclareMethod(ps_surface, dsc_begin_page_setup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(ps_surface, dsc_begin_page_setup)
{
	Signal &sig = env.GetSignal();
	Object_ps_surface *pThis = Object_ps_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	::cairo_ps_surface_dsc_begin_page_setup(surface);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

// cairo.ps_surface#dsc_comment(comment:string)
Gura_DeclareMethod(ps_surface, dsc_comment)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "comment", VTYPE_string);
}

Gura_ImplementMethod(ps_surface, dsc_comment)
{
	Signal &sig = env.GetSignal();
	Object_ps_surface *pThis = Object_ps_surface::GetObjectThis(args);
	cairo_surface_t *surface = pThis->GetEntity();
	const char *comment = args.GetString(0);
	::cairo_ps_surface_dsc_comment(surface, comment);
	if (Is_error(sig, surface)) return Value::Nil;
	return args.GetValueThis();
}

Gura_ImplementUserClass(ps_surface)
{
	Gura_AssignMethod(ps_surface, create);
	Gura_AssignMethod(ps_surface, restrict_to_level);
	Gura_AssignMethod(ps_surface, set_eps);
	Gura_AssignMethod(ps_surface, get_eps);
	Gura_AssignMethod(ps_surface, set_size);
	Gura_AssignMethod(ps_surface, dsc_begin_setup);
	Gura_AssignMethod(ps_surface, dsc_begin_page_setup);
	Gura_AssignMethod(ps_surface, dsc_comment);
}

Gura_EndModuleScope(cairo)
