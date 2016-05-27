//----------------------------------------------------------------------------
// wxHtmlTagHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTagHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTagHandler
//----------------------------------------------------------------------------
Object_wx_HtmlTagHandler::~Object_wx_HtmlTagHandler()
{
}

Object *Object_wx_HtmlTagHandler::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlTagHandler::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTagHandler:");
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
// Class implementation for wxHtmlTagHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTagHandler)
{
}

Gura_ImplementDescendantCreator(wx_HtmlTagHandler)
{
	return new Object_wx_HtmlTagHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
