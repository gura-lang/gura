//----------------------------------------------------------------------------
// wxDDEClient
// extracted from ddeclint.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DDEClient: public wxDDEClient, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DDEClient *_pObj;
public:
	inline wx_DDEClient() : wxDDEClient(), _sig(NULL), _pObj(NULL) {}
	~wx_DDEClient();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DDEClient *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DDEClient::~wx_DDEClient()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DDEClient::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEClient
//----------------------------------------------------------------------------
Gura_DeclareFunction(DDEClientEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DDEClient));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DDEClientEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DDEClient *pEntity = new wx_DDEClient();
	Object_wx_DDEClient *pObj = Object_wx_DDEClient::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DDEClient(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DDEClient, MakeConnection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "host", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEClient, MakeConnection)
{
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString host = wxString::FromUTF8(args.GetString(0));
	wxString service = wxString::FromUTF8(args.GetString(1));
	wxString topic = wxString::FromUTF8(args.GetString(2));
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->MakeConnection(host, service, topic);
	return ReturnValue(env, sig, args, Value(new Object_wx_ConnectionBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_DDEClient, OnMakeConnection)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEClient, OnMakeConnection)
{
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->OnMakeConnection();
	return ReturnValue(env, sig, args, Value(new Object_wx_ConnectionBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_DDEClient, ValidHost)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "host", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEClient, ValidHost)
{
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString host = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->ValidHost(host);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDDEClient
//----------------------------------------------------------------------------
Object_wx_DDEClient::~Object_wx_DDEClient()
{
}

Object *Object_wx_DDEClient::Clone() const
{
	return NULL;
}

String Object_wx_DDEClient::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DDEClient:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_DDEClient::DoAssignConstructor(Environment &env, Signal sig)
{
	Gura_AssignFunction(DDEClientEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxDDEClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEClient)
{
	Gura_AssignMethod(wx_DDEClient, MakeConnection);
	Gura_AssignMethod(wx_DDEClient, OnMakeConnection);
	Gura_AssignMethod(wx_DDEClient, ValidHost);
}

Gura_ImplementDescendantCreator(wx_DDEClient)
{
	return new Object_wx_DDEClient((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
