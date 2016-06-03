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
Gura_DeclareMethodAlias(wx_SocketClient, __wxSocketClient, "wxSocketClient")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, __wxSocketClient)
{
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->wxSocketClient();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SocketClient, __Connect, "Connect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, __Connect)
{
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//int wait = arg.GetNumber(1)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SocketClient, __Connect_1, "Connect_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "local", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, __Connect_1)
{
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//int local = arg.GetNumber(1)
	//int wait = arg.GetNumber(2)
	//pThis->GetEntity()->Connect();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SocketClient, __WaitOnConnect, "WaitOnConnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, __WaitOnConnect)
{
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
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
	Gura_AssignMethod(wx_SocketClient, __wxSocketClient);
	Gura_AssignMethod(wx_SocketClient, __Connect);
	Gura_AssignMethod(wx_SocketClient, __Connect_1);
	Gura_AssignMethod(wx_SocketClient, __WaitOnConnect);
}

Gura_ImplementDescendantCreator(wx_SocketClient)
{
	return new Object_wx_SocketClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
