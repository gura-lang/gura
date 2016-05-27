//----------------------------------------------------------------------------
// wxFontPickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontPickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontPickerCtrl
//----------------------------------------------------------------------------
Object_wx_FontPickerCtrl::~Object_wx_FontPickerCtrl()
{
}

Object *Object_wx_FontPickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_FontPickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.FontPickerCtrl:");
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
// Class implementation for wxFontPickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontPickerCtrl)
{
}

Gura_ImplementDescendantCreator(wx_FontPickerCtrl)
{
	return new Object_wx_FontPickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
