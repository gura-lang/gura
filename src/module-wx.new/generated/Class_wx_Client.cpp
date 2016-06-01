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
Gura_DeclareMethod(wx_Client, wxClient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Client, wxClient)
{
	Signal &sig = env.GetSignal();
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxClient();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Client, MakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Client, MakeConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int host = arg.GetNumber(0)
	//int service = arg.GetNumber(1)
	//int topic = arg.GetNumber(2)
	//pThis->GetEntity()->MakeConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Client, OnMakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Client, OnMakeConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnMakeConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Client, ValidHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Client, ValidHost)
{
	Signal &sig = env.GetSignal();
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int host = arg.GetNumber(0)
	//pThis->GetEntity()->ValidHost();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Client)
{
	Gura_AssignMethod(wx_Client, wxClient);
	Gura_AssignMethod(wx_Client, MakeConnection);
	Gura_AssignMethod(wx_Client, OnMakeConnection);
	Gura_AssignMethod(wx_Client, ValidHost);
}

Gura_ImplementDescendantCreator(wx_Client)
{
	return new Object_wx_Client((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
