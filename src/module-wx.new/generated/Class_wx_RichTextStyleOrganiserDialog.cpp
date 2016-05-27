//----------------------------------------------------------------------------
// wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
Object_wx_RichTextStyleOrganiserDialog::~Object_wx_RichTextStyleOrganiserDialog()
{
}

Object *Object_wx_RichTextStyleOrganiserDialog::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleOrganiserDialog::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleOrganiserDialog:");
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
// Class implementation for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleOrganiserDialog)
{
}

Gura_ImplementDescendantCreator(wx_RichTextStyleOrganiserDialog)
{
	return new Object_wx_RichTextStyleOrganiserDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
