//----------------------------------------------------------------------------
// wxTextUrlEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextUrlEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextUrlEvent
//----------------------------------------------------------------------------
Object_wx_TextUrlEvent::~Object_wx_TextUrlEvent()
{
}

Object *Object_wx_TextUrlEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TextUrlEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TextUrlEvent:");
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
// Class implementation for wxTextUrlEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextUrlEvent)
{
}

Gura_ImplementDescendantCreator(wx_TextUrlEvent)
{
	return new Object_wx_TextUrlEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
