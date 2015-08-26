//----------------------------------------------------------------------------
// wxRecursionGuard
// extracted from recguard.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_RecursionGuard: public wxRecursionGuard, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_RecursionGuard *_pObj;
public:
	//inline wx_RecursionGuard(wxRecursionGuardFlag& flag) : wxRecursionGuard(flag), _pObj(nullptr) {}
	~wx_RecursionGuard();
	inline void AssocWithGura(Object_wx_RecursionGuard *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_RecursionGuard::~wx_RecursionGuard()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_RecursionGuard::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxRecursionGuard
//----------------------------------------------------------------------------
Gura_DeclareFunction(RecursionGuard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_RecursionGuard));
	DeclareArg(env, "flag", VTYPE_wx_RecursionGuardFlag, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(RecursionGuard)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxRecursionGuardFlag *flag = Object_wx_RecursionGuardFlag::GetObject(args, 0)->GetEntity();
	wx_RecursionGuard *pEntity = new wx_RecursionGuard(*flag);
	Object_wx_RecursionGuard *pObj = Object_wx_RecursionGuard::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_RecursionGuard(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_RecursionGuard, IsInside)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_RecursionGuard, IsInside)
{
	Signal &sig = env.GetSignal();
	Object_wx_RecursionGuard *pThis = Object_wx_RecursionGuard::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsInside();
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxRecursionGuard
//----------------------------------------------------------------------------
Object_wx_RecursionGuard::~Object_wx_RecursionGuard()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_RecursionGuard::Clone() const
{
	return nullptr;
}

String Object_wx_RecursionGuard::ToString(bool exprFlag)
{
	String rtn("<wx.RecursionGuard:");
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
// Class implementation for wxRecursionGuard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RecursionGuard)
{
	Gura_AssignFunction(RecursionGuard);
	Gura_AssignMethod(wx_RecursionGuard, IsInside);
}

Gura_ImplementDescendantCreator(wx_RecursionGuard)
{
	return new Object_wx_RecursionGuard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
