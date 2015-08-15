//----------------------------------------------------------------------------
// wxRegion
// extracted from region.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Region: public wxRegion, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Region *_pObj;
public:
	inline wx_Region() : wxRegion(), _pObj(nullptr) {}
	inline wx_Region(wxCoord x, wxCoord y, wxCoord width, wxCoord height) : wxRegion(x, y, width, height), _pObj(nullptr) {}
	inline wx_Region(const wxPoint& topLeft, const wxPoint& bottomRight) : wxRegion(topLeft, bottomRight), _pObj(nullptr) {}
	inline wx_Region(const wxRect& rect) : wxRegion(rect), _pObj(nullptr) {}
	inline wx_Region(const wxRegion& region) : wxRegion(region), _pObj(nullptr) {}
	inline wx_Region(size_t n, const wxPoint *points, wxPolygonFillMode fillStyle) : wxRegion(n, points, fillStyle), _pObj(nullptr) {}
	inline wx_Region(const wxBitmap& bmp) : wxRegion(bmp), _pObj(nullptr) {}
	inline wx_Region(const wxBitmap& bmp, const wxColour& transColour, int tolerance) : wxRegion(bmp, transColour, tolerance), _pObj(nullptr) {}
	~wx_Region();
	inline void AssocWithGura(Object_wx_Region *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Region::~wx_Region()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Region::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRegion
//----------------------------------------------------------------------------
Gura_DeclareFunction(RegionEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegionEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Region *pEntity = new wx_Region();
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Region)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Region)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	wx_Region *pEntity = new wx_Region(x, y, width, height);
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Region_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareArg(env, "topLeft", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "bottomRight", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Region_1)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxPoint *topLeft = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint *bottomRight = Object_wx_Point::GetObject(args, 1)->GetEntity();
	wx_Region *pEntity = new wx_Region(*topLeft, *bottomRight);
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(RegionRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegionRect)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wx_Region *pEntity = new wx_Region(*rect);
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(RegionPoints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareArg(env, "points", VTYPE_wx_Point, OCCUR_Once, FLAG_List);
	DeclareArg(env, "fillStyle", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegionPoints)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	size_t n = args.GetList(0).size();
	wxPoint *points = new wxPoint[n];
	size_t i = 0;
	foreach_const (ValueList, pValue, args.GetList(0)) {
		points[i++] = *Object_wx_Point::GetObject(*pValue)->GetEntity();
	}
	wxPolygonFillMode fillStyle = wxWINDING_RULE;
	if (args.IsValid(1)) fillStyle = static_cast<wxPolygonFillMode>(args.GetInt(1));
	wx_Region *pEntity = new wx_Region(n, points, fillStyle);
	delete[] points;
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(RegionFromBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareArg(env, "bmp", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "transColour", VTYPE_wx_Colour, OCCUR_ZeroOrOnce);
	DeclareArg(env, "tolerance", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RegionFromBitmap)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wx_Region *pEntity = nullptr;
	if (args.IsValid(1)) {
		wxColour *transColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
		int tolerance = 0;
		if (args.IsValid(2)) tolerance = args.GetInt(2);
		pEntity = new wx_Region(*bmp, *transColour, tolerance);
	} else {
		pEntity = new wx_Region(*bmp);
	}
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

#if 0
Gura_DeclareFunction(Region_6)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Region));
	DeclareArg(env, "bmp", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "transColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "tolerance", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Region_6)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxColour *transColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	int tolerance = 0;
	if (args.IsValid(2)) tolerance = args.GetInt(2);
	wx_Region *pEntity = new wx_Region(*bmp, *transColour, tolerance);
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}
#endif

Gura_DeclareMethod(wx_Region, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, Clear)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Region, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, Contains)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	wxRegionContain rtn = pThis->GetEntity()->Contains(x, y);
	return ReturnValue(env, args, Value(rtn != wxOutRegion));
}

Gura_DeclareMethod(wx_Region, ContainsPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, ContainsPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxRegionContain rtn = pThis->GetEntity()->Contains(*pt);
	return ReturnValue(env, args, Value(rtn != wxOutRegion));
}

Gura_DeclareMethod(wx_Region, ContainsRectDim)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, ContainsRectDim)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	long width = args.GetLong(2);
	long height = args.GetLong(3);
	wxRegionContain rtn = pThis->GetEntity()->Contains(x, y, width, height);
	return ReturnValue(env, args, Value(rtn != wxOutRegion));
}

Gura_DeclareMethod(wx_Region, ContainsRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, ContainsRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRegionContain rtn = pThis->GetEntity()->Contains(*rect);
	return ReturnValue(env, args, Value(rtn != wxOutRegion));
}

