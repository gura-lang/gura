//----------------------------------------------------------------------------
// wxTimeSpan
// extracted from timespan.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_TimeSpan: public wxTimeSpan, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_TimeSpan *_pObj;
public:
	//inline wx_TimeSpan() : wxTimeSpan(), _sig(NULL), _pObj(NULL) {}
	//inline wx_TimeSpan(long hours, long min, long sec, long msec) : wxTimeSpan(hours, min, sec, msec), _sig(NULL), _pObj(NULL) {}
	~wx_TimeSpan();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_TimeSpan *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TimeSpan::~wx_TimeSpan()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_TimeSpan::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTimeSpan
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TimeSpan, Abs)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Abs)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan rtn = pThis->GetEntity()->Abs();
	return ReturnValue(env, sig, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, Add)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Add)
{
#if 0
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxTimeSpan rtn = pThis->GetEntity()->Add(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TimeSpan, Add_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Add_1)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxTimeSpan &rtn = pThis->GetEntity()->Add(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_TimeSpan, Days)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "days", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Days)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	long days = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Days(days);
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TimeSpan, Day)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Day)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxTimespan rtn = wxTimeSpan::Day();
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TimeSpan, Format)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Format)
{
#if 0
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString _format;
	const wxChar *format = wxDefaultTimeSpanFormat;
	if (args.IsValid(0)) {
		_format = wxString::FromUTF8(args.GetString(0));
		format = _format;
	}
	wxString rtn = pThis->GetEntity()->Format(format);
	return ReturnValue(env, sig, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TimeSpan, GetDays)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetDays)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetDays();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, GetHours)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetHours)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetHours();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, GetMilliseconds)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetMilliseconds)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLongLong rtn = pThis->GetEntity()->GetMilliseconds();
	return ReturnValue(env, sig, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, GetMinutes)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetMinutes)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetMinutes();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, GetSeconds)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetSeconds)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLongLong rtn = pThis->GetEntity()->GetSeconds();
	return ReturnValue(env, sig, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, GetValue)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetValue)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxLongLong rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, sig, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, GetWeeks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetWeeks)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetWeeks();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_TimeSpan, Hours)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "hours", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Hours)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	long hours = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Hours(hours);
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TimeSpan, Hour)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Hour)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxTimespan rtn = wxTimeSpan::Hour();
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TimeSpan, IsEqualTo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ts", VTYPE_wx_TimeSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsEqualTo)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *ts = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsEqualTo(*ts);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, IsLongerThan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ts", VTYPE_wx_TimeSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsLongerThan)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *ts = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsLongerThan(*ts);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, IsNegative)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsNegative)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsNegative();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, IsNull)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsNull)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsNull();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, IsPositive)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsPositive)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsPositive();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, IsShorterThan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ts", VTYPE_wx_TimeSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsShorterThan)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *ts = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsShorterThan(*ts);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_TimeSpan, Minutes)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Minutes)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	long min = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Minutes(min);
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TimeSpan, Minute)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Minute)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxTimespan rtn = wxTimeSpan::Minute();
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TimeSpan, Multiply)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Multiply)
{
#if 0
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	wxTimeSpan rtn = pThis->GetEntity()->Multiply(n);
	return ReturnValue(env, sig, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TimeSpan, Multiply_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Multiply_1)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = args.GetInt(0);
	wxTimeSpan &rtn = pThis->GetEntity()->Multiply(n);
	return ReturnValue(env, sig, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, Negate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Negate)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan rtn = pThis->GetEntity()->Negate();
	return ReturnValue(env, sig, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, Neg)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Neg)
{
#if 0
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan &rtn = pThis->GetEntity()->Neg();
	return ReturnValue(env, sig, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TimeSpan, Milliseconds)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ms", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Milliseconds)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	long ms = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Milliseconds(ms);
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TimeSpan, Millisecond)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Millisecond)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxTimespan rtn = wxTimeSpan::Millisecond();
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TimeSpan, Seconds)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Seconds)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	long sec = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Seconds(sec);
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TimeSpan, Second)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Second)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxTimespan rtn = wxTimeSpan::Second();
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TimeSpan, Subtract)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Subtract)
{
#if 0
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxTimeSpan rtn = pThis->GetEntity()->Subtract(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_TimeSpan, Subtract_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Subtract_1)
{
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxTimeSpan &rtn = pThis->GetEntity()->Subtract(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_TimeSpan, Weeks)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "weeks", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Weeks)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	long weeks = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Weeks(weeks);
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_TimeSpan, Week)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Week)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxTimespan rtn = wxTimeSpan::Week();
	return ReturnValue(env, sig, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(TimeSpanEmpty)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_TimeSpan));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(TimeSpanEmpty)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wx_TimeSpan *pEntity = new wx_TimeSpan();
	Object_wx_TimeSpan *pObj = Object_wx_TimeSpan::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TimeSpan(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareFunction(TimeSpan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_TimeSpan));
	DeclareArg(env, "hours", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "msec", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(TimeSpan)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	long hours = args.GetLong(0);
	long min = args.GetLong(1);
	long sec = args.GetLong(2);
	long msec = args.GetLong(3);
	wx_TimeSpan *pEntity = new wx_TimeSpan(hours, min, sec, msec);
	Object_wx_TimeSpan *pObj = Object_wx_TimeSpan::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_TimeSpan(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxTimeSpan
//----------------------------------------------------------------------------
Object_wx_TimeSpan::~Object_wx_TimeSpan()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_TimeSpan::Clone() const
{
	return NULL;
}

String Object_wx_TimeSpan::ToString(bool exprFlag)
{
	String rtn("<wx.TimeSpan:");
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
// Class implementation for wxTimeSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TimeSpan)
{
	Gura_AssignFunction(TimeSpanEmpty);
	Gura_AssignFunction(TimeSpan);
	Gura_AssignMethod(wx_TimeSpan, Abs);
	Gura_AssignMethod(wx_TimeSpan, Add);
	Gura_AssignMethod(wx_TimeSpan, Add_1);
	Gura_AssignMethod(wx_TimeSpan, Days);
	Gura_AssignMethod(wx_TimeSpan, Day);
	Gura_AssignMethod(wx_TimeSpan, Format);
	Gura_AssignMethod(wx_TimeSpan, GetDays);
	Gura_AssignMethod(wx_TimeSpan, GetHours);
	Gura_AssignMethod(wx_TimeSpan, GetMilliseconds);
	Gura_AssignMethod(wx_TimeSpan, GetMinutes);
	Gura_AssignMethod(wx_TimeSpan, GetSeconds);
	Gura_AssignMethod(wx_TimeSpan, GetValue);
	Gura_AssignMethod(wx_TimeSpan, GetWeeks);
	Gura_AssignMethod(wx_TimeSpan, Hours);
	Gura_AssignMethod(wx_TimeSpan, Hour);
	Gura_AssignMethod(wx_TimeSpan, IsEqualTo);
	Gura_AssignMethod(wx_TimeSpan, IsLongerThan);
	Gura_AssignMethod(wx_TimeSpan, IsNegative);
	Gura_AssignMethod(wx_TimeSpan, IsNull);
	Gura_AssignMethod(wx_TimeSpan, IsPositive);
	Gura_AssignMethod(wx_TimeSpan, IsShorterThan);
	Gura_AssignMethod(wx_TimeSpan, Minutes);
	Gura_AssignMethod(wx_TimeSpan, Minute);
	Gura_AssignMethod(wx_TimeSpan, Multiply);
	Gura_AssignMethod(wx_TimeSpan, Multiply_1);
	Gura_AssignMethod(wx_TimeSpan, Negate);
	Gura_AssignMethod(wx_TimeSpan, Neg);
	Gura_AssignMethod(wx_TimeSpan, Milliseconds);
	Gura_AssignMethod(wx_TimeSpan, Millisecond);
	Gura_AssignMethod(wx_TimeSpan, Seconds);
	Gura_AssignMethod(wx_TimeSpan, Second);
	Gura_AssignMethod(wx_TimeSpan, Subtract);
	Gura_AssignMethod(wx_TimeSpan, Subtract_1);
	Gura_AssignMethod(wx_TimeSpan, Weeks);
	Gura_AssignMethod(wx_TimeSpan, Week);
}

Gura_ImplementDescendantCreator(wx_TimeSpan)
{
	return new Object_wx_TimeSpan((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
