//----------------------------------------------------------------------------
// wxPageSetupDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPageSetupDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPageSetupDialog
//----------------------------------------------------------------------------
Object_wx_PageSetupDialog::~Object_wx_PageSetupDialog()
{
}

Object *Object_wx_PageSetupDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PageSetupDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PageSetupDialog:");
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
// Class implementation for wxPageSetupDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PageSetupDialog)
{
}

Gura_ImplementDescendantCreator(wx_PageSetupDialog)
{
	return new Object_wx_PageSetupDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
