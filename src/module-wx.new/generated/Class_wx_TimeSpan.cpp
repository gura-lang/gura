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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TimeSpan, wxTimeSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, wxTimeSpan)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxTimeSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, wxTimeSpan_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hours", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, wxTimeSpan_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int hours = arg.GetNumber(0)
	//int min = arg.GetNumber(1)
	//int sec = arg.GetNumber(2)
	//int msec = arg.GetNumber(3)
	//pThis->GetEntity()->wxTimeSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Abs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, Abs)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Abs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Day)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, Day)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Day();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Days)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "days", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Days)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int days = arg.GetNumber(0)
	//pThis->GetEntity()->Days();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "format", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Format)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int format = arg.GetNumber(0)
	//pThis->GetEntity()->Format();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, GetDays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, GetDays)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDays();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, GetHours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, GetHours)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHours();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, GetMilliseconds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, GetMilliseconds)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMilliseconds();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, GetMinutes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, GetMinutes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMinutes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, GetSeconds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, GetSeconds)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSeconds();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, GetWeeks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, GetWeeks)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWeeks();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Hour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, Hour)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Hour();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Hours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hours", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Hours)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int hours = arg.GetNumber(0)
	//pThis->GetEntity()->Hours();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, IsEqualTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ts", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, IsEqualTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ts = arg.GetNumber(0)
	//pThis->GetEntity()->IsEqualTo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, IsLongerThan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ts", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, IsLongerThan)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ts = arg.GetNumber(0)
	//pThis->GetEntity()->IsLongerThan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, IsNegative)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, IsNegative)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsNegative();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, IsNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, IsNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsNull();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, IsPositive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, IsPositive)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsPositive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, IsShorterThan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ts", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, IsShorterThan)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ts = arg.GetNumber(0)
	//pThis->GetEntity()->IsShorterThan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Millisecond)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, Millisecond)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Millisecond();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Milliseconds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ms", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Milliseconds)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ms = arg.GetNumber(0)
	//pThis->GetEntity()->Milliseconds();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Minute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, Minute)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Minute();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Minutes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Minutes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int min = arg.GetNumber(0)
	//pThis->GetEntity()->Minutes();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Multiply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Multiply)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Multiply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Multiply_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Multiply_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->Multiply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Neg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, Neg)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Neg();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Negate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, Negate)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Negate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Second)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, Second)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Second();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Seconds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Seconds)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sec = arg.GetNumber(0)
	//pThis->GetEntity()->Seconds();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Subtract)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Subtract)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Subtract_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "diff", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Subtract_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int diff = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Week)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TimeSpan, Week)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Week();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Weeks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "weeks", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TimeSpan, Weeks)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int weeks = arg.GetNumber(0)
	//pThis->GetEntity()->Weeks();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTimeSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimeSpan)
{
	Gura_AssignMethod(wx_TimeSpan, wxTimeSpan);
	Gura_AssignMethod(wx_TimeSpan, wxTimeSpan_1);
	Gura_AssignMethod(wx_TimeSpan, Abs);
	Gura_AssignMethod(wx_TimeSpan, Add);
	Gura_AssignMethod(wx_TimeSpan, Add_1);
	Gura_AssignMethod(wx_TimeSpan, Day);
	Gura_AssignMethod(wx_TimeSpan, Days);
	Gura_AssignMethod(wx_TimeSpan, Format);
	Gura_AssignMethod(wx_TimeSpan, GetDays);
	Gura_AssignMethod(wx_TimeSpan, GetHours);
	Gura_AssignMethod(wx_TimeSpan, GetMilliseconds);
	Gura_AssignMethod(wx_TimeSpan, GetMinutes);
	Gura_AssignMethod(wx_TimeSpan, GetSeconds);
	Gura_AssignMethod(wx_TimeSpan, GetValue);
	Gura_AssignMethod(wx_TimeSpan, GetWeeks);
	Gura_AssignMethod(wx_TimeSpan, Hour);
	Gura_AssignMethod(wx_TimeSpan, Hours);
	Gura_AssignMethod(wx_TimeSpan, IsEqualTo);
	Gura_AssignMethod(wx_TimeSpan, IsLongerThan);
	Gura_AssignMethod(wx_TimeSpan, IsNegative);
	Gura_AssignMethod(wx_TimeSpan, IsNull);
	Gura_AssignMethod(wx_TimeSpan, IsPositive);
	Gura_AssignMethod(wx_TimeSpan, IsShorterThan);
	Gura_AssignMethod(wx_TimeSpan, Millisecond);
	Gura_AssignMethod(wx_TimeSpan, Milliseconds);
	Gura_AssignMethod(wx_TimeSpan, Minute);
	Gura_AssignMethod(wx_TimeSpan, Minutes);
	Gura_AssignMethod(wx_TimeSpan, Multiply);
	Gura_AssignMethod(wx_TimeSpan, Multiply_1);
	Gura_AssignMethod(wx_TimeSpan, Neg);
	Gura_AssignMethod(wx_TimeSpan, Negate);
	Gura_AssignMethod(wx_TimeSpan, Second);
	Gura_AssignMethod(wx_TimeSpan, Seconds);
	Gura_AssignMethod(wx_TimeSpan, Subtract);
	Gura_AssignMethod(wx_TimeSpan, Subtract_1);
	Gura_AssignMethod(wx_TimeSpan, Week);
	Gura_AssignMethod(wx_TimeSpan, Weeks);
}

Gura_ImplementDescendantCreator(wx_TimeSpan)
{
	return new Object_wx_TimeSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
