//----------------------------------------------------------------------------
// wxDC
// extracted from dc.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(ComputeScaleAndOrigin);
Gura_DeclarePrivUserSymbol(DrawLabel);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DC: public wxDC, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DC *_pObj;
public:
	//virtual void ComputeScaleAndOrigin();
	//virtual void DrawLabel(const wxString& text, const wxBitmap& image, const wxRect& rect, int alignment, int indexAccel, wxRect * rectBounding);
	~wx_DC();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DC *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DC::~wx_DC()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DC::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDC
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DC, Blit)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord xdest = static_cast<wxCoord>(args.GetInt(0));
	wxCoord ydest = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	wxDC *source = Object_wx_DC::GetObject(args, 4)->GetEntity();
	wxCoord xsrc = static_cast<wxCoord>(args.GetInt(5));
	wxCoord ysrc = static_cast<wxCoord>(args.GetInt(6));
	int logicalFunc = wxCOPY;
	if (args.IsValid(7)) logicalFunc = args.GetInt(7);
	bool useMask = false;
	if (args.IsValid(8)) useMask = args.GetBoolean(8);
	wxCoord xsrcMask = -1;
	if (args.IsValid(9)) xsrcMask = static_cast<wxCoord>(args.GetInt(9));
	wxCoord ysrcMask = -1;
	if (args.IsValid(10)) ysrcMask = static_cast<wxCoord>(args.GetInt(10));
	bool rtn = pThis->GetEntity()->Blit(xdest, ydest, width, height, source, xsrc, ysrc, logicalFunc, useMask, xsrcMask, ysrcMask);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DC, CacheEnabled)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DC, CacheEnabled)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	bool rtn = wxDC::CacheEnabled();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, CalcBoundingBox)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, CalcBoundingBox)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->CalcBoundingBox(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, Clear)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
}

Gura_DeclareClassMethod(wx_DC, ClearCache)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementClassMethod(wx_DC, ClearCache)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if defined(__WXMSW__)
	wxDC::ClearCache();
	return Value::Null;
#else
	SetError_MSWOnly(sig);
	return Value::Null;
#endif	
}

