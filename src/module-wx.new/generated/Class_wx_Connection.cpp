//----------------------------------------------------------------------------
// wxConnection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxConnection
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxConnection
//----------------------------------------------------------------------------
Object_wx_Connection::~Object_wx_Connection()
{
}

Object *Object_wx_Connection::Clone() const
{
	return nullptr;
}

String Object_wx_Connection::ToString(bool exprFlag)
{
	String rtn("<wx.Connection:");
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
Gura_DeclareFunctionAlias(__Connection, "Connection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Connection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Connection)
{
	//wxConnection();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Connection_1, "Connection_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Connection));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Connection_1)
{
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//wxConnection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Connection, __Advise, "Advise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Advise)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Advise_1, "Advise_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Advise_1)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Advise_2, "Advise_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Advise_2)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Advise_3, "Advise_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Advise_3)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Disconnect, "Disconnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Connection, __Disconnect)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Execute, "Execute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Execute)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Execute_1, "Execute_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Execute_1)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Execute_2, "Execute_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Execute_2)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Execute_3, "Execute_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Execute_3)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __OnAdvise, "OnAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __OnAdvise)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->OnAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __OnDisconnect, "OnDisconnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Connection, __OnDisconnect)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnDisconnect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __OnExec, "OnExec")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __OnExec)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->OnExec();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __OnPoke, "OnPoke")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __OnPoke)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->OnPoke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __OnRequest, "OnRequest")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __OnRequest)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->OnRequest();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __OnStartAdvise, "OnStartAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __OnStartAdvise)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStartAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __OnStopAdvise, "OnStopAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __OnStopAdvise)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStopAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Poke, "Poke")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Poke)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Poke_1, "Poke_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Poke_1)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Poke_2, "Poke_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Poke_2)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Poke_3, "Poke_3")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Poke_3)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __Request, "Request")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __Request)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Request();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __StartAdvise, "StartAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __StartAdvise)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->StartAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __StopAdvise, "StopAdvise")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __StopAdvise)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->StopAdvise();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __IsTextFormat, "IsTextFormat")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __IsTextFormat)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->IsTextFormat();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Connection, __GetTextFromData, "GetTextFromData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, __GetTextFromData)
{
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->GetTextFromData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Connection)
{
	// Constructor assignment
	Gura_AssignFunction(__Connection);
	Gura_AssignFunction(__Connection_1);
	// Method assignment
	Gura_AssignMethod(wx_Connection, __Advise);
	Gura_AssignMethod(wx_Connection, __Advise_1);
	Gura_AssignMethod(wx_Connection, __Advise_2);
	Gura_AssignMethod(wx_Connection, __Advise_3);
	Gura_AssignMethod(wx_Connection, __Disconnect);
	Gura_AssignMethod(wx_Connection, __Execute);
	Gura_AssignMethod(wx_Connection, __Execute_1);
	Gura_AssignMethod(wx_Connection, __Execute_2);
	Gura_AssignMethod(wx_Connection, __Execute_3);
	Gura_AssignMethod(wx_Connection, __OnAdvise);
	Gura_AssignMethod(wx_Connection, __OnDisconnect);
	Gura_AssignMethod(wx_Connection, __OnExec);
	Gura_AssignMethod(wx_Connection, __OnPoke);
	Gura_AssignMethod(wx_Connection, __OnRequest);
	Gura_AssignMethod(wx_Connection, __OnStartAdvise);
	Gura_AssignMethod(wx_Connection, __OnStopAdvise);
	Gura_AssignMethod(wx_Connection, __Poke);
	Gura_AssignMethod(wx_Connection, __Poke_1);
	Gura_AssignMethod(wx_Connection, __Poke_2);
	Gura_AssignMethod(wx_Connection, __Poke_3);
	Gura_AssignMethod(wx_Connection, __Request);
	Gura_AssignMethod(wx_Connection, __StartAdvise);
	Gura_AssignMethod(wx_Connection, __StopAdvise);
	Gura_AssignMethod(wx_Connection, __IsTextFormat);
	Gura_AssignMethod(wx_Connection, __GetTextFromData);
}

Gura_ImplementDescendantCreator(wx_Connection)
{
	return new Object_wx_Connection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
