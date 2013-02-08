//-----------------------------------------------------------------------------
// Gura cairo module
// cairo version 1.12.12
//-----------------------------------------------------------------------------
#include "stdafx.h"

#define Gura_AssignCairoValue(name) \
Gura_AssignValue(name, Value(CAIRO_##name))

Gura_BeginModule(cairo)

const double NUM_PI = 3.14159265358979323846;



//-----------------------------------------------------------------------------
// Object_image_surface implementation
//-----------------------------------------------------------------------------
bool Object_image_surface::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object_surface::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(image));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_image_surface::DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(image))) {
		return Value(Object_image::Reference(_pObjImage.get()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		return Value(_pObjImage->GetWidth());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(_pObjImage->GetHeight());
	}
	evaluatedFlag = false;
	return Object_surface::DoGetProp(sig, pSymbol, evaluatedFlag);
}

//-----------------------------------------------------------------------------
// Gura interfaces for image_surface
//-----------------------------------------------------------------------------
// cairo.image_surface.create(width:number, height:number, color?:color) {block?}
Gura_DeclareClassMethod(image_surface, create)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "color", VTYPE_color, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(image_surface, create)
{
	Object_image *pObjImage = new Object_image(env, Image::FORMAT_RGBA);
	size_t width = args.GetSizeT(0);
	size_t height = args.GetSizeT(1);
	if (!pObjImage->AllocBuffer(sig, width, height, 0xff)) return Value::Null;
	if (args.IsColor(2)) {
		pObjImage->Fill(args.GetColorObj(2));
	}
	cairo_surface_t *surface = ::cairo_image_surface_create_for_data(
				pObjImage->GetBuffer(), CAIRO_FORMAT_ARGB32,
				static_cast<int>(width), static_cast<int>(height),
				static_cast<int>(pObjImage->GetBytesPerLine()));
	Object_image_surface *pObjSurface = new Object_image_surface(surface, pObjImage);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

//#cairo_surface_t *cairo_image_surface_create_from_png(const char *filename);
//#cairo_surface_t *cairo_image_surface_create_from_png_stream(cairo_read_func_t read_func, void *closure);

//#unsigned char *cairo_image_surface_get_data(cairo_surface_t *surface);
//#cairo_format_t cairo_image_surface_get_format(cairo_surface_t *surface);
//#int cairo_image_surface_get_width(cairo_surface_t *surface);
//#int cairo_image_surface_get_height(cairo_surface_t *surface);
//#int cairo_image_surface_get_stride(cairo_surface_t *surface);

Gura_ImplementUserClass(image_surface)
{
	Gura_AssignMethod(image_surface, create);
}

//-----------------------------------------------------------------------------
// Object_Writer_surface implementation
//-----------------------------------------------------------------------------
Object_Writer_surface::~Object_Writer_surface()
{
	if (_surface != NULL) {
		::cairo_surface_destroy(_surface);
		_surface = NULL;
	}
	delete _pWriter; // this must be deleted after surface is destroyed
	_pWriter = NULL;
}

bool Object_Writer_surface::DoDirProp(Signal sig, SymbolSet &symbols)
{
	if (!Object_surface::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_UserSymbol(stream));
	symbols.insert(Gura_UserSymbol(width));
	symbols.insert(Gura_UserSymbol(height));
	return true;
}

Value Object_Writer_surface::DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	Environment &env = *this;
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(stream))) {
		Stream *pStream = _pWriter->GetStream();
		if (pStream == NULL) return Value::Null;
		Object_stream *pObjStream = new Object_stream(env, Stream::Reference(pStream));
		return Value(pObjStream);
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(width))) {
		return Value(_pWriter->GetWidth());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(height))) {
		return Value(_pWriter->GetHeight());
	}
	evaluatedFlag = false;
	return Object_surface::DoGetProp(sig, pSymbol, evaluatedFlag);
}

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

