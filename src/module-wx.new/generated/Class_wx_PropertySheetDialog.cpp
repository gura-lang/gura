//----------------------------------------------------------------------------
// wxPropertySheetDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertySheetDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertySheetDialog
//----------------------------------------------------------------------------
Object_wx_PropertySheetDialog::~Object_wx_PropertySheetDialog()
{
}

Object *Object_wx_PropertySheetDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PropertySheetDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PropertySheetDialog:");
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
// Class implementation for wxPropertySheetDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertySheetDialog)
{
}

Gura_ImplementDescendantCreator(wx_PropertySheetDialog)
{
	return new Object_wx_PropertySheetDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
