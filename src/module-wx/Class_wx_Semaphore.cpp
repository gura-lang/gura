//----------------------------------------------------------------------------
// wxSemaphore
// extracted from semaphor.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Semaphore: public wxSemaphore, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Semaphore *_pObj;
public:
	inline wx_Semaphore(int initialcount, int maxcount) : wxSemaphore(initialcount, maxcount), _sig(NULL), _pObj(NULL) {}
	~wx_Semaphore();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Semaphore *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Semaphore::~wx_Semaphore()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Semaphore::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSemaphore
//----------------------------------------------------------------------------
Gura_DeclareFunction(Semaphore)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Semaphore));
	DeclareArg(env, "initialcount", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "maxcount", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Semaphore)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int initialcount = 0;
	if (args.IsValid(0)) initialcount = args.GetInt(0);
	int maxcount = 0;
	if (args.IsValid(1)) maxcount = args.GetInt(1);
	wx_Semaphore *pEntity = new wx_Semaphore(initialcount, maxcount);
	Object_wx_Semaphore *pObj = Object_wx_Semaphore::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Semaphore(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_Semaphore, Post)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Semaphore, Post)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSemaError rtn = pThis->GetEntity()->Post();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Semaphore, TryWait)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Semaphore, TryWait)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSemaError rtn = pThis->GetEntity()->TryWait();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Semaphore, Wait)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Semaphore, Wait)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxSemaError rtn = pThis->GetEntity()->Wait();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Semaphore, WaitTimeout)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "timeout_millis", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Semaphore, WaitTimeout)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned timeout_millis = args.GetInt(0);
	wxSemaError rtn = pThis->GetEntity()->WaitTimeout(timeout_millis);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSemaphore
//----------------------------------------------------------------------------
Object_wx_Semaphore::~Object_wx_Semaphore()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_Semaphore::Clone() const
{
	return NULL;
}

String Object_wx_Semaphore::ToString(bool exprFlag)
{
	String rtn("<wx.Semaphore:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxSemaphore
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Semaphore)
{
	Gura_AssignFunction(Semaphore);
	Gura_AssignMethod(wx_Semaphore, Post);
	Gura_AssignMethod(wx_Semaphore, TryWait);
	Gura_AssignMethod(wx_Semaphore, Wait);
	Gura_AssignMethod(wx_Semaphore, WaitTimeout);
}

Gura_ImplementDescendantCreator(wx_Semaphore)
{
	return new Object_wx_Semaphore((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
