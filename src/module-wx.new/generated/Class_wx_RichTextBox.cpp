//----------------------------------------------------------------------------
// wxRichTextBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextBox
//----------------------------------------------------------------------------
Object_wx_RichTextBox::~Object_wx_RichTextBox()
{
}

Object *Object_wx_RichTextBox::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextBox::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextBox:");
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
// Class implementation for wxRichTextBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextBox)
{
}

Gura_ImplementDescendantCreator(wx_RichTextBox)
{
	return new Object_wx_RichTextBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
