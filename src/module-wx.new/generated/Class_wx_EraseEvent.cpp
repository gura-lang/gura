//----------------------------------------------------------------------------
// wxEraseEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEraseEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEraseEvent
//----------------------------------------------------------------------------
Object_wx_EraseEvent::~Object_wx_EraseEvent()
{
}

Object *Object_wx_EraseEvent::Clone() const
{
	return nullptr;
}

String Object_wx_EraseEvent::ToString(bool exprFlag)
{
	String rtn("<wx.EraseEvent:");
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
// Class implementation for wxEraseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EraseEvent)
{
}

Gura_ImplementDescendantCreator(wx_EraseEvent)
{
	return new Object_wx_EraseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
