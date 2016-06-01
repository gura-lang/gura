//----------------------------------------------------------------------------
// wxNotifyEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNotifyEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNotifyEvent
//----------------------------------------------------------------------------
Object_wx_NotifyEvent::~Object_wx_NotifyEvent()
{
}

Object *Object_wx_NotifyEvent::Clone() const
{
	return nullptr;
}

String Object_wx_NotifyEvent::ToString(bool exprFlag)
{
	String rtn("<wx.NotifyEvent:");
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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_NotifyEvent, wxNotifyEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_NotifyEvent, wxNotifyEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_NotifyEvent *pThis = Object_wx_NotifyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxNotifyEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NotifyEvent, Allow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NotifyEvent, Allow)
{
	Signal &sig = env.GetSignal();
	Object_wx_NotifyEvent *pThis = Object_wx_NotifyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Allow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NotifyEvent, IsAllowed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NotifyEvent, IsAllowed)
{
	Signal &sig = env.GetSignal();
	Object_wx_NotifyEvent *pThis = Object_wx_NotifyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsAllowed();
	return Value::Nil;
}

Gura_DeclareMethod(wx_NotifyEvent, Veto)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NotifyEvent, Veto)
{
	Signal &sig = env.GetSignal();
	Object_wx_NotifyEvent *pThis = Object_wx_NotifyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Veto();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNotifyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NotifyEvent)
{
	Gura_AssignMethod(wx_NotifyEvent, wxNotifyEvent);
	Gura_AssignMethod(wx_NotifyEvent, Allow);
	Gura_AssignMethod(wx_NotifyEvent, IsAllowed);
	Gura_AssignMethod(wx_NotifyEvent, Veto);
}

Gura_ImplementDescendantCreator(wx_NotifyEvent)
{
	return new Object_wx_NotifyEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
