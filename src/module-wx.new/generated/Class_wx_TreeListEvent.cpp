//----------------------------------------------------------------------------
// wxTreeListEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTreeListEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTreeListEvent
//----------------------------------------------------------------------------
Object_wx_TreeListEvent::~Object_wx_TreeListEvent()
{
}

Object *Object_wx_TreeListEvent::Clone() const
{
	return nullptr;
}

String Object_wx_TreeListEvent::ToString(bool exprFlag)
{
	String rtn("<wx.TreeListEvent:");
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
// Class implementation for wxTreeListEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TreeListEvent)
{
}

Gura_ImplementDescendantCreator(wx_TreeListEvent)
{
	return new Object_wx_TreeListEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
