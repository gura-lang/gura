//----------------------------------------------------------------------------
// wxAuiToolBarItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiToolBarItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiToolBarItem
//----------------------------------------------------------------------------
Object_wx_AuiToolBarItem::~Object_wx_AuiToolBarItem()
{
}

Object *Object_wx_AuiToolBarItem::Clone() const
{
	return nullptr;
}

String Object_wx_AuiToolBarItem::ToString(bool exprFlag)
{
	String rtn("<wx.AuiToolBarItem:");
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
// Class implementation for wxAuiToolBarItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiToolBarItem)
{
}

Gura_ImplementDescendantCreator(wx_AuiToolBarItem)
{
	return new Object_wx_AuiToolBarItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
