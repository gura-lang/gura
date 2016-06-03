//----------------------------------------------------------------------------
// wxWebKitCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWebKitCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWebKitCtrl
//----------------------------------------------------------------------------
Object_wx_WebKitCtrl::~Object_wx_WebKitCtrl()
{
}

Object *Object_wx_WebKitCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_WebKitCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.WebKitCtrl:");
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
Gura_DeclareFunctionAlias(__wxWebKitCtrl, "wxWebKitCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_WebKitCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWebKitCtrl)
{
	//wxWebKitCtrl();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxWebKitCtrl_1, "wxWebKitCtrl_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strURL", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_WebKitCtrl));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxWebKitCtrl_1)
{
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int strURL = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//wxWebKitCtrl();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_WebKitCtrl, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "strURL", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, __Create)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int strURL = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __LoadURL, "LoadURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, __LoadURL)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->LoadURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __CanGoBack, "CanGoBack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __CanGoBack)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanGoBack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __CanGoForward, "CanGoForward")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __CanGoForward)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanGoForward();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __GoBack, "GoBack")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __GoBack)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GoBack();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __GoForward, "GoForward")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __GoForward)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GoForward();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __Reload, "Reload")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __Reload)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Reload();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __Stop, "Stop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __Stop)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __CanGetPageSource, "CanGetPageSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __CanGetPageSource)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanGetPageSource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __GetPageSource, "GetPageSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __GetPageSource)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __SetPageSource, "SetPageSource")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseUrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, __SetPageSource)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int source = arg.GetNumber(0)
	//int baseUrl = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageSource();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __GetPageURL, "GetPageURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __GetPageURL)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageURL();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __SetPageTitle, "SetPageTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, __SetPageTitle)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetPageTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __GetPageTitle, "GetPageTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __GetPageTitle)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __SetTitle, "SetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, __SetTitle)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __GetTitle, "GetTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __GetTitle)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __GetSelection)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __CanIncreaseTextSize, "CanIncreaseTextSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __CanIncreaseTextSize)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanIncreaseTextSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __IncreaseTextSize, "IncreaseTextSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __IncreaseTextSize)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IncreaseTextSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __CanDecreaseTextSize, "CanDecreaseTextSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __CanDecreaseTextSize)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanDecreaseTextSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __DecreaseTextSize, "DecreaseTextSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __DecreaseTextSize)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DecreaseTextSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __Print, "Print")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showPrompt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, __Print)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int showPrompt = arg.GetNumber(0)
	//pThis->GetEntity()->Print();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __MakeEditable, "MakeEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, __MakeEditable)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->MakeEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __IsEditable, "IsEditable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __IsEditable)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEditable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __RunScript, "RunScript")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "javascript", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, __RunScript)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int javascript = arg.GetNumber(0)
	//pThis->GetEntity()->RunScript();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __SetScrollPos, "SetScrollPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, __SetScrollPos)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetScrollPos();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_WebKitCtrl, __GetScrollPos, "GetScrollPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, __GetScrollPos)
{
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetScrollPos();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebKitCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitCtrl)
{
	// Constructor assignment
	Gura_AssignFunction(__wxWebKitCtrl);
	Gura_AssignFunction(__wxWebKitCtrl_1);
	// Method assignment
	Gura_AssignMethod(wx_WebKitCtrl, __Create);
	Gura_AssignMethod(wx_WebKitCtrl, __LoadURL);
	Gura_AssignMethod(wx_WebKitCtrl, __CanGoBack);
	Gura_AssignMethod(wx_WebKitCtrl, __CanGoForward);
	Gura_AssignMethod(wx_WebKitCtrl, __GoBack);
	Gura_AssignMethod(wx_WebKitCtrl, __GoForward);
	Gura_AssignMethod(wx_WebKitCtrl, __Reload);
	Gura_AssignMethod(wx_WebKitCtrl, __Stop);
	Gura_AssignMethod(wx_WebKitCtrl, __CanGetPageSource);
	Gura_AssignMethod(wx_WebKitCtrl, __GetPageSource);
	Gura_AssignMethod(wx_WebKitCtrl, __SetPageSource);
	Gura_AssignMethod(wx_WebKitCtrl, __GetPageURL);
	Gura_AssignMethod(wx_WebKitCtrl, __SetPageTitle);
	Gura_AssignMethod(wx_WebKitCtrl, __GetPageTitle);
	Gura_AssignMethod(wx_WebKitCtrl, __SetTitle);
	Gura_AssignMethod(wx_WebKitCtrl, __GetTitle);
	Gura_AssignMethod(wx_WebKitCtrl, __GetSelection);
	Gura_AssignMethod(wx_WebKitCtrl, __CanIncreaseTextSize);
	Gura_AssignMethod(wx_WebKitCtrl, __IncreaseTextSize);
	Gura_AssignMethod(wx_WebKitCtrl, __CanDecreaseTextSize);
	Gura_AssignMethod(wx_WebKitCtrl, __DecreaseTextSize);
	Gura_AssignMethod(wx_WebKitCtrl, __Print);
	Gura_AssignMethod(wx_WebKitCtrl, __MakeEditable);
	Gura_AssignMethod(wx_WebKitCtrl, __IsEditable);
	Gura_AssignMethod(wx_WebKitCtrl, __RunScript);
	Gura_AssignMethod(wx_WebKitCtrl, __SetScrollPos);
	Gura_AssignMethod(wx_WebKitCtrl, __GetScrollPos);
}

Gura_ImplementDescendantCreator(wx_WebKitCtrl)
{
	return new Object_wx_WebKitCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
