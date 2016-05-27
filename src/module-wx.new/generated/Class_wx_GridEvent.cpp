//----------------------------------------------------------------------------
// wxGridEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridEvent
//----------------------------------------------------------------------------
Object_wx_GridEvent::~Object_wx_GridEvent()
{
}

Object *Object_wx_GridEvent::Clone() const
{
	return nullptr;
}

String Object_wx_GridEvent::ToString(bool exprFlag)
{
	String rtn("<wx.GridEvent:");
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
// Class implementation for wxGridEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridEvent)
{
}

Gura_ImplementDescendantCreator(wx_GridEvent)
{
	return new Object_wx_GridEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
