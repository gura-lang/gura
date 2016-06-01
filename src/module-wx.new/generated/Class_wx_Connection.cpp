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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Connection, wxConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Connection, wxConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, wxConnection_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, wxConnection_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->wxConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Advise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Advise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Advise_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Advise_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Advise_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Advise_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Advise_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Advise_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Advise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Disconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Connection, Disconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Disconnect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Execute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Execute)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Execute_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Execute_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Execute_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Execute_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Execute_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Execute_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->Execute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, OnAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, OnAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->OnAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, OnDisconnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Connection, OnDisconnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnDisconnect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, OnExec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, OnExec)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->OnExec();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, OnPoke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, OnPoke)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int data = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int format = arg.GetNumber(4)
	//pThis->GetEntity()->OnPoke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, OnRequest)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, OnRequest)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->OnRequest();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, OnStartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, OnStartAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStartAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, OnStopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, OnStopAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//int item = arg.GetNumber(1)
	//pThis->GetEntity()->OnStopAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Poke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Poke)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int format = arg.GetNumber(3)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Poke_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Poke_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Poke_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Poke_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Poke_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Poke_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->Poke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, Request)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, Request)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//int format = arg.GetNumber(2)
	//pThis->GetEntity()->Request();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, StartAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, StartAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->StartAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, StopAdvise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, StopAdvise)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int item = arg.GetNumber(0)
	//pThis->GetEntity()->StopAdvise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, IsTextFormat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, IsTextFormat)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->IsTextFormat();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Connection, GetTextFromData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Connection, GetTextFromData)
{
	Signal &sig = env.GetSignal();
	Object_wx_Connection *pThis = Object_wx_Connection::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_Connection, wxConnection);
	Gura_AssignMethod(wx_Connection, wxConnection_1);
	Gura_AssignMethod(wx_Connection, Advise);
	Gura_AssignMethod(wx_Connection, Advise_1);
	Gura_AssignMethod(wx_Connection, Advise_2);
	Gura_AssignMethod(wx_Connection, Advise_3);
	Gura_AssignMethod(wx_Connection, Disconnect);
	Gura_AssignMethod(wx_Connection, Execute);
	Gura_AssignMethod(wx_Connection, Execute_1);
	Gura_AssignMethod(wx_Connection, Execute_2);
	Gura_AssignMethod(wx_Connection, Execute_3);
	Gura_AssignMethod(wx_Connection, OnAdvise);
	Gura_AssignMethod(wx_Connection, OnDisconnect);
	Gura_AssignMethod(wx_Connection, OnExec);
	Gura_AssignMethod(wx_Connection, OnPoke);
	Gura_AssignMethod(wx_Connection, OnRequest);
	Gura_AssignMethod(wx_Connection, OnStartAdvise);
	Gura_AssignMethod(wx_Connection, OnStopAdvise);
	Gura_AssignMethod(wx_Connection, Poke);
	Gura_AssignMethod(wx_Connection, Poke_1);
	Gura_AssignMethod(wx_Connection, Poke_2);
	Gura_AssignMethod(wx_Connection, Poke_3);
	Gura_AssignMethod(wx_Connection, Request);
	Gura_AssignMethod(wx_Connection, StartAdvise);
	Gura_AssignMethod(wx_Connection, StopAdvise);
	Gura_AssignMethod(wx_Connection, IsTextFormat);
	Gura_AssignMethod(wx_Connection, GetTextFromData);
}

Gura_ImplementDescendantCreator(wx_Connection)
{
	return new Object_wx_Connection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
