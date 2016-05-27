//----------------------------------------------------------------------------
// wxDataViewListCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewListCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewListCtrl
//----------------------------------------------------------------------------
Object_wx_DataViewListCtrl::~Object_wx_DataViewListCtrl()
{
}

Object *Object_wx_DataViewListCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewListCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewListCtrl:");
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
// Class implementation for wxDataViewListCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewListCtrl)
{
}

Gura_ImplementDescendantCreator(wx_DataViewListCtrl)
{
	return new Object_wx_DataViewListCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
