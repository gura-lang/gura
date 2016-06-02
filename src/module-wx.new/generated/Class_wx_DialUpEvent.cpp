//----------------------------------------------------------------------------
// wxDialUpEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDialUpEvent
//----------------------------------------------------------------------------

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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_DialUpEvent, wxDialUpEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "isConnected", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "isOwnEvent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DialUpEvent, wxDialUpEvent)
{
	Object_wx_DialUpEvent *pThis = Object_wx_DialUpEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int isConnected = arg.GetNumber(0)
	//int isOwnEvent = arg.GetNumber(1)
	//pThis->GetEntity()->wxDialUpEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpEvent, IsConnectedEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpEvent, IsConnectedEvent)
{
	Object_wx_DialUpEvent *pThis = Object_wx_DialUpEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsConnectedEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DialUpEvent, IsOwnEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DialUpEvent, IsOwnEvent)
{
	Object_wx_DialUpEvent *pThis = Object_wx_DialUpEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOwnEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDialUpEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialUpEvent)
{
	Gura_AssignMethod(wx_DialUpEvent, wxDialUpEvent);
	Gura_AssignMethod(wx_DialUpEvent, IsConnectedEvent);
	Gura_AssignMethod(wx_DialUpEvent, IsOwnEvent);
}

Gura_ImplementDescendantCreator(wx_DialUpEvent)
{
	return new Object_wx_DialUpEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
