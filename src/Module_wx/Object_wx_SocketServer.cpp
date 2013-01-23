//----------------------------------------------------------------------------
// wxSocketServer
// extracted from socksrv.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SocketServer: public wxSocketServer, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SocketServer *_pObj;
public:
	inline wx_SocketServer(const wxSockAddress& address, wxSocketFlags flags) : wxSocketServer(address, flags), _sig(NULL), _pObj(NULL) {}
	~wx_SocketServer();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SocketServer *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SocketServer::~wx_SocketServer()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SocketServer::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketServer
//----------------------------------------------------------------------------
Gura_DeclareFunction(SocketServer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SocketServer));
	DeclareArg(env, "address", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SocketServer)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxSockAddress *address = Object_wx_SockAddress::GetObject(args, 0)->GetEntity();
	wxSocketFlags flags = wxSOCKET_NONE;
	if (args.IsValid(1)) flags = static_cast<wxSocketFlags>(args.GetInt(1));
	wx_SocketServer *pEntity = new wx_SocketServer(*address, flags);
	Object_wx_SocketServer *pObj = Object_wx_SocketServer::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SocketServer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
}

Gura_DeclareMethod(wx_SocketServer, Accept)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "wait", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketServer, Accept)
{
	Object_wx_SocketServer *pSelf = Object_wx_SocketServer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool wait = true;
	if (args.IsValid(0)) wait = args.GetBoolean(0);
	wxSocketBase *rtn = (wxSocketBase *)pSelf->GetEntity()->Accept(wait);
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketBase(rtn, NULL, OwnerFalse)));
}

Gura_DeclareMethod(wx_SocketServer, AcceptWith)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "socket", VTYPE_wx_SocketBase, OCCUR_Once);
	DeclareArg(env, "wait", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketServer, AcceptWith)
{
	Object_wx_SocketServer *pSelf = Object_wx_SocketServer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSocketBase *socket = Object_wx_SocketBase::GetObject(args, 0)->GetEntity();
	bool wait = true;
	if (args.IsValid(1)) wait = args.GetBoolean(1);
	bool rtn = pSelf->GetEntity()->AcceptWith(*socket, wait);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketServer, WaitForAccept)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisecond", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketServer, WaitForAccept)
{
	Object_wx_SocketServer *pSelf = Object_wx_SocketServer::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long seconds = -1;
	if (args.IsValid(0)) seconds = args.GetLong(0);
	long millisecond = 0;
	if (args.IsValid(1)) millisecond = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->WaitForAccept(seconds, millisecond);
	return ReturnValue(env, sig, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSocketServer
//----------------------------------------------------------------------------
Object_wx_SocketServer::~Object_wx_SocketServer()
{
}

Object *Object_wx_SocketServer::Clone() const
{
	return NULL;
}

String Object_wx_SocketServer::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SocketServer:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SocketServer::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(SocketServer);
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketServer)
{
	Gura_AssignMethod(wx_SocketServer, Accept);
	Gura_AssignMethod(wx_SocketServer, AcceptWith);
	Gura_AssignMethod(wx_SocketServer, WaitForAccept);
}

Gura_ImplementDescendantCreator(wx_SocketServer)
{
	return new Object_wx_SocketServer((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
