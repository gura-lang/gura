//----------------------------------------------------------------------------
// wxToolBarToolBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxToolBarToolBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxToolBarToolBase
//----------------------------------------------------------------------------
Object_wx_ToolBarToolBase::~Object_wx_ToolBarToolBase()
{
}

Object *Object_wx_ToolBarToolBase::Clone() const
{
	return nullptr;
}

String Object_wx_ToolBarToolBase::ToString(bool exprFlag)
{
	String rtn("<wx.ToolBarToolBase:");
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
Gura_DeclareMethod(wx_ToolBarToolBase, wxToolBarToolBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tbar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "toolid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpNormal", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bmpDisabled", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shortHelpString", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "longHelpString", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBarToolBase, wxToolBarToolBase)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tbar = arg.GetNumber(0)
	//int toolid = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//int bmpNormal = arg.GetNumber(3)
	//int bmpDisabled = arg.GetNumber(4)
	//int kind = arg.GetNumber(5)
	//int clientData = arg.GetNumber(6)
	//int shortHelpString = arg.GetNumber(7)
	//int longHelpString = arg.GetNumber(8)
	//pThis->GetEntity()->wxToolBarToolBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, wxToolBarToolBase_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tbar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBarToolBase, wxToolBarToolBase_1)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tbar = arg.GetNumber(0)
	//int control = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//pThis->GetEntity()->wxToolBarToolBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetId)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetControl)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetToolBar)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, IsStretchable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, IsStretchable)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsStretchable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, IsButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, IsButton)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, IsControl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, IsControl)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsControl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, IsSeparator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, IsSeparator)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSeparator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, IsStretchableSpace)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, IsStretchableSpace)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsStretchableSpace();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetStyle)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetKind)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, IsEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, IsEnabled)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, IsToggled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, IsToggled)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsToggled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, CanBeToggled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, CanBeToggled)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanBeToggled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetNormalBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetNormalBitmap)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNormalBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetDisabledBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetDisabledBitmap)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetBitmap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetBitmap)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetLabel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetLabel)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetShortHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetShortHelp)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShortHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetLongHelp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetLongHelp)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLongHelp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetClientData)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, Detach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, Detach)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, Attach)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tbar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBarToolBase, Attach)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tbar = arg.GetNumber(0)
	//pThis->GetEntity()->Attach();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ToolBarToolBase, GetDropdownMenu)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, GetDropdownMenu)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDropdownMenu();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxToolBarToolBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ToolBarToolBase)
{
	Gura_AssignMethod(wx_ToolBarToolBase, wxToolBarToolBase);
	Gura_AssignMethod(wx_ToolBarToolBase, wxToolBarToolBase_1);
	Gura_AssignMethod(wx_ToolBarToolBase, GetId);
	Gura_AssignMethod(wx_ToolBarToolBase, GetControl);
	Gura_AssignMethod(wx_ToolBarToolBase, GetToolBar);
	Gura_AssignMethod(wx_ToolBarToolBase, IsStretchable);
	Gura_AssignMethod(wx_ToolBarToolBase, IsButton);
	Gura_AssignMethod(wx_ToolBarToolBase, IsControl);
	Gura_AssignMethod(wx_ToolBarToolBase, IsSeparator);
	Gura_AssignMethod(wx_ToolBarToolBase, IsStretchableSpace);
	Gura_AssignMethod(wx_ToolBarToolBase, GetStyle);
	Gura_AssignMethod(wx_ToolBarToolBase, GetKind);
	Gura_AssignMethod(wx_ToolBarToolBase, IsEnabled);
	Gura_AssignMethod(wx_ToolBarToolBase, IsToggled);
	Gura_AssignMethod(wx_ToolBarToolBase, CanBeToggled);
	Gura_AssignMethod(wx_ToolBarToolBase, GetNormalBitmap);
	Gura_AssignMethod(wx_ToolBarToolBase, GetDisabledBitmap);
	Gura_AssignMethod(wx_ToolBarToolBase, GetBitmap);
	Gura_AssignMethod(wx_ToolBarToolBase, GetLabel);
	Gura_AssignMethod(wx_ToolBarToolBase, GetShortHelp);
	Gura_AssignMethod(wx_ToolBarToolBase, GetLongHelp);
	Gura_AssignMethod(wx_ToolBarToolBase, GetClientData);
	Gura_AssignMethod(wx_ToolBarToolBase, Detach);
	Gura_AssignMethod(wx_ToolBarToolBase, Attach);
	Gura_AssignMethod(wx_ToolBarToolBase, GetDropdownMenu);
}

Gura_ImplementDescendantCreator(wx_ToolBarToolBase)
{
	return new Object_wx_ToolBarToolBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
