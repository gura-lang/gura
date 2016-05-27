//----------------------------------------------------------------------------
// wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
Object_wx_WebKitBeforeLoadEvent::~Object_wx_WebKitBeforeLoadEvent()
{
}

Object *Object_wx_WebKitBeforeLoadEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WebKitBeforeLoadEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WebKitBeforeLoadEvent:");
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
// Class implementation for wxWebKitBeforeLoadEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitBeforeLoadEvent)
{
}

Gura_ImplementDescendantCreator(wx_WebKitBeforeLoadEvent)
{
	return new Object_wx_WebKitBeforeLoadEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
