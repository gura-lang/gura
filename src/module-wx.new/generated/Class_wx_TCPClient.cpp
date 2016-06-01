//----------------------------------------------------------------------------
// wxTCPClient
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTCPClient
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTCPClient
//----------------------------------------------------------------------------
Object_wx_TCPClient::~Object_wx_TCPClient()
{
}

Object *Object_wx_TCPClient::Clone() const
{
	return nullptr;
}

String Object_wx_TCPClient::ToString(bool exprFlag)
{
	String rtn("<wx.TCPClient:");
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
Gura_DeclareMethod(wx_TCPClient, wxTCPClient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TCPClient, wxTCPClient)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPClient *pThis = Object_wx_TCPClient::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTCPClient();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPClient, MakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPClient, MakeConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPClient *pThis = Object_wx_TCPClient::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int host = arg.GetNumber(0)
	//int service = arg.GetNumber(1)
	//int topic = arg.GetNumber(2)
	//pThis->GetEntity()->MakeConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPClient, OnMakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TCPClient, OnMakeConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPClient *pThis = Object_wx_TCPClient::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnMakeConnection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TCPClient, ValidHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TCPClient, ValidHost)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPClient *pThis = Object_wx_TCPClient::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int host = arg.GetNumber(0)
	//pThis->GetEntity()->ValidHost();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTCPClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPClient)
{
	Gura_AssignMethod(wx_TCPClient, wxTCPClient);
	Gura_AssignMethod(wx_TCPClient, MakeConnection);
	Gura_AssignMethod(wx_TCPClient, OnMakeConnection);
	Gura_AssignMethod(wx_TCPClient, ValidHost);
}

Gura_ImplementDescendantCreator(wx_TCPClient)
{
	return new Object_wx_TCPClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
