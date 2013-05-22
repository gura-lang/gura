//----------------------------------------------------------------------------
// wxNotifyEvent
// extracted from notifevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_NotifyEvent: public wxNotifyEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_NotifyEvent *_pObj;
public:
	inline wx_NotifyEvent(wxEventType eventType, int id) : wxNotifyEvent(eventType, id), _sig(NULL), _pObj(NULL) {}
	~wx_NotifyEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_NotifyEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_NotifyEvent::~wx_NotifyEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_NotifyEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxNotifyEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(NotifyEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_NotifyEvent));
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(NotifyEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxEventType eventType = wxEVT_NULL;
	if (args.IsValid(0)) eventType = static_cast<wxEventType>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_NotifyEvent *pEntity = new wx_NotifyEvent(eventType, id);
	Object_wx_NotifyEvent *pObj = Object_wx_NotifyEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_NotifyEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_NotifyEvent, Allow)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NotifyEvent, Allow)
{
	Object_wx_NotifyEvent *pThis = Object_wx_NotifyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Allow();
	return Value::Null;
}

Gura_DeclareMethod(wx_NotifyEvent, IsAllowed)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_NotifyEvent, IsAllowed)
{
	Object_wx_NotifyEvent *pThis = Object_wx_NotifyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsAllowed();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_NotifyEvent, Veto)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NotifyEvent, Veto)
{
	Object_wx_NotifyEvent *pThis = Object_wx_NotifyEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Veto();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxNotifyEvent
//----------------------------------------------------------------------------
Object_wx_NotifyEvent::~Object_wx_NotifyEvent()
{
}

Object *Object_wx_NotifyEvent::Clone() const
{
	return NULL;
}

String Object_wx_NotifyEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.NotifyEvent:");
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
// Class implementation for wxNotifyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NotifyEvent)
{
	Gura_AssignFunction(NotifyEvent);
	Gura_AssignMethod(wx_NotifyEvent, Allow);
	Gura_AssignMethod(wx_NotifyEvent, IsAllowed);
	Gura_AssignMethod(wx_NotifyEvent, Veto);
}

Gura_ImplementDescendantCreator(wx_NotifyEvent)
{
	return new Object_wx_NotifyEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
