//----------------------------------------------------------------------------
// wxRect
// extracted from rect.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Rect: public wxRect, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Rect *_pObj;
public:
	inline wx_Rect() : wxRect(), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Rect(int x, int y, int width, int height) : wxRect(x, y, width, height), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Rect(const wxPoint& topLeft, const wxPoint& bottomRight) : wxRect(topLeft, bottomRight), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Rect(const wxPoint& pos, const wxSize& size) : wxRect(pos, size), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Rect(const wxSize& size) : wxRect(size), _sig(nullptr), _pObj(nullptr) {}
	~wx_Rect();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Rect *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Rect::~wx_Rect()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Rect::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRect
//----------------------------------------------------------------------------
Gura_DeclareFunction(RectEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RectEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Rect *pEntity = new wx_Rect();
	Object_wx_Rect *pObj = Object_wx_Rect::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Rect(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Rect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Rect)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	int width = args.GetInt(2);
	int height = args.GetInt(3);
	wx_Rect *pEntity = new wx_Rect(x, y, width, height);
	Object_wx_Rect *pObj = Object_wx_Rect::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Rect(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Rect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareArg(env, "topLeft", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "bottomRight", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Rect_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPoint *topLeft = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxPoint *bottomRight = Object_wx_Point::GetObject(args, 1)->GetEntity();
	wx_Rect *pEntity = new wx_Rect(*topLeft, *bottomRight);
	Object_wx_Rect *pObj = Object_wx_Rect::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Rect(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Rect_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareArg(env, "pos", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Rect_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPoint *pos = Object_wx_Point::GetObject(args, 0)->GetEntity();
	wxSize *size = Object_wx_Size::GetObject(args, 1)->GetEntity();
	wx_Rect *pEntity = new wx_Rect(*pos, *size);
	Object_wx_Rect *pObj = Object_wx_Rect::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Rect(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(Rect_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareArg(env, "size", VTYPE_wx_Size, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Rect_3)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSize *size = Object_wx_Size::GetObject(args, 0)->GetEntity();
	wx_Rect *pEntity = new wx_Rect(*size);
	Object_wx_Rect *pObj = Object_wx_Rect::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Rect(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Rect, CentreIn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "r", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "dir", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, CentreIn)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *r = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	int dir = wxBOTH;
	if (args.IsValid(1)) dir = args.GetInt(1);
	wxRect rtn = pThis->GetEntity()->CentreIn(*r, dir);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, CenterIn)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "r", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "dir", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, CenterIn)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *r = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	int dir = wxBOTH;
	if (args.IsValid(1)) dir = args.GetInt(1);
	wxRect rtn = pThis->GetEntity()->CenterIn(*r, dir);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, ContainsXY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, ContainsXY)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	int y = args.GetInt(1);
	bool rtn = pThis->GetEntity()->Contains(x, y);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, Contains)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Contains)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Contains(*pt);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, ContainsRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, ContainsRect)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Contains(*rect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, Deflate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Deflate)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord dx = static_cast<wxCoord>(args.GetInt(0));
	wxCoord dy = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->Deflate(dx, dy);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, Deflate_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "diff", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Deflate_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *diff = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Deflate(*diff);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, Deflate_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Deflate_2)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord diff = static_cast<wxCoord>(args.GetInt(0));
	pThis->GetEntity()->Deflate(diff);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, Deflate_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Deflate_3)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord dx = static_cast<wxCoord>(args.GetInt(0));
	wxCoord dy = static_cast<wxCoord>(args.GetInt(1));
	wxRect rtn = pThis->GetEntity()->Deflate(dx, dy);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetBottom)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetBottom)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetBottom();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, GetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetHeight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetHeight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, GetLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetLeft();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetPosition)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetTopLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetTopLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetTopLeft();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetTopRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetTopRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetTopRight();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetBottomLeft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetBottomLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetBottomLeft();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetBottomRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetBottomRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetBottomRight();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetRight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRight();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, GetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetSize)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetTop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetTop)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTop();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, GetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetWidth)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWidth();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetX)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetX();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetY)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetY();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, Inflate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Inflate)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord dx = static_cast<wxCoord>(args.GetInt(0));
	wxCoord dy = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->Inflate(dx, dy);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, Inflate_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "diff", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Inflate_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *diff = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Inflate(*diff);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, Inflate_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Inflate_2)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord diff = static_cast<wxCoord>(args.GetInt(0));
	pThis->GetEntity()->Inflate(diff);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, Inflate_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Inflate_3)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord dx = static_cast<wxCoord>(args.GetInt(0));
	wxCoord dy = static_cast<wxCoord>(args.GetInt(1));
	wxRect rtn = pThis->GetEntity()->Inflate(dx, dy);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, Intersect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Intersect)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRect rtn = pThis->GetEntity()->Intersect(*rect);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, Intersect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Intersect_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRect &rtn = pThis->GetEntity()->Intersect(*rect);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, Intersects)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Intersects)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->Intersects(*rect);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, IsEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, IsEmpty)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsEmpty();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Rect, Offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Offset)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCoord dx = static_cast<wxCoord>(args.GetInt(0));
	wxCoord dy = static_cast<wxCoord>(args.GetInt(1));
	pThis->GetEntity()->Offset(dx, dy);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, Offset_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, Offset_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->Offset(*pt);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, SetHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "height", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetHeight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int height = args.GetInt(0);
	pThis->GetEntity()->SetHeight(height);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, SetSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "s", VTYPE_wx_Size, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetSize)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize *s = Object_wx_Size::GetObject(args, 0)->GetEntity();
	pThis->GetEntity()->SetSize(*s);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, SetWidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "width", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetWidth)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int width = args.GetInt(0);
	pThis->GetEntity()->SetWidth(width);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, SetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetX)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int x = args.GetInt(0);
	pThis->GetEntity()->SetX(x);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, SetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Rect, SetY)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int y = args.GetInt(0);
	pThis->GetEntity()->SetY(y);
	return Value::Null;
}

