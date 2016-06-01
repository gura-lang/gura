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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_SocketServer, wxSocketServer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "address", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketServer, wxSocketServer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int address = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->wxSocketServer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketServer, ~wxSocketServer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketServer, ~wxSocketServer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxSocketServer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketServer, Accept)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketServer, Accept)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int wait = arg.GetNumber(0)
	//pThis->GetEntity()->Accept();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketServer, AcceptWith)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "socket", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wait", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketServer, AcceptWith)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int socket = arg.GetNumber(0)
	//int wait = arg.GetNumber(1)
	//pThis->GetEntity()->AcceptWith();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketServer, WaitForAccept)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "millisecond", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketServer, WaitForAccept)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int seconds = arg.GetNumber(0)
	//int millisecond = arg.GetNumber(1)
	//pThis->GetEntity()->WaitForAccept();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketServer)
{
	Gura_AssignMethod(wx_SocketServer, wxSocketServer);
	Gura_AssignMethod(wx_SocketServer, ~wxSocketServer);
	Gura_AssignMethod(wx_SocketServer, Accept);
	Gura_AssignMethod(wx_SocketServer, AcceptWith);
	Gura_AssignMethod(wx_SocketServer, WaitForAccept);
}

Gura_ImplementDescendantCreator(wx_SocketServer)
{
	return new Object_wx_SocketServer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
