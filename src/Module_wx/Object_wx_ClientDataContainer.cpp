//----------------------------------------------------------------------------
// wxClientDataContainer
// extracted from clientdat.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_ClientDataContainer: public wxClientDataContainer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_ClientDataContainer *_pObj;
public:
	inline wx_ClientDataContainer() : wxClientDataContainer(), _sig(NULL), _pObj(NULL) {}
	~wx_ClientDataContainer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_ClientDataContainer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_ClientDataContainer::~wx_ClientDataContainer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_ClientDataContainer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClientDataContainer
//----------------------------------------------------------------------------
Gura_DeclareFunction(ClientDataContainerEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_ClientDataContainer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ClientDataContainerEmpty)
{
	wx_ClientDataContainer *pEntity = new wx_ClientDataContainer();
	Object_wx_ClientDataContainer *pObj = Object_wx_ClientDataContainer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_ClientDataContainer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_ClientDataContainer, GetClientData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ClientDataContainer, GetClientData)
{
	Object_wx_ClientDataContainer *pSelf = Object_wx_ClientDataContainer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->GetClientData();
	return Value::Null;
}

Gura_DeclareMethod(wx_ClientDataContainer, GetClientObject)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_ClientDataContainer, GetClientObject)
{
#if 0
	Object_wx_ClientDataContainer *pSelf = Object_wx_ClientDataContainer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxClientData *rtn = (wxClientData *)pSelf->GetEntity()->GetClientObject();
	return ReturnValue(env, sig, args, Value(new Object_wx_ClientData(rtn, NULL, OwnerFalse)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ClientDataContainer, SetClientData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_ClientDataContainer, SetClientData)
{
#if 0
	Object_wx_ClientDataContainer *pSelf = Object_wx_ClientDataContainer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int data = args.GetInt(0);
	pSelf->GetEntity()->SetClientData(data);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_ClientDataContainer, SetClientObject)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "data", VTYPE_wx_ClientData, OCCUR_Once);
}

Gura_ImplementMethod(wx_ClientDataContainer, SetClientObject)
{
	Object_wx_ClientDataContainer *pSelf = Object_wx_ClientDataContainer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxClientData *data = Object_wx_ClientData::GetObject(args, 0)->GetEntity();
	pSelf->GetEntity()->SetClientObject(data);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxClientDataContainer
//----------------------------------------------------------------------------
Object_wx_ClientDataContainer::~Object_wx_ClientDataContainer()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_ClientDataContainer::Clone() const
{
	return NULL;
}

String Object_wx_ClientDataContainer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.ClientDataContainer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_ClientDataContainer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ClientDataContainerEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxClientDataContainer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ClientDataContainer)
{
	Gura_AssignMethod(wx_ClientDataContainer, GetClientData);
	Gura_AssignMethod(wx_ClientDataContainer, GetClientObject);
	Gura_AssignMethod(wx_ClientDataContainer, SetClientData);
	Gura_AssignMethod(wx_ClientDataContainer, SetClientObject);
}

Gura_ImplementDescendantCreator(wx_ClientDataContainer)
{
	return new Object_wx_ClientDataContainer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
