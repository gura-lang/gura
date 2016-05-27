//----------------------------------------------------------------------------
// wxRibbonPanelEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonPanelEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonPanelEvent
//----------------------------------------------------------------------------
Object_wx_RibbonPanelEvent::~Object_wx_RibbonPanelEvent()
{
}

Object *Object_wx_RibbonPanelEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonPanelEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonPanelEvent:");
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
// Class implementation for wxRibbonPanelEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonPanelEvent)
{
}

Gura_ImplementDescendantCreator(wx_RibbonPanelEvent)
{
	return new Object_wx_RibbonPanelEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
