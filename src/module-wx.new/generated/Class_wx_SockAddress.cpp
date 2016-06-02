//----------------------------------------------------------------------------
// wxSockAddress
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSockAddress
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSockAddress
//----------------------------------------------------------------------------
Object_wx_SockAddress::~Object_wx_SockAddress()
{
}

Object *Object_wx_SockAddress::Clone() const
{
	return nullptr;
}

String Object_wx_SockAddress::ToString(bool exprFlag)
{
	String rtn("<wx.SockAddress:");
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
Gura_DeclareMethod(wx_SockAddress, wxSockAddress)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, wxSockAddress)
{
	Object_wx_SockAddress *pThis = Object_wx_SockAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxSockAddress();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SockAddress, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, Clear)
{
	Object_wx_SockAddress *pThis = Object_wx_SockAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SockAddress, SockAddrLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, SockAddrLen)
{
	Object_wx_SockAddress *pThis = Object_wx_SockAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SockAddrLen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SockAddress, GetAddressData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, GetAddressData)
{
	Object_wx_SockAddress *pThis = Object_wx_SockAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAddressData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SockAddress, GetAddressDataLen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, GetAddressDataLen)
{
	Object_wx_SockAddress *pThis = Object_wx_SockAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAddressDataLen();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSockAddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SockAddress)
{
	Gura_AssignMethod(wx_SockAddress, wxSockAddress);
	Gura_AssignMethod(wx_SockAddress, Clear);
	Gura_AssignMethod(wx_SockAddress, SockAddrLen);
	Gura_AssignMethod(wx_SockAddress, GetAddressData);
	Gura_AssignMethod(wx_SockAddress, GetAddressDataLen);
}

Gura_ImplementDescendantCreator(wx_SockAddress)
{
	return new Object_wx_SockAddress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
