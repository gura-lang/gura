//----------------------------------------------------------------------------
// wxSocketBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSocketBase
//----------------------------------------------------------------------------

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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_SocketBase, wxSocketBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, wxSocketBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxSocketBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, ~wxSocketBase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, ~wxSocketBase)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxSocketBase();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Destroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, Destroy)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Destroy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Initialize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, Initialize)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Initialize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Shutdown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, Shutdown)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Shutdown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Error)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, Error)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Error();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, GetLocal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "addr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, GetLocal)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int addr = arg.GetNumber(0)
	//pThis->GetEntity()->GetLocal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, GetPeer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "addr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, GetPeer)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int addr = arg.GetNumber(0)
	//pThis->GetEntity()->GetPeer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, GetTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, GetTimeout)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTimeout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, IsConnected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, IsConnected)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsConnected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, IsData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, IsData)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, IsDisconnected)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, IsDisconnected)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDisconnected();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, LastCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, LastCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LastCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, LastReadCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, LastReadCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LastReadCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, LastWriteCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, LastWriteCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LastWriteCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, LastError)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, LastError)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LastError();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, RestoreState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, RestoreState)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RestoreState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SaveState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, SaveState)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->SaveState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Close)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, Close)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Close();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, ShutdownOutput)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, ShutdownOutput)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShutdownOutput();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Discard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, Discard)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Discard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, GetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, InterruptWait)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, InterruptWait)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->InterruptWait();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Peek)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, Peek)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int nbytes = arg.GetNumber(1)
	//pThis->GetEntity()->Peek();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, Read)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int nbytes = arg.GetNumber(1)
	//pThis->GetEntity()->Read();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, ReadMsg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, ReadMsg)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int nbytes = arg.GetNumber(1)
	//pThis->GetEntity()->ReadMsg();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, SetFlags)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetLocal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "local", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, SetLocal)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int local = arg.GetNumber(0)
	//pThis->GetEntity()->SetLocal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, SetTimeout)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int seconds = arg.GetNumber(0)
	//pThis->GetEntity()->SetTimeout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Unread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, Unread)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int nbytes = arg.GetNumber(1)
	//pThis->GetEntity()->Unread();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Wait)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "millisecond", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, Wait)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int seconds = arg.GetNumber(0)
	//int millisecond = arg.GetNumber(1)
	//pThis->GetEntity()->Wait();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, WaitForLost)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "millisecond", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, WaitForLost)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int seconds = arg.GetNumber(0)
	//int millisecond = arg.GetNumber(1)
	//pThis->GetEntity()->WaitForLost();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, WaitForRead)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "millisecond", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, WaitForRead)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int seconds = arg.GetNumber(0)
	//int millisecond = arg.GetNumber(1)
	//pThis->GetEntity()->WaitForRead();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, WaitForWrite)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "seconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "millisecond", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, WaitForWrite)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int seconds = arg.GetNumber(0)
	//int millisecond = arg.GetNumber(1)
	//pThis->GetEntity()->WaitForWrite();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Write)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, Write)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int nbytes = arg.GetNumber(1)
	//pThis->GetEntity()->Write();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, WriteMsg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "buffer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "nbytes", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, WriteMsg)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int buffer = arg.GetNumber(0)
	//int nbytes = arg.GetNumber(1)
	//pThis->GetEntity()->WriteMsg();
	return Value::Nil;
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
	//pThis->GetEntity()->GetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, Notify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "notify", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, Notify)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int notify = arg.GetNumber(0)
	//pThis->GetEntity()->Notify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetClientData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, SetClientData)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int data = arg.GetNumber(0)
	//pThis->GetEntity()->SetClientData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetEventHandler)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "handler", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, SetEventHandler)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int handler = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->SetEventHandler();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, SetNotify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SocketBase, SetNotify)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetNotify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SocketBase, GetSocket)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SocketBase, GetSocket)
{
	Signal &sig = env.GetSignal();
	Object_wx_SocketBase *pThis = Object_wx_SocketBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSocket();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSocketBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SocketBase)
{
	Gura_AssignMethod(wx_SocketBase, wxSocketBase);
	Gura_AssignMethod(wx_SocketBase, ~wxSocketBase);
	Gura_AssignMethod(wx_SocketBase, Destroy);
	Gura_AssignMethod(wx_SocketBase, Initialize);
	Gura_AssignMethod(wx_SocketBase, Shutdown);
	Gura_AssignMethod(wx_SocketBase, Error);
	Gura_AssignMethod(wx_SocketBase, GetLocal);
	Gura_AssignMethod(wx_SocketBase, GetPeer);
	Gura_AssignMethod(wx_SocketBase, GetTimeout);
	Gura_AssignMethod(wx_SocketBase, IsConnected);
	Gura_AssignMethod(wx_SocketBase, IsData);
	Gura_AssignMethod(wx_SocketBase, IsDisconnected);
	Gura_AssignMethod(wx_SocketBase, IsOk);
	Gura_AssignMethod(wx_SocketBase, LastCount);
	Gura_AssignMethod(wx_SocketBase, LastReadCount);
	Gura_AssignMethod(wx_SocketBase, LastWriteCount);
	Gura_AssignMethod(wx_SocketBase, LastError);
	Gura_AssignMethod(wx_SocketBase, RestoreState);
	Gura_AssignMethod(wx_SocketBase, SaveState);
	Gura_AssignMethod(wx_SocketBase, Close);
	Gura_AssignMethod(wx_SocketBase, ShutdownOutput);
	Gura_AssignMethod(wx_SocketBase, Discard);
	Gura_AssignMethod(wx_SocketBase, GetFlags);
	Gura_AssignMethod(wx_SocketBase, InterruptWait);
	Gura_AssignMethod(wx_SocketBase, Peek);
	Gura_AssignMethod(wx_SocketBase, Read);
	Gura_AssignMethod(wx_SocketBase, ReadMsg);
	Gura_AssignMethod(wx_SocketBase, SetFlags);
	Gura_AssignMethod(wx_SocketBase, SetLocal);
	Gura_AssignMethod(wx_SocketBase, SetTimeout);
	Gura_AssignMethod(wx_SocketBase, Unread);
	Gura_AssignMethod(wx_SocketBase, Wait);
	Gura_AssignMethod(wx_SocketBase, WaitForLost);
	Gura_AssignMethod(wx_SocketBase, WaitForRead);
	Gura_AssignMethod(wx_SocketBase, WaitForWrite);
	Gura_AssignMethod(wx_SocketBase, Write);
	Gura_AssignMethod(wx_SocketBase, WriteMsg);
	Gura_AssignMethod(wx_SocketBase, GetClientData);
	Gura_AssignMethod(wx_SocketBase, Notify);
	Gura_AssignMethod(wx_SocketBase, SetClientData);
	Gura_AssignMethod(wx_SocketBase, SetEventHandler);
	Gura_AssignMethod(wx_SocketBase, SetNotify);
	Gura_AssignMethod(wx_SocketBase, GetSocket);
}

Gura_ImplementDescendantCreator(wx_SocketBase)
{
	return new Object_wx_SocketBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
