//----------------------------------------------------------------------------
// wxCloseEvent
// extracted from closeevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_CloseEvent: public wxCloseEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_CloseEvent *_pObj;
public:
	inline wx_CloseEvent(WXTYPE commandEventType, int id) : wxCloseEvent(commandEventType, id), _pObj(nullptr) {}
	~wx_CloseEvent();
	inline void AssocWithGura(Object_wx_CloseEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_CloseEvent::~wx_CloseEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_CloseEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCloseEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(CloseEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_CloseEvent));
	DeclareArg(env, "commandEventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(CloseEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	WXTYPE commandEventType = 0;
	if (args.IsValid(0)) commandEventType = static_cast<WXTYPE>(args.GetInt(0));
	int id = 0;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_CloseEvent *pEntity = new wx_CloseEvent(commandEventType, id);
	Object_wx_CloseEvent *pObj = Object_wx_CloseEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_CloseEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_CloseEvent, CanVeto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CloseEvent, CanVeto)
{
	Signal &sig = env.GetSignal();
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->CanVeto();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_CloseEvent, GetLoggingOff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CloseEvent, GetLoggingOff)
{
	Signal &sig = env.GetSignal();
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->GetLoggingOff();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_CloseEvent, SetCanVeto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "canVeto", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_CloseEvent, SetCanVeto)
{
	Signal &sig = env.GetSignal();
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool canVeto = args.GetBoolean(0);
	pThis->GetEntity()->SetCanVeto(canVeto);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CloseEvent, SetForce)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "force", VTYPE_boolean, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_CloseEvent, SetForce)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool force = args.GetBoolean(0);
	pThis->GetEntity()->SetForce(force);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CloseEvent, SetLoggingOff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "loggingOff", VTYPE_boolean, OCCUR_Once);
}

Gura_ImplementMethod(wx_CloseEvent, SetLoggingOff)
{
	Signal &sig = env.GetSignal();
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool loggingOff = args.GetBoolean(0);
	pThis->GetEntity()->SetLoggingOff(loggingOff);
	return Value::Nil;
}

Gura_DeclareMethod(wx_CloseEvent, Veto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "veto", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_CloseEvent, Veto)
{
	Signal &sig = env.GetSignal();
	Object_wx_CloseEvent *pThis = Object_wx_CloseEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool veto = true;
	if (args.IsValid(0)) veto = args.GetBoolean(0);
	pThis->GetEntity()->Veto(veto);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxCloseEvent
//----------------------------------------------------------------------------
Object_wx_CloseEvent::~Object_wx_CloseEvent()
{
}

Object *Object_wx_CloseEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CloseEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CloseEvent:");
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
// Class implementation for wxCloseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CloseEvent)
{
	Gura_AssignFunction(CloseEvent);
	Gura_AssignMethod(wx_CloseEvent, CanVeto);
	Gura_AssignMethod(wx_CloseEvent, GetLoggingOff);
	Gura_AssignMethod(wx_CloseEvent, SetCanVeto);
	Gura_AssignMethod(wx_CloseEvent, SetForce);
	Gura_AssignMethod(wx_CloseEvent, SetLoggingOff);
	Gura_AssignMethod(wx_CloseEvent, Veto);
}

Gura_ImplementDescendantCreator(wx_CloseEvent)
{
	return new Object_wx_CloseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
