//-----------------------------------------------------------------------------
// Gura cairo module
// cairo version 1.12.12
//-----------------------------------------------------------------------------
#include "stdafx.h"

#define Gura_AssignCairoValue(name) \
Gura_AssignValue(name, Value(CAIRO_##name))

#define Gura_AssignCairoStringValue(name) \
Gura_AssignValue(name, Value(env, CAIRO_##name))

Gura_BeginModule(cairo)

const double NUM_PI = 3.14159265358979323846;

//-----------------------------------------------------------------------------
// Gura interfaces for image
// These method are available after importing opengl module.
//-----------------------------------------------------------------------------
// image#cairo() {block?}
Gura_DeclareMethod(image, cairo)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(image, cairo)
{
	Object_image *pThis = Object_image::GetThisObj(args);
	Object_image *pObjImage = Object_image::Reference(pThis);
	cairo_surface_t *surface = CreateSurfaceFromImage(sig, pObjImage);
	if (sig.IsSignalled()) {
		Object_image::Delete(pObjImage);
		return Value::Null;
	}
	Object_surface *pObjSurface = new Object_image_surface(surface, pObjImage);
	cairo_t *cr = ::cairo_create(surface);
	return ReturnValue(env, sig, args, Value(new Object_context(cr, pObjSurface)));
}

//-----------------------------------------------------------------------------
// Gura module functions: cairo
//-----------------------------------------------------------------------------
// cairo.create(surface:cairo.surface) {block?}
Gura_DeclareFunction(create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "surface", VTYPE_surface);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(create)
{
	Object_surface *pObjSurface = Object_surface::GetObject(args, 0);
	cairo_t *cr = ::cairo_create(pObjSurface->GetEntity());
	return ReturnValue(env, sig, args,
		Value(new Object_context(cr, Object_surface::Reference(pObjSurface))));
}

// cairo.pdf_get_versions()
Gura_DeclareFunction(pdf_get_versions)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(pdf_get_versions)
{
	cairo_pdf_version_t const *versions = NULL;
	int num_versions = 0;
	::cairo_pdf_get_versions(&versions, &num_versions);
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	if (num_versions > 0) {
		valList.reserve(num_versions);
		for (int i = 0; i < num_versions; i++) {
			valList.push_back(Value(versions[i]));
		}
	}
	return rtn;
}

// cairo.svg_get_versions()
Gura_DeclareFunction(svg_get_versions)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(svg_get_versions)
{
	cairo_svg_version_t const *versions = NULL;
	int num_versions = 0;
	::cairo_svg_get_versions(&versions, &num_versions);
	Value rtn;
	ValueList &valList = rtn.InitAsList(env);
	if (num_versions > 0) {
		valList.reserve(num_versions);
		for (int i = 0; i < num_versions; i++) {
			valList.push_back(Value(versions[i]));
		}
	}
	return rtn;
}

// cairo.pdf_version_to_string(version:number)
Gura_DeclareFunction(pdf_version_to_string)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "version", VTYPE_number);
}

Gura_ImplementFunction(pdf_version_to_string)
{
	cairo_pdf_version_t version = static_cast<cairo_pdf_version_t>(args.GetInt(0));
	const char *rtn = ::cairo_pdf_version_to_string(version);
	if (rtn == NULL) return Value::Null;
	return Value(env, rtn);
}

// cairo.svg_version_to_string(version:number)
Gura_DeclareFunction(svg_version_to_string)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "version", VTYPE_number);
}

Gura_ImplementFunction(svg_version_to_string)
{
	cairo_svg_version_t version = static_cast<cairo_svg_version_t>(args.GetInt(0));
	const char *rtn = ::cairo_svg_version_to_string(version);
	if (rtn == NULL) return Value::Null;
	return Value(env, rtn);
}

// cairo.status_to_string(status:number)
Gura_DeclareFunction(status_to_string)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "version", VTYPE_number);
}

Gura_ImplementFunction(status_to_string)
{
	cairo_status_t status = static_cast<cairo_status_t>(args.GetInt(0));
	const char *rtn = ::cairo_status_to_string(status);
	if (rtn == NULL) return Value::Null;
	return Value(env, rtn);
}

// cairo.format_stride_for_width(format:number, width:number)
Gura_DeclareFunction(format_stride_for_width)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
}

Gura_ImplementFunction(format_stride_for_width)
{
	cairo_format_t format = static_cast<cairo_format_t>(args.GetInt(0));
	int width = args.GetInt(1);
	int rtn = ::cairo_format_stride_for_width(format, width);
	return Value(rtn);
}

