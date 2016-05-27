//----------------------------------------------------------------------------
// wxMenuItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMenuItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMenuItem
//----------------------------------------------------------------------------
Object_wx_MenuItem::~Object_wx_MenuItem()
{
}

Object *Object_wx_MenuItem::Clone() const
{
	return nullptr;
}

String Object_wx_MenuItem::ToString(bool exprFlag)
{
	String rtn("<wx.MenuItem:");
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
// Class implementation for wxMenuItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MenuItem)
{
}

Gura_ImplementDescendantCreator(wx_MenuItem)
{
	return new Object_wx_MenuItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
