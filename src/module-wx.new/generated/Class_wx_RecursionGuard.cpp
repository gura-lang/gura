//----------------------------------------------------------------------------
// wxRecursionGuard
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRecursionGuard
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRecursionGuard
//----------------------------------------------------------------------------
Object_wx_RecursionGuard::~Object_wx_RecursionGuard()
{
}

Object *Object_wx_RecursionGuard::Clone() const
{
	return nullptr;
}

String Object_wx_RecursionGuard::ToString(bool exprFlag)
{
	String rtn("<wx.RecursionGuard:");
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
// Class implementation for wxRecursionGuard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RecursionGuard)
{
}

Gura_ImplementDescendantCreator(wx_RecursionGuard)
{
	return new Object_wx_RecursionGuard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
