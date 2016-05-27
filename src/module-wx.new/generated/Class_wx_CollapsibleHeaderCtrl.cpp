//----------------------------------------------------------------------------
// wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------
Object_wx_CollapsibleHeaderCtrl::~Object_wx_CollapsibleHeaderCtrl()
{
}

Object *Object_wx_CollapsibleHeaderCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_CollapsibleHeaderCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.CollapsibleHeaderCtrl:");
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
// Class implementation for wxCollapsibleHeaderCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CollapsibleHeaderCtrl)
{
}

Gura_ImplementDescendantCreator(wx_CollapsibleHeaderCtrl)
{
	return new Object_wx_CollapsibleHeaderCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
