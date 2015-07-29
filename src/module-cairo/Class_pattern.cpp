#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_pattern implementation
//-----------------------------------------------------------------------------
Object_pattern::~Object_pattern()
{
	::cairo_pattern_destroy(_pattern);
}

Object *Object_pattern::Clone() const
{
	return nullptr;
}

String Object_pattern::ToString(bool exprFlag)
{
	return String("<cairo.pattern>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for pattern
//-----------------------------------------------------------------------------
// cairo.pattern.create_rgb(red:number, green:number, blue:number) {block?}
Gura_DeclareClassMethod(pattern, create_rgb)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Creates a new cairo.pattern corresponding to an opaque color.\n"
	"The color components are floating point numbers in the range 0 to 1.\n"
	"If the values passed in are outside that range, they will be clamped.\n"
	);
}

Gura_ImplementClassMethod(pattern, create_rgb)
{
	Signal &sig = env.GetSignal();
	cairo_pattern_t *pattern = ::cairo_pattern_create_rgb(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2));
	if (Is_error(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern.create_rgba(red:number, green:number, blue:number, alpha:number) {block?}
Gura_DeclareClassMethod(pattern, create_rgba)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Creates a new cairo,pattern corresponding to a translucent color.\n"
	"The color components are floating point numbers in the range 0 to 1.\n"
	"If the values passed in are outside that range, they will be clamped.\n"
	);
}

Gura_ImplementClassMethod(pattern, create_rgba)
{
	Signal &sig = env.GetSignal();
	cairo_pattern_t *pattern = ::cairo_pattern_create_rgba(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2), args.GetDouble(3));
	if (Is_error(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern.create_color(color:color, alpha?:number) {block?}
Gura_DeclareClassMethod(pattern, create_color)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "color", VTYPE_color);
	DeclareArg(env, "alpha", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Creates a new cairo,pattern corresponding to a color instance of Gura and an alpha value.\n"
	);
}

Gura_ImplementClassMethod(pattern, create_color)
{
	Signal &sig = env.GetSignal();
	const Color &color = Object_color::GetObject(args, 0)->GetColor();
	double red = static_cast<double>(color.GetR()) / 255;
	double green = static_cast<double>(color.GetG()) / 255;
	double blue = static_cast<double>(color.GetB()) / 255;
	cairo_pattern_t *pattern;
	if (args.Is_number(1)) {
		double alpha = args.GetDouble(1);
		pattern = ::cairo_pattern_create_rgba(red, green, blue, alpha);
	} else {
		pattern = ::cairo_pattern_create_rgb(red, green, blue);
	}
	if (Is_error(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern.create_for_surface(surface:cairo.surface) {block?}
Gura_DeclareClassMethod(pattern, create_for_surface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "surface", VTYPE_surface);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Create a new cairo.pattern for the given surface.\n"
	);
}

Gura_ImplementClassMethod(pattern, create_for_surface)
{
	Signal &sig = env.GetSignal();
	cairo_surface_t *surface = Object_surface::GetObject(args, 0)->GetEntity();
	cairo_pattern_t *pattern = ::cairo_pattern_create_for_surface(surface);
	if (Is_error(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern.create_linear(x0:number, y0:number, x1:number, y1:number) {block?}
Gura_DeclareClassMethod(pattern, create_linear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "x0", VTYPE_number);
	DeclareArg(env, "y0", VTYPE_number);
	DeclareArg(env, "x1", VTYPE_number);
	DeclareArg(env, "y1", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Create a new linear gradient cairo.pattern along the line defined by (x0, y0) and (x1, y1).\n"
	"Before using the gradient pattern, a number of color stops should be defined using cairo.pattern#add_color_stop_rgb() or cairo.pattern#add_color_stop_rgba().\n"
	"\n"
	"Note: The coordinates here are in pattern space.\n"
	"For a new pattern, pattern space is identical to user space, but the relationship between the spaces can be changed with cairo.pattern#set_matrix().\n"
	);
}

Gura_ImplementClassMethod(pattern, create_linear)
{
	Signal &sig = env.GetSignal();
	cairo_pattern_t *pattern = ::cairo_pattern_create_linear(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2), args.GetDouble(3));
	if (Is_error(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern.create_radial(cx0:number, cy0:number, radius0:number, cx1:number, cy1:number, radius1:number) {block?}
Gura_DeclareClassMethod(pattern, create_radial)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "cx0", VTYPE_number);
	DeclareArg(env, "cy0", VTYPE_number);
	DeclareArg(env, "radius0", VTYPE_number);
	DeclareArg(env, "cx1", VTYPE_number);
	DeclareArg(env, "cy1", VTYPE_number);
	DeclareArg(env, "radius1", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Creates a new radial gradient cairo_pattern_t between the two circles defined by (cx0, cy0, radius0) and (cx1, cy1, radius1).\n"
	"Before using the gradient pattern, a number of color stops should be defined using cairo.pattern#add_color_stop_rgb() or cairo.pattern#add_color_stop_rgba().\n"
	"\n"
	"Note: The coordinates here are in pattern space.\n"
	"For a new pattern, pattern space is identical to user space, but the relationship between the spaces can be changed with cairo.pattern#set_matrix().\n"
	);
}

Gura_ImplementClassMethod(pattern, create_radial)
{
	Signal &sig = env.GetSignal();
	cairo_pattern_t *pattern = ::cairo_pattern_create_radial(
			args.GetDouble(0), args.GetDouble(1), args.GetDouble(2),
			args.GetDouble(3), args.GetDouble(4), args.GetDouble(5));
	if (Is_error(sig, pattern)) {
		::cairo_pattern_destroy(pattern);
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_pattern(pattern)));
}

// cairo.pattern#add_color_stop_rgb(offset:number, red:number, green:number, blue:number):reduce
Gura_DeclareMethod(pattern, add_color_stop_rgb)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Adds an opaque color stop to a gradient pattern.\n"
	"The offset specifies the location along the gradient's control vector.\n"
	"For example, a linear gradient's control vector is from (x0,y0) to (x1,y1)\n"
	"while a radial gradient's control vector is from any point on the start circle to the corresponding point on the end circle.\n"
	"\n"
	"The color is specified in the same way as in cairo.context#set_source_rgb().\n"
	"\n"
	"If two (or more) stops are specified with identical offset values, they will be sorted according to the order in which the stops are added,\n"
	"(stops added earlier will compare less than stops added later).\n"
	"This can be useful for reliably making sharp color transitions instead of the typical blend.\n"
	"\n"
	"Note: If the pattern is not a gradient pattern, (eg. a linear or radial pattern),\n"
	"then the pattern will be put into an error status with a status of cairo.STATUS_PATTERN_TYPE_MISMATCH.\n"
	);
}

