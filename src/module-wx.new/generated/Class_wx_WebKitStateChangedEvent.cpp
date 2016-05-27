//----------------------------------------------------------------------------
// wxWebKitStateChangedEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebKitStateChangedEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebKitStateChangedEvent
//----------------------------------------------------------------------------
Object_wx_WebKitStateChangedEvent::~Object_wx_WebKitStateChangedEvent()
{
}

Object *Object_wx_WebKitStateChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WebKitStateChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WebKitStateChangedEvent:");
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
// Class implementation for wxWebKitStateChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitStateChangedEvent)
{
}

Gura_ImplementDescendantCreator(wx_WebKitStateChangedEvent)
{
	return new Object_wx_WebKitStateChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
