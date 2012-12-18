//----------------------------------------------------------------------------
// wxServer
// extracted from ipcservr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

Gura_DeclarePrivUserSymbol(OnAcceptConnection);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_Server: public wxServer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_Server *_pObj;
public:
	inline wx_Server() : wxServer(), _sig(NULL), _pObj(NULL) {}
	//virtual wxConnectionBase * OnAcceptConnection(const wxString& topic);
	~wx_Server();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_Server *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_Server::~wx_Server()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_Server::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxServer
//----------------------------------------------------------------------------
Gura_DeclareFunction(ServerEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Server));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(ServerEmpty)
{
	wx_Server *pEntity = new wx_Server();
	Object_wx_Server *pObj = Object_wx_Server::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_Server(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_Server, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Server, Create)
{
	Object_wx_Server *pSelf = Object_wx_Server::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString service = wxString::FromUTF8(args.GetString(0));
	bool rtn = pSelf->GetEntity()->Create(service);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_Server, OnAcceptConnection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_Server, OnAcceptConnection)
{
	Object_wx_Server *pSelf = Object_wx_Server::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxConnectionBase *rtn = (wxConnectionBase *)pSelf->GetEntity()->OnAcceptConnection(topic);
	return ReturnValue(env, sig, args, Value(new Object_wx_ConnectionBase(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxServer
//----------------------------------------------------------------------------
Object_wx_Server::~Object_wx_Server()
{
}

Object *Object_wx_Server::Clone() const
{
	return NULL;
}

String Object_wx_Server::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.Server:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_Server::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_RealizeUserSymbol(OnAcceptConnection);
	Gura_AssignFunction(ServerEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Server)
{
	Gura_AssignMethod(wx_Server, Create);
	Gura_AssignMethod(wx_Server, OnAcceptConnection);
}

Gura_ImplementDescendantCreator(wx_Server)
{
	return new Object_wx_Server((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
