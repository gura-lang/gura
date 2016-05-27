//----------------------------------------------------------------------------
// wxDialogLayoutAdapter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDialogLayoutAdapter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDialogLayoutAdapter
//----------------------------------------------------------------------------
Object_wx_DialogLayoutAdapter::~Object_wx_DialogLayoutAdapter()
{
}

Object *Object_wx_DialogLayoutAdapter::Clone() const
{
	return nullptr;
}

String Object_wx_DialogLayoutAdapter::ToString(bool exprFlag)
{
	String rtn("<wx.DialogLayoutAdapter:");
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
// Class implementation for wxDialogLayoutAdapter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialogLayoutAdapter)
{
}

Gura_ImplementDescendantCreator(wx_DialogLayoutAdapter)
{
	return new Object_wx_DialogLayoutAdapter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
