//----------------------------------------------------------------------------
// wxHtmlRenderingState
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlRenderingState
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlRenderingState
//----------------------------------------------------------------------------
Object_wx_HtmlRenderingState::~Object_wx_HtmlRenderingState()
{
}

Object *Object_wx_HtmlRenderingState::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlRenderingState::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlRenderingState:");
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
// Class implementation for wxHtmlRenderingState
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlRenderingState)
{
}

Gura_ImplementDescendantCreator(wx_HtmlRenderingState)
{
	return new Object_wx_HtmlRenderingState((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
