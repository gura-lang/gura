//----------------------------------------------------------------------------
// wxMoveEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMoveEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMoveEvent
//----------------------------------------------------------------------------
Object_wx_MoveEvent::~Object_wx_MoveEvent()
{
}

Object *Object_wx_MoveEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MoveEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MoveEvent:");
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
// Class implementation for wxMoveEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MoveEvent)
{
}

Gura_ImplementDescendantCreator(wx_MoveEvent)
{
	return new Object_wx_MoveEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
