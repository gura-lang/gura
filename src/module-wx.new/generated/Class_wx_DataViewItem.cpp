//----------------------------------------------------------------------------
// wxDataViewItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewItem
//----------------------------------------------------------------------------
Object_wx_DataViewItem::~Object_wx_DataViewItem()
{
}

Object *Object_wx_DataViewItem::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewItem::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewItem:");
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
// Class implementation for wxDataViewItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewItem)
{
}

Gura_ImplementDescendantCreator(wx_DataViewItem)
{
	return new Object_wx_DataViewItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
