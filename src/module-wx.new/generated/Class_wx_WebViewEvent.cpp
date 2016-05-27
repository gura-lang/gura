//----------------------------------------------------------------------------
// wxWebViewEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewEvent
//----------------------------------------------------------------------------
Object_wx_WebViewEvent::~Object_wx_WebViewEvent()
{
}

Object *Object_wx_WebViewEvent::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewEvent::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewEvent:");
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
// Class implementation for wxWebViewEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewEvent)
{
}

Gura_ImplementDescendantCreator(wx_WebViewEvent)
{
	return new Object_wx_WebViewEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
