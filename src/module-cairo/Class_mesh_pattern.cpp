#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_mesh_pattern implementation
//-----------------------------------------------------------------------------
String Object_mesh_pattern::ToString(bool exprFlag)
{
	return String("<cairo.mesh_pattern>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for mesh_pattern
//-----------------------------------------------------------------------------
// cairo.mesh_pattern.create() {block?}
Gura_DeclareClassMethod(mesh_pattern, create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementClassMethod(mesh_pattern, create)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	cairo_pattern_t *pattern = ::cairo_pattern_create_mesh();
	if (Is_error(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Nil;
	}
	return ReturnValue(env, args, Value(new Object_mesh_pattern(pattern)));
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

// cairo.mesh_pattern#begin_patch():reduce
Gura_DeclareMethod(mesh_pattern, begin_patch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(mesh_pattern, begin_patch)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	::cairo_mesh_pattern_begin_patch(pattern);
	if (Is_error(sig, pattern)) return Value::Nil;
	return args.GetThis();
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

// cairo.mesh_pattern#end_patch():reduce
Gura_DeclareMethod(mesh_pattern, end_patch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(mesh_pattern, end_patch)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	::cairo_mesh_pattern_end_patch(pattern);
	if (Is_error(sig, pattern)) return Value::Nil;
	return args.GetThis();
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

// cairo.mesh_pattern#move_to(x:number, y:number):reduce
Gura_DeclareMethod(mesh_pattern, move_to)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(mesh_pattern, move_to)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double x = args.GetDouble(0);
	double y = args.GetDouble(1);
	::cairo_mesh_pattern_move_to(pattern, x, y);
	if (Is_error(sig, pattern)) return Value::Nil;
	return args.GetThis();
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

// cairo.mesh_pattern#line_to(x:number, y:number):reduce
Gura_DeclareMethod(mesh_pattern, line_to)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(mesh_pattern, line_to)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double x = args.GetDouble(0);
	double y = args.GetDouble(1);
	::cairo_mesh_pattern_line_to(pattern, x, y);
	if (Is_error(sig, pattern)) return Value::Nil;
	return args.GetThis();
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

// cairo.mesh_pattern#curve_to(x1:number, y1:number, x2:number, y2:number, x3:number, y3:number):reduce
Gura_DeclareMethod(mesh_pattern, curve_to)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x1", VTYPE_number);
	DeclareArg(env, "y1", VTYPE_number);
	DeclareArg(env, "x2", VTYPE_number);
	DeclareArg(env, "y2", VTYPE_number);
	DeclareArg(env, "x3", VTYPE_number);
	DeclareArg(env, "y3", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(mesh_pattern, curve_to)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double x1 = args.GetDouble(0);
	double y1 = args.GetDouble(1);
	double x2 = args.GetDouble(2);
	double y2 = args.GetDouble(3);
	double x3 = args.GetDouble(4);
	double y3 = args.GetDouble(5);
	::cairo_mesh_pattern_curve_to(pattern, x1, y1, x2, y2, x3, y3);
	if (Is_error(sig, pattern)) return Value::Nil;
	return args.GetThis();
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

// cairo.mesh_pattern#set_control_point(point_num:number, x:number, y:number):reduce
Gura_DeclareMethod(mesh_pattern, set_control_point)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "point_num", VTYPE_number);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(mesh_pattern, set_control_point)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	unsigned int point_num = args.GetUInt(0);
	double x = args.GetDouble(1);
	double y = args.GetDouble(2);
	::cairo_mesh_pattern_set_control_point(pattern, point_num, x, y);
	if (Is_error(sig, pattern)) return Value::Nil;
	return args.GetThis();
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

// cairo.mesh_pattern#set_corner_color_rgb(corner_num:number,
//                         red:number, green:number, blue:number):reduce
Gura_DeclareMethod(mesh_pattern, set_corner_color_rgb)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "corner_num", VTYPE_number);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(mesh_pattern, set_corner_color_rgb)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	unsigned int corner_num = args.GetUInt(0);
	double red = args.GetDouble(1);
	double green = args.GetDouble(2);
	double blue = args.GetDouble(3);
	::cairo_mesh_pattern_set_corner_color_rgb(pattern, corner_num, red, green, blue);
	if (Is_error(sig, pattern)) return Value::Nil;
	return args.GetThis();
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

// cairo.mesh_pattern#set_corner_color_rgba(corner_num:number,
//                         red:number, green:number, blue:number, alpha:number):reduce
Gura_DeclareMethod(mesh_pattern, set_corner_color_rgba)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "corner_num", VTYPE_number);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(mesh_pattern, set_corner_color_rgba)
{
	Signal &sig = env.GetSignal();
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	unsigned int corner_num = args.GetUInt(0);
	double red = args.GetDouble(1);
	double green = args.GetDouble(2);
	double blue = args.GetDouble(3);
	double alpha = args.GetDouble(4);
	::cairo_mesh_pattern_set_corner_color_rgba(pattern, corner_num, red, green, blue, alpha);
	if (Is_error(sig, pattern)) return Value::Nil;
	return args.GetThis();
#else
	sig.SetError(ERR_NotImplementedError, "only supported with cairo v1.12 or later");
	return Value::Nil;
#endif
}

//#cairo_status_t cairo_mesh_pattern_get_patch_count(cairo_pattern_t *pattern, unsigned int *count);
#if 0
// cairo.mesh_pattern#():reduce
Gura_DeclareMethod(mesh_pattern, )
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementMethod(mesh_pattern, )
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	::cairo_mesh_pattern_(pattern);
	if (Is_error(sig, pattern)) return Value::Nil;
	return args.GetThis();
}
#endif

//#cairo_path_t *cairo_mesh_pattern_get_path(cairo_pattern_t *pattern, unsigned int patch_num);

//#cairo_status_t cairo_mesh_pattern_get_control_point(cairo_pattern_t *pattern, unsigned int patch_num, unsigned int point_num, double *x, double *y);

//#cairo_status_t cairo_mesh_pattern_get_corner_color_rgba(cairo_pattern_t *pattern, unsigned int patch_num, unsigned int corner_num, double *red, double *green, double *blue, double *alpha);

// implementation of class mesh_pattern
Gura_ImplementUserClass(mesh_pattern)
{
	Gura_AssignMethod(mesh_pattern, create);
	Gura_AssignMethod(mesh_pattern, begin_patch);
	Gura_AssignMethod(mesh_pattern, end_patch);
	Gura_AssignMethod(mesh_pattern, move_to);
	Gura_AssignMethod(mesh_pattern, line_to);
	Gura_AssignMethod(mesh_pattern, curve_to);
	Gura_AssignMethod(mesh_pattern, set_control_point);
	Gura_AssignMethod(mesh_pattern, set_corner_color_rgb);
	Gura_AssignMethod(mesh_pattern, set_corner_color_rgba);
}

Gura_EndModuleScope(cairo)
