//----------------------------------------------------------------------------
// wxRichTextRange
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextRange
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextRange
//----------------------------------------------------------------------------
Object_wx_RichTextRange::~Object_wx_RichTextRange()
{
}

Object *Object_wx_RichTextRange::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextRange::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextRange:");
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
// Class implementation for wxRichTextRange
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextRange)
{
}

Gura_ImplementDescendantCreator(wx_RichTextRange)
{
	return new Object_wx_RichTextRange((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
