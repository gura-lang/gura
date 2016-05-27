//----------------------------------------------------------------------------
// wxRichTextPrintout
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPrintout
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPrintout
//----------------------------------------------------------------------------
Object_wx_RichTextPrintout::~Object_wx_RichTextPrintout()
{
}

Object *Object_wx_RichTextPrintout::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextPrintout::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextPrintout:");
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
// Class implementation for wxRichTextPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPrintout)
{
}

Gura_ImplementDescendantCreator(wx_RichTextPrintout)
{
	return new Object_wx_RichTextPrintout((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
