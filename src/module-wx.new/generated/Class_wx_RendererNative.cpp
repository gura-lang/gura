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
Gura_DeclareMethodAlias(wx_RendererNative, __DrawCheckBox, "DrawCheckBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawCheckBox)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawComboBoxDropButton, "DrawComboBoxDropButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawComboBoxDropButton)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawDropArrow, "DrawDropArrow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawDropArrow)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawFocusRect, "DrawFocusRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawFocusRect)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawGauge, "DrawGauge")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "max", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawGauge)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawHeaderButton, "DrawHeaderButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sortArrow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawHeaderButton)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawHeaderButtonContents, "DrawHeaderButtonContents")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sortArrow", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "params", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawHeaderButtonContents)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawItemSelectionRect, "DrawItemSelectionRect")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawItemSelectionRect)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawItemText, "DrawItemText")
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

Gura_ImplementMethod(wx_RendererNative, __DrawItemText)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawPushButton, "DrawPushButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawPushButton)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawCollapseButton, "DrawCollapseButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawCollapseButton)
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

Gura_DeclareMethodAlias(wx_RendererNative, __GetCollapseButtonSize, "GetCollapseButtonSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __GetCollapseButtonSize)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int dc = arg.GetNumber(1)
	//pThis->GetEntity()->GetCollapseButtonSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RendererNative, __DrawSplitterBorder, "DrawSplitterBorder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawSplitterBorder)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawSplitterSash, "DrawSplitterSash")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "position", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orient", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawSplitterSash)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawTreeItemButton, "DrawTreeItemButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawTreeItemButton)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawChoice, "DrawChoice")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawChoice)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawComboBox, "DrawComboBox")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawComboBox)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawTextCtrl, "DrawTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawTextCtrl)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawRadioBitmap, "DrawRadioBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawRadioBitmap)
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

Gura_DeclareMethodAlias(wx_RendererNative, __DrawTitleBarBitmap, "DrawTitleBarBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __DrawTitleBarBitmap)
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

Gura_DeclareMethodAlias(wx_RendererNative, __Get, "Get")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RendererNative, __Get)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Get();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RendererNative, __GetDefault, "GetDefault")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RendererNative, __GetDefault)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefault();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RendererNative, __GetGeneric, "GetGeneric")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RendererNative, __GetGeneric)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetGeneric();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RendererNative, __GetCheckBoxSize, "GetCheckBoxSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __GetCheckBoxSize)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetCheckBoxSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RendererNative, __GetHeaderButtonHeight, "GetHeaderButtonHeight")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __GetHeaderButtonHeight)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeaderButtonHeight();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RendererNative, __GetHeaderButtonMargin, "GetHeaderButtonMargin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __GetHeaderButtonMargin)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetHeaderButtonMargin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RendererNative, __GetSplitterParams, "GetSplitterParams")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __GetSplitterParams)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//pThis->GetEntity()->GetSplitterParams();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RendererNative, __GetVersion, "GetVersion")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RendererNative, __GetVersion)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetVersion();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RendererNative, __Load, "Load")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __Load)
{
	Object_wx_RendererNative *pThis = Object_wx_RendererNative::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int name = arg.GetNumber(0)
	//pThis->GetEntity()->Load();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RendererNative, __Set, "Set")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "renderer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RendererNative, __Set)
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
	// Method assignment
	Gura_AssignMethod(wx_RendererNative, __DrawCheckBox);
	Gura_AssignMethod(wx_RendererNative, __DrawComboBoxDropButton);
	Gura_AssignMethod(wx_RendererNative, __DrawDropArrow);
	Gura_AssignMethod(wx_RendererNative, __DrawFocusRect);
	Gura_AssignMethod(wx_RendererNative, __DrawGauge);
	Gura_AssignMethod(wx_RendererNative, __DrawHeaderButton);
	Gura_AssignMethod(wx_RendererNative, __DrawHeaderButtonContents);
	Gura_AssignMethod(wx_RendererNative, __DrawItemSelectionRect);
	Gura_AssignMethod(wx_RendererNative, __DrawItemText);
	Gura_AssignMethod(wx_RendererNative, __DrawPushButton);
	Gura_AssignMethod(wx_RendererNative, __DrawCollapseButton);
	Gura_AssignMethod(wx_RendererNative, __GetCollapseButtonSize);
	Gura_AssignMethod(wx_RendererNative, __DrawSplitterBorder);
	Gura_AssignMethod(wx_RendererNative, __DrawSplitterSash);
	Gura_AssignMethod(wx_RendererNative, __DrawTreeItemButton);
	Gura_AssignMethod(wx_RendererNative, __DrawChoice);
	Gura_AssignMethod(wx_RendererNative, __DrawComboBox);
	Gura_AssignMethod(wx_RendererNative, __DrawTextCtrl);
	Gura_AssignMethod(wx_RendererNative, __DrawRadioBitmap);
	Gura_AssignMethod(wx_RendererNative, __DrawTitleBarBitmap);
	Gura_AssignMethod(wx_RendererNative, __Get);
	Gura_AssignMethod(wx_RendererNative, __GetDefault);
	Gura_AssignMethod(wx_RendererNative, __GetGeneric);
	Gura_AssignMethod(wx_RendererNative, __GetCheckBoxSize);
	Gura_AssignMethod(wx_RendererNative, __GetHeaderButtonHeight);
	Gura_AssignMethod(wx_RendererNative, __GetHeaderButtonMargin);
	Gura_AssignMethod(wx_RendererNative, __GetSplitterParams);
	Gura_AssignMethod(wx_RendererNative, __GetVersion);
	Gura_AssignMethod(wx_RendererNative, __Load);
	Gura_AssignMethod(wx_RendererNative, __Set);
}

Gura_ImplementDescendantCreator(wx_RendererNative)
{
	return new Object_wx_RendererNative((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
