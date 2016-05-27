//----------------------------------------------------------------------------
// wxRibbonBarEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonBarEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonBarEvent
//----------------------------------------------------------------------------
Object_wx_RibbonBarEvent::~Object_wx_RibbonBarEvent()
{
}

Object *Object_wx_RibbonBarEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonBarEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonBarEvent:");
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
// Class implementation for wxRibbonBarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonBarEvent)
{
}

Gura_ImplementDescendantCreator(wx_RibbonBarEvent)
{
	return new Object_wx_RibbonBarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
