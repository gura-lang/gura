//----------------------------------------------------------------------------
// wxDataViewTreeStore
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewTreeStore
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewTreeStore
//----------------------------------------------------------------------------
Object_wx_DataViewTreeStore::~Object_wx_DataViewTreeStore()
{
}

Object *Object_wx_DataViewTreeStore::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewTreeStore::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewTreeStore:");
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
// Class implementation for wxDataViewTreeStore
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewTreeStore)
{
}

Gura_ImplementDescendantCreator(wx_DataViewTreeStore)
{
	return new Object_wx_DataViewTreeStore((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
