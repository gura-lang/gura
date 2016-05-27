//----------------------------------------------------------------------------
// wxRichTextCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCell
//----------------------------------------------------------------------------
Object_wx_RichTextCell::~Object_wx_RichTextCell()
{
}

Object *Object_wx_RichTextCell::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextCell::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCell:");
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
// Class implementation for wxRichTextCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCell)
{
}

Gura_ImplementDescendantCreator(wx_RichTextCell)
{
	return new Object_wx_RichTextCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
