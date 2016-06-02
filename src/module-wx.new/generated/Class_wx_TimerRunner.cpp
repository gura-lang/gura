//----------------------------------------------------------------------------
// wxTimerRunner
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTimerRunner
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTimerRunner
//----------------------------------------------------------------------------
Object_wx_TimerRunner::~Object_wx_TimerRunner()
{
}

Object *Object_wx_TimerRunner::Clone() const
{
	return nullptr;
}

String Object_wx_TimerRunner::ToString(bool exprFlag)
{
	String rtn("<wx.TimerRunner:");
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
Gura_DeclareMethod(wx_TimerRunner, wxTimerRunner)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimerRunner, wxTimerRunner)
{
	Object_wx_TimerRunner *pThis = Object_wx_TimerRunner::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int timer = arg.GetNumber(0)
	//pThis->GetEntity()->wxTimerRunner();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimerRunner, wxTimerRunner_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "milli", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oneShot", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimerRunner, wxTimerRunner_1)
{
	Object_wx_TimerRunner *pThis = Object_wx_TimerRunner::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int timer = arg.GetNumber(0)
	//int milli = arg.GetNumber(1)
	//int oneShot = arg.GetNumber(2)
	//pThis->GetEntity()->wxTimerRunner();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimerRunner, Start)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milli", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oneShot", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimerRunner, Start)
{
	Object_wx_TimerRunner *pThis = Object_wx_TimerRunner::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int milli = arg.GetNumber(0)
	//int oneShot = arg.GetNumber(1)
	//pThis->GetEntity()->Start();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTimerRunner
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimerRunner)
{
	Gura_AssignMethod(wx_TimerRunner, wxTimerRunner);
	Gura_AssignMethod(wx_TimerRunner, wxTimerRunner_1);
	Gura_AssignMethod(wx_TimerRunner, Start);
}

Gura_ImplementDescendantCreator(wx_TimerRunner)
{
	return new Object_wx_TimerRunner((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
