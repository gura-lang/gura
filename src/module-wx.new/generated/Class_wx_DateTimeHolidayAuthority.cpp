//----------------------------------------------------------------------------
// wxDateTimeHolidayAuthority
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDateTimeHolidayAuthority
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDateTimeHolidayAuthority
//----------------------------------------------------------------------------
Object_wx_DateTimeHolidayAuthority::~Object_wx_DateTimeHolidayAuthority()
{
}

Object *Object_wx_DateTimeHolidayAuthority::Clone() const
{
	return nullptr;
}

String Object_wx_DateTimeHolidayAuthority::ToString(bool exprFlag)
{
	String rtn("<wx.DateTimeHolidayAuthority:");
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
// Class implementation for wxDateTimeHolidayAuthority
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateTimeHolidayAuthority)
{
	
}

Gura_ImplementDescendantCreator(wx_DateTimeHolidayAuthority)
{
	return new Object_wx_DateTimeHolidayAuthority((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
