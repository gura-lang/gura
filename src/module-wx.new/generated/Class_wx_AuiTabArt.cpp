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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AuiTabArt, wxAuiTabArt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabArt, wxAuiTabArt)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxAuiTabArt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabArt, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, DrawBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, DrawBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, DrawButton)
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

Gura_ImplementMethod(wx_AuiTabArt, DrawButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_AuiTabArt, DrawTab)
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

Gura_ImplementMethod(wx_AuiTabArt, DrawTab)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_AuiTabArt, GetBestTabCtrlSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabArt, GetBestTabCtrlSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBestTabCtrlSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, GetIndentSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiTabArt, GetIndentSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetIndentSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, GetTabSize)
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

Gura_ImplementMethod(wx_AuiTabArt, GetTabSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_AuiTabArt, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetMeasuringFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetMeasuringFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetMeasuringFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetNormalFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetNormalFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetSelectedFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetSelectedFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetActiveColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetActiveColour)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetActiveColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiTabArt, SetSizingInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tab_ctrl_size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tab_count", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiTabArt, SetSizingInfo)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiTabArt *pThis = Object_wx_AuiTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_AuiTabArt, wxAuiTabArt);
	Gura_AssignMethod(wx_AuiTabArt, Clone);
	Gura_AssignMethod(wx_AuiTabArt, DrawBackground);
	Gura_AssignMethod(wx_AuiTabArt, DrawButton);
	Gura_AssignMethod(wx_AuiTabArt, DrawTab);
	Gura_AssignMethod(wx_AuiTabArt, GetBestTabCtrlSize);
	Gura_AssignMethod(wx_AuiTabArt, GetIndentSize);
	Gura_AssignMethod(wx_AuiTabArt, GetTabSize);
	Gura_AssignMethod(wx_AuiTabArt, SetFlags);
	Gura_AssignMethod(wx_AuiTabArt, SetMeasuringFont);
	Gura_AssignMethod(wx_AuiTabArt, SetNormalFont);
	Gura_AssignMethod(wx_AuiTabArt, SetSelectedFont);
	Gura_AssignMethod(wx_AuiTabArt, SetColour);
	Gura_AssignMethod(wx_AuiTabArt, SetActiveColour);
	Gura_AssignMethod(wx_AuiTabArt, SetSizingInfo);
}

Gura_ImplementDescendantCreator(wx_AuiTabArt)
{
	return new Object_wx_AuiTabArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
