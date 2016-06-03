//----------------------------------------------------------------------------
// wxAuiDefaultTabArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiDefaultTabArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiDefaultTabArt
//----------------------------------------------------------------------------
Object_wx_AuiDefaultTabArt::~Object_wx_AuiDefaultTabArt()
{
}

Object *Object_wx_AuiDefaultTabArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiDefaultTabArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiDefaultTabArt:");
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
Gura_DeclareFunctionAlias(__wxAuiDefaultTabArt, "wxAuiDefaultTabArt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiDefaultTabArt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxAuiDefaultTabArt)
{
	//wxAuiDefaultTabArt();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __Clone)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __SetFlags)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __SetSizingInfo, "SetSizingInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabCtrlSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tabCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __SetSizingInfo)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tabCtrlSize = arg.GetNumber(0)
	//int tabCount = arg.GetNumber(1)
	//pThis->GetEntity()->SetSizingInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __SetNormalFont, "SetNormalFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __SetNormalFont)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __SetSelectedFont, "SetSelectedFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __SetSelectedFont)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __SetMeasuringFont, "SetMeasuringFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __SetMeasuringFont)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetMeasuringFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __SetColour)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __SetActiveColour, "SetActiveColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __SetActiveColour)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetActiveColour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __DrawBackground, "DrawBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __DrawBackground)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __DrawTab, "DrawTab")
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

Gura_ImplementMethod(wx_AuiDefaultTabArt, __DrawTab)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __DrawButton, "DrawButton")
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

Gura_ImplementMethod(wx_AuiDefaultTabArt, __DrawButton)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __GetIndentSize, "GetIndentSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __GetIndentSize)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndentSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __GetTabSize, "GetTabSize")
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

Gura_ImplementMethod(wx_AuiDefaultTabArt, __GetTabSize)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
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

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __ShowDropDown, "ShowDropDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "activeIdx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __ShowDropDown)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wnd = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//int activeIdx = arg.GetNumber(2)
	//pThis->GetEntity()->ShowDropDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultTabArt, __GetBestTabCtrlSize, "GetBestTabCtrlSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "requiredBmpSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultTabArt, __GetBestTabCtrlSize)
{
	Object_wx_AuiDefaultTabArt *pThis = Object_wx_AuiDefaultTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wnd = arg.GetNumber(0)
	//int pages = arg.GetNumber(1)
	//int requiredBmpSize = arg.GetNumber(2)
	//pThis->GetEntity()->GetBestTabCtrlSize();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiDefaultTabArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiDefaultTabArt)
{
	// Constructor assignment
	Gura_AssignFunction(__wxAuiDefaultTabArt);
	// Method assignment
	Gura_AssignMethod(wx_AuiDefaultTabArt, __Clone);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __SetFlags);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __SetSizingInfo);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __SetNormalFont);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __SetSelectedFont);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __SetMeasuringFont);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __SetColour);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __SetActiveColour);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __DrawBackground);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __DrawTab);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __DrawButton);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __GetIndentSize);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __GetTabSize);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __ShowDropDown);
	Gura_AssignMethod(wx_AuiDefaultTabArt, __GetBestTabCtrlSize);
}

Gura_ImplementDescendantCreator(wx_AuiDefaultTabArt)
{
	return new Object_wx_AuiDefaultTabArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
