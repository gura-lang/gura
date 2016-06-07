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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__HtmlWindowInterface, "HtmlWindowInterface")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_HtmlWindowInterface));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__HtmlWindowInterface)
{
	//wxHtmlWindowInterface();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_HtmlWindowInterface, __SetHTMLWindowTitle, "SetHTMLWindowTitle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, __SetHTMLWindowTitle)
{
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//pThis->GetEntity()->SetHTMLWindowTitle(title);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindowInterface, __OnHTMLLinkClicked, "OnHTMLLinkClicked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "link", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, __OnHTMLLinkClicked)
{
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxHtmlLinkInfo& link = arg.GetNumber(0)
	//pThis->GetEntity()->OnHTMLLinkClicked(link);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindowInterface, __OnHTMLOpeningURL, "OnHTMLOpeningURL")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "url", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "redirect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, __OnHTMLOpeningURL)
{
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlURLType type = arg.GetNumber(0)
	//const wxString& url = arg.GetNumber(1)
	//wxString* redirect = arg.GetNumber(2)
	//pThis->GetEntity()->OnHTMLOpeningURL(type, url, redirect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindowInterface, __HTMLCoordsToWindow, "HTMLCoordsToWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cell", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, __HTMLCoordsToWindow)
{
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxHtmlCell* cell = arg.GetNumber(0)
	//const wxPoint& pos = arg.GetNumber(1)
	//pThis->GetEntity()->HTMLCoordsToWindow(cell, pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindowInterface, __GetHTMLWindow, "GetHTMLWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, __GetHTMLWindow)
{
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHTMLWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindowInterface, __GetHTMLBackgroundColour, "GetHTMLBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, __GetHTMLBackgroundColour)
{
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHTMLBackgroundColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindowInterface, __SetHTMLBackgroundColour, "SetHTMLBackgroundColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "clr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, __SetHTMLBackgroundColour)
{
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& clr = arg.GetNumber(0)
	//pThis->GetEntity()->SetHTMLBackgroundColour(clr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindowInterface, __SetHTMLBackgroundImage, "SetHTMLBackgroundImage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmpBg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, __SetHTMLBackgroundImage)
{
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bmpBg = arg.GetNumber(0)
	//pThis->GetEntity()->SetHTMLBackgroundImage(bmpBg);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_HtmlWindowInterface, __SetHTMLStatusText, "SetHTMLStatusText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_HtmlWindowInterface, __SetHTMLStatusText)
{
	Object_wx_HtmlWindowInterface *pThis = Object_wx_HtmlWindowInterface::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->SetHTMLStatusText(text);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxHtmlWindowInterface
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlWindowInterface)
{
	// Constructor assignment
	Gura_AssignFunction(__HtmlWindowInterface);
	// Method assignment
	Gura_AssignMethod(wx_HtmlWindowInterface, __SetHTMLWindowTitle);
	Gura_AssignMethod(wx_HtmlWindowInterface, __OnHTMLLinkClicked);
	Gura_AssignMethod(wx_HtmlWindowInterface, __OnHTMLOpeningURL);
	Gura_AssignMethod(wx_HtmlWindowInterface, __HTMLCoordsToWindow);
	Gura_AssignMethod(wx_HtmlWindowInterface, __GetHTMLWindow);
	Gura_AssignMethod(wx_HtmlWindowInterface, __GetHTMLBackgroundColour);
	Gura_AssignMethod(wx_HtmlWindowInterface, __SetHTMLBackgroundColour);
	Gura_AssignMethod(wx_HtmlWindowInterface, __SetHTMLBackgroundImage);
	Gura_AssignMethod(wx_HtmlWindowInterface, __SetHTMLStatusText);
}

Gura_ImplementDescendantCreator(wx_HtmlWindowInterface)
{
	return new Object_wx_HtmlWindowInterface((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
