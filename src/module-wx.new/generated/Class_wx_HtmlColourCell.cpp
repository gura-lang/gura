//----------------------------------------------------------------------------
// wxHtmlColourCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlColourCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlColourCell
//----------------------------------------------------------------------------
Object_wx_HtmlColourCell::~Object_wx_HtmlColourCell()
{
}

Object *Object_wx_HtmlColourCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlColourCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlColourCell:");
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
// Class implementation for wxHtmlColourCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlColourCell)
{
}

Gura_ImplementDescendantCreator(wx_HtmlColourCell)
{
	return new Object_wx_HtmlColourCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
