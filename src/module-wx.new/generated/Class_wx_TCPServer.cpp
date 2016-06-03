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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TCPServer, "TCPServer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TCPServer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TCPServer)
{
	//wxTCPServer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TCPServer, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPServer, __Create)
{
	Object_wx_TCPServer *pThis = Object_wx_TCPServer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& service = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TCPServer, __OnAcceptConnection, "OnAcceptConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPServer, __OnAcceptConnection)
{
	Object_wx_TCPServer *pThis = Object_wx_TCPServer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//pThis->GetEntity()->OnAcceptConnection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTCPServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPServer)
{
	// Constructor assignment
	Gura_AssignFunction(__TCPServer);
	// Method assignment
	Gura_AssignMethod(wx_TCPServer, __Create);
	Gura_AssignMethod(wx_TCPServer, __OnAcceptConnection);
}

Gura_ImplementDescendantCreator(wx_TCPServer)
{
	return new Object_wx_TCPServer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
