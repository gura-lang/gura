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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__WebViewHistoryItem, "WebViewHistoryItem")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WebViewHistoryItem));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__WebViewHistoryItem)
{
	//int url = arg.GetNumber(0)
	//int title = arg.GetNumber(1)
	//wxWebViewHistoryItem();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WebViewHistoryItem, __GetUrl, "GetUrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebViewHistoryItem, __GetUrl)
{
	Object_wx_WebViewHistoryItem *pThis = Object_wx_WebViewHistoryItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebViewHistoryItem, __GetTitle, "GetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebViewHistoryItem, __GetTitle)
{
	Object_wx_WebViewHistoryItem *pThis = Object_wx_WebViewHistoryItem::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebViewHistoryItem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebViewHistoryItem)
{
	// Constructor assignment
	Gura_AssignFunction(__WebViewHistoryItem);
	// Method assignment
	Gura_AssignMethod(wx_WebViewHistoryItem, __GetUrl);
	Gura_AssignMethod(wx_WebViewHistoryItem, __GetTitle);
}

Gura_ImplementDescendantCreator(wx_WebViewHistoryItem)
{
	return new Object_wx_WebViewHistoryItem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