Gura_ImplementMethod(pattern, add_color_stop_rgb)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	::cairo_pattern_add_color_stop_rgb(pattern, args.GetDouble(0),
		args.GetDouble(1), args.GetDouble(2), args.GetDouble(3));
	if (Is_error(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#add_color_stop_rgba(offset:number, red:number, green:number, blue:number, alpha:number):reduce
Gura_DeclareMethod(pattern, add_color_stop_rgba)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "offset", VTYPE_number);
	DeclareArg(env, "red", VTYPE_number);
	DeclareArg(env, "green", VTYPE_number);
	DeclareArg(env, "blue", VTYPE_number);
	DeclareArg(env, "alpha", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Adds a translucent color stop to a gradient pattern.\n"
	"The offset specifies the location along the gradient's control vector.\n"
	"For example, a linear gradient's control vector is from (x0,y0) to (x1,y1)\n"
	"while a radial gradient's control vector is from any point on the start circle to the corresponding point on the end circle.\n"
	"\n"
	"The color is specified in the same way as in cairo.context#set_source_rgba().\n"
	"\n"
	"If two (or more) stops are specified with identical offset values, they will be sorted according to the order in which the stops are added,\n"
	"(stops added earlier will compare less than stops added later).\n"
	"This can be useful for reliably making sharp color transitions instead of the typical blend.\n"
	"\n"
	"Note: If the pattern is not a gradient pattern, (eg. a linear or radial pattern),\n"
	"then the pattern will be put into an error status with a status of cairo.STATUS_PATTERN_TYPE_MISMATCH.\n"
	);
}

Gura_ImplementMethod(pattern, add_color_stop_rgba)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	::cairo_pattern_add_color_stop_rgba(pattern, args.GetDouble(0),
		args.GetDouble(1), args.GetDouble(2), args.GetDouble(3), args.GetDouble(4));
	if (Is_error(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_color_stop_count()
Gura_DeclareMethod(pattern, get_color_stop_count)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the number of color stops specified in the given gradient pattern.\n"
	);
}

Gura_ImplementMethod(pattern, get_color_stop_count)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	int count;
	cairo_status_t status = ::cairo_pattern_get_color_stop_count(pattern, &count);
	if (Is_error(sig, status)) return Value::Null;
	return Value(count);
}

// cairo.pattern#get_color_stop_rgba(index:number)
Gura_DeclareMethod(pattern, get_color_stop_rgba)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "index", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the color and offset information at the given index for a gradient pattern.\n"
	"Values of index are 0 to 1 less than the number returned by cairo.pattern#get_color_stop_count().\n"
	);
}

