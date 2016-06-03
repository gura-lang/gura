//----------------------------------------------------------------------------
// wxDDEServer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEServer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDDEServer
//----------------------------------------------------------------------------
Object_wx_DDEServer::~Object_wx_DDEServer()
{
}

Object *Object_wx_DDEServer::Clone() const
{
	return nullptr;
}

String Object_wx_DDEServer::ToString(bool exprFlag)
{
	String rtn("<wx.DDEServer:");
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
Gura_DeclareMethodAlias(wx_DDEServer, __wxDDEServer, "wxDDEServer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DDEServer, __wxDDEServer)
{
	Object_wx_DDEServer *pThis = Object_wx_DDEServer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDDEServer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEServer, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEServer, __Create)
{
	Object_wx_DDEServer *pThis = Object_wx_DDEServer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int service = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEServer, __OnAcceptConnection, "OnAcceptConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEServer, __OnAcceptConnection)
{
	Object_wx_DDEServer *pThis = Object_wx_DDEServer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int topic = arg.GetNumber(0)
	//pThis->GetEntity()->OnAcceptConnection();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDDEServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEServer)
{
	Gura_AssignMethod(wx_DDEServer, __wxDDEServer);
	Gura_AssignMethod(wx_DDEServer, __Create);
	Gura_AssignMethod(wx_DDEServer, __OnAcceptConnection);
}

Gura_ImplementDescendantCreator(wx_DDEServer)
{
	return new Object_wx_DDEServer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
