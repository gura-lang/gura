//----------------------------------------------------------------------------
// wxEventLoopBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEventLoopBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEventLoopBase
//----------------------------------------------------------------------------
Object_wx_EventLoopBase::~Object_wx_EventLoopBase()
{
}

Object *Object_wx_EventLoopBase::Clone() const
{
	return nullptr;
}

String Object_wx_EventLoopBase::ToString(bool exprFlag)
{
	String rtn("<wx.EventLoopBase:");
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
Gura_DeclareMethod(wx_EventLoopBase, GetActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, GetActive)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, SetActive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, SetActive)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int loop = arg.GetNumber(0)
	//pThis->GetEntity()->SetActive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, IsMain)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, IsMain)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsMain();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, Run)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, Run)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Run();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, IsRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, IsRunning)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsRunning();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, IsOk)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, Exit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, Exit)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rc = arg.GetNumber(0)
	//pThis->GetEntity()->Exit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, ScheduleExit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, ScheduleExit)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int rc = arg.GetNumber(0)
	//pThis->GetEntity()->ScheduleExit();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, Pending)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, Pending)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Pending();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, Dispatch)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, Dispatch)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Dispatch();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, DispatchTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timeout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, DispatchTimeout)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int timeout = arg.GetNumber(0)
	//pThis->GetEntity()->DispatchTimeout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, WakeUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, WakeUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WakeUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, WakeUpIdle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, WakeUpIdle)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->WakeUpIdle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, ProcessIdle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, ProcessIdle)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ProcessIdle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, IsYielding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, IsYielding)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsYielding();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, Yield)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "onlyIfNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, Yield)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int onlyIfNeeded = arg.GetNumber(0)
	//pThis->GetEntity()->Yield();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, YieldFor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventsToProcess", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, YieldFor)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int eventsToProcess = arg.GetNumber(0)
	//pThis->GetEntity()->YieldFor();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, IsEventAllowedInsideYield)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, IsEventAllowedInsideYield)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int cat = arg.GetNumber(0)
	//pThis->GetEntity()->IsEventAllowedInsideYield();
	return Value::Nil;
}

Gura_DeclareMethod(wx_EventLoopBase, OnExit)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, OnExit)
{
	Signal &sig = env.GetSignal();
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnExit();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEventLoopBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventLoopBase)
{
	Gura_AssignMethod(wx_EventLoopBase, GetActive);
	Gura_AssignMethod(wx_EventLoopBase, SetActive);
	Gura_AssignMethod(wx_EventLoopBase, IsMain);
	Gura_AssignMethod(wx_EventLoopBase, Run);
	Gura_AssignMethod(wx_EventLoopBase, IsRunning);
	Gura_AssignMethod(wx_EventLoopBase, IsOk);
	Gura_AssignMethod(wx_EventLoopBase, Exit);
	Gura_AssignMethod(wx_EventLoopBase, ScheduleExit);
	Gura_AssignMethod(wx_EventLoopBase, Pending);
	Gura_AssignMethod(wx_EventLoopBase, Dispatch);
	Gura_AssignMethod(wx_EventLoopBase, DispatchTimeout);
	Gura_AssignMethod(wx_EventLoopBase, WakeUp);
	Gura_AssignMethod(wx_EventLoopBase, WakeUpIdle);
	Gura_AssignMethod(wx_EventLoopBase, ProcessIdle);
	Gura_AssignMethod(wx_EventLoopBase, IsYielding);
	Gura_AssignMethod(wx_EventLoopBase, Yield);
	Gura_AssignMethod(wx_EventLoopBase, YieldFor);
	Gura_AssignMethod(wx_EventLoopBase, IsEventAllowedInsideYield);
	Gura_AssignMethod(wx_EventLoopBase, OnExit);
}

Gura_ImplementDescendantCreator(wx_EventLoopBase)
{
	return new Object_wx_EventLoopBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
