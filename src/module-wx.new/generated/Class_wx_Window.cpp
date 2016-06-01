//----------------------------------------------------------------------------
// wxWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindow
//----------------------------------------------------------------------------
Object_wx_Window::~Object_wx_Window()
{
}

Object *Object_wx_Window::Clone() const
{
	return nullptr;
}

String Object_wx_Window::ToString(bool exprFlag)
{
	String rtn("<wx.Window:");
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
Gura_DeclareMethod(wx_Window, wxWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, wxWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, wxWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, wxWindow_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->wxWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, ~wxWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, ~wxWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int pos = arg.GetNumber(2)
	//int size = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int name = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, AcceptsFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, AcceptsFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, AcceptsFocusFromKeyboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, AcceptsFocusFromKeyboard)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocusFromKeyboard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, AcceptsFocusRecursively)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, AcceptsFocusRecursively)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocusRecursively();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, IsFocusable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, IsFocusable)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsFocusable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, CanAcceptFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, CanAcceptFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanAcceptFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, CanAcceptFocusFromKeyboard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, CanAcceptFocusFromKeyboard)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanAcceptFocusFromKeyboard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, HasFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, HasFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetCanFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "canFocus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetCanFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int canFocus = arg.GetNumber(0)
	//pThis->GetEntity()->SetCanFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetFocus)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, SetFocus)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetFocus();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetFocusFromKbd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, SetFocusFromKbd)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SetFocusFromKbd();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, AddChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, AddChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->AddChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, DestroyChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, DestroyChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DestroyChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, FindWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, FindWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->FindWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, FindWindow_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, FindWindow_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->FindWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetChildren)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, GetChildren)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetChildren_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, GetChildren_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, RemoveChild)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, RemoveChild)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int child = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveChild();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetGrandParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, GetGrandParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetGrandParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetNextSibling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, GetNextSibling)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNextSibling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetParent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, GetParent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetPrevSibling)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, GetPrevSibling)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrevSibling();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, IsDescendant)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, IsDescendant)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->IsDescendant();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, Reparent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newParent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, Reparent)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int newParent = arg.GetNumber(0)
	//pThis->GetEntity()->Reparent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, AlwaysShowScrollbars)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hflag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vflag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, AlwaysShowScrollbars)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int hflag = arg.GetNumber(0)
	//int vflag = arg.GetNumber(1)
	//pThis->GetEntity()->AlwaysShowScrollbars();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetScrollPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, GetScrollPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->GetScrollPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetScrollRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, GetScrollRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->GetScrollRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, GetScrollThumb)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, GetScrollThumb)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->GetScrollThumb();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, CanScroll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, CanScroll)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->CanScroll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, HasScrollbar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, HasScrollbar)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->HasScrollbar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, IsScrollbarAlwaysShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, IsScrollbarAlwaysShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->IsScrollbarAlwaysShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, ScrollLines)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, ScrollLines)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int lines = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollLines();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, ScrollPages)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, ScrollPages)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pages = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollPages();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, ScrollWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, ScrollWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->ScrollWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, LineUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, LineUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, LineDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, LineDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LineDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, PageUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, PageUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PageUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, PageDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, PageDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->PageDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetScrollPos)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetScrollPos)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//int refresh = arg.GetNumber(2)
	//pThis->GetEntity()->SetScrollPos();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, SetScrollbar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "thumbSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, SetScrollbar)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//int thumbSize = arg.GetNumber(2)
	//int range = arg.GetNumber(3)
	//int refresh = arg.GetNumber(4)
	//pThis->GetEntity()->SetScrollbar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, ChildrenRepositioningGuard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, ChildrenRepositioningGuard)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->ChildrenRepositioningGuard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Window, ~ChildrenRepositioningGuard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, ~ChildrenRepositioningGuard)
{
	Signal &sig = env.GetSignal();
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~ChildrenRepositioningGuard();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Window)
{
	Gura_AssignMethod(wx_Window, wxWindow);
	Gura_AssignMethod(wx_Window, wxWindow_1);
	Gura_AssignMethod(wx_Window, ~wxWindow);
	Gura_AssignMethod(wx_Window, Create);
	Gura_AssignMethod(wx_Window, AcceptsFocus);
	Gura_AssignMethod(wx_Window, AcceptsFocusFromKeyboard);
	Gura_AssignMethod(wx_Window, AcceptsFocusRecursively);
	Gura_AssignMethod(wx_Window, IsFocusable);
	Gura_AssignMethod(wx_Window, CanAcceptFocus);
	Gura_AssignMethod(wx_Window, CanAcceptFocusFromKeyboard);
	Gura_AssignMethod(wx_Window, HasFocus);
	Gura_AssignMethod(wx_Window, SetCanFocus);
	Gura_AssignMethod(wx_Window, SetFocus);
	Gura_AssignMethod(wx_Window, SetFocusFromKbd);
	Gura_AssignMethod(wx_Window, AddChild);
	Gura_AssignMethod(wx_Window, DestroyChildren);
	Gura_AssignMethod(wx_Window, FindWindow);
	Gura_AssignMethod(wx_Window, FindWindow_1);
	Gura_AssignMethod(wx_Window, GetChildren);
	Gura_AssignMethod(wx_Window, GetChildren_1);
	Gura_AssignMethod(wx_Window, RemoveChild);
	Gura_AssignMethod(wx_Window, GetGrandParent);
	Gura_AssignMethod(wx_Window, GetNextSibling);
	Gura_AssignMethod(wx_Window, GetParent);
	Gura_AssignMethod(wx_Window, GetPrevSibling);
	Gura_AssignMethod(wx_Window, IsDescendant);
	Gura_AssignMethod(wx_Window, Reparent);
	Gura_AssignMethod(wx_Window, AlwaysShowScrollbars);
	Gura_AssignMethod(wx_Window, GetScrollPos);
	Gura_AssignMethod(wx_Window, GetScrollRange);
	Gura_AssignMethod(wx_Window, GetScrollThumb);
	Gura_AssignMethod(wx_Window, CanScroll);
	Gura_AssignMethod(wx_Window, HasScrollbar);
	Gura_AssignMethod(wx_Window, IsScrollbarAlwaysShown);
	Gura_AssignMethod(wx_Window, ScrollLines);
	Gura_AssignMethod(wx_Window, ScrollPages);
	Gura_AssignMethod(wx_Window, ScrollWindow);
	Gura_AssignMethod(wx_Window, LineUp);
	Gura_AssignMethod(wx_Window, LineDown);
	Gura_AssignMethod(wx_Window, PageUp);
	Gura_AssignMethod(wx_Window, PageDown);
	Gura_AssignMethod(wx_Window, SetScrollPos);
	Gura_AssignMethod(wx_Window, SetScrollbar);
	Gura_AssignMethod(wx_Window, ChildrenRepositioningGuard);
	Gura_AssignMethod(wx_Window, ~ChildrenRepositioningGuard);
}

Gura_ImplementDescendantCreator(wx_Window)
{
	return new Object_wx_Window((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
