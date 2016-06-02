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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Condition, wxCondition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mutex", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Condition, wxCondition)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mutex = arg.GetNumber(0)
	//pThis->GetEntity()->wxCondition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Condition, Broadcast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, Broadcast)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Broadcast();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Condition, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, IsOk)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Condition, Signal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, Signal)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Signal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Condition, Wait)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Condition, Wait)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Wait();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Condition, Wait_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "predicate", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Condition, Wait_1)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int predicate = arg.GetNumber(0)
	//pThis->GetEntity()->Wait();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Condition, WaitTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "milliseconds", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Condition, WaitTimeout)
{
	Object_wx_Condition *pThis = Object_wx_Condition::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int milliseconds = arg.GetNumber(0)
	//pThis->GetEntity()->WaitTimeout();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxCondition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Condition)
{
	Gura_AssignMethod(wx_Condition, wxCondition);
	Gura_AssignMethod(wx_Condition, Broadcast);
	Gura_AssignMethod(wx_Condition, IsOk);
	Gura_AssignMethod(wx_Condition, Signal);
	Gura_AssignMethod(wx_Condition, Wait);
	Gura_AssignMethod(wx_Condition, Wait_1);
	Gura_AssignMethod(wx_Condition, WaitTimeout);
}

Gura_ImplementDescendantCreator(wx_Condition)
{
	return new Object_wx_Condition((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
