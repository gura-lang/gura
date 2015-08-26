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
	//Gura::Signal *_pSig;
	Object_wx_TimeSpan *_pObj;
public:
	//inline wx_TimeSpan() : wxTimeSpan(), _pObj(nullptr) {}
	//inline wx_TimeSpan(long hours, long min, long sec, long msec) : wxTimeSpan(hours, min, sec, msec), _pObj(nullptr) {}
	~wx_TimeSpan();
	inline void AssocWithGura(Object_wx_TimeSpan *pObj) {
		_pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_TimeSpan::~wx_TimeSpan()
{
	if (_pObj != nullptr) _pObj->InvalidateEntity();
}

void wx_TimeSpan::GuraObjectDeleted()
{
	_pObj = nullptr;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxTimeSpan
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_TimeSpan, Abs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Abs)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTimeSpan rtn = pThis->GetEntity()->Abs();
	return ReturnValue(env, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, Add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Add)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxTimeSpan rtn = pThis->GetEntity()->Add(*diff);
	return ReturnValue(env, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Add_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Add_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxTimeSpan &rtn = pThis->GetEntity()->Add(*diff);
	return ReturnValue(env, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_TimeSpan, Days)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "days", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Days)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	long days = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Days(days);
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_TimeSpan, Day)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Day)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxTimespan rtn = wxTimeSpan::Day();
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Format)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxString _format;
	const wxChar *format = wxDefaultTimeSpanFormat;
	if (args.IsValid(0)) {
		_format = wxString::FromUTF8(args.GetString(0));
		format = _format;
	}
	wxString rtn = pThis->GetEntity()->Format(format);
	return ReturnValue(env, args, Value(env, static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, GetDays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetDays)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetDays();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, GetHours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetHours)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetHours();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, GetMilliseconds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetMilliseconds)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLongLong rtn = pThis->GetEntity()->GetMilliseconds();
	return ReturnValue(env, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, GetMinutes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetMinutes)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetMinutes();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, GetSeconds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetSeconds)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLongLong rtn = pThis->GetEntity()->GetSeconds();
	return ReturnValue(env, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxLongLong rtn = pThis->GetEntity()->GetValue();
	return ReturnValue(env, args, Value(new Object_wx_LongLong(new wxLongLong(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, GetWeeks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, GetWeeks)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int rtn = pThis->GetEntity()->GetWeeks();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_TimeSpan, Hours)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "hours", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Hours)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	long hours = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Hours(hours);
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_TimeSpan, Hour)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Hour)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxTimespan rtn = wxTimeSpan::Hour();
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, IsEqualTo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ts", VTYPE_wx_TimeSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsEqualTo)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTimeSpan *ts = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsEqualTo(*ts);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, IsLongerThan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ts", VTYPE_wx_TimeSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsLongerThan)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTimeSpan *ts = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsLongerThan(*ts);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, IsNegative)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsNegative)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsNegative();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, IsNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsNull();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, IsPositive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsPositive)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	bool rtn = pThis->GetEntity()->IsPositive();
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareMethod(wx_TimeSpan, IsShorterThan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "ts", VTYPE_wx_TimeSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, IsShorterThan)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTimeSpan *ts = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsShorterThan(*ts);
	return ReturnValue(env, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_TimeSpan, Minutes)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Minutes)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	long min = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Minutes(min);
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_TimeSpan, Minute)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Minute)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxTimespan rtn = wxTimeSpan::Minute();
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Multiply)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Multiply)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = args.GetInt(0);
	wxTimeSpan rtn = pThis->GetEntity()->Multiply(n);
	return ReturnValue(env, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Multiply_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Multiply_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	int n = args.GetInt(0);
	wxTimeSpan &rtn = pThis->GetEntity()->Multiply(n);
	return ReturnValue(env, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, Negate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Negate)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTimeSpan rtn = pThis->GetEntity()->Negate();
	return ReturnValue(env, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareMethod(wx_TimeSpan, Neg)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Neg)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTimeSpan &rtn = pThis->GetEntity()->Neg();
	return ReturnValue(env, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_TimeSpan, Milliseconds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ms", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Milliseconds)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	long ms = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Milliseconds(ms);
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_TimeSpan, Millisecond)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Millisecond)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxTimespan rtn = wxTimeSpan::Millisecond();
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_TimeSpan, Seconds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "sec", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Seconds)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	long sec = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Seconds(sec);
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_TimeSpan, Second)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Second)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxTimespan rtn = wxTimeSpan::Second();
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Subtract)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Subtract)
{
	Signal &sig = env.GetSignal();
#if 0
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxTimeSpan rtn = pThis->GetEntity()->Subtract(*diff);
	return ReturnValue(env, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareMethod(wx_TimeSpan, Subtract_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_TimeSpan, Subtract_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_TimeSpan *pThis = Object_wx_TimeSpan::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxTimeSpan &rtn = pThis->GetEntity()->Subtract(*diff);
	return ReturnValue(env, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), nullptr, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_TimeSpan, Weeks)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "weeks", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Weeks)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	long weeks = args.GetLong(0);
	wxTimespan rtn = wxTimeSpan::Weeks(weeks);
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareClassMethod(wx_TimeSpan, Week)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_TimeSpan, Week)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wxTimespan rtn = wxTimeSpan::Week();
	return ReturnValue(env, args, Value(new Object_wx_Timespan(new wxTimespan(rtn), nullptr, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(TimeSpanEmpty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
#if 0
	SetClassToConstruct(Gura_UserClass(wx_TimeSpan));
	DeclareBlock(OCCUR_ZeroOrOnce);
#endif
}

Gura_ImplementFunction(TimeSpanEmpty)
{
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	wx_TimeSpan *pEntity = new wx_TimeSpan();
	Object_wx_TimeSpan *pObj = Object_wx_TimeSpan::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TimeSpan(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

Gura_DeclareFunction(TimeSpan)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	Signal &sig = env.GetSignal();
	if (!CheckWxReady(sig)) return Value::Nil;
#if 0
	long hours = args.GetLong(0);
	long min = args.GetLong(1);
	long sec = args.GetLong(2);
	long msec = args.GetLong(3);
	wx_TimeSpan *pEntity = new wx_TimeSpan(hours, min, sec, msec);
	Object_wx_TimeSpan *pObj = Object_wx_TimeSpan::GetThisObj(args);
	if (pObj == nullptr) {
		pObj = new Object_wx_TimeSpan(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(pObj);
		return ReturnValue(env, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(pObj);
	return ReturnValue(env, args, args.GetValueThis());
#endif
	SetError_NotImplemented(sig);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Object implementation for wxTimeSpan
//----------------------------------------------------------------------------
Object_wx_TimeSpan::~Object_wx_TimeSpan()
{
	if (_pEntity != nullptr) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = nullptr;
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
	return new Object_wx_TimeSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
