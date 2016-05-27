//----------------------------------------------------------------------------
// wxTimerRunner
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTimerRunner
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTimerRunner
//----------------------------------------------------------------------------
Object_wx_TimerRunner::~Object_wx_TimerRunner()
{
}

Object *Object_wx_TimerRunner::Clone() const
{
	return nullptr;
}

String Object_wx_TimerRunner::ToString(bool exprFlag)
{
	String rtn("<wx.TimerRunner:");
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
// Class implementation for wxTimerRunner
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimerRunner)
{
}

Gura_ImplementDescendantCreator(wx_TimerRunner)
{
	return new Object_wx_TimerRunner((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
