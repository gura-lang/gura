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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Joystick, "Joystick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "joystick", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Joystick));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Joystick)
{
	//int joystick = arg.GetNumber(0)
	//wxJoystick(joystick);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Joystick, __GetButtonState, "GetButtonState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetButtonState)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetButtonState();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetButtonState_1, "GetButtonState_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, __GetButtonState_1)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int id = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->GetButtonState(id);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetManufacturerId, "GetManufacturerId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetManufacturerId)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetManufacturerId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetMovementThreshold, "GetMovementThreshold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetMovementThreshold)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetMovementThreshold();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetNumberAxes, "GetNumberAxes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetNumberAxes)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetNumberAxes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetNumberButtons, "GetNumberButtons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetNumberButtons)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetNumberButtons();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetNumberJoysticks, "GetNumberJoysticks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetNumberJoysticks)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetNumberJoysticks();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetPOVCTSPosition, "GetPOVCTSPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetPOVCTSPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetPOVCTSPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetPOVPosition, "GetPOVPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetPOVPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetPOVPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetPollingMax, "GetPollingMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetPollingMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetPollingMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetPollingMin, "GetPollingMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetPollingMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetPollingMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint _rtn = pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetPosition_1, "GetPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "axis", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, __GetPosition_1)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int axis = arg.GetNumber(0)
	//int _rtn = pThis->GetEntity()->GetPosition(axis);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetProductId, "GetProductId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetProductId)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetProductId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetProductName, "GetProductName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetProductName)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetProductName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetRudderMax, "GetRudderMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetRudderMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetRudderMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetRudderMin, "GetRudderMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetRudderMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetRudderMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetRudderPosition, "GetRudderPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetRudderPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetRudderPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetUMax, "GetUMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetUMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetUMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetUMin, "GetUMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetUMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetUMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetUPosition, "GetUPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetUPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetUPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetVMax, "GetVMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetVMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetVMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetVMin, "GetVMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetVMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetVMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetVPosition, "GetVPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetVPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetVPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetXMax, "GetXMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetXMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetXMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetXMin, "GetXMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetXMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetXMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetYMax, "GetYMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetYMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetYMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetYMin, "GetYMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetYMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetYMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetZMax, "GetZMax")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetZMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetZMax();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetZMin, "GetZMin")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetZMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetZMin();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __GetZPosition, "GetZPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __GetZPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetZPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __HasPOV, "HasPOV")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __HasPOV)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasPOV();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __HasPOV4Dir, "HasPOV4Dir")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __HasPOV4Dir)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasPOV4Dir();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __HasPOVCTS, "HasPOVCTS")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __HasPOVCTS)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasPOVCTS();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __HasRudder, "HasRudder")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __HasRudder)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasRudder();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __HasU, "HasU")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __HasU)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasU();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __HasV, "HasV")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __HasV)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasV();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __HasZ, "HasZ")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __HasZ)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->HasZ();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __IsOk)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __ReleaseCapture, "ReleaseCapture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Joystick, __ReleaseCapture)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->ReleaseCapture();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __SetCapture, "SetCapture")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "win", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pollingFreq", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, __SetCapture)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* win = arg.GetNumber(0)
	//int pollingFreq = arg.GetNumber(1)
	//bool _rtn = pThis->GetEntity()->SetCapture(win, pollingFreq);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Joystick, __SetMovementThreshold, "SetMovementThreshold")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, __SetMovementThreshold)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int threshold = arg.GetNumber(0)
	//pThis->GetEntity()->SetMovementThreshold(threshold);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxJoystick
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Joystick)
{
	// Constructor assignment
	Gura_AssignFunction(__Joystick);
	// Method assignment
	Gura_AssignMethod(wx_Joystick, __GetButtonState);
	Gura_AssignMethod(wx_Joystick, __GetButtonState_1);
	Gura_AssignMethod(wx_Joystick, __GetManufacturerId);
	Gura_AssignMethod(wx_Joystick, __GetMovementThreshold);
	Gura_AssignMethod(wx_Joystick, __GetNumberAxes);
	Gura_AssignMethod(wx_Joystick, __GetNumberButtons);
	Gura_AssignMethod(wx_Joystick, __GetNumberJoysticks);
	Gura_AssignMethod(wx_Joystick, __GetPOVCTSPosition);
	Gura_AssignMethod(wx_Joystick, __GetPOVPosition);
	Gura_AssignMethod(wx_Joystick, __GetPollingMax);
	Gura_AssignMethod(wx_Joystick, __GetPollingMin);
	Gura_AssignMethod(wx_Joystick, __GetPosition);
	Gura_AssignMethod(wx_Joystick, __GetPosition_1);
	Gura_AssignMethod(wx_Joystick, __GetProductId);
	Gura_AssignMethod(wx_Joystick, __GetProductName);
	Gura_AssignMethod(wx_Joystick, __GetRudderMax);
	Gura_AssignMethod(wx_Joystick, __GetRudderMin);
	Gura_AssignMethod(wx_Joystick, __GetRudderPosition);
	Gura_AssignMethod(wx_Joystick, __GetUMax);
	Gura_AssignMethod(wx_Joystick, __GetUMin);
	Gura_AssignMethod(wx_Joystick, __GetUPosition);
	Gura_AssignMethod(wx_Joystick, __GetVMax);
	Gura_AssignMethod(wx_Joystick, __GetVMin);
	Gura_AssignMethod(wx_Joystick, __GetVPosition);
	Gura_AssignMethod(wx_Joystick, __GetXMax);
	Gura_AssignMethod(wx_Joystick, __GetXMin);
	Gura_AssignMethod(wx_Joystick, __GetYMax);
	Gura_AssignMethod(wx_Joystick, __GetYMin);
	Gura_AssignMethod(wx_Joystick, __GetZMax);
	Gura_AssignMethod(wx_Joystick, __GetZMin);
	Gura_AssignMethod(wx_Joystick, __GetZPosition);
	Gura_AssignMethod(wx_Joystick, __HasPOV);
	Gura_AssignMethod(wx_Joystick, __HasPOV4Dir);
	Gura_AssignMethod(wx_Joystick, __HasPOVCTS);
	Gura_AssignMethod(wx_Joystick, __HasRudder);
	Gura_AssignMethod(wx_Joystick, __HasU);
	Gura_AssignMethod(wx_Joystick, __HasV);
	Gura_AssignMethod(wx_Joystick, __HasZ);
	Gura_AssignMethod(wx_Joystick, __IsOk);
	Gura_AssignMethod(wx_Joystick, __ReleaseCapture);
	Gura_AssignMethod(wx_Joystick, __SetCapture);
	Gura_AssignMethod(wx_Joystick, __SetMovementThreshold);
}

Gura_ImplementDescendantCreator(wx_Joystick)
{
	return new Object_wx_Joystick((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
