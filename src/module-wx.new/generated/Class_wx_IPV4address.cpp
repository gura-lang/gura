//----------------------------------------------------------------------------
// wxIPV4address
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIPV4address
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIPV4address
//----------------------------------------------------------------------------
Object_wx_IPV4address::~Object_wx_IPV4address()
{
}

Object *Object_wx_IPV4address::Clone() const
{
	return nullptr;
}

String Object_wx_IPV4address::ToString(bool exprFlag)
{
	String rtn("<wx.IPV4address:");
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
Gura_DeclareMethodAlias(wx_IPV4address, __AnyAddress, "AnyAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IPV4address, __AnyAddress)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AnyAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPV4address, __Hostname, "Hostname")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hostname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IPV4address, __Hostname)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& hostname = arg.GetNumber(0)
	//pThis->GetEntity()->Hostname(hostname);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPV4address, __Hostname_1, "Hostname_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IPV4address, __Hostname_1)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hostname();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPV4address, __IPAddress, "IPAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IPV4address, __IPAddress)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IPAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPV4address, __LocalHost, "LocalHost")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IPV4address, __LocalHost)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LocalHost();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPV4address, __Service, "Service")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IPV4address, __Service)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& service = arg.GetNumber(0)
	//pThis->GetEntity()->Service(service);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPV4address, __Service_1, "Service_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IPV4address, __Service_1)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned short service = arg.GetNumber(0)
	//pThis->GetEntity()->Service(service);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPV4address, __Service_2, "Service_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IPV4address, __Service_2)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Service();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIPV4address
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IPV4address)
{
	// Class assignment
	Gura_AssignValueEx("IPV4address", Reference());
	// Method assignment
	Gura_AssignMethod(wx_IPV4address, __AnyAddress);
	Gura_AssignMethod(wx_IPV4address, __Hostname);
	Gura_AssignMethod(wx_IPV4address, __Hostname_1);
	Gura_AssignMethod(wx_IPV4address, __IPAddress);
	Gura_AssignMethod(wx_IPV4address, __LocalHost);
	Gura_AssignMethod(wx_IPV4address, __Service);
	Gura_AssignMethod(wx_IPV4address, __Service_1);
	Gura_AssignMethod(wx_IPV4address, __Service_2);
}

Gura_ImplementDescendantCreator(wx_IPV4address)
{
	return new Object_wx_IPV4address((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
