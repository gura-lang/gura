//----------------------------------------------------------------------------
// wxItemContainer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxItemContainer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxItemContainer
//----------------------------------------------------------------------------
Object_wx_ItemContainer::~Object_wx_ItemContainer()
{
}

Object *Object_wx_ItemContainer::Clone() const
{
	return nullptr;
}

String Object_wx_ItemContainer::ToString(bool exprFlag)
{
	String rtn("<wx.ItemContainer:");
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
// Class implementation for wxItemContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ItemContainer)
{
}

Gura_ImplementDescendantCreator(wx_ItemContainer)
{
	return new Object_wx_ItemContainer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
