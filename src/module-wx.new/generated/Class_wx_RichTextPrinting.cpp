//----------------------------------------------------------------------------
// wxRichTextPrinting
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPrinting
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPrinting
//----------------------------------------------------------------------------
Object_wx_RichTextPrinting::~Object_wx_RichTextPrinting()
{
}

Object *Object_wx_RichTextPrinting::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextPrinting::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextPrinting:");
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
// Class implementation for wxRichTextPrinting
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPrinting)
{
}

Gura_ImplementDescendantCreator(wx_RichTextPrinting)
{
	return new Object_wx_RichTextPrinting((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
