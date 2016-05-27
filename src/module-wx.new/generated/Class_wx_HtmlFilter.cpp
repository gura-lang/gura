//----------------------------------------------------------------------------
// wxHtmlFilter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlFilter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlFilter
//----------------------------------------------------------------------------
Object_wx_HtmlFilter::~Object_wx_HtmlFilter()
{
}

Object *Object_wx_HtmlFilter::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlFilter::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlFilter:");
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
// Class implementation for wxHtmlFilter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlFilter)
{
}

Gura_ImplementDescendantCreator(wx_HtmlFilter)
{
	return new Object_wx_HtmlFilter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
