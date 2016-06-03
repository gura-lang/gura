//----------------------------------------------------------------------------
// wxAuiTabArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiTabArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiTabArt
//----------------------------------------------------------------------------
Object_wx_AuiTabArt::~Object_wx_AuiTabArt()
{
}

Object *Object_wx_AuiTabArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiTabArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiTabArt:");
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
Gura_DeclareFunctionAlias(__AuiTabArt, "AuiTabArt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiTabArt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiTabArt)
{
	//wxAuiTabArt();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiTabArt, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabArt, __Clone)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __DrawBackground, "DrawBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __DrawBackground)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __DrawButton, "DrawButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "in_rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button_state", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "out_rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __DrawButton)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int in_rect = arg.GetNumber(2)
	//int bitmap_id = arg.GetNumber(3)
	//int button_state = arg.GetNumber(4)
	//int orientation = arg.GetNumber(5)
	//int out_rect = arg.GetNumber(6)
	//pThis->GetEntity()->DrawButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __DrawTab, "DrawTab")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "page", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "close_button_state", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "out_tab_rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "out_button_rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x_extent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __DrawTab)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int page = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//int close_button_state = arg.GetNumber(4)
	//int out_tab_rect = arg.GetNumber(5)
	//int out_button_rect = arg.GetNumber(6)
	//int x_extent = arg.GetNumber(7)
	//pThis->GetEntity()->DrawTab();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __GetBestTabCtrlSize, "GetBestTabCtrlSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "_arg0", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg1", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg2", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __GetBestTabCtrlSize)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _arg0 = arg.GetNumber(0)
	//int _arg1 = arg.GetNumber(1)
	//int _arg2 = arg.GetNumber(2)
	//pThis->GetEntity()->GetBestTabCtrlSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __GetIndentSize, "GetIndentSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabArt, __GetIndentSize)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndentSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __GetTabSize, "GetTabSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "active", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "close_button_state", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x_extent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __GetTabSize)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int active = arg.GetNumber(4)
	//int close_button_state = arg.GetNumber(5)
	//int x_extent = arg.GetNumber(6)
	//pThis->GetEntity()->GetTabSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __SetFlags)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __SetMeasuringFont, "SetMeasuringFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __SetMeasuringFont)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetMeasuringFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __SetNormalFont, "SetNormalFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __SetNormalFont)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __SetSelectedFont, "SetSelectedFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __SetSelectedFont)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __SetColour)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __SetActiveColour, "SetActiveColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __SetActiveColour)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetActiveColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiTabArt, __SetSizingInfo, "SetSizingInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tab_ctrl_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tab_count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, __SetSizingInfo)
{
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tab_ctrl_size = arg.GetNumber(0)
	//int tab_count = arg.GetNumber(1)
	//pThis->GetEntity()->SetSizingInfo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiTabArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiTabArt)
{
	// Constructor assignment
	Gura_AssignFunction(__AuiTabArt);
	// Method assignment
	Gura_AssignMethod(wx_AuiTabArt, __Clone);
	Gura_AssignMethod(wx_AuiTabArt, __DrawBackground);
	Gura_AssignMethod(wx_AuiTabArt, __DrawButton);
	Gura_AssignMethod(wx_AuiTabArt, __DrawTab);
	Gura_AssignMethod(wx_AuiTabArt, __GetBestTabCtrlSize);
	Gura_AssignMethod(wx_AuiTabArt, __GetIndentSize);
	Gura_AssignMethod(wx_AuiTabArt, __GetTabSize);
	Gura_AssignMethod(wx_AuiTabArt, __SetFlags);
	Gura_AssignMethod(wx_AuiTabArt, __SetMeasuringFont);
	Gura_AssignMethod(wx_AuiTabArt, __SetNormalFont);
	Gura_AssignMethod(wx_AuiTabArt, __SetSelectedFont);
	Gura_AssignMethod(wx_AuiTabArt, __SetColour);
	Gura_AssignMethod(wx_AuiTabArt, __SetActiveColour);
	Gura_AssignMethod(wx_AuiTabArt, __SetSizingInfo);
}

Gura_ImplementDescendantCreator(wx_AuiTabArt)
{
	return new Object_wx_AuiTabArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
