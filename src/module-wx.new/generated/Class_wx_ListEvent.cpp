//----------------------------------------------------------------------------
// wxListEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListEvent
//----------------------------------------------------------------------------
Object_wx_ListEvent::~Object_wx_ListEvent()
{
}

Object *Object_wx_ListEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ListEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ListEvent:");
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
// Class implementation for wxListEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListEvent)
{
}

Gura_ImplementDescendantCreator(wx_ListEvent)
{
	return new Object_wx_ListEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
