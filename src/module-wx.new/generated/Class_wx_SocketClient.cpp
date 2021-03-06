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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SocketClient, "SocketClient")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SocketClient));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SocketClient)
{
	//wxSocketFlags flags = arg.GetNumber(0)
	//wxSocketClient(flags);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SocketClient, __Connect, "Connect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, __Connect)
{
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSockAddress& address = arg.GetNumber(0)
	//bool wait = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->Connect(address, wait);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SocketClient, __Connect_1, "Connect_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "local", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, __Connect_1)
{
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSockAddress& address = arg.GetNumber(0)
	//const wxSockAddress& local = arg.GetNumber(1)
	//bool wait = arg.GetNumber(2)
	//bool _rtn = pThis->GetEntity()->Connect(address, local, wait);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SocketClient, __WaitOnConnect, "WaitOnConnect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketClient, __WaitOnConnect)
{
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long seconds = arg.GetNumber(0)
	//long milliseconds = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->WaitOnConnect(seconds, milliseconds);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketClient)
{
	// Constructor assignment
	Gura_AssignFunction(__SocketClient);
	// Method assignment
	Gura_AssignMethod(wx_SocketClient, __Connect);
	Gura_AssignMethod(wx_SocketClient, __Connect_1);
	Gura_AssignMethod(wx_SocketClient, __WaitOnConnect);
}

Gura_ImplementDescendantCreator(wx_SocketClient)
{
	return new Object_wx_SocketClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
