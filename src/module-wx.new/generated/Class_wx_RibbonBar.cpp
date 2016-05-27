//----------------------------------------------------------------------------
// wxRibbonBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonBar
//----------------------------------------------------------------------------
Object_wx_RibbonBar::~Object_wx_RibbonBar()
{
}

Object *Object_wx_RibbonBar::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonBar::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonBar:");
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
// Class implementation for wxRibbonBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonBar)
{
}

Gura_ImplementDescendantCreator(wx_RibbonBar)
{
	return new Object_wx_RibbonBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
