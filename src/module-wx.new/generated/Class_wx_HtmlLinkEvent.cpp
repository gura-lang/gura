//----------------------------------------------------------------------------
// wxHtmlLinkEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlLinkEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlLinkEvent
//----------------------------------------------------------------------------
Object_wx_HtmlLinkEvent::~Object_wx_HtmlLinkEvent()
{
}

Object *Object_wx_HtmlLinkEvent::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlLinkEvent::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlLinkEvent:");
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
// Class implementation for wxHtmlLinkEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlLinkEvent)
{
}

Gura_ImplementDescendantCreator(wx_HtmlLinkEvent)
{
	return new Object_wx_HtmlLinkEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
