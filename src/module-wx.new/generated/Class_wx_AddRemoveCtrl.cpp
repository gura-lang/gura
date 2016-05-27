//----------------------------------------------------------------------------
// wxAddRemoveCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAddRemoveCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAddRemoveCtrl
//----------------------------------------------------------------------------
Object_wx_AddRemoveCtrl::~Object_wx_AddRemoveCtrl()
{
}

Object *Object_wx_AddRemoveCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_AddRemoveCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.AddRemoveCtrl:");
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
// Class implementation for wxAddRemoveCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AddRemoveCtrl)
{
}

Gura_ImplementDescendantCreator(wx_AddRemoveCtrl)
{
	return new Object_wx_AddRemoveCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
