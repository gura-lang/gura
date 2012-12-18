//----------------------------------------------------------------------------
// wxSockAddress
// extracted from sckaddr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SockAddress: public wxSockAddress, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SockAddress *_pObj;
public:
	//inline wx_SockAddress() : wxSockAddress(), _sig(NULL), _pObj(NULL) {}
	~wx_SockAddress();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SockAddress *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SockAddress::~wx_SockAddress()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SockAddress::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSockAddress
//----------------------------------------------------------------------------
Gura_DeclareFunction(SockAddressEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_SockAddress));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(SockAddressEmpty)
{
#if 0
	wx_SockAddress *pEntity = new wx_SockAddress();
	Object_wx_SockAddress *pObj = Object_wx_SockAddress::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SockAddress(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SockAddress, Clear)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, Clear)
{
	Object_wx_SockAddress *pSelf = Object_wx_SockAddress::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Clear();
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSockAddress
//----------------------------------------------------------------------------
Object_wx_SockAddress::~Object_wx_SockAddress()
{
}

Object *Object_wx_SockAddress::Clone() const
{
	return NULL;
}

String Object_wx_SockAddress::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SockAddress:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SockAddress::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(SockAddressEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxSockAddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SockAddress)
{
	Gura_AssignMethod(wx_SockAddress, Clear);
}

Gura_ImplementDescendantCreator(wx_SockAddress)
{
	return new Object_wx_SockAddress((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
