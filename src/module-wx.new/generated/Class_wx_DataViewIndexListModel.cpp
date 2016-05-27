//----------------------------------------------------------------------------
// wxDataViewIndexListModel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewIndexListModel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewIndexListModel
//----------------------------------------------------------------------------
Object_wx_DataViewIndexListModel::~Object_wx_DataViewIndexListModel()
{
}

Object *Object_wx_DataViewIndexListModel::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewIndexListModel::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewIndexListModel:");
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
// Class implementation for wxDataViewIndexListModel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewIndexListModel)
{
}

Gura_ImplementDescendantCreator(wx_DataViewIndexListModel)
{
	return new Object_wx_DataViewIndexListModel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
