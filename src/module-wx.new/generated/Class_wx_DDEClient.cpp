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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DDEClient, "DDEClient")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DDEClient));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DDEClient)
{
	//wxDDEClient();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DDEClient, __MakeConnection, "MakeConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topic", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEClient, __MakeConnection)
{
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& host = arg.GetNumber(0)
	//const wxString& service = arg.GetNumber(1)
	//const wxString& topic = arg.GetNumber(2)
	//wxConnectionBase* _rtn = pThis->GetEntity()->MakeConnection(host, service, topic);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEClient, __OnMakeConnection, "OnMakeConnection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DDEClient, __OnMakeConnection)
{
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxConnectionBase* _rtn = pThis->GetEntity()->OnMakeConnection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DDEClient, __ValidHost, "ValidHost")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "host", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DDEClient, __ValidHost)
{
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& host = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ValidHost(host);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDDEClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEClient)
{
	// Constructor assignment
	Gura_AssignFunction(__DDEClient);
	// Method assignment
	Gura_AssignMethod(wx_DDEClient, __MakeConnection);
	Gura_AssignMethod(wx_DDEClient, __OnMakeConnection);
	Gura_AssignMethod(wx_DDEClient, __ValidHost);
}

Gura_ImplementDescendantCreator(wx_DDEClient)
{
	return new Object_wx_DDEClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
