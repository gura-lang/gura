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
Gura_DeclareMethod(wx_IPV4address, AnyAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IPV4address, AnyAddress)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AnyAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IPV4address, Hostname)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hostname", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IPV4address, Hostname)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hostname = arg.GetNumber(0)
	//pThis->GetEntity()->Hostname();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IPV4address, Hostname_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IPV4address, Hostname_1)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hostname();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IPV4address, IPAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IPV4address, IPAddress)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IPAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IPV4address, LocalHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IPV4address, LocalHost)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LocalHost();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IPV4address, Service)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IPV4address, Service)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int service = arg.GetNumber(0)
	//pThis->GetEntity()->Service();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IPV4address, Service_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "service", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_IPV4address, Service_1)
{
	Object_wx_IPV4address *pThis = Object_wx_IPV4address::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int service = arg.GetNumber(0)
	//pThis->GetEntity()->Service();
	return Value::Nil;
}

Gura_DeclareMethod(wx_IPV4address, Service_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_IPV4address, Service_2)
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
	Gura_AssignMethod(wx_IPV4address, AnyAddress);
	Gura_AssignMethod(wx_IPV4address, Hostname);
	Gura_AssignMethod(wx_IPV4address, Hostname_1);
	Gura_AssignMethod(wx_IPV4address, IPAddress);
	Gura_AssignMethod(wx_IPV4address, LocalHost);
	Gura_AssignMethod(wx_IPV4address, Service);
	Gura_AssignMethod(wx_IPV4address, Service_1);
	Gura_AssignMethod(wx_IPV4address, Service_2);
}

Gura_ImplementDescendantCreator(wx_IPV4address)
{
	return new Object_wx_IPV4address((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
