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
	Gura::Signal _sig;
	Object_wx_Joystick *_pObj;
public:
	inline wx_Joystick(int joystick) : wxJoystick(joystick), _sig(NULL), _pObj(NULL) {}
	~wx_Joystick();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Joystick *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Joystick::~wx_Joystick()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Joystick::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxJoystick
//----------------------------------------------------------------------------
Gura_DeclareFunction(Joystick)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Joystick));
	DeclareArg(env, "joystick", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Joystick)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int joystick = wxJOYSTICK1;
	if (args.IsValid(0)) joystick = args.GetInt(0);
	wx_Joystick *pEntity = new wx_Joystick(joystick);
	Object_wx_Joystick *pObj = Object_wx_Joystick::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Joystick(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Joystick, GetButtonState)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetButtonState)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetButtonState();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetManufacturerId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetManufacturerId)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetManufacturerId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetMovementThreshold)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetMovementThreshold)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMovementThreshold();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetNumberAxes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetNumberAxes)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetNumberAxes();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetNumberButtons)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetNumberButtons)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetNumberButtons();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_Joystick, GetNumberJoysticks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_Joystick, GetNumberJoysticks)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int rtn = wxJoystick::GetNumberJoysticks();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetPollingMax)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetPollingMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPollingMax();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetPollingMin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetPollingMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPollingMin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetProductId)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetProductId)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetProductId();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetProductName)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetProductName)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->GetProductName();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_Joystick, GetPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, sig, args, Value(new Object_wx_Point(new wxPoint(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_Joystick, GetPOVPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetPOVPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPOVPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetPOVCTSPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetPOVCTSPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetPOVCTSPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetRudderMax)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetRudderMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRudderMax();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetRudderMin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetRudderMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRudderMin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetRudderPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetRudderPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetRudderPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetUMax)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetUMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetUMax();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetUMin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetUMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetUMin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetUPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetUPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetUPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetVMax)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetVMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetVMax();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetVMin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetVMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetVMin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetVPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetVPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetVPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetXMax)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetXMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetXMax();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetXMin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetXMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetXMin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetYMax)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetYMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetYMax();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetYMin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetYMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetYMin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetZMax)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetZMax)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetZMax();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetZMin)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetZMin)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetZMin();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, GetZPosition)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, GetZPosition)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetZPosition();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasPOV)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasPOV)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasPOV();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasPOV4Dir)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasPOV4Dir)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasPOV4Dir();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasPOVCTS)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasPOVCTS)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasPOVCTS();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasRudder)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasRudder)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasRudder();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasU)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasU)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasU();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasV)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasV)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasV();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, HasZ)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, HasZ)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->HasZ();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, IsOk)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, ReleaseCapture)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, ReleaseCapture)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->ReleaseCapture();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, SetCapture)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "win", VTYPE_wx_Window, OCCUR_Once);
	DeclareArg(env, "pollingFreq", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Joystick, SetCapture)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxWindow *win = Object_wx_Window::GetObject(args, 0)->GetEntity();
	int pollingFreq = 0;
	if (args.IsValid(1)) pollingFreq = args.GetInt(1);
	bool rtn = pThis->GetEntity()->SetCapture(win, pollingFreq);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Joystick, SetMovementThreshold)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Joystick, SetMovementThreshold)
{
	Object_wx_Joystick *pThis = Object_wx_Joystick::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int threshold = args.GetInt(0);
	pThis->GetEntity()->SetMovementThreshold(threshold);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxJoystick
//----------------------------------------------------------------------------
Object_wx_Joystick::~Object_wx_Joystick()
{
}

Object *Object_wx_Joystick::Clone() const
{
	return NULL;
}

String Object_wx_Joystick::ToString(bool exprFlag)
{
	String rtn("<wx.Joystick:");
	if (GetEntity() == NULL) {
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
	return new Object_wx_Joystick((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
