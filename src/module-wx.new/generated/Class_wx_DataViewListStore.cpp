//----------------------------------------------------------------------------
// wxDataViewListStore
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewListStore
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewListStore
//----------------------------------------------------------------------------
Object_wx_DataViewListStore::~Object_wx_DataViewListStore()
{
}

Object *Object_wx_DataViewListStore::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewListStore::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewListStore:");
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
// Class implementation for wxDataViewListStore
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewListStore)
{
}

Gura_ImplementDescendantCreator(wx_DataViewListStore)
{
	return new Object_wx_DataViewListStore((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
