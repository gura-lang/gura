//----------------------------------------------------------------------------
// wxRichTextImage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextImage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextImage
//----------------------------------------------------------------------------
Object_wx_RichTextImage::~Object_wx_RichTextImage()
{
}

Object *Object_wx_RichTextImage::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextImage::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextImage:");
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
// Class implementation for wxRichTextImage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextImage)
{
}

Gura_ImplementDescendantCreator(wx_RichTextImage)
{
	return new Object_wx_RichTextImage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
