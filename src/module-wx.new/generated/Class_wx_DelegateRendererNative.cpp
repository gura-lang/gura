//----------------------------------------------------------------------------
// wxDelegateRendererNative
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDelegateRendererNative
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDelegateRendererNative
//----------------------------------------------------------------------------
Object_wx_DelegateRendererNative::~Object_wx_DelegateRendererNative()
{
}

Object *Object_wx_DelegateRendererNative::Clone() const
{
	return nullptr;
}

String Object_wx_DelegateRendererNative::ToString(bool exprFlag)
{
	String rtn("<wx.DelegateRendererNative:");
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
Gura_DeclareFunctionAlias(__DelegateRendererNative, "DelegateRendererNative")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DelegateRendererNative));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DelegateRendererNative)
{
	//wxDelegateRendererNative();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__DelegateRendererNative_1, "DelegateRendererNative_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rendererNative", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DelegateRendererNative));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DelegateRendererNative_1)
{
	//wxRendererNative& rendererNative = arg.GetNumber(0)
	//wxDelegateRendererNative(rendererNative);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawHeaderButton, "DrawHeaderButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sortArrow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawHeaderButton)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//wxHeaderSortIconType sortArrow = arg.GetNumber(4)
	//wxHeaderButtonParams* params = arg.GetNumber(5)
	//pThis->GetEntity()->DrawHeaderButton(win, dc, rect, flags, sortArrow, params);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawHeaderButtonContents, "DrawHeaderButtonContents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sortArrow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawHeaderButtonContents)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//wxHeaderSortIconType sortArrow = arg.GetNumber(4)
	//wxHeaderButtonParams* params = arg.GetNumber(5)
	//pThis->GetEntity()->DrawHeaderButtonContents(win, dc, rect, flags, sortArrow, params);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __GetHeaderButtonHeight, "GetHeaderButtonHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __GetHeaderButtonHeight)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeaderButtonHeight(win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __GetHeaderButtonMargin, "GetHeaderButtonMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __GetHeaderButtonMargin)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeaderButtonMargin(win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawTreeItemButton, "DrawTreeItemButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawTreeItemButton)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawTreeItemButton(win, dc, rect, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawSplitterBorder, "DrawSplitterBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawSplitterBorder)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawSplitterBorder(win, dc, rect, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawSplitterSash, "DrawSplitterSash")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawSplitterSash)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxSize& size = arg.GetNumber(2)
	//wxCoord position = arg.GetNumber(3)
	//wxOrientation orient = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->DrawSplitterSash(win, dc, size, position, orient, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawComboBoxDropButton, "DrawComboBoxDropButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawComboBoxDropButton)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawComboBoxDropButton(win, dc, rect, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawDropArrow, "DrawDropArrow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawDropArrow)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawDropArrow(win, dc, rect, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawCheckBox, "DrawCheckBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawCheckBox)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawCheckBox(win, dc, rect, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __GetCheckBoxSize, "GetCheckBoxSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __GetCheckBoxSize)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->GetCheckBoxSize(win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawPushButton, "DrawPushButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawPushButton)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawPushButton(win, dc, rect, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawItemSelectionRect, "DrawItemSelectionRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawItemSelectionRect)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawItemSelectionRect(win, dc, rect, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __DrawFocusRect, "DrawFocusRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __DrawFocusRect)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//wxDC& dc = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawFocusRect(win, dc, rect, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __GetSplitterParams, "GetSplitterParams")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __GetSplitterParams)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxWindow* win = arg.GetNumber(0)
	//pThis->GetEntity()->GetSplitterParams(win);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __GetVersion, "GetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __GetVersion)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDelegateRendererNative
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DelegateRendererNative)
{
	// Constructor assignment
	Gura_AssignFunction(__DelegateRendererNative);
	Gura_AssignFunction(__DelegateRendererNative_1);
	// Method assignment
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawHeaderButton);
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawHeaderButtonContents);
	Gura_AssignMethod(wx_DelegateRendererNative, __GetHeaderButtonHeight);
	Gura_AssignMethod(wx_DelegateRendererNative, __GetHeaderButtonMargin);
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawTreeItemButton);
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawSplitterBorder);
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawSplitterSash);
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawComboBoxDropButton);
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawDropArrow);
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawCheckBox);
	Gura_AssignMethod(wx_DelegateRendererNative, __GetCheckBoxSize);
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawPushButton);
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawItemSelectionRect);
	Gura_AssignMethod(wx_DelegateRendererNative, __DrawFocusRect);
	Gura_AssignMethod(wx_DelegateRendererNative, __GetSplitterParams);
	Gura_AssignMethod(wx_DelegateRendererNative, __GetVersion);
}

Gura_ImplementDescendantCreator(wx_DelegateRendererNative)
{
	return new Object_wx_DelegateRendererNative((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
