//----------------------------------------------------------------------------
// wxRichTextLine
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextLine
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextLine
//----------------------------------------------------------------------------
Object_wx_RichTextLine::~Object_wx_RichTextLine()
{
}

Object *Object_wx_RichTextLine::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextLine::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextLine:");
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
// Class implementation for wxRichTextLine
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextLine)
{
}

Gura_ImplementDescendantCreator(wx_RichTextLine)
{
	return new Object_wx_RichTextLine((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
