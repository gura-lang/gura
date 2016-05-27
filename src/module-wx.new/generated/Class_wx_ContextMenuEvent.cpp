//----------------------------------------------------------------------------
// wxContextMenuEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxContextMenuEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxContextMenuEvent
//----------------------------------------------------------------------------
Object_wx_ContextMenuEvent::~Object_wx_ContextMenuEvent()
{
}

Object *Object_wx_ContextMenuEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ContextMenuEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ContextMenuEvent:");
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
// Class implementation for wxContextMenuEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextMenuEvent)
{
}

Gura_ImplementDescendantCreator(wx_ContextMenuEvent)
{
	return new Object_wx_ContextMenuEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
