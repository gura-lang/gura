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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __Clone)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
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
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetFlags)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
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
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetFont)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
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
	//pThis->GetEntity()->SetTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetTextOrientation, "GetTextOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetTextOrientation)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextOrientation();
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
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBackground();
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
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawPlainBackground();
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
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLabel();
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
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawButton();
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
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawDropDownButton();
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
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawControlLabel();
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
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawSeparator();
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
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawGripper();
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
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int state = arg.GetNumber(3)
	//pThis->GetEntity()->DrawOverflowButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetLabelSize, "GetLabelSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetLabelSize)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//pThis->GetEntity()->GetLabelSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetToolSize, "GetToolSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetToolSize)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//pThis->GetEntity()->GetToolSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __GetElementSize, "GetElementSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "element", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __GetElementSize)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int element = arg.GetNumber(0)
	//pThis->GetEntity()->GetElementSize();
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
	//pThis->GetEntity()->SetElementSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiDefaultToolBarArt, __ShowDropDown, "ShowDropDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, __ShowDropDown)
{
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wnd = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//pThis->GetEntity()->ShowDropDown();
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
