//----------------------------------------------------------------------------
// wxTreeItemData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeItemData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeItemData
//----------------------------------------------------------------------------
Object_wx_TreeItemData::~Object_wx_TreeItemData()
{
}

Object *Object_wx_TreeItemData::Clone() const
{
	return nullptr;
}

String Object_wx_TreeItemData::ToString(bool exprFlag)
{
	String rtn("<wx.TreeItemData:");
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
// Class implementation for wxTreeItemData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeItemData)
{
}

Gura_ImplementDescendantCreator(wx_TreeItemData)
{
	return new Object_wx_TreeItemData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
