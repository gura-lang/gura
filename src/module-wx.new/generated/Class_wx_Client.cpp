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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Client, "Client")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Client));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Client)
{
	//wxClient();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Client, __MakeConnection, "MakeConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Client, __MakeConnection)
{
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& host = arg.GetNumber(0)
	//const wxString& service = arg.GetNumber(1)
	//const wxString& topic = arg.GetNumber(2)
	//wxConnectionBase* _rtn = pThis->GetEntity()->MakeConnection(host, service, topic);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Client, __OnMakeConnection, "OnMakeConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Client, __OnMakeConnection)
{
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxConnectionBase* _rtn = pThis->GetEntity()->OnMakeConnection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Client, __ValidHost, "ValidHost")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Client, __ValidHost)
{
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& host = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ValidHost(host);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Client)
{
	// Constructor assignment
	Gura_AssignFunction(__Client);
	// Method assignment
	Gura_AssignMethod(wx_Client, __MakeConnection);
	Gura_AssignMethod(wx_Client, __OnMakeConnection);
	Gura_AssignMethod(wx_Client, __ValidHost);
}

Gura_ImplementDescendantCreator(wx_Client)
{
	return new Object_wx_Client((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