Gura_DeclareMethod(wx_DC, ComputeScaleAndOrigin)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, ComputeScaleAndOrigin)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ComputeScaleAndOrigin();
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, CrossHair)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, CrossHair)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->CrossHair(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DestroyClippingRegion)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, DestroyClippingRegion)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->DestroyClippingRegion();
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalX)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->DeviceToLogicalX(x);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalXRel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalXRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->DeviceToLogicalXRel(x);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalY)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord y = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->DeviceToLogicalY(y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, DeviceToLogicalYRel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DeviceToLogicalYRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord y = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->DeviceToLogicalYRel(y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, DrawArc)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xc", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "yc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawArc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x1 = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y1 = static_cast<wxCoord>(args.GetInt(1));
	wxCoord x2 = static_cast<wxCoord>(args.GetInt(2));
	wxCoord y2 = static_cast<wxCoord>(args.GetInt(3));
	wxCoord xc = static_cast<wxCoord>(args.GetInt(4));
	wxCoord yc = static_cast<wxCoord>(args.GetInt(5));
	pThis->GetEntity()->DrawArc(x1, y1, x2, y2, xc, yc);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawBitmap)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "bitmap", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "transparent", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawBitmap)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bitmap = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxCoord x = static_cast<wxCoord>(args.GetInt(1));
	wxCoord y = static_cast<wxCoord>(args.GetInt(2));
	bool transparent = args.GetBoolean(3);
	pThis->GetEntity()->DrawBitmap(*bitmap, x, y, transparent);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawCheckMark)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCheckMark)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	pThis->GetEntity()->DrawCheckMark(x, y, width, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawCheckMarkRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCheckMarkRect)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DrawCheckMark(*rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawCircle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCircle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord radius = static_cast<wxCoord>(args.GetInt(2));
	pThis->GetEntity()->DrawCircle(x, y, radius);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawCirclePoint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawCirclePoint)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxCoord radius = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->DrawCircle(*pt, radius);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawEllipse)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipse)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	pThis->GetEntity()->DrawEllipse(x, y, width, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawEllipsePointSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipsePointSize)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->DrawEllipse(*pt, *size);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawEllipseRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipseRect)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DrawEllipse(*rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawEllipticArc)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawEllipticArc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	double start = args.GetDouble(4);
	double end = args.GetDouble(5);
	pThis->GetEntity()->DrawEllipticArc(x, y, width, height, start, end);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawIcon)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "icon", VTYPE_wx_Icon, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawIcon)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxIcon *icon = Object_wx_Icon::GetObject(args, 0)->GetEntity();
	wxCoord x = static_cast<wxCoord>(args.GetInt(1));
	wxCoord y = static_cast<wxCoord>(args.GetInt(2));
	pThis->GetEntity()->DrawIcon(*icon, x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawLabel)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "image", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "indexAccel", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "rectBounding", VTYPE_wx_Rect, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DrawLabel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxBitmap *image = Object_wx_Bitmap::GetObject(args, 1)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 2)->GetEntity();
	int alignment = wxALIGN_LEFT | wxALIGN_TOP;
	if (args.IsValid(3)) alignment = args.GetInt(3);
	int indexAccel = -1;
	if (args.IsValid(4)) indexAccel = args.GetInt(4);
	wxRect *rectBounding = (wxRect *)(NULL);
	if (args.IsValid(5)) rectBounding = Object_wx_Rect::GetObject(args, 5)->GetEntity();
	pThis->GetEntity()->DrawLabel(text, *image, *rect, alignment, indexAccel, rectBounding);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawLabel_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "alignment", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "indexAccel", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DrawLabel_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	int alignment = wxALIGN_LEFT | wxALIGN_TOP;
	if (args.IsValid(2)) alignment = args.GetInt(2);
	int indexAccel = -1;
	if (args.IsValid(3)) indexAccel = args.GetInt(3);
	pThis->GetEntity()->DrawLabel(text, *rect, alignment, indexAccel);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawLine)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y1", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "x2", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawLine)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x1 = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y1 = static_cast<wxCoord>(args.GetInt(1));
	wxCoord x2 = static_cast<wxCoord>(args.GetInt(2));
	wxCoord y2 = static_cast<wxCoord>(args.GetInt(3));
	pThis->GetEntity()->DrawLine(x1, y1, x2, y2);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawLines)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "points", VTYPE_wx_Point, OCCUR_Once, FLAG_List);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DrawLines)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	CArrayOfPoint points(args.GetList(0));
	wxCoord xoffset = 0;
	if (args.IsValid(1)) xoffset = static_cast<wxCoord>(args.GetInt(1));
	wxCoord yoffset = 0;
	if (args.IsValid(2)) yoffset = static_cast<wxCoord>(args.GetInt(2));
	pThis->GetEntity()->DrawLines(points.Count(), points.Data(), xoffset, yoffset);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawPolygon)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "points", VTYPE_wx_Point, OCCUR_Once, FLAG_List);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "fill_style", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DrawPolygon)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	CArrayOfPoint points(args.GetList(0));
	wxCoord xoffset = 0;
	if (args.IsValid(1)) xoffset = static_cast<wxCoord>(args.GetInt(1));
	wxCoord yoffset = 0;
	if (args.IsValid(2)) yoffset = static_cast<wxCoord>(args.GetInt(2));
	int fill_style = wxODDEVEN_RULE;
	if (args.IsValid(3)) fill_style = args.GetInt(3);
	pThis->GetEntity()->DrawPolygon(points.Count(), points.Data(), xoffset, yoffset, fill_style);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawPolyPolygon)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "points", VTYPE_list, OCCUR_Once, FLAG_List | FLAG_NoMap);
	DeclareArg(env, "xoffset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "yoffset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "fill_style", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, DrawPolyPolygon)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
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
				return Value::Null;
			}
			points[iPoint++] = *Object_wx_Point::GetObject(*pValueElem)->GetEntity();
		}
	}
	wxCoord xoffset = 0;
	if (args.IsValid(1)) xoffset = static_cast<wxCoord>(args.GetInt(1));
	wxCoord yoffset = 0;
	if (args.IsValid(2)) yoffset = static_cast<wxCoord>(args.GetInt(2));
	int fill_style = wxODDEVEN_RULE;
	if (args.IsValid(3)) fill_style = args.GetInt(3);
	pThis->GetEntity()->DrawPolyPolygon(n, count, points, xoffset, yoffset, fill_style);
	delete[] count;
	delete[] points;
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawPoint)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawPoint)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->DrawPoint(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawRectangle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRectangle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	pThis->GetEntity()->DrawRectangle(x, y, width, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawRectanglePointSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRectanglePointSize)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxSize *sz = Object_wx_Size::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->DrawRectangle(*pt, *sz);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawRectangleRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRectangleRect)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->DrawRectangle(*rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawRotatedText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRotatedText)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxCoord x = static_cast<wxCoord>(args.GetInt(1));
	wxCoord y = static_cast<wxCoord>(args.GetInt(2));
	double angle = args.GetDouble(3);
	pThis->GetEntity()->DrawRotatedText(text, x, y, angle);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawRoundedRectangle)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRoundedRectangle)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	double radius = args.GetDouble(4);
	pThis->GetEntity()->DrawRoundedRectangle(x, y, width, height, radius);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawRoundedRectanglePointSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRoundedRectanglePointSize)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxSize *sz = Object_wx_Size::GetObject(args, 1)->GetEntity();
	double radius = args.GetDouble(2);
	pThis->GetEntity()->DrawRoundedRectangle(*pt, *sz, radius);
	return Value::Null;
}


