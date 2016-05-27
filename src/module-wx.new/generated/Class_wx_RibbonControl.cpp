//----------------------------------------------------------------------------
// wxRibbonControl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonControl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonControl
//----------------------------------------------------------------------------
Object_wx_RibbonControl::~Object_wx_RibbonControl()
{
}

Object *Object_wx_RibbonControl::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonControl::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonControl:");
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
// Class implementation for wxRibbonControl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonControl)
{
}

Gura_ImplementDescendantCreator(wx_RibbonControl)
{
	return new Object_wx_RibbonControl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
