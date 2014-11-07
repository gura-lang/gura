//----------------------------------------------------------------------------
// wxMutexLocker
// extracted from mutexlck.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_MutexLocker: public wxMutexLocker, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_MutexLocker *_pObj;
public:
	inline wx_MutexLocker(wxMutex& mutex) : wxMutexLocker(mutex), _sig(NULL), _pObj(NULL) {}
	~wx_MutexLocker();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_MutexLocker *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_MutexLocker::~wx_MutexLocker()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_MutexLocker::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMutexLocker
//----------------------------------------------------------------------------
Gura_DeclareFunction(MutexLocker)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_MutexLocker));
	DeclareArg(env, "mutex", VTYPE_wx_Mutex, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(MutexLocker)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxMutex *mutex = Object_wx_Mutex::GetObject(args, 0)->GetEntity();
	wx_MutexLocker *pEntity = new wx_MutexLocker(*mutex);
	Object_wx_MutexLocker *pObj = Object_wx_MutexLocker::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_MutexLocker(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_MutexLocker, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_MutexLocker, IsOk)
{
	Object_wx_MutexLocker *pThis = Object_wx_MutexLocker::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMutexLocker
//----------------------------------------------------------------------------
Object_wx_MutexLocker::~Object_wx_MutexLocker()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_MutexLocker::Clone() const
{
	return NULL;
}

String Object_wx_MutexLocker::ToString(bool exprFlag)
{
	String rtn("<wx.MutexLocker:");
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
// Class implementation for wxMutexLocker
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MutexLocker)
{
	Gura_AssignFunction(MutexLocker);
	Gura_AssignMethod(wx_MutexLocker, IsOk);
}

Gura_ImplementDescendantCreator(wx_MutexLocker)
{
	return new Object_wx_MutexLocker((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
