//----------------------------------------------------------------------------
// wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------
Object_wx_HtmlWordWithTabsCell::~Object_wx_HtmlWordWithTabsCell()
{
}

Object *Object_wx_HtmlWordWithTabsCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWordWithTabsCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWordWithTabsCell:");
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
// Class implementation for wxHtmlWordWithTabsCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWordWithTabsCell)
{
}

Gura_ImplementDescendantCreator(wx_HtmlWordWithTabsCell)
{
	return new Object_wx_HtmlWordWithTabsCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
