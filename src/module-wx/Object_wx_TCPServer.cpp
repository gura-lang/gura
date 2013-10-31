//----------------------------------------------------------------------------
// wxTCPServer
// extracted from tcpservr.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

Gura_DeclarePrivUserSymbol(OnAcceptConnection);

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TCPServer: public wxTCPServer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TCPServer *_pObj;
public:
	inline wx_TCPServer() : wxTCPServer(), _sig(NULL), _pObj(NULL) {}
	//virtual wxConnectionBase * OnAcceptConnection(const wxString& topic);
	~wx_TCPServer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TCPServer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TCPServer::~wx_TCPServer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TCPServer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTCPServer
//----------------------------------------------------------------------------
Gura_DeclareFunction(TCPServerEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TCPServer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(TCPServerEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_TCPServer *pEntity = new wx_TCPServer();
	Object_wx_TCPServer *pObj = Object_wx_TCPServer::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TCPServer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_TCPServer, Create)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "service", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPServer, Create)
{
	Object_wx_TCPServer *pThis = Object_wx_TCPServer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString service = wxString::FromUTF8(args.GetString(0));
	bool rtn = pThis->GetEntity()->Create(service);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TCPServer, OnAcceptConnection)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "topic", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TCPServer, OnAcceptConnection)
{
	Object_wx_TCPServer *pThis = Object_wx_TCPServer::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString topic = wxString::FromUTF8(args.GetString(0));
	wxConnectionBase *rtn = (wxConnectionBase *)pThis->GetEntity()->OnAcceptConnection(topic);
	return ReturnValue(env, sig, args, Value(new Object_wx_ConnectionBase(rtn, NULL, OwnerFalse)));
}

//----------------------------------------------------------------------------
// Object implementation for wxTCPServer
//----------------------------------------------------------------------------
Object_wx_TCPServer::~Object_wx_TCPServer()
{
}

Object *Object_wx_TCPServer::Clone() const
{
	return NULL;
}

String Object_wx_TCPServer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.TCPServer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxTCPServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TCPServer)
{
	Gura_RealizeUserSymbol(OnAcceptConnection);
	Gura_AssignFunction(TCPServerEmpty);
	Gura_AssignMethod(wx_TCPServer, Create);
	Gura_AssignMethod(wx_TCPServer, OnAcceptConnection);
}

Gura_ImplementDescendantCreator(wx_TCPServer)
{
	return new Object_wx_TCPServer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
