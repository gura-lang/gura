//-----------------------------------------------------------------------------
// Gura module: canvas
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(canvas)

//-----------------------------------------------------------------------------
// Anchor
//-----------------------------------------------------------------------------
void DeclareAnchorAttrs(Function *pFunc)
{
	pFunc->DeclareAttr(Gura_UserSymbol(n));
	pFunc->DeclareAttr(Gura_UserSymbol(ne));
	pFunc->DeclareAttr(Gura_UserSymbol(e));
	pFunc->DeclareAttr(Gura_UserSymbol(se));
	pFunc->DeclareAttr(Gura_UserSymbol(s));
	pFunc->DeclareAttr(Gura_UserSymbol(sw));
	pFunc->DeclareAttr(Gura_UserSymbol(w));
	pFunc->DeclareAttr(Gura_UserSymbol(nw));
	pFunc->DeclareAttr(Gura_UserSymbol(c));
}

Anchor GetAnchor(const SymbolSet &attrs)
{
	Anchor anchor = ANCHOR_SW;
	if (attrs.IsSet(Gura_UserSymbol(n))) {
		anchor = ANCHOR_N;
	} else if (attrs.IsSet(Gura_UserSymbol(ne))) {
		anchor = ANCHOR_NE;
	} else if (attrs.IsSet(Gura_UserSymbol(e))) {
		anchor = ANCHOR_E;
	} else if (attrs.IsSet(Gura_UserSymbol(se))) {
		anchor = ANCHOR_SE;
	} else if (attrs.IsSet(Gura_UserSymbol(s))) {
		anchor = ANCHOR_S;
	} else if (attrs.IsSet(Gura_UserSymbol(sw))) {
		anchor = ANCHOR_SW;
	} else if (attrs.IsSet(Gura_UserSymbol(w))) {
		anchor = ANCHOR_W;
	} else if (attrs.IsSet(Gura_UserSymbol(nw))) {
		anchor = ANCHOR_NW;
	} else if (attrs.IsSet(Gura_UserSymbol(c))) {
		anchor = ANCHOR_C;
	}
	return anchor;
}

//-----------------------------------------------------------------------------
// Color
//-----------------------------------------------------------------------------
Color::Color(Signal &sig, const Value &value)
{
	if (value.Is_list()) {
		const ValueList &valList = value.GetList();
		size_t len = valList.size();
		if (len < 3) {
			sig.SetError(ERR_ValueError, "insufficient list value for color");
			return;
		}
		_red = valList[0].GetUChar();
		_green = valList[1].GetUChar();
		_blue = valList[2].GetUChar();
	} else if (value.Is_string()) {
		const char *str = value.GetString();
		if (*str == '#') str++;
		char *strp;
		ULong num = ::strtoul(str, &strp, 16);
		if (strp - str != 6) {
			sig.SetError(ERR_ValueError, "invalid format of color string");
			return;
		}
		*this = Color(
			static_cast<UChar>(num >> 16),
			static_cast<UChar>(num >> 8),
			static_cast<UChar>(num >> 0));
	} else if (value.Is_symbol()) {
		const Symbol *pSymbol = value.GetSymbol();
		if (pSymbol->IsIdentical(Gura_UserSymbol(black))) {
			*this = Color(0, 0, 0);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(blue))) {
			*this = Color(0, 0, 255);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(green))) {
			*this = Color(0, 255, 0);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(light_blue))) {
			*this = Color(0, 255, 255);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(red))) {
			*this = Color(255, 0, 0);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(cyan))) {
			*this = Color(255, 0, 255);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(yellow))) {
			*this = Color(255, 255, 0);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(white))) {
			*this = Color(255, 255, 255);
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(grey))) {
			*this = Color(128, 128, 128);
		} else {
			sig.SetError(ERR_ValueError, "invalid color symbol %s", pSymbol->GetName());
			return;
		}
	} else {
		*this = Color(0, 0, 0);
	}
}

//-----------------------------------------------------------------------------
// Device
//-----------------------------------------------------------------------------
Device::~Device()
{
}

