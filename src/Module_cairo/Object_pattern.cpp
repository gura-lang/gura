#include "stdafx.h"

Gura_BeginModule(cairo)

//-----------------------------------------------------------------------------
// Object_pattern implementation
//-----------------------------------------------------------------------------
Object_pattern::~Object_pattern()
{
	::cairo_pattern_destroy(_pattern);
}

Object *Object_pattern::Clone() const
{
	return NULL;
}

String Object_pattern::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.pattern>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for pattern
//-----------------------------------------------------------------------------
// cairo.pattern.create_rgb(red:number, green:number, blue:number) {block?}
Gura_DeclareClassMethod(pattern, create_rgb)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(pattern, create_rgb)
{
	cairo_pattern_t *pattern = ::cairo_pattern_create_rgb(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2));
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern.create_rgba(red:number, green:number, blue:number, alpha:number) {block?}
Gura_DeclareClassMethod(pattern, create_rgba)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(pattern, create_rgba)
{
	cairo_pattern_t *pattern = ::cairo_pattern_create_rgba(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2), args.GetDouble(3));
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern.create_color(color:color, alpha?:number) {block?}
Gura_DeclareClassMethod(pattern, create_color)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "color", VTYPE_color);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(pattern, create_color)
{
	const Color &color = Object_color::GetObject(args, 0)->GetColor();
	double red = static_cast<double>(color.GetRed()) / 255;
	double green = static_cast<double>(color.GetGreen()) / 255;
	double blue = static_cast<double>(color.GetBlue()) / 255;
	cairo_pattern_t *pattern;
	if (args.IsNumber(1)) {
		double alpha = args.GetDouble(1);
		pattern = ::cairo_pattern_create_rgba(red, green, blue, alpha);
	} else {
		pattern = ::cairo_pattern_create_rgb(red, green, blue);
	}
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern.create_for_surface(surface:cairo.surface) {block?}
Gura_DeclareClassMethod(pattern, create_for_surface)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "surface", VTYPE_surface);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(pattern, create_for_surface)
{
	cairo_surface_t *surface = Object_surface::GetObject(args, 0)->GetEntity();
	cairo_pattern_t *pattern = ::cairo_pattern_create_for_surface(surface);
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern.create_linear(x0:number, y0:number, x1:number, y1:number) {block?}
Gura_DeclareClassMethod(pattern, create_linear)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x0", VTYPE_number);
	DeclareArg(env, "y0", VTYPE_number);
	DeclareArg(env, "x1", VTYPE_number);
	DeclareArg(env, "y1", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(pattern, create_linear)
{
	cairo_pattern_t *pattern = ::cairo_pattern_create_linear(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2), args.GetDouble(3));
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern.create_radial(cx0:number, cy0:number, radius0:number, cx1:number, cy1:number, radius1:number) {block?}
Gura_DeclareClassMethod(pattern, create_radial)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "cx0", VTYPE_number);
	DeclareArg(env, "cy0", VTYPE_number);
	DeclareArg(env, "radius0", VTYPE_number);
	DeclareArg(env, "cx1", VTYPE_number);
	DeclareArg(env, "cy1", VTYPE_number);
	DeclareArg(env, "radius1", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(pattern, create_radial)
{
	cairo_pattern_t *pattern = ::cairo_pattern_create_radial(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2),
			args.GetDouble(3), args.GetDouble(4), args.GetDouble(5));
	if (IsError(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern#add_color_stop_rgb(offset:number, red:number, green:number, blue:number):reduce
Gura_DeclareMethod(pattern, add_color_stop_rgb)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
}

Gura_ImplementMethod(pattern, add_color_stop_rgb)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	::cairo_pattern_add_color_stop_rgb(pattern, args.GetDouble(0),
		args.GetDouble(1), args.GetDouble(2), args.GetDouble(3));
	if (IsError(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#add_color_stop_rgba(offset:number, red:number, green:number, blue:number, alpha:number):reduce
Gura_DeclareMethod(pattern, add_color_stop_rgba)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
}

Gura_ImplementMethod(pattern, add_color_stop_rgba)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	::cairo_pattern_add_color_stop_rgba(pattern, args.GetDouble(0),
		args.GetDouble(1), args.GetDouble(2), args.GetDouble(3), args.GetDouble(4));
	if (IsError(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_color_stop_count()
Gura_DeclareMethod(pattern, get_color_stop_count)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_color_stop_count)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	int count;
	cairo_status_t status = ::cairo_pattern_get_color_stop_count(pattern, &count);
	if (IsError(sig, status)) return Value::Null;
	return Value(count);
}

// cairo.pattern#get_color_stop_rgba(index:number)
Gura_DeclareMethod(pattern, get_color_stop_rgba)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "index", VTYPE_number);
}

Gura_ImplementMethod(pattern, get_color_stop_rgba)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double offset, red, green, blue, alpha;
	cairo_status_t status = ::cairo_pattern_get_color_stop_rgba(pattern, args.GetInt(0),
										&offset, &red, &green, &blue, &alpha);
	if (IsError(sig, status)) return Value::Null;
	return CreateValueList(env, offset, red, green, blue, alpha);
}

// cairo.pattern#get_rgba()
Gura_DeclareMethod(pattern, get_rgba)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_rgba)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double red, green, blue, alpha;
	cairo_status_t status = ::cairo_pattern_get_rgba(pattern,
										&red, &green, &blue, &alpha);
	if (IsError(sig, status)) return Value::Null;
	return CreateValueList(env, red, green, blue, alpha);
}

