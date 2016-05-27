//----------------------------------------------------------------------------
// wxAuiPaneInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiPaneInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiPaneInfo
//----------------------------------------------------------------------------
Object_wx_AuiPaneInfo::~Object_wx_AuiPaneInfo()
{
}

Object *Object_wx_AuiPaneInfo::Clone() const
{
	return nullptr;
}

String Object_wx_AuiPaneInfo::ToString(bool exprFlag)
{
	String rtn("<wx.AuiPaneInfo:");
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
// Class implementation for wxAuiPaneInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiPaneInfo)
{
}

Gura_ImplementDescendantCreator(wx_AuiPaneInfo)
{
	return new Object_wx_AuiPaneInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
