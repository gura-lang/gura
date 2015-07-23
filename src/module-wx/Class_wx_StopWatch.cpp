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
	if (!CheckWxReady(sig)) return Value::Null;
	wx_StopWatch *pEntity = new wx_StopWatch();
	Object_wx_StopWatch *pObj = Object_wx_StopWatch::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_StopWatch(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_StopWatch, Pause)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, Pause)
{
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Pause();
	return Value::Null;
}

Gura_DeclareMethod(wx_StopWatch, Resume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_StopWatch, Resume)
{
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Resume();
	return Value::Null;
}

Gura_DeclareMethod(wx_StopWatch, Start)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StopWatch, Start)
{
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long milliseconds = 0;
	if (args.IsValid(0)) milliseconds = args.GetLong(0);
	pThis->GetEntity()->Start(milliseconds);
	return Value::Null;
}

Gura_DeclareMethod(wx_StopWatch, Time)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_StopWatch, Time)
{
	Object_wx_StopWatch *pThis = Object_wx_StopWatch::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	long rtn = pThis->GetEntity()->Time();
	return ReturnValue(env, args, Value(rtn));
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
