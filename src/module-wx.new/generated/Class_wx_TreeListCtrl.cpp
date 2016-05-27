//----------------------------------------------------------------------------
// wxTreeListCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeListCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeListCtrl
//----------------------------------------------------------------------------
Object_wx_TreeListCtrl::~Object_wx_TreeListCtrl()
{
}

Object *Object_wx_TreeListCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_TreeListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.TreeListCtrl:");
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
// Class implementation for wxTreeListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeListCtrl)
{
}

Gura_ImplementDescendantCreator(wx_TreeListCtrl)
{
	return new Object_wx_TreeListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
