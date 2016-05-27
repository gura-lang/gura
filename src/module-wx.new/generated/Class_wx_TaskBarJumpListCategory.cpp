//----------------------------------------------------------------------------
// wxTaskBarJumpListCategory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarJumpListCategory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarJumpListCategory
//----------------------------------------------------------------------------
Object_wx_TaskBarJumpListCategory::~Object_wx_TaskBarJumpListCategory()
{
}

Object *Object_wx_TaskBarJumpListCategory::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarJumpListCategory::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarJumpListCategory:");
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
// Class implementation for wxTaskBarJumpListCategory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarJumpListCategory)
{
}

Gura_ImplementDescendantCreator(wx_TaskBarJumpListCategory)
{
	return new Object_wx_TaskBarJumpListCategory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