// cairo.debug_reset_static_data():void
Gura_DeclareFunction(debug_reset_static_data)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(debug_reset_static_data)
{
	::cairo_debug_reset_static_data();
	return Value::Null;
}

// cairo.test()
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementFunction(test)
{
#if 0
	const char *driverName = "WINSPOOL\0";
	const char *printerName = "";
	char printerNameDefault[MAX_PATH];
	BYTE printerInfoBuff[16384];
	PRINTER_INFO_2 *pPrinterInfo2 = reinterpret_cast<PRINTER_INFO_2 *>(printerInfoBuff);
	if (::strcmp(printerName, "") == 0) {
		DWORD cch;
		if (!::GetDefaultPrinter(printerNameDefault, &cch)) {
			sig.SetError(ERR_IOError, "failed to get a default printer");
			return Value::Null;
		}
		printerName = printerNameDefault;
	}
	do {
		HANDLE hPrinter;
		if (!::OpenPrinter(const_cast<char *>(printerName), &hPrinter, NULL)) {
			sig.SetError(ERR_IOError, "failed to open printer handler");
			return Value::Null;
		}
		DWORD cbNeeded;
		if (!::GetPrinter(hPrinter, 2, printerInfoBuff, sizeof(printerInfoBuff), &cbNeeded)) {
			sig.SetError(ERR_IOError, "failed to get printer information");
			return Value::Null;
		}
		::ClosePrinter(hPrinter);
	} while (0);
	double width = 100 * 20, height = 100 * 20;
	RECT rc;
	rc.left = 0, rc.top = 0;
	rc.right = static_cast<long>(width * 20);	// unit: 1/20pt
	rc.bottom = static_cast<long>(height * 20);	// unit: 1/20pt
	HDC hdc = ::CreateDC(driverName, printerName, pPrinterInfo2->pPortName, NULL);
	::SetMapMode(hdc, MM_TWIPS);				// 1 unit = 1/20pt
	//::SetMapMode(hdc, MM_HIMETRIC);			// 1 unit = 0.01mm
	cairo_surface_t *surface = ::cairo_win32_printing_surface_create(hdc);
	cairo_t *cr = ::cairo_create(surface);
	
	
	
	::cairo_show_page(cr);
	::DeleteDC(hdc);
	::cairo_destroy(cr);
#endif
	return Value::Null;
}

