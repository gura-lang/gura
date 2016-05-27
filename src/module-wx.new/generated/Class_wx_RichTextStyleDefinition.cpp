//----------------------------------------------------------------------------
// wxRichTextStyleDefinition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleDefinition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextStyleDefinition::~Object_wx_RichTextStyleDefinition()
{
}

Object *Object_wx_RichTextStyleDefinition::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleDefinition:");
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
// Class implementation for wxRichTextStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleDefinition)
{
}

Gura_ImplementDescendantCreator(wx_RichTextStyleDefinition)
{
	return new Object_wx_RichTextStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
