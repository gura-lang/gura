//----------------------------------------------------------------------------
// wxRichTextObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextObject
//----------------------------------------------------------------------------
Object_wx_RichTextObject::~Object_wx_RichTextObject()
{
}

Object *Object_wx_RichTextObject::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextObject::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextObject:");
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
// Class implementation for wxRichTextObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextObject)
{
}

Gura_ImplementDescendantCreator(wx_RichTextObject)
{
	return new Object_wx_RichTextObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
