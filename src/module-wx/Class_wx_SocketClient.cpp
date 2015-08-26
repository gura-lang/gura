//----------------------------------------------------------------------------
// wxSocketClient
// extracted from socket.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SocketClient: public wxSocketClient, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SocketClient *_pObj;
public:
	inline wx_SocketClient(wxSocketFlags flags) : wxSocketClient(flags), _pObj(nullptr) {}
	~wx_SocketClient();
	inline void AssocWithGura(Object_wx_SocketClient *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SocketClient::~wx_SocketClient()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SocketClient::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketClient
//----------------------------------------------------------------------------
Gura_DeclareFunction(SocketClient)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_SocketClient));
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(SocketClient)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxSocketFlags flags = wxSOCKET_NONE;
	if (args.IsValid(0)) flags = static_cast<wxSocketFlags>(args.GetInt(0));
	wx_SocketClient *pEntity = new wx_SocketClient(flags);
	Object_wx_SocketClient *pObj = Object_wx_SocketClient::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_SocketClient(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
}

Gura_DeclareMethod(wx_SocketClient, Connect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "address", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareArg(env, "wait", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketClient, Connect)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSockAddress *address = Object_wx_SockAddress::GetObject(args, 0)->GetEntity();
	bool wait = true;
	if (args.IsValid(1)) wait = args.GetBoolean(1);
	bool rtn = pThis->GetEntity()->Connect(*address, wait);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketClient, Connect_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "address", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareArg(env, "local", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareArg(env, "wait", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketClient, Connect_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSockAddress *address = Object_wx_SockAddress::GetObject(args, 0)->GetEntity();
	wxSockAddress *local = Object_wx_SockAddress::GetObject(args, 1)->GetEntity();
	bool wait = true;
	if (args.IsValid(2)) wait = args.GetBoolean(2);
	bool rtn = pThis->GetEntity()->Connect(*address, *local, wait);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketClient, WaitOnConnect)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketClient, WaitOnConnect)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketClient *pThis = Object_wx_SocketClient::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long seconds = -1;
	if (args.IsValid(0)) seconds = args.GetLong(0);
	long milliseconds = 0;
	if (args.IsValid(1)) milliseconds = args.GetLong(1);
	bool rtn = pThis->GetEntity()->WaitOnConnect(seconds, milliseconds);
	return ReturnValue(env, args, Value(rtn));
}

//----------------------------------------------------------------------------
// Object implementation for wxSocketClient
//----------------------------------------------------------------------------
Object_wx_SocketClient::~Object_wx_SocketClient()
{
}

Object *Object_wx_SocketClient::Clone() const
{
	return nullptr;
}

String Object_wx_SocketClient::ToString(bool exprFlag)
{
	String rtn("<wx.SocketClient:");
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
// Class implementation for wxSocketClient
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketClient)
{
	Gura_AssignFunction(SocketClient);
	Gura_AssignMethod(wx_SocketClient, Connect);
	Gura_AssignMethod(wx_SocketClient, Connect_1);
	Gura_AssignMethod(wx_SocketClient, WaitOnConnect);
}

Gura_ImplementDescendantCreator(wx_SocketClient)
{
	return new Object_wx_SocketClient((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