// cairo.pattern#get_surface()
Gura_DeclareMethod(pattern, get_surface)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_surface)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_surface_t *surface = NULL;
	cairo_status_t status = ::cairo_pattern_get_surface(pattern, &surface);
	if (IsError(sig, status)) return Value::Null;
	cairo_surface_t *surface_ref = ::cairo_surface_reference(surface);
	cairo_surface_type_t surface_type = ::cairo_surface_get_type(surface);
	Object_surface *pObjSurface = NULL;
	if (surface_type == CAIRO_SURFACE_TYPE_IMAGE) {
		pObjSurface = new Object_image_surface(surface_ref, NULL);
	} else if (surface_type == CAIRO_SURFACE_TYPE_PDF) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_PS) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_XLIB) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_XCB) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_GLITZ) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_QUARTZ) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_WIN32) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_BEOS) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_DIRECTFB) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_SVG) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_OS2) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_WIN32_PRINTING) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_QUARTZ_IMAGE) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_SCRIPT) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_QT) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_RECORDING) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_VG) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_GL) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_DRM) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_TEE) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_XML) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_SKIA) {
		pObjSurface = new Object_surface(surface_ref);
	} else if (surface_type == CAIRO_SURFACE_TYPE_SUBSURFACE) {
		pObjSurface = new Object_surface(surface_ref);
	} else {
		pObjSurface = new Object_surface(surface_ref);
	}
	return Value(pObjSurface);
}

// cairo.pattern#get_linear_points()
Gura_DeclareMethod(pattern, get_linear_points)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_linear_points)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double x0, y0, x1, y1;
	cairo_status_t status =
			::cairo_pattern_get_linear_points(pattern, &x0, &y0, &x1, &y1);
	if (IsError(sig, status)) return Value::Null;
	return CreateValueList(env, x0, y0, x1, y1);
}

// cairo.pattern#get_radial_circles()
Gura_DeclareMethod(pattern, get_radial_circles)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_radial_circles)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double x0, y0, r0, x1, y1, r1;
	cairo_status_t status =
		::cairo_pattern_get_radial_circles(pattern, &x0, &y0, &r0, &x1, &y1, &r1);
	if (IsError(sig, status)) return Value::Null;
	return CreateValueList(env, x0, y0, r0, x1, y1, r1);
}

//#cairo_pattern_t *cairo_pattern_reference(cairo_pattern_t *pattern);
//#void cairo_pattern_destroy(cairo_pattern_t *pattern);

