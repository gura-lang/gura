//----------------------------------------------------------------------------
// wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Object_wx_RichTextListStyleDefinition::~Object_wx_RichTextListStyleDefinition()
{
}

Object *Object_wx_RichTextListStyleDefinition::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextListStyleDefinition::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextListStyleDefinition:");
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
// Class implementation for wxRichTextListStyleDefinition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextListStyleDefinition)
{
}

Gura_ImplementDescendantCreator(wx_RichTextListStyleDefinition)
{
	return new Object_wx_RichTextListStyleDefinition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
