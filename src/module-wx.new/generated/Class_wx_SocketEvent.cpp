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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SocketEvent, "SocketEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SocketEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SocketEvent)
{
	//int id = arg.GetNumber(0)
	//wxSocketEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SocketEvent, __GetClientData, "GetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketEvent, __GetClientData)
{
	Object_wx_SocketEvent *pThis = Object_wx_SocketEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SocketEvent, __GetSocket, "GetSocket")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketEvent, __GetSocket)
{
	Object_wx_SocketEvent *pThis = Object_wx_SocketEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSocket();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SocketEvent, __GetSocketEvent, "GetSocketEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketEvent, __GetSocketEvent)
{
	Object_wx_SocketEvent *pThis = Object_wx_SocketEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSocketEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__SocketEvent);
	// Method assignment
	Gura_AssignMethod(wx_SocketEvent, __GetClientData);
	Gura_AssignMethod(wx_SocketEvent, __GetSocket);
	Gura_AssignMethod(wx_SocketEvent, __GetSocketEvent);
}

Gura_ImplementDescendantCreator(wx_SocketEvent)
{
	return new Object_wx_SocketEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
