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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Thread, "Thread")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Thread));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Thread)
{
	//wxThreadKind kind = arg.GetNumber(0)
	//wxThread(kind);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Thread, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "stackSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, __Create)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int stackSize = arg.GetNumber(0)
	//wxThreadError _rtn = pThis->GetEntity()->Create(stackSize);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __Delete, "Delete")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "rc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "waitMode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, __Delete)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//ExitCode* rc = arg.GetNumber(0)
	//wxThreadWait waitMode = arg.GetNumber(1)
	//wxThreadError _rtn = pThis->GetEntity()->Delete(rc, waitMode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __GetCPUCount, "GetCPUCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __GetCPUCount)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetCPUCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __GetCurrentId, "GetCurrentId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __GetCurrentId)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThreadIdType _rtn = pThis->GetEntity()->GetCurrentId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __GetId, "GetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __GetId)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThreadIdType _rtn = pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __MSWGetHandle, "MSWGetHandle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __MSWGetHandle)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//WXHANDLE _rtn = pThis->GetEntity()->MSWGetHandle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __GetKind, "GetKind")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __GetKind)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThreadKind _rtn = pThis->GetEntity()->GetKind();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __GetMainId, "GetMainId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __GetMainId)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThreadIdType _rtn = pThis->GetEntity()->GetMainId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __GetPriority, "GetPriority")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __GetPriority)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int _rtn = pThis->GetEntity()->GetPriority();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __IsAlive, "IsAlive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __IsAlive)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsAlive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __IsDetached, "IsDetached")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __IsDetached)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsDetached();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __IsMain, "IsMain")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __IsMain)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsMain();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __IsPaused, "IsPaused")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __IsPaused)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsPaused();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __IsRunning, "IsRunning")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __IsRunning)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->IsRunning();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __Kill, "Kill")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __Kill)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThreadError _rtn = pThis->GetEntity()->Kill();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __Pause, "Pause")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __Pause)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThreadError _rtn = pThis->GetEntity()->Pause();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __Resume, "Resume")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __Resume)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThreadError _rtn = pThis->GetEntity()->Resume();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __Run, "Run")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __Run)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThreadError _rtn = pThis->GetEntity()->Run();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __SetConcurrency, "SetConcurrency")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, __SetConcurrency)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//size_t level = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->SetConcurrency(level);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __SetPriority, "SetPriority")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "priority", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, __SetPriority)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned int priority = arg.GetNumber(0)
	//pThis->GetEntity()->SetPriority(priority);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __Sleep, "Sleep")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, __Sleep)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned long milliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->Sleep(milliseconds);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __TestDestroy, "TestDestroy")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __TestDestroy)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->TestDestroy();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __This, "This")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __This)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThread* _rtn = pThis->GetEntity()->This();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __Wait, "Wait")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, __Wait)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxThreadWait flags = arg.GetNumber(0)
	//ExitCode _rtn = pThis->GetEntity()->Wait(flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __Yield, "Yield")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __Yield)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Yield();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __Entry, "Entry")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __Entry)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//ExitCode _rtn = pThis->GetEntity()->Entry();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __Exit, "Exit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "exitcode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Thread, __Exit)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//ExitCode exitcode = arg.GetNumber(0)
	//pThis->GetEntity()->Exit(exitcode);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Thread, __OnExit, "OnExit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Thread, __OnExit)
{
	Object_wx_Thread *pThis = Object_wx_Thread::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnExit();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxThread
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Thread)
{
	// Constructor assignment
	Gura_AssignFunction(__Thread);
	// Method assignment
	Gura_AssignMethod(wx_Thread, __Create);
	Gura_AssignMethod(wx_Thread, __Delete);
	Gura_AssignMethod(wx_Thread, __GetCPUCount);
	Gura_AssignMethod(wx_Thread, __GetCurrentId);
	Gura_AssignMethod(wx_Thread, __GetId);
	Gura_AssignMethod(wx_Thread, __MSWGetHandle);
	Gura_AssignMethod(wx_Thread, __GetKind);
	Gura_AssignMethod(wx_Thread, __GetMainId);
	Gura_AssignMethod(wx_Thread, __GetPriority);
	Gura_AssignMethod(wx_Thread, __IsAlive);
	Gura_AssignMethod(wx_Thread, __IsDetached);
	Gura_AssignMethod(wx_Thread, __IsMain);
	Gura_AssignMethod(wx_Thread, __IsPaused);
	Gura_AssignMethod(wx_Thread, __IsRunning);
	Gura_AssignMethod(wx_Thread, __Kill);
	Gura_AssignMethod(wx_Thread, __Pause);
	Gura_AssignMethod(wx_Thread, __Resume);
	Gura_AssignMethod(wx_Thread, __Run);
	Gura_AssignMethod(wx_Thread, __SetConcurrency);
	Gura_AssignMethod(wx_Thread, __SetPriority);
	Gura_AssignMethod(wx_Thread, __Sleep);
	Gura_AssignMethod(wx_Thread, __TestDestroy);
	Gura_AssignMethod(wx_Thread, __This);
	Gura_AssignMethod(wx_Thread, __Wait);
	Gura_AssignMethod(wx_Thread, __Yield);
	Gura_AssignMethod(wx_Thread, __Entry);
	Gura_AssignMethod(wx_Thread, __Exit);
	Gura_AssignMethod(wx_Thread, __OnExit);
}

Gura_ImplementDescendantCreator(wx_Thread)
{
	return new Object_wx_Thread((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
