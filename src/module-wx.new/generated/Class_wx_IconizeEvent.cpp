//----------------------------------------------------------------------------
// wxIconizeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIconizeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIconizeEvent
//----------------------------------------------------------------------------
Object_wx_IconizeEvent::~Object_wx_IconizeEvent()
{
}

Object *Object_wx_IconizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_IconizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.IconizeEvent:");
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
// Class implementation for wxIconizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconizeEvent)
{
}

Gura_ImplementDescendantCreator(wx_IconizeEvent)
{
	return new Object_wx_IconizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
