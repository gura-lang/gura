//----------------------------------------------------------------------------
// wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
Object_wx_RichTextParagraphLayoutBox::~Object_wx_RichTextParagraphLayoutBox()
{
}

Object *Object_wx_RichTextParagraphLayoutBox::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextParagraphLayoutBox::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextParagraphLayoutBox:");
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
// Class implementation for wxRichTextParagraphLayoutBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextParagraphLayoutBox)
{
}

Gura_ImplementDescendantCreator(wx_RichTextParagraphLayoutBox)
{
	return new Object_wx_RichTextParagraphLayoutBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
