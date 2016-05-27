//----------------------------------------------------------------------------
// wxAuiToolBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiToolBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiToolBar
//----------------------------------------------------------------------------
Object_wx_AuiToolBar::~Object_wx_AuiToolBar()
{
}

Object *Object_wx_AuiToolBar::Clone() const
{
	return nullptr;
}

String Object_wx_AuiToolBar::ToString(bool exprFlag)
{
	String rtn("<wx.AuiToolBar:");
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
// Class implementation for wxAuiToolBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiToolBar)
{
}

Gura_ImplementDescendantCreator(wx_AuiToolBar)
{
	return new Object_wx_AuiToolBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
