//----------------------------------------------------------------------------
// wxDatePickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDatePickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDatePickerCtrl
//----------------------------------------------------------------------------
Object_wx_DatePickerCtrl::~Object_wx_DatePickerCtrl()
{
}

Object *Object_wx_DatePickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_DatePickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.DatePickerCtrl:");
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
// Class implementation for wxDatePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DatePickerCtrl)
{
}

Gura_ImplementDescendantCreator(wx_DatePickerCtrl)
{
	return new Object_wx_DatePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
