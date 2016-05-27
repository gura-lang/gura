//----------------------------------------------------------------------------
// wxToggleButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxToggleButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToggleButton
//----------------------------------------------------------------------------
Object_wx_ToggleButton::~Object_wx_ToggleButton()
{
}

Object *Object_wx_ToggleButton::Clone() const
{
	return nullptr;
}

String Object_wx_ToggleButton::ToString(bool exprFlag)
{
	String rtn("<wx.ToggleButton:");
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
// Class implementation for wxToggleButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToggleButton)
{
}

Gura_ImplementDescendantCreator(wx_ToggleButton)
{
	return new Object_wx_ToggleButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
