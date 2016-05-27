//----------------------------------------------------------------------------
// wxMask
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMask
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMask
//----------------------------------------------------------------------------
Object_wx_Mask::~Object_wx_Mask()
{
}

Object *Object_wx_Mask::Clone() const
{
	return nullptr;
}

String Object_wx_Mask::ToString(bool exprFlag)
{
	String rtn("<wx.Mask:");
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
// Class implementation for wxMask
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Mask)
{
}

Gura_ImplementDescendantCreator(wx_Mask)
{
	return new Object_wx_Mask((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
