//----------------------------------------------------------------------------
// wxHtmlParser
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlParser
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlParser
//----------------------------------------------------------------------------
Object_wx_HtmlParser::~Object_wx_HtmlParser()
{
}

Object *Object_wx_HtmlParser::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlParser::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlParser:");
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
// Class implementation for wxHtmlParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlParser)
{
}

Gura_ImplementDescendantCreator(wx_HtmlParser)
{
	return new Object_wx_HtmlParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
