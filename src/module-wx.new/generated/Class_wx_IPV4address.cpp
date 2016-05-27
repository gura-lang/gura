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

//----------------------------------------------------------------------------
// Class implementation for wxIPV4address
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IPV4address)
{
}

Gura_ImplementDescendantCreator(wx_IPV4address)
{
	return new Object_wx_IPV4address((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
