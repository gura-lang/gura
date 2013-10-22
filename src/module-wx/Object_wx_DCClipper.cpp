//----------------------------------------------------------------------------
// wxDCClipper
// extracted from dcclipper.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DCClipper: public wxDCClipper, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DCClipper *_pObj;
public:
	inline wx_DCClipper(wxDC& dc, const wxRegion& r) : wxDCClipper(dc, r), _sig(NULL), _pObj(NULL) {}
	inline wx_DCClipper(wxDC& dc, const wxRect& rect) : wxDCClipper(dc, rect), _sig(NULL), _pObj(NULL) {}
	inline wx_DCClipper(wxDC& dc, int x, int y, int w, int h) : wxDCClipper(dc, x, y, w, h), _sig(NULL), _pObj(NULL) {}
	~wx_DCClipper();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DCClipper *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DCClipper::~wx_DCClipper()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DCClipper::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDCClipper
//----------------------------------------------------------------------------
Gura_DeclareFunction(DCClipper)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DCClipper));
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "r", VTYPE_wx_Region, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DCClipper)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRegion *r = Object_wx_Region::GetObject(args, 1)->GetEntity();
	wx_DCClipper *pEntity = new wx_DCClipper(*dc, *r);
	Object_wx_DCClipper *pObj = Object_wx_DCClipper::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DCClipper(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(DCClipper_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DCClipper));
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "rect", VTYPE_wx_Rect, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DCClipper_1)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	wxRect *rect = Object_wx_Rect::GetObject(args, 1)->GetEntity();
	wx_DCClipper *pEntity = new wx_DCClipper(*dc, *rect);
	Object_wx_DCClipper *pObj = Object_wx_DCClipper::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DCClipper(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareFunction(DCClipper_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DCClipper));
	DeclareArg(env, "dc", VTYPE_wx_DC, OCCUR_Once);
	DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "w", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "h", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DCClipper_2)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDC *dc = Object_wx_DC::GetObject(args, 0)->GetEntity();
	int x = args.GetInt(1);
	int y = args.GetInt(2);
	int w = args.GetInt(3);
	int h = args.GetInt(4);
	wx_DCClipper *pEntity = new wx_DCClipper(*dc, x, y, w, h);
	Object_wx_DCClipper *pObj = Object_wx_DCClipper::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DCClipper(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

//----------------------------------------------------------------------------
// Object implementation for wxDCClipper
//----------------------------------------------------------------------------
Object_wx_DCClipper::~Object_wx_DCClipper()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DCClipper::Clone() const
{
	return NULL;
}

String Object_wx_DCClipper::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DCClipper:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxDCClipper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCClipper)
{
	Gura_AssignFunction(DCClipper);
	Gura_AssignFunction(DCClipper_1);
	Gura_AssignFunction(DCClipper_2);
}

Gura_ImplementDescendantCreator(wx_DCClipper)
{
	return new Object_wx_DCClipper((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
