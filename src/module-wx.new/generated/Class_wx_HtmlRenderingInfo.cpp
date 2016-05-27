//----------------------------------------------------------------------------
// wxHtmlRenderingInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlRenderingInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlRenderingInfo
//----------------------------------------------------------------------------
Object_wx_HtmlRenderingInfo::~Object_wx_HtmlRenderingInfo()
{
}

Object *Object_wx_HtmlRenderingInfo::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlRenderingInfo::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlRenderingInfo:");
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
// Class implementation for wxHtmlRenderingInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlRenderingInfo)
{
}

Gura_ImplementDescendantCreator(wx_HtmlRenderingInfo)
{
	return new Object_wx_HtmlRenderingInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
