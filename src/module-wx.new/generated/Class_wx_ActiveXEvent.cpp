//----------------------------------------------------------------------------
// wxActiveXEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxActiveXEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxActiveXEvent
//----------------------------------------------------------------------------
Object_wx_ActiveXEvent::~Object_wx_ActiveXEvent()
{
}

Object *Object_wx_ActiveXEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ActiveXEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ActiveXEvent:");
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
// Class implementation for wxActiveXEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActiveXEvent)
{
}

Gura_ImplementDescendantCreator(wx_ActiveXEvent)
{
	return new Object_wx_ActiveXEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
