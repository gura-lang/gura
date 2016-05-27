//----------------------------------------------------------------------------
// wxIdleEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIdleEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIdleEvent
//----------------------------------------------------------------------------
Object_wx_IdleEvent::~Object_wx_IdleEvent()
{
}

Object *Object_wx_IdleEvent::Clone() const
{
	return nullptr;
}

String Object_wx_IdleEvent::ToString(bool exprFlag)
{
	String rtn("<wx.IdleEvent:");
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
// Class implementation for wxIdleEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IdleEvent)
{
}

Gura_ImplementDescendantCreator(wx_IdleEvent)
{
	return new Object_wx_IdleEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
