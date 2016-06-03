//----------------------------------------------------------------------------
// wxCondition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCondition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCondition
//----------------------------------------------------------------------------
Object_wx_Condition::~Object_wx_Condition()
{
}

Object *Object_wx_Condition::Clone() const
{
	return nullptr;
}

String Object_wx_Condition::ToString(bool exprFlag)
{
	String rtn("<wx.Condition:");
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
Gura_DeclareFunctionAlias(__Condition, "Condition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mutex", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Condition));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Condition)
{
	//wxMutex& mutex = arg.GetNumber(0)
	//wxCondition();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Condition, __Broadcast, "Broadcast")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, __Broadcast)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Broadcast();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Condition, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, __IsOk)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Condition, __Signal, "Signal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, __Signal)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Signal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Condition, __Wait, "Wait")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, __Wait)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Wait();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Condition, __Wait_1, "Wait_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "predicate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Condition, __Wait_1)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const Functor& predicate = arg.GetNumber(0)
	//pThis->GetEntity()->Wait();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Condition, __WaitTimeout, "WaitTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Condition, __WaitTimeout)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned long milliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->WaitTimeout();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCondition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Condition)
{
	// Constructor assignment
	Gura_AssignFunction(__Condition);
	// Method assignment
	Gura_AssignMethod(wx_Condition, __Broadcast);
	Gura_AssignMethod(wx_Condition, __IsOk);
	Gura_AssignMethod(wx_Condition, __Signal);
	Gura_AssignMethod(wx_Condition, __Wait);
	Gura_AssignMethod(wx_Condition, __Wait_1);
	Gura_AssignMethod(wx_Condition, __WaitTimeout);
}

Gura_ImplementDescendantCreator(wx_Condition)
{
	return new Object_wx_Condition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
