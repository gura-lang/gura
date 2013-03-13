//----------------------------------------------------------------------------
// wxRect
// extracted from rect.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Rect: public wxRect, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Rect *_pObj;
public:
	inline wx_Rect() : wxRect(), _sig(NULL), _pObj(NULL) {}
	inline wx_Rect(int x, int y, int width, int height) : wxRect(x, y, width, height), _sig(NULL), _pObj(NULL) {}
	inline wx_Rect(const wxPoint& topLeft, const wxPoint& bottomRight) : wxRect(topLeft, bottomRight), _sig(NULL), _pObj(NULL) {}
	inline wx_Rect(const wxPoint& pos, const wxSize& size) : wxRect(pos, size), _sig(NULL), _pObj(NULL) {}
	inline wx_Rect(const wxSize& size) : wxRect(size), _sig(NULL), _pObj(NULL) {}
	~wx_Rect();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Rect *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Rect::~wx_Rect()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Rect::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRect
//----------------------------------------------------------------------------
Gura_DeclareFunction(RectEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Rect));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(RectEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Rect *pEntity = new wx_Rect();
	Object_wx_Rect *pObj = Object_wx_Rect::GetThisObj(args);
	if (pObj == NULL) {
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == NULL) {
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == NULL) {
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == NULL) {
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	if (pObj == NULL) {
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, CenterIn)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, ContainsXY)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetBottom)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetPosition)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetTopLeft)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetTopLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetTopLeft();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetTopRight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetTopRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetTopRight();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetBottomLeft)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetBottomLeft)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetBottomLeft();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetBottomRight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetBottomRight)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetBottomRight();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetRight)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, GetSize)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSize rtn = pThis->GetEntity()->GetSize();
	return ReturnValue(env, sig, args, Value(new Object_wx_Size(new wxSize(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, GetTop)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, Intersect)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Intersect)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRect rtn = pThis->GetEntity()->Intersect(*rect);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, Intersect_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Intersect_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRect &rtn = pThis->GetEntity()->Intersect(*rect);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, Intersects)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
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
	SetMode(RSLTMODE_Normal, FLAG_None);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Void, FLAG_Map);
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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Union)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRect rtn = pThis->GetEntity()->Union(*rect);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, Union_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, Union_1)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxRect *rect = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRect &rtn = pThis->GetEntity()->Union(*rect);
	return ReturnValue(env, sig, args, Value(new Object_wx_Rect(new wxRect(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Rect, __eq__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, __eq__)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	wxRect *item1 = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRect *item2 = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	return *item1 == *item2;
}

Gura_DeclareMethod(wx_Rect, __ne__)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "item1", VTYPE_wx_Rect, OCCUR_Once);
	DeclareArg(env, "item2", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Rect, __ne__)
{
	Object_wx_Rect *pThis = Object_wx_Rect::GetThisObj(args);
	wxRect *item1 = Object_wx_Rect::GetObject(args, 0)->GetEntity();
	wxRect *item2 = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	return *item1 != *item2;
}

//----------------------------------------------------------------------------
// Object implementation for wxRect
//----------------------------------------------------------------------------
Object_wx_Rect::~Object_wx_Rect()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_Rect::Clone() const
{
	return new Object_wx_Rect(new wxRect(*dynamic_cast<wxRect *>(_pEntity)), NULL, OwnerTrue);
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
		if (!value.MustBeNumber(sig)) return Value::Null;
		GetEntity()->x = value.GetInt();
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(y))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		GetEntity()->y = value.GetInt();
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(width))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		GetEntity()->width = value.GetInt();
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(height))) {
		if (!value.MustBeNumber(sig)) return Value::Null;
		GetEntity()->height = value.GetInt();
		return value;
	}
	return Value::Null;
}

String Object_wx_Rect::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Rect:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Rect::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(RectEmpty);
	Gura_AssignFunction(Rect);
	Gura_AssignFunction(Rect_1);
	Gura_AssignFunction(Rect_2);
	Gura_AssignFunction(Rect_3);
}

//----------------------------------------------------------------------------
// Class implementation for wxRect
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Rect)
{
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
	Gura_AssignMethod(wx_Rect, __eq__);
	Gura_AssignMethod(wx_Rect, __ne__);
}

Gura_ImplementDescendantCreator(wx_Rect)
{
	return new Object_wx_Rect((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
