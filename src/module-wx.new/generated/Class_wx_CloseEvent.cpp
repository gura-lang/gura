//----------------------------------------------------------------------------
// wxCloseEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCloseEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCloseEvent
//----------------------------------------------------------------------------
Object_wx_CloseEvent::~Object_wx_CloseEvent()
{
}

Object *Object_wx_CloseEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CloseEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CloseEvent:");
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
// Class implementation for wxCloseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CloseEvent)
{
}

Gura_ImplementDescendantCreator(wx_CloseEvent)
{
	return new Object_wx_CloseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
