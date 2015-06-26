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
	Gura::Signal _sig;
	Object_wx_Timer *_pObj;
public:
	inline wx_Timer() : wxTimer(), _sig(nullptr), _pObj(nullptr) {}
	inline wx_Timer(wxEvtHandler * owner, int id) : wxTimer(owner, id), _sig(nullptr), _pObj(nullptr) {}
	~wx_Timer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Timer *pObj) {
		_sig = sig, _pObj = pObj;
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
	if (!CheckWxReady(sig)) return Value::Null;
	wx_Timer *pEntity = new wx_Timer();
	Object_wx_Timer *pObj = Object_wx_Timer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Timer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
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
	if (!CheckWxReady(sig)) return Value::Null;
	wxEvtHandler *owner = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	int id = -1;
	if (args.IsValid(1)) id = args.GetInt(1);
	wx_Timer *pEntity = new wx_Timer(owner, id);
	Object_wx_Timer *pObj = Object_wx_Timer::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Timer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Timer, GetInterval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Timer, GetInterval)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetInterval();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Timer, IsOneShot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Timer, IsOneShot)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOneShot();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Timer, IsRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Timer, IsRunning)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsRunning();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Timer, Notify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, Notify)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Notify();
	return Value::Null;
}

Gura_DeclareMethod(wx_Timer, SetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "owner", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Timer, SetOwner)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *owner = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	int id = -1;
	if (args.IsValid(1)) id = args.GetInt(1);
	pThis->GetEntity()->SetOwner(owner, id);
	return Value::Null;
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
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int milliseconds = -1;
	if (args.IsValid(0)) milliseconds = args.GetInt(0);
	bool oneShot = false;
	if (args.IsValid(1)) oneShot = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Start(milliseconds, oneShot);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Timer, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, Stop)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Stop();
	return Value::Null;
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
