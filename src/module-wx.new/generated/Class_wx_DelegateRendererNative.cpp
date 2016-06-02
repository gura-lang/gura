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
Gura_DeclareMethod(wx_DelegateRendererNative, wxDelegateRendererNative)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DelegateRendererNative, wxDelegateRendererNative)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxDelegateRendererNative();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DelegateRendererNative, wxDelegateRendererNative_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rendererNative", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, wxDelegateRendererNative_1)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rendererNative = arg.GetNumber(0)
	//pThis->GetEntity()->wxDelegateRendererNative();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DelegateRendererNative, DrawHeaderButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sortArrow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawHeaderButton)
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

Gura_DeclareMethod(wx_DelegateRendererNative, DrawHeaderButtonContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sortArrow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawHeaderButtonContents)
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

Gura_DeclareMethod(wx_DelegateRendererNative, GetHeaderButtonHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, GetHeaderButtonHeight)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeaderButtonHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DelegateRendererNative, GetHeaderButtonMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, GetHeaderButtonMargin)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeaderButtonMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DelegateRendererNative, DrawTreeItemButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawTreeItemButton)
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

Gura_DeclareMethod(wx_DelegateRendererNative, DrawSplitterBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawSplitterBorder)
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

Gura_DeclareMethod(wx_DelegateRendererNative, DrawSplitterSash)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawSplitterSash)
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

Gura_DeclareMethod(wx_DelegateRendererNative, DrawComboBoxDropButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawComboBoxDropButton)
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

Gura_DeclareMethod(wx_DelegateRendererNative, DrawDropArrow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawDropArrow)
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

Gura_DeclareMethod(wx_DelegateRendererNative, DrawCheckBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawCheckBox)
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

Gura_DeclareMethod(wx_DelegateRendererNative, GetCheckBoxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, GetCheckBoxSize)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetCheckBoxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DelegateRendererNative, DrawPushButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawPushButton)
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

Gura_DeclareMethod(wx_DelegateRendererNative, DrawItemSelectionRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawItemSelectionRect)
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

Gura_DeclareMethod(wx_DelegateRendererNative, DrawFocusRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, DrawFocusRect)
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

Gura_DeclareMethod(wx_DelegateRendererNative, GetSplitterParams)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DelegateRendererNative, GetSplitterParams)
{
	Object_wx_DelegateRendererNative *pThis = Object_wx_DelegateRendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetSplitterParams();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DelegateRendererNative, GetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DelegateRendererNative, GetVersion)
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
	Gura_AssignMethod(wx_DelegateRendererNative, wxDelegateRendererNative);
	Gura_AssignMethod(wx_DelegateRendererNative, wxDelegateRendererNative_1);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawHeaderButton);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawHeaderButtonContents);
	Gura_AssignMethod(wx_DelegateRendererNative, GetHeaderButtonHeight);
	Gura_AssignMethod(wx_DelegateRendererNative, GetHeaderButtonMargin);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawTreeItemButton);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawSplitterBorder);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawSplitterSash);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawComboBoxDropButton);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawDropArrow);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawCheckBox);
	Gura_AssignMethod(wx_DelegateRendererNative, GetCheckBoxSize);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawPushButton);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawItemSelectionRect);
	Gura_AssignMethod(wx_DelegateRendererNative, DrawFocusRect);
	Gura_AssignMethod(wx_DelegateRendererNative, GetSplitterParams);
	Gura_AssignMethod(wx_DelegateRendererNative, GetVersion);
}

Gura_ImplementDescendantCreator(wx_DelegateRendererNative)
{
	return new Object_wx_DelegateRendererNative((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
