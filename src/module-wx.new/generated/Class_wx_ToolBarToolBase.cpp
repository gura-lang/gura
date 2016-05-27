//----------------------------------------------------------------------------
// wxToolBarToolBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxToolBarToolBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolBarToolBase
//----------------------------------------------------------------------------
Object_wx_ToolBarToolBase::~Object_wx_ToolBarToolBase()
{
}

Object *Object_wx_ToolBarToolBase::Clone() const
{
	return nullptr;
}

String Object_wx_ToolBarToolBase::ToString(bool exprFlag)
{
	String rtn("<wx.ToolBarToolBase:");
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
// Class implementation for wxToolBarToolBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolBarToolBase)
{
}

Gura_ImplementDescendantCreator(wx_ToolBarToolBase)
{
	return new Object_wx_ToolBarToolBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
