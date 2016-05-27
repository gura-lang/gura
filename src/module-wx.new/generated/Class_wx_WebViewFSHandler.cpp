//----------------------------------------------------------------------------
// wxWebViewFSHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewFSHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewFSHandler
//----------------------------------------------------------------------------
Object_wx_WebViewFSHandler::~Object_wx_WebViewFSHandler()
{
}

Object *Object_wx_WebViewFSHandler::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewFSHandler::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewFSHandler:");
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
// Class implementation for wxWebViewFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewFSHandler)
{
}

Gura_ImplementDescendantCreator(wx_WebViewFSHandler)
{
	return new Object_wx_WebViewFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
