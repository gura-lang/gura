//----------------------------------------------------------------------------
// wxNavigationKeyEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNavigationKeyEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNavigationKeyEvent
//----------------------------------------------------------------------------
Object_wx_NavigationKeyEvent::~Object_wx_NavigationKeyEvent()
{
}

Object *Object_wx_NavigationKeyEvent::Clone() const
{
	return nullptr;
}

String Object_wx_NavigationKeyEvent::ToString(bool exprFlag)
{
	String rtn("<wx.NavigationKeyEvent:");
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
// Class implementation for wxNavigationKeyEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NavigationKeyEvent)
{
	
}

Gura_ImplementDescendantCreator(wx_NavigationKeyEvent)
{
	return new Object_wx_NavigationKeyEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
