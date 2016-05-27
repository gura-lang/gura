//----------------------------------------------------------------------------
// wxHtmlWidgetCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWidgetCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Object_wx_HtmlWidgetCell::~Object_wx_HtmlWidgetCell()
{
}

Object *Object_wx_HtmlWidgetCell::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWidgetCell::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWidgetCell:");
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
// Class implementation for wxHtmlWidgetCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWidgetCell)
{
}

Gura_ImplementDescendantCreator(wx_HtmlWidgetCell)
{
	return new Object_wx_HtmlWidgetCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
