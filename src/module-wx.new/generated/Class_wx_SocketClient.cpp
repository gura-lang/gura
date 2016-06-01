//----------------------------------------------------------------------------
// wxSocketClient
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketClient
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSocketClient
//----------------------------------------------------------------------------
Object_wx_SocketClient::~Object_wx_SocketClient()
{
}

Object *Object_wx_SocketClient::Clone() const
{
	return nullptr;
}

String Object_wx_SocketClient::ToString(bool exprFlag)
{
	String rtn("<wx.SocketClient:");
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
Gura_DeclareMethod(wx_SocketClient, wxSocketClient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, wxSocketClient)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->wxSocketClient();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketClient, ~wxSocketClient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketClient, ~wxSocketClient)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxSocketClient();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketClient, Connect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, Connect)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//int wait = arg.GetNumber(1)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketClient, Connect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "local", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, Connect_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//int local = arg.GetNumber(1)
	//int wait = arg.GetNumber(2)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketClient, WaitOnConnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, WaitOnConnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int seconds = arg.GetNumber(0)
	//int milliseconds = arg.GetNumber(1)
	//pThis->GetEntity()->WaitOnConnect();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketClient)
{
	Gura_AssignMethod(wx_SocketClient, wxSocketClient);
	Gura_AssignMethod(wx_SocketClient, ~wxSocketClient);
	Gura_AssignMethod(wx_SocketClient, Connect);
	Gura_AssignMethod(wx_SocketClient, Connect_1);
	Gura_AssignMethod(wx_SocketClient, WaitOnConnect);
}

Gura_ImplementDescendantCreator(wx_SocketClient)
{
	return new Object_wx_SocketClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
