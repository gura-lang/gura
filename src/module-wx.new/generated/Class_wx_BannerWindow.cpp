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
Gura_DeclareFunctionAlias(__wxBannerWindow, "wxBannerWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxBannerWindow)
{
	//wxBannerWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxBannerWindow_1, "wxBannerWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementFunction(__wxBannerWindow_1)
{
	//int parent = arg.GetNumber(0)
	//int dir = arg.GetNumber(1)
	//wxBannerWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxBannerWindow_2, "wxBannerWindow_2")
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

Gura_ImplementFunction(__wxBannerWindow_2)
{
	//int parent = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int dir = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
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

Gura_DeclareMethodAlias(wx_BannerWindow, __SetBitmap, "SetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "bmp", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_BannerWindow, __SetBitmap)
{
	Object_wx_BannerWindow *pThis = Object_wx_BannerWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int bmp = arg.GetNumber(0)
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
	//int title = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
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
	// Constructor assignment
	Gura_AssignFunction(__wxBannerWindow);
	Gura_AssignFunction(__wxBannerWindow_1);
	Gura_AssignFunction(__wxBannerWindow_2);
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
