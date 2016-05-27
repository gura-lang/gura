//----------------------------------------------------------------------------
// wxDataViewItemAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewItemAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewItemAttr
//----------------------------------------------------------------------------
Object_wx_DataViewItemAttr::~Object_wx_DataViewItemAttr()
{
}

Object *Object_wx_DataViewItemAttr::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewItemAttr::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewItemAttr:");
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
// Class implementation for wxDataViewItemAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewItemAttr)
{
}

Gura_ImplementDescendantCreator(wx_DataViewItemAttr)
{
	return new Object_wx_DataViewItemAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
