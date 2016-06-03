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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DelegateRendererNative, __wxDelegateRendererNative, "wxDelegateRendererNative")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __wxDelegateRendererNative)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDelegateRendererNative();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DelegateRendererNative, __wxDelegateRendererNative_1, "wxDelegateRendererNative_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rendererNative", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, __wxDelegateRendererNative_1)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rendererNative = arg.GetNumber(0)
	//pThis->GetEntity()->wxDelegateRendererNative();
	return Value::Nil;
}

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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int sortArrow = arg.GetNumber(4)
	//int params = arg.GetNumber(5)
	//pThis->GetEntity()->DrawHeaderButton();
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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//int sortArrow = arg.GetNumber(4)
	//int params = arg.GetNumber(5)
	//pThis->GetEntity()->DrawHeaderButtonContents();
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
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeaderButtonHeight();
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
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeaderButtonMargin();
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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawTreeItemButton();
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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawSplitterBorder();
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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int size = arg.GetNumber(2)
	//int position = arg.GetNumber(3)
	//int orient = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->DrawSplitterSash();
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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawComboBoxDropButton();
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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawDropArrow();
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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawCheckBox();
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
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetCheckBoxSize();
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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawPushButton();
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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawItemSelectionRect();
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
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawFocusRect();
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
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetSplitterParams();
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
	Gura_AssignMethod(wx_DelegateRendererNative, __wxDelegateRendererNative);
	Gura_AssignMethod(wx_DelegateRendererNative, __wxDelegateRendererNative_1);
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
