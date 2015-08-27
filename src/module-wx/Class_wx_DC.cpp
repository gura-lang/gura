//----------------------------------------------------------------------------
// wxDC
// extracted from dc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(ComputeScaleAndOrigin);
Gura_DeclarePrivUserSymbol(DrawLabel);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DC: public wxDC, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DC *_pObj;
public:
	//virtual void ComputeScaleAndOrigin();
	//virtual void DrawLabel(const wxString& text, const wxBitmap& image, const wxRect& rect, int alignment, int indexAccel, wxRect * rectBounding);
	~wx_DC();
	inline void AssocWithGura(Object_wx_DC *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DC::~wx_DC()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DC::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDC
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DC, Blit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "xdest", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ydest", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "source", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "xsrc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ysrc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "logicalFunc", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "useMask", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "xsrcMask", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ysrcMask", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, Blit)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord xdest = static_cast<wxCoord>(args.GetInt(0));
	wxCoord ydest = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	wxDC *source = Object_wx_DC::GetObject(args, 4)->GetEntity();
	wxCoord xsrc = static_cast<wxCoord>(args.GetInt(5));
	wxCoord ysrc = static_cast<wxCoord>(args.GetInt(6));
	wxRasterOperationMode logicalFunc = wxCOPY;
	if (args.IsValid(7)) logicalFunc = static_cast<wxRasterOperationMode>(args.GetInt(7));
	bool useMask = false;
	if (args.IsValid(8)) useMask = args.GetBoolean(8);
	wxCoord xsrcMask = -1;
	if (args.IsValid(9)) xsrcMask = static_cast<wxCoord>(args.GetInt(9));
	wxCoord ysrcMask = -1;
	if (args.IsValid(10)) ysrcMask = static_cast<wxCoord>(args.GetInt(10));
	bool rtn = pThis->GetEntity()->Blit(xdest, ydest, width, height, source, xsrc, ysrc, logicalFunc, useMask, xsrcMask, ysrcMask);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DC, CacheEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DC, CacheEnabled)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	bool rtn = wxDC::CacheEnabled();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, CalcBoundingBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, CalcBoundingBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->CalcBoundingBox(x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
}

#if 0
Gura_DeclareClassMethod(wx_DC, ClearCache)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_DC, ClearCache)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if defined(__WXMSW__)
	wxDC::ClearCache();
	return Value::Nil;
#else
	SetError_MSWOnly(sig);
	return Value::Nil;
#endif	
}
#endif

#if 0
Gura_DeclareMethod(wx_DC, ComputeScaleAndOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, ComputeScaleAndOrigin)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ComputeScaleAndOrigin();
	return Value::Nil;
}
#endif

