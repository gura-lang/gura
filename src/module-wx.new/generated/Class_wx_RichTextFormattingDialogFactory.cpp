//----------------------------------------------------------------------------
// wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------
Object_wx_RichTextFormattingDialogFactory::~Object_wx_RichTextFormattingDialogFactory()
{
}

Object *Object_wx_RichTextFormattingDialogFactory::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFormattingDialogFactory::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFormattingDialogFactory:");
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
// Class implementation for wxRichTextFormattingDialogFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFormattingDialogFactory)
{
}

Gura_ImplementDescendantCreator(wx_RichTextFormattingDialogFactory)
{
	return new Object_wx_RichTextFormattingDialogFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
