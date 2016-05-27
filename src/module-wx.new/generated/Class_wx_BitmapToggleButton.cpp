//----------------------------------------------------------------------------
// wxBitmapToggleButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapToggleButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmapToggleButton
//----------------------------------------------------------------------------
Object_wx_BitmapToggleButton::~Object_wx_BitmapToggleButton()
{
}

Object *Object_wx_BitmapToggleButton::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapToggleButton::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapToggleButton:");
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
// Class implementation for wxBitmapToggleButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapToggleButton)
{
}

Gura_ImplementDescendantCreator(wx_BitmapToggleButton)
{
	return new Object_wx_BitmapToggleButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
