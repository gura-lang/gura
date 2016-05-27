//----------------------------------------------------------------------------
// wxSymbolPickerDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSymbolPickerDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Object_wx_SymbolPickerDialog::~Object_wx_SymbolPickerDialog()
{
}

Object *Object_wx_SymbolPickerDialog::Clone() const
{
	return nullptr;
}

String Object_wx_SymbolPickerDialog::ToString(bool exprFlag)
{
	String rtn("<wx.SymbolPickerDialog:");
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
// Class implementation for wxSymbolPickerDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SymbolPickerDialog)
{
}

Gura_ImplementDescendantCreator(wx_SymbolPickerDialog)
{
	return new Object_wx_SymbolPickerDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
