//----------------------------------------------------------------------------
// wxWebViewHistoryItem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebViewHistoryItem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebViewHistoryItem
//----------------------------------------------------------------------------
Object_wx_WebViewHistoryItem::~Object_wx_WebViewHistoryItem()
{
}

Object *Object_wx_WebViewHistoryItem::Clone() const
{
	return nullptr;
}

String Object_wx_WebViewHistoryItem::ToString(bool exprFlag)
{
	String rtn("<wx.WebViewHistoryItem:");
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
// Class implementation for wxWebViewHistoryItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewHistoryItem)
{
}

Gura_ImplementDescendantCreator(wx_WebViewHistoryItem)
{
	return new Object_wx_WebViewHistoryItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
