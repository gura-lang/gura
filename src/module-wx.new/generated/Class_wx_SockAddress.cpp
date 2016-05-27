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
// Class implementation for wxSockAddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SockAddress)
{
}

Gura_ImplementDescendantCreator(wx_SockAddress)
{
	return new Object_wx_SockAddress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
