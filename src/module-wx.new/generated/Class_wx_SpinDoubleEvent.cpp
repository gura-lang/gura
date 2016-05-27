//----------------------------------------------------------------------------
// wxSpinDoubleEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinDoubleEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSpinDoubleEvent
//----------------------------------------------------------------------------
Object_wx_SpinDoubleEvent::~Object_wx_SpinDoubleEvent()
{
}

Object *Object_wx_SpinDoubleEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SpinDoubleEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SpinDoubleEvent:");
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
// Class implementation for wxSpinDoubleEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinDoubleEvent)
{
}

Gura_ImplementDescendantCreator(wx_SpinDoubleEvent)
{
	return new Object_wx_SpinDoubleEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
