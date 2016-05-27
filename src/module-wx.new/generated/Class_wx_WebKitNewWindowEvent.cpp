//----------------------------------------------------------------------------
// wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
Object_wx_WebKitNewWindowEvent::~Object_wx_WebKitNewWindowEvent()
{
}

Object *Object_wx_WebKitNewWindowEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WebKitNewWindowEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WebKitNewWindowEvent:");
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
// Class implementation for wxWebKitNewWindowEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitNewWindowEvent)
{
}

Gura_ImplementDescendantCreator(wx_WebKitNewWindowEvent)
{
	return new Object_wx_WebKitNewWindowEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
