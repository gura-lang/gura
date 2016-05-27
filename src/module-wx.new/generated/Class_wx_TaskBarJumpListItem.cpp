//----------------------------------------------------------------------------
// wxTaskBarJumpListItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarJumpListItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarJumpListItem
//----------------------------------------------------------------------------
Object_wx_TaskBarJumpListItem::~Object_wx_TaskBarJumpListItem()
{
}

Object *Object_wx_TaskBarJumpListItem::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarJumpListItem::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarJumpListItem:");
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
// Class implementation for wxTaskBarJumpListItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarJumpListItem)
{
}

Gura_ImplementDescendantCreator(wx_TaskBarJumpListItem)
{
	return new Object_wx_TaskBarJumpListItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