Gura_ImplementMethod(pattern, get_color_stop_rgba)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double offset, red, green, blue, alpha;
	cairo_status_t status = ::cairo_pattern_get_color_stop_rgba(pattern, args.GetInt(0),
										&offset, &red, &green, &blue, &alpha);
	if (Is_error(sig, status)) return Value::Null;
	return CreateValueList(env, offset, red, green, blue, alpha);
}

// cairo.pattern#get_rgba()
Gura_DeclareMethod(pattern, get_rgba)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the solid color for a solid color pattern.\n"
	);
}

Gura_ImplementMethod(pattern, get_rgba)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double red, green, blue, alpha;
	cairo_status_t status = ::cairo_pattern_get_rgba(pattern,
										&red, &green, &blue, &alpha);
	if (Is_error(sig, status)) return Value::Null;
	return CreateValueList(env, red, green, blue, alpha);
}

// cairo.pattern#get_surface()
Gura_DeclareMethod(pattern, get_surface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the surface of a surface pattern.\n"
	"The reference returned in surface is owned by the pattern;\n"
	"the caller should call cairo_surface_reference() if the surface is to be retained.\n"
	);
}

Gura_ImplementMethod(pattern, get_surface)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_surface_t *surface = nullptr;
	cairo_status_t status = ::cairo_pattern_get_surface(pattern, &surface);
	if (Is_error(sig, status)) return Value::Null;
	cairo_surface_t *surface_ref = ::cairo_surface_reference(surface);
	cairo_surface_type_t surface_type = ::cairo_surface_get_type(surface);
	Object_surface *pObjSurface = nullptr;
	if (surface_type == CAIRO_SURFACE_TYPE_IMAGE) {
		pObjSurface = new Object_image_surface(surface_ref, nullptr);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the gradient endpoints for a linear gradient.\n"
	);
}

Gura_ImplementMethod(pattern, get_linear_points)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double x0, y0, x1, y1;
	cairo_status_t status =
			::cairo_pattern_get_linear_points(pattern, &x0, &y0, &x1, &y1);
	if (Is_error(sig, status)) return Value::Null;
	return CreateValueList(env, x0, y0, x1, y1);
}

// cairo.pattern#get_radial_circles()
Gura_DeclareMethod(pattern, get_radial_circles)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the gradient endpoint circles for a radial gradient, each specified as a center coordinate and a radius.\n"
	);
}

Gura_ImplementMethod(pattern, get_radial_circles)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	double x0, y0, r0, x1, y1, r1;
	cairo_status_t status =
		::cairo_pattern_get_radial_circles(pattern, &x0, &y0, &r0, &x1, &y1, &r1);
	if (Is_error(sig, status)) return Value::Null;
	return CreateValueList(env, x0, y0, r0, x1, y1, r1);
}

//#cairo_pattern_t *cairo_pattern_reference(cairo_pattern_t *pattern);
//#void cairo_pattern_destroy(cairo_pattern_t *pattern);

// cairo.pattern#status()
Gura_DeclareMethod(pattern, status)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Checks whether an error has previously occurred for this pattern.\n"
	);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "extend", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the mode to be used for drawing outside the area of a pattern.\n"
	"See cairo_extend_t for details on the semantics of each extend strategy.\n"
	"\n"
	"The default extend mode is cairo.EXTEND_NONE for surface patterns and cairo.EXTEND_PAD for gradient patterns.\n"
	);
}

Gura_ImplementMethod(pattern, set_extend)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_extend_t extend = static_cast<cairo_extend_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_pattern_set_extend(pattern, extend);
	if (Is_error(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_extend()
Gura_DeclareMethod(pattern, get_extend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current extend mode for a pattern.\n"
	"See cairo_extend_t for details on the semantics of each extend strategy.\n"
	);
}

Gura_ImplementMethod(pattern, get_extend)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_extend_t extend = ::cairo_pattern_get_extend(pattern);
	if (Is_error(sig, pattern)) return Value::Null;
	return Value(extend);
}

// cairo.pattern#set_filter(filter:number):reduce
Gura_DeclareMethod(pattern, set_filter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "filter", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the filter to be used for resizing when using this pattern. See cairo_filter_t for details on each filter.\n"
	"\n"
	"* Note that you might want to control filtering even when you do not have an explicit cairo.pattern object,\n"
	"(for example when using cairo.context#set_source_surface()).\n"
	"In these cases, it is convenient to use cairo.context#get_source() to get access to the pattern that cairo creates implicitly. For example:\n"
	"\n"
	"  cr.set_source_surface(image, x, y)\n"
	"  cr.get_source().set_filter(cairo.FILTER_NEAREST)\n"
	);
}

