//----------------------------------------------------------------------------
// wxJoystick
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxJoystick
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxJoystick
//----------------------------------------------------------------------------
Object_wx_Joystick::~Object_wx_Joystick()
{
}

Object *Object_wx_Joystick::Clone() const
{
	return nullptr;
}

String Object_wx_Joystick::ToString(bool exprFlag)
{
	String rtn("<wx.Joystick:");
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
Gura_DeclareMethod(wx_Joystick, wxJoystick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "joystick", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, wxJoystick)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int joystick = arg.GetNumber(0)
	//pThis->GetEntity()->wxJoystick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, ~wxJoystick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, ~wxJoystick)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxJoystick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetButtonState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetButtonState)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetButtonState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetButtonState_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, GetButtonState_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->GetButtonState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetManufacturerId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetManufacturerId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetManufacturerId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetMovementThreshold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetMovementThreshold)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMovementThreshold();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetNumberAxes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetNumberAxes)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNumberAxes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetNumberButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetNumberButtons)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNumberButtons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetNumberJoysticks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetNumberJoysticks)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetNumberJoysticks();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetPOVCTSPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetPOVCTSPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPOVCTSPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetPOVPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetPOVPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPOVPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetPollingMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetPollingMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPollingMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetPollingMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetPollingMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPollingMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "axis", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, GetPosition_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int axis = arg.GetNumber(0)
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetProductId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetProductId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProductId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetProductName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetProductName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetProductName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetRudderMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetRudderMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRudderMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetRudderMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetRudderMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRudderMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetRudderPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetRudderPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRudderPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetUMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetUMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetUMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetUMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetUPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetUPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetUPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetVMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetVMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetVMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetVMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetVPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetVPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetVPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetXMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetXMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetXMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetXMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetXMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetXMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetYMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetYMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetYMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetYMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetYMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetYMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetZMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetZMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetZMax();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetZMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetZMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetZMin();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, GetZPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, GetZPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetZPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, HasPOV)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, HasPOV)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasPOV();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, HasPOV4Dir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, HasPOV4Dir)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasPOV4Dir();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, HasPOVCTS)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, HasPOVCTS)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasPOVCTS();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, HasRudder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, HasRudder)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasRudder();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, HasU)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, HasU)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasU();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, HasV)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, HasV)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasV();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, HasZ)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, HasZ)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasZ();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, ReleaseCapture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, ReleaseCapture)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ReleaseCapture();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, SetCapture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pollingFreq", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, SetCapture)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int win = arg.GetNumber(0)
	//int pollingFreq = arg.GetNumber(1)
	//pThis->GetEntity()->SetCapture();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Joystick, SetMovementThreshold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, SetMovementThreshold)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int threshold = arg.GetNumber(0)
	//pThis->GetEntity()->SetMovementThreshold();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxJoystick
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Joystick)
{
	Gura_AssignMethod(wx_Joystick, wxJoystick);
	Gura_AssignMethod(wx_Joystick, ~wxJoystick);
	Gura_AssignMethod(wx_Joystick, GetButtonState);
	Gura_AssignMethod(wx_Joystick, GetButtonState_1);
	Gura_AssignMethod(wx_Joystick, GetManufacturerId);
	Gura_AssignMethod(wx_Joystick, GetMovementThreshold);
	Gura_AssignMethod(wx_Joystick, GetNumberAxes);
	Gura_AssignMethod(wx_Joystick, GetNumberButtons);
	Gura_AssignMethod(wx_Joystick, GetNumberJoysticks);
	Gura_AssignMethod(wx_Joystick, GetPOVCTSPosition);
	Gura_AssignMethod(wx_Joystick, GetPOVPosition);
	Gura_AssignMethod(wx_Joystick, GetPollingMax);
	Gura_AssignMethod(wx_Joystick, GetPollingMin);
	Gura_AssignMethod(wx_Joystick, GetPosition);
	Gura_AssignMethod(wx_Joystick, GetPosition_1);
	Gura_AssignMethod(wx_Joystick, GetProductId);
	Gura_AssignMethod(wx_Joystick, GetProductName);
	Gura_AssignMethod(wx_Joystick, GetRudderMax);
	Gura_AssignMethod(wx_Joystick, GetRudderMin);
	Gura_AssignMethod(wx_Joystick, GetRudderPosition);
	Gura_AssignMethod(wx_Joystick, GetUMax);
	Gura_AssignMethod(wx_Joystick, GetUMin);
	Gura_AssignMethod(wx_Joystick, GetUPosition);
	Gura_AssignMethod(wx_Joystick, GetVMax);
	Gura_AssignMethod(wx_Joystick, GetVMin);
	Gura_AssignMethod(wx_Joystick, GetVPosition);
	Gura_AssignMethod(wx_Joystick, GetXMax);
	Gura_AssignMethod(wx_Joystick, GetXMin);
	Gura_AssignMethod(wx_Joystick, GetYMax);
	Gura_AssignMethod(wx_Joystick, GetYMin);
	Gura_AssignMethod(wx_Joystick, GetZMax);
	Gura_AssignMethod(wx_Joystick, GetZMin);
	Gura_AssignMethod(wx_Joystick, GetZPosition);
	Gura_AssignMethod(wx_Joystick, HasPOV);
	Gura_AssignMethod(wx_Joystick, HasPOV4Dir);
	Gura_AssignMethod(wx_Joystick, HasPOVCTS);
	Gura_AssignMethod(wx_Joystick, HasRudder);
	Gura_AssignMethod(wx_Joystick, HasU);
	Gura_AssignMethod(wx_Joystick, HasV);
	Gura_AssignMethod(wx_Joystick, HasZ);
	Gura_AssignMethod(wx_Joystick, IsOk);
	Gura_AssignMethod(wx_Joystick, ReleaseCapture);
	Gura_AssignMethod(wx_Joystick, SetCapture);
	Gura_AssignMethod(wx_Joystick, SetMovementThreshold);
}

Gura_ImplementDescendantCreator(wx_Joystick)
{
	return new Object_wx_Joystick((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
