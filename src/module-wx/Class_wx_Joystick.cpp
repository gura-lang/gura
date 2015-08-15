//----------------------------------------------------------------------------
// wxJoystick
// extracted from joystick.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Joystick: public wxJoystick, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Joystick *_pObj;
public:
	inline wx_Joystick(int joystick) : wxJoystick(joystick), _pObj(nullptr) {}
	~wx_Joystick();
	inline void AssocWithGura(Object_wx_Joystick *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Joystick::~wx_Joystick()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Joystick::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxJoystick
//----------------------------------------------------------------------------
Gura_DeclareFunction(Joystick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Joystick));
	DeclareArg(env, "joystick", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Joystick)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int joystick = wxJOYSTICK1;
	if (args.IsValid(0)) joystick = args.GetInt(0);
	wx_Joystick *pEntity = new wx_Joystick(joystick);
	Object_wx_Joystick *pObj = Object_wx_Joystick::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Joystick(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Joystick, GetButtonState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetButtonState)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetButtonState();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetManufacturerId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetManufacturerId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetManufacturerId();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetMovementThreshold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetMovementThreshold)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMovementThreshold();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetNumberAxes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetNumberAxes)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetNumberAxes();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetNumberButtons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetNumberButtons)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetNumberButtons();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Joystick, GetNumberJoysticks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Joystick, GetNumberJoysticks)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int rtn = wxJoystick::GetNumberJoysticks();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetPollingMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetPollingMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetPollingMax();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetPollingMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetPollingMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetPollingMin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetProductId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetProductId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetProductId();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetProductName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetProductName)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString rtn = pThis->GetEntity()->GetProductName();
	return ReturnValue(env, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Joystick, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, args, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_Joystick, GetPOVPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetPOVPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetPOVPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetPOVCTSPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetPOVCTSPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetPOVCTSPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetRudderMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetRudderMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetRudderMax();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetRudderMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetRudderMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetRudderMin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetRudderPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetRudderPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetRudderPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetUMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetUMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetUMax();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetUMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetUMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetUMin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetUPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetUPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetUPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetVMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetVMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetVMax();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetVMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetVMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetVMin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetVPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetVPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetVPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetXMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetXMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetXMax();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetXMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetXMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetXMin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetYMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetYMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetYMax();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetYMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetYMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetYMin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetZMax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetZMax)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetZMax();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetZMin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetZMin)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetZMin();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetZPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetZPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetZPosition();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasPOV)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasPOV)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasPOV();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasPOV4Dir)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasPOV4Dir)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasPOV4Dir();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasPOVCTS)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasPOVCTS)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasPOVCTS();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasRudder)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasRudder)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasRudder();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasU)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasU)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasU();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasV)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasV)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasV();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasZ)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasZ)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->HasZ();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, ReleaseCapture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, ReleaseCapture)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->ReleaseCapture();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, SetCapture)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pollingFreq", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, SetCapture)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int pollingFreq = 0;
	if (args.IsValid(1)) pollingFreq = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SetCapture(win, pollingFreq);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, SetMovementThreshold)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, SetMovementThreshold)
{
	Signal &sig = env.GetSignal();
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int threshold = args.GetInt(0);
	pThis->GetEntity()->SetMovementThreshold(threshold);
	return Value::Nil;
}

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
// Class implementation for wxJoystick
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Joystick)
{
	Gura_AssignFunction(Joystick);
	Gura_AssignMethod(wx_Joystick, GetButtonState);
	Gura_AssignMethod(wx_Joystick, GetManufacturerId);
	Gura_AssignMethod(wx_Joystick, GetMovementThreshold);
	Gura_AssignMethod(wx_Joystick, GetNumberAxes);
	Gura_AssignMethod(wx_Joystick, GetNumberButtons);
	Gura_AssignMethod(wx_Joystick, GetNumberJoysticks);
	Gura_AssignMethod(wx_Joystick, GetPollingMax);
	Gura_AssignMethod(wx_Joystick, GetPollingMin);
	Gura_AssignMethod(wx_Joystick, GetProductId);
	Gura_AssignMethod(wx_Joystick, GetProductName);
	Gura_AssignMethod(wx_Joystick, GetPosition);
	Gura_AssignMethod(wx_Joystick, GetPOVPosition);
	Gura_AssignMethod(wx_Joystick, GetPOVCTSPosition);
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
