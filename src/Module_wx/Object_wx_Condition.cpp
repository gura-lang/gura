//----------------------------------------------------------------------------
// wxCondition
// extracted from conditn.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Condition: public wxCondition, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Condition *_pObj;
public:
	inline wx_Condition(wxMutex& mutex) : wxCondition(mutex), _sig(NULL), _pObj(NULL) {}
	~wx_Condition();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Condition *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Condition::~wx_Condition()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Condition::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCondition
//----------------------------------------------------------------------------
Gura_DeclareFunction(Condition)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Condition));
	DeclareArg(env, "mutex", VTYPE_wx_Mutex, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Condition)
{
	wxMutex *mutex = Object_wx_Mutex::GetObject(args, 0)->GetEntity();
	wx_Condition *pEntity = new wx_Condition(*mutex);
	Object_wx_Condition *pObj = Object_wx_Condition::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Condition(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Condition, Broadcast)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, Broadcast)
{
	Object_wx_Condition *pSelf = Object_wx_Condition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Broadcast();
	return Value::Null;
}

Gura_DeclareMethod(wx_Condition, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Condition, IsOk)
{
	Object_wx_Condition *pSelf = Object_wx_Condition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Condition, Signal)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, Signal)
{
	Object_wx_Condition *pSelf = Object_wx_Condition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Signal();
	return Value::Null;
}

Gura_DeclareMethod(wx_Condition, Wait)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Condition, Wait)
{
	Object_wx_Condition *pSelf = Object_wx_Condition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxCondError rtn = pSelf->GetEntity()->Wait();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Condition, WaitTimeout)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Condition, WaitTimeout)
{
	Object_wx_Condition *pSelf = Object_wx_Condition::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	unsigned milliseconds = args.GetInt(0);
	wxCondError rtn = pSelf->GetEntity()->WaitTimeout(milliseconds);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxCondition
//----------------------------------------------------------------------------
Object_wx_Condition::~Object_wx_Condition()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_Condition::Clone() const
{
	return NULL;
}

String Object_wx_Condition::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Condition:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Condition::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(Condition);
}

//----------------------------------------------------------------------------
// Class implementation for wxCondition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Condition)
{
	Gura_AssignMethod(wx_Condition, Broadcast);
	Gura_AssignMethod(wx_Condition, IsOk);
	Gura_AssignMethod(wx_Condition, Signal);
	Gura_AssignMethod(wx_Condition, Wait);
	Gura_AssignMethod(wx_Condition, WaitTimeout);
}

Gura_ImplementDescendantCreator(wx_Condition)
{
	return new Object_wx_Condition((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
