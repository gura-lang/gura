//----------------------------------------------------------------------------
// wxProcessEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxProcessEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxProcessEvent
//----------------------------------------------------------------------------
Object_wx_ProcessEvent::~Object_wx_ProcessEvent()
{
}

Object *Object_wx_ProcessEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ProcessEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ProcessEvent:");
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
// Class implementation for wxProcessEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ProcessEvent)
{
}

Gura_ImplementDescendantCreator(wx_ProcessEvent)
{
	return new Object_wx_ProcessEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
