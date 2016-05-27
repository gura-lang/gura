//----------------------------------------------------------------------------
// wxCalendarDateAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCalendarDateAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCalendarDateAttr
//----------------------------------------------------------------------------
Object_wx_CalendarDateAttr::~Object_wx_CalendarDateAttr()
{
}

Object *Object_wx_CalendarDateAttr::Clone() const
{
	return nullptr;
}

String Object_wx_CalendarDateAttr::ToString(bool exprFlag)
{
	String rtn("<wx.CalendarDateAttr:");
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
// Class implementation for wxCalendarDateAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalendarDateAttr)
{
}

Gura_ImplementDescendantCreator(wx_CalendarDateAttr)
{
	return new Object_wx_CalendarDateAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
