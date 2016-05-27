//----------------------------------------------------------------------------
// wxTaskBarJumpList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarJumpList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarJumpList
//----------------------------------------------------------------------------
Object_wx_TaskBarJumpList::~Object_wx_TaskBarJumpList()
{
}

Object *Object_wx_TaskBarJumpList::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarJumpList::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarJumpList:");
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
// Class implementation for wxTaskBarJumpList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarJumpList)
{
}

Gura_ImplementDescendantCreator(wx_TaskBarJumpList)
{
	return new Object_wx_TaskBarJumpList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
