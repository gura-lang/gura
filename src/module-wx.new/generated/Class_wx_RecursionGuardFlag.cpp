//----------------------------------------------------------------------------
// wxRecursionGuardFlag
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRecursionGuardFlag
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRecursionGuardFlag
//----------------------------------------------------------------------------
Object_wx_RecursionGuardFlag::~Object_wx_RecursionGuardFlag()
{
}

Object *Object_wx_RecursionGuardFlag::Clone() const
{
	return nullptr;
}

String Object_wx_RecursionGuardFlag::ToString(bool exprFlag)
{
	String rtn("<wx.RecursionGuardFlag:");
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
// Class implementation for wxRecursionGuardFlag
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RecursionGuardFlag)
{
}

Gura_ImplementDescendantCreator(wx_RecursionGuardFlag)
{
	return new Object_wx_RecursionGuardFlag((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
