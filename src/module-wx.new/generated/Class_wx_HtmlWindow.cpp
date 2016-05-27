//----------------------------------------------------------------------------
// wxHtmlWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWindow
//----------------------------------------------------------------------------
Object_wx_HtmlWindow::~Object_wx_HtmlWindow()
{
}

Object *Object_wx_HtmlWindow::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWindow::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWindow:");
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
// Class implementation for wxHtmlWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWindow)
{
}

Gura_ImplementDescendantCreator(wx_HtmlWindow)
{
	return new Object_wx_HtmlWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
