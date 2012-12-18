//----------------------------------------------------------------------------
// wxDialUpEvent
// extracted from dialevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DialUpEvent: public wxDialUpEvent, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DialUpEvent *_pObj;
public:
	inline wx_DialUpEvent(bool isConnected, bool isOwnEvent) : wxDialUpEvent(isConnected, isOwnEvent), _sig(NULL), _pObj(NULL) {}
	~wx_DialUpEvent();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DialUpEvent *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DialUpEvent::~wx_DialUpEvent()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DialUpEvent::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDialUpEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(DialUpEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DialUpEvent));
	DeclareArg(env, "isConnected", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "isOwnEvent", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DialUpEvent)
{
	bool isConnected = args.GetBoolean(0);
	bool isOwnEvent = args.GetBoolean(1);
	wx_DialUpEvent *pEntity = new wx_DialUpEvent(isConnected, isOwnEvent);
	Object_wx_DialUpEvent *pObj = Object_wx_DialUpEvent::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DialUpEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_DialUpEvent, IsConnectedEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpEvent, IsConnectedEvent)
{
	Object_wx_DialUpEvent *pSelf = Object_wx_DialUpEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsConnectedEvent();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpEvent, IsOwnEvent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpEvent, IsOwnEvent)
{
	Object_wx_DialUpEvent *pSelf = Object_wx_DialUpEvent::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOwnEvent();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDialUpEvent
//----------------------------------------------------------------------------
Object_wx_DialUpEvent::~Object_wx_DialUpEvent()
{
}

Object *Object_wx_DialUpEvent::Clone() const
{
	return NULL;
}

String Object_wx_DialUpEvent::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DialUpEvent:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DialUpEvent::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(DialUpEvent);
}

//----------------------------------------------------------------------------
// Class implementation for wxDialUpEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialUpEvent)
{
	Gura_AssignMethod(wx_DialUpEvent, IsConnectedEvent);
	Gura_AssignMethod(wx_DialUpEvent, IsOwnEvent);
}

Gura_ImplementDescendantCreator(wx_DialUpEvent)
{
	return new Object_wx_DialUpEvent((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
