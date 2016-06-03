//----------------------------------------------------------------------------
// wxJoystickEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxJoystickEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxJoystickEvent
//----------------------------------------------------------------------------
Object_wx_JoystickEvent::~Object_wx_JoystickEvent()
{
}

Object *Object_wx_JoystickEvent::Clone() const
{
	return nullptr;
}

String Object_wx_JoystickEvent::ToString(bool exprFlag)
{
	String rtn("<wx.JoystickEvent:");
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
Gura_DeclareMethodAlias(wx_JoystickEvent, __wxJoystickEvent, "wxJoystickEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "joystick", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "change", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_JoystickEvent, __wxJoystickEvent)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//int joystick = arg.GetNumber(2)
	//int change = arg.GetNumber(3)
	//pThis->GetEntity()->wxJoystickEvent();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __ButtonDown, "ButtonDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_JoystickEvent, __ButtonDown)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __ButtonIsDown, "ButtonIsDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_JoystickEvent, __ButtonIsDown)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonIsDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __ButtonUp, "ButtonUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_JoystickEvent, __ButtonUp)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __GetButtonChange, "GetButtonChange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, __GetButtonChange)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetButtonChange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __GetButtonState, "GetButtonState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, __GetButtonState)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetButtonState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __GetJoystick, "GetJoystick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, __GetJoystick)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetJoystick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, __GetPosition)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __GetZPosition, "GetZPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, __GetZPosition)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetZPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __IsButton, "IsButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, __IsButton)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __IsMove, "IsMove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, __IsMove)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMove();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_JoystickEvent, __IsZMove, "IsZMove")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, __IsZMove)
{
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsZMove();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxJoystickEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_JoystickEvent)
{
	Gura_AssignMethod(wx_JoystickEvent, __wxJoystickEvent);
	Gura_AssignMethod(wx_JoystickEvent, __ButtonDown);
	Gura_AssignMethod(wx_JoystickEvent, __ButtonIsDown);
	Gura_AssignMethod(wx_JoystickEvent, __ButtonUp);
	Gura_AssignMethod(wx_JoystickEvent, __GetButtonChange);
	Gura_AssignMethod(wx_JoystickEvent, __GetButtonState);
	Gura_AssignMethod(wx_JoystickEvent, __GetJoystick);
	Gura_AssignMethod(wx_JoystickEvent, __GetPosition);
	Gura_AssignMethod(wx_JoystickEvent, __GetZPosition);
	Gura_AssignMethod(wx_JoystickEvent, __IsButton);
	Gura_AssignMethod(wx_JoystickEvent, __IsMove);
	Gura_AssignMethod(wx_JoystickEvent, __IsZMove);
}

Gura_ImplementDescendantCreator(wx_JoystickEvent)
{
	return new Object_wx_JoystickEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
