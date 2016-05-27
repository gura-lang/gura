//----------------------------------------------------------------------------
// wxMaximizeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMaximizeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMaximizeEvent
//----------------------------------------------------------------------------
Object_wx_MaximizeEvent::~Object_wx_MaximizeEvent()
{
}

Object *Object_wx_MaximizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MaximizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MaximizeEvent:");
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
// Class implementation for wxMaximizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MaximizeEvent)
{
}

Gura_ImplementDescendantCreator(wx_MaximizeEvent)
{
	return new Object_wx_MaximizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
