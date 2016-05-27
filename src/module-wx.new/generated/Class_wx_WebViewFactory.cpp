//----------------------------------------------------------------------------
// wxWebViewFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewFactory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewFactory
//----------------------------------------------------------------------------
Object_wx_WebViewFactory::~Object_wx_WebViewFactory()
{
}

Object *Object_wx_WebViewFactory::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewFactory::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewFactory:");
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
// Class implementation for wxWebViewFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewFactory)
{
}

Gura_ImplementDescendantCreator(wx_WebViewFactory)
{
	return new Object_wx_WebViewFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
