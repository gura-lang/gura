//----------------------------------------------------------------------------
// wxCondition
// extracted from conditn.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Condition: public wxCondition, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_Condition *_pObj;
public:
	inline wx_Condition(wxMutex& mutex) : wxCondition(mutex), _pSig(nullptr), _pObj(nullptr) {}
	~wx_Condition();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Condition *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Condition::~wx_Condition()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Condition::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxCondition
//----------------------------------------------------------------------------
Gura_DeclareFunction(Condition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Condition));
	DeclareArg(env, "mutex", VTYPE_wx_Mutex, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Condition)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxMutex *mutex = Object_wx_Mutex::GetObject(args, 0)->GetEntity();
	wx_Condition *pEntity = new wx_Condition(*mutex);
	Object_wx_Condition *pObj = Object_wx_Condition::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Condition(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Condition, Broadcast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, Broadcast)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Broadcast();
	return Value::Null;
}

Gura_DeclareMethod(wx_Condition, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Condition, IsOk)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Condition, Signal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, Signal)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Signal();
	return Value::Null;
}

Gura_DeclareMethod(wx_Condition, Wait)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Condition, Wait)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxCondError rtn = pThis->GetEntity()->Wait();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Condition, WaitTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Condition, WaitTimeout)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned milliseconds = args.GetInt(0);
	wxCondError rtn = pThis->GetEntity()->WaitTimeout(milliseconds);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxCondition
//----------------------------------------------------------------------------
Object_wx_Condition::~Object_wx_Condition()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_Condition::Clone() const
{
	return nullptr;
}

String Object_wx_Condition::ToString(bool exprFlag)
{
	String rtn("<wx.Condition:");
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
// Class implementation for wxCondition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Condition)
{
	Gura_AssignFunction(Condition);
	Gura_AssignMethod(wx_Condition, Broadcast);
	Gura_AssignMethod(wx_Condition, IsOk);
	Gura_AssignMethod(wx_Condition, Signal);
	Gura_AssignMethod(wx_Condition, Wait);
	Gura_AssignMethod(wx_Condition, WaitTimeout);
}

Gura_ImplementDescendantCreator(wx_Condition)
{
	return new Object_wx_Condition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
