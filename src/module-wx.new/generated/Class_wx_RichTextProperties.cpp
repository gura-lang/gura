//----------------------------------------------------------------------------
// wxRichTextProperties
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextProperties
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextProperties
//----------------------------------------------------------------------------
Object_wx_RichTextProperties::~Object_wx_RichTextProperties()
{
}

Object *Object_wx_RichTextProperties::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextProperties::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextProperties:");
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
// Class implementation for wxRichTextProperties
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextProperties)
{
}

Gura_ImplementDescendantCreator(wx_RichTextProperties)
{
	return new Object_wx_RichTextProperties((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
