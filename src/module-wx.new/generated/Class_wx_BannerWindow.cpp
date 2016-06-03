//----------------------------------------------------------------------------
// wxBannerWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBannerWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBannerWindow
//----------------------------------------------------------------------------
Object_wx_BannerWindow::~Object_wx_BannerWindow()
{
}

Object *Object_wx_BannerWindow::Clone() const
{
	return nullptr;
}

String Object_wx_BannerWindow::ToString(bool exprFlag)
{
	String rtn("<wx.BannerWindow:");
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
Gura_DeclareFunctionAlias(__BannerWindow, "BannerWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_BannerWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BannerWindow)
{
	//wxBannerWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BannerWindow_1, "BannerWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BannerWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BannerWindow_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxDirection dir = arg.GetNumber(1)
	//wxBannerWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__BannerWindow_2, "BannerWindow_2")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_BannerWindow));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__BannerWindow_2)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//wxDirection dir = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//wxBannerWindow();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_BannerWindow, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BannerWindow, __Create)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID winid = arg.GetNumber(1)
	//wxDirection dir = arg.GetNumber(2)
	//const wxPoint& pos = arg.GetNumber(3)
	//const wxSize& size = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxString& name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BannerWindow, __SetBitmap, "SetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BannerWindow, __SetBitmap)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxBitmap& bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BannerWindow, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BannerWindow, __SetText)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& title = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_BannerWindow, __SetGradient, "SetGradient")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BannerWindow, __SetGradient)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& start = arg.GetNumber(0)
	//const wxColour& end = arg.GetNumber(1)
	//pThis->GetEntity()->SetGradient();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBannerWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BannerWindow)
{
	// Constructor assignment
	Gura_AssignFunction(__BannerWindow);
	Gura_AssignFunction(__BannerWindow_1);
	Gura_AssignFunction(__BannerWindow_2);
	// Method assignment
	Gura_AssignMethod(wx_BannerWindow, __Create);
	Gura_AssignMethod(wx_BannerWindow, __SetBitmap);
	Gura_AssignMethod(wx_BannerWindow, __SetText);
	Gura_AssignMethod(wx_BannerWindow, __SetGradient);
}

Gura_ImplementDescendantCreator(wx_BannerWindow)
{
	return new Object_wx_BannerWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
