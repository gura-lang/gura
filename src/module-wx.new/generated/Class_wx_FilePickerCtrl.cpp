//----------------------------------------------------------------------------
// wxFilePickerCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFilePickerCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFilePickerCtrl
//----------------------------------------------------------------------------
Object_wx_FilePickerCtrl::~Object_wx_FilePickerCtrl()
{
}

Object *Object_wx_FilePickerCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_FilePickerCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.FilePickerCtrl:");
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
// Class implementation for wxFilePickerCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilePickerCtrl)
{
}

Gura_ImplementDescendantCreator(wx_FilePickerCtrl)
{
	return new Object_wx_FilePickerCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
