//----------------------------------------------------------------------------
// wxClient
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClient
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClient
//----------------------------------------------------------------------------
Object_wx_Client::~Object_wx_Client()
{
}

Object *Object_wx_Client::Clone() const
{
	return nullptr;
}

String Object_wx_Client::ToString(bool exprFlag)
{
	String rtn("<wx.Client:");
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
Gura_DeclareMethodAlias(wx_Client, __wxClient, "wxClient")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Client, __wxClient)
{
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxClient();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Client, __MakeConnection, "MakeConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Client, __MakeConnection)
{
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int host = arg.GetNumber(0)
	//int service = arg.GetNumber(1)
	//int topic = arg.GetNumber(2)
	//pThis->GetEntity()->MakeConnection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Client, __OnMakeConnection, "OnMakeConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Client, __OnMakeConnection)
{
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnMakeConnection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Client, __ValidHost, "ValidHost")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Client, __ValidHost)
{
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int host = arg.GetNumber(0)
	//pThis->GetEntity()->ValidHost();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Client)
{
	Gura_AssignMethod(wx_Client, __wxClient);
	Gura_AssignMethod(wx_Client, __MakeConnection);
	Gura_AssignMethod(wx_Client, __OnMakeConnection);
	Gura_AssignMethod(wx_Client, __ValidHost);
}

Gura_ImplementDescendantCreator(wx_Client)
{
	return new Object_wx_Client((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
