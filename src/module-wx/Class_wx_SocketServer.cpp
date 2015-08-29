//----------------------------------------------------------------------------
// wxSocketServer
// extracted from socksrv.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SocketServer: public wxSocketServer, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SocketServer *_pObj;
public:
	inline wx_SocketServer(const wxSockAddress& address, wxSocketFlags flags) : wxSocketServer(address, flags), _pObj(nullptr) {}
	~wx_SocketServer();
	inline void AssocWithGura(Object_wx_SocketServer *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SocketServer::~wx_SocketServer()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SocketServer::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketServer
//----------------------------------------------------------------------------
Gura_DeclareFunction(SocketServer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SocketServer));
	DeclareArg(env, "address", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SocketServer)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxSockAddress *address = Object_wx_SockAddress::GetObject(arg, 0)->GetEntity();
	wxSocketFlags flags = wxSOCKET_NONE;
	if (arg.IsValid(1)) flags = static_cast<wxSocketFlags>(arg.GetInt(1));
	wx_SocketServer *pEntity = new wx_SocketServer(*address, flags);
	Object_wx_SocketServer *pObj = Object_wx_SocketServer::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SocketServer(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_SocketServer, Accept)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "wait", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketServer, Accept)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool wait = true;
	if (arg.IsValid(0)) wait = arg.GetBoolean(0);
	wxSocketBase *rtn = (wxSocketBase *)pThis->GetEntity()->Accept(wait);
	return ReturnValue(env, arg, Value(new Object_wx_SocketBase(rtn, nullptr, OwnerFalse)));
}

Gura_DeclareMethod(wx_SocketServer, AcceptWith)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "socket", VTYPE_wx_SocketBase, OCCUR_Once);
	DeclareArg(env, "wait", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketServer, AcceptWith)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSocketBase *socket = Object_wx_SocketBase::GetObject(arg, 0)->GetEntity();
	bool wait = true;
	if (arg.IsValid(1)) wait = arg.GetBoolean(1);
	bool rtn = pThis->GetEntity()->AcceptWith(*socket, wait);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SocketServer, WaitForAccept)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisecond", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketServer, WaitForAccept)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketServer *pThis = Object_wx_SocketServer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long seconds = -1;
	if (arg.IsValid(0)) seconds = arg.GetLong(0);
	long millisecond = 0;
	if (arg.IsValid(1)) millisecond = arg.GetLong(1);
	bool rtn = pThis->GetEntity()->WaitForAccept(seconds, millisecond);
	return ReturnValue(env, arg, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSocketServer
//----------------------------------------------------------------------------
Object_wx_SocketServer::~Object_wx_SocketServer()
{
}

Object *Object_wx_SocketServer::Clone() const
{
	return nullptr;
}

String Object_wx_SocketServer::ToString(bool exprFlag)
{
	String rtn("<wx.SocketServer:");
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
// Class implementation for wxSocketServer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketServer)
{
	Gura_AssignFunction(SocketServer);
	Gura_AssignMethod(wx_SocketServer, Accept);
	Gura_AssignMethod(wx_SocketServer, AcceptWith);
	Gura_AssignMethod(wx_SocketServer, WaitForAccept);
}

Gura_ImplementDescendantCreator(wx_SocketServer)
{
	return new Object_wx_SocketServer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
