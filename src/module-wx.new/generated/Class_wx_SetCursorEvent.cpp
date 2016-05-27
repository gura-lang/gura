//----------------------------------------------------------------------------
// wxSetCursorEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSetCursorEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSetCursorEvent
//----------------------------------------------------------------------------
Object_wx_SetCursorEvent::~Object_wx_SetCursorEvent()
{
}

Object *Object_wx_SetCursorEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SetCursorEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SetCursorEvent:");
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
// Class implementation for wxSetCursorEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SetCursorEvent)
{
}

Gura_ImplementDescendantCreator(wx_SetCursorEvent)
{
	return new Object_wx_SetCursorEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