Value Device::Initialize(Environment &env, const Function *pFuncBlock)
{
	Signal &sig = env.GetSignal();
	SetPen(sig, Value(Gura_UserSymbol(black)), 1., Gura_UserSymbol(solid));
	SetFont(sig, 8.0, Gura_UserSymbol(default), Gura_UserSymbol(normal),
									Gura_UserSymbol(normal), "");
	Fill(sig, Value(Gura_UserSymbol(white)));
	Object_Canvas *pObj = new Object_Canvas(env, this);
	Value result(pObj);
	if (pFuncBlock != nullptr) {
		AutoPtr<Environment> pEnvBlock(new Environment(&env, ENVTYPE_block));
		//ValueList valList(result);
		AutoPtr<Argument> pArg(new Argument(pFuncBlock));
		if (!pArg->StoreValue(env, result)) return Value::Nil;
		pFuncBlock->Eval(*pEnvBlock, *pArg);
		
		// temporary handling before GC is correctly implemented
		pObj->Device().Close();
		
		result = Value::Nil;
	}
	return result;
}

//-----------------------------------------------------------------------------
// Device_EnhMetaFile
//-----------------------------------------------------------------------------
Device_EnhMetaFile::Device_EnhMetaFile(Signal &sig, const char *fileName,
		Number width, Number height, const char *appName, const char *imageName) :
														Device(width, height)
{
	_rc.left = 0, _rc.top = 0;
	_rc.right = static_cast<long>(width * 100);		// unit: 0.01mm
	_rc.bottom = static_cast<long>(height * 100);	// unit: 0.01mm
	PrepareSimpleLogfont(&_lf, 10, "");
	char *description = nullptr;
	if (appName != nullptr) {
		size_t lenAppName = ::strlen(appName);
		if (imageName == nullptr) {
			description = new char[lenAppName + 2];
			::strcpy(description, appName);
			description[lenAppName + 1] = '\0';
		} else {
			size_t lenImageName = ::strlen(imageName);
			description = new char[lenAppName + lenImageName + 3];
			::strcpy(description, appName);
			::strcpy(description + lenAppName + 1, imageName);
			description[lenAppName + lenImageName + 2] = '\0';
		}
	}
	_hdc = ::CreateEnhMetaFile(nullptr, fileName, &_rc, description);
	_rc.bottom = -_rc.bottom;
	delete[] description;
	// SetViewPortOrg doesn't work correctly with some devices
	if (_hdc == nullptr) {
		sig.SetError(ERR_IOError, "failed to create an enhanced meta file");
		return;
	}
	::SetMapMode(_hdc, MM_HIMETRIC);				// 1 unit = 0.01 mm
}

Device_EnhMetaFile::~Device_EnhMetaFile()
{
	Close();
}

const char *Device_EnhMetaFile::GetName() const
{
	return "EnhancedMetaFile";
}

void Device_EnhMetaFile::Close()
{
	if (_hdc == nullptr) return;
	//::printf("CloseEnhMetaFile\n");
	HENHMETAFILE hEmf = ::CloseEnhMetaFile(_hdc);
	::DeleteEnhMetaFile(hEmf);
	_hdc = nullptr;
}

void Device_EnhMetaFile::Fill(Signal &sig, const Value &color)
{
	Color colorWk(sig, color);
	if (sig.IsSignalled()) return;
	::FillRect(_hdc, &_rc, ::CreateSolidBrush(colorWk.ToWin32()));
}

void Device_EnhMetaFile::SetPen(Signal &sig,
					const Value &color, Number width, const Symbol *pSymbol)
{
	if (_hdc == nullptr) return;
	if (color.IsInvalid()) {
		::SelectObject(_hdc, ::CreatePen(PS_NULL, 0, RGB(0, 0, 0)));
		return;
	}
	int fnPenStyle = PS_SOLID;
	if (pSymbol->IsIdentical(Gura_UserSymbol(solid))) {
		fnPenStyle = PS_SOLID;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(dash))) {
		fnPenStyle = PS_DASH;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(dot))) {
		fnPenStyle = PS_DOT;
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(dot_dash))) {
		fnPenStyle = PS_DASHDOT;
	} else {
		sig.SetError(ERR_ValueError, "invalid pen style %s", pSymbol->GetName());
		return;
	}
	int nWidth = static_cast<int>(width * 100 * 25.4 * 0.25 / 72);
	Color colorWk(sig, color);
	if (sig.IsSignalled()) return;
	::SelectObject(_hdc, ::CreatePen(fnPenStyle, nWidth, colorWk.ToWin32()));
}

