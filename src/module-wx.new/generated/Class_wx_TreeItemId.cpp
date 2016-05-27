//----------------------------------------------------------------------------
// wxTreeItemId
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeItemId
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeItemId
//----------------------------------------------------------------------------
Object_wx_TreeItemId::~Object_wx_TreeItemId()
{
}

Object *Object_wx_TreeItemId::Clone() const
{
	return nullptr;
}

String Object_wx_TreeItemId::ToString(bool exprFlag)
{
	String rtn("<wx.TreeItemId:");
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
// Class implementation for wxTreeItemId
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeItemId)
{
}

Gura_ImplementDescendantCreator(wx_TreeItemId)
{
	return new Object_wx_TreeItemId((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
