//----------------------------------------------------------------------------
// wxRichTextParagraph
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextParagraph
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextParagraph
//----------------------------------------------------------------------------
Object_wx_RichTextParagraph::~Object_wx_RichTextParagraph()
{
}

Object *Object_wx_RichTextParagraph::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextParagraph::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextParagraph:");
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
// Class implementation for wxRichTextParagraph
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextParagraph)
{
}

Gura_ImplementDescendantCreator(wx_RichTextParagraph)
{
	return new Object_wx_RichTextParagraph((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