void Device_EnhMetaFile::SetBrush(Signal &sig, const Value &color, const Symbol *pSymbol)
{
	if (_hdc == nullptr) return;
	if (color.IsInvalid()) {
		::SelectObject(_hdc, reinterpret_cast<HBRUSH>(::GetStockObject(NULL_BRUSH)));
		return;
	}
	Color colorWk(sig, color);
	if (sig.IsSignalled()) return;
	if (pSymbol->IsIdentical(Gura_UserSymbol(solid))) {
		::SelectObject(_hdc, ::CreateSolidBrush(colorWk.ToWin32()));
	} else {
		int fnStyle = 0;
		if (pSymbol->IsIdentical(Gura_UserSymbol(bdiagonal))) {
			fnStyle = HS_BDIAGONAL;
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(cross))) {
			fnStyle = HS_CROSS;
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(diagcross))) {
			fnStyle = HS_DIAGCROSS;
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(fdiagonal))) {
			fnStyle = HS_FDIAGONAL;
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(horizontal))) {
			fnStyle = HS_HORIZONTAL;
		} else if (pSymbol->IsIdentical(Gura_UserSymbol(vertical))) {
			fnStyle = HS_VERTICAL;
		} else {
			sig.SetError(ERR_ValueError, "invalid brush style %s", pSymbol->GetName());
			return;
		}
		::SelectObject(_hdc, ::CreateHatchBrush(fnStyle, colorWk.ToWin32()));
	}
}

void Device_EnhMetaFile::SetFont(Signal &sig, Number height,
			const Symbol *family, const Symbol *style, const Symbol *weight,
			const char *faceName)
{
	// 1pt = 25.4/72mm = 0.353mm
	PrepareSimpleLogfont(&_lf, static_cast<int>(height * 100), "");
	if (family->IsIdentical(Gura_UserSymbol(default))) {
		_lf.lfPitchAndFamily = FF_DONTCARE;
	} else if (family->IsIdentical(Gura_UserSymbol(decorative))) {
		_lf.lfPitchAndFamily = FF_DECORATIVE;
	} else if (family->IsIdentical(Gura_UserSymbol(roman))) {
		_lf.lfPitchAndFamily = FF_ROMAN;
	} else if (family->IsIdentical(Gura_UserSymbol(script))) {
		_lf.lfPitchAndFamily = FF_SCRIPT;
	} else if (family->IsIdentical(Gura_UserSymbol(swiss))) {
		_lf.lfPitchAndFamily = FF_SWISS;
	} else if (family->IsIdentical(Gura_UserSymbol(modern))) {
		_lf.lfPitchAndFamily = FF_MODERN;
	} else if (family->IsIdentical(Gura_UserSymbol(teletype))) {
		_lf.lfPitchAndFamily = FF_SWISS | FIXED_PITCH;
	} else {
		sig.SetError(ERR_ValueError, "invalid family symbol %s", family->GetName());
		return;
	}
	if (style->IsIdentical(Gura_UserSymbol(italic))) {
		_lf.lfItalic = TRUE;
	} else if (style->IsIdentical(Gura_UserSymbol(slant))) {
		_lf.lfStrikeOut = TRUE;
	}
	if (weight->IsIdentical(Gura_UserSymbol(normal))) {
		_lf.lfWeight = FW_NORMAL;
	} else if (weight->IsIdentical(Gura_UserSymbol(light))) {
		_lf.lfWeight = FW_LIGHT;
	} else if (weight->IsIdentical(Gura_UserSymbol(bold))) {
		_lf.lfWeight = FW_BOLD;
	} else {
		sig.SetError(ERR_ValueError, "invalid weight symbol %s", weight->GetName());
		return;
	}
	HFONT hFont = ::CreateFontIndirect(&_lf);
	::SelectObject(_hdc, hFont);
}

