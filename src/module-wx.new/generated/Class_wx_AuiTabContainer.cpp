//----------------------------------------------------------------------------
// wxAuiTabContainer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiTabContainer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiTabContainer
//----------------------------------------------------------------------------
Object_wx_AuiTabContainer::~Object_wx_AuiTabContainer()
{
}

Object *Object_wx_AuiTabContainer::Clone() const
{
	return nullptr;
}

String Object_wx_AuiTabContainer::ToString(bool exprFlag)
{
	String rtn("<wx.AuiTabContainer:");
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
// Class implementation for wxAuiTabContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiTabContainer)
{
}

Gura_ImplementDescendantCreator(wx_AuiTabContainer)
{
	return new Object_wx_AuiTabContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
