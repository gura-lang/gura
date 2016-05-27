//----------------------------------------------------------------------------
// wxDisplay
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDisplay
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDisplay
//----------------------------------------------------------------------------
Object_wx_Display::~Object_wx_Display()
{
}

Object *Object_wx_Display::Clone() const
{
	return nullptr;
}

String Object_wx_Display::ToString(bool exprFlag)
{
	String rtn("<wx.Display:");
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
// Class implementation for wxDisplay
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Display)
{
}

Gura_ImplementDescendantCreator(wx_Display)
{
	return new Object_wx_Display((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
