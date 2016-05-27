//----------------------------------------------------------------------------
// wxFindReplaceDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFindReplaceDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFindReplaceDialog
//----------------------------------------------------------------------------
Object_wx_FindReplaceDialog::~Object_wx_FindReplaceDialog()
{
}

Object *Object_wx_FindReplaceDialog::Clone() const
{
	return nullptr;
}

String Object_wx_FindReplaceDialog::ToString(bool exprFlag)
{
	String rtn("<wx.FindReplaceDialog:");
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
// Class implementation for wxFindReplaceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindReplaceDialog)
{
}

Gura_ImplementDescendantCreator(wx_FindReplaceDialog)
{
	return new Object_wx_FindReplaceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
