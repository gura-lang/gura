//----------------------------------------------------------------------------
// wxBookCtrlEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBookCtrlEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBookCtrlEvent
//----------------------------------------------------------------------------
Object_wx_BookCtrlEvent::~Object_wx_BookCtrlEvent()
{
}

Object *Object_wx_BookCtrlEvent::Clone() const
{
	return nullptr;
}

String Object_wx_BookCtrlEvent::ToString(bool exprFlag)
{
	String rtn("<wx.BookCtrlEvent:");
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
// Class implementation for wxBookCtrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BookCtrlEvent)
{
}

Gura_ImplementDescendantCreator(wx_BookCtrlEvent)
{
	return new Object_wx_BookCtrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
