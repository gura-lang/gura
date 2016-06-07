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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__NotifyEvent, "NotifyEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_NotifyEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__NotifyEvent)
{
	//wxEventType eventType = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxNotifyEvent(eventType, id);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_NotifyEvent, __Allow, "Allow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NotifyEvent, __Allow)
{
	Object_wx_NotifyEvent *pThis = Object_wx_NotifyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Allow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NotifyEvent, __IsAllowed, "IsAllowed")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_NotifyEvent, __IsAllowed)
{
	Object_wx_NotifyEvent *pThis = Object_wx_NotifyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsAllowed();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_NotifyEvent, __Veto, "Veto")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_NotifyEvent, __Veto)
{
	Object_wx_NotifyEvent *pThis = Object_wx_NotifyEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Veto();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNotifyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NotifyEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__NotifyEvent);
	// Method assignment
	Gura_AssignMethod(wx_NotifyEvent, __Allow);
	Gura_AssignMethod(wx_NotifyEvent, __IsAllowed);
	Gura_AssignMethod(wx_NotifyEvent, __Veto);
}

Gura_ImplementDescendantCreator(wx_NotifyEvent)
{
	return new Object_wx_NotifyEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
