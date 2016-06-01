//----------------------------------------------------------------------------
// wxSocketEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSocketEvent
//----------------------------------------------------------------------------
Object_wx_SocketEvent::~Object_wx_SocketEvent()
{
}

Object *Object_wx_SocketEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SocketEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SocketEvent:");
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
Gura_DeclareMethod(wx_SocketEvent, wxSocketEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketEvent, wxSocketEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketEvent *pThis = Object_wx_SocketEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->wxSocketEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketEvent, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketEvent, GetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketEvent *pThis = Object_wx_SocketEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketEvent, GetSocket)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketEvent, GetSocket)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketEvent *pThis = Object_wx_SocketEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSocket();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketEvent, GetSocketEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketEvent, GetSocketEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketEvent *pThis = Object_wx_SocketEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSocketEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketEvent)
{
	Gura_AssignMethod(wx_SocketEvent, wxSocketEvent);
	Gura_AssignMethod(wx_SocketEvent, GetClientData);
	Gura_AssignMethod(wx_SocketEvent, GetSocket);
	Gura_AssignMethod(wx_SocketEvent, GetSocketEvent);
}

Gura_ImplementDescendantCreator(wx_SocketEvent)
{
	return new Object_wx_SocketEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
