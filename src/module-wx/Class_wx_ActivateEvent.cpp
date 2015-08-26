//----------------------------------------------------------------------------
// wxActivateEvent
// extracted from activevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ActivateEvent: public wxActivateEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_ActivateEvent *_pObj;
public:
	inline wx_ActivateEvent(WXTYPE eventType, bool active, int id) : wxActivateEvent(eventType, active, id), _pObj(nullptr) {}
	~wx_ActivateEvent();
	inline void AssocWithGura(Object_wx_ActivateEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ActivateEvent::~wx_ActivateEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_ActivateEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxActivateEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ActivateEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ActivateEvent));
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "active", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ActivateEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	WXTYPE eventType = 0;
	if (args.IsValid(0)) eventType = static_cast<WXTYPE>(args.GetInt(0));
	bool active = true;
	if (args.IsValid(1)) active = args.GetBoolean(1);
	int id = 0;
	if (args.IsValid(2)) id = args.GetInt(2);
	wx_ActivateEvent *pEntity = new wx_ActivateEvent(eventType, active, id);
	Object_wx_ActivateEvent *pObj = Object_wx_ActivateEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_ActivateEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_ActivateEvent, GetActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ActivateEvent, GetActive)
{
	Signal &sig = env.GetSignal();
	Object_wx_ActivateEvent *pThis = Object_wx_ActivateEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetActive();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxActivateEvent
//----------------------------------------------------------------------------
Object_wx_ActivateEvent::~Object_wx_ActivateEvent()
{
}

Object *Object_wx_ActivateEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ActivateEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ActivateEvent:");
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
// Class implementation for wxActivateEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActivateEvent)
{
	Gura_AssignFunction(ActivateEvent);
	Gura_AssignMethod(wx_ActivateEvent, GetActive);
}

Gura_ImplementDescendantCreator(wx_ActivateEvent)
{
	return new Object_wx_ActivateEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