Gura_ImplementMethod(pattern, set_filter)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_filter_t filter = static_cast<cairo_filter_t>(args.GetInt(0));
	if (sig.IsSignalled()) return Value::Null;
	::cairo_pattern_set_filter(pattern, filter);
	if (Is_error(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_filter()
Gura_DeclareMethod(pattern, get_filter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Gets the current filter for a pattern. See cairo_filter_t for details on each filter.\n"
	);
}

Gura_ImplementMethod(pattern, get_filter)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_filter_t filter = ::cairo_pattern_get_filter(pattern);
	if (Is_error(sig, pattern)) return Value::Null;
	return Value(pattern);
}

// cairo.pattern#set_matrix(matrix:matrix):reduce
Gura_DeclareMethod(pattern, set_matrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "matrix", VTYPE_matrix);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Sets the pattern's transformation matrix to matrix. This matrix is a transformation from user space to pattern space.\n"
	"\n"
	"When a pattern is first created it always has the identity matrix for its transformation matrix, which means that pattern space is initially identical to user space.\n"
	"\n"
	"Important: Please note that the direction of this transformation matrix is from user space to pattern space.\n"
	"This means that if you imagine the flow from a pattern to user space (and on to device space),\n"
	"then coordinates in that flow will be transformed by the inverse of the pattern matrix.\n"
	"\n"
	"For example, if you want to make a pattern appear twice as large as it does by default the correct code to use is:\n"
	"\n"
	"  cairo_matrix_init_scale (&matrix, 0.5, 0.5);\n"
	"  cairo_pattern_set_matrix (pattern, &matrix);\n"
	"\n"
	"Meanwhile, using values of 2.0 rather than 0.5 in the code above would cause the pattern to appear at half of its default size.\n"
	"\n"
	"Also, please note the discussion of the user-space locking semantics of cairo.context#set_source().\n"
	);
}

Gura_ImplementMethod(pattern, set_matrix)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	Object_matrix *pObjMatrix = Object_matrix::GetObject(args, 0);
	cairo_matrix_t matrix;
	if (!MatrixToCairo(sig, matrix, pObjMatrix->GetMatrix())) return Value::Null;
	::cairo_pattern_set_matrix(pattern, &matrix);
	if (Is_error(sig, pattern)) return Value::Null;
	return args.GetThis();
}

// cairo.pattern#get_matrix()
Gura_DeclareMethod(pattern, get_matrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"Stores the pattern's transformation matrix into matrix.\n"
	);
}

Gura_ImplementMethod(pattern, get_matrix)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_matrix_t matrix;
	::cairo_pattern_get_matrix(pattern, &matrix);
	if (Is_error(sig, pattern)) return Value::Null;
	AutoPtr<Matrix> pMat(CairoToMatrix(matrix));
	return Value(new Object_matrix(env, pMat.release()));
}

// cairo.pattern#get_type()
Gura_DeclareMethod(pattern, get_type)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This function returns the type a pattern. See cairo_pattern_type_t for available types.\n"
	);
}

Gura_ImplementMethod(pattern, get_type)
{
	Signal &sig = env.GetSignal();
	Object_pattern *pThis = Object_pattern::GetThisObj(args);
	cairo_pattern_t *pattern = pThis->GetEntity();
	cairo_pattern_type_t rtn = ::cairo_pattern_get_type(pattern);
	if (Is_error(sig, pattern)) return Value::Null;
	return Value(rtn);
}

//#unsigned int cairo_pattern_get_reference_count(cairo_pattern_t *pattern);
//#cairo_status_t cairo_pattern_set_user_data(cairo_pattern_t *pattern, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
//#void *cairo_pattern_get_user_data(cairo_pattern_t *pattern, const cairo_user_data_key_t *key);

// implementation of class pattern
Gura_ImplementUserClassWithCast(pattern)
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

Gura_ImplementCastFrom(pattern)
{
	Signal &sig = GetSignal();
	Value valueCast(value);
	env.LookupClass(VTYPE_surface)->CastFrom(env, valueCast, pDecl);
	if (valueCast.GetValueType() == VTYPE_surface) {
		cairo_surface_t *surface = Object_surface::GetObject(valueCast)->GetEntity();
		cairo_pattern_t *pattern = ::cairo_pattern_create_for_surface(surface);
		if (Is_error(sig, pattern)) {
			::cairo_pattern_destroy(pattern);
			return false;
		}
		value = Value(new Object_pattern(pattern));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(pattern)
{
	return false;
}

Gura_EndModuleScope(cairo)
