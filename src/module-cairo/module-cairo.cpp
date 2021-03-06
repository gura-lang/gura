//-----------------------------------------------------------------------------
// Gura module: cairo
// cairo version 1.12.12
//-----------------------------------------------------------------------------
#include "stdafx.h"

#define Gura_AssignCairoValue(name) \
Gura_AssignValue(name, Value(CAIRO_##name))

#define Gura_AssignCairoStringValue(name) \
Gura_AssignValue(name, Value(CAIRO_##name))

Gura_BeginModuleBody(cairo)

//-----------------------------------------------------------------------------
// Gura interfaces for image
// These method are available after importing opengl module.
//-----------------------------------------------------------------------------
// image#cairo() {block?}
Gura_DeclareMethod(image, cairo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, cairo)
{
	Object_image *pThis = Object_image::GetObjectThis(arg);
	Image *pImage = Image::Reference(pThis->GetImage());
	cairo_surface_t *surface = CreateSurfaceFromImage(env, pImage);
	if (env.IsSignalled()) {
		Image::Delete(pImage);
		return Value::Nil;
	}
	Object_surface *pObjSurface = new Object_image_surface(surface, pImage);
	cairo_t *cr = ::cairo_create(surface);
	return ReturnValue(env, arg, Value(new Object_context(cr, pObjSurface)));
}

//-----------------------------------------------------------------------------
// Gura module functions: cairo
//-----------------------------------------------------------------------------
// cairo.create(surface:cairo.surface) {block?}
Gura_DeclareFunction(create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "surface", VTYPE_surface);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(create)
{
	Object_surface *pObjSurface = Object_surface::GetObject(arg, 0);
	cairo_t *cr = ::cairo_create(pObjSurface->GetEntity());
	return ReturnValue(env, arg,
		Value(new Object_context(cr, Object_surface::Reference(pObjSurface))));
}

// cairo.pdf_get_versions()
Gura_DeclareFunction(pdf_get_versions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(pdf_get_versions)
{
	cairo_pdf_version_t const *versions = nullptr;
	int num_versions = 0;
	::cairo_pdf_get_versions(&versions, &num_versions);
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	if (num_versions > 0) {
		pObjList->Reserve(num_versions);
		for (int i = 0; i < num_versions; i++) {
			pObjList->Add(Value(versions[i]));
		}
	}
	return rtn;
}

#if !defined(GURA_ON_DARWIN)
//#void cairo_ps_get_levels(cairo_ps_level_t const **levels, int *num_levels);
// cairo.ps_get_levels()
Gura_DeclareFunction(ps_get_levels)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(ps_get_levels)
{
	cairo_ps_level_t const *levels = nullptr;
	int num_levels = 0;
	::cairo_ps_get_levels(&levels, &num_levels);
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	if (num_levels > 0) {
		pObjList->Reserve(num_levels);
		for (int i = 0; i < num_levels; i++) {
			pObjList->Add(Value(levels[i]));
		}
	}
	return rtn;
}

// cairo.ps_level_to_string(level:number)
Gura_DeclareFunction(ps_level_to_string)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "level", VTYPE_number);
}

Gura_ImplementFunction(ps_level_to_string)
{
	cairo_ps_level_t level = static_cast<cairo_ps_level_t>(arg.GetInt(0));
	const char *rtn = ::cairo_ps_level_to_string(level);
	if (rtn == nullptr) return Value::Nil;
	return Value(rtn);
}
#endif

// cairo.svg_get_versions()
Gura_DeclareFunction(svg_get_versions)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(svg_get_versions)
{
	cairo_svg_version_t const *versions = nullptr;
	int num_versions = 0;
	::cairo_svg_get_versions(&versions, &num_versions);
	Value rtn;
	Object_list *pObjList = rtn.InitAsList(env);
	if (num_versions > 0) {
		pObjList->Reserve(num_versions);
		for (int i = 0; i < num_versions; i++) {
			pObjList->Add(Value(versions[i]));
		}
	}
	return rtn;
}

// cairo.pdf_version_to_string(version:number)
Gura_DeclareFunction(pdf_version_to_string)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "version", VTYPE_number);
}

Gura_ImplementFunction(pdf_version_to_string)
{
	cairo_pdf_version_t version = static_cast<cairo_pdf_version_t>(arg.GetInt(0));
	const char *rtn = ::cairo_pdf_version_to_string(version);
	if (rtn == nullptr) return Value::Nil;
	return Value(rtn);
}

// cairo.svg_version_to_string(version:number)
Gura_DeclareFunction(svg_version_to_string)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "version", VTYPE_number);
}

Gura_ImplementFunction(svg_version_to_string)
{
	cairo_svg_version_t version = static_cast<cairo_svg_version_t>(arg.GetInt(0));
	const char *rtn = ::cairo_svg_version_to_string(version);
	if (rtn == nullptr) return Value::Nil;
	return Value(rtn);
}

