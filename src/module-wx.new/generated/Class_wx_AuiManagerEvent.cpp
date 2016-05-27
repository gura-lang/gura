//----------------------------------------------------------------------------
// wxAuiManagerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiManagerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiManagerEvent
//----------------------------------------------------------------------------
Object_wx_AuiManagerEvent::~Object_wx_AuiManagerEvent()
{
}

Object *Object_wx_AuiManagerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_AuiManagerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.AuiManagerEvent:");
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
// Class implementation for wxAuiManagerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiManagerEvent)
{
}

Gura_ImplementDescendantCreator(wx_AuiManagerEvent)
{
	return new Object_wx_AuiManagerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
