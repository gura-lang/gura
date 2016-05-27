//----------------------------------------------------------------------------
// wxHtmlFontCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlFontCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlFontCell
//----------------------------------------------------------------------------
Object_wx_HtmlFontCell::~Object_wx_HtmlFontCell()
{
}

Object *Object_wx_HtmlFontCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlFontCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlFontCell:");
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
// Class implementation for wxHtmlFontCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlFontCell)
{
}

Gura_ImplementDescendantCreator(wx_HtmlFontCell)
{
	return new Object_wx_HtmlFontCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
