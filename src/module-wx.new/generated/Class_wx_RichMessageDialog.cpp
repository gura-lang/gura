//----------------------------------------------------------------------------
// wxRichMessageDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichMessageDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichMessageDialog
//----------------------------------------------------------------------------
Object_wx_RichMessageDialog::~Object_wx_RichMessageDialog()
{
}

Object *Object_wx_RichMessageDialog::Clone() const
{
	return nullptr;
}

String Object_wx_RichMessageDialog::ToString(bool exprFlag)
{
	String rtn("<wx.RichMessageDialog:");
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
// Class implementation for wxRichMessageDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichMessageDialog)
{
}

Gura_ImplementDescendantCreator(wx_RichMessageDialog)
{
	return new Object_wx_RichMessageDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
