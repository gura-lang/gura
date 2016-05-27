//----------------------------------------------------------------------------
// wxWindowDestroyEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDestroyEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Object_wx_WindowDestroyEvent::~Object_wx_WindowDestroyEvent()
{
}

Object *Object_wx_WindowDestroyEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WindowDestroyEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WindowDestroyEvent:");
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
// Class implementation for wxWindowDestroyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDestroyEvent)
{
}

Gura_ImplementDescendantCreator(wx_WindowDestroyEvent)
{
	return new Object_wx_WindowDestroyEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
