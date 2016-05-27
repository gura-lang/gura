//----------------------------------------------------------------------------
// wxHtmlRenderingStyle
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlRenderingStyle
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlRenderingStyle
//----------------------------------------------------------------------------
Object_wx_HtmlRenderingStyle::~Object_wx_HtmlRenderingStyle()
{
}

Object *Object_wx_HtmlRenderingStyle::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlRenderingStyle::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlRenderingStyle:");
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
// Class implementation for wxHtmlRenderingStyle
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlRenderingStyle)
{
}

Gura_ImplementDescendantCreator(wx_HtmlRenderingStyle)
{
	return new Object_wx_HtmlRenderingStyle((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
