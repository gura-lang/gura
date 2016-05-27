//----------------------------------------------------------------------------
// wxRichTextStyleListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleListBox
//----------------------------------------------------------------------------
Object_wx_RichTextStyleListBox::~Object_wx_RichTextStyleListBox()
{
}

Object *Object_wx_RichTextStyleListBox::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleListBox::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleListBox:");
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
// Class implementation for wxRichTextStyleListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleListBox)
{
}

Gura_ImplementDescendantCreator(wx_RichTextStyleListBox)
{
	return new Object_wx_RichTextStyleListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