//#cairo_surface_t *cairo_ps_surface_create(const char *filename, double width_in_points, double height_in_points);
//#cairo_surface_t *cairo_ps_surface_create_for_stream(cairo_write_func_t write_func, void *closure, double width_in_points, double height_in_points);
//#void cairo_ps_surface_restrict_to_level(cairo_surface_t *surface, cairo_ps_level_t level);
//#void cairo_ps_get_levels(cairo_ps_level_t const **levels, int *num_levels);
//#const char *cairo_ps_level_to_string(cairo_ps_level_t level);
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

//-----------------------------------------------------------------------------
// Object_recording_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for recording_surface
//-----------------------------------------------------------------------------
//#cairo_surface_t *cairo_recording_surface_create(cairo_content_t content, const cairo_rectangle_t *extents);
//#void cairo_recording_surface_ink_extents(cairo_surface_t *surface, double *x0, double *y0, double *width, double *height);
//#cairo_bool_t cairo_recording_surface_get_extents(cairo_surface_t *surface, cairo_rectangle_t *extents);

Gura_ImplementUserClass(recording_surface)
{
}

//-----------------------------------------------------------------------------
// Object_win32_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for win32_surface
//-----------------------------------------------------------------------------
#if defined(HAVE_WINDOWS_H)
// cairo.win32_surface.emf_create(filename:string, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareClassMethod(win32_surface, create_emf)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "filename", VTYPE_string);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(win32_surface, create_emf)
{
	double width = args.GetDouble(1);
	double height = args.GetDouble(2);
	RECT rc;
	rc.left = 0, rc.top = 0;
	rc.right = static_cast<long>(width * 20);	// unit: 1/20pt
	rc.bottom = static_cast<long>(height * 20);	// unit: 1/20pt
	HDC hdc = ::CreateEnhMetaFile(NULL, args.GetString(0), &rc, "EMF by Gura\0");
	::StartPage(hdc);
	//::SetMapMode(hdc, MM_TWIPS);				// 1 unit = 1/20pt
	::SetMapMode(hdc, MM_HIMETRIC);				// 1 unit = 0.01mm
	//::SetWindowOrgEx(hdc, 0, height * 20, NULL);
	//::MoveToEx(hdc, 0, 0, NULL);
	//::LineTo(hdc, 1000, 1000);
	//::MoveToEx(hdc, 0, 0, NULL);
	//::LineTo(hdc, 1000, -1000);
	Writer_EnhMetaFile *pWriter = new Writer_EnhMetaFile(sig, width, height, hdc);
	cairo_surface_t *surface = ::cairo_win32_printing_surface_create(hdc);
	Object_surface *pObjSurface = new Object_win32_surface(surface, pWriter);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}

// cairo.win32_surface.create_printing(printer_name:string, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareClassMethod(win32_surface, create_printing)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "printer_name", VTYPE_string);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(win32_surface, create_printing)
{
	const char *driverName = "WINSPOOL\0";
	const char *printerName = args.GetString(0);
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
	double width = args.GetDouble(1), height = args.GetDouble(2);
	RECT rc;
	rc.left = 0, rc.top = 0;
	rc.right = static_cast<long>(width * 20);	// unit: 1/20pt
	rc.bottom = static_cast<long>(height * 20);	// unit: 1/20pt
	HDC hdc = ::CreateDC(driverName, printerName, pPrinterInfo2->pPortName, NULL);
	::SetMapMode(hdc, MM_TWIPS);				// 1 unit = 1/20pt
	//::SetMapMode(hdc, MM_HIMETRIC);			// 1 unit = 0.01mm
	Writer_WindowsDC *pWriter = new Writer_WindowsDC(sig, width, height, hdc);
	cairo_surface_t *surface = ::cairo_win32_printing_surface_create(hdc);
	Object_surface *pObjSurface = new Object_win32_surface(surface, pWriter);
	return ReturnValue(env, sig, args, Value(pObjSurface));
}
#endif

