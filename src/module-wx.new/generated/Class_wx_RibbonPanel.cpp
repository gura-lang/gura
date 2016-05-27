//----------------------------------------------------------------------------
// wxRibbonPanel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonPanel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonPanel
//----------------------------------------------------------------------------
Object_wx_RibbonPanel::~Object_wx_RibbonPanel()
{
}

Object *Object_wx_RibbonPanel::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonPanel::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonPanel:");
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
// Class implementation for wxRibbonPanel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonPanel)
{
}

Gura_ImplementDescendantCreator(wx_RibbonPanel)
{
	return new Object_wx_RibbonPanel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
