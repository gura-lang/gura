//----------------------------------------------------------------------------
// wxStatusBarPane
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStatusBarPane
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStatusBarPane
//----------------------------------------------------------------------------
Object_wx_StatusBarPane::~Object_wx_StatusBarPane()
{
}

Object *Object_wx_StatusBarPane::Clone() const
{
	return nullptr;
}

String Object_wx_StatusBarPane::ToString(bool exprFlag)
{
	String rtn("<wx.StatusBarPane:");
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
// Class implementation for wxStatusBarPane
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StatusBarPane)
{
}

Gura_ImplementDescendantCreator(wx_StatusBarPane)
{
	return new Object_wx_StatusBarPane((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
