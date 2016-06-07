//----------------------------------------------------------------------------
// wxSocketServer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketServer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSocketServer
//----------------------------------------------------------------------------
Object_wx_SocketServer::~Object_wx_SocketServer()
{
}

Object *Object_wx_SocketServer::Clone() const
{
	return nullptr;
}

String Object_wx_SocketServer::ToString(bool exprFlag)
{
	String rtn("<wx.SocketServer:");
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
Gura_DeclareFunctionAlias(__SocketServer, "SocketServer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SocketServer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SocketServer)
{
	//const wxSockAddress& address = arg.GetNumber(0)
	//wxSocketFlags flags = arg.GetNumber(1)
	//wxSocketServer(address, flags);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SocketServer, __Accept, "Accept")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketServer, __Accept)
{
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool wait = arg.GetNumber(0)
	//wxSocketBase* _rtn = pThis->GetEntity()->Accept(wait);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SocketServer, __AcceptWith, "AcceptWith")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "socket", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketServer, __AcceptWith)
{
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSocketBase& socket = arg.GetNumber(0)
	//bool wait = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->AcceptWith(socket, wait);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SocketServer, __WaitForAccept, "WaitForAccept")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "millisecond", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketServer, __WaitForAccept)
{
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long seconds = arg.GetNumber(0)
	//long millisecond = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->WaitForAccept(seconds, millisecond);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketServer)
{
	// Constructor assignment
	Gura_AssignFunction(__SocketServer);
	// Method assignment
	Gura_AssignMethod(wx_SocketServer, __Accept);
	Gura_AssignMethod(wx_SocketServer, __AcceptWith);
	Gura_AssignMethod(wx_SocketServer, __WaitForAccept);
}

Gura_ImplementDescendantCreator(wx_SocketServer)
{
	return new Object_wx_SocketServer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
