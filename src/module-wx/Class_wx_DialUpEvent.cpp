//----------------------------------------------------------------------------
// wxDialUpEvent
// extracted from dialevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DialUpEvent: public wxDialUpEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DialUpEvent *_pObj;
public:
	inline wx_DialUpEvent(bool isConnected, bool isOwnEvent) : wxDialUpEvent(isConnected, isOwnEvent), _pObj(nullptr) {}
	~wx_DialUpEvent();
	inline void AssocWithGura(Object_wx_DialUpEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DialUpEvent::~wx_DialUpEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DialUpEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDialUpEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(DialUpEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DialUpEvent));
	DeclareArg(env, "isConnected", VTYPE_boolean, OCCUR_Once);
	DeclareArg(env, "isOwnEvent", VTYPE_boolean, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DialUpEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Null;
	bool isConnected = args.GetBoolean(0);
	bool isOwnEvent = args.GetBoolean(1);
	wx_DialUpEvent *pEntity = new wx_DialUpEvent(isConnected, isOwnEvent);
	Object_wx_DialUpEvent *pObj = Object_wx_DialUpEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DialUpEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_DialUpEvent, IsConnectedEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpEvent, IsConnectedEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpEvent *pThis = Object_wx_DialUpEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsConnectedEvent();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_DialUpEvent, IsOwnEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DialUpEvent, IsOwnEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_DialUpEvent *pThis = Object_wx_DialUpEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOwnEvent();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDialUpEvent
//----------------------------------------------------------------------------
Object_wx_DialUpEvent::~Object_wx_DialUpEvent()
{
}

Object *Object_wx_DialUpEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DialUpEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DialUpEvent:");
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
// Class implementation for wxDialUpEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialUpEvent)
{
	Gura_AssignFunction(DialUpEvent);
	Gura_AssignMethod(wx_DialUpEvent, IsConnectedEvent);
	Gura_AssignMethod(wx_DialUpEvent, IsOwnEvent);
}

Gura_ImplementDescendantCreator(wx_DialUpEvent)
{
	return new Object_wx_DialUpEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
