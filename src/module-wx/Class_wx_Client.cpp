//----------------------------------------------------------------------------
// wxClient
// extracted from ipcclint.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Client: public wxClient, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_Client *_pObj;
public:
	inline wx_Client() : wxClient(), _pObj(nullptr) {}
	~wx_Client();
	inline void AssocWithGura(Object_wx_Client *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Client::~wx_Client()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_Client::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxClient
//----------------------------------------------------------------------------
Gura_DeclareFunction(ClientEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Client));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ClientEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_Client *pEntity = new wx_Client();
	Object_wx_Client *pObj = Object_wx_Client::GetObjectThis(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_Client(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_Client, MakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "host", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Client, MakeConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString host = wxString::FromUTF8(args.GetString(0));
	wxString service = wxString::FromUTF8(args.GetString(1));
	wxString topic = wxString::FromUTF8(args.GetString(2));
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->MakeConnection(host, service, topic);
	return ReturnValue(env, args, Value(new Object_wx_ConnectionBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Client, OnMakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Client, OnMakeConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->OnMakeConnection();
	return ReturnValue(env, args, Value(new Object_wx_ConnectionBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_Client, ValidHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "host", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Client, ValidHost)
{
	Signal &sig = env.GetSignal();
	Object_wx_Client *pThis = Object_wx_Client::GetObjectThis(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString host = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->ValidHost(host);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxClient
//----------------------------------------------------------------------------
Object_wx_Client::~Object_wx_Client()
{
}

Object *Object_wx_Client::Clone() const
{
	return nullptr;
}

String Object_wx_Client::ToString(bool exprFlag)
{
	String rtn("<wx.Client:");
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
// Class implementation for wxClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Client)
{
	Gura_AssignFunction(ClientEmpty);
	Gura_AssignMethod(wx_Client, MakeConnection);
	Gura_AssignMethod(wx_Client, OnMakeConnection);
	Gura_AssignMethod(wx_Client, ValidHost);
}

Gura_ImplementDescendantCreator(wx_Client)
{
	return new Object_wx_Client((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
