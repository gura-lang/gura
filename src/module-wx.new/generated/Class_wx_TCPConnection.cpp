//----------------------------------------------------------------------------
// wxTCPConnection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTCPConnection
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTCPConnection
//----------------------------------------------------------------------------
Object_wx_TCPConnection::~Object_wx_TCPConnection()
{
}

Object *Object_wx_TCPConnection::Clone() const
{
	return nullptr;
}

String Object_wx_TCPConnection::ToString(bool exprFlag)
{
	String rtn("<wx.TCPConnection:");
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
Gura_DeclareMethod(wx_TCPConnection, wxTCPConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TCPConnection, wxTCPConnection)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTCPConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, wxTCPConnection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, wxTCPConnection_1)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->wxTCPConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Advise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Advise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Advise_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Advise_1)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Advise_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Advise_2)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Advise_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Advise_3)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Disconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TCPConnection, Disconnect)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Execute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Execute)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Execute_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Execute_1)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Execute_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Execute_2)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Execute_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Execute_3)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, OnAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->OnAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnDisconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TCPConnection, OnDisconnect)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnDisconnect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnExecute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, OnExecute)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->OnExecute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnPoke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, OnPoke)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->OnPoke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnRequest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, OnRequest)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->OnRequest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnStartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, OnStartAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStartAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, OnStopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, OnStopAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStopAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Poke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Poke)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Poke_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Poke_1)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Poke_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Poke_2)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Poke_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Poke_3)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, Request)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, Request)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Request();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, StartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, StartAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->StartAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPConnection, StopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, StopAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->StopAdvise();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTCPConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPConnection)
{
	Gura_AssignMethod(wx_TCPConnection, wxTCPConnection);
	Gura_AssignMethod(wx_TCPConnection, wxTCPConnection_1);
	Gura_AssignMethod(wx_TCPConnection, Advise);
	Gura_AssignMethod(wx_TCPConnection, Advise_1);
	Gura_AssignMethod(wx_TCPConnection, Advise_2);
	Gura_AssignMethod(wx_TCPConnection, Advise_3);
	Gura_AssignMethod(wx_TCPConnection, Disconnect);
	Gura_AssignMethod(wx_TCPConnection, Execute);
	Gura_AssignMethod(wx_TCPConnection, Execute_1);
	Gura_AssignMethod(wx_TCPConnection, Execute_2);
	Gura_AssignMethod(wx_TCPConnection, Execute_3);
	Gura_AssignMethod(wx_TCPConnection, OnAdvise);
	Gura_AssignMethod(wx_TCPConnection, OnDisconnect);
	Gura_AssignMethod(wx_TCPConnection, OnExecute);
	Gura_AssignMethod(wx_TCPConnection, OnPoke);
	Gura_AssignMethod(wx_TCPConnection, OnRequest);
	Gura_AssignMethod(wx_TCPConnection, OnStartAdvise);
	Gura_AssignMethod(wx_TCPConnection, OnStopAdvise);
	Gura_AssignMethod(wx_TCPConnection, Poke);
	Gura_AssignMethod(wx_TCPConnection, Poke_1);
	Gura_AssignMethod(wx_TCPConnection, Poke_2);
	Gura_AssignMethod(wx_TCPConnection, Poke_3);
	Gura_AssignMethod(wx_TCPConnection, Request);
	Gura_AssignMethod(wx_TCPConnection, StartAdvise);
	Gura_AssignMethod(wx_TCPConnection, StopAdvise);
}

Gura_ImplementDescendantCreator(wx_TCPConnection)
{
	return new Object_wx_TCPConnection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
