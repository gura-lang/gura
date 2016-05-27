//----------------------------------------------------------------------------
// wxBitmapButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmapButton
//----------------------------------------------------------------------------
Object_wx_BitmapButton::~Object_wx_BitmapButton()
{
}

Object *Object_wx_BitmapButton::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapButton::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapButton:");
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
// Class implementation for wxBitmapButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapButton)
{
}

Gura_ImplementDescendantCreator(wx_BitmapButton)
{
	return new Object_wx_BitmapButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
