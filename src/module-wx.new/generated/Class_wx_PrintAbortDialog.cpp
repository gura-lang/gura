//----------------------------------------------------------------------------
// wxPrintAbortDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintAbortDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintAbortDialog
//----------------------------------------------------------------------------
Object_wx_PrintAbortDialog::~Object_wx_PrintAbortDialog()
{
}

Object *Object_wx_PrintAbortDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PrintAbortDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PrintAbortDialog:");
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
// Class implementation for wxPrintAbortDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintAbortDialog)
{
}

Gura_ImplementDescendantCreator(wx_PrintAbortDialog)
{
	return new Object_wx_PrintAbortDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
