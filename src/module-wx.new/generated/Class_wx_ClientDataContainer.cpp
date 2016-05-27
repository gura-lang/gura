//----------------------------------------------------------------------------
// wxClientDataContainer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClientDataContainer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClientDataContainer
//----------------------------------------------------------------------------
Object_wx_ClientDataContainer::~Object_wx_ClientDataContainer()
{
}

Object *Object_wx_ClientDataContainer::Clone() const
{
	return nullptr;
}

String Object_wx_ClientDataContainer::ToString(bool exprFlag)
{
	String rtn("<wx.ClientDataContainer:");
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
// Class implementation for wxClientDataContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientDataContainer)
{
}

Gura_ImplementDescendantCreator(wx_ClientDataContainer)
{
	return new Object_wx_ClientDataContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
