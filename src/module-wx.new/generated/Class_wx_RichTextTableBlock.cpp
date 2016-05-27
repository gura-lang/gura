//----------------------------------------------------------------------------
// wxRichTextTableBlock
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextTableBlock
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextTableBlock
//----------------------------------------------------------------------------
Object_wx_RichTextTableBlock::~Object_wx_RichTextTableBlock()
{
}

Object *Object_wx_RichTextTableBlock::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextTableBlock::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextTableBlock:");
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
// Class implementation for wxRichTextTableBlock
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextTableBlock)
{
}

Gura_ImplementDescendantCreator(wx_RichTextTableBlock)
{
	return new Object_wx_RichTextTableBlock((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
