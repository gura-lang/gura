//----------------------------------------------------------------------------
// wxPropertyGridEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridEvent
//----------------------------------------------------------------------------
Object_wx_PropertyGridEvent::~Object_wx_PropertyGridEvent()
{
}

Object *Object_wx_PropertyGridEvent::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridEvent::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridEvent:");
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
// Class implementation for wxPropertyGridEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridEvent)
{
}

Gura_ImplementDescendantCreator(wx_PropertyGridEvent)
{
	return new Object_wx_PropertyGridEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
