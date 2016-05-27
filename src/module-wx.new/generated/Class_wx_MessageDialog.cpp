//----------------------------------------------------------------------------
// wxMessageDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageDialog
//----------------------------------------------------------------------------
Object_wx_MessageDialog::~Object_wx_MessageDialog()
{
}

Object *Object_wx_MessageDialog::Clone() const
{
	return nullptr;
}

String Object_wx_MessageDialog::ToString(bool exprFlag)
{
	String rtn("<wx.MessageDialog:");
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
// Class implementation for wxMessageDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageDialog)
{
}

Gura_ImplementDescendantCreator(wx_MessageDialog)
{
	return new Object_wx_MessageDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
