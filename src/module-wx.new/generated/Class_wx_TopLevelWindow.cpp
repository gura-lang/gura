//----------------------------------------------------------------------------
// wxTopLevelWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTopLevelWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTopLevelWindow
//----------------------------------------------------------------------------
Object_wx_TopLevelWindow::~Object_wx_TopLevelWindow()
{
}

Object *Object_wx_TopLevelWindow::Clone() const
{
	return nullptr;
}

String Object_wx_TopLevelWindow::ToString(bool exprFlag)
{
	String rtn("<wx.TopLevelWindow:");
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
Gura_DeclareMethod(wx_TopLevelWindow, wxTopLevelWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, wxTopLevelWindow)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTopLevelWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, wxTopLevelWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, wxTopLevelWindow_1)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxTopLevelWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, Create)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, CanSetTransparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, CanSetTransparent)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanSetTransparent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, CenterOnScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, CenterOnScreen)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->CenterOnScreen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, CentreOnScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, CentreOnScreen)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->CentreOnScreen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, EnableCloseButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, EnableCloseButton)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableCloseButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, EnableMaximizeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, EnableMaximizeButton)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableMaximizeButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, EnableMinimizeButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, EnableMinimizeButton)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableMinimizeButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, GetDefaultItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetDefaultItem)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, GetDefaultSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetDefaultSize)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, GetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetIcon)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, GetIcons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetIcons)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIcons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, GetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetTitle)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, Iconize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, Iconize)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iconize = arg.GetNumber(0)
	//pThis->GetEntity()->Iconize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, IsActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsActive)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, IsAlwaysMaximized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsAlwaysMaximized)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsAlwaysMaximized();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, IsFullScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsFullScreen)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFullScreen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, IsIconized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsIconized)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsIconized();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, IsMaximized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsMaximized)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMaximized();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, IsUsingNativeDecorations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, IsUsingNativeDecorations)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsUsingNativeDecorations();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, Layout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, Layout)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Layout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, Maximize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maximize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, Maximize)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int maximize = arg.GetNumber(0)
	//pThis->GetEntity()->Maximize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, MSWGetSystemMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, MSWGetSystemMenu)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MSWGetSystemMenu();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, RequestUserAttention)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, RequestUserAttention)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->RequestUserAttention();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, Restore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, Restore)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Restore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetDefaultItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetDefaultItem)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetTmpDefaultItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetTmpDefaultItem)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->SetTmpDefaultItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, GetTmpDefaultItem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, GetTmpDefaultItem)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTmpDefaultItem();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetIcon)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetIcons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icons", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetIcons)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icons = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetMaxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetMaxSize)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetMinSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetMinSize)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int size = arg.GetNumber(0)
	//pThis->GetEntity()->SetMinSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetSizeHints)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minW", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minH", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxW", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxH", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "incW", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "incH", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetSizeHints)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minW = arg.GetNumber(0)
	//int minH = arg.GetNumber(1)
	//int maxW = arg.GetNumber(2)
	//int maxH = arg.GetNumber(3)
	//int incW = arg.GetNumber(4)
	//int incH = arg.GetNumber(5)
	//pThis->GetEntity()->SetSizeHints();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetSizeHints_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "minSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "incSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetSizeHints_1)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int minSize = arg.GetNumber(0)
	//int maxSize = arg.GetNumber(1)
	//int incSize = arg.GetNumber(2)
	//pThis->GetEntity()->SetSizeHints();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetTitle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetTitle)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//pThis->GetEntity()->SetTitle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetTransparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "alpha", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetTransparent)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int alpha = arg.GetNumber(0)
	//pThis->GetEntity()->SetTransparent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, ShouldPreventAppExit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, ShouldPreventAppExit)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShouldPreventAppExit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, OSXSetModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "modified", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, OSXSetModified)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int modified = arg.GetNumber(0)
	//pThis->GetEntity()->OSXSetModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, OSXIsModified)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, OSXIsModified)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OSXIsModified();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, SetRepresentedFilename)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filename", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, SetRepresentedFilename)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filename = arg.GetNumber(0)
	//pThis->GetEntity()->SetRepresentedFilename();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, ShowWithoutActivating)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TopLevelWindow, ShowWithoutActivating)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowWithoutActivating();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, EnableFullScreenView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, EnableFullScreenView)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableFullScreenView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, ShowFullScreen)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, ShowFullScreen)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//int style = arg.GetNumber(1)
	//pThis->GetEntity()->ShowFullScreen();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, UseNativeDecorations)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "native", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, UseNativeDecorations)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int native = arg.GetNumber(0)
	//pThis->GetEntity()->UseNativeDecorations();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TopLevelWindow, UseNativeDecorationsByDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "native", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TopLevelWindow, UseNativeDecorationsByDefault)
{
	Object_wx_TopLevelWindow *pThis = Object_wx_TopLevelWindow::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int native = arg.GetNumber(0)
	//pThis->GetEntity()->UseNativeDecorationsByDefault();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTopLevelWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TopLevelWindow)
{
	Gura_AssignMethod(wx_TopLevelWindow, wxTopLevelWindow);
	Gura_AssignMethod(wx_TopLevelWindow, wxTopLevelWindow_1);
	Gura_AssignMethod(wx_TopLevelWindow, Create);
	Gura_AssignMethod(wx_TopLevelWindow, CanSetTransparent);
	Gura_AssignMethod(wx_TopLevelWindow, CenterOnScreen);
	Gura_AssignMethod(wx_TopLevelWindow, CentreOnScreen);
	Gura_AssignMethod(wx_TopLevelWindow, EnableCloseButton);
	Gura_AssignMethod(wx_TopLevelWindow, EnableMaximizeButton);
	Gura_AssignMethod(wx_TopLevelWindow, EnableMinimizeButton);
	Gura_AssignMethod(wx_TopLevelWindow, GetDefaultItem);
	Gura_AssignMethod(wx_TopLevelWindow, GetDefaultSize);
	Gura_AssignMethod(wx_TopLevelWindow, GetIcon);
	Gura_AssignMethod(wx_TopLevelWindow, GetIcons);
	Gura_AssignMethod(wx_TopLevelWindow, GetTitle);
	Gura_AssignMethod(wx_TopLevelWindow, Iconize);
	Gura_AssignMethod(wx_TopLevelWindow, IsActive);
	Gura_AssignMethod(wx_TopLevelWindow, IsAlwaysMaximized);
	Gura_AssignMethod(wx_TopLevelWindow, IsFullScreen);
	Gura_AssignMethod(wx_TopLevelWindow, IsIconized);
	Gura_AssignMethod(wx_TopLevelWindow, IsMaximized);
	Gura_AssignMethod(wx_TopLevelWindow, IsUsingNativeDecorations);
	Gura_AssignMethod(wx_TopLevelWindow, Layout);
	Gura_AssignMethod(wx_TopLevelWindow, Maximize);
	Gura_AssignMethod(wx_TopLevelWindow, MSWGetSystemMenu);
	Gura_AssignMethod(wx_TopLevelWindow, RequestUserAttention);
	Gura_AssignMethod(wx_TopLevelWindow, Restore);
	Gura_AssignMethod(wx_TopLevelWindow, SetDefaultItem);
	Gura_AssignMethod(wx_TopLevelWindow, SetTmpDefaultItem);
	Gura_AssignMethod(wx_TopLevelWindow, GetTmpDefaultItem);
	Gura_AssignMethod(wx_TopLevelWindow, SetIcon);
	Gura_AssignMethod(wx_TopLevelWindow, SetIcons);
	Gura_AssignMethod(wx_TopLevelWindow, SetMaxSize);
	Gura_AssignMethod(wx_TopLevelWindow, SetMinSize);
	Gura_AssignMethod(wx_TopLevelWindow, SetSizeHints);
	Gura_AssignMethod(wx_TopLevelWindow, SetSizeHints_1);
	Gura_AssignMethod(wx_TopLevelWindow, SetTitle);
	Gura_AssignMethod(wx_TopLevelWindow, SetTransparent);
	Gura_AssignMethod(wx_TopLevelWindow, ShouldPreventAppExit);
	Gura_AssignMethod(wx_TopLevelWindow, OSXSetModified);
	Gura_AssignMethod(wx_TopLevelWindow, OSXIsModified);
	Gura_AssignMethod(wx_TopLevelWindow, SetRepresentedFilename);
	Gura_AssignMethod(wx_TopLevelWindow, ShowWithoutActivating);
	Gura_AssignMethod(wx_TopLevelWindow, EnableFullScreenView);
	Gura_AssignMethod(wx_TopLevelWindow, ShowFullScreen);
	Gura_AssignMethod(wx_TopLevelWindow, UseNativeDecorations);
	Gura_AssignMethod(wx_TopLevelWindow, UseNativeDecorationsByDefault);
}

Gura_ImplementDescendantCreator(wx_TopLevelWindow)
{
	return new Object_wx_TopLevelWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
