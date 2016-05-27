//----------------------------------------------------------------------------
// wxDataViewVirtualListModel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewVirtualListModel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewVirtualListModel
//----------------------------------------------------------------------------
Object_wx_DataViewVirtualListModel::~Object_wx_DataViewVirtualListModel()
{
}

Object *Object_wx_DataViewVirtualListModel::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewVirtualListModel::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewVirtualListModel:");
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
// Class implementation for wxDataViewVirtualListModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewVirtualListModel)
{
}

Gura_ImplementDescendantCreator(wx_DataViewVirtualListModel)
{
	return new Object_wx_DataViewVirtualListModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
