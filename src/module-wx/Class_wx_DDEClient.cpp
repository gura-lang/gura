//----------------------------------------------------------------------------
// wxDDEClient
// extracted from ddeclint.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DDEClient: public wxDDEClient, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DDEClient *_pObj;
public:
	inline wx_DDEClient() : wxDDEClient(), _pObj(nullptr) {}
	~wx_DDEClient();
	inline void AssocWithGura(Object_wx_DDEClient *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DDEClient::~wx_DDEClient()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DDEClient::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDDEClient
//----------------------------------------------------------------------------
Gura_DeclareFunction(DDEClientEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DDEClient));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DDEClientEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wx_DDEClient *pEntity = new wx_DDEClient();
	Object_wx_DDEClient *pObj = Object_wx_DDEClient::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_DDEClient(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_DDEClient, MakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "host", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEClient, MakeConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString host = wxString::FromUTF8(args.GetString(0));
	wxString service = wxString::FromUTF8(args.GetString(1));
	wxString topic = wxString::FromUTF8(args.GetString(2));
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->MakeConnection(host, service, topic);
	return ReturnValue(env, args, Value(new Object_wx_ConnectionBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DDEClient, OnMakeConnection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEClient, OnMakeConnection)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->OnMakeConnection();
	return ReturnValue(env, args, Value(new Object_wx_ConnectionBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_DDEClient, ValidHost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "host", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DDEClient, ValidHost)
{
	Signal &sig = env.GetSignal();
	Object_wx_DDEClient *pThis = Object_wx_DDEClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString host = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->ValidHost(host);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxDDEClient
//----------------------------------------------------------------------------
Object_wx_DDEClient::~Object_wx_DDEClient()
{
}

Object *Object_wx_DDEClient::Clone() const
{
	return nullptr;
}

String Object_wx_DDEClient::ToString(bool exprFlag)
{
	String rtn("<wx.DDEClient:");
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
// Class implementation for wxDDEClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DDEClient)
{
	Gura_AssignFunction(DDEClientEmpty);
	Gura_AssignMethod(wx_DDEClient, MakeConnection);
	Gura_AssignMethod(wx_DDEClient, OnMakeConnection);
	Gura_AssignMethod(wx_DDEClient, ValidHost);
}

Gura_ImplementDescendantCreator(wx_DDEClient)
{
	return new Object_wx_DDEClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