// cairo.status_to_string(status:number)
Gura_DeclareFunction(status_to_string)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "version", VTYPE_number);
}

Gura_ImplementFunction(status_to_string)
{
	cairo_status_t status = static_cast<cairo_status_t>(arg.GetInt(0));
	const char *rtn = ::cairo_status_to_string(status);
	if (rtn == nullptr) return Value::Nil;
	return Value(rtn);
}

// cairo.format_stride_for_width(format:number, width:number)
Gura_DeclareFunction(format_stride_for_width)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
}

Gura_ImplementFunction(format_stride_for_width)
{
	cairo_format_t format = static_cast<cairo_format_t>(arg.GetInt(0));
	int width = arg.GetInt(1);
	int rtn = ::cairo_format_stride_for_width(format, width);
	return Value(rtn);
}

// cairo.debug_reset_static_data():void
Gura_DeclareFunction(debug_reset_static_data)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(debug_reset_static_data)
{
	::cairo_debug_reset_static_data();
	return Value::Nil;
}

// cairo.test()
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(test)
{
#if 0
	HDC hdc;
	char printerName[MAX_PATH];
	DWORD cch = ArraySizeOf(printerName) - 1;
	if (!::GetDefaultPrinter(printerName, &cch)) {
		::printf("failed to get a default printer");
		return Value::Nil;
	}
	if (!(hdc = ::CreateDC(nullptr, printerName, nullptr , nullptr))) {
		::printf("error in CreateDC()\n");
		return Value::Nil;
	}
	DOCINFO diInfo;
	::memset(&diInfo, 0x00, sizeof(diInfo));
	diInfo.cbSize = sizeof (DOCINFO);
	diInfo.lpszDocName = "title";
	if (::StartDoc(hdc , &diInfo) > 0 && ::StartPage(hdc) > 0) {
		::SetMapMode(hdc, MM_LOMETRIC);
		::Ellipse(hdc , 0 , 0 , 500 , -500);
		::TextOut(hdc , 0 , 0 , "test", 4);
		::EndPage(hdc);
		::EndDoc(hdc);
	}
	::DeleteDC(hdc);
#endif
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// symbol realization
	Gura_RealizeUserSymbol(ascent);
	Gura_RealizeUserSymbol(descent);
	Gura_RealizeUserSymbol(height);
	Gura_RealizeUserSymbol(image);
	Gura_RealizeUserSymbol(max_x_advance);
	Gura_RealizeUserSymbol(max_y_advance);
	Gura_RealizeUserSymbol(stream);
	Gura_RealizeUserSymbol(surface);
	Gura_RealizeUserSymbol(type);
	Gura_RealizeUserSymbol(width);
	Gura_RealizeUserSymbol(x_advance);
	Gura_RealizeUserSymbol(x_bearing);
	Gura_RealizeUserSymbol(y_advance);
	Gura_RealizeUserSymbol(y_bearing);
	// class realization
	Gura_RealizeAndPrepareUserClass(font_extents,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(text_extents,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(rectangle,			env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(rectangle_int,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(font_face,			env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(toy_font_face,		Gura_UserClass(font_face));
	Gura_RealizeAndPrepareUserClass(ft_font_face,		Gura_UserClass(font_face));
	Gura_RealizeAndPrepareUserClass(win32_font_face,	Gura_UserClass(font_face));
	Gura_RealizeAndPrepareUserClass(quartz_font_face,	Gura_UserClass(font_face));
	Gura_RealizeAndPrepareUserClass(user_font_face,		Gura_UserClass(font_face));
	Gura_RealizeAndPrepareUserClass(scaled_font,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(font_options,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(device,				env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(surface,			env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(image_surface,		Gura_UserClass(surface));
	Gura_RealizeAndPrepareUserClass(pdf_surface,		Gura_UserClass(surface));
#if !defined(GURA_ON_DARWIN)
	Gura_RealizeAndPrepareUserClass(ps_surface,			Gura_UserClass(surface));
#endif
	Gura_RealizeAndPrepareUserClass(recording_surface,	Gura_UserClass(surface));
	Gura_RealizeAndPrepareUserClass(win32_surface,		Gura_UserClass(surface));
	Gura_RealizeAndPrepareUserClass(svg_surface,		Gura_UserClass(surface));
	Gura_RealizeAndPrepareUserClass(quartz_surface,		Gura_UserClass(surface));
	Gura_RealizeAndPrepareUserClass(xcb_surface,		Gura_UserClass(surface));
	Gura_RealizeAndPrepareUserClass(xlib_surface,		Gura_UserClass(surface));
	Gura_RealizeAndPrepareUserClass(script_surface,		Gura_UserClass(surface));
	Gura_RealizeAndPrepareUserClass(pattern,			env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(raster_source_pattern, Gura_UserClass(pattern));
	Gura_RealizeAndPrepareUserClass(mesh_pattern,		Gura_UserClass(pattern));
	Gura_RealizeAndPrepareUserClass(region,				env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(path,				env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(glyph,				env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(text_cluster,		env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(context,			env.LookupClass(VTYPE_object));
	// method assignment to image type
	Gura_AssignMethodTo(VTYPE_image, image, cairo);
	// class reference assignment
	Gura_AssignValue(font_extents,			Value(Gura_UserClass(font_extents)->Reference()));
	Gura_AssignValue(text_extents,			Value(Gura_UserClass(text_extents)->Reference()));
	//Gura_AssignValue(rectangle,			Value(Gura_UserClass(rectangle)->Reference()));
	//Gura_AssignValue(rectangle_int,		Value(Gura_UserClass(rectangle_int)->Reference()));
	Gura_AssignValue(font_face,				Value(Gura_UserClass(font_face)->Reference()));
	Gura_AssignValue(toy_font_face,			Value(Gura_UserClass(toy_font_face)->Reference()));
	Gura_AssignValue(ft_font_face,			Value(Gura_UserClass(ft_font_face)->Reference()));
	Gura_AssignValue(win32_font_face,		Value(Gura_UserClass(win32_font_face)->Reference()));
	Gura_AssignValue(quartz_font_face,		Value(Gura_UserClass(quartz_font_face)->Reference()));
	Gura_AssignValue(user_font_face,		Value(Gura_UserClass(user_font_face)->Reference()));
	Gura_AssignValue(scaled_font,			Value(Gura_UserClass(scaled_font)->Reference()));
	Gura_AssignValue(font_options,			Value(Gura_UserClass(font_options)->Reference()));
	Gura_AssignValue(device,				Value(Gura_UserClass(device)->Reference()));
	Gura_AssignValue(surface,				Value(Gura_UserClass(surface)->Reference()));
	Gura_AssignValue(image_surface,			Value(Gura_UserClass(image_surface)->Reference()));
	Gura_AssignValue(pdf_surface,			Value(Gura_UserClass(pdf_surface)->Reference()));
#if !defined(GURA_ON_DARWIN)
	Gura_AssignValue(ps_surface,			Value(Gura_UserClass(ps_surface)->Reference()));
#endif
	Gura_AssignValue(recording_surface,		Value(Gura_UserClass(recording_surface)->Reference()));
	Gura_AssignValue(win32_surface,			Value(Gura_UserClass(win32_surface)->Reference()));
	Gura_AssignValue(svg_surface,			Value(Gura_UserClass(svg_surface)->Reference()));
	Gura_AssignValue(quartz_surface,		Value(Gura_UserClass(quartz_surface)->Reference()));
	Gura_AssignValue(xcb_surface,			Value(Gura_UserClass(xcb_surface)->Reference()));
	Gura_AssignValue(xlib_surface,			Value(Gura_UserClass(xlib_surface)->Reference()));
	Gura_AssignValue(script_surface,		Value(Gura_UserClass(script_surface)->Reference()));
	Gura_AssignValue(pattern,				Value(Gura_UserClass(pattern)->Reference()));
	Gura_AssignValue(raster_source_pattern,	Value(Gura_UserClass(raster_source_pattern)->Reference()));
	Gura_AssignValue(mesh_pattern,			Value(Gura_UserClass(mesh_pattern)->Reference()));
	Gura_AssignValue(region,				Value(Gura_UserClass(region)->Reference()));
	Gura_AssignValue(path,					Value(Gura_UserClass(path)->Reference()));
	Gura_AssignValue(glyph,					Value(Gura_UserClass(glyph)->Reference()));
	Gura_AssignValue(text_cluster,			Value(Gura_UserClass(text_cluster)->Reference()));
	Gura_AssignValue(context,				Value(Gura_UserClass(context)->Reference()));
	// function assignment
	Gura_AssignFunction(create);
#if !defined(GURA_ON_DARWIN)
	Gura_AssignFunction(ps_get_levels);
	Gura_AssignFunction(ps_level_to_string);
#endif
	Gura_AssignFunction(pdf_get_versions);
	Gura_AssignFunction(svg_get_versions);
	Gura_AssignFunction(pdf_version_to_string);
	Gura_AssignFunction(svg_version_to_string);
	Gura_AssignFunction(status_to_string);
	Gura_AssignFunction(format_stride_for_width);
	Gura_AssignFunction(debug_reset_static_data);
	Gura_AssignFunction(test);
	// cairo_format_t
	Gura_AssignCairoValue(FORMAT_INVALID);
	Gura_AssignCairoValue(FORMAT_ARGB32);
	Gura_AssignCairoValue(FORMAT_RGB24);
	Gura_AssignCairoValue(FORMAT_A8);
	Gura_AssignCairoValue(FORMAT_A1);
	Gura_AssignCairoValue(FORMAT_RGB16_565);
	//Gura_AssignCairoValue(FORMAT_RGB30);
	// cairo_path_data_type_t
	Gura_AssignCairoValue(PATH_MOVE_TO);
	Gura_AssignCairoValue(PATH_LINE_TO);
	Gura_AssignCairoValue(PATH_CURVE_TO);
	Gura_AssignCairoValue(PATH_CLOSE_PATH);
	// cairo_antialias_t
	Gura_AssignCairoValue(ANTIALIAS_DEFAULT);
	Gura_AssignCairoValue(ANTIALIAS_NONE);
	Gura_AssignCairoValue(ANTIALIAS_GRAY);
	Gura_AssignCairoValue(ANTIALIAS_SUBPIXEL);
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Gura_AssignCairoValue(ANTIALIAS_FAST);
	Gura_AssignCairoValue(ANTIALIAS_GOOD);
	Gura_AssignCairoValue(ANTIALIAS_BEST);
#endif
	// cairo_fill_rule_t
	Gura_AssignCairoValue(FILL_RULE_WINDING);
	Gura_AssignCairoValue(FILL_RULE_EVEN_ODD);
	// cairo_line_cap_t
	Gura_AssignCairoValue(LINE_CAP_BUTT);
	Gura_AssignCairoValue(LINE_CAP_ROUND);
	Gura_AssignCairoValue(LINE_CAP_SQUARE);
	// cairo_line_join_t
	Gura_AssignCairoValue(LINE_JOIN_MITER);
	Gura_AssignCairoValue(LINE_JOIN_ROUND);
	Gura_AssignCairoValue(LINE_JOIN_BEVEL);
	// cairo_font_slant_t
	Gura_AssignCairoValue(FONT_SLANT_NORMAL);
	Gura_AssignCairoValue(FONT_SLANT_ITALIC);
	Gura_AssignCairoValue(FONT_SLANT_OBLIQUE);
	// cairo_font_weight_t
	Gura_AssignCairoValue(FONT_WEIGHT_NORMAL);
	Gura_AssignCairoValue(FONT_WEIGHT_BOLD);
	// cairo_font_type_t
	Gura_AssignCairoValue(FONT_TYPE_TOY);
	Gura_AssignCairoValue(FONT_TYPE_FT);
	Gura_AssignCairoValue(FONT_TYPE_WIN32);
	Gura_AssignCairoValue(FONT_TYPE_QUARTZ);
	Gura_AssignCairoValue(FONT_TYPE_USER);
	// cairo_operator_t
	Gura_AssignCairoValue(OPERATOR_CLEAR);
	Gura_AssignCairoValue(OPERATOR_SOURCE);
	Gura_AssignCairoValue(OPERATOR_OVER);
	Gura_AssignCairoValue(OPERATOR_IN);
	Gura_AssignCairoValue(OPERATOR_OUT);
	Gura_AssignCairoValue(OPERATOR_ATOP);
	Gura_AssignCairoValue(OPERATOR_DEST);
	Gura_AssignCairoValue(OPERATOR_DEST_OVER);
	Gura_AssignCairoValue(OPERATOR_DEST_IN);
	Gura_AssignCairoValue(OPERATOR_DEST_OUT);
	Gura_AssignCairoValue(OPERATOR_DEST_ATOP);
	Gura_AssignCairoValue(OPERATOR_XOR);
	Gura_AssignCairoValue(OPERATOR_ADD);
	Gura_AssignCairoValue(OPERATOR_SATURATE);
	Gura_AssignCairoValue(OPERATOR_MULTIPLY);
	Gura_AssignCairoValue(OPERATOR_SCREEN);
	Gura_AssignCairoValue(OPERATOR_OVERLAY);
	Gura_AssignCairoValue(OPERATOR_DARKEN);
	Gura_AssignCairoValue(OPERATOR_LIGHTEN);
	Gura_AssignCairoValue(OPERATOR_COLOR_DODGE);
	Gura_AssignCairoValue(OPERATOR_COLOR_BURN);
	Gura_AssignCairoValue(OPERATOR_HARD_LIGHT);
	Gura_AssignCairoValue(OPERATOR_SOFT_LIGHT);
	Gura_AssignCairoValue(OPERATOR_DIFFERENCE);
	Gura_AssignCairoValue(OPERATOR_EXCLUSION);
	Gura_AssignCairoValue(OPERATOR_HSL_HUE);
	Gura_AssignCairoValue(OPERATOR_HSL_SATURATION);
	Gura_AssignCairoValue(OPERATOR_HSL_COLOR);
	Gura_AssignCairoValue(OPERATOR_HSL_LUMINOSITY);
	// cairo_region_overlap_t
	Gura_AssignCairoValue(REGION_OVERLAP_IN);
	Gura_AssignCairoValue(REGION_OVERLAP_OUT);
	Gura_AssignCairoValue(REGION_OVERLAP_PART);
	// cairo_extend_t
	Gura_AssignCairoValue(EXTEND_NONE);
	Gura_AssignCairoValue(EXTEND_REPEAT);
	Gura_AssignCairoValue(EXTEND_REFLECT);
	Gura_AssignCairoValue(EXTEND_PAD);
	// cairo_filter_t
	Gura_AssignCairoValue(FILTER_FAST);
	Gura_AssignCairoValue(FILTER_GOOD);
	Gura_AssignCairoValue(FILTER_BEST);
	Gura_AssignCairoValue(FILTER_NEAREST);
	Gura_AssignCairoValue(FILTER_BILINEAR);
	Gura_AssignCairoValue(FILTER_GAUSSIAN);
	// cairo_content_t
	Gura_AssignCairoValue(CONTENT_COLOR);
	Gura_AssignCairoValue(CONTENT_ALPHA);
	Gura_AssignCairoValue(CONTENT_COLOR_ALPHA);
	// cairo_subpixel_order_t
	Gura_AssignCairoValue(SUBPIXEL_ORDER_DEFAULT);
	Gura_AssignCairoValue(SUBPIXEL_ORDER_RGB);
	Gura_AssignCairoValue(SUBPIXEL_ORDER_BGR);
	Gura_AssignCairoValue(SUBPIXEL_ORDER_VRGB);
	Gura_AssignCairoValue(SUBPIXEL_ORDER_VBGR);
	// cairo_hint_style_t
	Gura_AssignCairoValue(HINT_STYLE_DEFAULT);
	Gura_AssignCairoValue(HINT_STYLE_NONE);
	Gura_AssignCairoValue(HINT_STYLE_SLIGHT);
	Gura_AssignCairoValue(HINT_STYLE_MEDIUM);
	Gura_AssignCairoValue(HINT_STYLE_FULL);
	// cairo_hint_metrics_t
	Gura_AssignCairoValue(HINT_METRICS_DEFAULT);
	Gura_AssignCairoValue(HINT_METRICS_OFF);
	Gura_AssignCairoValue(HINT_METRICS_ON);
	// cairo_surface_type_t
	Gura_AssignCairoValue(SURFACE_TYPE_IMAGE);
	Gura_AssignCairoValue(SURFACE_TYPE_PDF);
	Gura_AssignCairoValue(SURFACE_TYPE_PS);
	Gura_AssignCairoValue(SURFACE_TYPE_XLIB);
	Gura_AssignCairoValue(SURFACE_TYPE_XCB);
	Gura_AssignCairoValue(SURFACE_TYPE_GLITZ);
	Gura_AssignCairoValue(SURFACE_TYPE_QUARTZ);
	Gura_AssignCairoValue(SURFACE_TYPE_WIN32);
	Gura_AssignCairoValue(SURFACE_TYPE_BEOS);
	Gura_AssignCairoValue(SURFACE_TYPE_DIRECTFB);
	Gura_AssignCairoValue(SURFACE_TYPE_SVG);
	Gura_AssignCairoValue(SURFACE_TYPE_OS2);
	Gura_AssignCairoValue(SURFACE_TYPE_WIN32_PRINTING);
	Gura_AssignCairoValue(SURFACE_TYPE_QUARTZ_IMAGE);
	Gura_AssignCairoValue(SURFACE_TYPE_SCRIPT);
	Gura_AssignCairoValue(SURFACE_TYPE_QT);
	Gura_AssignCairoValue(SURFACE_TYPE_RECORDING);
	Gura_AssignCairoValue(SURFACE_TYPE_VG);
	Gura_AssignCairoValue(SURFACE_TYPE_GL);
	Gura_AssignCairoValue(SURFACE_TYPE_DRM);
	Gura_AssignCairoValue(SURFACE_TYPE_TEE);
	Gura_AssignCairoValue(SURFACE_TYPE_XML);
	Gura_AssignCairoValue(SURFACE_TYPE_SKIA);
	Gura_AssignCairoValue(SURFACE_TYPE_SUBSURFACE);
	// cairo_device_type_t
	Gura_AssignCairoValue(DEVICE_TYPE_DRM);
	Gura_AssignCairoValue(DEVICE_TYPE_GL);
	Gura_AssignCairoValue(DEVICE_TYPE_SCRIPT);
	Gura_AssignCairoValue(DEVICE_TYPE_XCB);
	Gura_AssignCairoValue(DEVICE_TYPE_XLIB);
	Gura_AssignCairoValue(DEVICE_TYPE_XML);
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 12, 0)
	Gura_AssignCairoValue(DEVICE_TYPE_COGL);
	Gura_AssignCairoValue(DEVICE_TYPE_WIN32);
#endif
	//Gura_AssignCairoValue(DEVICE_TYPE_INVALID);
#if !defined(GURA_ON_DARWIN)
	// cairo_ps_level_t
	Gura_AssignCairoValue(PS_LEVEL_2);
	Gura_AssignCairoValue(PS_LEVEL_3);
#endif
	// cairo_pdf_version_t
	Gura_AssignCairoValue(PDF_VERSION_1_4);
	Gura_AssignCairoValue(PDF_VERSION_1_5);
	// cairo_svg_version_t
	Gura_AssignCairoValue(SVG_VERSION_1_1);
	Gura_AssignCairoValue(SVG_VERSION_1_2);
	// MIME_TYPE
	Gura_AssignCairoStringValue(MIME_TYPE_JP2);
	Gura_AssignCairoStringValue(MIME_TYPE_JPEG);
	Gura_AssignCairoStringValue(MIME_TYPE_PNG);
	Gura_AssignCairoStringValue(MIME_TYPE_URI);
	//Gura_AssignCairoStringValue(MIME_TYPE_UNIQUE_ID);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// Reader implementation
//-----------------------------------------------------------------------------
Reader::~Reader()
{
}

//-----------------------------------------------------------------------------
// Reader_Stream implementation
//-----------------------------------------------------------------------------
Reader_Stream::~Reader_Stream()
{
}

cairo_status_t Reader_Stream::ReadFunc(unsigned char *data, unsigned int length)
{
	_pStream->Read(_sig, data, length);
	if (_sig.IsSignalled()) return CAIRO_STATUS_WRITE_ERROR;
	return CAIRO_STATUS_SUCCESS;
}

cairo_status_t Reader_Stream::read_func(void *closure,
						unsigned char *data, unsigned int length)
{
	Reader_Stream *pReader = reinterpret_cast<Reader_Stream *>(closure);
	return pReader->ReadFunc(data, length);
}

Stream *Reader_Stream::GetStream()
{
	return _pStream.get();
}

//-----------------------------------------------------------------------------
// Writer implementation
//-----------------------------------------------------------------------------
Writer::~Writer()
{
}

//-----------------------------------------------------------------------------
// Writer_Stream implementation
//-----------------------------------------------------------------------------
Writer_Stream::~Writer_Stream()
{
	//_pStream->Close();
}

cairo_status_t Writer_Stream::WriteFunc(const unsigned char *data, unsigned int length)
{
	_pStream->Write(_sig, data, length);
	if (_sig.IsSignalled()) return CAIRO_STATUS_WRITE_ERROR;
	return CAIRO_STATUS_SUCCESS;
}

cairo_status_t Writer_Stream::write_func(void *closure,
						const unsigned char *data, unsigned int length)
{
	Writer_Stream *pWriter = reinterpret_cast<Writer_Stream *>(closure);
	return pWriter->WriteFunc(data, length);
}

Stream *Writer_Stream::GetStream()
{
	return _pStream.get();
}

#if defined(GURA_ON_MSWIN)
//-----------------------------------------------------------------------------
// Writer_EnhMetaFile implementation
//-----------------------------------------------------------------------------
Writer_EnhMetaFile::~Writer_EnhMetaFile()
{
	::EndPage(_hdc);
	HENHMETAFILE hEmf = ::CloseEnhMetaFile(_hdc);
	::DeleteEnhMetaFile(hEmf);
}

Stream *Writer_EnhMetaFile::GetStream()
{
	return nullptr;
}

//-----------------------------------------------------------------------------
// Writer_WindowsDC implementation
//-----------------------------------------------------------------------------
Writer_WindowsDC::~Writer_WindowsDC()
{
	::EndDoc(_hdc);
	::DeleteDC(_hdc);
}

Stream *Writer_WindowsDC::GetStream()
{
	return nullptr;
}
#endif

//-----------------------------------------------------------------------------
// Error handling
//-----------------------------------------------------------------------------
bool IsInvalid(Signal &sig, cairo_t *cr)
{
	if (cr == nullptr) {
		sig.SetError(ERR_ValueError, "invalid context");
		return true;
	}
	return false;
}

bool Is_error(Signal &sig, cairo_status_t status)
{
	if (status == CAIRO_STATUS_SUCCESS) return false;
	sig.SetError(ERR_LibraryError, "[cairo] %s", ::cairo_status_to_string(status));
	return true;
}

bool Is_error(Signal &sig, cairo_t *cr)
{
	return Is_error(sig, ::cairo_status(cr));
}

bool Is_error(Signal &sig, cairo_pattern_t *pattern)
{
	return Is_error(sig, ::cairo_pattern_status(pattern));
}

bool Is_error(Signal &sig, cairo_region_t *region)
{
	return Is_error(sig, ::cairo_region_status(region));
}

bool Is_error(Signal &sig, cairo_font_face_t *font_face)
{
	return Is_error(sig, ::cairo_font_face_status(font_face));
}

bool Is_error(Signal &sig, cairo_scaled_font_t *scaled_font)
{
	return Is_error(sig, ::cairo_scaled_font_status(scaled_font));
}

bool Is_error(Signal &sig, cairo_device_t *device)
{
	return Is_error(sig, ::cairo_device_status(device));
}

bool Is_error(Signal &sig, cairo_surface_t *surface)
{
	return Is_error(sig, ::cairo_surface_status(surface));
}

bool Is_error(Signal &sig, cairo_font_options_t *options)
{
	return Is_error(sig, ::cairo_font_options_status(options));
}

const char *SurfaceTypeToName(cairo_surface_type_t surface_type)
{
	struct Info {
		cairo_surface_type_t surface_type;
		const char *name;
	};
	static const Info infoTbl[] = {
		{ CAIRO_SURFACE_TYPE_IMAGE,			"image"			},
		{ CAIRO_SURFACE_TYPE_PDF,			"pdf"			},
		{ CAIRO_SURFACE_TYPE_PS,			"ps"			},
		{ CAIRO_SURFACE_TYPE_XLIB,			"xlib"			},
		{ CAIRO_SURFACE_TYPE_XCB,			"xcb"			},
		{ CAIRO_SURFACE_TYPE_GLITZ,			"glitz"			},
		{ CAIRO_SURFACE_TYPE_QUARTZ,		"quartz"		},
		{ CAIRO_SURFACE_TYPE_WIN32,			"win32"			},
		{ CAIRO_SURFACE_TYPE_BEOS,			"beos"			},
		{ CAIRO_SURFACE_TYPE_DIRECTFB,		"directfb"		},
		{ CAIRO_SURFACE_TYPE_SVG,			"svg"			},
		{ CAIRO_SURFACE_TYPE_OS2,			"os2"			},
		{ CAIRO_SURFACE_TYPE_WIN32_PRINTING,"win32_printing"},
		{ CAIRO_SURFACE_TYPE_QUARTZ_IMAGE,	"quartz_image"	},
		{ CAIRO_SURFACE_TYPE_SCRIPT,		"script"		},
		{ CAIRO_SURFACE_TYPE_QT,			"qt"			},
		{ CAIRO_SURFACE_TYPE_RECORDING,		"recording"		},
		{ CAIRO_SURFACE_TYPE_VG,			"vg"			},
		{ CAIRO_SURFACE_TYPE_GL,			"gl"			},
		{ CAIRO_SURFACE_TYPE_DRM,			"drm"			},
		{ CAIRO_SURFACE_TYPE_TEE,			"tee"			},
		{ CAIRO_SURFACE_TYPE_XML,			"xml"			},
		{ CAIRO_SURFACE_TYPE_SKIA		,	"skia"			},
		{ CAIRO_SURFACE_TYPE_SUBSURFACE,	"subsurface"	},
	};
	for (size_t i = 0; i < ArraySizeOf(infoTbl); i++) {
		if (infoTbl[i].surface_type == surface_type) return infoTbl[i].name;
	}
	return "(unknown)";
}

//-----------------------------------------------------------------------------
// Value converter
//-----------------------------------------------------------------------------
Value RectangleToValue(Environment &env, const cairo_rectangle_t &rectangle)
{
	Value value;
	Object_list *pObjList = value.InitAsList(env);
	pObjList->Reserve(5);
	pObjList->Add(Value(rectangle.x));
	pObjList->Add(Value(rectangle.y));
	pObjList->Add(Value(rectangle.width));
	pObjList->Add(Value(rectangle.height));
	pObjList->Add(value);
	return value;
}

bool ValueListToRectangle(Signal &sig, cairo_rectangle_t &rectangle, const ValueList &valList)
{
	if (valList.size() != 4) {
		sig.SetError(ERR_ValueError, "list must have four elements");
		return false;
	}
	rectangle.x = valList[0].GetDouble();
	rectangle.y = valList[1].GetDouble();
	rectangle.width = valList[2].GetDouble();
	rectangle.height = valList[3].GetDouble();
	return true;
}

bool ValueListToRectangle(Signal &sig, cairo_rectangle_int_t &rectangle, const ValueList &valList)
{
	if (valList.size() != 4) {
		sig.SetError(ERR_ValueError, "list must have four elements");
		return false;
	}
	rectangle.x = valList[0].GetInt();
	rectangle.y = valList[1].GetInt();
	rectangle.width = valList[2].GetInt();
	rectangle.height = valList[3].GetInt();
	return true;
}

ArrayT<Double> *CairoToArray(const cairo_matrix_t &matrix)
{
	AutoPtr<ArrayT<Double> > pArrayT(ArrayT<Double>::Create2d(3, 3));
	Double *pElem = pArrayT->GetPointer();
	*pElem++ = matrix.xx;	*pElem++ = matrix.xy;	*pElem++ = matrix.x0;
	*pElem++ = matrix.yx;	*pElem++ = matrix.yy;	*pElem++ = matrix.y0;
	*pElem++ = 0;			*pElem++ = 0;			*pElem++ = 1;
	return pArrayT.release();
}

bool ArrayToCairo(Signal &sig, cairo_matrix_t &matrix, const ArrayT<Double> *pArrayT)
{
	if (pArrayT->GetElemNum() != 9) {
		sig.SetError(ERR_ValueError, "matrix size must be 3x3");
		return false;
	}
	const Double *pElem = pArrayT->GetPointer();
	matrix.xx = *pElem++;
	matrix.xy = *pElem++;
	matrix.x0 = *pElem++;
	matrix.yx = *pElem++;
	matrix.yy = *pElem++;
	matrix.y0 = *pElem++;
	return true;
}

Value CreateValueList(Environment &env, double x1, double x2)
{
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	pObjList->Reserve(2);
	pObjList->Add(Value(x1));
	pObjList->Add(Value(x2));
	return result;
}

Value CreateValueList(Environment &env, double x1, double x2, double x3)
{
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	pObjList->Reserve(3);
	pObjList->Add(Value(x1));
	pObjList->Add(Value(x2));
	pObjList->Add(Value(x3));
	return result;
}

Value CreateValueList(Environment &env, double x1, double x2, double x3, double x4)
{
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	pObjList->Reserve(4);
	pObjList->Add(Value(x1));
	pObjList->Add(Value(x2));
	pObjList->Add(Value(x3));
	pObjList->Add(Value(x4));
	return result;
}

Value CreateValueList(Environment &env,
				double x1, double x2, double x3, double x4, double x5)
{
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	pObjList->Reserve(5);
	pObjList->Add(Value(x1));
	pObjList->Add(Value(x2));
	pObjList->Add(Value(x3));
	pObjList->Add(Value(x4));
	pObjList->Add(Value(x5));
	return result;
}

Value CreateValueList(Environment &env,
				double x1, double x2, double x3, double x4, double x5, double x6)
{
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	pObjList->Reserve(6);
	pObjList->Add(Value(x1));
	pObjList->Add(Value(x2));
	pObjList->Add(Value(x3));
	pObjList->Add(Value(x4));
	pObjList->Add(Value(x5));
	pObjList->Add(Value(x6));
	return result;
}

cairo_surface_t *CreateSurfaceFromImage(Signal &sig, Image *pImage)
{
	if (!pImage->CheckValid(sig)) return nullptr;
	if (pImage->GetFormat() != Image::FORMAT_RGBA) {
		sig.SetError(ERR_FormatError, "cairo can only be applied to image in `rgba format");
		return nullptr;
	}
	size_t width = pImage->GetWidth();
	size_t height = pImage->GetHeight();
	cairo_surface_t *surface = ::cairo_image_surface_create_for_data(
				pImage->GetBuffer(), CAIRO_FORMAT_ARGB32,
				static_cast<int>(width), static_cast<int>(height),
				static_cast<int>(pImage->GetBytesPerLine()));
	return surface;
}

Gura_EndModuleBody(cairo, cairo)

Gura_RegisterModule(cairo)

//#void cairo_matrix_init(cairo_matrix_t *matrix, double xx, double yx, double xy, double yy, double x0, double y0);
//#void cairo_matrix_init_identity(cairo_matrix_t *matrix);
//#void cairo_matrix_init_translate(cairo_matrix_t *matrix, double tx, double ty);
//#void cairo_matrix_init_scale(cairo_matrix_t *matrix, double sx, double sy);
//#void cairo_matrix_init_rotate(cairo_matrix_t *matrix, double radians);
//#void cairo_matrix_translate(cairo_matrix_t *matrix, double tx, double ty);
//#void cairo_matrix_scale(cairo_matrix_t *matrix, double sx, double sy);
//#void cairo_matrix_rotate(cairo_matrix_t *matrix, double radians);
//#cairo_status_t cairo_matrix_invert(cairo_matrix_t *matrix);
//#void cairo_matrix_multiply(cairo_matrix_t *result, const cairo_matrix_t *a, const cairo_matrix_t *b);
//#void cairo_matrix_transform_distance(const cairo_matrix_t *matrix, double *dx, double *dy);
//#void cairo_matrix_transform_point(const cairo_matrix_t *matrix, double *x, double *y);
