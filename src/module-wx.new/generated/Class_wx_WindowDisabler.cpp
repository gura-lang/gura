//----------------------------------------------------------------------------
// wxWindowDisabler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindowDisabler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindowDisabler
//----------------------------------------------------------------------------
Object_wx_WindowDisabler::~Object_wx_WindowDisabler()
{
}

Object *Object_wx_WindowDisabler::Clone() const
{
	return nullptr;
}

String Object_wx_WindowDisabler::ToString(bool exprFlag)
{
	String rtn("<wx.WindowDisabler:");
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
// Class implementation for wxWindowDisabler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WindowDisabler)
{
}

Gura_ImplementDescendantCreator(wx_WindowDisabler)
{
	return new Object_wx_WindowDisabler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