Gura_DeclareMethod(wx_DC, CrossHair)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, CrossHair)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->CrossHair(x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DestroyClippingRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, DestroyClippingRegion)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->DestroyClippingRegion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalX)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->DeviceToLogicalX(x);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalXRel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalXRel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->DeviceToLogicalXRel(x);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalY)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord y = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->DeviceToLogicalY(y);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalYRel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalYRel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord y = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->DeviceToLogicalYRel(y);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, DrawArc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "yc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawArc)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x1 = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y1 = static_cast<wxCoord>(args.GetInt(1));
	wxCoord x2 = static_cast<wxCoord>(args.GetInt(2));
	wxCoord y2 = static_cast<wxCoord>(args.GetInt(3));
	wxCoord xc = static_cast<wxCoord>(args.GetInt(4));
	wxCoord yc = static_cast<wxCoord>(args.GetInt(5));
	pThis->GetEntity()->DrawArc(x1, y1, x2, y2, xc, yc);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "transparent", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxCoord x = static_cast<wxCoord>(args.GetInt(1));
	wxCoord y = static_cast<wxCoord>(args.GetInt(2));
	bool transparent = args.GetBoolean(3);
	pThis->GetEntity()->DrawBitmap(*bitmap, x, y, transparent);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawCheckMark)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCheckMark)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	pThis->GetEntity()->DrawCheckMark(x, y, width, height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawCheckMarkRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCheckMarkRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DrawCheckMark(*rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawCircle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCircle)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord radius = static_cast<wxCoord>(args.GetInt(2));
	pThis->GetEntity()->DrawCircle(x, y, radius);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawCirclePoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCirclePoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxCoord radius = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->DrawCircle(*pt, radius);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawEllipse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipse)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	pThis->GetEntity()->DrawEllipse(x, y, width, height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawEllipsePointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipsePointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->DrawEllipse(*pt, *size);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawEllipseRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipseRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DrawEllipse(*rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawEllipticArc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipticArc)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	double start = args.GetDouble(4);
	double end = args.GetDouble(5);
	pThis->GetEntity()->DrawEllipticArc(x, y, width, height, start, end);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	wxCoord x = static_cast<wxCoord>(args.GetInt(1));
	wxCoord y = static_cast<wxCoord>(args.GetInt(2));
	pThis->GetEntity()->DrawIcon(*icon, x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "indexAccel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "rectBounding", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DrawLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxBitmap *image = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int alignment = wxALIGN_LEFT | wxALIGN_TOP;
	if (args.IsValid(3)) alignment = args.GetInt(3);
	int indexAccel = -1;
	if (args.IsValid(4)) indexAccel = args.GetInt(4);
	wxRect *rectBounding = (wxRect *)(nullptr);
	if (args.IsValid(5)) rectBounding = Object_wx_Rect::GetObject(args, 5)->GetEntity();
	pThis->GetEntity()->DrawLabel(text, *image, *rect, alignment, indexAccel, rectBounding);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawLabel_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "indexAccel", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DrawLabel_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	int alignment = wxALIGN_LEFT | wxALIGN_TOP;
	if (args.IsValid(2)) alignment = args.GetInt(2);
	int indexAccel = -1;
	if (args.IsValid(3)) indexAccel = args.GetInt(3);
	pThis->GetEntity()->DrawLabel(text, *rect, alignment, indexAccel);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawLine)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawLine)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x1 = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y1 = static_cast<wxCoord>(args.GetInt(1));
	wxCoord x2 = static_cast<wxCoord>(args.GetInt(2));
	wxCoord y2 = static_cast<wxCoord>(args.GetInt(3));
	pThis->GetEntity()->DrawLine(x1, y1, x2, y2);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "points", VTYPE_wx_Point, OCCUR_Once, FLAG_List);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DrawLines)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	CArrayOfPoint points(args.GetList(0));
	wxCoord xoffset = 0;
	if (args.IsValid(1)) xoffset = static_cast<wxCoord>(args.GetInt(1));
	wxCoord yoffset = 0;
	if (args.IsValid(2)) yoffset = static_cast<wxCoord>(args.GetInt(2));
	pThis->GetEntity()->DrawLines(points.Count(), points.Data(), xoffset, yoffset);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "points", VTYPE_wx_Point, OCCUR_Once, FLAG_List);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "fill_style", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DrawPolygon)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	CArrayOfPoint points(args.GetList(0));
	wxCoord xoffset = 0;
	if (args.IsValid(1)) xoffset = static_cast<wxCoord>(args.GetInt(1));
	wxCoord yoffset = 0;
	if (args.IsValid(2)) yoffset = static_cast<wxCoord>(args.GetInt(2));
	wxPolygonFillMode fill_style = wxODDEVEN_RULE;
	if (args.IsValid(3)) fill_style = static_cast<wxPolygonFillMode>(args.GetInt(3));
	pThis->GetEntity()->DrawPolygon(points.Count(), points.Data(), xoffset, yoffset, fill_style);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawPolyPolygon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "points", VTYPE_list, OCCUR_Once, FLAG_List | FLAG_NoMap);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "fill_style", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DrawPolyPolygon)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = args.GetList(0).size();
	int *count = new int [n];
	int nPoints = 0;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		nPoints += pValue->GetList().size();
	}
	wxPoint *points = new wxPoint [nPoints];
	int iPolygon = 0;
	int iPoint = 0;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		count[iPolygon++] = static_cast<int>(pValue->GetList().size());
		foreach_const (ValueList, pValueElem, pValue->GetList()) {
			if (!pValueElem->IsInstanceOf(VTYPE_wx_Point)) {
				sig.SetError(ERR_ValueError, "element must be an instance of Point");
				delete[] count;
				delete[] points;
				return Value::Nil;
			}
			points[iPoint++] = *Object_wx_Point::GetObject(*pValueElem)->GetEntity();
		}
	}
	wxCoord xoffset = 0;
	if (args.IsValid(1)) xoffset = static_cast<wxCoord>(args.GetInt(1));
	wxCoord yoffset = 0;
	if (args.IsValid(2)) yoffset = static_cast<wxCoord>(args.GetInt(2));
	wxPolygonFillMode fill_style = wxODDEVEN_RULE;
	if (args.IsValid(3)) fill_style = static_cast<wxPolygonFillMode>(args.GetInt(3));
	pThis->GetEntity()->DrawPolyPolygon(n, count, points, xoffset, yoffset, fill_style);
	delete[] count;
	delete[] points;
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->DrawPoint(x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRectangle)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	pThis->GetEntity()->DrawRectangle(x, y, width, height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRectanglePointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRectanglePointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxSize *sz = Object_wx_Size::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->DrawRectangle(*pt, *sz);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRectangleRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRectangleRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DrawRectangle(*rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRotatedText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRotatedText)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxCoord x = static_cast<wxCoord>(args.GetInt(1));
	wxCoord y = static_cast<wxCoord>(args.GetInt(2));
	double angle = args.GetDouble(3);
	pThis->GetEntity()->DrawRotatedText(text, x, y, angle);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRoundedRectangle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRoundedRectangle)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	double radius = args.GetDouble(4);
	pThis->GetEntity()->DrawRoundedRectangle(x, y, width, height, radius);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawRoundedRectanglePointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRoundedRectanglePointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxSize *sz = Object_wx_Size::GetObject(args, 1)->GetEntity();
	double radius = args.GetDouble(2);
	pThis->GetEntity()->DrawRoundedRectangle(*pt, *sz, radius);
	return Value::Nil;
}


