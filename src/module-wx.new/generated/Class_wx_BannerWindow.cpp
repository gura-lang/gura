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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_BannerWindow, wxBannerWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_BannerWindow, wxBannerWindow)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxBannerWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BannerWindow, wxBannerWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BannerWindow, wxBannerWindow_1)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//pThis->GetEntity()->wxBannerWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BannerWindow, wxBannerWindow_2)
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

Gura_ImplementMethod(wx_BannerWindow, wxBannerWindow_2)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int dir = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxBannerWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BannerWindow, Create)
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

Gura_ImplementMethod(wx_BannerWindow, Create)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int dir = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BannerWindow, SetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BannerWindow, SetBitmap)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
	//pThis->GetEntity()->SetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BannerWindow, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BannerWindow, SetText)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_BannerWindow, SetGradient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "start", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "end", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BannerWindow, SetGradient)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int start = arg.GetNumber(0)
	//int end = arg.GetNumber(1)
	//pThis->GetEntity()->SetGradient();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxBannerWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BannerWindow)
{
	Gura_AssignMethod(wx_BannerWindow, wxBannerWindow);
	Gura_AssignMethod(wx_BannerWindow, wxBannerWindow_1);
	Gura_AssignMethod(wx_BannerWindow, wxBannerWindow_2);
	Gura_AssignMethod(wx_BannerWindow, Create);
	Gura_AssignMethod(wx_BannerWindow, SetBitmap);
	Gura_AssignMethod(wx_BannerWindow, SetText);
	Gura_AssignMethod(wx_BannerWindow, SetGradient);
}

Gura_ImplementDescendantCreator(wx_BannerWindow)
{
	return new Object_wx_BannerWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
