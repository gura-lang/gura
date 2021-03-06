//----------------------------------------------------------------------------
// wxMutex
// extracted from mutex.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Mutex: public wxMutex, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Mutex *_pObj;
public:
	inline wx_Mutex(wxMutexType type) : wxMutex(type), _pObj(nullptr) {}
	~wx_Mutex();
	inline void AssocWithGura(Object_wx_Mutex *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Mutex::~wx_Mutex()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Mutex::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxMutex
//----------------------------------------------------------------------------
Gura_DeclareFunction(Mutex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_Mutex));
	DeclareArg(env, "type", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(Mutex)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxMutexType type = wxMUTEX_DEFAULT;
	if (arg.IsValid(0)) type = static_cast<wxMutexType>(arg.GetInt(0));
	wx_Mutex *pEntity = new wx_Mutex(type);
	Object_wx_Mutex *pObj = Object_wx_Mutex::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_Mutex(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_Mutex, Lock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Mutex, Lock)
{
	Signal &sig = env.GetSignal();
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMutexError rtn = pThis->GetEntity()->Lock();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Mutex, TryLock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Mutex, TryLock)
{
	Signal &sig = env.GetSignal();
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMutexError rtn = pThis->GetEntity()->TryLock();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_Mutex, Unlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Mutex, Unlock)
{
	Signal &sig = env.GetSignal();
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxMutexError rtn = pThis->GetEntity()->Unlock();
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxMutex
//----------------------------------------------------------------------------
Object_wx_Mutex::~Object_wx_Mutex()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
}

Object *Object_wx_Mutex::Clone() const
{
	return nullptr;
}

String Object_wx_Mutex::ToString(bool exprFlag)
{
	String rtn("<wx.Mutex:");
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
// Class implementation for wxMutex
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Mutex)
{
	Gura_AssignFunction(Mutex);
	Gura_AssignMethod(wx_Mutex, Lock);
	Gura_AssignMethod(wx_Mutex, TryLock);
	Gura_AssignMethod(wx_Mutex, Unlock);
}

Gura_ImplementDescendantCreator(wx_Mutex)
{
	return new Object_wx_Mutex((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
