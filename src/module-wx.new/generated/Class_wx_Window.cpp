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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Window, "Window")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Window));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Window)
{
	//wxWindow();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Window_1, "Window_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Window));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Window_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//wxWindow(parent, id, pos, size, style, name);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Window, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __Create)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//wxWindowID id = arg.GetNumber(1)
	//const wxPoint& pos = arg.GetNumber(2)
	//const wxSize& size = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxString& name = arg.GetNumber(5)
	//pThis->GetEntity()->Create(parent, id, pos, size, style, name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __AcceptsFocus, "AcceptsFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __AcceptsFocus)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __AcceptsFocusFromKeyboard, "AcceptsFocusFromKeyboard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __AcceptsFocusFromKeyboard)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocusFromKeyboard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __AcceptsFocusRecursively, "AcceptsFocusRecursively")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __AcceptsFocusRecursively)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AcceptsFocusRecursively();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __IsFocusable, "IsFocusable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __IsFocusable)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsFocusable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __CanAcceptFocus, "CanAcceptFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __CanAcceptFocus)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanAcceptFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __CanAcceptFocusFromKeyboard, "CanAcceptFocusFromKeyboard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __CanAcceptFocusFromKeyboard)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanAcceptFocusFromKeyboard();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __HasFocus, "HasFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __HasFocus)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->HasFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __SetCanFocus, "SetCanFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "canFocus", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __SetCanFocus)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool canFocus = arg.GetNumber(0)
	//pThis->GetEntity()->SetCanFocus(canFocus);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __SetFocus, "SetFocus")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __SetFocus)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetFocus();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __SetFocusFromKbd, "SetFocusFromKbd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __SetFocusFromKbd)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->SetFocusFromKbd();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __AddChild, "AddChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __AddChild)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* child = arg.GetNumber(0)
	//pThis->GetEntity()->AddChild(child);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __DestroyChildren, "DestroyChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __DestroyChildren)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DestroyChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __FindWindow, "FindWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __FindWindow)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long id = arg.GetNumber(0)
	//pThis->GetEntity()->FindWindow(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __FindWindow_1, "FindWindow_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __FindWindow_1)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& name = arg.GetNumber(0)
	//pThis->GetEntity()->FindWindow(name);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __GetChildren, "GetChildren")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __GetChildren)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __GetChildren_1, "GetChildren_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __GetChildren_1)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChildren();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __RemoveChild, "RemoveChild")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "child", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __RemoveChild)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* child = arg.GetNumber(0)
	//pThis->GetEntity()->RemoveChild(child);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __GetGrandParent, "GetGrandParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __GetGrandParent)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGrandParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __GetNextSibling, "GetNextSibling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __GetNextSibling)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNextSibling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __GetParent, "GetParent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __GetParent)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetParent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __GetPrevSibling, "GetPrevSibling")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __GetPrevSibling)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrevSibling();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __IsDescendant, "IsDescendant")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __IsDescendant)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindowBase* win = arg.GetNumber(0)
	//pThis->GetEntity()->IsDescendant(win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __Reparent, "Reparent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newParent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __Reparent)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* newParent = arg.GetNumber(0)
	//pThis->GetEntity()->Reparent(newParent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __AlwaysShowScrollbars, "AlwaysShowScrollbars")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hflag", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "vflag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __AlwaysShowScrollbars)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool hflag = arg.GetNumber(0)
	//bool vflag = arg.GetNumber(1)
	//pThis->GetEntity()->AlwaysShowScrollbars(hflag, vflag);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __GetScrollPos, "GetScrollPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __GetScrollPos)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->GetScrollPos(orientation);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __GetScrollRange, "GetScrollRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __GetScrollRange)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->GetScrollRange(orientation);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __GetScrollThumb, "GetScrollThumb")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __GetScrollThumb)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->GetScrollThumb(orientation);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __CanScroll, "CanScroll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __CanScroll)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->CanScroll(orient);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __HasScrollbar, "HasScrollbar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __HasScrollbar)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->HasScrollbar(orient);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __IsScrollbarAlwaysShown, "IsScrollbarAlwaysShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __IsScrollbarAlwaysShown)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orient = arg.GetNumber(0)
	//pThis->GetEntity()->IsScrollbarAlwaysShown(orient);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __ScrollLines, "ScrollLines")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lines", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __ScrollLines)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lines = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollLines(lines);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __ScrollPages, "ScrollPages")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __ScrollPages)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int pages = arg.GetNumber(0)
	//pThis->GetEntity()->ScrollPages(pages);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __ScrollWindow, "ScrollWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dx", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dy", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __ScrollWindow)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dx = arg.GetNumber(0)
	//int dy = arg.GetNumber(1)
	//const wxRect* rect = arg.GetNumber(2)
	//pThis->GetEntity()->ScrollWindow(dx, dy, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __LineUp, "LineUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __LineUp)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __LineDown, "LineDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __LineDown)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LineDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __PageUp, "PageUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __PageUp)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __PageDown, "PageDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Window, __PageDown)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->PageDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __SetScrollPos, "SetScrollPos")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __SetScrollPos)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//int pos = arg.GetNumber(1)
	//bool refresh = arg.GetNumber(2)
	//pThis->GetEntity()->SetScrollPos(orientation, pos, refresh);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __SetScrollbar, "SetScrollbar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "thumbSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "refresh", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __SetScrollbar)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//int position = arg.GetNumber(1)
	//int thumbSize = arg.GetNumber(2)
	//int range = arg.GetNumber(3)
	//bool refresh = arg.GetNumber(4)
	//pThis->GetEntity()->SetScrollbar(orientation, position, thumbSize, range, refresh);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Window, __ChildrenRepositioningGuard, "ChildrenRepositioningGuard")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Window, __ChildrenRepositioningGuard)
{
	Object_wx_Window *pThis = Object_wx_Window::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->ChildrenRepositioningGuard(win);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Window)
{
	// Constructor assignment
	Gura_AssignFunction(__Window);
	Gura_AssignFunction(__Window_1);
	// Method assignment
	Gura_AssignMethod(wx_Window, __Create);
	Gura_AssignMethod(wx_Window, __AcceptsFocus);
	Gura_AssignMethod(wx_Window, __AcceptsFocusFromKeyboard);
	Gura_AssignMethod(wx_Window, __AcceptsFocusRecursively);
	Gura_AssignMethod(wx_Window, __IsFocusable);
	Gura_AssignMethod(wx_Window, __CanAcceptFocus);
	Gura_AssignMethod(wx_Window, __CanAcceptFocusFromKeyboard);
	Gura_AssignMethod(wx_Window, __HasFocus);
	Gura_AssignMethod(wx_Window, __SetCanFocus);
	Gura_AssignMethod(wx_Window, __SetFocus);
	Gura_AssignMethod(wx_Window, __SetFocusFromKbd);
	Gura_AssignMethod(wx_Window, __AddChild);
	Gura_AssignMethod(wx_Window, __DestroyChildren);
	Gura_AssignMethod(wx_Window, __FindWindow);
	Gura_AssignMethod(wx_Window, __FindWindow_1);
	Gura_AssignMethod(wx_Window, __GetChildren);
	Gura_AssignMethod(wx_Window, __GetChildren_1);
	Gura_AssignMethod(wx_Window, __RemoveChild);
	Gura_AssignMethod(wx_Window, __GetGrandParent);
	Gura_AssignMethod(wx_Window, __GetNextSibling);
	Gura_AssignMethod(wx_Window, __GetParent);
	Gura_AssignMethod(wx_Window, __GetPrevSibling);
	Gura_AssignMethod(wx_Window, __IsDescendant);
	Gura_AssignMethod(wx_Window, __Reparent);
	Gura_AssignMethod(wx_Window, __AlwaysShowScrollbars);
	Gura_AssignMethod(wx_Window, __GetScrollPos);
	Gura_AssignMethod(wx_Window, __GetScrollRange);
	Gura_AssignMethod(wx_Window, __GetScrollThumb);
	Gura_AssignMethod(wx_Window, __CanScroll);
	Gura_AssignMethod(wx_Window, __HasScrollbar);
	Gura_AssignMethod(wx_Window, __IsScrollbarAlwaysShown);
	Gura_AssignMethod(wx_Window, __ScrollLines);
	Gura_AssignMethod(wx_Window, __ScrollPages);
	Gura_AssignMethod(wx_Window, __ScrollWindow);
	Gura_AssignMethod(wx_Window, __LineUp);
	Gura_AssignMethod(wx_Window, __LineDown);
	Gura_AssignMethod(wx_Window, __PageUp);
	Gura_AssignMethod(wx_Window, __PageDown);
	Gura_AssignMethod(wx_Window, __SetScrollPos);
	Gura_AssignMethod(wx_Window, __SetScrollbar);
	Gura_AssignMethod(wx_Window, __ChildrenRepositioningGuard);
}

Gura_ImplementDescendantCreator(wx_Window)
{
	return new Object_wx_Window((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
