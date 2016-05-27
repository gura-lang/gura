//----------------------------------------------------------------------------
// wxHashSet
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHashSet
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHashSet
//----------------------------------------------------------------------------
Object_wx_HashSet::~Object_wx_HashSet()
{
}

Object *Object_wx_HashSet::Clone() const
{
	return nullptr;
}

String Object_wx_HashSet::ToString(bool exprFlag)
{
	String rtn("<wx.HashSet:");
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
// Class implementation for wxHashSet
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashSet)
{
}

Gura_ImplementDescendantCreator(wx_HashSet)
{
	return new Object_wx_HashSet((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