void Device_EnhMetaFile::SetTextColor(Signal &sig, const Value &color)
{
	Color colorWk(sig, color);
	if (sig.IsSignalled()) return;
	::SetTextColor(_hdc, colorWk.ToWin32());
}

void Device_EnhMetaFile::Text(Signal &sig, Number x, Number y,
				const char *text, Number wdBound, Number htBound, Anchor anchor)
{
	if (_hdc == nullptr) return;
	RECT rc;
	rc.left = rc.right = rc.top = rc.bottom = 0;
	::DrawText(_hdc, text, -1, &rc, DT_CALCRECT);
	wdBound *= 100, htBound *= 100;
	if (wdBound <= 0) wdBound = rc.right;
	if (htBound <= 0) htBound = -rc.bottom;
	MakeRect(&rc, ToPoint(x, y),
				static_cast<int>(wdBound), static_cast<int>(htBound), anchor);
	//MakeRect(&rc, ToPoint(_xCur, _yCur), rc.right - rc.left, rc.top - rc.bottom, anchor);
	::SetTextAlign(_hdc, TA_TOP);
	::DrawText(_hdc, text, -1, &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//::DrawText(_hdc, text, -1, &rc, DT_SINGLELINE);
}

void Device_EnhMetaFile::TextRot(Signal &sig, Number x, Number y, const char *text, Number angle)
{
	if (_hdc == nullptr) return;
	POINT pt = ToPoint(x, y);
	LOGFONT lf = _lf;
	lf.lfEscapement = -static_cast<int>(angle * 10);
	lf.lfOrientation = lf.lfEscapement;
	HFONT hFont = ::CreateFontIndirect(&lf);
	HFONT hFontOld = reinterpret_cast<HFONT>(::SelectObject(_hdc, hFont));
	::SetTextAlign(_hdc, TA_BOTTOM);
	::TextOut(_hdc, pt.x, pt.y, text, static_cast<int>(::strlen(text)));
	::SelectObject(_hdc, hFontOld);
}

void Device_EnhMetaFile::Line(Signal &sig, Number x1, Number y1, Number x2, Number y2)
{
	if (_hdc == nullptr) return;
	POINT pt1 = ToPoint(x1, y1);
	POINT pt2 = ToPoint(x2, y2);
	::MoveToEx(_hdc, pt1.x, pt1.y, nullptr);
	::LineTo(_hdc, pt2.x, pt2.y);
}

void Device_EnhMetaFile::Rectangle(Signal &sig, Number x, Number y,
									Number width, Number height, Anchor anchor)
{
	if (_hdc == nullptr) return;
	RECT rc;
	MakeRect(&rc, ToPoint(x, y),
		static_cast<int>(width * 100), static_cast<int>(height * 100), anchor);
	::Rectangle(_hdc, rc.left, rc.top, rc.right, rc.bottom);
}

void Device_EnhMetaFile::Ellipse(Signal &sig, Number x, Number y,
									Number width, Number height, Anchor anchor)
{
	if (_hdc == nullptr) return;
	RECT rc;
	MakeRect(&rc, ToPoint(x, y),
		static_cast<int>(width * 100), static_cast<int>(height * 100), anchor);
	::Ellipse(_hdc, rc.left, rc.top, rc.right, rc.bottom);
}

void Device_EnhMetaFile::Pie(Signal &sig, Number x, Number y, Number width, Number height,
								Number degStart, Number degEnd, Anchor anchor)
{
	if (_hdc == nullptr) return;
	RECT rc;
	MakeRect(&rc, ToPoint(x, y),
		static_cast<int>(width * 100), static_cast<int>(height * 100), anchor);
	double radStart = degStart * 3.1415926 / 180;
	double radEnd = degEnd * 3.1415926 / 180;
	int xCenter = (rc.left + rc.right) / 2;
	int yCenter = (rc.top + rc.bottom) / 2;
	double lenBeam = 100000;
	int xStart = static_cast<int>(lenBeam * ::cos(radStart) + xCenter);
	int yStart = static_cast<int>(lenBeam * ::sin(radStart) + yCenter);
	int xEnd = static_cast<int>(xCenter + ::cos(radEnd) * lenBeam);
	int yEnd = static_cast<int>(yCenter + ::sin(radEnd) * lenBeam);
	::Pie(_hdc, rc.left, rc.top, rc.right, rc.bottom, xStart, yStart, xEnd, yEnd);
}

void Device_EnhMetaFile::Polygon(Signal &sig,
					const ValueList &xs, const ValueList &ys, bool closeFlag)
{
	if (_hdc == nullptr) return;
	int cnt = static_cast<int>((xs.size() < ys.size())? xs.size() : ys.size());
	if (cnt == 0) return;
	POINT *ptList = new POINT[cnt];
	ValueList::const_iterator xp = xs.begin();
	ValueList::const_iterator yp = ys.begin();
	int i = 0;
	for (POINT *ptpDst = ptList; i < cnt; xp++, yp++, ptpDst++, i++) {
		*ptpDst = ToPoint(xp->GetNumber(), yp->GetNumber());
	}
	if (closeFlag) {
		::Polygon(_hdc, ptList, cnt);
	} else {
		::Polyline(_hdc, ptList, cnt);
	}
	delete[] ptList;
}

void Device_EnhMetaFile::Polygon(Signal &sig, const ValueList &pts, bool closeFlag)
{
	if (_hdc == nullptr) return;
	int cnt = static_cast<int>(pts.size());
	if (cnt == 0) return;
	POINT *ptList = new POINT[cnt];
	ValueList::const_iterator ptp = pts.begin();
	POINT *ptpDst = ptList;
	foreach_const (ValueList, pValue, pts) {
		if (!pValue->Is_list()) {
			sig.SetError(ERR_ValueError, "element of point list must be a list");
			return;
		}
		const ValueList &valList = pValue->GetList();
		if (valList.size() != 2) {
			sig.SetError(ERR_ValueError, "wrong format of point list");
			return;
		}
		*ptpDst = ToPoint(valList[0].GetNumber(), valList[1].GetNumber());
		ptpDst++;
	}
	if (closeFlag) {
		::Polygon(_hdc, ptList, cnt);
	} else {
		::Polyline(_hdc, ptList, cnt);
	}
	delete[] ptList;
}

void Device_EnhMetaFile::PrepareSimpleLogfont(LOGFONT *plf,
											LONG lHeight, LPCTSTR pszFaceName)
{
	plf->lfHeight = lHeight; 
	plf->lfWidth = 0;
	plf->lfEscapement = 0;		// 1/10 degree
	plf->lfOrientation = 0;		// 1/10 degree
	plf->lfWeight = FW_NORMAL;
	plf->lfItalic = FALSE;
	plf->lfUnderline = FALSE;
	plf->lfStrikeOut = FALSE;
	plf->lfCharSet = DEFAULT_CHARSET;
	plf->lfOutPrecision = OUT_DEFAULT_PRECIS;
	plf->lfClipPrecision = CLIP_DEFAULT_PRECIS;
	plf->lfQuality = DEFAULT_QUALITY;
	plf->lfPitchAndFamily = DEFAULT_PITCH;
	::strcpy(plf->lfFaceName, pszFaceName);
}

void Device_EnhMetaFile::MakeRect(RECT *prc,
						const POINT &pt, int width, int height, Anchor anchor)
{
	prc->left =
		(anchor == ANCHOR_NW || anchor == ANCHOR_W || anchor == ANCHOR_SW)? pt.x :
		(anchor == ANCHOR_NE || anchor == ANCHOR_E || anchor == ANCHOR_SE)? pt.x - width + 1 :
		pt.x - width / 2;
	prc->right = prc->left + width;
	prc->bottom =
		(anchor == ANCHOR_NW || anchor == ANCHOR_N || anchor == ANCHOR_NE)? pt.y - height + 1 :
		(anchor == ANCHOR_SW || anchor == ANCHOR_S || anchor == ANCHOR_SE)? pt.y :
		pt.y - height / 2;
	prc->top = prc->bottom + height;
}

//-----------------------------------------------------------------------------
// Object_Canvas
//-----------------------------------------------------------------------------
Object_Canvas::~Object_Canvas()
{
	Device::Delete(_pDevice);
}

Object *Object_Canvas::Clone() const
{
	return new Object_Canvas(*this);
}

String Object_Canvas::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<canvas:";
	rtn += _pDevice->GetName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// AScipr interfaces for Object_Canvas
//-----------------------------------------------------------------------------
// canvas.canvas#width()
Gura_DeclareMethod(Canvas, width)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Canvas, width)
{
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	return Value(pObj->Device().GetWidth());
}

