//----------------------------------------------------------------------------
// wxSystemSettings
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSystemSettings
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSystemSettings
//----------------------------------------------------------------------------
Object_wx_SystemSettings::~Object_wx_SystemSettings()
{
}

Object *Object_wx_SystemSettings::Clone() const
{
	return nullptr;
}

String Object_wx_SystemSettings::ToString(bool exprFlag)
{
	String rtn("<wx.SystemSettings:");
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
// Class implementation for wxSystemSettings
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SystemSettings)
{
}

Gura_ImplementDescendantCreator(wx_SystemSettings)
{
	return new Object_wx_SystemSettings((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
