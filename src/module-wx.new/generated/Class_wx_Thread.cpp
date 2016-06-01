//----------------------------------------------------------------------------
// wxThread
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxThread
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxThread
//----------------------------------------------------------------------------
Object_wx_Thread::~Object_wx_Thread()
{
}

Object *Object_wx_Thread::Clone() const
{
	return nullptr;
}

String Object_wx_Thread::ToString(bool exprFlag)
{
	String rtn("<wx.Thread:");
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
Gura_DeclareMethod(wx_Thread, wxThread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, wxThread)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int kind = arg.GetNumber(0)
	//pThis->GetEntity()->wxThread();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, ~wxThread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, ~wxThread)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxThread();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stackSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stackSize = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Delete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "waitMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, Delete)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rc = arg.GetNumber(0)
	//int waitMode = arg.GetNumber(1)
	//pThis->GetEntity()->Delete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, GetCPUCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, GetCPUCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCPUCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, GetCurrentId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, GetCurrentId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCurrentId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, GetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, MSWGetHandle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, MSWGetHandle)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MSWGetHandle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, GetKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, GetKind)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, GetMainId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, GetMainId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMainId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, GetPriority)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, GetPriority)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPriority();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, IsAlive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, IsAlive)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsAlive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, IsDetached)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, IsDetached)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsDetached();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, IsMain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, IsMain)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsMain();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, IsPaused)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, IsPaused)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsPaused();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, IsRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, IsRunning)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsRunning();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Kill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, Kill)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Kill();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Pause)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, Pause)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Pause();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Resume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, Resume)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Resume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Run)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, Run)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Run();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, SetConcurrency)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, SetConcurrency)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->SetConcurrency();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, SetPriority)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "priority", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, SetPriority)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int priority = arg.GetNumber(0)
	//pThis->GetEntity()->SetPriority();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Sleep)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, Sleep)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int milliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->Sleep();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, TestDestroy)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, TestDestroy)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->TestDestroy();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, This)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, This)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->This();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Wait)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, Wait)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->Wait();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Yield)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, Yield)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Yield();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Entry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, Entry)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Entry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, Exit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "exitcode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, Exit)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int exitcode = arg.GetNumber(0)
	//pThis->GetEntity()->Exit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Thread, OnExit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, OnExit)
{
	Signal &sig = env.GetSignal();
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnExit();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxThread
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Thread)
{
	Gura_AssignMethod(wx_Thread, wxThread);
	Gura_AssignMethod(wx_Thread, ~wxThread);
	Gura_AssignMethod(wx_Thread, Create);
	Gura_AssignMethod(wx_Thread, Delete);
	Gura_AssignMethod(wx_Thread, GetCPUCount);
	Gura_AssignMethod(wx_Thread, GetCurrentId);
	Gura_AssignMethod(wx_Thread, GetId);
	Gura_AssignMethod(wx_Thread, MSWGetHandle);
	Gura_AssignMethod(wx_Thread, GetKind);
	Gura_AssignMethod(wx_Thread, GetMainId);
	Gura_AssignMethod(wx_Thread, GetPriority);
	Gura_AssignMethod(wx_Thread, IsAlive);
	Gura_AssignMethod(wx_Thread, IsDetached);
	Gura_AssignMethod(wx_Thread, IsMain);
	Gura_AssignMethod(wx_Thread, IsPaused);
	Gura_AssignMethod(wx_Thread, IsRunning);
	Gura_AssignMethod(wx_Thread, Kill);
	Gura_AssignMethod(wx_Thread, Pause);
	Gura_AssignMethod(wx_Thread, Resume);
	Gura_AssignMethod(wx_Thread, Run);
	Gura_AssignMethod(wx_Thread, SetConcurrency);
	Gura_AssignMethod(wx_Thread, SetPriority);
	Gura_AssignMethod(wx_Thread, Sleep);
	Gura_AssignMethod(wx_Thread, TestDestroy);
	Gura_AssignMethod(wx_Thread, This);
	Gura_AssignMethod(wx_Thread, Wait);
	Gura_AssignMethod(wx_Thread, Yield);
	Gura_AssignMethod(wx_Thread, Entry);
	Gura_AssignMethod(wx_Thread, Exit);
	Gura_AssignMethod(wx_Thread, OnExit);
}

Gura_ImplementDescendantCreator(wx_Thread)
{
	return new Object_wx_Thread((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
