//----------------------------------------------------------------------------
// wxAuiDockArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiDockArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiDockArt
//----------------------------------------------------------------------------
Object_wx_AuiDockArt::~Object_wx_AuiDockArt()
{
}

Object *Object_wx_AuiDockArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiDockArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiDockArt:");
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
Gura_DeclareMethod(wx_AuiDockArt, wxAuiDockArt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AuiDockArt, wxAuiDockArt)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxAuiDockArt();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawBackground)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawBackground)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int orientation = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawBackground();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawBorder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawBorder)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int pane = arg.GetNumber(3)
	//pThis->GetEntity()->DrawBorder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawCaption)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawCaption)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int text = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//int pane = arg.GetNumber(4)
	//pThis->GetEntity()->DrawCaption();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawGripper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawGripper)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int rect = arg.GetNumber(2)
	//int pane = arg.GetNumber(3)
	//pThis->GetEntity()->DrawGripper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawPaneButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "button_state", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pane", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawPaneButton)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int button = arg.GetNumber(2)
	//int button_state = arg.GetNumber(3)
	//int rect = arg.GetNumber(4)
	//int pane = arg.GetNumber(5)
	//pThis->GetEntity()->DrawPaneButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, DrawSash)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "orientation", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rect", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, DrawSash)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//int window = arg.GetNumber(1)
	//int orientation = arg.GetNumber(2)
	//int rect = arg.GetNumber(3)
	//pThis->GetEntity()->DrawSash();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, GetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, GetColour)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, GetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, GetFont)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, GetMetric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, GetMetric)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetMetric();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, SetColour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "colour", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, SetColour)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int colour = arg.GetNumber(1)
	//pThis->GetEntity()->SetColour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, SetFont)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "font", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, SetFont)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int font = arg.GetNumber(1)
	//pThis->GetEntity()->SetFont();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AuiDockArt, SetMetric)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "new_val", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AuiDockArt, SetMetric)
{
	Object_wx_AuiDockArt *pThis = Object_wx_AuiDockArt::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int new_val = arg.GetNumber(1)
	//pThis->GetEntity()->SetMetric();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAuiDockArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiDockArt)
{
	Gura_AssignMethod(wx_AuiDockArt, wxAuiDockArt);
	Gura_AssignMethod(wx_AuiDockArt, DrawBackground);
	Gura_AssignMethod(wx_AuiDockArt, DrawBorder);
	Gura_AssignMethod(wx_AuiDockArt, DrawCaption);
	Gura_AssignMethod(wx_AuiDockArt, DrawGripper);
	Gura_AssignMethod(wx_AuiDockArt, DrawPaneButton);
	Gura_AssignMethod(wx_AuiDockArt, DrawSash);
	Gura_AssignMethod(wx_AuiDockArt, GetColour);
	Gura_AssignMethod(wx_AuiDockArt, GetFont);
	Gura_AssignMethod(wx_AuiDockArt, GetMetric);
	Gura_AssignMethod(wx_AuiDockArt, SetColour);
	Gura_AssignMethod(wx_AuiDockArt, SetFont);
	Gura_AssignMethod(wx_AuiDockArt, SetMetric);
}

Gura_ImplementDescendantCreator(wx_AuiDockArt)
{
	return new Object_wx_AuiDockArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
