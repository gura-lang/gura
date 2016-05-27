//----------------------------------------------------------------------------
// wxDataViewCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewCtrl
//----------------------------------------------------------------------------
Object_wx_DataViewCtrl::~Object_wx_DataViewCtrl()
{
}

Object *Object_wx_DataViewCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewCtrl:");
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
// Class implementation for wxDataViewCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewCtrl)
{
}

Gura_ImplementDescendantCreator(wx_DataViewCtrl)
{
	return new Object_wx_DataViewCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
