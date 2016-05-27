//----------------------------------------------------------------------------
// wxGenericAboutDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGenericAboutDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGenericAboutDialog
//----------------------------------------------------------------------------
Object_wx_GenericAboutDialog::~Object_wx_GenericAboutDialog()
{
}

Object *Object_wx_GenericAboutDialog::Clone() const
{
	return nullptr;
}

String Object_wx_GenericAboutDialog::ToString(bool exprFlag)
{
	String rtn("<wx.GenericAboutDialog:");
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
// Class implementation for wxGenericAboutDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GenericAboutDialog)
{
}

Gura_ImplementDescendantCreator(wx_GenericAboutDialog)
{
	return new Object_wx_GenericAboutDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
