//----------------------------------------------------------------------------
// wxDataViewTreeCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewTreeCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewTreeCtrl
//----------------------------------------------------------------------------
Object_wx_DataViewTreeCtrl::~Object_wx_DataViewTreeCtrl()
{
}

Object *Object_wx_DataViewTreeCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewTreeCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewTreeCtrl:");
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
// Class implementation for wxDataViewTreeCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewTreeCtrl)
{
}

Gura_ImplementDescendantCreator(wx_DataViewTreeCtrl)
{
	return new Object_wx_DataViewTreeCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
