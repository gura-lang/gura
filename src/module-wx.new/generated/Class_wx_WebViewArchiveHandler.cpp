//----------------------------------------------------------------------------
// wxWebViewArchiveHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewArchiveHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewArchiveHandler
//----------------------------------------------------------------------------
Object_wx_WebViewArchiveHandler::~Object_wx_WebViewArchiveHandler()
{
}

Object *Object_wx_WebViewArchiveHandler::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewArchiveHandler::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewArchiveHandler:");
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
// Class implementation for wxWebViewArchiveHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewArchiveHandler)
{
}

Gura_ImplementDescendantCreator(wx_WebViewArchiveHandler)
{
	return new Object_wx_WebViewArchiveHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
