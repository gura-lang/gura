//----------------------------------------------------------------------------
// wxHtmlWordCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWordCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWordCell
//----------------------------------------------------------------------------
Object_wx_HtmlWordCell::~Object_wx_HtmlWordCell()
{
}

Object *Object_wx_HtmlWordCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWordCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWordCell:");
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
// Class implementation for wxHtmlWordCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWordCell)
{
}

Gura_ImplementDescendantCreator(wx_HtmlWordCell)
{
	return new Object_wx_HtmlWordCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
