//----------------------------------------------------------------------------
// wxDataViewColumn
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewColumn
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewColumn
//----------------------------------------------------------------------------
Object_wx_DataViewColumn::~Object_wx_DataViewColumn()
{
}

Object *Object_wx_DataViewColumn::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewColumn::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewColumn:");
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
// Class implementation for wxDataViewColumn
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewColumn)
{
}

Gura_ImplementDescendantCreator(wx_DataViewColumn)
{
	return new Object_wx_DataViewColumn((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
