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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_WebKitCtrl, wxWebKitCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, wxWebKitCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxWebKitCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, wxWebKitCtrl_1)
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

Gura_ImplementMethod(wx_WebKitCtrl, wxWebKitCtrl_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int strURL = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxWebKitCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, Create)
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

Gura_ImplementMethod(wx_WebKitCtrl, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_WebKitCtrl, ~wxWebKitCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, ~wxWebKitCtrl)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxWebKitCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, LoadURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, LoadURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int url = arg.GetNumber(0)
	//pThis->GetEntity()->LoadURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, CanGoBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, CanGoBack)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanGoBack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, CanGoForward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, CanGoForward)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanGoForward();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, GoBack)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, GoBack)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GoBack();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, GoForward)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, GoForward)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GoForward();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, Reload)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, Reload)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Reload();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, Stop)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, CanGetPageSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, CanGetPageSource)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanGetPageSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, GetPageSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, GetPageSource)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, SetPageSource)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "source", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "baseUrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, SetPageSource)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int source = arg.GetNumber(0)
	//int baseUrl = arg.GetNumber(1)
	//pThis->GetEntity()->SetPageSource();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, GetPageURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, GetPageURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, SetPageTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, SetPageTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetPageTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, GetPageTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, GetPageTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, SetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, GetTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, CanIncreaseTextSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, CanIncreaseTextSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanIncreaseTextSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, IncreaseTextSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, IncreaseTextSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IncreaseTextSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, CanDecreaseTextSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, CanDecreaseTextSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanDecreaseTextSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, DecreaseTextSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, DecreaseTextSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DecreaseTextSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, Print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "showPrompt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, Print)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int showPrompt = arg.GetNumber(0)
	//pThis->GetEntity()->Print();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, MakeEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, MakeEditable)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->MakeEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, IsEditable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, IsEditable)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsEditable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, RunScript)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "javascript", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, RunScript)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int javascript = arg.GetNumber(0)
	//pThis->GetEntity()->RunScript();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, SetScrollPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_WebKitCtrl, SetScrollPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetScrollPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_WebKitCtrl, GetScrollPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_WebKitCtrl, GetScrollPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_WebKitCtrl *pThis = Object_wx_WebKitCtrl::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetScrollPos();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWebKitCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_WebKitCtrl)
{
	Gura_AssignMethod(wx_WebKitCtrl, wxWebKitCtrl);
	Gura_AssignMethod(wx_WebKitCtrl, wxWebKitCtrl_1);
	Gura_AssignMethod(wx_WebKitCtrl, Create);
	Gura_AssignMethod(wx_WebKitCtrl, ~wxWebKitCtrl);
	Gura_AssignMethod(wx_WebKitCtrl, LoadURL);
	Gura_AssignMethod(wx_WebKitCtrl, CanGoBack);
	Gura_AssignMethod(wx_WebKitCtrl, CanGoForward);
	Gura_AssignMethod(wx_WebKitCtrl, GoBack);
	Gura_AssignMethod(wx_WebKitCtrl, GoForward);
	Gura_AssignMethod(wx_WebKitCtrl, Reload);
	Gura_AssignMethod(wx_WebKitCtrl, Stop);
	Gura_AssignMethod(wx_WebKitCtrl, CanGetPageSource);
	Gura_AssignMethod(wx_WebKitCtrl, GetPageSource);
	Gura_AssignMethod(wx_WebKitCtrl, SetPageSource);
	Gura_AssignMethod(wx_WebKitCtrl, GetPageURL);
	Gura_AssignMethod(wx_WebKitCtrl, SetPageTitle);
	Gura_AssignMethod(wx_WebKitCtrl, GetPageTitle);
	Gura_AssignMethod(wx_WebKitCtrl, SetTitle);
	Gura_AssignMethod(wx_WebKitCtrl, GetTitle);
	Gura_AssignMethod(wx_WebKitCtrl, GetSelection);
	Gura_AssignMethod(wx_WebKitCtrl, CanIncreaseTextSize);
	Gura_AssignMethod(wx_WebKitCtrl, IncreaseTextSize);
	Gura_AssignMethod(wx_WebKitCtrl, CanDecreaseTextSize);
	Gura_AssignMethod(wx_WebKitCtrl, DecreaseTextSize);
	Gura_AssignMethod(wx_WebKitCtrl, Print);
	Gura_AssignMethod(wx_WebKitCtrl, MakeEditable);
	Gura_AssignMethod(wx_WebKitCtrl, IsEditable);
	Gura_AssignMethod(wx_WebKitCtrl, RunScript);
	Gura_AssignMethod(wx_WebKitCtrl, SetScrollPos);
	Gura_AssignMethod(wx_WebKitCtrl, GetScrollPos);
}

Gura_ImplementDescendantCreator(wx_WebKitCtrl)
{
	return new Object_wx_WebKitCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
