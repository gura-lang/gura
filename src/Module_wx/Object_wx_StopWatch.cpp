//----------------------------------------------------------------------------
// wxStopWatch
// extracted from stopwtch.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_StopWatch: public wxStopWatch, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_StopWatch *_pObj;
public:
	inline wx_StopWatch() : wxStopWatch(), _sig(NULL), _pObj(NULL) {}
	~wx_StopWatch();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_StopWatch *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_StopWatch::~wx_StopWatch()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_StopWatch::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxStopWatch
//----------------------------------------------------------------------------
Gura_DeclareFunction(StopWatch)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_StopWatch));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(StopWatch)
{
	wx_StopWatch *pEntity = new wx_StopWatch();
	Object_wx_StopWatch *pObj = Object_wx_StopWatch::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_StopWatch(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_StopWatch, Pause)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, Pause)
{
	Object_wx_StopWatch *pSelf = Object_wx_StopWatch::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Pause();
	return Value::Null;
}

Gura_DeclareMethod(wx_StopWatch, Resume)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, Resume)
{
	Object_wx_StopWatch *pSelf = Object_wx_StopWatch::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Resume();
	return Value::Null;
}

Gura_DeclareMethod(wx_StopWatch, Start)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StopWatch, Start)
{
	Object_wx_StopWatch *pSelf = Object_wx_StopWatch::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long milliseconds = 0;
	if (args.IsValid(0)) milliseconds = args.GetLong(0);
	pSelf->GetEntity()->Start(milliseconds);
	return Value::Null;
}

Gura_DeclareMethod(wx_StopWatch, Time)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StopWatch, Time)
{
	Object_wx_StopWatch *pSelf = Object_wx_StopWatch::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long rtn = pSelf->GetEntity()->Time();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxStopWatch
//----------------------------------------------------------------------------
Object_wx_StopWatch::~Object_wx_StopWatch()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_StopWatch::Clone() const
{
	return NULL;
}

String Object_wx_StopWatch::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.StopWatch:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_StopWatch::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(StopWatch);
}

//----------------------------------------------------------------------------
// Class implementation for wxStopWatch
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StopWatch)
{
	Gura_AssignMethod(wx_StopWatch, Pause);
	Gura_AssignMethod(wx_StopWatch, Resume);
	Gura_AssignMethod(wx_StopWatch, Start);
	Gura_AssignMethod(wx_StopWatch, Time);
}

Gura_ImplementDescendantCreator(wx_StopWatch)
{
	return new Object_wx_StopWatch((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
