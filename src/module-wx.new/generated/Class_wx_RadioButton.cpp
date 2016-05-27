//----------------------------------------------------------------------------
// wxRadioButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRadioButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRadioButton
//----------------------------------------------------------------------------
Object_wx_RadioButton::~Object_wx_RadioButton()
{
}

Object *Object_wx_RadioButton::Clone() const
{
	return nullptr;
}

String Object_wx_RadioButton::ToString(bool exprFlag)
{
	String rtn("<wx.RadioButton:");
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
// Class implementation for wxRadioButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RadioButton)
{
}

Gura_ImplementDescendantCreator(wx_RadioButton)
{
	return new Object_wx_RadioButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
