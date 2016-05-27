//----------------------------------------------------------------------------
// wxToolTip
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxToolTip
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolTip
//----------------------------------------------------------------------------
Object_wx_ToolTip::~Object_wx_ToolTip()
{
}

Object *Object_wx_ToolTip::Clone() const
{
	return nullptr;
}

String Object_wx_ToolTip::ToString(bool exprFlag)
{
	String rtn("<wx.ToolTip:");
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
// Class implementation for wxToolTip
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolTip)
{
}

Gura_ImplementDescendantCreator(wx_ToolTip)
{
	return new Object_wx_ToolTip((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
