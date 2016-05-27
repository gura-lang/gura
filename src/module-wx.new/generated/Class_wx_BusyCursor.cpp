//----------------------------------------------------------------------------
// wxBusyCursor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBusyCursor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBusyCursor
//----------------------------------------------------------------------------
Object_wx_BusyCursor::~Object_wx_BusyCursor()
{
}

Object *Object_wx_BusyCursor::Clone() const
{
	return nullptr;
}

String Object_wx_BusyCursor::ToString(bool exprFlag)
{
	String rtn("<wx.BusyCursor:");
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
// Class implementation for wxBusyCursor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BusyCursor)
{
}

Gura_ImplementDescendantCreator(wx_BusyCursor)
{
	return new Object_wx_BusyCursor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
