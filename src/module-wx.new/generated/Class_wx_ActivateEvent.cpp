//----------------------------------------------------------------------------
// wxActivateEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxActivateEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxActivateEvent
//----------------------------------------------------------------------------
Object_wx_ActivateEvent::~Object_wx_ActivateEvent()
{
}

Object *Object_wx_ActivateEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ActivateEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ActivateEvent:");
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
// Class implementation for wxActivateEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActivateEvent)
{
	
}

Gura_ImplementDescendantCreator(wx_ActivateEvent)
{
	return new Object_wx_ActivateEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
