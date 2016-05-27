//----------------------------------------------------------------------------
// wxAuiToolBarEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiToolBarEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiToolBarEvent
//----------------------------------------------------------------------------
Object_wx_AuiToolBarEvent::~Object_wx_AuiToolBarEvent()
{
}

Object *Object_wx_AuiToolBarEvent::Clone() const
{
	return nullptr;
}

String Object_wx_AuiToolBarEvent::ToString(bool exprFlag)
{
	String rtn("<wx.AuiToolBarEvent:");
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
// Class implementation for wxAuiToolBarEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiToolBarEvent)
{
}

Gura_ImplementDescendantCreator(wx_AuiToolBarEvent)
{
	return new Object_wx_AuiToolBarEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
