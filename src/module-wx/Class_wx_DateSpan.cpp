//----------------------------------------------------------------------------
// wxDateSpan
// extracted from datespan.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DateSpan: public wxDateSpan, public GuraObjectObserver {
private:
	//Gura::Signal *_pSig;
	Object_wx_DateSpan *_pObj;
public:
	inline wx_DateSpan(int years, int months, int weeks, int days) : wxDateSpan(years, months, weeks, days), _pObj(nullptr) {}
	~wx_DateSpan();
	inline void AssocWithGura(Object_wx_DateSpan *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DateSpan::~wx_DateSpan()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_DateSpan::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDateSpan
//----------------------------------------------------------------------------
Gura_DeclareFunction(DateSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DateSpan));
	DeclareArg(env, "years", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "months", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "weeks", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "days", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DateSpan)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int years = 0;
	if (arg.IsValid(0)) years = arg.GetInt(0);
	int months = 0;
	if (arg.IsValid(1)) months = arg.GetInt(1);
	int weeks = 0;
	if (arg.IsValid(2)) weeks = arg.GetInt(2);
	int days = 0;
	if (arg.IsValid(3)) days = arg.GetInt(3);
	wx_DateSpan *pEntity = new wx_DateSpan(years, months, weeks, days);
	Object_wx_DateSpan *pObj = Object_wx_DateSpan::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_wx_DateSpan(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, arg, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, arg, arg.GetValueThis());
}

Gura_DeclareMethod(wx_DateSpan, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "other", VTYPE_wx_DateSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Add)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateSpan *other = Object_wx_DateSpan::GetObject(arg, 0)->GetEntity();
	wxDateSpan rtn = pThis->GetEntity()->Add(*other);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "other", VTYPE_wx_DateSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateSpan *other = Object_wx_DateSpan::GetObject(arg, 0)->GetEntity();
	wxDateSpan &rtn = pThis->GetEntity()->Add(*other);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Day)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Day)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxDateSpan rtn = wxDateSpan::Day();
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Days)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "days", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Days)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int days = arg.GetInt(0);
	wxDateSpan rtn = wxDateSpan::Days(days);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, GetDays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, GetDays)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetDays();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DateSpan, GetMonths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, GetMonths)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMonths();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DateSpan, GetTotalDays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, GetTotalDays)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetTotalDays();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DateSpan, GetWeeks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, GetWeeks)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetWeeks();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareMethod(wx_DateSpan, GetYears)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, GetYears)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetYears();
	return ReturnValue(env, arg, Value(rtn));
}

Gura_DeclareClassMethod(wx_DateSpan, Month)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Month)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxDateSpan rtn = wxDateSpan::Month();
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Months)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mon", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Months)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int mon = arg.GetInt(0);
	wxDateSpan rtn = wxDateSpan::Months(mon);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Multiply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Multiply)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int factor = arg.GetInt(0);
	wxDateSpan rtn = pThis->GetEntity()->Multiply(factor);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Multiply_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Multiply_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int factor = arg.GetInt(0);
	wxDateSpan &rtn = pThis->GetEntity()->Multiply(factor);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Negate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Negate)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateSpan rtn = pThis->GetEntity()->Negate();
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Neg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Neg)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateSpan &rtn = pThis->GetEntity()->Neg();
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, SetDays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, SetDays)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = arg.GetInt(0);
	wxDateSpan &rtn = pThis->GetEntity()->SetDays(n);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, SetYears)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, SetYears)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = arg.GetInt(0);
	wxDateSpan &rtn = pThis->GetEntity()->SetYears(n);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, SetMonths)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, SetMonths)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = arg.GetInt(0);
	wxDateSpan &rtn = pThis->GetEntity()->SetMonths(n);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, SetWeeks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, SetWeeks)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = arg.GetInt(0);
	wxDateSpan &rtn = pThis->GetEntity()->SetWeeks(n);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Subtract)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "other", VTYPE_wx_DateSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Subtract)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateSpan *other = Object_wx_DateSpan::GetObject(arg, 0)->GetEntity();
	wxDateSpan rtn = pThis->GetEntity()->Subtract(*other);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Subtract_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "other", VTYPE_wx_DateSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Subtract_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxDateSpan *other = Object_wx_DateSpan::GetObject(arg, 0)->GetEntity();
	wxDateSpan &rtn = pThis->GetEntity()->Subtract(*other);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Week)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Week)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxDateSpan rtn = wxDateSpan::Week();
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Weeks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "weeks", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Weeks)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int weeks = arg.GetInt(0);
	wxDateSpan rtn = wxDateSpan::Weeks(weeks);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Year)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Year)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	wxDateSpan rtn = wxDateSpan::Year();
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Years)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "years", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Years)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
	int years = arg.GetInt(0);
	wxDateSpan rtn = wxDateSpan::Years(years);
	return ReturnValue(env, arg, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), nullptr, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxDateSpan
//----------------------------------------------------------------------------
Object_wx_DateSpan::~Object_wx_DateSpan()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
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
// Class implementation for wxDateSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateSpan)
{
	Gura_AssignFunction(DateSpan);
	Gura_AssignMethod(wx_DateSpan, Add);
	Gura_AssignMethod(wx_DateSpan, Add_1);
	Gura_AssignMethod(wx_DateSpan, Day);
	Gura_AssignMethod(wx_DateSpan, Days);
	Gura_AssignMethod(wx_DateSpan, GetDays);
	Gura_AssignMethod(wx_DateSpan, GetMonths);
	Gura_AssignMethod(wx_DateSpan, GetTotalDays);
	Gura_AssignMethod(wx_DateSpan, GetWeeks);
	Gura_AssignMethod(wx_DateSpan, GetYears);
	Gura_AssignMethod(wx_DateSpan, Month);
	Gura_AssignMethod(wx_DateSpan, Months);
	Gura_AssignMethod(wx_DateSpan, Multiply);
	Gura_AssignMethod(wx_DateSpan, Multiply_1);
	Gura_AssignMethod(wx_DateSpan, Negate);
	Gura_AssignMethod(wx_DateSpan, Neg);
	Gura_AssignMethod(wx_DateSpan, SetDays);
	Gura_AssignMethod(wx_DateSpan, SetYears);
	Gura_AssignMethod(wx_DateSpan, SetMonths);
	Gura_AssignMethod(wx_DateSpan, SetWeeks);
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
