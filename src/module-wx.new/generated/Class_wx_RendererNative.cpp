//----------------------------------------------------------------------------
// wxRendererNative
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRendererNative
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRendererNative
//----------------------------------------------------------------------------
Object_wx_RendererNative::~Object_wx_RendererNative()
{
}

Object *Object_wx_RendererNative::Clone() const
{
	return nullptr;
}

String Object_wx_RendererNative::ToString(bool exprFlag)
{
	String rtn("<wx.RendererNative:");
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
Gura_DeclareMethod(wx_RendererNative, DrawCheckBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawCheckBox)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawCheckBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawComboBoxDropButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawComboBoxDropButton)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawComboBoxDropButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawDropArrow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawDropArrow)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawDropArrow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawFocusRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawFocusRect)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawFocusRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawGauge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawGauge)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int value = arg.GetNumber(3)
	//int max = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//pThis->GetEntity()->DrawGauge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawHeaderButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sortArrow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawHeaderButton)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RendererNative, DrawHeaderButtonContents)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sortArrow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawHeaderButtonContents)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RendererNative, DrawItemSelectionRect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawItemSelectionRect)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawItemSelectionRect();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawItemText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "align", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ellipsizeMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawItemText)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//int align = arg.GetNumber(4)
	//int flags = arg.GetNumber(5)
	//int ellipsizeMode = arg.GetNumber(6)
	//pThis->GetEntity()->DrawItemText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawPushButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawPushButton)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawPushButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawCollapseButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawCollapseButton)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawCollapseButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, GetCollapseButtonSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, GetCollapseButtonSize)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//pThis->GetEntity()->GetCollapseButtonSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawSplitterBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawSplitterBorder)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawSplitterBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawSplitterSash)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawSplitterSash)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
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

Gura_DeclareMethod(wx_RendererNative, DrawTreeItemButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawTreeItemButton)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawTreeItemButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawChoice)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawChoice)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawChoice();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawComboBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawComboBox)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawComboBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawTextCtrl)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawRadioBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawRadioBitmap)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int flags = arg.GetNumber(3)
	//pThis->GetEntity()->DrawRadioBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, DrawTitleBarBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, DrawTitleBarBitmap)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int button = arg.GetNumber(3)
	//int flags = arg.GetNumber(4)
	//pThis->GetEntity()->DrawTitleBarBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, Get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RendererNative, Get)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, GetDefault)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RendererNative, GetDefault)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefault();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, GetGeneric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RendererNative, GetGeneric)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGeneric();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, GetCheckBoxSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, GetCheckBoxSize)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetCheckBoxSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, GetHeaderButtonHeight)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, GetHeaderButtonHeight)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeaderButtonHeight();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, GetHeaderButtonMargin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, GetHeaderButtonMargin)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeaderButtonMargin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, GetSplitterParams)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, GetSplitterParams)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetSplitterParams();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, GetVersion)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RendererNative, GetVersion)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, Load)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, Load)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RendererNative, Set)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "renderer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, Set)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int renderer = arg.GetNumber(0)
	//pThis->GetEntity()->Set();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRendererNative
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RendererNative)
{
	Gura_AssignMethod(wx_RendererNative, DrawCheckBox);
	Gura_AssignMethod(wx_RendererNative, DrawComboBoxDropButton);
	Gura_AssignMethod(wx_RendererNative, DrawDropArrow);
	Gura_AssignMethod(wx_RendererNative, DrawFocusRect);
	Gura_AssignMethod(wx_RendererNative, DrawGauge);
	Gura_AssignMethod(wx_RendererNative, DrawHeaderButton);
	Gura_AssignMethod(wx_RendererNative, DrawHeaderButtonContents);
	Gura_AssignMethod(wx_RendererNative, DrawItemSelectionRect);
	Gura_AssignMethod(wx_RendererNative, DrawItemText);
	Gura_AssignMethod(wx_RendererNative, DrawPushButton);
	Gura_AssignMethod(wx_RendererNative, DrawCollapseButton);
	Gura_AssignMethod(wx_RendererNative, GetCollapseButtonSize);
	Gura_AssignMethod(wx_RendererNative, DrawSplitterBorder);
	Gura_AssignMethod(wx_RendererNative, DrawSplitterSash);
	Gura_AssignMethod(wx_RendererNative, DrawTreeItemButton);
	Gura_AssignMethod(wx_RendererNative, DrawChoice);
	Gura_AssignMethod(wx_RendererNative, DrawComboBox);
	Gura_AssignMethod(wx_RendererNative, DrawTextCtrl);
	Gura_AssignMethod(wx_RendererNative, DrawRadioBitmap);
	Gura_AssignMethod(wx_RendererNative, DrawTitleBarBitmap);
	Gura_AssignMethod(wx_RendererNative, Get);
	Gura_AssignMethod(wx_RendererNative, GetDefault);
	Gura_AssignMethod(wx_RendererNative, GetGeneric);
	Gura_AssignMethod(wx_RendererNative, GetCheckBoxSize);
	Gura_AssignMethod(wx_RendererNative, GetHeaderButtonHeight);
	Gura_AssignMethod(wx_RendererNative, GetHeaderButtonMargin);
	Gura_AssignMethod(wx_RendererNative, GetSplitterParams);
	Gura_AssignMethod(wx_RendererNative, GetVersion);
	Gura_AssignMethod(wx_RendererNative, Load);
	Gura_AssignMethod(wx_RendererNative, Set);
}

Gura_ImplementDescendantCreator(wx_RendererNative)
{
	return new Object_wx_RendererNative((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
