//----------------------------------------------------------------------------
// wxGBPosition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGBPosition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGBPosition
//----------------------------------------------------------------------------
Object_wx_GBPosition::~Object_wx_GBPosition()
{
}

Object *Object_wx_GBPosition::Clone() const
{
	return nullptr;
}

String Object_wx_GBPosition::ToString(bool exprFlag)
{
	String rtn("<wx.GBPosition:");
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
// Class implementation for wxGBPosition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBPosition)
{
}

Gura_ImplementDescendantCreator(wx_GBPosition)
{
	return new Object_wx_GBPosition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
