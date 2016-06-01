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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Timer, wxTimer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, wxTimer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTimer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, wxTimer_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "owner", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Timer, wxTimer_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int owner = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->wxTimer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, ~wxTimer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, ~wxTimer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxTimer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, GetId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, GetId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, GetInterval)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, GetInterval)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetInterval();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, GetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, GetOwner)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetOwner();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, IsOneShot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, IsOneShot)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsOneShot();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, IsRunning)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, IsRunning)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsRunning();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, Notify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, Notify)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Notify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, SetOwner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "owner", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Timer, SetOwner)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int owner = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//pThis->GetEntity()->SetOwner();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, Start)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oneShot", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Timer, Start)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int milliseconds = arg.GetNumber(0)
	//int oneShot = arg.GetNumber(1)
	//pThis->GetEntity()->Start();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, StartOnce)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Timer, StartOnce)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int milliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->StartOnce();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Timer, Stop)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Timer, Stop)
{
	Signal &sig = env.GetSignal();
	Object_wx_Timer *pThis = Object_wx_Timer::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Stop();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTimer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Timer)
{
	Gura_AssignMethod(wx_Timer, wxTimer);
	Gura_AssignMethod(wx_Timer, wxTimer_1);
	Gura_AssignMethod(wx_Timer, ~wxTimer);
	Gura_AssignMethod(wx_Timer, GetId);
	Gura_AssignMethod(wx_Timer, GetInterval);
	Gura_AssignMethod(wx_Timer, GetOwner);
	Gura_AssignMethod(wx_Timer, IsOneShot);
	Gura_AssignMethod(wx_Timer, IsRunning);
	Gura_AssignMethod(wx_Timer, Notify);
	Gura_AssignMethod(wx_Timer, SetOwner);
	Gura_AssignMethod(wx_Timer, Start);
	Gura_AssignMethod(wx_Timer, StartOnce);
	Gura_AssignMethod(wx_Timer, Stop);
}

Gura_ImplementDescendantCreator(wx_Timer)
{
	return new Object_wx_Timer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