Gura_DeclareMethod(wx_DC, DrawRoundedRectangleRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRoundedRectangleRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	double radius = args.GetDouble(1);
	pThis->GetEntity()->DrawRoundedRectangle(*rect, radius);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawSpline)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "points", VTYPE_wx_Point, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_DC, DrawSpline)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	CArrayOfPoint points(args.GetList(0));
	pThis->GetEntity()->DrawSpline(points.Count(), points.Data());
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, DrawText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawText)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxCoord x = static_cast<wxCoord>(args.GetInt(1));
	wxCoord y = static_cast<wxCoord>(args.GetInt(2));
	pThis->GetEntity()->DrawText(text, x, y);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_DC, EnableCache)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "enableCache", VTYPE_boolean, OCCUR_Once);
#endif
}

Gura_ImplementClassMethod(wx_DC, EnableCache)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	bool enableCache = args.GetBoolean(0);
	wxDC::EnableCache(enableCache);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, EndDoc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, EndDoc)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->EndDoc();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, EndPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, EndPage)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->EndPage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, FloodFill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, FloodFill)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxColour *colour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	wxFloodFillStyle style = wxFLOOD_SURFACE;
	if (args.IsValid(3)) style = static_cast<wxFloodFillStyle>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->FloodFill(x, y, *colour, style);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxBrush &rtn = pThis->GetEntity()->GetBackground();
	return ReturnValue(env, args, Value(new Object_wx_Brush(new wxBrush(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetBackgroundMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetBackgroundMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetBackgroundMode();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxBrush &rtn = pThis->GetEntity()->GetBrush();
	return ReturnValue(env, args, Value(new Object_wx_Brush(new wxBrush(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetCharHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetCharHeight)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord rtn = pThis->GetEntity()->GetCharHeight();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetCharWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetCharWidth)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord rtn = pThis->GetEntity()->GetCharWidth();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetClippingBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetClippingBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x;
	wxCoord y;
	wxCoord width;
	wxCoord height;
	pThis->GetEntity()->GetClippingBox(&x, &y, &width, &height);
	return ReturnValue(env, args, Value::CreateList(env, x, y, width, height));
}

Gura_DeclareMethod(wx_DC, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxFont &rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, args, Value(new Object_wx_Font(new wxFont(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetLayoutDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetLayoutDirection)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutDirection rtn = pThis->GetEntity()->GetLayoutDirection();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetLogicalFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetLogicalFunction)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetLogicalFunction();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetMapMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetMapMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMapMode();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetMultiLineTextExtent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetMultiLineTextExtent)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(args.GetString(0));
	wxFont *font = (wxFont *)(nullptr);
	if (args.IsValid(4)) font = Object_wx_Font::GetObject(args, 4)->GetEntity();
	wxCoord w;
	wxCoord h;
	wxCoord heightLine;
	pThis->GetEntity()->GetMultiLineTextExtent(string, &w, &h, &heightLine, font);
	return ReturnValue(env, args, Value::CreateList(env, w, h, heightLine));
}

Gura_DeclareMethod(wx_DC, GetPartialTextExtents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "widths", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetPartialTextExtents)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString text = wxString::FromUTF8(args.GetString(0));
	std::unique_ptr<wxArrayInt> widths(CreateArrayInt(args.GetList(1)));
	bool rtn = pThis->GetEntity()->GetPartialTextExtents(text, *widths);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetPen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetPen)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxPen &rtn = pThis->GetEntity()->GetPen();
	return ReturnValue(env, args, Value(new Object_wx_Pen(new wxPen(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetPixel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetPixel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxColour *colour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->GetPixel(x, y, colour);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetPPI)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetPPI)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetPPI();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetSizeAsList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetSizeAsList)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord width;
	wxCoord height;
	pThis->GetEntity()->GetSize(&width, &height);
	return ReturnValue(env, args, Value::CreateList(env, width, height));
}

Gura_DeclareMethod(wx_DC, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetSizeMMAsList)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetSizeMMAsList)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord width;
	wxCoord height;
	pThis->GetEntity()->GetSizeMM(&width, &height);
	return ReturnValue(env, args, Value::CreateList(env, width, height));
}

Gura_DeclareMethod(wx_DC, GetSizeMM)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetSizeMM)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSize rtn = pThis->GetEntity()->GetSizeMM();
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetTextBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetTextBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetTextBackground();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetTextExtent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetTextExtent)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(args.GetString(0));
	wxFont *font = (wxFont *)(nullptr);
	if (args.IsValid(1)) font = Object_wx_Font::GetObject(args, 1)->GetEntity();
	wxCoord w;
	wxCoord h;
	wxCoord descent;
	wxCoord externalLeading;
	pThis->GetEntity()->GetTextExtent(string, &w, &h, &descent, &externalLeading, font);
	return ReturnValue(env, args, Value::CreateList(env, w, h, descent, externalLeading));
}

