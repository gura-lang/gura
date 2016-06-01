//----------------------------------------------------------------------------
// wxHtmlWindowInterface
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlWindowInterface
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlWindowInterface
//----------------------------------------------------------------------------
Object_wx_HtmlWindowInterface::~Object_wx_HtmlWindowInterface()
{
}

Object *Object_wx_HtmlWindowInterface::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlWindowInterface::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlWindowInterface:");
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
Gura_DeclareMethod(wx_HtmlWindowInterface, wxHtmlWindowInterface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, wxHtmlWindowInterface)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxHtmlWindowInterface();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindowInterface, ~wxHtmlWindowInterface)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, ~wxHtmlWindowInterface)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxHtmlWindowInterface();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindowInterface, SetHTMLWindowTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, SetHTMLWindowTitle)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetHTMLWindowTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindowInterface, OnHTMLLinkClicked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, OnHTMLLinkClicked)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int link = arg.GetNumber(0)
	//pThis->GetEntity()->OnHTMLLinkClicked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindowInterface, OnHTMLOpeningURL)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "redirect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, OnHTMLOpeningURL)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//int url = arg.GetNumber(1)
	//int redirect = arg.GetNumber(2)
	//pThis->GetEntity()->OnHTMLOpeningURL();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindowInterface, HTMLCoordsToWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, HTMLCoordsToWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cell = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//pThis->GetEntity()->HTMLCoordsToWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindowInterface, GetHTMLWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, GetHTMLWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHTMLWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindowInterface, GetHTMLBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, GetHTMLBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHTMLBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindowInterface, SetHTMLBackgroundColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, SetHTMLBackgroundColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int clr = arg.GetNumber(0)
	//pThis->GetEntity()->SetHTMLBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindowInterface, SetHTMLBackgroundImage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmpBg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, SetHTMLBackgroundImage)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int bmpBg = arg.GetNumber(0)
	//pThis->GetEntity()->SetHTMLBackgroundImage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_HtmlWindowInterface, SetHTMLStatusText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, SetHTMLStatusText)
{
	Signal &sig = env.GetSignal();
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetHTMLStatusText();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWindowInterface
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWindowInterface)
{
	Gura_AssignMethod(wx_HtmlWindowInterface, wxHtmlWindowInterface);
	Gura_AssignMethod(wx_HtmlWindowInterface, ~wxHtmlWindowInterface);
	Gura_AssignMethod(wx_HtmlWindowInterface, SetHTMLWindowTitle);
	Gura_AssignMethod(wx_HtmlWindowInterface, OnHTMLLinkClicked);
	Gura_AssignMethod(wx_HtmlWindowInterface, OnHTMLOpeningURL);
	Gura_AssignMethod(wx_HtmlWindowInterface, HTMLCoordsToWindow);
	Gura_AssignMethod(wx_HtmlWindowInterface, GetHTMLWindow);
	Gura_AssignMethod(wx_HtmlWindowInterface, GetHTMLBackgroundColour);
	Gura_AssignMethod(wx_HtmlWindowInterface, SetHTMLBackgroundColour);
	Gura_AssignMethod(wx_HtmlWindowInterface, SetHTMLBackgroundImage);
	Gura_AssignMethod(wx_HtmlWindowInterface, SetHTMLStatusText);
}

Gura_ImplementDescendantCreator(wx_HtmlWindowInterface)
{
	return new Object_wx_HtmlWindowInterface((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