//#cairo_surface_t *cairo_win32_surface_create(HDC hdc);
//#cairo_surface_t *cairo_win32_surface_create_with_dib(cairo_format_t format, int width, int height);
//#cairo_surface_t *cairo_win32_surface_create_with_ddb(HDC hdc, cairo_format_t format, int width, int height);
//#cairo_surface_t *cairo_win32_printing_surface_create(HDC hdc);
//#HDC cairo_win32_surface_get_dc(cairo_surface_t *surface);
//#cairo_surface_t *cairo_win32_surface_get_image(cairo_surface_t *surface);

Gura_ImplementUserClass(win32_surface)
{
#if defined(HAVE_WINDOWS_H)
	Gura_AssignMethod(win32_surface, create_emf);
	Gura_AssignMethod(win32_surface, create_printing);
#endif
}

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

//-----------------------------------------------------------------------------
// Object_quartz_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for quartz_surface
//-----------------------------------------------------------------------------
//#cairo_surface_t *cairo_quartz_surface_create(cairo_format_t format, unsigned int width, unsigned int height);
//#cairo_surface_t *cairo_quartz_surface_create_for_cg_context(CGContextRef cgContext, unsigned int width, unsigned int height);
//#CGContextRef cairo_quartz_surface_get_cg_context (cairo_surface_t *surface);

Gura_ImplementUserClass(quartz_surface)
{
}

//-----------------------------------------------------------------------------
// Object_xcb_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for xcb_surface
//-----------------------------------------------------------------------------
//#cairo_surface_t *cairo_xcb_surface_create(xcb_connection_t *connection, xcb_drawable_t drawable, xcb_visualtype_t *visual, int width, int height);
//#cairo_surface_t *cairo_xcb_surface_create_for_bitmap(xcb_connection_t *connection, xcb_screen_t *screen, xcb_pixmap_t bitmap, int width, int height);
//#cairo_surface_t *cairo_xcb_surface_create_with_xrender_format(xcb_connection_t *connection, xcb_screen_t *screen, xcb_drawable_t drawable, xcb_render_pictforminfo_t *format, int width, int height);
//#void cairo_xcb_surface_set_size(cairo_surface_t *surface, int width, int height);
//#void cairo_xcb_surface_set_drawable(cairo_surface_t *surface, xcb_drawable_t drawable, int width, int height);
//#xcb_connection_t *cairo_xcb_device_get_connection(cairo_device_t *device);
//#void cairo_xcb_device_debug_cap_xrender_version(cairo_device_t *device, int major_version, int minor_version);
//#void cairo_xcb_device_debug_cap_xshm_version(cairo_device_t *device, int major_version, int minor_version);
//#int cairo_xcb_device_debug_get_precision(cairo_device_t *device);
//#void cairo_xcb_device_debug_set_precision(cairo_device_t *device, int precision);

Gura_ImplementUserClass(xcb_surface)
{
}

//-----------------------------------------------------------------------------
// Object_xlib_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for xlib_surface
//-----------------------------------------------------------------------------
//#cairo_surface_t *cairo_xlib_surface_create(Display *dpy, Drawable drawable, Visual *visual, int width, int height);
//#cairo_surface_t *cairo_xlib_surface_create_for_bitmap(Display *dpy, Pixmap bitmap, Screen *screen, int width, int height);
//#void cairo_xlib_surface_set_size(cairo_surface_t *surface, int width, int height);
//#Display *cairo_xlib_surface_get_display(cairo_surface_t *surface);
//#Screen *cairo_xlib_surface_get_screen(cairo_surface_t *surface);
//#void cairo_xlib_surface_set_drawable(cairo_surface_t *surface, Drawable drawable, int width, int height);
//#Drawable cairo_xlib_surface_get_drawable(cairo_surface_t *surface);
//#Visual *cairo_xlib_surface_get_visual(cairo_surface_t *surface);
//#int cairo_xlib_surface_get_width(cairo_surface_t *surface);
//#int cairo_xlib_surface_get_height(cairo_surface_t *surface);
//#int cairo_xlib_surface_get_depth(cairo_surface_t *surface);
//#void cairo_xlib_device_debug_cap_xrender_version(cairo_device_t *device, int major_version, int minor_version);
//#int cairo_xlib_device_debug_get_precision(cairo_device_t *device);
//#void cairo_xlib_device_debug_set_precision(cairo_device_t *device, int precision);

