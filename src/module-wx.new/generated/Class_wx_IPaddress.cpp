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

//----------------------------------------------------------------------------
// Class implementation for wxIPaddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IPaddress)
{
}

Gura_ImplementDescendantCreator(wx_IPaddress)
{
	return new Object_wx_IPaddress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