// canvas.canvas#height()
Gura_DeclareMethod(Canvas, height)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Canvas, height)
{
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	return Value(pObj->Device().GetHeight());
}

// canvas.canvas#setfont(height:number, family:symbol => `default,
//			style:symbol => `normal, weight:symbol => `normal, facename?:string):reduce
Gura_DeclareMethod(Canvas, setfont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "family", VTYPE_symbol, OCCUR_Once, FLAG_None,
								new Expr_Value(Gura_UserSymbol(default)));
	DeclareArg(env, "style", VTYPE_symbol, OCCUR_Once, FLAG_None,
								new Expr_Value(Gura_UserSymbol(normal)));
	DeclareArg(env, "weight", VTYPE_symbol, OCCUR_Once, FLAG_None,
								new Expr_Value(Gura_UserSymbol(normal)));
	DeclareArg(env, "facename", VTYPE_string, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(Canvas, setfont)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().SetFont(sig, arg.GetNumber(0),
			arg.GetSymbol(1), arg.GetSymbol(2), arg.GetSymbol(3),
			arg.Is_string(4)? arg.GetString(4) : "");
	return arg.GetValueThis();
}

// canvas.canvas#settextcolor(color):reduce
Gura_DeclareMethod(Canvas, settextcolor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "color", VTYPE_any);
}

