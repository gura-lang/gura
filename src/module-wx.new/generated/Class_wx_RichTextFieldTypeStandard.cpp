//----------------------------------------------------------------------------
// wxRichTextFieldTypeStandard
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFieldTypeStandard
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFieldTypeStandard
//----------------------------------------------------------------------------
Object_wx_RichTextFieldTypeStandard::~Object_wx_RichTextFieldTypeStandard()
{
}

Object *Object_wx_RichTextFieldTypeStandard::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFieldTypeStandard::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFieldTypeStandard:");
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
// Class implementation for wxRichTextFieldTypeStandard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFieldTypeStandard)
{
	
}

Gura_ImplementDescendantCreator(wx_RichTextFieldTypeStandard)
{
	return new Object_wx_RichTextFieldTypeStandard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
