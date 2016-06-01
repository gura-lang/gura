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
Gura_DeclareMethod(wx_JoystickEvent, wxJoystickEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "joystick", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "change", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_JoystickEvent, wxJoystickEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int eventType = arg.GetNumber(0)
	//int state = arg.GetNumber(1)
	//int joystick = arg.GetNumber(2)
	//int change = arg.GetNumber(3)
	//pThis->GetEntity()->wxJoystickEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, ButtonDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_JoystickEvent, ButtonDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, ButtonIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_JoystickEvent, ButtonIsDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonIsDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, ButtonUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "button", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_JoystickEvent, ButtonUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int button = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, GetButtonChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, GetButtonChange)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetButtonChange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, GetButtonState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, GetButtonState)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetButtonState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, GetJoystick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, GetJoystick)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetJoystick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, GetZPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, GetZPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetZPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, IsButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, IsButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, IsMove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, IsMove)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsMove();
	return Value::Nil;
}

Gura_DeclareMethod(wx_JoystickEvent, IsZMove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_JoystickEvent, IsZMove)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsZMove();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxJoystickEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_JoystickEvent)
{
	Gura_AssignMethod(wx_JoystickEvent, wxJoystickEvent);
	Gura_AssignMethod(wx_JoystickEvent, ButtonDown);
	Gura_AssignMethod(wx_JoystickEvent, ButtonIsDown);
	Gura_AssignMethod(wx_JoystickEvent, ButtonUp);
	Gura_AssignMethod(wx_JoystickEvent, GetButtonChange);
	Gura_AssignMethod(wx_JoystickEvent, GetButtonState);
	Gura_AssignMethod(wx_JoystickEvent, GetJoystick);
	Gura_AssignMethod(wx_JoystickEvent, GetPosition);
	Gura_AssignMethod(wx_JoystickEvent, GetZPosition);
	Gura_AssignMethod(wx_JoystickEvent, IsButton);
	Gura_AssignMethod(wx_JoystickEvent, IsMove);
	Gura_AssignMethod(wx_JoystickEvent, IsZMove);
}

Gura_ImplementDescendantCreator(wx_JoystickEvent)
{
	return new Object_wx_JoystickEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