Gura_DeclareMethod(wx_Region, ConvertToBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, ConvertToBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap rtn = pThis->GetEntity()->ConvertToBitmap();
	return ReturnValue(env, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Region, GetBoxRectDim)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, GetBoxRectDim)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x;
	wxCoord y;
	wxCoord width;
	wxCoord height;
	pThis->GetEntity()->GetBox(x, y, width, height);
	return ReturnValue(env, args, Value::CreateList(env,
						Value(x), Value(y), Value(width), Value(height)));
}

Gura_DeclareMethod(wx_Region, GetBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, GetBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect rtn = pThis->GetEntity()->GetBox();
	return ReturnValue(env, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Region, Intersect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, Intersect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->Intersect(x, y, width, height);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, IntersectRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, IntersectRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Intersect(*rect);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, IntersectRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, IntersectRegion)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Intersect(*region);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, IsEmpty)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, IsEqual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, IsEqual)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsEqual(*region);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, SubtractRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, SubtractRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Subtract(*rect);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, SubtractRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, SubtractRegion)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Subtract(*region);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, Offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, Offset)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->Offset(x, y);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, OffsetPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, OffsetPoint)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Offset(*pt);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, Union)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, Union)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->Union(x, y, width, height);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, UnionRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, UnionRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Union(*rect);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, UnionRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, UnionRegion)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Union(*region);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, UnionBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bmp", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, UnionBitmap)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Union(*bmp);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, UnionBitmapColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bmp", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareArg(env, "transColour", VTYPE_wx_Colour, OCCUR_Once);
	DeclareArg(env, "tolerance", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, UnionBitmapColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxColour *transColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	int tolerance = 0;
	if (args.IsValid(2)) tolerance = args.GetInt(2);
	bool rtn = pThis->GetEntity()->Union(*bmp, *transColour, tolerance);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, Xor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, Xor)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->Xor(x, y, width, height);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, XorRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, XorRect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Xor(*rect);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, XorRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, XorRegion)
{
	Signal &sig = env.GetSignal();
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Xor(*region);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRegion
//----------------------------------------------------------------------------
Object_wx_Region::~Object_wx_Region()
{
}

Object *Object_wx_Region::Clone() const
{
	return nullptr;
}

String Object_wx_Region::ToString(bool exprFlag)
{
	String rtn("<wx.Region:");
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
// Class implementation for wxRegion
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Region)
{
	Gura_AssignFunction(RegionEmpty);
	Gura_AssignFunction(Region);
	Gura_AssignFunction(Region_1);
	Gura_AssignFunction(RegionRect);
	Gura_AssignFunction(RegionPoints);
	Gura_AssignFunction(RegionFromBitmap);
	//Gura_AssignFunction(Region_6);
	Gura_AssignMethod(wx_Region, Clear);
	Gura_AssignMethod(wx_Region, Contains);
	Gura_AssignMethod(wx_Region, ContainsPoint);
	Gura_AssignMethod(wx_Region, ContainsRect);
	Gura_AssignMethod(wx_Region, ContainsRectDim);
	Gura_AssignMethod(wx_Region, ConvertToBitmap);
	Gura_AssignMethod(wx_Region, GetBox);
	Gura_AssignMethod(wx_Region, GetBoxRectDim);
	Gura_AssignMethod(wx_Region, Intersect);
	Gura_AssignMethod(wx_Region, IntersectRect);
	Gura_AssignMethod(wx_Region, IntersectRegion);
	Gura_AssignMethod(wx_Region, IsEmpty);
	Gura_AssignMethod(wx_Region, IsEqual);
	Gura_AssignMethod(wx_Region, SubtractRect);
	Gura_AssignMethod(wx_Region, SubtractRegion);
	Gura_AssignMethod(wx_Region, Offset);
	Gura_AssignMethod(wx_Region, OffsetPoint);
	Gura_AssignMethod(wx_Region, Union);
	Gura_AssignMethod(wx_Region, UnionRect);
	Gura_AssignMethod(wx_Region, UnionRegion);
	Gura_AssignMethod(wx_Region, UnionBitmap);
	Gura_AssignMethod(wx_Region, UnionBitmapColour);
	Gura_AssignMethod(wx_Region, Xor);
	Gura_AssignMethod(wx_Region, XorRect);
	Gura_AssignMethod(wx_Region, XorRegion);
}

Gura_ImplementDescendantCreator(wx_Region)
{
	return new Object_wx_Region((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
