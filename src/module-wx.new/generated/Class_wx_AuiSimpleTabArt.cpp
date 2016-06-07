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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__AuiSimpleTabArt, "AuiSimpleTabArt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiSimpleTabArt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiSimpleTabArt)
{
	//wxAuiSimpleTabArt();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __Clone)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __SetFlags)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __SetSizingInfo, "SetSizingInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tabCtrlSize", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "tabCount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __SetSizingInfo)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxSize& tabCtrlSize = arg.GetNumber(0)
	//size_t tabCount = arg.GetNumber(1)
	//pThis->GetEntity()->SetSizingInfo(tabCtrlSize, tabCount);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __SetNormalFont, "SetNormalFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __SetNormalFont)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetNormalFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __SetSelectedFont, "SetSelectedFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __SetSelectedFont)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelectedFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __SetMeasuringFont, "SetMeasuringFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __SetMeasuringFont)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetMeasuringFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __SetColour, "SetColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __SetColour)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __SetActiveColour, "SetActiveColour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __SetActiveColour)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxColour& colour = arg.GetNumber(0)
	//pThis->GetEntity()->SetActiveColour(colour);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __DrawBackground, "DrawBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __DrawBackground)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBackground(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __DrawTab, "DrawTab")
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

Gura_ImplementMethod(wx_AuiSimpleTabArt, __DrawTab)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxAuiNotebookPage& pane = arg.GetNumber(2)
	//const wxRect& inRect = arg.GetNumber(3)
	//int closeButtonState = arg.GetNumber(4)
	//wxRect* outTabRect = arg.GetNumber(5)
	//wxRect* outButtonRect = arg.GetNumber(6)
	//int* xExtent = arg.GetNumber(7)
	//pThis->GetEntity()->DrawTab(dc, wnd, pane, inRect, closeButtonState, outTabRect, outButtonRect, xExtent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __DrawButton, "DrawButton")
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

Gura_ImplementMethod(wx_AuiSimpleTabArt, __DrawButton)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& inRect = arg.GetNumber(2)
	//int bitmapId = arg.GetNumber(3)
	//int buttonState = arg.GetNumber(4)
	//int orientation = arg.GetNumber(5)
	//wxRect* outRect = arg.GetNumber(6)
	//pThis->GetEntity()->DrawButton(dc, wnd, inRect, bitmapId, buttonState, orientation, outRect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __GetIndentSize, "GetIndentSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __GetIndentSize)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetIndentSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __GetTabSize, "GetTabSize")
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

Gura_ImplementMethod(wx_AuiSimpleTabArt, __GetTabSize)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxString& caption = arg.GetNumber(2)
	//const wxBitmap& bitmap = arg.GetNumber(3)
	//bool active = arg.GetNumber(4)
	//int closeButtonState = arg.GetNumber(5)
	//int* xExtent = arg.GetNumber(6)
	//pThis->GetEntity()->GetTabSize(dc, wnd, caption, bitmap, active, closeButtonState, xExtent);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __ShowDropDown, "ShowDropDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "activeIdx", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __ShowDropDown)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* wnd = arg.GetNumber(0)
	//const wxAuiNotebookPageArray& items = arg.GetNumber(1)
	//int activeIdx = arg.GetNumber(2)
	//pThis->GetEntity()->ShowDropDown(wnd, items, activeIdx);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiSimpleTabArt, __GetBestTabCtrlSize, "GetBestTabCtrlSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pages", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "requiredBmpSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiSimpleTabArt, __GetBestTabCtrlSize)
{
	Object_wx_AuiSimpleTabArt *pThis = Object_wx_AuiSimpleTabArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* wnd = arg.GetNumber(0)
	//const wxAuiNotebookPageArray& pages = arg.GetNumber(1)
	//const wxSize& requiredBmpSize = arg.GetNumber(2)
	//pThis->GetEntity()->GetBestTabCtrlSize(wnd, pages, requiredBmpSize);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiSimpleTabArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiSimpleTabArt)
{
	// Constructor assignment
	Gura_AssignFunction(__AuiSimpleTabArt);
	// Method assignment
	Gura_AssignMethod(wx_AuiSimpleTabArt, __Clone);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __SetFlags);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __SetSizingInfo);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __SetNormalFont);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __SetSelectedFont);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __SetMeasuringFont);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __SetColour);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __SetActiveColour);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __DrawBackground);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __DrawTab);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __DrawButton);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __GetIndentSize);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __GetTabSize);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __ShowDropDown);
	Gura_AssignMethod(wx_AuiSimpleTabArt, __GetBestTabCtrlSize);
}

Gura_ImplementDescendantCreator(wx_AuiSimpleTabArt)
{
	return new Object_wx_AuiSimpleTabArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
