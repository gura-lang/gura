//----------------------------------------------------------------------------
// wxControlWithItems
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxControlWithItems
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxControlWithItems
//----------------------------------------------------------------------------
Object_wx_ControlWithItems::~Object_wx_ControlWithItems()
{
}

Object *Object_wx_ControlWithItems::Clone() const
{
	return nullptr;
}

String Object_wx_ControlWithItems::ToString(bool exprFlag)
{
	String rtn("<wx.ControlWithItems:");
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
// Class implementation for wxControlWithItems
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ControlWithItems)
{
}

Gura_ImplementDescendantCreator(wx_ControlWithItems)
{
	return new Object_wx_ControlWithItems((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
