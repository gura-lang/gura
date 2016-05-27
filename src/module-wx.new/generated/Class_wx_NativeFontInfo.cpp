//----------------------------------------------------------------------------
// wxNativeFontInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNativeFontInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNativeFontInfo
//----------------------------------------------------------------------------
Object_wx_NativeFontInfo::~Object_wx_NativeFontInfo()
{
}

Object *Object_wx_NativeFontInfo::Clone() const
{
	return nullptr;
}

String Object_wx_NativeFontInfo::ToString(bool exprFlag)
{
	String rtn("<wx.NativeFontInfo:");
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
// Class implementation for wxNativeFontInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NativeFontInfo)
{
}

Gura_ImplementDescendantCreator(wx_NativeFontInfo)
{
	return new Object_wx_NativeFontInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
