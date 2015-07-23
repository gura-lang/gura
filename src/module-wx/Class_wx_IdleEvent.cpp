//----------------------------------------------------------------------------
// wxIdleEvent
// extracted from idleevt.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_IdleEvent: public wxIdleEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_IdleEvent *_pObj;
public:
	inline wx_IdleEvent() : wxIdleEvent(), _pObj(nullptr) {}
	~wx_IdleEvent();
	inline void AssocWithGura(Object_wx_IdleEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_IdleEvent::~wx_IdleEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_IdleEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxIdleEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(IdleEventEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_IdleEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(IdleEventEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_IdleEvent *pEntity = new wx_IdleEvent();
	Object_wx_IdleEvent *pObj = Object_wx_IdleEvent::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_IdleEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

#if 0
Gura_DeclareClassMethod(wx_IdleEvent, CanSend)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "window", VTYPE_wx_Window, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_IdleEvent, CanSend)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxWindow *window = Object_wx_Window::GetObject(args, 0)->GetEntity();
	bool rtn = wxIdleEvent::CanSend(window);
	return ReturnValue(env, args, Value(rtn));
}
#endif

Gura_DeclareClassMethod(wx_IdleEvent, GetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_IdleEvent, GetMode)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxIdleMode rtn = wxIdleEvent::GetMode();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_IdleEvent, RequestMore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "needMore", VTYPE_boolean, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IdleEvent, RequestMore)
{
	Object_wx_IdleEvent *pThis = Object_wx_IdleEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool needMore = true;
	if (args.IsValid(0)) needMore = args.GetBoolean(0);
	pThis->GetEntity()->RequestMore(needMore);
	return Value::Null;
}

Gura_DeclareMethod(wx_IdleEvent, MoreRequested)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_IdleEvent, MoreRequested)
{
	Object_wx_IdleEvent *pThis = Object_wx_IdleEvent::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->MoreRequested();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethodAlias(wx_IdleEvent, SetMode_, "SetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementClassMethod(wx_IdleEvent, SetMode_)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxIdleMode mode = static_cast<wxIdleMode>(args.GetInt(0));
	wxIdleEvent::SetMode(mode);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxIdleEvent
//----------------------------------------------------------------------------
Object_wx_IdleEvent::~Object_wx_IdleEvent()
{
}

Object *Object_wx_IdleEvent::Clone() const
{
	return nullptr;
}

String Object_wx_IdleEvent::ToString(bool exprFlag)
{
	String rtn("<wx.IdleEvent:");
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
// Class implementation for wxIdleEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IdleEvent)
{
	Gura_AssignFunction(IdleEventEmpty);
	//Gura_AssignMethod(wx_IdleEvent, CanSend);
	Gura_AssignMethod(wx_IdleEvent, GetMode);
	Gura_AssignMethod(wx_IdleEvent, RequestMore);
	Gura_AssignMethod(wx_IdleEvent, MoreRequested);
	Gura_AssignMethod(wx_IdleEvent, SetMode_);
}

Gura_ImplementDescendantCreator(wx_IdleEvent)
{
	return new Object_wx_IdleEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
