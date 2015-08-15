//----------------------------------------------------------------------------
// wxTimer
// extracted from timer.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Timer: public wxTimer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Timer *_pObj;
public:
	inline wx_Timer() : wxTimer(), _pObj(nullptr) {}
	inline wx_Timer(wxEvtHandler * owner, int id) : wxTimer(owner, id), _pObj(nullptr) {}
	~wx_Timer();
	inline void AssocWithGura(Object_wx_Timer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Timer::~wx_Timer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Timer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTimer
//----------------------------------------------------------------------------
Gura_DeclareFunction(TimerEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Timer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TimerEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Timer *pEntity = new wx_Timer();
	Object_wx_Timer *pObj = Object_wx_Timer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Timer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareFunction(Timer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Timer));
	DeclareArg(env, "owner", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Timer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxEvtHandler *owner = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	int id = -1;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_Timer *pEntity = new wx_Timer(owner, id);
	Object_wx_Timer *pObj = Object_wx_Timer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Timer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_Timer, GetInterval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Timer, GetInterval)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetInterval();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Timer, IsOneShot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Timer, IsOneShot)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOneShot();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Timer, IsRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Timer, IsRunning)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsRunning();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Timer, Notify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, Notify)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Notify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, SetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "owner", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Timer, SetOwner)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvtHandler *owner = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	int id = -1;
	if (args.IsValid(1)) id = args.GetInt(1);
	pThis->GetEntity()->SetOwner(owner, id);
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, Start)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "oneShot", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Timer, Start)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int milliseconds = -1;
	if (args.IsValid(0)) milliseconds = args.GetInt(0);
	bool oneShot = false;
	if (args.IsValid(1)) oneShot = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Start(milliseconds, oneShot);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_Timer, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, Stop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Stop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxTimer
//----------------------------------------------------------------------------
Object_wx_Timer::~Object_wx_Timer()
{
}

Object *Object_wx_Timer::Clone() const
{
	return nullptr;
}

String Object_wx_Timer::ToString(bool exprFlag)
{
	String rtn("<wx.Timer:");
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
// Class implementation for wxTimer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Timer)
{
	Gura_AssignFunction(TimerEmpty);
	Gura_AssignFunction(Timer);
	Gura_AssignMethod(wx_Timer, GetInterval);
	Gura_AssignMethod(wx_Timer, IsOneShot);
	Gura_AssignMethod(wx_Timer, IsRunning);
	Gura_AssignMethod(wx_Timer, Notify);
	Gura_AssignMethod(wx_Timer, SetOwner);
	Gura_AssignMethod(wx_Timer, Start);
	Gura_AssignMethod(wx_Timer, Stop);
}

Gura_ImplementDescendantCreator(wx_Timer)
{
	return new Object_wx_Timer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
