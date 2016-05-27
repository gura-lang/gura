//----------------------------------------------------------------------------
// wxMultiChoiceDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMultiChoiceDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMultiChoiceDialog
//----------------------------------------------------------------------------
Object_wx_MultiChoiceDialog::~Object_wx_MultiChoiceDialog()
{
}

Object *Object_wx_MultiChoiceDialog::Clone() const
{
	return nullptr;
}

String Object_wx_MultiChoiceDialog::ToString(bool exprFlag)
{
	String rtn("<wx.MultiChoiceDialog:");
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
// Class implementation for wxMultiChoiceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MultiChoiceDialog)
{
}

Gura_ImplementDescendantCreator(wx_MultiChoiceDialog)
{
	return new Object_wx_MultiChoiceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
