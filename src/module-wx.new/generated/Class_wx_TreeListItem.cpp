//----------------------------------------------------------------------------
// wxTreeListItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeListItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeListItem
//----------------------------------------------------------------------------
Object_wx_TreeListItem::~Object_wx_TreeListItem()
{
}

Object *Object_wx_TreeListItem::Clone() const
{
	return nullptr;
}

String Object_wx_TreeListItem::ToString(bool exprFlag)
{
	String rtn("<wx.TreeListItem:");
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
// Class implementation for wxTreeListItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeListItem)
{
}

Gura_ImplementDescendantCreator(wx_TreeListItem)
{
	return new Object_wx_TreeListItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
