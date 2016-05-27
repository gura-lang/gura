//----------------------------------------------------------------------------
// wxTreeListItemComparator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeListItemComparator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeListItemComparator
//----------------------------------------------------------------------------
Object_wx_TreeListItemComparator::~Object_wx_TreeListItemComparator()
{
}

Object *Object_wx_TreeListItemComparator::Clone() const
{
	return nullptr;
}

String Object_wx_TreeListItemComparator::ToString(bool exprFlag)
{
	String rtn("<wx.TreeListItemComparator:");
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
// Class implementation for wxTreeListItemComparator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeListItemComparator)
{
}

Gura_ImplementDescendantCreator(wx_TreeListItemComparator)
{
	return new Object_wx_TreeListItemComparator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
