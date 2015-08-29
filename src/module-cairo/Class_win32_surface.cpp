#include "stdafx.h"

Gura_BeginModuleScope(cairo)

//-----------------------------------------------------------------------------
// Object_win32_surface implementation
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Gura interfaces for win32_surface
//-----------------------------------------------------------------------------
#if defined(GURA_ON_MSWIN)
// cairo.win32_surface.emf_create(filename:string, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareClassMethod(win32_surface, create_emf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "filename", VTYPE_string);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(win32_surface, create_emf)
{
	Signal &sig = env.GetSignal();
	double width = arg.GetDouble(1);
	double height = arg.GetDouble(2);
	RECT rc;
	rc.left = 0, rc.top = 0;
	rc.right = static_cast<long>(width * 20);	// unit: 1/20pt
	rc.bottom = static_cast<long>(height * 20);	// unit: 1/20pt
	HDC hdc = ::CreateEnhMetaFile(nullptr, arg.GetString(0), &rc, "EMF by Gura\0");
	::StartPage(hdc);
	//::SetMapMode(hdc, MM_TWIPS);				// 1 unit = 1/20pt
	::SetMapMode(hdc, MM_HIMETRIC);				// 1 unit = 0.01mm
	//::SetWindowOrgEx(hdc, 0, height * 20, nullptr);
	//::MoveToEx(hdc, 0, 0, nullptr);
	//::LineTo(hdc, 1000, 1000);
	//::MoveToEx(hdc, 0, 0, nullptr);
	//::LineTo(hdc, 1000, -1000);
	Writer_EnhMetaFile *pWriter = new Writer_EnhMetaFile(sig, width, height, hdc);
	cairo_surface_t *surface = ::cairo_win32_printing_surface_create(hdc);
	Object_surface *pObjSurface = new Object_win32_surface(surface, pWriter);
	return ReturnValue(env, arg, Value(pObjSurface));
}

// cairo.win32_surface.create_printing(printer_name:string, width_in_points:number, height_in_points:number) {block?}
Gura_DeclareClassMethod(win32_surface, create_printing)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "printer_name", VTYPE_string);
	DeclareArg(env, "width_in_points", VTYPE_number);
	DeclareArg(env, "height_in_points", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(win32_surface, create_printing)
{
	Signal &sig = env.GetSignal();
	const char *driverName = nullptr;
	const char *printerName = arg.GetString(0);
	char printerNameDefault[MAX_PATH];
	BYTE printerInfoBuff[16384];
	PRINTER_INFO_2 *pPrinterInfo2 = reinterpret_cast<PRINTER_INFO_2 *>(printerInfoBuff);
	if (::strcmp(printerName, "") == 0) {
		DWORD cch = ArraySizeOf(printerNameDefault) - 1;
		if (!::GetDefaultPrinter(printerNameDefault, &cch)) {
			sig.SetError(ERR_IOError, "failed to get a default printer");
			return Value::Nil;
		}
		printerName = printerNameDefault;
	}
	do {
		HANDLE hPrinter = nullptr;
		if (!::OpenPrinter(const_cast<char *>(printerName), &hPrinter, nullptr)) {
			sig.SetError(ERR_IOError, "failed to open printer handler");
			return Value::Nil;
		}
		DWORD cbNeeded = sizeof(printerInfoBuff);
		if (!::GetPrinter(hPrinter, 2, printerInfoBuff, sizeof(printerInfoBuff), &cbNeeded)) {
			sig.SetError(ERR_IOError, "failed to get printer information");
			return Value::Nil;
		}
		::ClosePrinter(hPrinter);
	} while (0);
	double width = arg.GetDouble(1), height = arg.GetDouble(2);
	RECT rc;
	rc.left = 0, rc.top = 0;
	rc.right = static_cast<long>(width * 20);	// unit: 1/20pt
	rc.bottom = static_cast<long>(height * 20);	// unit: 1/20pt
	HDC hdc = ::CreateDC(driverName, printerName, pPrinterInfo2->pPortName, nullptr);
	DOCINFO di;
	::memset(&di, 0x00, sizeof(di));
	di.cbSize = sizeof(DOCINFO);
	di.lpszDocName = "cairo";
	::StartDoc(hdc, &di);
	::SetMapMode(hdc, MM_TWIPS);				// 1 unit = 1/20pt
	//::SetMapMode(hdc, MM_HIMETRIC);			// 1 unit = 0.01mm
	Writer_WindowsDC *pWriter = new Writer_WindowsDC(sig, width, height, hdc);
	cairo_surface_t *surface = ::cairo_win32_printing_surface_create(hdc);
	Object_surface *pObjSurface = new Object_win32_surface(surface, pWriter);
	return ReturnValue(env, arg, Value(pObjSurface));
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
#if defined(GURA_ON_MSWIN)
	Gura_AssignMethod(win32_surface, create_emf);
	Gura_AssignMethod(win32_surface, create_printing);
#endif
}

Gura_EndModuleScope(cairo)
