//----------------------------------------------------------------------------
// wxDateSpan
// extracted from datespan.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModule(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DateSpan: public wxDateSpan, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DateSpan *_pObj;
public:
	inline wx_DateSpan(int years, int months, int weeks, int days) : wxDateSpan(years, months, weeks, days), _sig(NULL), _pObj(NULL) {}
	~wx_DateSpan();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DateSpan *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DateSpan::~wx_DateSpan()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DateSpan::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDateSpan
//----------------------------------------------------------------------------
Gura_DeclareFunction(DateSpan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DateSpan));
	DeclareArg(env, "years", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "months", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "weeks", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "days", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DateSpan)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int years = 0;
	if (args.IsValid(0)) years = args.GetInt(0);
	int months = 0;
	if (args.IsValid(1)) months = args.GetInt(1);
	int weeks = 0;
	if (args.IsValid(2)) weeks = args.GetInt(2);
	int days = 0;
	if (args.IsValid(3)) days = args.GetInt(3);
	wx_DateSpan *pEntity = new wx_DateSpan(years, months, weeks, days);
	Object_wx_DateSpan *pObj = Object_wx_DateSpan::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DateSpan(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DateSpan, Add)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "other", VTYPE_wx_DateSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Add)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateSpan *other = Object_wx_DateSpan::GetObject(args, 0)->GetEntity();
	wxDateSpan rtn = pThis->GetEntity()->Add(*other);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Add_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "other", VTYPE_wx_DateSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Add_1)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateSpan *other = Object_wx_DateSpan::GetObject(args, 0)->GetEntity();
	wxDateSpan &rtn = pThis->GetEntity()->Add(*other);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Day)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Day)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateSpan rtn = wxDateSpan::Day();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Days)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "days", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Days)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int days = args.GetInt(0);
	wxDateSpan rtn = wxDateSpan::Days(days);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, GetDays)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, GetDays)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDays();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateSpan, GetMonths)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, GetMonths)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMonths();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateSpan, GetTotalDays)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, GetTotalDays)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetTotalDays();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateSpan, GetWeeks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, GetWeeks)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWeeks();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateSpan, GetYears)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, GetYears)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetYears();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DateSpan, Month)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Month)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateSpan rtn = wxDateSpan::Month();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Months)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "mon", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Months)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int mon = args.GetInt(0);
	wxDateSpan rtn = wxDateSpan::Months(mon);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Multiply)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Multiply)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int factor = args.GetInt(0);
	wxDateSpan rtn = pThis->GetEntity()->Multiply(factor);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Multiply_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "factor", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Multiply_1)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int factor = args.GetInt(0);
	wxDateSpan &rtn = pThis->GetEntity()->Multiply(factor);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Negate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Negate)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateSpan rtn = pThis->GetEntity()->Negate();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Neg)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Neg)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateSpan &rtn = pThis->GetEntity()->Neg();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, SetDays)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, SetDays)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	wxDateSpan &rtn = pThis->GetEntity()->SetDays(n);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, SetYears)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, SetYears)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	wxDateSpan &rtn = pThis->GetEntity()->SetYears(n);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, SetMonths)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, SetMonths)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	wxDateSpan &rtn = pThis->GetEntity()->SetMonths(n);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, SetWeeks)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, SetWeeks)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	wxDateSpan &rtn = pThis->GetEntity()->SetWeeks(n);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Subtract)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "other", VTYPE_wx_DateSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Subtract)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateSpan *other = Object_wx_DateSpan::GetObject(args, 0)->GetEntity();
	wxDateSpan rtn = pThis->GetEntity()->Subtract(*other);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateSpan, Subtract_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "other", VTYPE_wx_DateSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateSpan, Subtract_1)
{
	Object_wx_DateSpan *pThis = Object_wx_DateSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateSpan *other = Object_wx_DateSpan::GetObject(args, 0)->GetEntity();
	wxDateSpan &rtn = pThis->GetEntity()->Subtract(*other);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Week)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Week)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateSpan rtn = wxDateSpan::Week();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Weeks)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "weeks", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Weeks)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int weeks = args.GetInt(0);
	wxDateSpan rtn = wxDateSpan::Weeks(weeks);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Year)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Year)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateSpan rtn = wxDateSpan::Year();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateSpan, Years)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "years", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateSpan, Years)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int years = args.GetInt(0);
	wxDateSpan rtn = wxDateSpan::Years(years);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateSpan(new wxDateSpan(rtn), NULL, OwnerTrue)));
}

//----------------------------------------------------------------------------
// Object implementation for wxDateSpan
//----------------------------------------------------------------------------
Object_wx_DateSpan::~Object_wx_DateSpan()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DateSpan::Clone() const
{
	return NULL;
}

String Object_wx_DateSpan::ToString(Signal sig, bool exprFlag)
{
	String rtn("<wx.DateSpan:");
	if (GetEntity() == NULL) {
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
	return new Object_wx_DateSpan((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

}}
