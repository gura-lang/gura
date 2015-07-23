//----------------------------------------------------------------------------
// wxGraphicsContext
// extracted from graphicscontext.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_GraphicsContext: public wxGraphicsContext, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_GraphicsContext *_pObj;
public:
	~wx_GraphicsContext();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_GraphicsContext *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_GraphicsContext::~wx_GraphicsContext()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_GraphicsContext::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsContext
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_GraphicsContext, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dc", VTYPE_wx_WindowDC, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, Create)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindowDC *dc = Object_wx_WindowDC::GetObject(args, 0)->GetEntity();
	wxGraphicsContext *rtn = (wxGraphicsContext *)pThis->GetEntity()->Create(*dc);
	return ReturnValue(env, args, Value(new Object_wx_GraphicsContext(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsContext, Create_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, Create_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	wxGraphicsContext *rtn = (wxGraphicsContext *)pThis->GetEntity()->Create(window);
	return ReturnValue(env, args, Value(new Object_wx_GraphicsContext(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsContext, CreateFromNative)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "context", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateFromNative)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int context = args.GetInt(0);
	wxGraphicsContext *rtn = (wxGraphicsContext *)pThis->GetEntity()->CreateFromNative(context);
	return ReturnValue(env, args, Value(new Object_wx_GraphicsContext(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsContext, CreateFromNativeWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateFromNativeWindow)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int window = args.GetInt(0);
	wxGraphicsContext *rtn = (wxGraphicsContext *)pThis->GetEntity()->CreateFromNativeWindow(window);
	return ReturnValue(env, args, Value(new Object_wx_GraphicsContext(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_GraphicsContext, CreatePen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pen", VTYPE_wx_Pen, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, CreatePen)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPen *pen = Object_wx_Pen::GetObject(args, 0)->GetEntity();
	wxGraphicsPen rtn = pThis->GetEntity()->CreatePen(*pen);
	return ReturnValue(env, args, Value(new Object_wx_GraphicsPen(new wxGraphicsPen(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsContext, CreateBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "brush", VTYPE_wx_Brush, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateBrush)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBrush *brush = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	wxGraphicsBrush rtn = pThis->GetEntity()->CreateBrush(*brush);
	return ReturnValue(env, args, Value(new Object_wx_GraphicsBrush(new wxGraphicsBrush(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsContext, CreateRadialGradientBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "xo", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "yo", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "xc", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "yc", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "oColor", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "cColor", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateRadialGradientBrush)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *xo = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *yo = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *xc = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *yc = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *radius = Object_wx_Double::GetObject(args, 4)->GetEntity();
	wxColour *oColor = Object_wx_Colour::GetObject(args, 5)->GetEntity();
	wxColour *cColor = Object_wx_Colour::GetObject(args, 6)->GetEntity();
	wxGraphicsBrush rtn = pThis->GetEntity()->CreateRadialGradientBrush(*xo, *yo, *xc, *yc, *radius, *oColor, *cColor);
	return ReturnValue(env, args, Value(new Object_wx_GraphicsBrush(new wxGraphicsBrush(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsContext, CreateLinearGradientBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y1", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "x2", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y2", VTYPE_wx_Double, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateLinearGradientBrush)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x1 = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y1 = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *x2 = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *y2 = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxGraphicsBrush rtn = pThis->GetEntity()->CreateLinearGradientBrush(*x1, *y1, *x2, *y2, , );
	return ReturnValue(env, args, Value(new Object_wx_GraphicsBrush(new wxGraphicsBrush(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsContext, CreateFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareArg(env, "col", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateFont)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	wxColour *col = (wxColour *)(&*wxBLACK);
	if (args.IsValid(1)) col = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxGraphicsFont rtn = pThis->GetEntity()->CreateFont(*font, *col);
	return ReturnValue(env, args, Value(new Object_wx_GraphicsFont(new wxGraphicsFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsContext, CreateMatrix)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "b", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "c", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "d", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tx", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ty", VTYPE_wx_Double, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, CreateMatrix)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *a = (wxDouble *)(&1.0);
	if (args.IsValid(0)) a = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *b = (wxDouble *)(&0.0);
	if (args.IsValid(1)) b = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *c = (wxDouble *)(&0.0);
	if (args.IsValid(2)) c = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *d = (wxDouble *)(&1.0);
	if (args.IsValid(3)) d = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *tx = (wxDouble *)(&0.0);
	if (args.IsValid(4)) tx = Object_wx_Double::GetObject(args, 4)->GetEntity();
	wxDouble *ty = (wxDouble *)(&0.0);
	if (args.IsValid(5)) ty = Object_wx_Double::GetObject(args, 5)->GetEntity();
	wxGraphicsMatrix rtn = pThis->GetEntity()->CreateMatrix(*a, *b, *c, *d, *tx, *ty);
	return ReturnValue(env, args, Value(new Object_wx_GraphicsMatrix(new wxGraphicsMatrix(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsContext, CreatePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, CreatePath)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsPath rtn = pThis->GetEntity()->CreatePath();
	return ReturnValue(env, args, Value(new Object_wx_GraphicsPath(new wxGraphicsPath(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsContext, Clip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Clip)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Clip(*region);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, Clip_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Clip_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *w = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *h = Object_wx_Double::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->Clip(*x, *y, *w, *h);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, ResetClip)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, ResetClip)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ResetClip();
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bmp", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawBitmap)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxDouble *x = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *w = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *h = Object_wx_Double::GetObject(args, 4)->GetEntity();
	pThis->GetEntity()->DrawBitmap(*bmp, *x, *y, *w, *h);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawEllipse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawEllipse)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *w = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *h = Object_wx_Double::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->DrawEllipse(*x, *y, *w, *h);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawIcon)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	wxDouble *x = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *w = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *h = Object_wx_Double::GetObject(args, 4)->GetEntity();
	pThis->GetEntity()->DrawIcon(*icon, *x, *y, *w, *h);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "points", VTYPE_wx_Point2DDouble, OCCUR_Once);
	DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawLines)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxPoint2DDouble *points = Object_wx_Point2DDouble::GetObject(args, 1)->GetEntity();
	int fillStyle = wxODDEVEN_RULE;
	if (args.IsValid(2)) fillStyle = args.GetInt(2);
	pThis->GetEntity()->DrawLines(n, points, fillStyle);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_wx_GraphicsPath, OCCUR_Once);
	DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawPath)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsPath *path = Object_wx_GraphicsPath::GetObject(args, 0)->GetEntity();
	int fillStyle = wxODDEVEN_RULE;
	if (args.IsValid(1)) fillStyle = args.GetInt(1);
	pThis->GetEntity()->DrawPath(*path, fillStyle);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawRectangle)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *w = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *h = Object_wx_Double::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->DrawRectangle(*x, *y, *w, *h);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawRoundedRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawRoundedRectangle)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *w = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *h = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *radius = Object_wx_Double::GetObject(args, 4)->GetEntity();
	pThis->GetEntity()->DrawRoundedRectangle(*x, *y, *w, *h, *radius);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "angle", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawText)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxDouble *x = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *angle = Object_wx_Double::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->DrawText(str, *x, *y, *angle);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, DrawText_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, DrawText_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString str = wxString::FromUTF8(args.GetString(0));
	wxDouble *x = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *y = Object_wx_Double::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->DrawText(str, *x, *y);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, FillPath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_wx_GraphicsPath, OCCUR_Once);
	DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, FillPath)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsPath *path = Object_wx_GraphicsPath::GetObject(args, 0)->GetEntity();
	int fillStyle = wxODDEVEN_RULE;
	if (args.IsValid(1)) fillStyle = args.GetInt(1);
	pThis->GetEntity()->FillPath(*path, fillStyle);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, StrokePath)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "path", VTYPE_wx_GraphicsPath, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, StrokePath)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsPath *path = Object_wx_GraphicsPath::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->StrokePath(*path);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, GetNativeContext)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GraphicsContext, GetNativeContext)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->GetNativeContext();
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, GetPartialTextExtents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "widths", VTYPE_wx_ArrayDouble, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, GetPartialTextExtents)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxArrayDouble *widths = Object_wx_ArrayDouble::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->GetPartialTextExtents(text, *widths);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, GetTextExtent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "descent", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "externalLeading", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, GetTextExtent)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxDouble *width = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *height = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *descent = Object_wx_Double::GetObject(args, 3)->GetEntity();
	wxDouble *externalLeading = Object_wx_Double::GetObject(args, 4)->GetEntity();
	pThis->GetEntity()->GetTextExtent(text, width, height, descent, externalLeading);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, Rotate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Rotate)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *angle = Object_wx_Double::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Rotate(*angle);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, Scale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xScale", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "yScale", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Scale)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *xScale = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *yScale = Object_wx_Double::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Scale(*xScale, *yScale);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, Translate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, Translate)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *dx = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *dy = Object_wx_Double::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->Translate(*dx, *dy);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, GetTransform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_GraphicsContext, GetTransform)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsMatrix rtn = pThis->GetEntity()->GetTransform();
	return ReturnValue(env, args, Value(new Object_wx_GraphicsMatrix(new wxGraphicsMatrix(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_GraphicsContext, SetTransform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "matrix", VTYPE_wx_GraphicsMatrix, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetTransform)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsMatrix *matrix = Object_wx_GraphicsMatrix::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTransform(*matrix);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, ConcatTransform)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "matrix", VTYPE_wx_GraphicsMatrix, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, ConcatTransform)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsMatrix *matrix = Object_wx_GraphicsMatrix::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->ConcatTransform(*matrix);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, SetBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "brush", VTYPE_wx_Brush, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetBrush)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBrush *brush = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBrush(*brush);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, SetBrush_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "brush", VTYPE_wx_GraphicsBrush, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetBrush_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsBrush *brush = Object_wx_GraphicsBrush::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBrush(*brush);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetFont)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	wxColour *colour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetFont(*font, *colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, SetFont_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_GraphicsFont, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetFont_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsFont *font = Object_wx_GraphicsFont::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, SetPen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pen", VTYPE_wx_GraphicsPen, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetPen)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxGraphicsPen *pen = Object_wx_GraphicsPen::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPen(*pen);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, SetPen_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pen", VTYPE_wx_Pen, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, SetPen_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPen *pen = Object_wx_Pen::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPen(*pen);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, StrokeLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y1", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "x2", VTYPE_wx_Double, OCCUR_Once);
	DeclareArg(env, "y2", VTYPE_wx_Double, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, StrokeLine)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDouble *x1 = Object_wx_Double::GetObject(args, 0)->GetEntity();
	wxDouble *y1 = Object_wx_Double::GetObject(args, 1)->GetEntity();
	wxDouble *x2 = Object_wx_Double::GetObject(args, 2)->GetEntity();
	wxDouble *y2 = Object_wx_Double::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->StrokeLine(*x1, *y1, *x2, *y2);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, StrokeLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "beginPoints", VTYPE_wx_Point2DDouble, OCCUR_Once);
	DeclareArg(env, "endPoints", VTYPE_wx_Point2DDouble, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, StrokeLines)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxPoint2DDouble *beginPoints = Object_wx_Point2DDouble::GetObject(args, 1)->GetEntity();
	wxPoint2DDouble *endPoints = Object_wx_Point2DDouble::GetObject(args, 2)->GetEntity();
	pThis->GetEntity()->StrokeLines(n, beginPoints, endPoints);
	return Value::Null;
}

Gura_DeclareMethod(wx_GraphicsContext, StrokeLines_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "points", VTYPE_wx_Point2DDouble, OCCUR_Once);
}

Gura_ImplementMethod(wx_GraphicsContext, StrokeLines_1)
{
	Object_wx_GraphicsContext *pThis = Object_wx_GraphicsContext::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	size_t n = args.GetSizeT(0);
	wxPoint2DDouble *points = Object_wx_Point2DDouble::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->StrokeLines(n, points);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsContext
//----------------------------------------------------------------------------
Object_wx_GraphicsContext::~Object_wx_GraphicsContext()
{
}

Object *Object_wx_GraphicsContext::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsContext::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsContext:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxGraphicsContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsContext)
{
	Gura_AssignMethod(wx_GraphicsContext, Create);
	Gura_AssignMethod(wx_GraphicsContext, Create_1);
	Gura_AssignMethod(wx_GraphicsContext, CreateFromNative);
	Gura_AssignMethod(wx_GraphicsContext, CreateFromNativeWindow);
	Gura_AssignMethod(wx_GraphicsContext, CreatePen);
	Gura_AssignMethod(wx_GraphicsContext, CreateBrush);
	Gura_AssignMethod(wx_GraphicsContext, CreateRadialGradientBrush);
	Gura_AssignMethod(wx_GraphicsContext, CreateLinearGradientBrush);
	Gura_AssignMethod(wx_GraphicsContext, CreateFont);
	Gura_AssignMethod(wx_GraphicsContext, CreateMatrix);
	Gura_AssignMethod(wx_GraphicsContext, CreatePath);
	Gura_AssignMethod(wx_GraphicsContext, Clip);
	Gura_AssignMethod(wx_GraphicsContext, Clip_1);
	Gura_AssignMethod(wx_GraphicsContext, ResetClip);
	Gura_AssignMethod(wx_GraphicsContext, DrawBitmap);
	Gura_AssignMethod(wx_GraphicsContext, DrawEllipse);
	Gura_AssignMethod(wx_GraphicsContext, DrawIcon);
	Gura_AssignMethod(wx_GraphicsContext, DrawLines);
	Gura_AssignMethod(wx_GraphicsContext, DrawPath);
	Gura_AssignMethod(wx_GraphicsContext, DrawRectangle);
	Gura_AssignMethod(wx_GraphicsContext, DrawRoundedRectangle);
	Gura_AssignMethod(wx_GraphicsContext, DrawText);
	Gura_AssignMethod(wx_GraphicsContext, DrawText_1);
	Gura_AssignMethod(wx_GraphicsContext, FillPath);
	Gura_AssignMethod(wx_GraphicsContext, StrokePath);
	Gura_AssignMethod(wx_GraphicsContext, GetNativeContext);
	Gura_AssignMethod(wx_GraphicsContext, GetPartialTextExtents);
	Gura_AssignMethod(wx_GraphicsContext, GetTextExtent);
	Gura_AssignMethod(wx_GraphicsContext, Rotate);
	Gura_AssignMethod(wx_GraphicsContext, Scale);
	Gura_AssignMethod(wx_GraphicsContext, Translate);
	Gura_AssignMethod(wx_GraphicsContext, GetTransform);
	Gura_AssignMethod(wx_GraphicsContext, SetTransform);
	Gura_AssignMethod(wx_GraphicsContext, ConcatTransform);
	Gura_AssignMethod(wx_GraphicsContext, SetBrush);
	Gura_AssignMethod(wx_GraphicsContext, SetBrush_1);
	Gura_AssignMethod(wx_GraphicsContext, SetFont);
	Gura_AssignMethod(wx_GraphicsContext, SetFont_1);
	Gura_AssignMethod(wx_GraphicsContext, SetPen);
	Gura_AssignMethod(wx_GraphicsContext, SetPen_1);
	Gura_AssignMethod(wx_GraphicsContext, StrokeLine);
	Gura_AssignMethod(wx_GraphicsContext, StrokeLines);
	Gura_AssignMethod(wx_GraphicsContext, StrokeLines_1);
}

Gura_ImplementDescendantCreator(wx_GraphicsContext)
{
	return new Object_wx_GraphicsContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
