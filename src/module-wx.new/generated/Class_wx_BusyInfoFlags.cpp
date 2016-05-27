//----------------------------------------------------------------------------
// wxBusyInfoFlags
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBusyInfoFlags
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBusyInfoFlags
//----------------------------------------------------------------------------
Object_wx_BusyInfoFlags::~Object_wx_BusyInfoFlags()
{
}

Object *Object_wx_BusyInfoFlags::Clone() const
{
	return nullptr;
}

String Object_wx_BusyInfoFlags::ToString(bool exprFlag)
{
	String rtn("<wx.BusyInfoFlags:");
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
// Class implementation for wxBusyInfoFlags
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BusyInfoFlags)
{
}

Gura_ImplementDescendantCreator(wx_BusyInfoFlags)
{
	return new Object_wx_BusyInfoFlags((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
