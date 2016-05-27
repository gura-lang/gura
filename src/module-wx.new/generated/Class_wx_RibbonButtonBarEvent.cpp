//----------------------------------------------------------------------------
// wxRibbonButtonBarEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonButtonBarEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonButtonBarEvent
//----------------------------------------------------------------------------
Object_wx_RibbonButtonBarEvent::~Object_wx_RibbonButtonBarEvent()
{
}

Object *Object_wx_RibbonButtonBarEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonButtonBarEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonButtonBarEvent:");
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
// Class implementation for wxRibbonButtonBarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonButtonBarEvent)
{
}

Gura_ImplementDescendantCreator(wx_RibbonButtonBarEvent)
{
	return new Object_wx_RibbonButtonBarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
