//----------------------------------------------------------------------------
// wxAuiManager
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiManager
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiManager
//----------------------------------------------------------------------------
Object_wx_AuiManager::~Object_wx_AuiManager()
{
}

Object *Object_wx_AuiManager::Clone() const
{
	return nullptr;
}

String Object_wx_AuiManager::ToString(bool exprFlag)
{
	String rtn("<wx.AuiManager:");
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
// Class implementation for wxAuiManager
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiManager)
{
}

Gura_ImplementDescendantCreator(wx_AuiManager)
{
	return new Object_wx_AuiManager((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
