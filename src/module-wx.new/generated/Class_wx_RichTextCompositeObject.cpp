//----------------------------------------------------------------------------
// wxRichTextCompositeObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCompositeObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCompositeObject
//----------------------------------------------------------------------------
Object_wx_RichTextCompositeObject::~Object_wx_RichTextCompositeObject()
{
}

Object *Object_wx_RichTextCompositeObject::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextCompositeObject::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCompositeObject:");
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
// Class implementation for wxRichTextCompositeObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCompositeObject)
{
}

Gura_ImplementDescendantCreator(wx_RichTextCompositeObject)
{
	return new Object_wx_RichTextCompositeObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
