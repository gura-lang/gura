//----------------------------------------------------------------------------
// wxDialUpEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDialUpEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDialUpEvent
//----------------------------------------------------------------------------
Object_wx_DialUpEvent::~Object_wx_DialUpEvent()
{
}

Object *Object_wx_DialUpEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DialUpEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DialUpEvent:");
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
// Class implementation for wxDialUpEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DialUpEvent)
{
}

Gura_ImplementDescendantCreator(wx_DialUpEvent)
{
	return new Object_wx_DialUpEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
