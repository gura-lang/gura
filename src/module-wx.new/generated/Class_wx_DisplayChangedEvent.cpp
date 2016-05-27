//----------------------------------------------------------------------------
// wxDisplayChangedEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDisplayChangedEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDisplayChangedEvent
//----------------------------------------------------------------------------
Object_wx_DisplayChangedEvent::~Object_wx_DisplayChangedEvent()
{
}

Object *Object_wx_DisplayChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DisplayChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DisplayChangedEvent:");
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
// Class implementation for wxDisplayChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DisplayChangedEvent)
{
}

Gura_ImplementDescendantCreator(wx_DisplayChangedEvent)
{
	return new Object_wx_DisplayChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
