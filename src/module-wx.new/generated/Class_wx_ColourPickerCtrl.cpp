//----------------------------------------------------------------------------
// wxColourPickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxColourPickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxColourPickerCtrl
//----------------------------------------------------------------------------
Object_wx_ColourPickerCtrl::~Object_wx_ColourPickerCtrl()
{
}

Object *Object_wx_ColourPickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_ColourPickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.ColourPickerCtrl:");
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
// Class implementation for wxColourPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourPickerCtrl)
{
}

Gura_ImplementDescendantCreator(wx_ColourPickerCtrl)
{
	return new Object_wx_ColourPickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
