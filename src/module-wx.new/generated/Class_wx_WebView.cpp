//----------------------------------------------------------------------------
// wxWebView
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebView
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebView
//----------------------------------------------------------------------------
Object_wx_WebView::~Object_wx_WebView()
{
}

Object *Object_wx_WebView::Clone() const
{
	return nullptr;
}

String Object_wx_WebView::ToString(bool exprFlag)
{
	String rtn("<wx.WebView:");
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
// Class implementation for wxWebView
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebView)
{
}

Gura_ImplementDescendantCreator(wx_WebView)
{
	return new Object_wx_WebView((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
