//----------------------------------------------------------------------------
// wxJoystickEvent
// extracted from joyevent.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_JoystickEvent: public wxJoystickEvent, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_JoystickEvent *_pObj;
public:
	inline wx_JoystickEvent(WXTYPE eventType, int state, int joystick, int change) : wxJoystickEvent(eventType, state, joystick, change), _pObj(nullptr) {}
	~wx_JoystickEvent();
	inline void AssocWithGura(Object_wx_JoystickEvent *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_JoystickEvent::~wx_JoystickEvent()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_JoystickEvent::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxJoystickEvent
//----------------------------------------------------------------------------
Gura_DeclareFunction(JoystickEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_JoystickEvent));
	DeclareArg(env, "eventType", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "state", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "joystick", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "change", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(JoystickEvent)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	WXTYPE eventType = 0;
	if (arg.IsValid(0)) eventType = static_cast<WXTYPE>(arg.GetInt(0));
	int state = 0;
	if (arg.IsValid(1)) state = arg.GetInt(1);
	int joystick = wxJOYSTICK1;
	if (arg.IsValid(2)) joystick = arg.GetInt(2);
	int change = 0;
	if (arg.IsValid(3)) change = arg.GetInt(3);
	wx_JoystickEvent *pEntity = new wx_JoystickEvent(eventType, state, joystick, change);
	Object_wx_JoystickEvent *pObj = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_JoystickEvent(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_JoystickEvent, ButtonDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "button", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, ButtonDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int button = wxJOY_BUTTON_ANY;
	if (arg.IsValid(0)) button = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->ButtonDown(button);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_JoystickEvent, ButtonIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "button", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, ButtonIsDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int button = wxJOY_BUTTON_ANY;
	if (arg.IsValid(0)) button = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->ButtonIsDown(button);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_JoystickEvent, ButtonUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "button", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, ButtonUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int button = wxJOY_BUTTON_ANY;
	if (arg.IsValid(0)) button = arg.GetInt(0);
	bool rtn = pThis->GetEntity()->ButtonUp(button);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_JoystickEvent, GetButtonChange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, GetButtonChange)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetButtonChange();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_JoystickEvent, GetButtonState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, GetButtonState)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetButtonState();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_JoystickEvent, GetJoystick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, GetJoystick)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetJoystick();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_JoystickEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxPoint rtn = pThis->GetEntity()->GetPosition();
	return ReturnValue(env, arg, Value(new Object_wx_Point(new wxPoint(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_JoystickEvent, GetZPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, GetZPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetZPosition();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_JoystickEvent, IsButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, IsButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsButton();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_JoystickEvent, IsMove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, IsMove)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsMove();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_JoystickEvent, IsZMove)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_JoystickEvent, IsZMove)
{
	Signal &sig = env.GetSignal();
	Object_wx_JoystickEvent *pThis = Object_wx_JoystickEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsZMove();
	return ReturnValue(env, arg, Value(rtn));
}

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
// Class implementation for wxJoystickEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_JoystickEvent)
{
	Gura_AssignFunction(JoystickEvent);
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
