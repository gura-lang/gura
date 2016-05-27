//----------------------------------------------------------------------------
// wxDateTimeWorkDays
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDateTimeWorkDays
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDateTimeWorkDays
//----------------------------------------------------------------------------
Object_wx_DateTimeWorkDays::~Object_wx_DateTimeWorkDays()
{
}

Object *Object_wx_DateTimeWorkDays::Clone() const
{
	return nullptr;
}

String Object_wx_DateTimeWorkDays::ToString(bool exprFlag)
{
	String rtn("<wx.DateTimeWorkDays:");
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
// Class implementation for wxDateTimeWorkDays
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateTimeWorkDays)
{
}

Gura_ImplementDescendantCreator(wx_DateTimeWorkDays)
{
	return new Object_wx_DateTimeWorkDays((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
