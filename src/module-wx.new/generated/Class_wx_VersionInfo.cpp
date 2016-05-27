//----------------------------------------------------------------------------
// wxVersionInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVersionInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVersionInfo
//----------------------------------------------------------------------------
Object_wx_VersionInfo::~Object_wx_VersionInfo()
{
}

Object *Object_wx_VersionInfo::Clone() const
{
	return nullptr;
}

String Object_wx_VersionInfo::ToString(bool exprFlag)
{
	String rtn("<wx.VersionInfo:");
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
// Class implementation for wxVersionInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VersionInfo)
{
}

Gura_ImplementDescendantCreator(wx_VersionInfo)
{
	return new Object_wx_VersionInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
