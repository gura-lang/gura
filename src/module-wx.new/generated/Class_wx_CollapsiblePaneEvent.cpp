//----------------------------------------------------------------------------
// wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Object_wx_CollapsiblePaneEvent::~Object_wx_CollapsiblePaneEvent()
{
}

Object *Object_wx_CollapsiblePaneEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CollapsiblePaneEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CollapsiblePaneEvent:");
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
// Class implementation for wxCollapsiblePaneEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CollapsiblePaneEvent)
{
}

Gura_ImplementDescendantCreator(wx_CollapsiblePaneEvent)
{
	return new Object_wx_CollapsiblePaneEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
