//----------------------------------------------------------------------------
// wxTreeCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeCtrl
//----------------------------------------------------------------------------
Object_wx_TreeCtrl::~Object_wx_TreeCtrl()
{
}

Object *Object_wx_TreeCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_TreeCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.TreeCtrl:");
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
// Class implementation for wxTreeCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeCtrl)
{
}

Gura_ImplementDescendantCreator(wx_TreeCtrl)
{
	return new Object_wx_TreeCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
