//----------------------------------------------------------------------------
// wxChildFocusEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxChildFocusEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxChildFocusEvent
//----------------------------------------------------------------------------
Object_wx_ChildFocusEvent::~Object_wx_ChildFocusEvent()
{
}

Object *Object_wx_ChildFocusEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ChildFocusEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ChildFocusEvent:");
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
// Class implementation for wxChildFocusEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ChildFocusEvent)
{
}

Gura_ImplementDescendantCreator(wx_ChildFocusEvent)
{
	return new Object_wx_ChildFocusEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
