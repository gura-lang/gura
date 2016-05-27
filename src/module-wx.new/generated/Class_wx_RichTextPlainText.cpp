//----------------------------------------------------------------------------
// wxRichTextPlainText
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPlainText
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPlainText
//----------------------------------------------------------------------------
Object_wx_RichTextPlainText::~Object_wx_RichTextPlainText()
{
}

Object *Object_wx_RichTextPlainText::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextPlainText::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextPlainText:");
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
// Class implementation for wxRichTextPlainText
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPlainText)
{
}

Gura_ImplementDescendantCreator(wx_RichTextPlainText)
{
	return new Object_wx_RichTextPlainText((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
