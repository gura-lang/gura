//----------------------------------------------------------------------------
// wxClient
// extracted from ipcclint.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Client: public wxClient, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Client *_pObj;
public:
	inline wx_Client() : wxClient(), _sig(NULL), _pObj(NULL) {}
	~wx_Client();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Client *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Client::~wx_Client()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Client::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClient
//----------------------------------------------------------------------------
Gura_DeclareFunction(ClientEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Client));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ClientEmpty)
{
	wx_Client *pEntity = new wx_Client();
	Object_wx_Client *pObj = Object_wx_Client::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Client(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Client, MakeConnection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "host", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Client, MakeConnection)
{
	Object_wx_Client *pSelf = Object_wx_Client::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString host = wxString::FromUTF8(args.GetString(0));
	wxString service = wxString::FromUTF8(args.GetString(1));
	wxString topic = wxString::FromUTF8(args.GetString(2));
	wxConnectionBase *rtn = (wxConnectionBase *)pSelf->GetEntity()->MakeConnection(host, service, topic);
	return ReturnValue(env, sig, args, Value(new Object_wx_ConnectionBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Client, OnMakeConnection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Client, OnMakeConnection)
{
	Object_wx_Client *pSelf = Object_wx_Client::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxConnectionBase *rtn = (wxConnectionBase *)pSelf->GetEntity()->OnMakeConnection();
	return ReturnValue(env, sig, args, Value(new Object_wx_ConnectionBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_Client, ValidHost)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "host", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Client, ValidHost)
{
	Object_wx_Client *pSelf = Object_wx_Client::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString host = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->ValidHost(host);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxClient
//----------------------------------------------------------------------------
Object_wx_Client::~Object_wx_Client()
{
}

Object *Object_wx_Client::Clone() const
{
	return NULL;
}

String Object_wx_Client::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Client:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Client::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(ClientEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Client)
{
	Gura_AssignMethod(wx_Client, MakeConnection);
	Gura_AssignMethod(wx_Client, OnMakeConnection);
	Gura_AssignMethod(wx_Client, ValidHost);
}

Gura_ImplementDescendantCreator(wx_Client)
{
	return new Object_wx_Client((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
