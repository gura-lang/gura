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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_UpdateUIEvent, wxUpdateUIEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, wxUpdateUIEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commandId = arg.GetNumber(0)
	//pThis->GetEntity()->wxUpdateUIEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, CanUpdate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, CanUpdate)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int window = arg.GetNumber(0)
	//pThis->GetEntity()->CanUpdate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, Check)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "check", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, Check)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int check = arg.GetNumber(0)
	//pThis->GetEntity()->Check();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, Enable)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, Enable)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->Enable();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetChecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSetChecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSetEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSetShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetSetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetSetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetShown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetShown)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetShown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, GetUpdateInterval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, GetUpdateInterval)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUpdateInterval();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, ResetUpdateTime)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, ResetUpdateTime)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ResetUpdateTime();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, SetMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, SetMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, SetText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "text", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, SetText)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, SetUpdateInterval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "updateInterval", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, SetUpdateInterval)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int updateInterval = arg.GetNumber(0)
	//pThis->GetEntity()->SetUpdateInterval();
	return Value::Nil;
}

Gura_DeclareMethod(wx_UpdateUIEvent, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxUpdateUIEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UpdateUIEvent)
{
	Gura_AssignMethod(wx_UpdateUIEvent, wxUpdateUIEvent);
	Gura_AssignMethod(wx_UpdateUIEvent, CanUpdate);
	Gura_AssignMethod(wx_UpdateUIEvent, Check);
	Gura_AssignMethod(wx_UpdateUIEvent, Enable);
	Gura_AssignMethod(wx_UpdateUIEvent, GetChecked);
	Gura_AssignMethod(wx_UpdateUIEvent, GetEnabled);
	Gura_AssignMethod(wx_UpdateUIEvent, GetMode);
	Gura_AssignMethod(wx_UpdateUIEvent, GetSetChecked);
	Gura_AssignMethod(wx_UpdateUIEvent, GetSetEnabled);
	Gura_AssignMethod(wx_UpdateUIEvent, GetSetShown);
	Gura_AssignMethod(wx_UpdateUIEvent, GetSetText);
	Gura_AssignMethod(wx_UpdateUIEvent, GetShown);
	Gura_AssignMethod(wx_UpdateUIEvent, GetText);
	Gura_AssignMethod(wx_UpdateUIEvent, GetUpdateInterval);
	Gura_AssignMethod(wx_UpdateUIEvent, ResetUpdateTime);
	Gura_AssignMethod(wx_UpdateUIEvent, SetMode);
	Gura_AssignMethod(wx_UpdateUIEvent, SetText);
	Gura_AssignMethod(wx_UpdateUIEvent, SetUpdateInterval);
	Gura_AssignMethod(wx_UpdateUIEvent, Show);
}

Gura_ImplementDescendantCreator(wx_UpdateUIEvent)
{
	return new Object_wx_UpdateUIEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
