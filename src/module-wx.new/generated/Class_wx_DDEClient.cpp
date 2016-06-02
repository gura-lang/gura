//----------------------------------------------------------------------------
// wxDDEClient
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEClient
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDDEClient
//----------------------------------------------------------------------------
Object_wx_DDEClient::~Object_wx_DDEClient()
{
}

Object *Object_wx_DDEClient::Clone() const
{
	return nullptr;
}

String Object_wx_DDEClient::ToString(bool exprFlag)
{
	String rtn("<wx.DDEClient:");
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
Gura_DeclareMethod(wx_DDEClient, wxDDEClient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DDEClient, wxDDEClient)
{
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDDEClient();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEClient, MakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEClient, MakeConnection)
{
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int host = arg.GetNumber(0)
	//int service = arg.GetNumber(1)
	//int topic = arg.GetNumber(2)
	//pThis->GetEntity()->MakeConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEClient, OnMakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DDEClient, OnMakeConnection)
{
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnMakeConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DDEClient, ValidHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEClient, ValidHost)
{
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int host = arg.GetNumber(0)
	//pThis->GetEntity()->ValidHost();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDDEClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEClient)
{
	Gura_AssignMethod(wx_DDEClient, wxDDEClient);
	Gura_AssignMethod(wx_DDEClient, MakeConnection);
	Gura_AssignMethod(wx_DDEClient, OnMakeConnection);
	Gura_AssignMethod(wx_DDEClient, ValidHost);
}

Gura_ImplementDescendantCreator(wx_DDEClient)
{
	return new Object_wx_DDEClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
