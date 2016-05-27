//----------------------------------------------------------------------------
// wxHtmlWinTagHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWinTagHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWinTagHandler
//----------------------------------------------------------------------------
Object_wx_HtmlWinTagHandler::~Object_wx_HtmlWinTagHandler()
{
}

Object *Object_wx_HtmlWinTagHandler::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWinTagHandler::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWinTagHandler:");
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
// Class implementation for wxHtmlWinTagHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWinTagHandler)
{
}

Gura_ImplementDescendantCreator(wx_HtmlWinTagHandler)
{
	return new Object_wx_HtmlWinTagHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
