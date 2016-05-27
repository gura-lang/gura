//----------------------------------------------------------------------------
// wxClassInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxClassInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxClassInfo
//----------------------------------------------------------------------------
Object_wx_ClassInfo::~Object_wx_ClassInfo()
{
}

Object *Object_wx_ClassInfo::Clone() const
{
	return nullptr;
}

String Object_wx_ClassInfo::ToString(bool exprFlag)
{
	String rtn("<wx.ClassInfo:");
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
// Class implementation for wxClassInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClassInfo)
{
}

Gura_ImplementDescendantCreator(wx_ClassInfo)
{
	return new Object_wx_ClassInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
