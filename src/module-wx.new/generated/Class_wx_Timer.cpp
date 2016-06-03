//----------------------------------------------------------------------------
// wxTimer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTimer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTimer
//----------------------------------------------------------------------------
Object_wx_Timer::~Object_wx_Timer()
{
}

Object *Object_wx_Timer::Clone() const
{
	return nullptr;
}

String Object_wx_Timer::ToString(bool exprFlag)
{
	String rtn("<wx.Timer:");
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
Gura_DeclareFunctionAlias(__Timer, "Timer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Timer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Timer)
{
	//wxTimer();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__Timer_1, "Timer_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "owner", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Timer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Timer_1)
{
	//wxEvtHandler* owner = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//wxTimer();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Timer, __GetId, "GetId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, __GetId)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Timer, __GetInterval, "GetInterval")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, __GetInterval)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetInterval();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Timer, __GetOwner, "GetOwner")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, __GetOwner)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetOwner();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Timer, __IsOneShot, "IsOneShot")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, __IsOneShot)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOneShot();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Timer, __IsRunning, "IsRunning")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, __IsRunning)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsRunning();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Timer, __Notify, "Notify")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, __Notify)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Notify();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Timer, __SetOwner, "SetOwner")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "owner", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Timer, __SetOwner)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxEvtHandler* owner = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->SetOwner();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Timer, __Start, "Start")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oneShot", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Timer, __Start)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int milliseconds = arg.GetNumber(0)
	//bool oneShot = arg.GetNumber(1)
	//pThis->GetEntity()->Start();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Timer, __StartOnce, "StartOnce")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Timer, __StartOnce)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int milliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->StartOnce();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Timer, __Stop, "Stop")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, __Stop)
{
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTimer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Timer)
{
	// Constructor assignment
	Gura_AssignFunction(__Timer);
	Gura_AssignFunction(__Timer_1);
	// Method assignment
	Gura_AssignMethod(wx_Timer, __GetId);
	Gura_AssignMethod(wx_Timer, __GetInterval);
	Gura_AssignMethod(wx_Timer, __GetOwner);
	Gura_AssignMethod(wx_Timer, __IsOneShot);
	Gura_AssignMethod(wx_Timer, __IsRunning);
	Gura_AssignMethod(wx_Timer, __Notify);
	Gura_AssignMethod(wx_Timer, __SetOwner);
	Gura_AssignMethod(wx_Timer, __Start);
	Gura_AssignMethod(wx_Timer, __StartOnce);
	Gura_AssignMethod(wx_Timer, __Stop);
}

Gura_ImplementDescendantCreator(wx_Timer)
{
	return new Object_wx_Timer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
