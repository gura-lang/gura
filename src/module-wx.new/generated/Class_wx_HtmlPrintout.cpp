//----------------------------------------------------------------------------
// wxHtmlPrintout
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlPrintout
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlPrintout
//----------------------------------------------------------------------------
Object_wx_HtmlPrintout::~Object_wx_HtmlPrintout()
{
}

Object *Object_wx_HtmlPrintout::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlPrintout::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlPrintout:");
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
// Class implementation for wxHtmlPrintout
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlPrintout)
{
}

Gura_ImplementDescendantCreator(wx_HtmlPrintout)
{
	return new Object_wx_HtmlPrintout((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
