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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TimerRunner, "TimerRunner")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timer", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TimerRunner));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TimerRunner)
{
	//int timer = arg.GetNumber(0)
	//wxTimerRunner();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TimerRunner_1, "TimerRunner_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timer", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "milli", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oneShot", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TimerRunner));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TimerRunner_1)
{
	//int timer = arg.GetNumber(0)
	//int milli = arg.GetNumber(1)
	//int oneShot = arg.GetNumber(2)
	//wxTimerRunner();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TimerRunner, __Start, "Start")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milli", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "oneShot", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimerRunner, __Start)
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
	// Constructor assignment
	Gura_AssignFunction(__TimerRunner);
	Gura_AssignFunction(__TimerRunner_1);
	// Method assignment
	Gura_AssignMethod(wx_TimerRunner, __Start);
}

Gura_ImplementDescendantCreator(wx_TimerRunner)
{
	return new Object_wx_TimerRunner((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