Gura_DeclareMethod(wx_DC, DrawRoundedRectangleRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "radius", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawRoundedRectangleRect)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	double radius = args.GetDouble(1);
	pThis->GetEntity()->DrawRoundedRectangle(*rect, radius);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawSpline)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "points", VTYPE_wx_Point, OCCUR_Once, FLAG_List);
}

Gura_ImplementMethod(wx_DC, DrawSpline)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	CArrayOfPoint points(args.GetList(0));
	pThis->GetEntity()->DrawSpline(points.Count(), points.Data());
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, DrawText)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, DrawText)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	wxCoord x = static_cast<wxCoord>(args.GetInt(1));
	wxCoord y = static_cast<wxCoord>(args.GetInt(2));
	pThis->GetEntity()->DrawText(text, x, y);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_DC, EnableCache)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "enableCache", VTYPE_boolean, OCCUR_Once);
#endif
}

Gura_ImplementClassMethod(wx_DC, EnableCache)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	bool enableCache = args.GetBoolean(0);
	wxDC::EnableCache(enableCache);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, EndDoc)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, EndDoc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->EndDoc();
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, EndPage)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, EndPage)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->EndPage();
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, FloodFill)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "style", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, FloodFill)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxColour *colour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	int style = wxFLOOD_SURFACE;
	if (args.IsValid(3)) style = args.GetInt(3);
	bool rtn = pThis->GetEntity()->FloodFill(x, y, *colour, style);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetBackground)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBrush &rtn = pThis->GetEntity()->GetBackground();
	return ReturnValue(env, sig, args, Value(new Object_wx_Brush(new wxBrush(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetBackgroundMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetBackgroundMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetBackgroundMode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetBrush)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetBrush)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxBrush &rtn = pThis->GetEntity()->GetBrush();
	return ReturnValue(env, sig, args, Value(new Object_wx_Brush(new wxBrush(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetCharHeight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetCharHeight)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetCharHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetCharWidth)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetCharWidth)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->GetCharWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetClippingBox)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetClippingBox)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x;
	wxCoord y;
	wxCoord width;
	wxCoord height;
	pThis->GetEntity()->GetClippingBox(&x, &y, &width, &height);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, x, y, width, height));
}

Gura_DeclareMethod(wx_DC, GetFont)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetFont)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxFont &rtn = pThis->GetEntity()->GetFont();
	return ReturnValue(env, sig, args, Value(new Object_wx_Font(new wxFont(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetLayoutDirection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetLayoutDirection)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLayoutDirection rtn = pThis->GetEntity()->GetLayoutDirection();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetLogicalFunction)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetLogicalFunction)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLogicalFunction();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetMapMode)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetMapMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMapMode();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetMultiLineTextExtent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetMultiLineTextExtent)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	wxFont *font = (wxFont *)(NULL);
	if (args.IsValid(4)) font = Object_wx_Font::GetObject(args, 4)->GetEntity();
	wxCoord w;
	wxCoord h;
	wxCoord heightLine;
	pThis->GetEntity()->GetMultiLineTextExtent(string, &w, &h, &heightLine, font);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, w, h, heightLine));
}

