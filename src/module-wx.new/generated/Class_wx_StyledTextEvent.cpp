//----------------------------------------------------------------------------
// wxStyledTextEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStyledTextEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStyledTextEvent
//----------------------------------------------------------------------------
Object_wx_StyledTextEvent::~Object_wx_StyledTextEvent()
{
}

Object *Object_wx_StyledTextEvent::Clone() const
{
	return nullptr;
}

String Object_wx_StyledTextEvent::ToString(bool exprFlag)
{
	String rtn("<wx.StyledTextEvent:");
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
// Class implementation for wxStyledTextEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StyledTextEvent)
{
}

Gura_ImplementDescendantCreator(wx_StyledTextEvent)
{
	return new Object_wx_StyledTextEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
