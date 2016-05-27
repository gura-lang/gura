//----------------------------------------------------------------------------
// wxDataViewListModel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewListModel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewListModel
//----------------------------------------------------------------------------
Object_wx_DataViewListModel::~Object_wx_DataViewListModel()
{
}

Object *Object_wx_DataViewListModel::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewListModel::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewListModel:");
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
// Class implementation for wxDataViewListModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewListModel)
{
}

Gura_ImplementDescendantCreator(wx_DataViewListModel)
{
	return new Object_wx_DataViewListModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
