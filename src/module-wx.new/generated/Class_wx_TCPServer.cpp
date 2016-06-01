//----------------------------------------------------------------------------
// wxTCPServer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTCPServer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTCPServer
//----------------------------------------------------------------------------
Object_wx_TCPServer::~Object_wx_TCPServer()
{
}

Object *Object_wx_TCPServer::Clone() const
{
	return nullptr;
}

String Object_wx_TCPServer::ToString(bool exprFlag)
{
	String rtn("<wx.TCPServer:");
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
Gura_DeclareMethod(wx_TCPServer, wxTCPServer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TCPServer, wxTCPServer)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPServer *pThis = Object_wx_TCPServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTCPServer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPServer, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPServer, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPServer *pThis = Object_wx_TCPServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int service = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPServer, OnAcceptConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPServer, OnAcceptConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPServer *pThis = Object_wx_TCPServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//pThis->GetEntity()->OnAcceptConnection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTCPServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPServer)
{
	Gura_AssignMethod(wx_TCPServer, wxTCPServer);
	Gura_AssignMethod(wx_TCPServer, Create);
	Gura_AssignMethod(wx_TCPServer, OnAcceptConnection);
}

Gura_ImplementDescendantCreator(wx_TCPServer)
{
	return new Object_wx_TCPServer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
