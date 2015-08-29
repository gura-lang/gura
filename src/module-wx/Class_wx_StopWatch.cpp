//----------------------------------------------------------------------------
// wxStopWatch
// extracted from stopwtch.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StopWatch: public wxStopWatch, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_StopWatch *_pObj;
public:
	inline wx_StopWatch() : wxStopWatch(), _pObj(nullptr) {}
	~wx_StopWatch();
	inline void AssocWithGura(Object_wx_StopWatch *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StopWatch::~wx_StopWatch()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_StopWatch::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStopWatch
//----------------------------------------------------------------------------
Gura_DeclareFunction(StopWatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StopWatch));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StopWatch)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_StopWatch *pEntity = new wx_StopWatch();
	Object_wx_StopWatch *pObj = Object_wx_StopWatch::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_StopWatch(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_StopWatch, Pause)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, Pause)
{
	Signal &sig = env.GetSignal();
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Pause();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StopWatch, Resume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, Resume)
{
	Signal &sig = env.GetSignal();
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Resume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_StopWatch, Start)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StopWatch, Start)
{
	Signal &sig = env.GetSignal();
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long milliseconds = 0;
	if (arg.IsValid(0)) milliseconds = arg.GetLong(0);
	pThis->GetEntity()->Start(milliseconds);
	return Value::Nil;
}

Gura_DeclareMethod(wx_StopWatch, Time)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StopWatch, Time)
{
	Signal &sig = env.GetSignal();
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long rtn = pThis->GetEntity()->Time();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxStopWatch
//----------------------------------------------------------------------------
Object_wx_StopWatch::~Object_wx_StopWatch()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_StopWatch::Clone() const
{
	return nullptr;
}

String Object_wx_StopWatch::ToString(bool exprFlag)
{
	String rtn("<wx.StopWatch:");
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
// Class implementation for wxStopWatch
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StopWatch)
{
	Gura_AssignFunction(StopWatch);
	Gura_AssignMethod(wx_StopWatch, Pause);
	Gura_AssignMethod(wx_StopWatch, Resume);
	Gura_AssignMethod(wx_StopWatch, Start);
	Gura_AssignMethod(wx_StopWatch, Time);
}

Gura_ImplementDescendantCreator(wx_StopWatch)
{
	return new Object_wx_StopWatch((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
