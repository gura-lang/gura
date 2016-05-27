//----------------------------------------------------------------------------
// wxDirFilterListCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDirFilterListCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDirFilterListCtrl
//----------------------------------------------------------------------------
Object_wx_DirFilterListCtrl::~Object_wx_DirFilterListCtrl()
{
}

Object *Object_wx_DirFilterListCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DirFilterListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DirFilterListCtrl:");
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
// Class implementation for wxDirFilterListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DirFilterListCtrl)
{
}

Gura_ImplementDescendantCreator(wx_DirFilterListCtrl)
{
	return new Object_wx_DirFilterListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
