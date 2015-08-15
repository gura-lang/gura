//----------------------------------------------------------------------------
// wxTCPClient
// extracted from tcpclint.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TCPClient: public wxTCPClient, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_TCPClient *_pObj;
public:
	inline wx_TCPClient() : wxTCPClient(), _pObj(nullptr) {}
	~wx_TCPClient();
	inline void AssocWithGura(Object_wx_TCPClient *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TCPClient::~wx_TCPClient()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TCPClient::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTCPClient
//----------------------------------------------------------------------------
Gura_DeclareFunction(TCPClientEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TCPClient));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TCPClientEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_TCPClient *pEntity = new wx_TCPClient();
	Object_wx_TCPClient *pObj = Object_wx_TCPClient::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TCPClient(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetThis());
}

Gura_DeclareMethod(wx_TCPClient, MakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "host", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPClient, MakeConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPClient *pThis = Object_wx_TCPClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString host = wxString::FromUTF8(args.GetString(0));
	wxString service = wxString::FromUTF8(args.GetString(1));
	wxString topic = wxString::FromUTF8(args.GetString(2));
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->MakeConnection(host, service, topic);
	return ReturnValue(env, args, Value(new Object_wx_ConnectionBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_TCPClient, OnMakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPClient, OnMakeConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPClient *pThis = Object_wx_TCPClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->OnMakeConnection();
	return ReturnValue(env, args, Value(new Object_wx_ConnectionBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_TCPClient, ValidHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "host", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPClient, ValidHost)
{
	Signal &sig = env.GetSignal();
	Object_wx_TCPClient *pThis = Object_wx_TCPClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString host = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->ValidHost(host);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxTCPClient
//----------------------------------------------------------------------------
Object_wx_TCPClient::~Object_wx_TCPClient()
{
}

Object *Object_wx_TCPClient::Clone() const
{
	return nullptr;
}

String Object_wx_TCPClient::ToString(bool exprFlag)
{
	String rtn("<wx.TCPClient:");
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
// Class implementation for wxTCPClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPClient)
{
	Gura_AssignFunction(TCPClientEmpty);
	Gura_AssignMethod(wx_TCPClient, MakeConnection);
	Gura_AssignMethod(wx_TCPClient, OnMakeConnection);
	Gura_AssignMethod(wx_TCPClient, ValidHost);
}

Gura_ImplementDescendantCreator(wx_TCPClient)
{
	return new Object_wx_TCPClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
