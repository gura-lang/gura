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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_AuiDefaultToolBarArt, wxAuiDefaultToolBarArt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, wxAuiDefaultToolBarArt)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxAuiDefaultToolBarArt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, ~wxAuiDefaultToolBarArt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, ~wxAuiDefaultToolBarArt)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxAuiDefaultToolBarArt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, Clone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, Clone)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Clone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, SetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int font = arg.GetNumber(0)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, GetFont)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, SetTextOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, SetTextOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int orientation = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, GetTextOrientation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, GetTextOrientation)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTextOrientation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, DrawBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, DrawBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, DrawPlainBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, DrawPlainBackground)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawPlainBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, DrawLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, DrawLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, DrawButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, DrawButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, DrawDropDownButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, DrawDropDownButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawDropDownButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, DrawControlLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, DrawControlLabel)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawControlLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, DrawSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, DrawSeparator)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, DrawGripper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, DrawGripper)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//pThis->GetEntity()->DrawGripper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, DrawOverflowButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, DrawOverflowButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int state = arg.GetNumber(3)
	//pThis->GetEntity()->DrawOverflowButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, GetLabelSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, GetLabelSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//pThis->GetEntity()->GetLabelSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, GetToolSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "item", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, GetToolSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int wnd = arg.GetNumber(1)
	//int item = arg.GetNumber(2)
	//pThis->GetEntity()->GetToolSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, GetElementSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "element", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, GetElementSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int element = arg.GetNumber(0)
	//pThis->GetEntity()->GetElementSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, SetElementSize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "element_id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, SetElementSize)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int element_id = arg.GetNumber(0)
	//int size = arg.GetNumber(1)
	//pThis->GetEntity()->SetElementSize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDefaultToolBarArt, ShowDropDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "wnd", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "items", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDefaultToolBarArt, ShowDropDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_AuiDefaultToolBarArt *pThis = Object_wx_AuiDefaultToolBarArt::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, wxAuiDefaultToolBarArt);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, ~wxAuiDefaultToolBarArt);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, Clone);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, SetFlags);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, GetFlags);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, SetFont);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, GetFont);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, SetTextOrientation);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, GetTextOrientation);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, DrawBackground);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, DrawPlainBackground);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, DrawLabel);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, DrawButton);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, DrawDropDownButton);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, DrawControlLabel);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, DrawSeparator);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, DrawGripper);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, DrawOverflowButton);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, GetLabelSize);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, GetToolSize);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, GetElementSize);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, SetElementSize);
	Gura_AssignMethod(wx_AuiDefaultToolBarArt, ShowDropDown);
}

Gura_ImplementDescendantCreator(wx_AuiDefaultToolBarArt)
{
	return new Object_wx_AuiDefaultToolBarArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