Gura_DeclareMethod(wx_DC, GetTextExtent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetTextExtent_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString string = wxString::FromUTF8(args.GetString(0));
	wxSize rtn = pThis->GetEntity()->GetTextExtent(string);
	return ReturnValue(env, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetTextForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetTextForeground)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	const wxColour &rtn = pThis->GetEntity()->GetTextForeground();
	return ReturnValue(env, args, Value(new Object_wx_Colour(new wxColour(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetUserScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetUserScale)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double x;
	double y;
	pThis->GetEntity()->GetUserScale(&x, &y);
	return ReturnValue(env, args, Value::CreateList(env, x, y));
}

Gura_DeclareMethod(wx_DC, GradientFillConcentric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "initialColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "destColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "circleCenter", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GradientFillConcentric)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxColour *initialColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxColour *destColour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	if (args.IsValid(3)) {
		wxPoint *circleCenter = Object_wx_Point::GetObject(args, 3)->GetEntity();
		pThis->GetEntity()->GradientFillConcentric(*rect, *initialColour, *destColour, *circleCenter);
	} else {
		pThis->GetEntity()->GradientFillConcentric(*rect, *initialColour, *destColour);
	}
	return Value::Nil;
}

#if 0
Gura_DeclareMethod(wx_DC, GradientFillConcentric_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "initialColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "destColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "circleCenter", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GradientFillConcentric_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxColour *initialColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxColour *destColour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	wxPoint *circleCenter = Object_wx_Point::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->GradientFillConcentric(*rect, *initialColour, *destColour, *circleCenter);
	return Value::Nil;
}
#endif

Gura_DeclareMethod(wx_DC, GradientFillLinear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "initialColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "destColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "nDirection", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GradientFillLinear)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxColour *initialColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxColour *destColour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	wxDirection nDirection = wxEAST;
	if (args.IsValid(3)) nDirection = static_cast<wxDirection>(args.GetInt(3));
	pThis->GetEntity()->GradientFillLinear(*rect, *initialColour, *destColour, nDirection);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceX)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->LogicalToDeviceX(x);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceXRel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceXRel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->LogicalToDeviceXRel(x);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceY)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord y = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->LogicalToDeviceY(y);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceYRel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceYRel)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord y = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->LogicalToDeviceYRel(y);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, MaxX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, MaxX)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord rtn = pThis->GetEntity()->MaxX();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, MaxY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, MaxY)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord rtn = pThis->GetEntity()->MaxY();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, MinX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, MinX)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord rtn = pThis->GetEntity()->MinX();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, MinY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, MinY)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord rtn = pThis->GetEntity()->MinY();
	return ReturnValue(env, args, Value(rtn));
}

