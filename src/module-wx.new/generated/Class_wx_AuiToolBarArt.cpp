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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AuiToolBarArt, wxAuiToolBarArt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarArt, wxAuiToolBarArt)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxAuiToolBarArt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarArt, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarArt, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarArt, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, SetTextOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, SetTextOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, GetTextOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiToolBarArt, GetTextOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, DrawBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, DrawBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, DrawPlainBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, DrawPlainBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawPlainBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, DrawLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, DrawLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, DrawButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, DrawButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, DrawDropDownButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, DrawDropDownButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawDropDownButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, DrawControlLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, DrawControlLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawControlLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, DrawSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, DrawSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, DrawGripper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, DrawGripper)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawGripper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, DrawOverflowButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, DrawOverflowButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int state = arg.GetNumber(3)
	//pThis->GetEntity()->DrawOverflowButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, GetLabelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, GetLabelSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//pThis->GetEntity()->GetLabelSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, GetToolSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, GetToolSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//pThis->GetEntity()->GetToolSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, GetElementSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "element_id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, GetElementSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int element_id = arg.GetNumber(0)
	//pThis->GetEntity()->GetElementSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, SetElementSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "element_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, SetElementSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int element_id = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->SetElementSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiToolBarArt, ShowDropDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiToolBarArt, ShowDropDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiToolBarArt *pThis = Object_wx_AuiToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_AuiToolBarArt, wxAuiToolBarArt);
	Gura_AssignMethod(wx_AuiToolBarArt, Clone);
	Gura_AssignMethod(wx_AuiToolBarArt, SetFlags);
	Gura_AssignMethod(wx_AuiToolBarArt, GetFlags);
	Gura_AssignMethod(wx_AuiToolBarArt, SetFont);
	Gura_AssignMethod(wx_AuiToolBarArt, GetFont);
	Gura_AssignMethod(wx_AuiToolBarArt, SetTextOrientation);
	Gura_AssignMethod(wx_AuiToolBarArt, GetTextOrientation);
	Gura_AssignMethod(wx_AuiToolBarArt, DrawBackground);
	Gura_AssignMethod(wx_AuiToolBarArt, DrawPlainBackground);
	Gura_AssignMethod(wx_AuiToolBarArt, DrawLabel);
	Gura_AssignMethod(wx_AuiToolBarArt, DrawButton);
	Gura_AssignMethod(wx_AuiToolBarArt, DrawDropDownButton);
	Gura_AssignMethod(wx_AuiToolBarArt, DrawControlLabel);
	Gura_AssignMethod(wx_AuiToolBarArt, DrawSeparator);
	Gura_AssignMethod(wx_AuiToolBarArt, DrawGripper);
	Gura_AssignMethod(wx_AuiToolBarArt, DrawOverflowButton);
	Gura_AssignMethod(wx_AuiToolBarArt, GetLabelSize);
	Gura_AssignMethod(wx_AuiToolBarArt, GetToolSize);
	Gura_AssignMethod(wx_AuiToolBarArt, GetElementSize);
	Gura_AssignMethod(wx_AuiToolBarArt, SetElementSize);
	Gura_AssignMethod(wx_AuiToolBarArt, ShowDropDown);
}

Gura_ImplementDescendantCreator(wx_AuiToolBarArt)
{
	return new Object_wx_AuiToolBarArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
