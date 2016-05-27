//----------------------------------------------------------------------------
// wxRichTextAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextAttr
//----------------------------------------------------------------------------
Object_wx_RichTextAttr::~Object_wx_RichTextAttr()
{
}

Object *Object_wx_RichTextAttr::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextAttr::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextAttr:");
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
// Class implementation for wxRichTextAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextAttr)
{
}

Gura_ImplementDescendantCreator(wx_RichTextAttr)
{
	return new Object_wx_RichTextAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