//#cairo_surface_t *   cairo_xlib_surface_create_with_xrender_format(Display *dpy, Drawable drawable, Screen *screen, XRenderPictFormat *format, int width, int height);
//#XRenderPictFormat * cairo_xlib_surface_get_xrender_format(cairo_surface_t *surface);

Gura_ImplementUserClass(xlib_surface)
{
}

//-----------------------------------------------------------------------------
// Object_script_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for script_surface
//-----------------------------------------------------------------------------
//#cairo_device_t *cairo_script_create(const char *filename);
//#cairo_device_t *cairo_script_create_for_stream(cairo_write_func_t write_func, void *closure);
//#cairo_status_t cairo_script_from_recording_surface(cairo_device_t *script, cairo_surface_t *recording_surface);
//#cairo_script_mode_t cairo_script_get_mode(cairo_device_t *script);
//#void cairo_script_set_mode(cairo_device_t *script, cairo_script_mode_t mode);
//#cairo_surface_t *cairo_script_surface_create(cairo_device_t *script, cairo_content_t content, double width, double height);
//#cairo_surface_t *cairo_script_surface_create_for_target(cairo_device_t *script, cairo_surface_t *target);
//#void cairo_script_write_comment(cairo_device_t *script, const char *comment, int len);

Gura_ImplementUserClass(script_surface)
{
}

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
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
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
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
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
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
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
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
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
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
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
	Value result(new Object_pattern(pattern));
	return ReturnValue(env, sig, args, result);
}

//#cairo_pattern_t *cairo_pattern_create_raster_source(void *user_data, cairo_content_t content, int width, int height);

//#void cairo_raster_source_pattern_set_callback_data(cairo_pattern_t *pattern, void *data);
//#void *cairo_raster_source_pattern_get_callback_data(cairo_pattern_t *pattern);
//#void cairo_raster_source_pattern_set_acquire(cairo_pattern_t *pattern, cairo_raster_source_acquire_func_t acquire, cairo_raster_source_release_func_t release);
//#void cairo_raster_source_pattern_get_acquire(cairo_pattern_t *pattern, cairo_raster_source_acquire_func_t *acquire, cairo_raster_source_release_func_t *release);
//#void cairo_raster_source_pattern_set_snapshot(cairo_pattern_t *pattern, cairo_raster_source_snapshot_func_t snapshot);
//#cairo_raster_source_snapshot_func_t cairo_raster_source_pattern_get_snapshot(cairo_pattern_t *pattern);
//#void cairo_raster_source_pattern_set_copy(cairo_pattern_t *pattern, cairo_raster_source_copy_func_t copy);
//#cairo_raster_source_copy_func_t cairo_raster_source_pattern_get_copy(cairo_pattern_t *pattern);
//#void cairo_raster_source_pattern_set_finish(cairo_pattern_t *pattern, cairo_raster_source_finish_func_t finish);
//#cairo_raster_source_finish_func_t cairo_raster_source_pattern_get_finish(cairo_pattern_t *pattern);

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
	Object_surface *pObjSurface =
			new Object_surface(::cairo_surface_reference(surface));
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

// cairo.pattern#get_radial_circles():reduce
Gura_DeclareMethod(pattern, get_radial_circles)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
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