Gura_ImplementMethod(Canvas, settextcolor)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().SetTextColor(sig, arg.GetValue(0));
	return arg.GetValueThis();
}

// canvas.canvas#setpen(color, width:number => 1, style:symbol => `solid):reduce
Gura_DeclareMethod(Canvas, setpen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "color", VTYPE_any);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once, FLAG_None,
								new Expr_Value(1));
	DeclareArg(env, "style", VTYPE_symbol, OCCUR_Once, FLAG_None,
								new Expr_Value(Gura_UserSymbol(solid)));
}

Gura_ImplementMethod(Canvas, setpen)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().SetPen(sig, arg.GetValue(0),
							arg.GetNumber(1), arg.GetSymbol(2));
	return arg.GetValueThis();
}

// canvas.canvas#setbrush(color, style:symbol => `solid):reduce
Gura_DeclareMethod(Canvas, setbrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "color", VTYPE_any);
	DeclareArg(env, "style", VTYPE_symbol, OCCUR_Once, FLAG_None,
								new Expr_Value(Gura_UserSymbol(solid)));
}

Gura_ImplementMethod(Canvas, setbrush)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().SetBrush(sig, arg.GetValue(0), arg.GetSymbol(1));
	return arg.GetValueThis();
}

// canvas.canvas#text(x:number, y:number, text:string, width_bound?:number, height_bound?:number):reduce:[n,ne,e,se,s,sw,w,nw,c]
Gura_DeclareMethod(Canvas, text)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "width_bound", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "height_bound", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAnchorAttrs(this);
}

Gura_ImplementMethod(Canvas, text)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().Text(sig, arg.GetNumber(0), arg.GetNumber(1),
		arg.GetString(2),
		arg.Is_number(3)? arg.GetNumber(3) : -1,
		arg.Is_number(4)? arg.GetNumber(4) : -1, GetAnchor(arg.GetAttrs()));
	return arg.GetValueThis();
}

// canvas.canvas#textrot(x:number, y:number, text:string, angle:number):reduce
Gura_DeclareMethod(Canvas, textrot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "text", VTYPE_string);
	DeclareArg(env, "angle", VTYPE_number);
}

