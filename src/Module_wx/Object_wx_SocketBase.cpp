//----------------------------------------------------------------------------
// wxSocketBase
// extracted from socket.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SocketBase: public wxSocketBase, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_SocketBase *_pObj;
public:
	//inline wx_SocketBase() : wxSocketBase(), _sig(NULL), _pObj(NULL) {}
	~wx_SocketBase();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_SocketBase *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SocketBase::~wx_SocketBase()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_SocketBase::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketBase
//----------------------------------------------------------------------------
Gura_DeclareFunction(SocketBaseEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_SocketBase));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(SocketBaseEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_SocketBase *pEntity = new wx_SocketBase();
	Object_wx_SocketBase *pObj = Object_wx_SocketBase::GetSelfObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_SocketBase(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetSelf());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Close)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, Close)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->Close();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Destroy)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Destroy)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Destroy();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Discard)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Discard)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSocketBase &rtn = pSelf->GetEntity()->Discard();
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Error)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Error)
{
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->Error();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, GetClientData)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, GetClientData)
{
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->GetClientData();
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, GetLocal)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "addr", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, GetLocal)
{
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSockAddress *addr = Object_wx_SockAddress::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetLocal(*addr);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, GetFlags)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, GetFlags)
{
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSocketFlags rtn = pSelf->GetEntity()->GetFlags();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, GetPeer)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "addr", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, GetPeer)
{
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSockAddress *addr = Object_wx_SockAddress::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->GetPeer(*addr);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, InterruptWait)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, InterruptWait)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->InterruptWait();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, IsConnected)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, IsConnected)
{
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsConnected();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, IsData)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, IsData)
{
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsData();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, IsDisconnected)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, IsDisconnected)
{
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsDisconnected();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, LastCount)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, LastCount)
{
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxUint32 rtn = pSelf->GetEntity()->LastCount();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, LastError)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, LastError)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSocketError rtn = pSelf->GetEntity()->LastError();
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketError(new wxSocketError(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Notify)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "notify", VTYPE_boolean, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_SocketBase, Notify)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool notify = args.GetBoolean(0);
	pSelf->GetEntity()->Notify(notify);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, IsOk)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, IsOk)
{
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	bool rtn = pSelf->GetEntity()->IsOk();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, RestoreState)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, RestoreState)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->RestoreState();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, SaveState)
{
	SetMode(RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, SaveState)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	pSelf->GetEntity()->SaveState();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, SetClientData)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_SocketBase, SetClientData)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int data = args.GetInt(0);
	pSelf->GetEntity()->SetClientData(data);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, SetEventHandler)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_SocketBase, SetEventHandler)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(args, 0)->GetEntity();
	int id = -1;
	if (args.IsValid(1)) id = args.GetInt(1);
	pSelf->GetEntity()->SetEventHandler(*handler, id);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, SetFlags)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_SocketBase, SetFlags)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSocketFlags flags = static_cast<wxSocketFlags>(args.GetInt(0));
	pSelf->GetEntity()->SetFlags(flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, SetLocal)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "local", VTYPE_wx_IPV4address, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, SetLocal)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxIPV4address *local = Object_wx_IPV4address::GetObject(args, 0)->GetEntity();
	bool rtn = pSelf->GetEntity()->SetLocal(*local);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, SetNotify)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_SocketBase, SetNotify)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	wxSocketEventFlags flags = static_cast<wxSocketEventFlags>(args.GetInt(0));
	pSelf->GetEntity()->SetNotify(flags);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, SetTimeout)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_SocketBase, SetTimeout)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int seconds = args.GetInt(0);
	pSelf->GetEntity()->SetTimeout(seconds);
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Peek)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Peek)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(args.GetULong(1));
	wxSocketBase &rtn = pSelf->GetEntity()->Peek(buffer, nbytes);
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Read)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Read)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(args.GetULong(1));
	wxSocketBase &rtn = pSelf->GetEntity()->Read(buffer, nbytes);
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, ReadMsg)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, ReadMsg)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(args.GetULong(1));
	wxSocketBase &rtn = pSelf->GetEntity()->ReadMsg(buffer, nbytes);
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Unread)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Unread)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(args.GetULong(1));
	wxSocketBase &rtn = pSelf->GetEntity()->Unread(buffer, nbytes);
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Wait)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisecond", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Wait)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long seconds = -1;
	if (args.IsValid(0)) seconds = args.GetLong(0);
	long millisecond = 0;
	if (args.IsValid(1)) millisecond = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->Wait(seconds, millisecond);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Wait_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisecond", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Wait_1)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long seconds = -1;
	if (args.IsValid(0)) seconds = args.GetLong(0);
	long millisecond = 0;
	if (args.IsValid(1)) millisecond = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->Wait(seconds, millisecond);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, WaitForRead)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisecond", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, WaitForRead)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long seconds = -1;
	if (args.IsValid(0)) seconds = args.GetLong(0);
	long millisecond = 0;
	if (args.IsValid(1)) millisecond = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->WaitForRead(seconds, millisecond);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, WaitForWrite)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisecond", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, WaitForWrite)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	long seconds = -1;
	if (args.IsValid(0)) seconds = args.GetLong(0);
	long millisecond = 0;
	if (args.IsValid(1)) millisecond = args.GetLong(1);
	bool rtn = pSelf->GetEntity()->WaitForWrite(seconds, millisecond);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, Write)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Write)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(args.GetULong(1));
	wxSocketBase &rtn = pSelf->GetEntity()->Write(buffer, nbytes);
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_SocketBase, WriteMsg)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, WriteMsg)
{
#if 0
	Object_wx_SocketBase *pSelf = Object_wx_SocketBase::GetSelfObj(args);
	if (pSelf->IsInvalid(sig)) return Value::Null;
	int buffer = args.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(args.GetULong(1));
	wxSocketBase &rtn = pSelf->GetEntity()->WriteMsg(buffer, nbytes);
	return ReturnValue(env, sig, args, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxSocketBase
//----------------------------------------------------------------------------
Object_wx_SocketBase::~Object_wx_SocketBase()
{
}

Object *Object_wx_SocketBase::Clone() const
{
	return NULL;
}

String Object_wx_SocketBase::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.SocketBase:");
	if (GetEntity() == NULL) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

void Object_wx_SocketBase::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(SocketBaseEmpty);
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketBase)
{
	Gura_AssignMethod(wx_SocketBase, Close);
	Gura_AssignMethod(wx_SocketBase, Destroy);
	Gura_AssignMethod(wx_SocketBase, Discard);
	Gura_AssignMethod(wx_SocketBase, Error);
	Gura_AssignMethod(wx_SocketBase, GetClientData);
	Gura_AssignMethod(wx_SocketBase, GetLocal);
	Gura_AssignMethod(wx_SocketBase, GetFlags);
	Gura_AssignMethod(wx_SocketBase, GetPeer);
	Gura_AssignMethod(wx_SocketBase, InterruptWait);
	Gura_AssignMethod(wx_SocketBase, IsConnected);
	Gura_AssignMethod(wx_SocketBase, IsData);
	Gura_AssignMethod(wx_SocketBase, IsDisconnected);
	Gura_AssignMethod(wx_SocketBase, LastCount);
	Gura_AssignMethod(wx_SocketBase, LastError);
	Gura_AssignMethod(wx_SocketBase, Notify);
	Gura_AssignMethod(wx_SocketBase, IsOk);
	Gura_AssignMethod(wx_SocketBase, RestoreState);
	Gura_AssignMethod(wx_SocketBase, SaveState);
	Gura_AssignMethod(wx_SocketBase, SetClientData);
	Gura_AssignMethod(wx_SocketBase, SetEventHandler);
	Gura_AssignMethod(wx_SocketBase, SetFlags);
	Gura_AssignMethod(wx_SocketBase, SetLocal);
	Gura_AssignMethod(wx_SocketBase, SetNotify);
	Gura_AssignMethod(wx_SocketBase, SetTimeout);
	Gura_AssignMethod(wx_SocketBase, Peek);
	Gura_AssignMethod(wx_SocketBase, Read);
	Gura_AssignMethod(wx_SocketBase, ReadMsg);
	Gura_AssignMethod(wx_SocketBase, Unread);
	Gura_AssignMethod(wx_SocketBase, Wait);
	Gura_AssignMethod(wx_SocketBase, Wait_1);
	Gura_AssignMethod(wx_SocketBase, WaitForRead);
	Gura_AssignMethod(wx_SocketBase, WaitForWrite);
	Gura_AssignMethod(wx_SocketBase, Write);
	Gura_AssignMethod(wx_SocketBase, WriteMsg);
}

Gura_ImplementDescendantCreator(wx_SocketBase)
{
	return new Object_wx_SocketBase((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
