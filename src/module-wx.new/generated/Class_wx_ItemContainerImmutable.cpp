//----------------------------------------------------------------------------
// wxItemContainerImmutable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxItemContainerImmutable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxItemContainerImmutable
//----------------------------------------------------------------------------
Object_wx_ItemContainerImmutable::~Object_wx_ItemContainerImmutable()
{
}

Object *Object_wx_ItemContainerImmutable::Clone() const
{
	return nullptr;
}

String Object_wx_ItemContainerImmutable::ToString(bool exprFlag)
{
	String rtn("<wx.ItemContainerImmutable:");
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
// Class implementation for wxItemContainerImmutable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ItemContainerImmutable)
{
}

Gura_ImplementDescendantCreator(wx_ItemContainerImmutable)
{
	return new Object_wx_ItemContainerImmutable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
