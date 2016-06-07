//----------------------------------------------------------------------------
// wxIPaddress
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIPaddress
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIPaddress
//----------------------------------------------------------------------------
Object_wx_IPaddress::~Object_wx_IPaddress()
{
}

Object *Object_wx_IPaddress::Clone() const
{
	return nullptr;
}

String Object_wx_IPaddress::ToString(bool exprFlag)
{
	String rtn("<wx.IPaddress:");
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
Gura_DeclareMethodAlias(wx_IPaddress, __AnyAddress, "AnyAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IPaddress, __AnyAddress)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->AnyAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPaddress, __BroadcastAddress, "BroadcastAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IPaddress, __BroadcastAddress)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->BroadcastAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPaddress, __Hostname, "Hostname")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "hostname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IPaddress, __Hostname)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& hostname = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Hostname(hostname);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPaddress, __Hostname_1, "Hostname_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IPaddress, __Hostname_1)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->Hostname();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPaddress, __IPAddress, "IPAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IPaddress, __IPAddress)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->IPAddress();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPaddress, __IsLocalHost, "IsLocalHost")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IPaddress, __IsLocalHost)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsLocalHost();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPaddress, __LocalHost, "LocalHost")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IPaddress, __LocalHost)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->LocalHost();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPaddress, __Service, "Service")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IPaddress, __Service)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& service = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Service(service);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPaddress, __Service_1, "Service_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IPaddress, __Service_1)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned short service = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->Service(service);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_IPaddress, __Service_2, "Service_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_IPaddress, __Service_2)
{
	Object_wx_IPaddress *pThis = Object_wx_IPaddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned short _rtn = pThis->GetEntity()->Service();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxIPaddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IPaddress)
{
	// Class assignment
	Gura_AssignValueEx("IPaddress", Reference());
	// Method assignment
	Gura_AssignMethod(wx_IPaddress, __AnyAddress);
	Gura_AssignMethod(wx_IPaddress, __BroadcastAddress);
	Gura_AssignMethod(wx_IPaddress, __Hostname);
	Gura_AssignMethod(wx_IPaddress, __Hostname_1);
	Gura_AssignMethod(wx_IPaddress, __IPAddress);
	Gura_AssignMethod(wx_IPaddress, __IsLocalHost);
	Gura_AssignMethod(wx_IPaddress, __LocalHost);
	Gura_AssignMethod(wx_IPaddress, __Service);
	Gura_AssignMethod(wx_IPaddress, __Service_1);
	Gura_AssignMethod(wx_IPaddress, __Service_2);
}

Gura_ImplementDescendantCreator(wx_IPaddress)
{
	return new Object_wx_IPaddress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
