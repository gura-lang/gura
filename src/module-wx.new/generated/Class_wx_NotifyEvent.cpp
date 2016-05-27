//----------------------------------------------------------------------------
// wxNotifyEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNotifyEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNotifyEvent
//----------------------------------------------------------------------------
Object_wx_NotifyEvent::~Object_wx_NotifyEvent()
{
}

Object *Object_wx_NotifyEvent::Clone() const
{
	return nullptr;
}

String Object_wx_NotifyEvent::ToString(bool exprFlag)
{
	String rtn("<wx.NotifyEvent:");
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
// Class implementation for wxNotifyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NotifyEvent)
{
}

Gura_ImplementDescendantCreator(wx_NotifyEvent)
{
	return new Object_wx_NotifyEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
