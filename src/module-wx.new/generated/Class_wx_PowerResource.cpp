//----------------------------------------------------------------------------
// wxPowerResource
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPowerResource
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPowerResource
//----------------------------------------------------------------------------
Object_wx_PowerResource::~Object_wx_PowerResource()
{
}

Object *Object_wx_PowerResource::Clone() const
{
	return nullptr;
}

String Object_wx_PowerResource::ToString(bool exprFlag)
{
	String rtn("<wx.PowerResource:");
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
// Class implementation for wxPowerResource
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PowerResource)
{
}

Gura_ImplementDescendantCreator(wx_PowerResource)
{
	return new Object_wx_PowerResource((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
