//----------------------------------------------------------------------------
// wxUpdateUIEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxUpdateUIEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxUpdateUIEvent
//----------------------------------------------------------------------------
Object_wx_UpdateUIEvent::~Object_wx_UpdateUIEvent()
{
}

Object *Object_wx_UpdateUIEvent::Clone() const
{
	return nullptr;
}

String Object_wx_UpdateUIEvent::ToString(bool exprFlag)
{
	String rtn("<wx.UpdateUIEvent:");
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
Gura_DeclareFunctionAlias(__UpdateUIEvent, "UpdateUIEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandId", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UpdateUIEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UpdateUIEvent)
{
	//int commandId = arg.GetNumber(0)
	//wxUpdateUIEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_UpdateUIEvent, __CanUpdate, "CanUpdate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __CanUpdate)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->CanUpdate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __Check, "Check")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __Check)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int check = arg.GetNumber(0)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __Enable, "Enable")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __Enable)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetChecked, "GetChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetChecked)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetChecked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetEnabled, "GetEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetEnabled)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetMode, "GetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetMode)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetSetChecked, "GetSetChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetSetChecked)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSetChecked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetSetEnabled, "GetSetEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetSetEnabled)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSetEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetSetShown, "GetSetShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetSetShown)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSetShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetSetText, "GetSetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetSetText)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetShown, "GetShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetShown)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetText)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetUpdateInterval, "GetUpdateInterval")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetUpdateInterval)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetUpdateInterval();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __ResetUpdateTime, "ResetUpdateTime")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __ResetUpdateTime)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ResetUpdateTime();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __SetMode, "SetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __SetMode)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __SetText, "SetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __SetText)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __SetUpdateInterval, "SetUpdateInterval")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "updateInterval", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __SetUpdateInterval)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int updateInterval = arg.GetNumber(0)
	//pThis->GetEntity()->SetUpdateInterval();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __Show)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxUpdateUIEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UpdateUIEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__UpdateUIEvent);
	// Method assignment
	Gura_AssignMethod(wx_UpdateUIEvent, __CanUpdate);
	Gura_AssignMethod(wx_UpdateUIEvent, __Check);
	Gura_AssignMethod(wx_UpdateUIEvent, __Enable);
	Gura_AssignMethod(wx_UpdateUIEvent, __GetChecked);
	Gura_AssignMethod(wx_UpdateUIEvent, __GetEnabled);
	Gura_AssignMethod(wx_UpdateUIEvent, __GetMode);
	Gura_AssignMethod(wx_UpdateUIEvent, __GetSetChecked);
	Gura_AssignMethod(wx_UpdateUIEvent, __GetSetEnabled);
	Gura_AssignMethod(wx_UpdateUIEvent, __GetSetShown);
	Gura_AssignMethod(wx_UpdateUIEvent, __GetSetText);
	Gura_AssignMethod(wx_UpdateUIEvent, __GetShown);
	Gura_AssignMethod(wx_UpdateUIEvent, __GetText);
	Gura_AssignMethod(wx_UpdateUIEvent, __GetUpdateInterval);
	Gura_AssignMethod(wx_UpdateUIEvent, __ResetUpdateTime);
	Gura_AssignMethod(wx_UpdateUIEvent, __SetMode);
	Gura_AssignMethod(wx_UpdateUIEvent, __SetText);
	Gura_AssignMethod(wx_UpdateUIEvent, __SetUpdateInterval);
	Gura_AssignMethod(wx_UpdateUIEvent, __Show);
}

Gura_ImplementDescendantCreator(wx_UpdateUIEvent)
{
	return new Object_wx_UpdateUIEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
