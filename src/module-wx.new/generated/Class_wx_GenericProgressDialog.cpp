//----------------------------------------------------------------------------
// wxGenericProgressDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGenericProgressDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGenericProgressDialog
//----------------------------------------------------------------------------
Object_wx_GenericProgressDialog::~Object_wx_GenericProgressDialog()
{
}

Object *Object_wx_GenericProgressDialog::Clone() const
{
	return nullptr;
}

String Object_wx_GenericProgressDialog::ToString(bool exprFlag)
{
	String rtn("<wx.GenericProgressDialog:");
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
// Class implementation for wxGenericProgressDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GenericProgressDialog)
{
}

Gura_ImplementDescendantCreator(wx_GenericProgressDialog)
{
	return new Object_wx_GenericProgressDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
