//----------------------------------------------------------------------------
// wxPickerBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPickerBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPickerBase
//----------------------------------------------------------------------------
Object_wx_PickerBase::~Object_wx_PickerBase()
{
}

Object *Object_wx_PickerBase::Clone() const
{
	return nullptr;
}

String Object_wx_PickerBase::ToString(bool exprFlag)
{
	String rtn("<wx.PickerBase:");
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
// Class implementation for wxPickerBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PickerBase)
{
}

Gura_ImplementDescendantCreator(wx_PickerBase)
{
	return new Object_wx_PickerBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
