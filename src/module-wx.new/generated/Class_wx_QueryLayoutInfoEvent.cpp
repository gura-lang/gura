//----------------------------------------------------------------------------
// wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
Object_wx_QueryLayoutInfoEvent::~Object_wx_QueryLayoutInfoEvent()
{
}

Object *Object_wx_QueryLayoutInfoEvent::Clone() const
{
	return nullptr;
}

String Object_wx_QueryLayoutInfoEvent::ToString(bool exprFlag)
{
	String rtn("<wx.QueryLayoutInfoEvent:");
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
// Class implementation for wxQueryLayoutInfoEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_QueryLayoutInfoEvent)
{
}

Gura_ImplementDescendantCreator(wx_QueryLayoutInfoEvent)
{
	return new Object_wx_QueryLayoutInfoEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
