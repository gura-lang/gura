//----------------------------------------------------------------------------
// wxCommandEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCommandEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCommandEvent
//----------------------------------------------------------------------------
Object_wx_CommandEvent::~Object_wx_CommandEvent()
{
}

Object *Object_wx_CommandEvent::Clone() const
{
	return nullptr;
}

String Object_wx_CommandEvent::ToString(bool exprFlag)
{
	String rtn("<wx.CommandEvent:");
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
// Class implementation for wxCommandEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CommandEvent)
{
}

Gura_ImplementDescendantCreator(wx_CommandEvent)
{
	return new Object_wx_CommandEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
