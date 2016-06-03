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
Gura_DeclareMethodAlias(wx_ToolBarToolBase, __wxToolBarToolBase, "wxToolBarToolBase")
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

Gura_ImplementMethod(wx_ToolBarToolBase, __wxToolBarToolBase)
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

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __wxToolBarToolBase_1, "wxToolBarToolBase_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tbar", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "control", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "label", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __wxToolBarToolBase_1)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tbar = arg.GetNumber(0)
	//int control = arg.GetNumber(1)
	//int label = arg.GetNumber(2)
	//pThis->GetEntity()->wxToolBarToolBase();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetId, "GetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetId)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetControl, "GetControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetControl)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetToolBar, "GetToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetToolBar)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __IsStretchable, "IsStretchable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __IsStretchable)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsStretchable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __IsButton, "IsButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __IsButton)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __IsControl, "IsControl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __IsControl)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsControl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __IsSeparator, "IsSeparator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __IsSeparator)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsSeparator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __IsStretchableSpace, "IsStretchableSpace")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __IsStretchableSpace)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsStretchableSpace();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetStyle, "GetStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetStyle)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetKind, "GetKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetKind)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __IsEnabled, "IsEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __IsEnabled)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __IsToggled, "IsToggled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __IsToggled)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsToggled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __CanBeToggled, "CanBeToggled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __CanBeToggled)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanBeToggled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetNormalBitmap, "GetNormalBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetNormalBitmap)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetNormalBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetDisabledBitmap, "GetDisabledBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetDisabledBitmap)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDisabledBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetBitmap, "GetBitmap")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetBitmap)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetBitmap();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetLabel, "GetLabel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetLabel)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLabel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetShortHelp, "GetShortHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetShortHelp)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShortHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetLongHelp, "GetLongHelp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetLongHelp)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLongHelp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetClientData, "GetClientData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetClientData)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __Detach, "Detach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __Detach)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Detach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __Attach, "Attach")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "tbar", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __Attach)
{
	Object_wx_ToolBarToolBase *pThis = Object_wx_ToolBarToolBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int tbar = arg.GetNumber(0)
	//pThis->GetEntity()->Attach();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_ToolBarToolBase, __GetDropdownMenu, "GetDropdownMenu")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ToolBarToolBase, __GetDropdownMenu)
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
	Gura_AssignMethod(wx_ToolBarToolBase, __wxToolBarToolBase);
	Gura_AssignMethod(wx_ToolBarToolBase, __wxToolBarToolBase_1);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetId);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetControl);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetToolBar);
	Gura_AssignMethod(wx_ToolBarToolBase, __IsStretchable);
	Gura_AssignMethod(wx_ToolBarToolBase, __IsButton);
	Gura_AssignMethod(wx_ToolBarToolBase, __IsControl);
	Gura_AssignMethod(wx_ToolBarToolBase, __IsSeparator);
	Gura_AssignMethod(wx_ToolBarToolBase, __IsStretchableSpace);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetStyle);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetKind);
	Gura_AssignMethod(wx_ToolBarToolBase, __IsEnabled);
	Gura_AssignMethod(wx_ToolBarToolBase, __IsToggled);
	Gura_AssignMethod(wx_ToolBarToolBase, __CanBeToggled);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetNormalBitmap);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetDisabledBitmap);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetBitmap);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetLabel);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetShortHelp);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetLongHelp);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetClientData);
	Gura_AssignMethod(wx_ToolBarToolBase, __Detach);
	Gura_AssignMethod(wx_ToolBarToolBase, __Attach);
	Gura_AssignMethod(wx_ToolBarToolBase, __GetDropdownMenu);
}

Gura_ImplementDescendantCreator(wx_ToolBarToolBase)
{
	return new Object_wx_ToolBarToolBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
