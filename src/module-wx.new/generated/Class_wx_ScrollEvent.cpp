//----------------------------------------------------------------------------
// wxScrollEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScrollEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScrollEvent
//----------------------------------------------------------------------------
Object_wx_ScrollEvent::~Object_wx_ScrollEvent()
{
}

Object *Object_wx_ScrollEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ScrollEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ScrollEvent:");
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
// Class implementation for wxScrollEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrollEvent)
{
}

Gura_ImplementDescendantCreator(wx_ScrollEvent)
{
	return new Object_wx_ScrollEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
