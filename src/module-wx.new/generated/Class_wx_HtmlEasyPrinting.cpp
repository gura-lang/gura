//----------------------------------------------------------------------------
// wxHtmlEasyPrinting
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlEasyPrinting
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlEasyPrinting
//----------------------------------------------------------------------------
Object_wx_HtmlEasyPrinting::~Object_wx_HtmlEasyPrinting()
{
}

Object *Object_wx_HtmlEasyPrinting::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlEasyPrinting::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlEasyPrinting:");
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
// Class implementation for wxHtmlEasyPrinting
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlEasyPrinting)
{
}

Gura_ImplementDescendantCreator(wx_HtmlEasyPrinting)
{
	return new Object_wx_HtmlEasyPrinting((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
