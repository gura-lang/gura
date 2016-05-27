//----------------------------------------------------------------------------
// wxUpdateUIEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxUpdateUIEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxUpdateUIEvent
//----------------------------------------------------------------------------
Object_wx_UpdateUIEvent::~Object_wx_UpdateUIEvent()
{
}

Object *Object_wx_UpdateUIEvent::Clone() const
{
	return nullptr;
}

String Object_wx_UpdateUIEvent::ToString(bool exprFlag)
{
	String rtn("<wx.UpdateUIEvent:");
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
// Class implementation for wxUpdateUIEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UpdateUIEvent)
{
}

Gura_ImplementDescendantCreator(wx_UpdateUIEvent)
{
	return new Object_wx_UpdateUIEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
