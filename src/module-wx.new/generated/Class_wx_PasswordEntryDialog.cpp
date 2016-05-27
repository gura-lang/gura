//----------------------------------------------------------------------------
// wxPasswordEntryDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPasswordEntryDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPasswordEntryDialog
//----------------------------------------------------------------------------
Object_wx_PasswordEntryDialog::~Object_wx_PasswordEntryDialog()
{
}

Object *Object_wx_PasswordEntryDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PasswordEntryDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PasswordEntryDialog:");
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
// Class implementation for wxPasswordEntryDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PasswordEntryDialog)
{
}

Gura_ImplementDescendantCreator(wx_PasswordEntryDialog)
{
	return new Object_wx_PasswordEntryDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
