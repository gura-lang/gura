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
	Gura::Signal _sig;
	Object_wx_ActivateEvent *_pObj;
public:
	inline wx_ActivateEvent(WXTYPE eventType, bool active, int id) : wxActivateEvent(eventType, active, id), _sig(NULL), _pObj(NULL) {}
	~wx_ActivateEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ActivateEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ActivateEvent::~wx_ActivateEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ActivateEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxActivateEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(ActivateEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_ActivateEvent));
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "active", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ActivateEvent)
{
	if (!CheckWxReady(sig)) return Value::Null;
	WXTYPE eventType = 0;
	if (args.IsValid(0)) eventType = static_cast<WXTYPE>(args.GetInt(0));
	bool active = true;
	if (args.IsValid(1)) active = args.GetBoolean(1);
	int id = 0;
	if (args.IsValid(2)) id = args.GetInt(2);
	wx_ActivateEvent *pEntity = new wx_ActivateEvent(eventType, active, id);
	Object_wx_ActivateEvent *pObj = Object_wx_ActivateEvent::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ActivateEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_ActivateEvent, GetActive)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ActivateEvent, GetActive)
{
	Object_wx_ActivateEvent *pThis = Object_wx_ActivateEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->GetActive();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxActivateEvent
//----------------------------------------------------------------------------
Object_wx_ActivateEvent::~Object_wx_ActivateEvent()
{
}

Object *Object_wx_ActivateEvent::Clone() const
{
	return NULL;
}

String Object_wx_ActivateEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ActivateEvent:");
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
// Class implementation for wxActivateEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActivateEvent)
{
	Gura_AssignFunction(ActivateEvent);
	Gura_AssignMethod(wx_ActivateEvent, GetActive);
}

Gura_ImplementDescendantCreator(wx_ActivateEvent)
{
	return new Object_wx_ActivateEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