Gura_DeclareMethod(wx_DC, GetPartialTextExtents)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "text", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "widths", VTYPE_number, OCCUR_Once, FLAG_List);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetPartialTextExtents)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString text = wxString::FromUTF8(args.GetString(0));
	std::auto_ptr<wxArrayInt> widths(CreateArrayInt(args.GetList(1)));
	bool rtn = pThis->GetEntity()->GetPartialTextExtents(text, *widths);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetPen)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetPen)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxPen &rtn = pThis->GetEntity()->GetPen();
	return ReturnValue(env, sig, args, Value(new Object_wx_Pen(new wxPen(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetPixel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetPixel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxColour *colour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	bool rtn = pThis->GetEntity()->GetPixel(x, y, colour);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, GetPPI)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetPPI)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetPPI();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetSizeAsList)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetSizeAsList)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord width;
	wxCoord height;
	pThis->GetEntity()->GetSize(&width, &height);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, width, height));
}

Gura_DeclareMethod(wx_DC, GetSize)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetSize)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetSizeMMAsList)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetSizeMMAsList)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord width;
	wxCoord height;
	pThis->GetEntity()->GetSizeMM(&width, &height);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, width, height));
}

Gura_DeclareMethod(wx_DC, GetSizeMM)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetSizeMM)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetSizeMM();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetTextBackground)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetTextBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetTextBackground();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetTextExtent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetTextExtent)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	wxFont *font = (wxFont *)(NULL);
	if (args.IsValid(1)) font = Object_wx_Font::GetObject(args, 1)->GetEntity();
	wxCoord w;
	wxCoord h;
	wxCoord descent;
	wxCoord externalLeading;
	pThis->GetEntity()->GetTextExtent(string, &w, &h, &descent, &externalLeading, font);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, w, h, descent, externalLeading));
}

Gura_DeclareMethod(wx_DC, GetTextExtent_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "string", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetTextExtent_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString string = wxString::FromUTF8(args.GetString(0));
	wxSize rtn = pThis->GetEntity()->GetTextExtent(string);
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetTextForeground)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetTextForeground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	const wxColour &rtn = pThis->GetEntity()->GetTextForeground();
	return ReturnValue(env, sig, args, Value(new Object_wx_Colour(new wxColour(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DC, GetUserScale)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GetUserScale)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double x;
	double y;
	pThis->GetEntity()->GetUserScale(&x, &y);
	return ReturnValue(env, sig, args, Value::CreateAsList(env, x, y));
}

Gura_DeclareMethod(wx_DC, GradientFillConcentric)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "initialColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "destColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "circleCenter", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GradientFillConcentric)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxColour *initialColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxColour *destColour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	if (args.IsValid(3)) {
		wxPoint *circleCenter = Object_wx_Point::GetObject(args, 3)->GetEntity();
		pThis->GetEntity()->GradientFillConcentric(*rect, *initialColour, *destColour, *circleCenter);
	} else {
		pThis->GetEntity()->GradientFillConcentric(*rect, *initialColour, *destColour);
	}
	return Value::Null;
}

#if 0
Gura_DeclareMethod(wx_DC, GradientFillConcentric_1)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "initialColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "destColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "circleCenter", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, GradientFillConcentric_1)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxColour *initialColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxColour *destColour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	wxPoint *circleCenter = Object_wx_Point::GetObject(args, 3)->GetEntity();
	pThis->GetEntity()->GradientFillConcentric(*rect, *initialColour, *destColour, *circleCenter);
	return Value::Null;
}
#endif

