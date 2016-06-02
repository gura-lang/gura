//----------------------------------------------------------------------------
// wxAuiSimpleTabArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiSimpleTabArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiSimpleTabArt
//----------------------------------------------------------------------------
Object_wx_AuiSimpleTabArt::~Object_wx_AuiSimpleTabArt()
{
}

Object *Object_wx_AuiSimpleTabArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiSimpleTabArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiSimpleTabArt:");
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
Gura_DeclareMethod(wx_AuiSimpleTabArt, wxAuiSimpleTabArt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, wxAuiSimpleTabArt)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAuiSimpleTabArt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, Clone)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, SetFlags)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, SetSizingInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabCtrlSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tabCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, SetSizingInfo)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tabCtrlSize = arg.GetNumber(0)
	//int tabCount = arg.GetNumber(1)
	//pThis->GetEntity()->SetSizingInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, SetNormalFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, SetNormalFont)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, SetSelectedFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, SetSelectedFont)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, SetMeasuringFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, SetMeasuringFont)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetMeasuringFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, SetColour)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, SetActiveColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, SetActiveColour)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetActiveColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, DrawBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, DrawBackground)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, DrawTab)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "closeButtonState", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outTabRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outButtonRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xExtent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, DrawTab)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int pane = arg.GetNumber(2)
	//int inRect = arg.GetNumber(3)
	//int closeButtonState = arg.GetNumber(4)
	//int outTabRect = arg.GetNumber(5)
	//int outButtonRect = arg.GetNumber(6)
	//int xExtent = arg.GetNumber(7)
	//pThis->GetEntity()->DrawTab();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, DrawButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "inRect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmapId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "buttonState", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "outRect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, DrawButton)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int inRect = arg.GetNumber(2)
	//int bitmapId = arg.GetNumber(3)
	//int buttonState = arg.GetNumber(4)
	//int orientation = arg.GetNumber(5)
	//int outRect = arg.GetNumber(6)
	//pThis->GetEntity()->DrawButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, GetIndentSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, GetIndentSize)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndentSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, GetTabSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bitmap", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "active", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "closeButtonState", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "xExtent", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, GetTabSize)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int bitmap = arg.GetNumber(3)
	//int active = arg.GetNumber(4)
	//int closeButtonState = arg.GetNumber(5)
	//int xExtent = arg.GetNumber(6)
	//pThis->GetEntity()->GetTabSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, ShowDropDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "activeIdx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, ShowDropDown)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wnd = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int activeIdx = arg.GetNumber(2)
	//pThis->GetEntity()->ShowDropDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiSimpleTabArt, GetBestTabCtrlSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "requiredBmpSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, GetBestTabCtrlSize)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wnd = arg.GetNumber(0)
	//int pages = arg.GetNumber(1)
	//int requiredBmpSize = arg.GetNumber(2)
	//pThis->GetEntity()->GetBestTabCtrlSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiSimpleTabArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiSimpleTabArt)
{
	Gura_AssignMethod(wx_AuiSimpleTabArt, wxAuiSimpleTabArt);
	Gura_AssignMethod(wx_AuiSimpleTabArt, Clone);
	Gura_AssignMethod(wx_AuiSimpleTabArt, SetFlags);
	Gura_AssignMethod(wx_AuiSimpleTabArt, SetSizingInfo);
	Gura_AssignMethod(wx_AuiSimpleTabArt, SetNormalFont);
	Gura_AssignMethod(wx_AuiSimpleTabArt, SetSelectedFont);
	Gura_AssignMethod(wx_AuiSimpleTabArt, SetMeasuringFont);
	Gura_AssignMethod(wx_AuiSimpleTabArt, SetColour);
	Gura_AssignMethod(wx_AuiSimpleTabArt, SetActiveColour);
	Gura_AssignMethod(wx_AuiSimpleTabArt, DrawBackground);
	Gura_AssignMethod(wx_AuiSimpleTabArt, DrawTab);
	Gura_AssignMethod(wx_AuiSimpleTabArt, DrawButton);
	Gura_AssignMethod(wx_AuiSimpleTabArt, GetIndentSize);
	Gura_AssignMethod(wx_AuiSimpleTabArt, GetTabSize);
	Gura_AssignMethod(wx_AuiSimpleTabArt, ShowDropDown);
	Gura_AssignMethod(wx_AuiSimpleTabArt, GetBestTabCtrlSize);
}

Gura_ImplementDescendantCreator(wx_AuiSimpleTabArt)
{
	return new Object_wx_AuiSimpleTabArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
