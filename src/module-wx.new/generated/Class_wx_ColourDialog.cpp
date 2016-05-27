//----------------------------------------------------------------------------
// wxColourDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxColourDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxColourDialog
//----------------------------------------------------------------------------
Object_wx_ColourDialog::~Object_wx_ColourDialog()
{
}

Object *Object_wx_ColourDialog::Clone() const
{
	return nullptr;
}

String Object_wx_ColourDialog::ToString(bool exprFlag)
{
	String rtn("<wx.ColourDialog:");
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
// Class implementation for wxColourDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourDialog)
{
}

Gura_ImplementDescendantCreator(wx_ColourDialog)
{
	return new Object_wx_ColourDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