Gura_ImplementMethod(Canvas, textrot)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().TextRot(sig, arg.GetNumber(0), arg.GetNumber(1),
							arg.GetString(2), arg.GetNumber(3));
	return arg.GetValueThis();
}

// canvas.canvas#line(x1:number, y1:number, x2:number, y2:number):map:reduce
Gura_DeclareMethod(Canvas, line)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_number);
	DeclareArg(env, "y1", VTYPE_number);
	DeclareArg(env, "x2", VTYPE_number);
	DeclareArg(env, "y2", VTYPE_number);
}

Gura_ImplementMethod(Canvas, line)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().Line(sig, arg.GetNumber(0), arg.GetNumber(1),
					arg.GetNumber(2), arg.GetNumber(3));
	return arg.GetValueThis();
}

// canvas.canvas#rectangle(x:number, y:number, width:number, height:number):map:reduce
Gura_DeclareMethod(Canvas, rectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareAnchorAttrs(this);
}

Gura_ImplementMethod(Canvas, rectangle)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().Rectangle(sig, arg.GetNumber(0), arg.GetNumber(1),
		arg.GetNumber(2), arg.GetNumber(3), GetAnchor(arg.GetAttrs()));
	return arg.GetValueThis();
}

// canvas.canvas#ellipse(x:number, y:number, width:number, height:number):map:reduce
Gura_DeclareMethod(Canvas, ellipse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareAnchorAttrs(this);
}

Gura_ImplementMethod(Canvas, ellipse)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().Ellipse(sig, arg.GetNumber(0), arg.GetNumber(1),
		arg.GetNumber(2), arg.GetNumber(3), GetAnchor(arg.GetAttrs()));
	return arg.GetValueThis();
}

// canvas.canvas#pie(x:number, y:number, width:number, height:number, start_degree:number, end_degree:number):map:reduce
Gura_DeclareMethod(Canvas, pie)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number);
	DeclareArg(env, "y", VTYPE_number);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "start_degree", VTYPE_number);
	DeclareArg(env, "end_degree", VTYPE_number);
	DeclareAnchorAttrs(this);
}

Gura_ImplementMethod(Canvas, pie)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().Pie(sig, arg.GetNumber(0), arg.GetNumber(1),
		arg.GetNumber(2), arg.GetNumber(3),
		arg.GetNumber(4), arg.GetNumber(5), GetAnchor(arg.GetAttrs()));
	return arg.GetValueThis();
}

// canvas.canvas#polyline(xs[]:number, ys[]:number):reduce
Gura_DeclareMethod(Canvas, polyline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "xs", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "ys", VTYPE_number, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(Canvas, polyline)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().Polygon(sig, arg.GetList(0), arg.GetList(1), false);
	return arg.GetValueThis();
}

// canvas.canvas#polylinep(pts[]:List):reduce
Gura_DeclareMethod(Canvas, polylinep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "pts", VTYPE_list, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(Canvas, polylinep)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().Polygon(sig, arg.GetList(0), false);
	return arg.GetValueThis();
}

// canvas.canvas#polygon(xs[]:number, ys[]:number):reduce
Gura_DeclareMethod(Canvas, polygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "xs", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "ys", VTYPE_number, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(Canvas, polygon)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().Polygon(sig, arg.GetList(0), arg.GetList(1), true);
	return arg.GetValueThis();
}

// canvas.canvas#polygonp(pts[]:List):reduce
Gura_DeclareMethod(Canvas, polygonp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "pts", VTYPE_list, OCCUR_Once, FLAG_ListVar);
}

Gura_ImplementMethod(Canvas, polygonp)
{
	Signal &sig = env.GetSignal();
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().Polygon(sig, arg.GetList(0), true);
	return arg.GetValueThis();
}