//#cairo_pattern_t *cairo_pattern_create_mesh(void);
//#void cairo_mesh_pattern_begin_patch(cairo_pattern_t *pattern);
//#void cairo_mesh_pattern_end_patch(cairo_pattern_t *pattern);
//#void cairo_mesh_pattern_move_to(cairo_pattern_t *pattern, double x, double y);
//#void cairo_mesh_pattern_line_to(cairo_pattern_t *pattern, double x, double y);
//#void cairo_mesh_pattern_curve_to(cairo_pattern_t *pattern, double x1, double y1, double x2, double y2, double x3, double y3);
//#void cairo_mesh_pattern_set_control_point(cairo_pattern_t *pattern, unsigned int point_num, double x, double y);
//#void cairo_mesh_pattern_set_corner_color_rgb(cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue);
//#void cairo_mesh_pattern_set_corner_color_rgba(cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue, double alpha);
//#cairo_status_t cairo_mesh_pattern_get_patch_count(cairo_pattern_t *pattern, unsigned int *count);
//#cairo_path_t *cairo_mesh_pattern_get_path(cairo_pattern_t *pattern, unsigned int patch_num);
//#cairo_status_t cairo_mesh_pattern_get_control_point(cairo_pattern_t *pattern, unsigned int patch_num, unsigned int point_num, double *x, double *y);
//#cairo_status_t cairo_mesh_pattern_get_corner_color_rgba(cairo_pattern_t *pattern, unsigned int patch_num, unsigned int corner_num, double *red, double *green, double *blue, double *alpha);

//#cairo_pattern_t *cairo_pattern_reference(cairo_pattern_t *pattern);
//#void cairo_pattern_destroy(cairo_pattern_t *pattern);
//#cairo_status_t cairo_pattern_status(cairo_pattern_t *pattern);

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

//#cairo_pattern_type_t cairo_pattern_get_type(cairo_pattern_t *pattern);
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
	Gura_AssignMethod(pattern, set_extend);
	Gura_AssignMethod(pattern, get_extend);
	Gura_AssignMethod(pattern, set_filter);
	Gura_AssignMethod(pattern, get_filter);
	Gura_AssignMethod(pattern, set_matrix);
	Gura_AssignMethod(pattern, get_matrix);
}

//-----------------------------------------------------------------------------
// Object_path implementation
//-----------------------------------------------------------------------------
Object_path::~Object_path()
{
	::cairo_path_destroy(_path);
}

Object *Object_path::Clone() const
{
	return NULL;
}

String Object_path::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.path>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for path
//-----------------------------------------------------------------------------
// implementation of class path
Gura_ImplementUserClass(path)
{
}

//-----------------------------------------------------------------------------
// Object_glyph implementation
//-----------------------------------------------------------------------------
Object_glyph::~Object_glyph()
{
}

Object *Object_glyph::Clone() const
{
	return NULL;
}

String Object_glyph::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.glyph>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for glyph
//-----------------------------------------------------------------------------
//#cairo_glyph_t *cairo_glyph_allocate(int num_glyphs);
//#void cairo_glyph_free(cairo_glyph_t *glyphs);

// implementation of class glyph
Gura_ImplementUserClass(glyph)
{
}

//-----------------------------------------------------------------------------
// Object_text_cluster implementation
//-----------------------------------------------------------------------------
Object_text_cluster::~Object_text_cluster()
{
}

Object *Object_text_cluster::Clone() const
{
	return NULL;
}

String Object_text_cluster::ToString(Signal sig, bool exprFlag)
{
	return String("<cairo.text_cluster>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for text_cluster
//-----------------------------------------------------------------------------
//#cairo_text_cluster_t *cairo_text_cluster_allocate(int num_clusters);
//#void cairo_text_cluster_free(cairo_text_cluster_t *clusters);

// implementation of class text_cluster
Gura_ImplementUserClass(text_cluster)
{
}

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

//#int cairo_format_stride_for_width(cairo_format_t format, int width);
//#cairo_surface_t *cairo_image_surface_create(cairo_format_t format, int width, int height);
//#const char *cairo_status_to_string(cairo_status_t status);
//#void cairo_debug_reset_static_data(void);

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
}

Gura_ModuleTerminate()
{
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
