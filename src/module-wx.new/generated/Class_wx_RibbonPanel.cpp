//----------------------------------------------------------------------------
// wxRibbonPanel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonPanel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonPanel
//----------------------------------------------------------------------------
Object_wx_RibbonPanel::~Object_wx_RibbonPanel()
{
}

Object *Object_wx_RibbonPanel::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonPanel::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonPanel:");
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
Gura_DeclareMethod(wx_RibbonPanel, wxRibbonPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, wxRibbonPanel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxRibbonPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, wxRibbonPanel_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "minimised_icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPanel, wxRibbonPanel_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int minimised_icon = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->wxRibbonPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPanel, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int icon = arg.GetNumber(3)
	//int pos = arg.GetNumber(4)
	//int size = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, ~wxRibbonPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, ~wxRibbonPanel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRibbonPanel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, GetMinimisedIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, GetMinimisedIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMinimisedIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, GetMinimisedIcon_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, GetMinimisedIcon_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMinimisedIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, HasExtButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, HasExtButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasExtButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, IsMinimised)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, IsMinimised)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsMinimised();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, IsMinimised_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "at_size", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPanel, IsMinimised_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int at_size = arg.GetNumber(0)
	//pThis->GetEntity()->IsMinimised();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, IsHovered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, IsHovered)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsHovered();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, IsExtButtonHovered)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, IsExtButtonHovered)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsExtButtonHovered();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, CanAutoMinimise)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, CanAutoMinimise)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanAutoMinimise();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, ShowExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, ShowExpanded)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShowExpanded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, HideExpanded)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, HideExpanded)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HideExpanded();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, SetArtProvider)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "art", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RibbonPanel, SetArtProvider)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int art = arg.GetNumber(0)
	//pThis->GetEntity()->SetArtProvider();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, Realize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, Realize)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Realize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, GetExpandedDummy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, GetExpandedDummy)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetExpandedDummy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RibbonPanel, GetExpandedPanel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RibbonPanel, GetExpandedPanel)
{
	Signal &sig = env.GetSignal();
	Object_wx_RibbonPanel *pThis = Object_wx_RibbonPanel::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetExpandedPanel();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRibbonPanel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonPanel)
{
	Gura_AssignMethod(wx_RibbonPanel, wxRibbonPanel);
	Gura_AssignMethod(wx_RibbonPanel, wxRibbonPanel_1);
	Gura_AssignMethod(wx_RibbonPanel, Create);
	Gura_AssignMethod(wx_RibbonPanel, ~wxRibbonPanel);
	Gura_AssignMethod(wx_RibbonPanel, GetMinimisedIcon);
	Gura_AssignMethod(wx_RibbonPanel, GetMinimisedIcon_1);
	Gura_AssignMethod(wx_RibbonPanel, HasExtButton);
	Gura_AssignMethod(wx_RibbonPanel, IsMinimised);
	Gura_AssignMethod(wx_RibbonPanel, IsMinimised_1);
	Gura_AssignMethod(wx_RibbonPanel, IsHovered);
	Gura_AssignMethod(wx_RibbonPanel, IsExtButtonHovered);
	Gura_AssignMethod(wx_RibbonPanel, CanAutoMinimise);
	Gura_AssignMethod(wx_RibbonPanel, ShowExpanded);
	Gura_AssignMethod(wx_RibbonPanel, HideExpanded);
	Gura_AssignMethod(wx_RibbonPanel, SetArtProvider);
	Gura_AssignMethod(wx_RibbonPanel, Realize);
	Gura_AssignMethod(wx_RibbonPanel, GetExpandedDummy);
	Gura_AssignMethod(wx_RibbonPanel, GetExpandedPanel);
}

Gura_ImplementDescendantCreator(wx_RibbonPanel)
{
	return new Object_wx_RibbonPanel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
