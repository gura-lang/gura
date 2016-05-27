//----------------------------------------------------------------------------
// wxComboBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxComboBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxComboBox
//----------------------------------------------------------------------------
Object_wx_ComboBox::~Object_wx_ComboBox()
{
}

Object *Object_wx_ComboBox::Clone() const
{
	return nullptr;
}

String Object_wx_ComboBox::ToString(bool exprFlag)
{
	String rtn("<wx.ComboBox:");
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
// Class implementation for wxComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ComboBox)
{
}

Gura_ImplementDescendantCreator(wx_ComboBox)
{
	return new Object_wx_ComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
