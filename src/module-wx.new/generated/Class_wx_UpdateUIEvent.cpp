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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "commandId", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_UpdateUIEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__UpdateUIEvent)
{
	//wxWindowID commandId = arg.GetNumber(0)
	//wxUpdateUIEvent(commandId);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_UpdateUIEvent, __CanUpdate, "CanUpdate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "window", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __CanUpdate)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* window = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->CanUpdate(window);
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
	//bool check = arg.GetNumber(0)
	//pThis->GetEntity()->Check(check);
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
	//bool enable = arg.GetNumber(0)
	//pThis->GetEntity()->Enable(enable);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetChecked, "GetChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetChecked)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetChecked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetEnabled, "GetEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetEnabled)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetMode, "GetMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetMode)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxUpdateUIMode _rtn = pThis->GetEntity()->GetMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetSetChecked, "GetSetChecked")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetSetChecked)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetSetChecked();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetSetEnabled, "GetSetEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetSetEnabled)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetSetEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetSetShown, "GetSetShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetSetShown)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetSetShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetSetText, "GetSetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetSetText)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetSetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetShown, "GetShown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetShown)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetShown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetText, "GetText")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetText)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetText();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_UpdateUIEvent, __GetUpdateInterval, "GetUpdateInterval")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_UpdateUIEvent, __GetUpdateInterval)
{
	Object_wx_UpdateUIEvent *pThis = Object_wx_UpdateUIEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long _rtn = pThis->GetEntity()->GetUpdateInterval();
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
	//wxUpdateUIMode mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetMode(mode);
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
	//const wxString& text = arg.GetNumber(0)
	//pThis->GetEntity()->SetText(text);
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
	//long updateInterval = arg.GetNumber(0)
	//pThis->GetEntity()->SetUpdateInterval(updateInterval);
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
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->Show(show);
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
