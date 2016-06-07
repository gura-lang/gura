//----------------------------------------------------------------------------
// wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------
Object_wx_AuiDefaultToolBarArt::~Object_wx_AuiDefaultToolBarArt()
{
}

Object *Object_wx_AuiDefaultToolBarArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiDefaultToolBarArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiDefaultToolBarArt:");
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
Gura_DeclareFunctionAlias(__AuiDefaultToolBarArt, "AuiDefaultToolBarArt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiDefaultToolBarArt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AuiDefaultToolBarArt)
{
	//wxAuiDefaultToolBarArt();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __Clone)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAuiToolBarArt* _rtn = pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __SetFlags)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetFlags)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int _rtn = pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __SetFont)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxFont& font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont(font);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetFont)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxFont _rtn = pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __SetTextOrientation, "SetTextOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __SetTextOrientation)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextOrientation(orientation);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetTextOrientation, "GetTextOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetTextOrientation)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __DrawBackground, "DrawBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __DrawBackground)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBackground(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __DrawPlainBackground, "DrawPlainBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __DrawPlainBackground)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawPlainBackground(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __DrawLabel, "DrawLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __DrawLabel)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxAuiToolBarItem& item = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLabel(dc, wnd, item, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __DrawButton, "DrawButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __DrawButton)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxAuiToolBarItem& item = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawButton(dc, wnd, item, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __DrawDropDownButton, "DrawDropDownButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __DrawDropDownButton)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxAuiToolBarItem& item = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawDropDownButton(dc, wnd, item, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __DrawControlLabel, "DrawControlLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __DrawControlLabel)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxAuiToolBarItem& item = arg.GetNumber(2)
	//const wxRect& rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawControlLabel(dc, wnd, item, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __DrawSeparator, "DrawSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __DrawSeparator)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawSeparator(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __DrawGripper, "DrawGripper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __DrawGripper)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawGripper(dc, wnd, rect);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __DrawOverflowButton, "DrawOverflowButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __DrawOverflowButton)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxRect& rect = arg.GetNumber(2)
	//int state = arg.GetNumber(3)
	//pThis->GetEntity()->DrawOverflowButton(dc, wnd, rect, state);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetLabelSize, "GetLabelSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetLabelSize)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxAuiToolBarItem& item = arg.GetNumber(2)
	//wxSize _rtn = pThis->GetEntity()->GetLabelSize(dc, wnd, item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetToolSize, "GetToolSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetToolSize)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDC& dc = arg.GetNumber(0)
	//wxWindow* wnd = arg.GetNumber(1)
	//const wxAuiToolBarItem& item = arg.GetNumber(2)
	//wxSize _rtn = pThis->GetEntity()->GetToolSize(dc, wnd, item);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetElementSize, "GetElementSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "element", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetElementSize)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int element = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetElementSize(element);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __SetElementSize, "SetElementSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "element_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __SetElementSize)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int element_id = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->SetElementSize(element_id, size);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __ShowDropDown, "ShowDropDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __ShowDropDown)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* wnd = arg.GetNumber(0)
	//const wxAuiToolBarItemArray& items = arg.GetNumber(1)
	//int _rtn = pThis->GetEntity()->ShowDropDown(wnd, items);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiDefaultToolBarArt)
{
	// Constructor assignment
	Gura_AssignFunction(__AuiDefaultToolBarArt);
	// Method assignment
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __Clone);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __SetFlags);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __GetFlags);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __SetFont);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __GetFont);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __SetTextOrientation);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __GetTextOrientation);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __DrawBackground);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __DrawPlainBackground);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __DrawLabel);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __DrawButton);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __DrawDropDownButton);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __DrawControlLabel);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __DrawSeparator);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __DrawGripper);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __DrawOverflowButton);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __GetLabelSize);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __GetToolSize);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __GetElementSize);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __SetElementSize);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, __ShowDropDown);
}

Gura_ImplementDescendantCreator(wx_AuiDefaultToolBarArt)
{
	return new Object_wx_AuiDefaultToolBarArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
