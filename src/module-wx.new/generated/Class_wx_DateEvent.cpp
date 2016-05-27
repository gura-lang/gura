//----------------------------------------------------------------------------
// wxDateEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDateEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDateEvent
//----------------------------------------------------------------------------
Object_wx_DateEvent::~Object_wx_DateEvent()
{
}

Object *Object_wx_DateEvent::Clone() const
{
	return nullptr;
}

String Object_wx_DateEvent::ToString(bool exprFlag)
{
	String rtn("<wx.DateEvent:");
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
// Class implementation for wxDateEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateEvent)
{
}

Gura_ImplementDescendantCreator(wx_DateEvent)
{
	return new Object_wx_DateEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
