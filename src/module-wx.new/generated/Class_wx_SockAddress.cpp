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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxSockAddress, "wxSockAddress")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxSockAddress)
{
	//wxSockAddress();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SockAddress, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, __Clear)
{
	Object_wx_SockAddress *pThis = Object_wx_SockAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SockAddress, __SockAddrLen, "SockAddrLen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, __SockAddrLen)
{
	Object_wx_SockAddress *pThis = Object_wx_SockAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SockAddrLen();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SockAddress, __GetAddressData, "GetAddressData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, __GetAddressData)
{
	Object_wx_SockAddress *pThis = Object_wx_SockAddress::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAddressData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SockAddress, __GetAddressDataLen, "GetAddressDataLen")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, __GetAddressDataLen)
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
	// Constructor assignment
	Gura_AssignFunction(__wxSockAddress);
	// Method assignment
	Gura_AssignMethod(wx_SockAddress, __Clear);
	Gura_AssignMethod(wx_SockAddress, __SockAddrLen);
	Gura_AssignMethod(wx_SockAddress, __GetAddressData);
	Gura_AssignMethod(wx_SockAddress, __GetAddressDataLen);
}

Gura_ImplementDescendantCreator(wx_SockAddress)
{
	return new Object_wx_SockAddress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
