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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DateSpan, "DateSpan")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "years", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "months", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "weeks", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "days", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_DateSpan));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DateSpan)
{
	//int years = arg.GetNumber(0)
	//int months = arg.GetNumber(1)
	//int weeks = arg.GetNumber(2)
	//int days = arg.GetNumber(3)
	//wxDateSpan(years, months, weeks, days);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DateSpan, __Add, "Add")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __Add)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDateSpan& other = arg.GetNumber(0)
	//wxDateSpan _rtn = pThis->GetEntity()->Add(other);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Add_1, "Add_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __Add_1)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDateSpan& other = arg.GetNumber(0)
	//wxDateSpan& _rtn = pThis->GetEntity()->Add(other);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Day, "Day")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __Day)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDateSpan _rtn = pThis->GetEntity()->Day();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Days, "Days")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "days", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __Days)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int days = arg.GetNumber(0)
	//wxDateSpan _rtn = pThis->GetEntity()->Days(days);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __GetDays, "GetDays")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __GetDays)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetDays();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __GetMonths, "GetMonths")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __GetMonths)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetMonths();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __GetTotalMonths, "GetTotalMonths")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __GetTotalMonths)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetTotalMonths();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __GetTotalDays, "GetTotalDays")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __GetTotalDays)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetTotalDays();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __GetWeeks, "GetWeeks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __GetWeeks)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetWeeks();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __GetYears, "GetYears")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __GetYears)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetYears();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Month, "Month")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __Month)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDateSpan _rtn = pThis->GetEntity()->Month();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Months, "Months")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "mon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __Months)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mon = arg.GetNumber(0)
	//wxDateSpan _rtn = pThis->GetEntity()->Months(mon);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Multiply, "Multiply")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __Multiply)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int factor = arg.GetNumber(0)
	//wxDateSpan _rtn = pThis->GetEntity()->Multiply(factor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Multiply_1, "Multiply_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __Multiply_1)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int factor = arg.GetNumber(0)
	//wxDateSpan& _rtn = pThis->GetEntity()->Multiply(factor);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Neg, "Neg")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __Neg)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDateSpan& _rtn = pThis->GetEntity()->Neg();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Negate, "Negate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __Negate)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDateSpan _rtn = pThis->GetEntity()->Negate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __SetDays, "SetDays")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __SetDays)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//wxDateSpan& _rtn = pThis->GetEntity()->SetDays(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __SetMonths, "SetMonths")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __SetMonths)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//wxDateSpan& _rtn = pThis->GetEntity()->SetMonths(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __SetWeeks, "SetWeeks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __SetWeeks)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//wxDateSpan& _rtn = pThis->GetEntity()->SetWeeks(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __SetYears, "SetYears")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __SetYears)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int n = arg.GetNumber(0)
	//wxDateSpan& _rtn = pThis->GetEntity()->SetYears(n);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Subtract, "Subtract")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __Subtract)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDateSpan& other = arg.GetNumber(0)
	//wxDateSpan _rtn = pThis->GetEntity()->Subtract(other);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Subtract_1, "Subtract_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __Subtract_1)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxDateSpan& other = arg.GetNumber(0)
	//wxDateSpan& _rtn = pThis->GetEntity()->Subtract(other);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Week, "Week")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __Week)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDateSpan _rtn = pThis->GetEntity()->Week();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Weeks, "Weeks")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "weeks", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __Weeks)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int weeks = arg.GetNumber(0)
	//wxDateSpan _rtn = pThis->GetEntity()->Weeks(weeks);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Year, "Year")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_DateSpan, __Year)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDateSpan _rtn = pThis->GetEntity()->Year();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DateSpan, __Years, "Years")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "years", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DateSpan, __Years)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int years = arg.GetNumber(0)
	//wxDateSpan _rtn = pThis->GetEntity()->Years(years);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDateSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateSpan)
{
	// Constructor assignment
	Gura_AssignFunction(__DateSpan);
	// Method assignment
	Gura_AssignMethod(wx_DateSpan, __Add);
	Gura_AssignMethod(wx_DateSpan, __Add_1);
	Gura_AssignMethod(wx_DateSpan, __Day);
	Gura_AssignMethod(wx_DateSpan, __Days);
	Gura_AssignMethod(wx_DateSpan, __GetDays);
	Gura_AssignMethod(wx_DateSpan, __GetMonths);
	Gura_AssignMethod(wx_DateSpan, __GetTotalMonths);
	Gura_AssignMethod(wx_DateSpan, __GetTotalDays);
	Gura_AssignMethod(wx_DateSpan, __GetWeeks);
	Gura_AssignMethod(wx_DateSpan, __GetYears);
	Gura_AssignMethod(wx_DateSpan, __Month);
	Gura_AssignMethod(wx_DateSpan, __Months);
	Gura_AssignMethod(wx_DateSpan, __Multiply);
	Gura_AssignMethod(wx_DateSpan, __Multiply_1);
	Gura_AssignMethod(wx_DateSpan, __Neg);
	Gura_AssignMethod(wx_DateSpan, __Negate);
	Gura_AssignMethod(wx_DateSpan, __SetDays);
	Gura_AssignMethod(wx_DateSpan, __SetMonths);
	Gura_AssignMethod(wx_DateSpan, __SetWeeks);
	Gura_AssignMethod(wx_DateSpan, __SetYears);
	Gura_AssignMethod(wx_DateSpan, __Subtract);
	Gura_AssignMethod(wx_DateSpan, __Subtract_1);
	Gura_AssignMethod(wx_DateSpan, __Week);
	Gura_AssignMethod(wx_DateSpan, __Weeks);
	Gura_AssignMethod(wx_DateSpan, __Year);
	Gura_AssignMethod(wx_DateSpan, __Years);
}

Gura_ImplementDescendantCreator(wx_DateSpan)
{
	return new Object_wx_DateSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
