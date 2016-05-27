//----------------------------------------------------------------------------
// wxPrintDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintDialog
//----------------------------------------------------------------------------
Object_wx_PrintDialog::~Object_wx_PrintDialog()
{
}

Object *Object_wx_PrintDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PrintDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PrintDialog:");
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
// Class implementation for wxPrintDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintDialog)
{
}

Gura_ImplementDescendantCreator(wx_PrintDialog)
{
	return new Object_wx_PrintDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