// Module entry
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
	Gura_RealizeUserClass(font_extents,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(text_extents,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(rectangle,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(rectangle_int,	env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(font_face,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(toy_font_face,	Gura_UserClass(font_face));
	Gura_RealizeUserClass(ft_font_face,		Gura_UserClass(font_face));
	Gura_RealizeUserClass(win32_font_face,	Gura_UserClass(font_face));
	Gura_RealizeUserClass(quartz_font_face,	Gura_UserClass(font_face));
	Gura_RealizeUserClass(user_font_face,	Gura_UserClass(font_face));
	Gura_RealizeUserClass(scaled_font,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(font_options,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(device,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(surface,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(image_surface,	Gura_UserClass(surface));
	Gura_RealizeUserClass(pdf_surface,		Gura_UserClass(surface));
	Gura_RealizeUserClass(ps_surface,		Gura_UserClass(surface));
	Gura_RealizeUserClass(recording_surface,Gura_UserClass(surface));
	Gura_RealizeUserClass(win32_surface,	Gura_UserClass(surface));
	Gura_RealizeUserClass(svg_surface,		Gura_UserClass(surface));
	Gura_RealizeUserClass(quartz_surface,	Gura_UserClass(surface));
	Gura_RealizeUserClass(xcb_surface,		Gura_UserClass(surface));
	Gura_RealizeUserClass(xlib_surface,		Gura_UserClass(surface));
	Gura_RealizeUserClass(script_surface,	Gura_UserClass(surface));
	Gura_RealizeUserClass(pattern,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(region,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(path,				env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(glyph,			env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(text_cluster,		env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(context,			env.LookupClass(VTYPE_object));
	// method assignment to image type
	Gura_AssignMethodTo(VTYPE_image, image, cairo);
	// class reference assignment
	Gura_AssignValue(font_extents,			Value(Gura_UserClass(font_extents)));
	Gura_AssignValue(text_extents,			Value(Gura_UserClass(text_extents)));
	Gura_AssignValue(rectangle,				Value(Gura_UserClass(rectangle)));
	Gura_AssignValue(rectangle_int,			Value(Gura_UserClass(rectangle_int)));
	Gura_AssignValue(font_face,				Value(Gura_UserClass(font_face)));
	Gura_AssignValue(toy_font_face,			Value(Gura_UserClass(toy_font_face)));
	Gura_AssignValue(ft_font_face,			Value(Gura_UserClass(ft_font_face)));
	Gura_AssignValue(win32_font_face,		Value(Gura_UserClass(win32_font_face)));
	Gura_AssignValue(quartz_font_face,		Value(Gura_UserClass(quartz_font_face)));
	Gura_AssignValue(user_font_face,		Value(Gura_UserClass(user_font_face)));
	Gura_AssignValue(scaled_font,			Value(Gura_UserClass(scaled_font)));
	Gura_AssignValue(font_options,			Value(Gura_UserClass(font_options)));
	Gura_AssignValue(device,				Value(Gura_UserClass(device)));
	Gura_AssignValue(surface,				Value(Gura_UserClass(surface)));
	Gura_AssignValue(image_surface,			Value(Gura_UserClass(image_surface)));
	Gura_AssignValue(pdf_surface,			Value(Gura_UserClass(pdf_surface)));
	Gura_AssignValue(ps_surface,			Value(Gura_UserClass(ps_surface)));
	Gura_AssignValue(recording_surface,		Value(Gura_UserClass(recording_surface)));
	Gura_AssignValue(win32_surface,			Value(Gura_UserClass(win32_surface)));
	Gura_AssignValue(svg_surface,			Value(Gura_UserClass(svg_surface)));
	Gura_AssignValue(quartz_surface,		Value(Gura_UserClass(quartz_surface)));
	Gura_AssignValue(xcb_surface,			Value(Gura_UserClass(xcb_surface)));
	Gura_AssignValue(xlib_surface,			Value(Gura_UserClass(xlib_surface)));
	Gura_AssignValue(script_surface,		Value(Gura_UserClass(script_surface)));
	Gura_AssignValue(pattern,				Value(Gura_UserClass(pattern)));
	Gura_AssignValue(region,				Value(Gura_UserClass(region)));
	Gura_AssignValue(path,					Value(Gura_UserClass(path)));
	Gura_AssignValue(glyph,					Value(Gura_UserClass(glyph)));
	Gura_AssignValue(text_cluster,			Value(Gura_UserClass(text_cluster)));
	Gura_AssignValue(context,				Value(Gura_UserClass(context)));
	// function assignment
	Gura_AssignFunction(create);
	Gura_AssignFunction(pdf_get_versions);
	Gura_AssignFunction(svg_get_versions);
	Gura_AssignFunction(pdf_version_to_string);
	Gura_AssignFunction(svg_version_to_string);
	Gura_AssignFunction(status_to_string);
	Gura_AssignFunction(format_stride_for_width);
	Gura_AssignFunction(debug_reset_static_data);
	Gura_AssignFunction(test);
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
	Gura_AssignCairoValue(DEVICE_TYPE_COGL);
	Gura_AssignCairoValue(DEVICE_TYPE_WIN32);
	Gura_AssignCairoValue(DEVICE_TYPE_INVALID);
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
	Gura_AssignCairoStringValue(MIME_TYPE_UNIQUE_ID);
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

#if defined(HAVE_WINDOWS_H)
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
	return NULL;
}

//-----------------------------------------------------------------------------
// Writer_WindowsDC implementation
//-----------------------------------------------------------------------------
Writer_WindowsDC::~Writer_WindowsDC()
{
	::DeleteDC(_hdc);
}

Stream *Writer_WindowsDC::GetStream()
{
	return NULL;
}
#endif

//-----------------------------------------------------------------------------
// Error handling
//-----------------------------------------------------------------------------
bool IsInvalid(Signal sig, cairo_t *cr)
{
	if (cr == NULL) {
		sig.SetError(ERR_ValueError, "invalid context");
		return true;
	}
	return false;
}

bool IsError(Signal sig, cairo_status_t status)
{
	if (status == CAIRO_STATUS_SUCCESS) return false;
	sig.SetError(ERR_RuntimeError, "%s", ::cairo_status_to_string(status));
	return true;
}

bool IsError(Signal sig, cairo_t *cr)
{
	return IsError(sig, ::cairo_status(cr));
}

bool IsError(Signal sig, cairo_pattern_t *pattern)
{
	return IsError(sig, ::cairo_pattern_status(pattern));
}

bool IsError(Signal sig, cairo_region_t *region)
{
	return IsError(sig, ::cairo_region_status(region));
}

bool IsError(Signal sig, cairo_font_face_t *font_face)
{
	return IsError(sig, ::cairo_font_face_status(font_face));
}

bool IsError(Signal sig, cairo_scaled_font_t *scaled_font)
{
	return IsError(sig, ::cairo_scaled_font_status(scaled_font));
}

bool IsError(Signal sig, cairo_device_t *device)
{
	return IsError(sig, ::cairo_device_status(device));
}

bool IsError(Signal sig, cairo_surface_t *surface)
{
	return IsError(sig, ::cairo_surface_status(surface));
}

bool IsError(Signal sig, cairo_font_options_t *options)
{
	return IsError(sig, ::cairo_font_options_status(options));
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
	for (size_t i = 0; i < NUMBEROF(infoTbl); i++) {
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
	ValueList &valList = value.InitAsList(env);
	valList.reserve(4);
	valList.push_back(Value(rectangle.x));
	valList.push_back(Value(rectangle.y));
	valList.push_back(Value(rectangle.width));
	valList.push_back(Value(rectangle.height));
	valList.push_back(value);
	return value;
}

bool ValueListToRectangle(Signal sig, cairo_rectangle_t &rectangle, const ValueList &valList)
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

bool ValueListToRectangle(Signal sig, cairo_rectangle_int_t &rectangle, const ValueList &valList)
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

Object_matrix *CairoToMatrix(Environment &env, cairo_matrix_t &matrix)
{
	Object_matrix *pObjMatrix = new Object_matrix(env, 3, 3);
	pObjMatrix->SetElement(0, 0, Value(matrix.xx));
	pObjMatrix->SetElement(0, 1, Value(matrix.xy));
	pObjMatrix->SetElement(1, 0, Value(matrix.yx));
	pObjMatrix->SetElement(1, 1, Value(matrix.yy));
	pObjMatrix->SetElement(0, 2, Value(matrix.x0));
	pObjMatrix->SetElement(1, 2, Value(matrix.y0));
	pObjMatrix->SetElement(2, 2, Value(1.));
	return pObjMatrix;
}

bool MatrixToCairo(Signal sig, cairo_matrix_t &matrix, Object_matrix *pObjMatrix)
{
	if (pObjMatrix->GetRows() != 3 || pObjMatrix->GetCols() != 3) {
		sig.SetError(ERR_ValueError, "matrix size must be 3x3");
		return false;
	}
	matrix.xx = pObjMatrix->GetElement(0, 0).GetDouble();
	matrix.xy = pObjMatrix->GetElement(0, 1).GetDouble();
	matrix.yx = pObjMatrix->GetElement(1, 0).GetDouble();
	matrix.yy = pObjMatrix->GetElement(1, 1).GetDouble();
	matrix.x0 = pObjMatrix->GetElement(0, 2).GetDouble();
	matrix.y0 = pObjMatrix->GetElement(1, 2).GetDouble();
	return true;
}

Value CreateValueList(Environment &env, double x1, double x2)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(2);
	valList.push_back(Value(x1));
	valList.push_back(Value(x2));
	return result;
}

Value CreateValueList(Environment &env, double x1, double x2, double x3)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(3);
	valList.push_back(Value(x1));
	valList.push_back(Value(x2));
	valList.push_back(Value(x3));
	return result;
}

Value CreateValueList(Environment &env, double x1, double x2, double x3, double x4)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(4);
	valList.push_back(Value(x1));
	valList.push_back(Value(x2));
	valList.push_back(Value(x3));
	valList.push_back(Value(x4));
	return result;
}

Value CreateValueList(Environment &env,
				double x1, double x2, double x3, double x4, double x5)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(5);
	valList.push_back(Value(x1));
	valList.push_back(Value(x2));
	valList.push_back(Value(x3));
	valList.push_back(Value(x4));
	valList.push_back(Value(x5));
	return result;
}

Value CreateValueList(Environment &env,
				double x1, double x2, double x3, double x4, double x5, double x6)
{
	Value result;
	ValueList &valList = result.InitAsList(env);
	valList.reserve(6);
	valList.push_back(Value(x1));
	valList.push_back(Value(x2));
	valList.push_back(Value(x3));
	valList.push_back(Value(x4));
	valList.push_back(Value(x5));
	valList.push_back(Value(x6));
	return result;
}

cairo_surface_t *CreateSurfaceFromImage(Signal sig, Object_image *pObjImage)
{
	if (!pObjImage->CheckValid(sig)) return NULL;
	if (pObjImage->GetFormat() != Image::FORMAT_RGBA) {
		sig.SetError(ERR_FormatError, "cairo can be applied to image in `rgba format");
		return NULL;
	}
	size_t width = pObjImage->GetWidth();
	size_t height = pObjImage->GetHeight();
	cairo_surface_t *surface = ::cairo_image_surface_create_for_data(
				pObjImage->GetBuffer(), CAIRO_FORMAT_ARGB32,
				static_cast<int>(width), static_cast<int>(height),
				static_cast<int>(pObjImage->GetBytesPerLine()));
	return surface;
}

Gura_EndModule(cairo, cairo)

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
