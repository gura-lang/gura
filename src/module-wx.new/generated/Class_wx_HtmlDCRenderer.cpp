//----------------------------------------------------------------------------
// wxHtmlDCRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlDCRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Object_wx_HtmlDCRenderer::~Object_wx_HtmlDCRenderer()
{
}

Object *Object_wx_HtmlDCRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlDCRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlDCRenderer:");
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
// Class implementation for wxHtmlDCRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlDCRenderer)
{
}

Gura_ImplementDescendantCreator(wx_HtmlDCRenderer)
{
	return new Object_wx_HtmlDCRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