// cairo.pattern#status()
Gura_DeclareMethod(pattern, status)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, status)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_status_t rtn = ::cairo_pattern_status(pattern);
	return Value(rtn);
}

// cairo.pattern#set_extend(extend:number):reduce
Gura_DeclareMethod(pattern, set_extend)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "extend", VTYPE_number);
}

Gura_ImplementMethod(pattern, set_extend)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_extend_t extend = static_cast<cairo_extend_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_pattern_set_extend(pattern, extend);
	if (IsError(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_extend()
Gura_DeclareMethod(pattern, get_extend)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_extend)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_extend_t extend = ::cairo_pattern_get_extend(pattern);
	if (IsError(sig, pattern)) return Value::Null;
	return Value(extend);
}

// cairo.pattern#set_filter(filter:number):reduce
Gura_DeclareMethod(pattern, set_filter)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "filter", VTYPE_number);
}

Gura_ImplementMethod(pattern, set_filter)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_filter_t filter = static_cast<cairo_filter_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_pattern_set_filter(pattern, filter);
	if (IsError(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_filter()
Gura_DeclareMethod(pattern, get_filter)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_filter)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_filter_t filter = ::cairo_pattern_get_filter(pattern);
	if (IsError(sig, pattern)) return Value::Null;
	return Value(pattern);
}

// cairo.pattern#set_matrix(matrix:matrix):reduce
Gura_DeclareMethod(pattern, set_matrix)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_matrix);
}

Gura_ImplementMethod(pattern, set_matrix)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	Object_matrix *pObjMatrix = args.GetMatrixObj(0);
	cairo_matrix_t matrix;
	if (!MatrixToCairo(sig, matrix, pObjMatrix)) return Value::Null;
	::cairo_pattern_set_matrix(pattern, &matrix);
	if (IsError(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_matrix()
Gura_DeclareMethod(pattern, get_matrix)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_matrix)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_matrix_t matrix;
	::cairo_pattern_get_matrix(pattern, &matrix);
	if (IsError(sig, pattern)) return Value::Null;
	Object_matrix *pObjMatrix = CairoToMatrix(env, matrix);
	return Value(pObjMatrix);
}

// cairo.pattern#get_type()
Gura_DeclareMethod(pattern, get_type)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(pattern, get_type)
{
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_pattern_type_t rtn = ::cairo_pattern_get_type(pattern);
	if (IsError(sig, pattern)) return Value::Null;
	return Value(rtn);
}

//#unsigned int cairo_pattern_get_reference_count(cairo_pattern_t *pattern);
//#cairo_status_t cairo_pattern_set_user_data(cairo_pattern_t *pattern, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_pattern_get_user_data(cairo_pattern_t *pattern, const cairo_user_data_key_t *key);

// implementation of class pattern
Gura_ImplementUserClass(pattern)
{
	Gura_AssignMethod(pattern, create_rgb);
	Gura_AssignMethod(pattern, create_rgba);
	Gura_AssignMethod(pattern, create_color);
	Gura_AssignMethod(pattern, create_for_surface);
	Gura_AssignMethod(pattern, create_linear);
	Gura_AssignMethod(pattern, create_radial);
	Gura_AssignMethod(pattern, add_color_stop_rgb);
	Gura_AssignMethod(pattern, add_color_stop_rgba);
	Gura_AssignMethod(pattern, get_color_stop_count);
	Gura_AssignMethod(pattern, get_color_stop_rgba);
	Gura_AssignMethod(pattern, get_rgba);
	Gura_AssignMethod(pattern, get_surface);
	Gura_AssignMethod(pattern, get_linear_points);
	Gura_AssignMethod(pattern, get_radial_circles);
	Gura_AssignMethod(pattern, status);
	Gura_AssignMethod(pattern, set_extend);
	Gura_AssignMethod(pattern, get_extend);
	Gura_AssignMethod(pattern, set_filter);
	Gura_AssignMethod(pattern, get_filter);
	Gura_AssignMethod(pattern, set_matrix);
	Gura_AssignMethod(pattern, get_matrix);
	Gura_AssignMethod(pattern, get_type);
}

}}
