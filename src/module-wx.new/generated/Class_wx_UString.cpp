//----------------------------------------------------------------------------
// wxUString
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxUString
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxUString
//----------------------------------------------------------------------------
Object_wx_UString::~Object_wx_UString()
{
}

Object *Object_wx_UString::Clone() const
{
	return nullptr;
}

String Object_wx_UString::ToString(bool exprFlag)
{
	String rtn("<wx.UString:");
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
// Class implementation for wxUString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UString)
{
}

Gura_ImplementDescendantCreator(wx_UString)
{
	return new Object_wx_UString((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
