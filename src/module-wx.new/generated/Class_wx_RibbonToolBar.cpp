//----------------------------------------------------------------------------
// wxRibbonToolBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonToolBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonToolBar
//----------------------------------------------------------------------------
Object_wx_RibbonToolBar::~Object_wx_RibbonToolBar()
{
}

Object *Object_wx_RibbonToolBar::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonToolBar::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonToolBar:");
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
// Class implementation for wxRibbonToolBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonToolBar)
{
}

Gura_ImplementDescendantCreator(wx_RibbonToolBar)
{
	return new Object_wx_RibbonToolBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
