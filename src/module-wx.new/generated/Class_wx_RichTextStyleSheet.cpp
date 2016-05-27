//----------------------------------------------------------------------------
// wxRichTextStyleSheet
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleSheet
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleSheet
//----------------------------------------------------------------------------
Object_wx_RichTextStyleSheet::~Object_wx_RichTextStyleSheet()
{
}

Object *Object_wx_RichTextStyleSheet::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleSheet::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleSheet:");
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
// Class implementation for wxRichTextStyleSheet
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleSheet)
{
}

Gura_ImplementDescendantCreator(wx_RichTextStyleSheet)
{
	return new Object_wx_RichTextStyleSheet((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
