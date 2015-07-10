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
	Gura::Signal *_pSig;
	Object_wx_Region *_pObj;
public:
	inline wx_Region() : wxRegion(), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_Region(wxCoord x, wxCoord y, wxCoord width, wxCoord height) : wxRegion(x, y, width, height), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_Region(const wxPoint& topLeft, const wxPoint& bottomRight) : wxRegion(topLeft, bottomRight), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_Region(const wxRect& rect) : wxRegion(rect), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_Region(const wxRegion& region) : wxRegion(region), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_Region(size_t n, const wxPoint *points, wxPolygonFillMode fillStyle) : wxRegion(n, points, fillStyle), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_Region(const wxBitmap& bmp) : wxRegion(bmp), _pSig(nullptr), _pObj(nullptr) {}
	inline wx_Region(const wxBitmap& bmp, const wxColour& transColour, int tolerance) : wxRegion(bmp, transColour, tolerance), _pSig(nullptr), _pObj(nullptr) {}
	~wx_Region();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Region *pObj) {
		_pSig = &sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Region *pEntity = new wx_Region();
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	wx_Region *pEntity = new wx_Region(x, y, width, height);
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxPoint *topLeft = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint *bottomRight = Object_wx_Point::GetObject(args, 1)->GetEntity();
	wx_Region *pEntity = new wx_Region(*topLeft, *bottomRight);
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wx_Region *pEntity = new wx_Region(*rect);
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
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
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
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
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxColour *transColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	int tolerance = 0;
	if (args.IsValid(2)) tolerance = args.GetInt(2);
	wx_Region *pEntity = new wx_Region(*bmp, *transColour, tolerance);
	Object_wx_Region *pObj = Object_wx_Region::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Region(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}
#endif

Gura_DeclareMethod(wx_Region, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Region, Clear)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
	return Value::Null;
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
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	wxRegionContain rtn = pThis->GetEntity()->Contains(x, y);
	return ReturnValue(env, sig, args, Value(rtn != wxOutRegion));
}

Gura_DeclareMethod(wx_Region, ContainsPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, ContainsPoint)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxRegionContain rtn = pThis->GetEntity()->Contains(*pt);
	return ReturnValue(env, sig, args, Value(rtn != wxOutRegion));
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
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long x = args.GetLong(0);
	long y = args.GetLong(1);
	long width = args.GetLong(2);
	long height = args.GetLong(3);
	wxRegionContain rtn = pThis->GetEntity()->Contains(x, y, width, height);
	return ReturnValue(env, sig, args, Value(rtn != wxOutRegion));
}

Gura_DeclareMethod(wx_Region, ContainsRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, ContainsRect)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRegionContain rtn = pThis->GetEntity()->Contains(*rect);
	return ReturnValue(env, sig, args, Value(rtn != wxOutRegion));
}

Gura_DeclareMethod(wx_Region, ConvertToBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, ConvertToBitmap)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap rtn = pThis->GetEntity()->ConvertToBitmap();
	return ReturnValue(env, sig, args, Value(new Object_wx_Bitmap(new wxBitmap(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Region, GetBoxRectDim)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, GetBoxRectDim)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x;
	wxCoord y;
	wxCoord width;
	wxCoord height;
	pThis->GetEntity()->GetBox(x, y, width, height);
	return ReturnValue(env, sig, args, Value::CreateList(env,
						Value(x), Value(y), Value(width), Value(height)));
}

Gura_DeclareMethod(wx_Region, GetBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, GetBox)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect rtn = pThis->GetEntity()->GetBox();
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
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
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->Intersect(x, y, width, height);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, IntersectRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, IntersectRect)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Intersect(*rect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, IntersectRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, IntersectRegion)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Intersect(*region);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, IsEmpty)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, IsEqual)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, IsEqual)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsEqual(*region);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, SubtractRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, SubtractRect)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Subtract(*rect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, SubtractRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, SubtractRegion)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Subtract(*region);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	bool rtn = pThis->GetEntity()->Offset(x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, OffsetPoint)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, OffsetPoint)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Offset(*pt);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->Union(x, y, width, height);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, UnionRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, UnionRect)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Union(*rect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, UnionRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, UnionRegion)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Union(*region);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, UnionBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "bmp", VTYPE_wx_Bitmap, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, UnionBitmap)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Union(*bmp);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxBitmap *bmp = Object_wx_Bitmap::GetObject(args, 0)->GetEntity();
	wxColour *transColour = Object_wx_Colour::GetObject(args, 1)->GetEntity();
	int tolerance = 0;
	if (args.IsValid(2)) tolerance = args.GetInt(2);
	bool rtn = pThis->GetEntity()->Union(*bmp, *transColour, tolerance);
	return ReturnValue(env, sig, args, Value(rtn));
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
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord x = static_cast<wxCoord>(args.GetInt(0));
	wxCoord y = static_cast<wxCoord>(args.GetInt(1));
	wxCoord width = static_cast<wxCoord>(args.GetInt(2));
	wxCoord height = static_cast<wxCoord>(args.GetInt(3));
	bool rtn = pThis->GetEntity()->Xor(x, y, width, height);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, XorRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, XorRect)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Xor(*rect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Region, XorRegion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "region", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Region, XorRegion)
{
	Object_wx_Region *pThis = Object_wx_Region::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRegion *region = Object_wx_Region::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Xor(*region);
	return ReturnValue(env, sig, args, Value(rtn));
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