Gura_DeclareMethod(wx_Rect, Union)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Union)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRect rtn = pThis->GetEntity()->Union(*rect);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, Union_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Union_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRect &rtn = pThis->GetEntity()->Union(*rect);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), nullptr, OwnerTrue)));
}

// operator ==
Gura_ImplementBinaryOperator(Eq, wx_Rect, wx_Rect)
{
	wxRect *item1 = Object_wx_Rect::GetObject(valueLeft)->GetEntity();
	wxRect *item2 = Object_wx_Rect::GetObject(valueRight)->GetEntity();
	return *item1 == *item2;
}

// operator !=
Gura_ImplementBinaryOperator(Ne, wx_Rect, wx_Rect)
{
	wxRect *item1 = Object_wx_Rect::GetObject(valueLeft)->GetEntity();
	wxRect *item2 = Object_wx_Rect::GetObject(valueRight)->GetEntity();
	return *item1 != *item2;
}

//----------------------------------------------------------------------------
// Object implementation for wxRect
//----------------------------------------------------------------------------
Object_wx_Rect::~Object_wx_Rect()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_Rect::Clone() const
{
	return new Object_wx_Rect(new wxRect(*dynamic_cast<wxRect *>(_pEntity)), nullptr, OwnerTrue);
}

bool Object_wx_Rect::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(x));
	symbols.insert(Gura_Symbol(y));
	symbols.insert(Gura_Symbol(width));
	symbols.insert(Gura_Symbol(height));
	return true;
}

Value Object_wx_Rect::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		return Value(GetEntity()->x);
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		return Value(GetEntity()->y);
	} else if (pSymbol->IsIdentical(Gura_Symbol(width))) {
		return Value(GetEntity()->width);
	} else if (pSymbol->IsIdentical(Gura_Symbol(height))) {
		return Value(GetEntity()->height);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_wx_Rect::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	if (pSymbol->IsIdentical(Gura_Symbol(x))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		GetEntity()->x = value.GetInt();
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		GetEntity()->y = value.GetInt();
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(width))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		GetEntity()->width = value.GetInt();
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(height))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		GetEntity()->height = value.GetInt();
		return value;
	}
	return Value::Null;
}

String Object_wx_Rect::ToString(bool exprFlag)
{
	String rtn("<wx.Rect:");
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
// Class implementation for wxRect
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Rect)
{
	Gura_AssignFunction(RectEmpty);
	Gura_AssignFunction(Rect);
	Gura_AssignFunction(Rect_1);
	Gura_AssignFunction(Rect_2);
	Gura_AssignFunction(Rect_3);
	Gura_AssignBinaryOperator(Eq, wx_Rect, wx_Rect);
	Gura_AssignBinaryOperator(Ne, wx_Rect, wx_Rect);
	Gura_AssignMethod(wx_Rect, CentreIn);
	Gura_AssignMethod(wx_Rect, CenterIn);
	Gura_AssignMethod(wx_Rect, ContainsXY);
	Gura_AssignMethod(wx_Rect, Contains);
	Gura_AssignMethod(wx_Rect, ContainsRect);
	Gura_AssignMethod(wx_Rect, Deflate);
	Gura_AssignMethod(wx_Rect, Deflate_1);
	Gura_AssignMethod(wx_Rect, Deflate_2);
	Gura_AssignMethod(wx_Rect, Deflate_3);
	Gura_AssignMethod(wx_Rect, GetBottom);
	Gura_AssignMethod(wx_Rect, GetHeight);
	Gura_AssignMethod(wx_Rect, GetLeft);
	Gura_AssignMethod(wx_Rect, GetPosition);
	Gura_AssignMethod(wx_Rect, GetTopLeft);
	Gura_AssignMethod(wx_Rect, GetTopRight);
	Gura_AssignMethod(wx_Rect, GetBottomLeft);
	Gura_AssignMethod(wx_Rect, GetBottomRight);
	Gura_AssignMethod(wx_Rect, GetRight);
	Gura_AssignMethod(wx_Rect, GetSize);
	Gura_AssignMethod(wx_Rect, GetTop);
	Gura_AssignMethod(wx_Rect, GetWidth);
	Gura_AssignMethod(wx_Rect, GetX);
	Gura_AssignMethod(wx_Rect, GetY);
	Gura_AssignMethod(wx_Rect, Inflate);
	Gura_AssignMethod(wx_Rect, Inflate_1);
	Gura_AssignMethod(wx_Rect, Inflate_2);
	Gura_AssignMethod(wx_Rect, Inflate_3);
	Gura_AssignMethod(wx_Rect, Intersect);
	Gura_AssignMethod(wx_Rect, Intersect_1);
	Gura_AssignMethod(wx_Rect, Intersects);
	Gura_AssignMethod(wx_Rect, IsEmpty);
	Gura_AssignMethod(wx_Rect, Offset);
	Gura_AssignMethod(wx_Rect, Offset_1);
	Gura_AssignMethod(wx_Rect, SetHeight);
	Gura_AssignMethod(wx_Rect, SetSize);
	Gura_AssignMethod(wx_Rect, SetWidth);
	Gura_AssignMethod(wx_Rect, SetX);
	Gura_AssignMethod(wx_Rect, SetY);
	Gura_AssignMethod(wx_Rect, Union);
	Gura_AssignMethod(wx_Rect, Union_1);
}

Gura_ImplementDescendantCreator(wx_Rect)
{
	return new Object_wx_Rect((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
