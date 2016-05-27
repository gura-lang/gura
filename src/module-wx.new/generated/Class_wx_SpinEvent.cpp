//----------------------------------------------------------------------------
// wxSpinEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSpinEvent
//----------------------------------------------------------------------------
Object_wx_SpinEvent::~Object_wx_SpinEvent()
{
}

Object *Object_wx_SpinEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SpinEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SpinEvent:");
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
// Class implementation for wxSpinEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinEvent)
{
}

Gura_ImplementDescendantCreator(wx_SpinEvent)
{
	return new Object_wx_SpinEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
