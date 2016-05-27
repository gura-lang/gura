//----------------------------------------------------------------------------
// wxHtmlTag
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTag
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTag
//----------------------------------------------------------------------------
Object_wx_HtmlTag::~Object_wx_HtmlTag()
{
}

Object *Object_wx_HtmlTag::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlTag::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTag:");
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
// Class implementation for wxHtmlTag
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTag)
{
}

Gura_ImplementDescendantCreator(wx_HtmlTag)
{
	return new Object_wx_HtmlTag((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
