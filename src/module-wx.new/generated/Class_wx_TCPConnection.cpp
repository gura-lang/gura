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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TCPConnection, "TCPConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TCPConnection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TCPConnection)
{
	//wxTCPConnection();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TCPConnection_1, "TCPConnection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TCPConnection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TCPConnection_1)
{
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//wxTCPConnection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TCPConnection, __Advise, "Advise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Advise)
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

Gura_DeclareMethodAlias(wx_TCPConnection, __Advise_1, "Advise_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Advise_1)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Advise_2, "Advise_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Advise_2)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Advise_3, "Advise_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Advise_3)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Disconnect, "Disconnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TCPConnection, __Disconnect)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Execute, "Execute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Execute)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Execute_1, "Execute_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Execute_1)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Execute_2, "Execute_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Execute_2)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Execute_3, "Execute_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Execute_3)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __OnAdvise, "OnAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnAdvise)
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

Gura_DeclareMethodAlias(wx_TCPConnection, __OnDisconnect, "OnDisconnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TCPConnection, __OnDisconnect)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnDisconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __OnExecute, "OnExecute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnExecute)
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

Gura_DeclareMethodAlias(wx_TCPConnection, __OnPoke, "OnPoke")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnPoke)
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

Gura_DeclareMethodAlias(wx_TCPConnection, __OnRequest, "OnRequest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnRequest)
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

Gura_DeclareMethodAlias(wx_TCPConnection, __OnStartAdvise, "OnStartAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnStartAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStartAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __OnStopAdvise, "OnStopAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __OnStopAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStopAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Poke, "Poke")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Poke)
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

Gura_DeclareMethodAlias(wx_TCPConnection, __Poke_1, "Poke_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Poke_1)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Poke_2, "Poke_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Poke_2)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Poke_3, "Poke_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Poke_3)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __Request, "Request")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __Request)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Request();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __StartAdvise, "StartAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __StartAdvise)
{
	Object_wx_TCPConnection *pThis = Object_wx_TCPConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->StartAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPConnection, __StopAdvise, "StopAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPConnection, __StopAdvise)
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
	// Constructor assignment
	Gura_AssignFunction(__TCPConnection);
	Gura_AssignFunction(__TCPConnection_1);
	// Method assignment
	Gura_AssignMethod(wx_TCPConnection, __Advise);
	Gura_AssignMethod(wx_TCPConnection, __Advise_1);
	Gura_AssignMethod(wx_TCPConnection, __Advise_2);
	Gura_AssignMethod(wx_TCPConnection, __Advise_3);
	Gura_AssignMethod(wx_TCPConnection, __Disconnect);
	Gura_AssignMethod(wx_TCPConnection, __Execute);
	Gura_AssignMethod(wx_TCPConnection, __Execute_1);
	Gura_AssignMethod(wx_TCPConnection, __Execute_2);
	Gura_AssignMethod(wx_TCPConnection, __Execute_3);
	Gura_AssignMethod(wx_TCPConnection, __OnAdvise);
	Gura_AssignMethod(wx_TCPConnection, __OnDisconnect);
	Gura_AssignMethod(wx_TCPConnection, __OnExecute);
	Gura_AssignMethod(wx_TCPConnection, __OnPoke);
	Gura_AssignMethod(wx_TCPConnection, __OnRequest);
	Gura_AssignMethod(wx_TCPConnection, __OnStartAdvise);
	Gura_AssignMethod(wx_TCPConnection, __OnStopAdvise);
	Gura_AssignMethod(wx_TCPConnection, __Poke);
	Gura_AssignMethod(wx_TCPConnection, __Poke_1);
	Gura_AssignMethod(wx_TCPConnection, __Poke_2);
	Gura_AssignMethod(wx_TCPConnection, __Poke_3);
	Gura_AssignMethod(wx_TCPConnection, __Request);
	Gura_AssignMethod(wx_TCPConnection, __StartAdvise);
	Gura_AssignMethod(wx_TCPConnection, __StopAdvise);
}

Gura_ImplementDescendantCreator(wx_TCPConnection)
{
	return new Object_wx_TCPConnection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
