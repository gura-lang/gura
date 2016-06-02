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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Server, wxServer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Server, wxServer)
{
	Object_wx_Server *pThis = Object_wx_Server::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxServer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Server, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Server, Create)
{
	Object_wx_Server *pThis = Object_wx_Server::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int service = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Server, OnAcceptConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Server, OnAcceptConnection)
{
	Object_wx_Server *pThis = Object_wx_Server::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//pThis->GetEntity()->OnAcceptConnection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Server)
{
	Gura_AssignMethod(wx_Server, wxServer);
	Gura_AssignMethod(wx_Server, Create);
	Gura_AssignMethod(wx_Server, OnAcceptConnection);
}

Gura_ImplementDescendantCreator(wx_Server)
{
	return new Object_wx_Server((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
