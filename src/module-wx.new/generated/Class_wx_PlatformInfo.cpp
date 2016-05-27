//----------------------------------------------------------------------------
// wxPlatformInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPlatformInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPlatformInfo
//----------------------------------------------------------------------------
Object_wx_PlatformInfo::~Object_wx_PlatformInfo()
{
}

Object *Object_wx_PlatformInfo::Clone() const
{
	return nullptr;
}

String Object_wx_PlatformInfo::ToString(bool exprFlag)
{
	String rtn("<wx.PlatformInfo:");
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
// Class implementation for wxPlatformInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PlatformInfo)
{
}

Gura_ImplementDescendantCreator(wx_PlatformInfo)
{
	return new Object_wx_PlatformInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
