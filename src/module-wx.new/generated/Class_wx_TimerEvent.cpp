//----------------------------------------------------------------------------
// wxTimerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTimerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTimerEvent
//----------------------------------------------------------------------------
Object_wx_TimerEvent::~Object_wx_TimerEvent()
{
}

Object *Object_wx_TimerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TimerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TimerEvent:");
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
// Class implementation for wxTimerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimerEvent)
{
}

Gura_ImplementDescendantCreator(wx_TimerEvent)
{
	return new Object_wx_TimerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
