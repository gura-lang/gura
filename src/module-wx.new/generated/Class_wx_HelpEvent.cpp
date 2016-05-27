//----------------------------------------------------------------------------
// wxHelpEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHelpEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHelpEvent
//----------------------------------------------------------------------------
Object_wx_HelpEvent::~Object_wx_HelpEvent()
{
}

Object *Object_wx_HelpEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HelpEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HelpEvent:");
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
// Class implementation for wxHelpEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HelpEvent)
{
}

Gura_ImplementDescendantCreator(wx_HelpEvent)
{
	return new Object_wx_HelpEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
