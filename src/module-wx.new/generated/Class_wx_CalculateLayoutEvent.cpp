//----------------------------------------------------------------------------
// wxCalculateLayoutEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCalculateLayoutEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Object_wx_CalculateLayoutEvent::~Object_wx_CalculateLayoutEvent()
{
}

Object *Object_wx_CalculateLayoutEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CalculateLayoutEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CalculateLayoutEvent:");
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
// Class implementation for wxCalculateLayoutEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CalculateLayoutEvent)
{
}

Gura_ImplementDescendantCreator(wx_CalculateLayoutEvent)
{
	return new Object_wx_CalculateLayoutEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
