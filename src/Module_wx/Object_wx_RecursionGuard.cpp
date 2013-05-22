//----------------------------------------------------------------------------
// wxRecursionGuard
// extracted from recguard.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RecursionGuard: public wxRecursionGuard, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_RecursionGuard *_pObj;
public:
	//inline wx_RecursionGuard(wxRecursionGuardFlag& flag) : wxRecursionGuard(flag), _sig(NULL), _pObj(NULL) {}
	~wx_RecursionGuard();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_RecursionGuard *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RecursionGuard::~wx_RecursionGuard()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_RecursionGuard::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRecursionGuard
//----------------------------------------------------------------------------
Gura_DeclareFunction(RecursionGuard)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_RecursionGuard));
	DeclareArg(env, "flag", VTYPE_wx_RecursionGuardFlag, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(RecursionGuard)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxRecursionGuardFlag *flag = Object_wx_RecursionGuardFlag::GetObject(args, 0)->GetEntity();
	wx_RecursionGuard *pEntity = new wx_RecursionGuard(*flag);
	Object_wx_RecursionGuard *pObj = Object_wx_RecursionGuard::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_RecursionGuard(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_RecursionGuard, IsInside)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RecursionGuard, IsInside)
{
	Object_wx_RecursionGuard *pThis = Object_wx_RecursionGuard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsInside();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRecursionGuard
//----------------------------------------------------------------------------
Object_wx_RecursionGuard::~Object_wx_RecursionGuard()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_RecursionGuard::Clone() const
{
	return NULL;
}

String Object_wx_RecursionGuard::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.RecursionGuard:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_RecursionGuard::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(RecursionGuard);
}

//----------------------------------------------------------------------------
// Class implementation for wxRecursionGuard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RecursionGuard)
{
	Gura_AssignMethod(wx_RecursionGuard, IsInside);
}

Gura_ImplementDescendantCreator(wx_RecursionGuard)
{
	return new Object_wx_RecursionGuard((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
