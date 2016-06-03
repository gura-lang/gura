//----------------------------------------------------------------------------
// wxTimeSpan
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTimeSpan
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTimeSpan
//----------------------------------------------------------------------------
Object_wx_TimeSpan::~Object_wx_TimeSpan()
{
}

Object *Object_wx_TimeSpan::Clone() const
{
	return nullptr;
}

String Object_wx_TimeSpan::ToString(bool exprFlag)
{
	String rtn("<wx.TimeSpan:");
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
Gura_DeclareFunctionAlias(__TimeSpan, "TimeSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TimeSpan));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TimeSpan)
{
	//wxTimeSpan();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TimeSpan_1, "TimeSpan_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hours", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msec", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TimeSpan));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TimeSpan_1)
{
	//int hours = arg.GetNumber(0)
	//int min = arg.GetNumber(1)
	//int sec = arg.GetNumber(2)
	//int msec = arg.GetNumber(3)
	//wxTimeSpan();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TimeSpan, __Abs, "Abs")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __Abs)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Abs();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Add)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Add_1, "Add_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Add_1)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Day, "Day")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __Day)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Day();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Days, "Days")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "days", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Days)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int days = arg.GetNumber(0)
	//pThis->GetEntity()->Days();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Format, "Format")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Format)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->Format();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __GetDays, "GetDays")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __GetDays)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDays();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __GetHours, "GetHours")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __GetHours)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetHours();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __GetMilliseconds, "GetMilliseconds")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __GetMilliseconds)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMilliseconds();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __GetMinutes, "GetMinutes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __GetMinutes)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMinutes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __GetSeconds, "GetSeconds")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __GetSeconds)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSeconds();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __GetValue)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __GetWeeks, "GetWeeks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __GetWeeks)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWeeks();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Hour, "Hour")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __Hour)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Hour();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Hours, "Hours")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hours", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Hours)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int hours = arg.GetNumber(0)
	//pThis->GetEntity()->Hours();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __IsEqualTo, "IsEqualTo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ts", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __IsEqualTo)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ts = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqualTo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __IsLongerThan, "IsLongerThan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ts", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __IsLongerThan)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ts = arg.GetNumber(0)
	//pThis->GetEntity()->IsLongerThan();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __IsNegative, "IsNegative")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __IsNegative)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsNegative();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __IsNull, "IsNull")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __IsNull)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsNull();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __IsPositive, "IsPositive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __IsPositive)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPositive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __IsShorterThan, "IsShorterThan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ts", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __IsShorterThan)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ts = arg.GetNumber(0)
	//pThis->GetEntity()->IsShorterThan();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Millisecond, "Millisecond")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __Millisecond)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Millisecond();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Milliseconds, "Milliseconds")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ms", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Milliseconds)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ms = arg.GetNumber(0)
	//pThis->GetEntity()->Milliseconds();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Minute, "Minute")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __Minute)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Minute();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Minutes, "Minutes")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Minutes)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->Minutes();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Multiply, "Multiply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Multiply)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Multiply();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Multiply_1, "Multiply_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Multiply_1)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Multiply();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Neg, "Neg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __Neg)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Neg();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Negate, "Negate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __Negate)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Negate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Second, "Second")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __Second)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Second();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Seconds, "Seconds")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Seconds)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sec = arg.GetNumber(0)
	//pThis->GetEntity()->Seconds();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Subtract, "Subtract")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Subtract)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Subtract_1, "Subtract_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Subtract_1)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Week, "Week")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, __Week)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Week();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TimeSpan, __Weeks, "Weeks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "weeks", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, __Weeks)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int weeks = arg.GetNumber(0)
	//pThis->GetEntity()->Weeks();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTimeSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimeSpan)
{
	// Constructor assignment
	Gura_AssignFunction(__TimeSpan);
	Gura_AssignFunction(__TimeSpan_1);
	// Method assignment
	Gura_AssignMethod(wx_TimeSpan, __Abs);
	Gura_AssignMethod(wx_TimeSpan, __Add);
	Gura_AssignMethod(wx_TimeSpan, __Add_1);
	Gura_AssignMethod(wx_TimeSpan, __Day);
	Gura_AssignMethod(wx_TimeSpan, __Days);
	Gura_AssignMethod(wx_TimeSpan, __Format);
	Gura_AssignMethod(wx_TimeSpan, __GetDays);
	Gura_AssignMethod(wx_TimeSpan, __GetHours);
	Gura_AssignMethod(wx_TimeSpan, __GetMilliseconds);
	Gura_AssignMethod(wx_TimeSpan, __GetMinutes);
	Gura_AssignMethod(wx_TimeSpan, __GetSeconds);
	Gura_AssignMethod(wx_TimeSpan, __GetValue);
	Gura_AssignMethod(wx_TimeSpan, __GetWeeks);
	Gura_AssignMethod(wx_TimeSpan, __Hour);
	Gura_AssignMethod(wx_TimeSpan, __Hours);
	Gura_AssignMethod(wx_TimeSpan, __IsEqualTo);
	Gura_AssignMethod(wx_TimeSpan, __IsLongerThan);
	Gura_AssignMethod(wx_TimeSpan, __IsNegative);
	Gura_AssignMethod(wx_TimeSpan, __IsNull);
	Gura_AssignMethod(wx_TimeSpan, __IsPositive);
	Gura_AssignMethod(wx_TimeSpan, __IsShorterThan);
	Gura_AssignMethod(wx_TimeSpan, __Millisecond);
	Gura_AssignMethod(wx_TimeSpan, __Milliseconds);
	Gura_AssignMethod(wx_TimeSpan, __Minute);
	Gura_AssignMethod(wx_TimeSpan, __Minutes);
	Gura_AssignMethod(wx_TimeSpan, __Multiply);
	Gura_AssignMethod(wx_TimeSpan, __Multiply_1);
	Gura_AssignMethod(wx_TimeSpan, __Neg);
	Gura_AssignMethod(wx_TimeSpan, __Negate);
	Gura_AssignMethod(wx_TimeSpan, __Second);
	Gura_AssignMethod(wx_TimeSpan, __Seconds);
	Gura_AssignMethod(wx_TimeSpan, __Subtract);
	Gura_AssignMethod(wx_TimeSpan, __Subtract_1);
	Gura_AssignMethod(wx_TimeSpan, __Week);
	Gura_AssignMethod(wx_TimeSpan, __Weeks);
}

Gura_ImplementDescendantCreator(wx_TimeSpan)
{
	return new Object_wx_TimeSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
