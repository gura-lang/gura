//----------------------------------------------------------------------------
// wxPowerResourceBlocker
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPowerResourceBlocker
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPowerResourceBlocker
//----------------------------------------------------------------------------
Object_wx_PowerResourceBlocker::~Object_wx_PowerResourceBlocker()
{
}

Object *Object_wx_PowerResourceBlocker::Clone() const
{
	return nullptr;
}

String Object_wx_PowerResourceBlocker::ToString(bool exprFlag)
{
	String rtn("<wx.PowerResourceBlocker:");
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
// Class implementation for wxPowerResourceBlocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PowerResourceBlocker)
{
}

Gura_ImplementDescendantCreator(wx_PowerResourceBlocker)
{
	return new Object_wx_PowerResourceBlocker((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
