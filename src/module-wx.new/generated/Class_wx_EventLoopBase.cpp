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
Gura_DeclareMethodAlias(wx_EventLoopBase, __GetActive, "GetActive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __GetActive)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetActive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __SetActive, "SetActive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "loop", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, __SetActive)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int loop = arg.GetNumber(0)
	//pThis->GetEntity()->SetActive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __IsMain, "IsMain")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __IsMain)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsMain();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __Run, "Run")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __Run)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Run();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __IsRunning, "IsRunning")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __IsRunning)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsRunning();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __IsOk)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __Exit, "Exit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, __Exit)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rc = arg.GetNumber(0)
	//pThis->GetEntity()->Exit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __ScheduleExit, "ScheduleExit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "rc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, __ScheduleExit)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int rc = arg.GetNumber(0)
	//pThis->GetEntity()->ScheduleExit();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __Pending, "Pending")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __Pending)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Pending();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __Dispatch, "Dispatch")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __Dispatch)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dispatch();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __DispatchTimeout, "DispatchTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timeout", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, __DispatchTimeout)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int timeout = arg.GetNumber(0)
	//pThis->GetEntity()->DispatchTimeout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __WakeUp, "WakeUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __WakeUp)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WakeUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __WakeUpIdle, "WakeUpIdle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __WakeUpIdle)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WakeUpIdle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __ProcessIdle, "ProcessIdle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __ProcessIdle)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ProcessIdle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __IsYielding, "IsYielding")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __IsYielding)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsYielding();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __Yield, "Yield")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "onlyIfNeeded", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, __Yield)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int onlyIfNeeded = arg.GetNumber(0)
	//pThis->GetEntity()->Yield();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __YieldFor, "YieldFor")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "eventsToProcess", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, __YieldFor)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int eventsToProcess = arg.GetNumber(0)
	//pThis->GetEntity()->YieldFor();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __IsEventAllowedInsideYield, "IsEventAllowedInsideYield")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "cat", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_EventLoopBase, __IsEventAllowedInsideYield)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int cat = arg.GetNumber(0)
	//pThis->GetEntity()->IsEventAllowedInsideYield();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_EventLoopBase, __OnExit, "OnExit")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_EventLoopBase, __OnExit)
{
	Object_wx_EventLoopBase *pThis = Object_wx_EventLoopBase::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->OnExit();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxEventLoopBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EventLoopBase)
{
	Gura_AssignMethod(wx_EventLoopBase, __GetActive);
	Gura_AssignMethod(wx_EventLoopBase, __SetActive);
	Gura_AssignMethod(wx_EventLoopBase, __IsMain);
	Gura_AssignMethod(wx_EventLoopBase, __Run);
	Gura_AssignMethod(wx_EventLoopBase, __IsRunning);
	Gura_AssignMethod(wx_EventLoopBase, __IsOk);
	Gura_AssignMethod(wx_EventLoopBase, __Exit);
	Gura_AssignMethod(wx_EventLoopBase, __ScheduleExit);
	Gura_AssignMethod(wx_EventLoopBase, __Pending);
	Gura_AssignMethod(wx_EventLoopBase, __Dispatch);
	Gura_AssignMethod(wx_EventLoopBase, __DispatchTimeout);
	Gura_AssignMethod(wx_EventLoopBase, __WakeUp);
	Gura_AssignMethod(wx_EventLoopBase, __WakeUpIdle);
	Gura_AssignMethod(wx_EventLoopBase, __ProcessIdle);
	Gura_AssignMethod(wx_EventLoopBase, __IsYielding);
	Gura_AssignMethod(wx_EventLoopBase, __Yield);
	Gura_AssignMethod(wx_EventLoopBase, __YieldFor);
	Gura_AssignMethod(wx_EventLoopBase, __IsEventAllowedInsideYield);
	Gura_AssignMethod(wx_EventLoopBase, __OnExit);
}

Gura_ImplementDescendantCreator(wx_EventLoopBase)
{
	return new Object_wx_EventLoopBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
