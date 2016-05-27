//----------------------------------------------------------------------------
// wxRichTextImageBlock
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextImageBlock
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextImageBlock
//----------------------------------------------------------------------------
Object_wx_RichTextImageBlock::~Object_wx_RichTextImageBlock()
{
}

Object *Object_wx_RichTextImageBlock::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextImageBlock::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextImageBlock:");
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
// Class implementation for wxRichTextImageBlock
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextImageBlock)
{
}

Gura_ImplementDescendantCreator(wx_RichTextImageBlock)
{
	return new Object_wx_RichTextImageBlock((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
