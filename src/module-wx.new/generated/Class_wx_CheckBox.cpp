//----------------------------------------------------------------------------
// wxCheckBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCheckBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCheckBox
//----------------------------------------------------------------------------
Object_wx_CheckBox::~Object_wx_CheckBox()
{
}

Object *Object_wx_CheckBox::Clone() const
{
	return nullptr;
}

String Object_wx_CheckBox::ToString(bool exprFlag)
{
	String rtn("<wx.CheckBox:");
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
// Class implementation for wxCheckBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CheckBox)
{
}

Gura_ImplementDescendantCreator(wx_CheckBox)
{
	return new Object_wx_CheckBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
