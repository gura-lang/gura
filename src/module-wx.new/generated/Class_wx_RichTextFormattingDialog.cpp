//----------------------------------------------------------------------------
// wxRichTextFormattingDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFormattingDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFormattingDialog
//----------------------------------------------------------------------------
Object_wx_RichTextFormattingDialog::~Object_wx_RichTextFormattingDialog()
{
}

Object *Object_wx_RichTextFormattingDialog::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFormattingDialog::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFormattingDialog:");
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
// Class implementation for wxRichTextFormattingDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFormattingDialog)
{
}

Gura_ImplementDescendantCreator(wx_RichTextFormattingDialog)
{
	return new Object_wx_RichTextFormattingDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
