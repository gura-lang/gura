//----------------------------------------------------------------------------
// wxSockAddress
// extracted from sckaddr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SockAddress: public wxSockAddress, public GuraObjectObserver {
private:
	Gura::Signal *_pSig;
	Object_wx_SockAddress *_pObj;
public:
	//inline wx_SockAddress() : wxSockAddress(), _pSig(nullptr), _pObj(nullptr) {}
	~wx_SockAddress();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SockAddress *pObj) {
		_pSig = &sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SockAddress::~wx_SockAddress()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SockAddress::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSockAddress
//----------------------------------------------------------------------------
Gura_DeclareFunction(SockAddressEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_SockAddress));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(SockAddressEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_SockAddress *pEntity = new wx_SockAddress();
	Object_wx_SockAddress *pObj = Object_wx_SockAddress::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SockAddress(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SockAddress, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SockAddress, Clear)
{
	Object_wx_SockAddress *pThis = Object_wx_SockAddress::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	pThis->GetEntity()->Clear();
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
	return nullptr;
}

String Object_wx_SockAddress::ToString(bool exprFlag)
{
	String rtn("<wx.SockAddress:");
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
// Class implementation for wxSockAddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SockAddress)
{
	Gura_AssignFunction(SockAddressEmpty);
	Gura_AssignMethod(wx_SockAddress, Clear);
}

Gura_ImplementDescendantCreator(wx_SockAddress)
{
	return new Object_wx_SockAddress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
