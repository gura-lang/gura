//----------------------------------------------------------------------------
// wxDDEConnection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEConnection
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDDEConnection
//----------------------------------------------------------------------------
Object_wx_DDEConnection::~Object_wx_DDEConnection()
{
}

Object *Object_wx_DDEConnection::Clone() const
{
	return nullptr;
}

String Object_wx_DDEConnection::ToString(bool exprFlag)
{
	String rtn("<wx.DDEConnection:");
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
Gura_DeclareMethod(wx_DDEConnection, wxDDEConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DDEConnection, wxDDEConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDDEConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, wxDDEConnection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, wxDDEConnection_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->wxDDEConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Advise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Advise)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Advise_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Advise_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Advise_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Advise_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Advise_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Advise_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Disconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DDEConnection, Disconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Execute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Execute)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Execute_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Execute_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Execute_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Execute_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Execute_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Execute_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, OnAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->OnAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnDisconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DDEConnection, OnDisconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnDisconnect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnExecute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, OnExecute)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->OnExecute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnPoke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, OnPoke)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->OnPoke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnRequest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, OnRequest)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->OnRequest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnStartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, OnStartAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStartAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, OnStopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, OnStopAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStopAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Poke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Poke)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Poke_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Poke_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Poke_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Poke_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Poke_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Poke_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, Request)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, Request)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Request();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, StartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, StartAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->StartAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEConnection, StopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEConnection, StopAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEConnection *pThis = Object_wx_DDEConnection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->StopAdvise();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDDEConnection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEConnection)
{
	Gura_AssignMethod(wx_DDEConnection, wxDDEConnection);
	Gura_AssignMethod(wx_DDEConnection, wxDDEConnection_1);
	Gura_AssignMethod(wx_DDEConnection, Advise);
	Gura_AssignMethod(wx_DDEConnection, Advise_1);
	Gura_AssignMethod(wx_DDEConnection, Advise_2);
	Gura_AssignMethod(wx_DDEConnection, Advise_3);
	Gura_AssignMethod(wx_DDEConnection, Disconnect);
	Gura_AssignMethod(wx_DDEConnection, Execute);
	Gura_AssignMethod(wx_DDEConnection, Execute_1);
	Gura_AssignMethod(wx_DDEConnection, Execute_2);
	Gura_AssignMethod(wx_DDEConnection, Execute_3);
	Gura_AssignMethod(wx_DDEConnection, OnAdvise);
	Gura_AssignMethod(wx_DDEConnection, OnDisconnect);
	Gura_AssignMethod(wx_DDEConnection, OnExecute);
	Gura_AssignMethod(wx_DDEConnection, OnPoke);
	Gura_AssignMethod(wx_DDEConnection, OnRequest);
	Gura_AssignMethod(wx_DDEConnection, OnStartAdvise);
	Gura_AssignMethod(wx_DDEConnection, OnStopAdvise);
	Gura_AssignMethod(wx_DDEConnection, Poke);
	Gura_AssignMethod(wx_DDEConnection, Poke_1);
	Gura_AssignMethod(wx_DDEConnection, Poke_2);
	Gura_AssignMethod(wx_DDEConnection, Poke_3);
	Gura_AssignMethod(wx_DDEConnection, Request);
	Gura_AssignMethod(wx_DDEConnection, StartAdvise);
	Gura_AssignMethod(wx_DDEConnection, StopAdvise);
}

Gura_ImplementDescendantCreator(wx_DDEConnection)
{
	return new Object_wx_DDEConnection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
