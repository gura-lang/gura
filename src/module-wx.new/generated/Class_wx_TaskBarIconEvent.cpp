//----------------------------------------------------------------------------
// wxTaskBarIconEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarIconEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarIconEvent
//----------------------------------------------------------------------------
Object_wx_TaskBarIconEvent::~Object_wx_TaskBarIconEvent()
{
}

Object *Object_wx_TaskBarIconEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarIconEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarIconEvent:");
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
// Class implementation for wxTaskBarIconEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarIconEvent)
{
}

Gura_ImplementDescendantCreator(wx_TaskBarIconEvent)
{
	return new Object_wx_TaskBarIconEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
