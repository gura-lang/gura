//----------------------------------------------------------------------------
// wxRibbonButtonBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonButtonBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonButtonBar
//----------------------------------------------------------------------------
Object_wx_RibbonButtonBar::~Object_wx_RibbonButtonBar()
{
}

Object *Object_wx_RibbonButtonBar::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonButtonBar::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonButtonBar:");
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
// Class implementation for wxRibbonButtonBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonButtonBar)
{
}

Gura_ImplementDescendantCreator(wx_RibbonButtonBar)
{
	return new Object_wx_RibbonButtonBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
