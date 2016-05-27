//----------------------------------------------------------------------------
// wxHeaderCtrlEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHeaderCtrlEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHeaderCtrlEvent
//----------------------------------------------------------------------------
Object_wx_HeaderCtrlEvent::~Object_wx_HeaderCtrlEvent()
{
}

Object *Object_wx_HeaderCtrlEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HeaderCtrlEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HeaderCtrlEvent:");
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
// Class implementation for wxHeaderCtrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderCtrlEvent)
{
}

Gura_ImplementDescendantCreator(wx_HeaderCtrlEvent)
{
	return new Object_wx_HeaderCtrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