#if 0
Gura_DeclareMethod(wx_DC, Ok)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, Ok)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Ok();
	return ReturnValue(env, args, Value(rtn));
}
#endif

Gura_DeclareMethod(wx_DC, ResetBoundingBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, ResetBoundingBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->ResetBoundingBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetAxisOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xLeftRight", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "yBottomUp", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetAxisOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool xLeftRight = args.GetBoolean(0);
	bool yBottomUp = args.GetBoolean(1);
	pThis->GetEntity()->SetAxisOrientation(xLeftRight, yBottomUp);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "brush", VTYPE_wx_Brush, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBrush *brush = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBackground(*brush);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetBackgroundMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetBackgroundMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int mode = args.GetInt(0);
	pThis->GetEntity()->SetBackgroundMode(mode);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetBrush)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "brush", VTYPE_wx_Brush, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetBrush)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBrush *brush = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBrush(*brush);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetClippingRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRegion)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	pThis->GetEntity()->SetClippingRegion(x, y, width, height);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetClippingRegionPointSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRegionPointSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxSize *sz = Object_wx_Size::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetClippingRegion(*pt, *sz);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetClippingRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetClippingRegion(*rect);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetClippingRegionAsRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRegionAsRegion)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetClippingRegion(*region);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetDeviceOrigin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetDeviceOrigin)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->SetDeviceOrigin(x, y);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetLayoutDirection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetLayoutDirection)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLayoutDirection dir = static_cast<wxLayoutDirection>(args.GetInt(0));
	pThis->GetEntity()->SetLayoutDirection(dir);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetLogicalFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetLogicalFunction)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRasterOperationMode function = static_cast<wxRasterOperationMode>(args.GetInt(0));
	pThis->GetEntity()->SetLogicalFunction(function);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetMapMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetMapMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMappingMode mode = static_cast<wxMappingMode>(args.GetInt(0));
	pThis->GetEntity()->SetMapMode(mode);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetPalette)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetPalette)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPalette *palette = Object_wx_Palette::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPalette(*palette);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetPen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pen", VTYPE_wx_Pen, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetPen)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPen *pen = Object_wx_Pen::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPen(*pen);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetTextBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetTextBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextBackground(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetTextForeground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetTextForeground)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextForeground(*colour);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, SetUserScale)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetUserScale)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	double xScale = args.GetDouble(0);
	double yScale = args.GetDouble(1);
	pThis->GetEntity()->SetUserScale(xScale, yScale);
	return Value::Nil;
}

