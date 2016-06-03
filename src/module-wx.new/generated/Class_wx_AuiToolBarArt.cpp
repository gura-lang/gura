//----------------------------------------------------------------------------
// wxAuiToolBarArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiToolBarArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiToolBarArt
//----------------------------------------------------------------------------
Object_wx_AuiToolBarArt::~Object_wx_AuiToolBarArt()
{
}

Object *Object_wx_AuiToolBarArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiToolBarArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiToolBarArt:");
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
Gura_DeclareFunctionAlias(__wxAuiToolBarArt, "wxAuiToolBarArt")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_AuiToolBarArt));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxAuiToolBarArt)
{
	//wxAuiToolBarArt();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AuiToolBarArt, __Clone, "Clone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __Clone)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __SetFlags)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __GetFlags)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __SetFont, "SetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __SetFont)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __GetFont, "GetFont")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __GetFont)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __SetTextOrientation, "SetTextOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __SetTextOrientation)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __GetTextOrientation, "GetTextOrientation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __GetTextOrientation)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __DrawBackground, "DrawBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __DrawBackground)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __DrawPlainBackground, "DrawPlainBackground")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __DrawPlainBackground)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawPlainBackground();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __DrawLabel, "DrawLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __DrawLabel)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __DrawButton, "DrawButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __DrawButton)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __DrawDropDownButton, "DrawDropDownButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __DrawDropDownButton)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawDropDownButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __DrawControlLabel, "DrawControlLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __DrawControlLabel)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawControlLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __DrawSeparator, "DrawSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __DrawSeparator)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __DrawGripper, "DrawGripper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __DrawGripper)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawGripper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __DrawOverflowButton, "DrawOverflowButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __DrawOverflowButton)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int state = arg.GetNumber(3)
	//pThis->GetEntity()->DrawOverflowButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __GetLabelSize, "GetLabelSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __GetLabelSize)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//pThis->GetEntity()->GetLabelSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __GetToolSize, "GetToolSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __GetToolSize)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//pThis->GetEntity()->GetToolSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __GetElementSize, "GetElementSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "element_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __GetElementSize)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int element_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetElementSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __SetElementSize, "SetElementSize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "element_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __SetElementSize)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int element_id = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->SetElementSize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AuiToolBarArt, __ShowDropDown, "ShowDropDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, __ShowDropDown)
{
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int wnd = arg.GetNumber(0)
	//int items = arg.GetNumber(1)
	//pThis->GetEntity()->ShowDropDown();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiToolBarArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiToolBarArt)
{
	// Constructor assignment
	Gura_AssignFunction(__wxAuiToolBarArt);
	// Method assignment
	Gura_AssignMethod(wx_AuiToolBarArt, __Clone);
	Gura_AssignMethod(wx_AuiToolBarArt, __SetFlags);
	Gura_AssignMethod(wx_AuiToolBarArt, __GetFlags);
	Gura_AssignMethod(wx_AuiToolBarArt, __SetFont);
	Gura_AssignMethod(wx_AuiToolBarArt, __GetFont);
	Gura_AssignMethod(wx_AuiToolBarArt, __SetTextOrientation);
	Gura_AssignMethod(wx_AuiToolBarArt, __GetTextOrientation);
	Gura_AssignMethod(wx_AuiToolBarArt, __DrawBackground);
	Gura_AssignMethod(wx_AuiToolBarArt, __DrawPlainBackground);
	Gura_AssignMethod(wx_AuiToolBarArt, __DrawLabel);
	Gura_AssignMethod(wx_AuiToolBarArt, __DrawButton);
	Gura_AssignMethod(wx_AuiToolBarArt, __DrawDropDownButton);
	Gura_AssignMethod(wx_AuiToolBarArt, __DrawControlLabel);
	Gura_AssignMethod(wx_AuiToolBarArt, __DrawSeparator);
	Gura_AssignMethod(wx_AuiToolBarArt, __DrawGripper);
	Gura_AssignMethod(wx_AuiToolBarArt, __DrawOverflowButton);
	Gura_AssignMethod(wx_AuiToolBarArt, __GetLabelSize);
	Gura_AssignMethod(wx_AuiToolBarArt, __GetToolSize);
	Gura_AssignMethod(wx_AuiToolBarArt, __GetElementSize);
	Gura_AssignMethod(wx_AuiToolBarArt, __SetElementSize);
	Gura_AssignMethod(wx_AuiToolBarArt, __ShowDropDown);
}

Gura_ImplementDescendantCreator(wx_AuiToolBarArt)
{
	return new Object_wx_AuiToolBarArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
