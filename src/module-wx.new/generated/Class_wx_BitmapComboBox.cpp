//----------------------------------------------------------------------------
// wxBitmapComboBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapComboBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmapComboBox
//----------------------------------------------------------------------------
Object_wx_BitmapComboBox::~Object_wx_BitmapComboBox()
{
}

Object *Object_wx_BitmapComboBox::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapComboBox::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapComboBox:");
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
// Class implementation for wxBitmapComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapComboBox)
{
}

Gura_ImplementDescendantCreator(wx_BitmapComboBox)
{
	return new Object_wx_BitmapComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
