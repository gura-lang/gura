//----------------------------------------------------------------------------
// wxSocketBase
// extracted from socket.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_SocketBase: public wxSocketBase, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_SocketBase *_pObj;
public:
	//inline wx_SocketBase() : wxSocketBase(), _pObj(nullptr) {}
	~wx_SocketBase();
	inline void AssocWithGura(Object_wx_SocketBase *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_SocketBase::~wx_SocketBase()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_SocketBase::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketBase
//----------------------------------------------------------------------------
Gura_DeclareFunction(SocketBaseEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_SocketBase));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(SocketBaseEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_SocketBase *pEntity = new wx_SocketBase();
	Object_wx_SocketBase *pObj = Object_wx_SocketBase::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_SocketBase(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, Close)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->Close();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Destroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Destroy)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Destroy();
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Discard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Discard)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSocketBase &rtn = pThis->GetEntity()->Discard();
	return ReturnValue(env, arg, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Error)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Error)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->Error();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, GetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, GetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, GetLocal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "addr", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, GetLocal)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSockAddress *addr = Object_wx_SockAddress::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->GetLocal(*addr);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSocketFlags rtn = pThis->GetEntity()->GetFlags();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, GetPeer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "addr", VTYPE_wx_SockAddress, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, GetPeer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSockAddress *addr = Object_wx_SockAddress::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->GetPeer(*addr);
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, InterruptWait)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, InterruptWait)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->InterruptWait();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, IsConnected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, IsConnected)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsConnected();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, IsData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, IsData)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsData();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, IsDisconnected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, IsDisconnected)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsDisconnected();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, LastCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, LastCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxUint32 rtn = pThis->GetEntity()->LastCount();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, LastError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, LastError)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSocketError rtn = pThis->GetEntity()->LastError();
	return ReturnValue(env, arg, Value(new Object_wx_SocketError(new wxSocketError(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Notify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "notify", VTYPE_boolean, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_SocketBase, Notify)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool notify = arg.GetBoolean(0);
	pThis->GetEntity()->Notify(notify);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsOk();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_SocketBase, RestoreState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, RestoreState)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->RestoreState();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SaveState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, SaveState)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	pThis->GetEntity()->SaveState();
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_SocketBase, SetClientData)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int data = arg.GetInt(0);
	pThis->GetEntity()->SetClientData(data);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetEventHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "handler", VTYPE_wx_EvtHandler, OCCUR_Once);
	DeclareArg(env, "id", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementMethod(wx_SocketBase, SetEventHandler)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxEvtHandler *handler = Object_wx_EvtHandler::GetObject(arg, 0)->GetEntity();
	int id = -1;
	if (arg.IsValid(1)) id = arg.GetInt(1);
	pThis->GetEntity()->SetEventHandler(*handler, id);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_SocketBase, SetFlags)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSocketFlags flags = static_cast<wxSocketFlags>(arg.GetInt(0));
	pThis->GetEntity()->SetFlags(flags);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetLocal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "local", VTYPE_wx_IPV4address, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, SetLocal)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxIPV4address *local = Object_wx_IPV4address::GetObject(arg, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->SetLocal(*local);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetNotify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_SocketBase, SetNotify)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxSocketEventFlags flags = static_cast<wxSocketEventFlags>(arg.GetInt(0));
	pThis->GetEntity()->SetNotify(flags);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
#if 0
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
#endif
}

Gura_ImplementMethod(wx_SocketBase, SetTimeout)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int seconds = arg.GetInt(0);
	pThis->GetEntity()->SetTimeout(seconds);
	return Value::Nil;
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Peek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Peek)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int buffer = arg.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(arg.GetULong(1));
	wxSocketBase &rtn = pThis->GetEntity()->Peek(buffer, nbytes);
	return ReturnValue(env, arg, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Read)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int buffer = arg.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(arg.GetULong(1));
	wxSocketBase &rtn = pThis->GetEntity()->Read(buffer, nbytes);
	return ReturnValue(env, arg, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, ReadMsg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, ReadMsg)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int buffer = arg.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(arg.GetULong(1));
	wxSocketBase &rtn = pThis->GetEntity()->ReadMsg(buffer, nbytes);
	return ReturnValue(env, arg, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Unread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Unread)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int buffer = arg.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(arg.GetULong(1));
	wxSocketBase &rtn = pThis->GetEntity()->Unread(buffer, nbytes);
	return ReturnValue(env, arg, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Wait)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisecond", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Wait)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long seconds = -1;
	if (arg.IsValid(0)) seconds = arg.GetLong(0);
	long millisecond = 0;
	if (arg.IsValid(1)) millisecond = arg.GetLong(1);
	bool rtn = pThis->GetEntity()->Wait(seconds, millisecond);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Wait_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisecond", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Wait_1)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long seconds = -1;
	if (arg.IsValid(0)) seconds = arg.GetLong(0);
	long millisecond = 0;
	if (arg.IsValid(1)) millisecond = arg.GetLong(1);
	bool rtn = pThis->GetEntity()->Wait(seconds, millisecond);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, WaitForRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisecond", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, WaitForRead)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long seconds = -1;
	if (arg.IsValid(0)) seconds = arg.GetLong(0);
	long millisecond = 0;
	if (arg.IsValid(1)) millisecond = arg.GetLong(1);
	bool rtn = pThis->GetEntity()->WaitForRead(seconds, millisecond);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, WaitForWrite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "seconds", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisecond", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, WaitForWrite)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	long seconds = -1;
	if (arg.IsValid(0)) seconds = arg.GetLong(0);
	long millisecond = 0;
	if (arg.IsValid(1)) millisecond = arg.GetLong(1);
	bool rtn = pThis->GetEntity()->WaitForWrite(seconds, millisecond);
	return ReturnValue(env, arg, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, Write)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int buffer = arg.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(arg.GetULong(1));
	wxSocketBase &rtn = pThis->GetEntity()->Write(buffer, nbytes);
	return ReturnValue(env, arg, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, WriteMsg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_SocketBase, WriteMsg)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int buffer = arg.GetInt(0);
	wxUint32 nbytes = static_cast<wxUint32>(arg.GetULong(1));
	wxSocketBase &rtn = pThis->GetEntity()->WriteMsg(buffer, nbytes);
	return ReturnValue(env, arg, Value(new Object_wx_SocketBase(new wxSocketBase(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxSocketBase
//----------------------------------------------------------------------------
Object_wx_SocketBase::~Object_wx_SocketBase()
{
}

Object *Object_wx_SocketBase::Clone() const
{
	return nullptr;
}

String Object_wx_SocketBase::ToString(bool exprFlag)
{
	String rtn("<wx.SocketBase:");
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
// Class implementation for wxSocketBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketBase)
{
	Gura_AssignFunction(SocketBaseEmpty);
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
	return new Object_wx_SocketBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
