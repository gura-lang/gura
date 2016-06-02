//----------------------------------------------------------------------------
// wxDateSpan
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDateSpan
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDateSpan
//----------------------------------------------------------------------------
Object_wx_DateSpan::~Object_wx_DateSpan()
{
}

Object *Object_wx_DateSpan::Clone() const
{
	return nullptr;
}

String Object_wx_DateSpan::ToString(bool exprFlag)
{
	String rtn("<wx.DateSpan:");
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
Gura_DeclareMethod(wx_DateSpan, wxDateSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "years", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "months", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weeks", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "days", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, wxDateSpan)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int years = arg.GetNumber(0)
	//int months = arg.GetNumber(1)
	//int weeks = arg.GetNumber(2)
	//int days = arg.GetNumber(3)
	//pThis->GetEntity()->wxDateSpan();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, Add)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, Add_1)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->Add();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Day)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, Day)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Day();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Days)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "days", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, Days)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int days = arg.GetNumber(0)
	//pThis->GetEntity()->Days();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, GetDays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, GetDays)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDays();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, GetMonths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, GetMonths)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMonths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, GetTotalMonths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, GetTotalMonths)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTotalMonths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, GetTotalDays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, GetTotalDays)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetTotalDays();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, GetWeeks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, GetWeeks)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWeeks();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, GetYears)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, GetYears)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetYears();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Month)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, Month)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Month();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Months)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, Months)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mon = arg.GetNumber(0)
	//pThis->GetEntity()->Months();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Multiply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, Multiply)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int factor = arg.GetNumber(0)
	//pThis->GetEntity()->Multiply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Multiply_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, Multiply_1)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int factor = arg.GetNumber(0)
	//pThis->GetEntity()->Multiply();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Neg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, Neg)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Neg();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Negate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, Negate)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Negate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, SetDays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, SetDays)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetDays();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, SetMonths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, SetMonths)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetMonths();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, SetWeeks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, SetWeeks)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetWeeks();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, SetYears)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, SetYears)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//pThis->GetEntity()->SetYears();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Subtract)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, Subtract)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Subtract_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, Subtract_1)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->Subtract();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Week)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, Week)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Week();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Weeks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "weeks", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, Weeks)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int weeks = arg.GetNumber(0)
	//pThis->GetEntity()->Weeks();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Year)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, Year)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Year();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DateSpan, Years)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "years", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, Years)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int years = arg.GetNumber(0)
	//pThis->GetEntity()->Years();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDateSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateSpan)
{
	Gura_AssignMethod(wx_DateSpan, wxDateSpan);
	Gura_AssignMethod(wx_DateSpan, Add);
	Gura_AssignMethod(wx_DateSpan, Add_1);
	Gura_AssignMethod(wx_DateSpan, Day);
	Gura_AssignMethod(wx_DateSpan, Days);
	Gura_AssignMethod(wx_DateSpan, GetDays);
	Gura_AssignMethod(wx_DateSpan, GetMonths);
	Gura_AssignMethod(wx_DateSpan, GetTotalMonths);
	Gura_AssignMethod(wx_DateSpan, GetTotalDays);
	Gura_AssignMethod(wx_DateSpan, GetWeeks);
	Gura_AssignMethod(wx_DateSpan, GetYears);
	Gura_AssignMethod(wx_DateSpan, Month);
	Gura_AssignMethod(wx_DateSpan, Months);
	Gura_AssignMethod(wx_DateSpan, Multiply);
	Gura_AssignMethod(wx_DateSpan, Multiply_1);
	Gura_AssignMethod(wx_DateSpan, Neg);
	Gura_AssignMethod(wx_DateSpan, Negate);
	Gura_AssignMethod(wx_DateSpan, SetDays);
	Gura_AssignMethod(wx_DateSpan, SetMonths);
	Gura_AssignMethod(wx_DateSpan, SetWeeks);
	Gura_AssignMethod(wx_DateSpan, SetYears);
	Gura_AssignMethod(wx_DateSpan, Subtract);
	Gura_AssignMethod(wx_DateSpan, Subtract_1);
	Gura_AssignMethod(wx_DateSpan, Week);
	Gura_AssignMethod(wx_DateSpan, Weeks);
	Gura_AssignMethod(wx_DateSpan, Year);
	Gura_AssignMethod(wx_DateSpan, Years);
}

Gura_ImplementDescendantCreator(wx_DateSpan)
{
	return new Object_wx_DateSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
