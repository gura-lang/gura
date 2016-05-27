//----------------------------------------------------------------------------
// wxWebViewHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewHandler
//----------------------------------------------------------------------------
Object_wx_WebViewHandler::~Object_wx_WebViewHandler()
{
}

Object *Object_wx_WebViewHandler::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewHandler::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewHandler:");
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
// Class implementation for wxWebViewHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewHandler)
{
}

Gura_ImplementDescendantCreator(wx_WebViewHandler)
{
	return new Object_wx_WebViewHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
