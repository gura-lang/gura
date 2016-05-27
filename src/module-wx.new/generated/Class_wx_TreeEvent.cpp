//----------------------------------------------------------------------------
// wxTreeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeEvent
//----------------------------------------------------------------------------
Object_wx_TreeEvent::~Object_wx_TreeEvent()
{
}

Object *Object_wx_TreeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TreeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TreeEvent:");
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
// Class implementation for wxTreeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeEvent)
{
}

Gura_ImplementDescendantCreator(wx_TreeEvent)
{
	return new Object_wx_TreeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
