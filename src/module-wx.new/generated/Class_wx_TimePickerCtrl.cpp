//----------------------------------------------------------------------------
// wxTimePickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTimePickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTimePickerCtrl
//----------------------------------------------------------------------------
Object_wx_TimePickerCtrl::~Object_wx_TimePickerCtrl()
{
}

Object *Object_wx_TimePickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_TimePickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.TimePickerCtrl:");
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
// Class implementation for wxTimePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimePickerCtrl)
{
}

Gura_ImplementDescendantCreator(wx_TimePickerCtrl)
{
	return new Object_wx_TimePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
