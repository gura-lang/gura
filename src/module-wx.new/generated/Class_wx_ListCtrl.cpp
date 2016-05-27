//----------------------------------------------------------------------------
// wxListCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListCtrl
//----------------------------------------------------------------------------
Object_wx_ListCtrl::~Object_wx_ListCtrl()
{
}

Object *Object_wx_ListCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_ListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.ListCtrl:");
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
// Class implementation for wxListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListCtrl)
{
}

Gura_ImplementDescendantCreator(wx_ListCtrl)
{
	return new Object_wx_ListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
