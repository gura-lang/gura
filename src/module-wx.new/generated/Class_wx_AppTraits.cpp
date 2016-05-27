//----------------------------------------------------------------------------
// wxAppTraits
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAppTraits
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAppTraits
//----------------------------------------------------------------------------
Object_wx_AppTraits::~Object_wx_AppTraits()
{
}

Object *Object_wx_AppTraits::Clone() const
{
	return nullptr;
}

String Object_wx_AppTraits::ToString(bool exprFlag)
{
	String rtn("<wx.AppTraits:");
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
// Class implementation for wxAppTraits
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AppTraits)
{
}

Gura_ImplementDescendantCreator(wx_AppTraits)
{
	return new Object_wx_AppTraits((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
