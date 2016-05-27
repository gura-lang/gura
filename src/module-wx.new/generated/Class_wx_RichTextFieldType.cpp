//----------------------------------------------------------------------------
// wxRichTextFieldType
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFieldType
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFieldType
//----------------------------------------------------------------------------
Object_wx_RichTextFieldType::~Object_wx_RichTextFieldType()
{
}

Object *Object_wx_RichTextFieldType::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFieldType::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFieldType:");
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
// Class implementation for wxRichTextFieldType
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFieldType)
{
}

Gura_ImplementDescendantCreator(wx_RichTextFieldType)
{
	return new Object_wx_RichTextFieldType((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
