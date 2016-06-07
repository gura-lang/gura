//----------------------------------------------------------------------------
// wxServer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxServer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxServer
//----------------------------------------------------------------------------
Object_wx_Server::~Object_wx_Server()
{
}

Object *Object_wx_Server::Clone() const
{
	return nullptr;
}

String Object_wx_Server::ToString(bool exprFlag)
{
	String rtn("<wx.Server:");
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
Gura_DeclareFunctionAlias(__Server, "Server")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Server));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Server)
{
	//wxServer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Server, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Server, __Create)
{
	Object_wx_Server *pThis = Object_wx_Server::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& service = arg.GetNumber(0)
	//pThis->GetEntity()->Create(service);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Server, __OnAcceptConnection, "OnAcceptConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Server, __OnAcceptConnection)
{
	Object_wx_Server *pThis = Object_wx_Server::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& topic = arg.GetNumber(0)
	//pThis->GetEntity()->OnAcceptConnection(topic);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Server)
{
	// Constructor assignment
	Gura_AssignFunction(__Server);
	// Method assignment
	Gura_AssignMethod(wx_Server, __Create);
	Gura_AssignMethod(wx_Server, __OnAcceptConnection);
}

Gura_ImplementDescendantCreator(wx_Server)
{
	return new Object_wx_Server((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