Gura_DeclareMethod(wx_DC, GradientFillLinear)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "initialColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "destColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "nDirection", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, GradientFillLinear)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxColour *initialColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	wxColour *destColour = Object_wx_Colour::GetObject(args, 2)->GetEntity();
	wxDirection nDirection = wxEAST;
	if (args.IsValid(3)) nDirection = static_cast<wxDirection>(args.GetInt(3));
	pThis->GetEntity()->GradientFillLinear(*rect, *initialColour, *destColour, nDirection);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceX)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->LogicalToDeviceX(x);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceXRel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceXRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->LogicalToDeviceXRel(x);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceY)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord y = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->LogicalToDeviceY(y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, LogicalToDeviceYRel)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, LogicalToDeviceYRel)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord y = static_cast<wxCoord>(args.GetInt(0));
	wxCoord rtn = pThis->GetEntity()->LogicalToDeviceYRel(y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, MaxX)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, MaxX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->MaxX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, MaxY)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, MaxY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->MaxY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, MinX)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, MinX)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->MinX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, MinY)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, MinY)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord rtn = pThis->GetEntity()->MinY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, Ok)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, Ok)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->Ok();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, ResetBoundingBox)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DC, ResetBoundingBox)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->ResetBoundingBox();
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetAxisOrientation)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xLeftRight", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "yBottomUp", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetAxisOrientation)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool xLeftRight = args.GetBoolean(0);
	bool yBottomUp = args.GetBoolean(1);
	pThis->GetEntity()->SetAxisOrientation(xLeftRight, yBottomUp);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetBackground)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "brush", VTYPE_wx_Brush, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBrush *brush = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBackground(*brush);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetBackgroundMode)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetBackgroundMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int mode = args.GetInt(0);
	pThis->GetEntity()->SetBackgroundMode(mode);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetBrush)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "brush", VTYPE_wx_Brush, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetBrush)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBrush *brush = Object_wx_Brush::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetBrush(*brush);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetClippingRegion)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRegion)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	pThis->GetEntity()->SetClippingRegion(x, y, width, height);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetClippingRegionPointSize)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "sz", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRegionPointSize)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxSize *sz = Object_wx_Size::GetObject(args, 1)->GetEntity();
	pThis->GetEntity()->SetClippingRegion(*pt, *sz);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetClippingRect)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRect)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetClippingRegion(*rect);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetClippingRegionAsRegion)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetClippingRegionAsRegion)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetClippingRegion(*region);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetDeviceOrigin)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetDeviceOrigin)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->SetDeviceOrigin(x, y);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetFont)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "font", VTYPE_wx_Font, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetFont)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxFont *font = Object_wx_Font::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetFont(*font);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetLayoutDirection)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetLayoutDirection)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLayoutDirection dir = static_cast<wxLayoutDirection>(args.GetInt(0));
	pThis->GetEntity()->SetLayoutDirection(dir);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetLogicalFunction)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "function", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetLogicalFunction)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int function = args.GetInt(0);
	pThis->GetEntity()->SetLogicalFunction(function);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetMapMode)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetMapMode)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int mode = args.GetInt(0);
	pThis->GetEntity()->SetMapMode(mode);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetPalette)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "palette", VTYPE_wx_Palette, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetPalette)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPalette *palette = Object_wx_Palette::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPalette(*palette);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetPen)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pen", VTYPE_wx_Pen, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetPen)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPen *pen = Object_wx_Pen::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetPen(*pen);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetTextBackground)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetTextBackground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextBackground(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetTextForeground)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "colour", VTYPE_wx_Colour, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetTextForeground)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxColour *colour = Object_wx_Colour::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetTextForeground(*colour);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, SetUserScale)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "xScale", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "yScale", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DC, SetUserScale)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double xScale = args.GetDouble(0);
	double yScale = args.GetDouble(1);
	pThis->GetEntity()->SetUserScale(xScale, yScale);
	return Value::Null;
}

Gura_DeclareMethod(wx_DC, StartDoc)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "message", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, StartDoc)
{
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString message = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->StartDoc(message);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DC, StartPage)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DC, StartPage)
{
#if 0
	Object_wx_DC *pThis = Object_wx_DC::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->StartPage();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDC
//----------------------------------------------------------------------------
Object_wx_DC::~Object_wx_DC()
{
}

Object *Object_wx_DC::Clone() const
{
	return NULL;
}

String Object_wx_DC::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DC:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DC::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(ComputeScaleAndOrigin);
	Gura_RealizeUserSymbol(DrawLabel);
}

//----------------------------------------------------------------------------
// Class implementation for wxDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DC)
{
	Gura_AssignMethod(wx_DC, Blit);
	Gura_AssignMethod(wx_DC, CacheEnabled);
	Gura_AssignMethod(wx_DC, CalcBoundingBox);
	Gura_AssignMethod(wx_DC, Clear);
	Gura_AssignMethod(wx_DC, ClearCache);
	Gura_AssignMethod(wx_DC, ComputeScaleAndOrigin);
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
	Gura_AssignMethod(wx_DC, Ok);
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
	return new Object_wx_DC((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