// str = canvas.canvas#close()
Gura_DeclareMethod(Canvas, close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(Canvas, close)
{
	Object_Canvas *pObj = Object_Canvas::GetObjectThis(arg);
	pObj->Device().Close();
	return Value::Nil;
}

Gura_ImplementUserClass(Canvas)
{
	Gura_AssignMethod(Canvas, width);
	Gura_AssignMethod(Canvas, height);
	Gura_AssignMethod(Canvas, setfont);
	Gura_AssignMethod(Canvas, settextcolor);
	Gura_AssignMethod(Canvas, setpen);
	Gura_AssignMethod(Canvas, setbrush);
	Gura_AssignMethod(Canvas, text);
	Gura_AssignMethod(Canvas, textrot);
	Gura_AssignMethod(Canvas, line);
	Gura_AssignMethod(Canvas, rectangle);
	Gura_AssignMethod(Canvas, ellipse);
	Gura_AssignMethod(Canvas, pie);
	Gura_AssignMethod(Canvas, polyline);
	Gura_AssignMethod(Canvas, polylinep);
	Gura_AssignMethod(Canvas, polygon);
	Gura_AssignMethod(Canvas, polygonp);
	Gura_AssignMethod(Canvas, close);
}

//-----------------------------------------------------------------------------
// AScipr module functions
//-----------------------------------------------------------------------------
// create_emf(filename:string, width:number, height:number, appname?:string, imagename?:string) {block?}
// unit of width and height is mm
Gura_DeclareFunction(create_emf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "filename", VTYPE_string);
	DeclareArg(env, "width", VTYPE_number);
	DeclareArg(env, "height", VTYPE_number);
	DeclareArg(env, "appname", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "imagename", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(create_emf)
{
	Signal &sig = env.GetSignal();
	Device *pDevice = new Device_EnhMetaFile(sig,
		arg.GetString(0), arg.GetNumber(1), arg.GetNumber(2),
		arg.Is_string(3)? arg.GetString(3) : nullptr,
		arg.Is_string(4)? arg.GetString(4) : nullptr);
	if (sig.IsSignalled()) {
		delete pDevice;
		return Value::Nil;
	}
	const Function *pFuncBlock =
						arg.GetBlockFunc(env, GetSymbolForBlock());
	return pDevice->Initialize(env, pFuncBlock);
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
	Gura_RealizeUserSymbol(red);
	Gura_RealizeUserSymbol(blue);
	Gura_RealizeUserSymbol(green);
	Gura_RealizeUserSymbol(cyan);
	Gura_RealizeUserSymbol(light_blue);
	Gura_RealizeUserSymbol(yellow);
	Gura_RealizeUserSymbol(black);
	Gura_RealizeUserSymbol(white);
	Gura_RealizeUserSymbol(grey);
	Gura_RealizeUserSymbol(solid);
	Gura_RealizeUserSymbol(dot);
	Gura_RealizeUserSymbol(dash);
	Gura_RealizeUserSymbol(dot_dash);
	Gura_RealizeUserSymbol(bdiagonal);
	Gura_RealizeUserSymbol(cross);
	Gura_RealizeUserSymbol(diagcross);
	Gura_RealizeUserSymbol(fdiagonal);
	Gura_RealizeUserSymbol(horizontal);
	Gura_RealizeUserSymbol(vertical);
	Gura_RealizeUserSymbol(normal);
	Gura_RealizeUserSymbol(default);
	Gura_RealizeUserSymbol(decorative);
	Gura_RealizeUserSymbol(roman);
	Gura_RealizeUserSymbol(script);
	Gura_RealizeUserSymbol(swiss);
	Gura_RealizeUserSymbol(modern);
	Gura_RealizeUserSymbol(teletype);
	Gura_RealizeUserSymbol(slant);
	Gura_RealizeUserSymbol(italic);
	Gura_RealizeUserSymbol(light);
	Gura_RealizeUserSymbol(bold);
	Gura_RealizeUserSymbol(n);
	Gura_RealizeUserSymbol(ne);
	Gura_RealizeUserSymbol(e);
	Gura_RealizeUserSymbol(se);
	Gura_RealizeUserSymbol(s);
	Gura_RealizeUserSymbol(sw);
	Gura_RealizeUserSymbol(w);
	Gura_RealizeUserSymbol(nw);
	Gura_RealizeUserSymbol(c);
	// class realization
	Gura_RealizeAndPrepareUserClassAlias(Canvas, "canvas", env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(create_emf);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(canvas, canvas)

Gura_RegisterModule(canvas)
