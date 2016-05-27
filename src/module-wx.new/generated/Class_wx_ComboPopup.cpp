//----------------------------------------------------------------------------
// wxComboPopup
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxComboPopup
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxComboPopup
//----------------------------------------------------------------------------
Object_wx_ComboPopup::~Object_wx_ComboPopup()
{
}

Object *Object_wx_ComboPopup::Clone() const
{
	return nullptr;
}

String Object_wx_ComboPopup::ToString(bool exprFlag)
{
	String rtn("<wx.ComboPopup:");
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
// Class implementation for wxComboPopup
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboPopup)
{
}

Gura_ImplementDescendantCreator(wx_ComboPopup)
{
	return new Object_wx_ComboPopup((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