Gura_DeclareMethod(wx_DC, StartDoc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, StartDoc)
{
	Signal &sig = env.GetSignal();
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString message = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->StartDoc(message);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, StartPage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, StartPage)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_DC *pThis = Object_wx_DC::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->StartPage();
	return ReturnValue(env, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxDC
//----------------------------------------------------------------------------
Object_wx_DC::~Object_wx_DC()
{
}

Object *Object_wx_DC::Clone() const
{
	return nullptr;
}

String Object_wx_DC::ToString(bool exprFlag)
{
	String rtn("<wx.DC:");
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
// Class implementation for wxDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DC)
{
	Gura_RealizeUserSymbol(ComputeScaleAndOrigin);
	Gura_RealizeUserSymbol(DrawLabel);
	Gura_AssignMethod(wx_DC, Blit);
	Gura_AssignMethod(wx_DC, CacheEnabled);
	Gura_AssignMethod(wx_DC, CalcBoundingBox);
	Gura_AssignMethod(wx_DC, Clear);
	//Gura_AssignMethod(wx_DC, ClearCache);
	//Gura_AssignMethod(wx_DC, ComputeScaleAndOrigin);
	Gura_AssignMethod(wx_DC, CrossHair);
	Gura_AssignMethod(wx_DC, DestroyClippingRegion);
	Gura_AssignMethod(wx_DC, DeviceToLogicalX);
	Gura_AssignMethod(wx_DC, DeviceToLogicalXRel);
	Gura_AssignMethod(wx_DC, DeviceToLogicalY);
	Gura_AssignMethod(wx_DC, DeviceToLogicalYRel);
	Gura_AssignMethod(wx_DC, DrawArc);
	Gura_AssignMethod(wx_DC, DrawBitmap);
	Gura_AssignMethod(wx_DC, DrawCheckMark);
	Gura_AssignMethod(wx_DC, DrawCheckMarkRect);
	Gura_AssignMethod(wx_DC, DrawCircle);
	Gura_AssignMethod(wx_DC, DrawCirclePoint);
	Gura_AssignMethod(wx_DC, DrawEllipse);
	Gura_AssignMethod(wx_DC, DrawEllipsePointSize);
	Gura_AssignMethod(wx_DC, DrawEllipseRect);
	Gura_AssignMethod(wx_DC, DrawEllipticArc);
	Gura_AssignMethod(wx_DC, DrawIcon);
	Gura_AssignMethod(wx_DC, DrawLabel);
	Gura_AssignMethod(wx_DC, DrawLabel_1);
	Gura_AssignMethod(wx_DC, DrawLine);
	Gura_AssignMethod(wx_DC, DrawLines);
	Gura_AssignMethod(wx_DC, DrawPolygon);
	Gura_AssignMethod(wx_DC, DrawPolyPolygon);
	Gura_AssignMethod(wx_DC, DrawPoint);
	Gura_AssignMethod(wx_DC, DrawRectangle);
	Gura_AssignMethod(wx_DC, DrawRectanglePointSize);
	Gura_AssignMethod(wx_DC, DrawRectangleRect);
	Gura_AssignMethod(wx_DC, DrawRotatedText);
	Gura_AssignMethod(wx_DC, DrawRoundedRectangle);
	Gura_AssignMethod(wx_DC, DrawRoundedRectanglePointSize);
	Gura_AssignMethod(wx_DC, DrawRoundedRectangleRect);
	Gura_AssignMethod(wx_DC, DrawSpline);
	Gura_AssignMethod(wx_DC, DrawText);
	Gura_AssignMethod(wx_DC, EnableCache);
	Gura_AssignMethod(wx_DC, EndDoc);
	Gura_AssignMethod(wx_DC, EndPage);
	Gura_AssignMethod(wx_DC, FloodFill);
	Gura_AssignMethod(wx_DC, GetBackground);
	Gura_AssignMethod(wx_DC, GetBackgroundMode);
	Gura_AssignMethod(wx_DC, GetBrush);
	Gura_AssignMethod(wx_DC, GetCharHeight);
	Gura_AssignMethod(wx_DC, GetCharWidth);
	Gura_AssignMethod(wx_DC, GetClippingBox);
	Gura_AssignMethod(wx_DC, GetFont);
	Gura_AssignMethod(wx_DC, GetLayoutDirection);
	Gura_AssignMethod(wx_DC, GetLogicalFunction);
	Gura_AssignMethod(wx_DC, GetMapMode);
	Gura_AssignMethod(wx_DC, GetMultiLineTextExtent);
	Gura_AssignMethod(wx_DC, GetPartialTextExtents);
	Gura_AssignMethod(wx_DC, GetPen);
	Gura_AssignMethod(wx_DC, GetPixel);
	Gura_AssignMethod(wx_DC, GetPPI);
	Gura_AssignMethod(wx_DC, GetSize);
	Gura_AssignMethod(wx_DC, GetSizeAsList);
	Gura_AssignMethod(wx_DC, GetSizeMM);
	Gura_AssignMethod(wx_DC, GetSizeMMAsList);
	Gura_AssignMethod(wx_DC, GetTextBackground);
	Gura_AssignMethod(wx_DC, GetTextExtent);
	Gura_AssignMethod(wx_DC, GetTextExtent_1);
	Gura_AssignMethod(wx_DC, GetTextForeground);
	Gura_AssignMethod(wx_DC, GetUserScale);
	Gura_AssignMethod(wx_DC, GradientFillConcentric);
	Gura_AssignMethod(wx_DC, GradientFillLinear);
	Gura_AssignMethod(wx_DC, LogicalToDeviceX);
	Gura_AssignMethod(wx_DC, LogicalToDeviceXRel);
	Gura_AssignMethod(wx_DC, LogicalToDeviceY);
	Gura_AssignMethod(wx_DC, LogicalToDeviceYRel);
	Gura_AssignMethod(wx_DC, MaxX);
	Gura_AssignMethod(wx_DC, MaxY);
	Gura_AssignMethod(wx_DC, MinX);
	Gura_AssignMethod(wx_DC, MinY);
	//Gura_AssignMethod(wx_DC, Ok);
	Gura_AssignMethod(wx_DC, ResetBoundingBox);
	Gura_AssignMethod(wx_DC, SetAxisOrientation);
	Gura_AssignMethod(wx_DC, SetBackground);
	Gura_AssignMethod(wx_DC, SetBackgroundMode);
	Gura_AssignMethod(wx_DC, SetBrush);
	Gura_AssignMethod(wx_DC, SetClippingRegion);
	Gura_AssignMethod(wx_DC, SetClippingRegionPointSize);
	Gura_AssignMethod(wx_DC, SetClippingRect);
	Gura_AssignMethod(wx_DC, SetClippingRegionAsRegion);
	Gura_AssignMethod(wx_DC, SetDeviceOrigin);
	Gura_AssignMethod(wx_DC, SetFont);
	Gura_AssignMethod(wx_DC, SetLayoutDirection);
	Gura_AssignMethod(wx_DC, SetLogicalFunction);
	Gura_AssignMethod(wx_DC, SetMapMode);
	Gura_AssignMethod(wx_DC, SetPalette);
	Gura_AssignMethod(wx_DC, SetPen);
	Gura_AssignMethod(wx_DC, SetTextBackground);
	Gura_AssignMethod(wx_DC, SetTextForeground);
	Gura_AssignMethod(wx_DC, SetUserScale);
	Gura_AssignMethod(wx_DC, StartDoc);
	Gura_AssignMethod(wx_DC, StartPage);
}

Gura_ImplementDescendantCreator(wx_DC)
{
	return new Object_wx_DC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
