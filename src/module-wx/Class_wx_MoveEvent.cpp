//----------------------------------------------------------------------------
// wxMoveEvent
// extracted from moveevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MoveEvent: public wxMoveEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_MoveEvent *_pObj;
public:
	inline wx_MoveEvent(const wxPoint& pt, int id) : wxMoveEvent(pt, id), _pObj(nullptr) {}
	~wx_MoveEvent();
	inline void AssocWithGura(Object_wx_MoveEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MoveEvent::~wx_MoveEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_MoveEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMoveEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(MoveEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MoveEvent));
	DeclareArg(env, "pt", VTYPE_wx_Point, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MoveEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxPoint *pt = Object_wx_Point::GetObject(args, 0)->GetEntity();
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_MoveEvent *pEntity = new wx_MoveEvent(*pt, id);
	Object_wx_MoveEvent *pObj = Object_wx_MoveEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_MoveEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_MoveEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MoveEvent, GetPosition)
{
	Object_wx_MoveEvent *pThis = Object_wx_MoveEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxMoveEvent
//----------------------------------------------------------------------------
Object_wx_MoveEvent::~Object_wx_MoveEvent()
{
}

Object *Object_wx_MoveEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MoveEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MoveEvent:");
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
// Class implementation for wxMoveEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MoveEvent)
{
	Gura_AssignFunction(MoveEvent);
	Gura_AssignMethod(wx_MoveEvent, GetPosition);
}

Gura_ImplementDescendantCreator(wx_MoveEvent)
{
	return new Object_wx_MoveEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
