//----------------------------------------------------------------------------
// wxDateTime
// extracted from datetime.tex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Class derivation
//----------------------------------------------------------------------------
class wx_DateTime: public wxDateTime, public GuraObjectObserver {
private:
	Gura::Signal _sig;
	Object_wx_DateTime *_pObj;
public:
	//inline wx_DateTime() : wxDateTime(), _sig(NULL), _pObj(NULL) {}
	//inline wx_DateTime(time_t timet) : wxDateTime(timet), _sig(NULL), _pObj(NULL) {}
	//inline wx_DateTime(const struct tm& tm) : wxDateTime(tm), _sig(NULL), _pObj(NULL) {}
	//inline wx_DateTime(double jdn) : wxDateTime(jdn), _sig(NULL), _pObj(NULL) {}
	//inline wx_DateTime(wxDateTime_t hour, wxDateTime_t minute, wxDateTime_t second, wxDateTime_t millisec) : wxDateTime(hour, minute, second, millisec), _sig(NULL), _pObj(NULL) {}
	//inline wx_DateTime(wxDateTime_t day, Month month, int Inv_Year, wxDateTime_t hour, wxDateTime_t minute, wxDateTime_t second, wxDateTime_t millisec) : wxDateTime(day, month, Inv_Year, hour, minute, second, millisec), _sig(NULL), _pObj(NULL) {}
	~wx_DateTime();
	inline void AssocWithGura(Gura::Signal &sig, Object_wx_DateTime *pObj) {
		_sig = sig, _pObj = pObj;
	}
	// virtual function of GuraObjectObserver
	virtual void GuraObjectDeleted();
};

wx_DateTime::~wx_DateTime()
{
	if (_pObj != NULL) _pObj->InvalidateEntity();
}

void wx_DateTime::GuraObjectDeleted()
{
	_pObj = NULL;
}

//----------------------------------------------------------------------------
// Gura interfaces for wxDateTime
//----------------------------------------------------------------------------
Gura_DeclareClassMethod(wx_DateTime, ConvertYearToBC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, ConvertYearToBC)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int year = args.GetInt(0);
	int rtn = wxDateTime::ConvertYearToBC(year);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DateTime, GetAmPmStrings)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetAmPmStrings)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxString am;
	wxString pm;
	wxDateTime::GetAmPmStrings(&am, &pm);
	return ReturnValue(env, sig, args, Value::CreateAsList(env,
				Value(static_cast<const char *>(am.ToUTF8())),
				Value(static_cast<const char *>(pm.ToUTF8()))));
}

Gura_DeclareClassMethod(wx_DateTime, GetBeginDST)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "country", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetBeginDST)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int year = wxDateTime::Inv_Year;
	if (args.IsValid(0)) year = args.GetInt(0);
	wxDateTime::Country country = wxDateTime::Country_Default;
	if (args.IsValid(1)) country = static_cast<wxDateTime::Country>(args.GetInt(1));
	wxDateTime rtn = wxDateTime::GetBeginDST(year, country);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateTime, GetCountry)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetCountry)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateTime::Country rtn = wxDateTime::GetCountry();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DateTime, GetCurrentYear)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "country", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetCurrentYear)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateTime::Calendar cal = wxDateTime::Gregorian;
	if (args.IsValid(0)) cal = static_cast<wxDateTime::Calendar>(args.GetInt(0));
	int rtn = wxDateTime::GetCurrentYear(cal);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DateTime, GetCurrentMonth)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "country", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetCurrentMonth)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateTime::Calendar cal = wxDateTime::Gregorian;
	if (args.IsValid(0)) cal = static_cast<wxDateTime::Calendar>(args.GetInt(0));
	wxDateTime::Month rtn = wxDateTime::GetCurrentMonth(cal);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DateTime, GetCentury)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetCentury)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int year = args.GetInt(0);
	int rtn = wxDateTime::GetCentury(year);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DateTime, GetEndDST)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "country", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetEndDST)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int year = wxDateTime::Inv_Year;
	if (args.IsValid(0)) year = args.GetInt(0);
	wxDateTime::Country country = wxDateTime::Country_Default;
	if (args.IsValid(1)) country = static_cast<wxDateTime::Country>(args.GetInt(1));
	wxDateTime rtn = wxDateTime::GetEndDST(year, country);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateTime, GetMonthName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "month", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetMonthName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateTime::Month month = static_cast<wxDateTime::Month>(args.GetInt(0));
	wxDateTime::NameFlags flags = wxDateTime::Name_Full;
	if (args.IsValid(1)) flags = static_cast<wxDateTime::NameFlags>(args.GetInt(1));
	wxString rtn = wxDateTime::GetMonthName(month, flags);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_DateTime, GetNumberOfDaysInYear)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "cal", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetNumberOfDaysInYear)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int year = args.GetInt(0);
	wxDateTime::Calendar cal = wxDateTime::Gregorian;
	if (args.IsValid(1)) cal = static_cast<wxDateTime::Calendar>(args.GetInt(1));
	wxDateTime::wxDateTime_t rtn = wxDateTime::GetNumberOfDays(year, cal);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DateTime, GetNumberOfDaysInMonth)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "month", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "cal", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetNumberOfDaysInMonth)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateTime::Month month = static_cast<wxDateTime::Month>(args.GetInt(0));
	int year = wxDateTime::Inv_Year;
	if (args.IsValid(1)) year = args.GetInt(1);
	wxDateTime::Calendar cal = wxDateTime::Gregorian;
	if (args.IsValid(2)) cal = static_cast<wxDateTime::Calendar>(args.GetInt(2));
	wxDateTime::wxDateTime_t rtn = wxDateTime::GetNumberOfDays(month, year, cal);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DateTime, GetTimeNow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetTimeNow)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_DateTime, GetTmNow)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetTmNow)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_DateTime, GetWeekDayName)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "weekday", VTYPE_number);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, GetWeekDayName)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateTime::WeekDay weekday = static_cast<wxDateTime::WeekDay>(args.GetInt(0));
	wxDateTime::NameFlags flags = wxDateTime::Name_Full;
	if (args.IsValid(1)) flags = static_cast<wxDateTime::NameFlags>(args.GetInt(1));
	wxString rtn = wxDateTime::GetWeekDayName(weekday, flags);
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareClassMethod(wx_DateTime, IsLeapYear)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "flags", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, IsLeapYear)
{
	if (!CheckWxReady(sig)) return Value::Null;
	int year = wxDateTime::Inv_Year;
	if (args.IsValid(0)) year = args.GetInt(0);
	wxDateTime::Calendar cal = wxDateTime::Gregorian;
	if (args.IsValid(1)) cal = static_cast<wxDateTime::Calendar>(args.GetInt(1));
	bool rtn = wxDateTime::IsLeapYear(year, cal);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareClassMethod(wx_DateTime, IsWestEuropeanCountry)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, IsWestEuropeanCountry)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	bool rtn = wxDateTime::IsWestEuropeanCountry();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_DateTime, IsDSTApplicable)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, IsDSTApplicable)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int year = Inv_Year;
	if (args.IsValid(0)) year = args.GetInt(0);
	bool rtn = wxDateTime::IsDSTApplicable(year, );
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_DateTime, Now)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, Now)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateTime rtn = wxDateTime::Now();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateTime, SetCountry)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
#if 0
#endif
}

Gura_ImplementClassMethod(wx_DateTime, SetCountry)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	wxDateTime::SetCountry();
	return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_DateTime, Today)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, Today)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateTime rtn = wxDateTime::Today();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareClassMethod(wx_DateTime, UNow)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, UNow)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wxDateTime rtn = wxDateTime::UNow();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareFunction(DateTime)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	SetClassToConstruct(Gura_UserClass(wx_DateTime));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(DateTime)
{
	if (!CheckWxReady(sig)) return Value::Null;
	wx_DateTime *pEntity = new wx_DateTime();
	Object_wx_DateTime *pObj = Object_wx_DateTime::GetThisObj(args);
	if (pObj == NULL) {
		pObj = new Object_wx_DateTime(pEntity, pEntity, OwnerFalse);
		pEntity->AssocWithGura(sig, pObj);
		return ReturnValue(env, sig, args, Value(pObj));
	}
	pObj->SetEntity(pEntity, pEntity, OwnerFalse);
	pEntity->AssocWithGura(sig, pObj);
	return ReturnValue(env, sig, args, args.GetThis());
}

Gura_DeclareMethod(wx_DateTime, SetToCurrent)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetToCurrent)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime &rtn = pThis->GetEntity()->SetToCurrent();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetJDN)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "jdn", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetJDN)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double jdn = args.GetDouble(0);
	wxDateTime &rtn = pThis->GetEntity()->Set(jdn);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateTime, SetHMS)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hour", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "minute", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "second", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisec", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetHMS)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::wxDateTime_t hour = static_cast<wxDateTime::wxDateTime_t>(args.GetInt(0));
	wxDateTime::wxDateTime_t minute = 0;
	if (args.IsValid(1)) minute = static_cast<wxDateTime::wxDateTime_t>(args.GetInt(1));
	wxDateTime::wxDateTime_t second = 0;
	if (args.IsValid(2)) second = static_cast<wxDateTime::wxDateTime_t>(args.GetInt(2));
	wxDateTime::wxDateTime_t millisec = 0;
	if (args.IsValid(3)) hour = static_cast<wxDateTime::wxDateTime_t>(args.GetInt(3));
	wxDateTime &rtn = pThis->GetEntity()->Set(hour, minute, second, millisec);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateTime, Set)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "month", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "hour", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "minute", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "second", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "millisec", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Set)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::wxDateTime_t day = static_cast<wxDateTime::wxDateTime_t>(args.GetInt(0));
	wxDateTime::Month month = wxDateTime::Inv_Month;
	if (args.IsValid(1)) month = static_cast<wxDateTime::Month>(args.GetInt(1));
	int year = wxDateTime::Inv_Year;
	if (args.IsValid(2)) year = args.GetInt(2);
	wxDateTime::wxDateTime_t hour = 0;
	if (args.IsValid(3)) hour = static_cast<wxDateTime::wxDateTime_t>(args.GetInt(3));
	wxDateTime::wxDateTime_t minute = 0;
	if (args.IsValid(4)) minute = static_cast<wxDateTime::wxDateTime_t>(args.GetInt(4));
	wxDateTime::wxDateTime_t second = 0;
	if (args.IsValid(5)) second = static_cast<wxDateTime::wxDateTime_t>(args.GetInt(5));
	wxDateTime::wxDateTime_t millisec = 0;
	if (args.IsValid(6)) hour = static_cast<wxDateTime::wxDateTime_t>(args.GetInt(6));
	wxDateTime &rtn = pThis->GetEntity()->Set(day, month, year, hour, minute, second, millisec);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateTime, ResetTime)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, ResetTime)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime &rtn = pThis->GetEntity()->ResetTime();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetYear)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "year", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetYear)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int year = args.GetInt(0);
	wxDateTime &rtn = pThis->GetEntity()->SetYear(year);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetMonth)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetMonth)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime &rtn = pThis->GetEntity()->SetMonth();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "day", VTYPE_wx_DateTime_t, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime_t *day = Object_wx_DateTime_t::GetObject(args, 0)->GetEntity();
	wxDateTime &rtn = pThis->GetEntity()->SetDay(*day);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetHour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "hour", VTYPE_wx_DateTime_t, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetHour)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime_t *hour = Object_wx_DateTime_t::GetObject(args, 0)->GetEntity();
	wxDateTime &rtn = pThis->GetEntity()->SetHour(*hour);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetMinute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "minute", VTYPE_wx_DateTime_t, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetMinute)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime_t *minute = Object_wx_DateTime_t::GetObject(args, 0)->GetEntity();
	wxDateTime &rtn = pThis->GetEntity()->SetMinute(*minute);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetSecond)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "second", VTYPE_wx_DateTime_t, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetSecond)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime_t *second = Object_wx_DateTime_t::GetObject(args, 0)->GetEntity();
	wxDateTime &rtn = pThis->GetEntity()->SetSecond(*second);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetMillisecond)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "millisecond", VTYPE_wx_DateTime_t, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetMillisecond)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime_t *millisecond = Object_wx_DateTime_t::GetObject(args, 0)->GetEntity();
	wxDateTime &rtn = pThis->GetEntity()->SetMillisecond(*millisecond);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsValid)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsValid)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsValid();
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateTime, GetDateOnly)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetDateOnly)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime rtn = pThis->GetEntity()->GetDateOnly();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
}

Gura_DeclareMethod(wx_DateTime, GetTm)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetTm)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetTicks)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetTicks)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetCentury_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetCentury_1)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->GetCentury();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetYear)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetYear)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::TimeZone tz = wxDateTime::Local;
	if (args.IsValid(0)) tz = static_cast<wxDateTime::TimeZone>(args.GetInt(0));
	int rtn = pThis->GetEntity()->GetYear(tz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateTime, GetMonth)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetMonth)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::TimeZone tz = wxDateTime::Local;
	if (args.IsValid(0)) tz = static_cast<wxDateTime::TimeZone>(args.GetInt(0));
	wxDateTime::Month rtn = pThis->GetEntity()->GetMonth(tz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateTime, GetDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetDay)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::TimeZone tz = wxDateTime::Local;
	if (args.IsValid(0)) tz = static_cast<wxDateTime::TimeZone>(args.GetInt(0));
	wxDateTime::wxDateTime_t rtn = pThis->GetEntity()->GetDay(tz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateTime, GetWeekDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetWeekDay)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::TimeZone tz = wxDateTime::Local;
	if (args.IsValid(0)) tz = static_cast<wxDateTime::TimeZone>(args.GetInt(0));
	wxDateTime::WeekDay rtn = pThis->GetEntity()->GetWeekDay(tz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateTime, GetHour)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetHour)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::TimeZone tz = wxDateTime::Local;
	if (args.IsValid(0)) tz = static_cast<wxDateTime::TimeZone>(args.GetInt(0));
	wxDateTime::wxDateTime_t rtn = pThis->GetEntity()->GetHour(tz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateTime, GetMinute)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetMinute)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::TimeZone tz = wxDateTime::Local;
	if (args.IsValid(0)) tz = static_cast<wxDateTime::TimeZone>(args.GetInt(0));
	wxDateTime::wxDateTime_t rtn = pThis->GetEntity()->GetMinute(tz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateTime, GetSecond)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetSecond)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::TimeZone tz = wxDateTime::Local;
	if (args.IsValid(0)) tz = static_cast<wxDateTime::TimeZone>(args.GetInt(0));
	wxDateTime::wxDateTime_t rtn = pThis->GetEntity()->GetSecond(tz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateTime, GetMillisecond)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetMillisecond)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::TimeZone tz = wxDateTime::Local;
	if (args.IsValid(0)) tz = static_cast<wxDateTime::TimeZone>(args.GetInt(0));
	wxDateTime::wxDateTime_t rtn = pThis->GetEntity()->GetMillisecond(tz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateTime, GetDayOfYear)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "tz", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetDayOfYear)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime::TimeZone tz = wxDateTime::Local;
	if (args.IsValid(0)) tz = static_cast<wxDateTime::TimeZone>(args.GetInt(0));
	wxDateTime::wxDateTime_t rtn = pThis->GetEntity()->GetDayOfYear(tz);
	return ReturnValue(env, sig, args, Value(rtn));
}

Gura_DeclareMethod(wx_DateTime, GetWeekOfYear)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetWeekOfYear)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime_t rtn = pThis->GetEntity()->GetWeekOfYear(, );
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime_t(new wxDateTime_t(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetWeekOfMonth)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetWeekOfMonth)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime_t rtn = pThis->GetEntity()->GetWeekOfMonth(, );
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime_t(new wxDateTime_t(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsWorkDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsWorkDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsWorkDay();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsGregorianDate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsGregorianDate)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool rtn = pThis->GetEntity()->IsGregorianDate();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Set_5)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "ddt", VTYPE_number, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Set_5)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned ddt = args.GetInt(0);
	wxDateTime &rtn = pThis->GetEntity()->Set(ddt);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetAsDOS)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetAsDOS)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	unsigned rtn = pThis->GetEntity()->GetAsDOS();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsEqualTo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "datetime", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsEqualTo)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *datetime = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsEqualTo(*datetime);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsEarlierThan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "datetime", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsEarlierThan)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *datetime = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsEarlierThan(*datetime);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsLaterThan)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "datetime", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsLaterThan)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *datetime = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsLaterThan(*datetime);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsStrictlyBetween)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "t1", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "t2", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsStrictlyBetween)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *t1 = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	wxDateTime *t2 = Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->IsStrictlyBetween(*t1, *t2);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsBetween)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "t1", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "t2", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsBetween)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *t1 = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	wxDateTime *t2 = Object_wx_DateTime::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->IsBetween(*t1, *t2);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsSameDate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsSameDate)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *dt = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsSameDate(*dt);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsSameTime)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsSameTime)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *dt = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	bool rtn = pThis->GetEntity()->IsSameTime(*dt);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsEqualUpTo)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
	DeclareArg(env, "ts", VTYPE_wx_TimeSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsEqualUpTo)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *dt = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	wxTimeSpan *ts = Object_wx_TimeSpan::GetObject(args, 1)->GetEntity();
	bool rtn = pThis->GetEntity()->IsEqualUpTo(*dt, *ts);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Add)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Add)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxDateTime rtn = pThis->GetEntity()->Add(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Add_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Add_1)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxDateTime &rtn = pThis->GetEntity()->Add(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Add_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_DateSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Add_2)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateSpan *diff = Object_wx_DateSpan::GetObject(args, 0)->GetEntity();
	wxDateTime rtn = pThis->GetEntity()->Add(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Add_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_DateSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Add_3)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateSpan *diff = Object_wx_DateSpan::GetObject(args, 0)->GetEntity();
	wxDateTime &rtn = pThis->GetEntity()->Add(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Subtract)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Subtract)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxDateTime rtn = pThis->GetEntity()->Subtract(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Subtract_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_TimeSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Subtract_1)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxTimeSpan *diff = Object_wx_TimeSpan::GetObject(args, 0)->GetEntity();
	wxDateTime &rtn = pThis->GetEntity()->Subtract(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Subtract_2)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_DateSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Subtract_2)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateSpan *diff = Object_wx_DateSpan::GetObject(args, 0)->GetEntity();
	wxDateTime rtn = pThis->GetEntity()->Subtract(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Subtract_3)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "diff", VTYPE_wx_DateSpan, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Subtract_3)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateSpan *diff = Object_wx_DateSpan::GetObject(args, 0)->GetEntity();
	wxDateTime &rtn = pThis->GetEntity()->Subtract(*diff);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Subtract_4)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "dt", VTYPE_wx_DateTime, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Subtract_4)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime *dt = Object_wx_DateTime::GetObject(args, 0)->GetEntity();
	wxTimeSpan rtn = pThis->GetEntity()->Subtract(*dt);
	return ReturnValue(env, sig, args, Value(new Object_wx_TimeSpan(new wxTimeSpan(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, ParseRfc822Date)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "date", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, ParseRfc822Date)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString date = wxString::FromUTF8(args.GetString(0));
	wxChar rtn = pThis->GetEntity()->ParseRfc822Date(date);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, ParseFormat)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "date", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format", VTYPE_string, OCCUR_ZeroOrOnce);
	DeclareArg(env, "dateDef", VTYPE_wx_DateTime, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, ParseFormat)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString date = wxString::FromUTF8(args.GetString(0));
	wxString _format;
	const wxChar *format = wxDefaultDateTimeFormat;
	if (args.IsValid(1)) {
		_format = wxString::FromUTF8(args.GetString(1));
		format = _format;
	}
	wxDateTime *dateDef = (wxDateTime *)(&wxDefaultDateTime);
	if (args.IsValid(2)) dateDef = Object_wx_DateTime::GetObject(args, 2)->GetEntity();
	wxChar rtn = pThis->GetEntity()->ParseFormat(date, format, *dateDef);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, ParseDateTime)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "datetime", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, ParseDateTime)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString datetime = wxString::FromUTF8(args.GetString(0));
	wxChar rtn = pThis->GetEntity()->ParseDateTime(datetime);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, ParseDate)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "date", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, ParseDate)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString date = wxString::FromUTF8(args.GetString(0));
	wxChar rtn = pThis->GetEntity()->ParseDate(date);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, ParseTime)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "time", VTYPE_string, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, ParseTime)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString time = wxString::FromUTF8(args.GetString(0));
	wxChar rtn = pThis->GetEntity()->ParseTime(time);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, Format)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "format", VTYPE_string, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, Format)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString _format;
	const wxChar *format = wxDefaultDateTimeFormat;
	if (args.IsValid(0)) {
		_format = wxString::FromUTF8(args.GetString(0));
		format = _format;
	}
	wxString rtn = pThis->GetEntity()->Format(format, );
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, FormatDate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, FormatDate)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->FormatDate();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, FormatTime)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, FormatTime)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->FormatTime();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DateTime, FormatISODate)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, FormatISODate)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->FormatISODate();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DateTime, FormatISOTime)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, FormatISOTime)
{
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxString rtn = pThis->GetEntity()->FormatISOTime();
	return ReturnValue(env, sig, args, Value(static_cast<const char *>(rtn.ToUTF8())));
}

Gura_DeclareMethod(wx_DateTime, SetToWeekDayInSameWeek)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetToWeekDayInSameWeek)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime &rtn = pThis->GetEntity()->SetToWeekDayInSameWeek(, );
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetWeekDayInSameWeek)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetWeekDayInSameWeek)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime rtn = pThis->GetEntity()->GetWeekDayInSameWeek(, );
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetToNextWeekDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetToNextWeekDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime &rtn = pThis->GetEntity()->SetToNextWeekDay();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetNextWeekDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetNextWeekDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime rtn = pThis->GetEntity()->GetNextWeekDay();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetToPrevWeekDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetToPrevWeekDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime &rtn = pThis->GetEntity()->SetToPrevWeekDay();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetPrevWeekDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetPrevWeekDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime rtn = pThis->GetEntity()->GetPrevWeekDay();
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetToWeekDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetToWeekDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = 1;
	if (args.IsValid(1)) n = args.GetInt(1);
	int year = Inv_Year;
	if (args.IsValid(3)) year = args.GetInt(3);
	bool rtn = pThis->GetEntity()->SetToWeekDay(, n, , year);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetWeekDay_1)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "n", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetWeekDay_1)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int n = 1;
	if (args.IsValid(1)) n = args.GetInt(1);
	int year = Inv_Year;
	if (args.IsValid(3)) year = args.GetInt(3);
	wxDateTime rtn = pThis->GetEntity()->GetWeekDay(, n, , year);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetToLastWeekDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetToLastWeekDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int year = Inv_Year;
	if (args.IsValid(2)) year = args.GetInt(2);
	bool rtn = pThis->GetEntity()->SetToLastWeekDay(, , year);
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetLastWeekDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetLastWeekDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int year = Inv_Year;
	if (args.IsValid(2)) year = args.GetInt(2);
	wxDateTime rtn = pThis->GetEntity()->GetLastWeekDay(, , year);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareClassMethod(wx_DateTime, SetToWeekOfYear)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "year", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "numWeek", VTYPE_wx_DateTime_t, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementClassMethod(wx_DateTime, SetToWeekOfYear)
{
	if (!CheckWxReady(sig)) return Value::Null;
#if 0
	int year = args.GetInt(0);
	wxDateTime_t *numWeek = Object_wx_DateTime_t::GetObject(args, 1)->GetEntity();
	wxDateTime rtn = wxDateTime::SetToWeekOfYear(year, *numWeek, );
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetToLastMonthDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetToLastMonthDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int year = Inv_Year;
	if (args.IsValid(1)) year = args.GetInt(1);
	wxDateTime &rtn = pThis->GetEntity()->SetToLastMonthDay(, year);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetLastMonthDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "year", VTYPE_number, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetLastMonthDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int year = Inv_Year;
	if (args.IsValid(1)) year = args.GetInt(1);
	wxDateTime rtn = pThis->GetEntity()->GetLastMonthDay(, year);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, SetToYearDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "yday", VTYPE_wx_DateTime_t, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, SetToYearDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime_t *yday = Object_wx_DateTime_t::GetObject(args, 0)->GetEntity();
	wxDateTime &rtn = pThis->GetEntity()->SetToYearDay(*yday);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetYearDay)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "yday", VTYPE_wx_DateTime_t, OCCUR_Once);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetYearDay)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	wxDateTime_t *yday = Object_wx_DateTime_t::GetObject(args, 0)->GetEntity();
	wxDateTime rtn = pThis->GetEntity()->GetYearDay(*yday);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetJulianDayNumber)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetJulianDayNumber)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double rtn = pThis->GetEntity()->GetJulianDayNumber();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetJDN)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetJDN)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double rtn = pThis->GetEntity()->GetJDN();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetModifiedJulianDayNumber)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetModifiedJulianDayNumber)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double rtn = pThis->GetEntity()->GetModifiedJulianDayNumber();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetMJD)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetMJD)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double rtn = pThis->GetEntity()->GetMJD();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, GetRataDie)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, GetRataDie)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	double rtn = pThis->GetEntity()->GetRataDie();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, FromTimezone)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "noDST", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, FromTimezone)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool noDST = false;
	if (args.IsValid(1)) noDST = args.GetBoolean(1);
	wxDateTime rtn = pThis->GetEntity()->FromTimezone(, noDST);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, ToTimezone)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "noDST", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, ToTimezone)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool noDST = false;
	if (args.IsValid(1)) noDST = args.GetBoolean(1);
	wxDateTime rtn = pThis->GetEntity()->ToTimezone(, noDST);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, MakeTimezone)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "noDST", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, MakeTimezone)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool noDST = false;
	if (args.IsValid(1)) noDST = args.GetBoolean(1);
	wxDateTime &rtn = pThis->GetEntity()->MakeTimezone(, noDST);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, MakeFromTimezone)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "noDST", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, MakeFromTimezone)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool noDST = false;
	if (args.IsValid(1)) noDST = args.GetBoolean(1);
	wxDateTime &rtn = pThis->GetEntity()->MakeFromTimezone(, noDST);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, ToUTC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "noDST", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, ToUTC)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool noDST = false;
	if (args.IsValid(0)) noDST = args.GetBoolean(0);
	wxDateTime rtn = pThis->GetEntity()->ToUTC(noDST);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, MakeUTC)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
	DeclareArg(env, "noDST", VTYPE_boolean, OCCUR_ZeroOrOnce);
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, MakeUTC)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	bool noDST = false;
	if (args.IsValid(0)) noDST = args.GetBoolean(0);
	wxDateTime &rtn = pThis->GetEntity()->MakeUTC(noDST);
	return ReturnValue(env, sig, args, Value(new Object_wx_DateTime(new wxDateTime(rtn), NULL, OwnerTrue)));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

Gura_DeclareMethod(wx_DateTime, IsDST)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
#if 0
#endif
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(wx_DateTime, IsDST)
{
#if 0
	Object_wx_DateTime *pThis = Object_wx_DateTime::GetThisObj(args);
	if (pThis->IsInvalid(sig)) return Value::Null;
	int rtn = pThis->GetEntity()->IsDST();
	return ReturnValue(env, sig, args, Value(rtn));
#endif
	SetError_NotImplemented(sig);
	return Value::Null;
}

//----------------------------------------------------------------------------
// Object implementation for wxDateTime
//----------------------------------------------------------------------------
Object_wx_DateTime::~Object_wx_DateTime()
{
	if (_pEntity != NULL) NotifyGuraObjectDeleted();
	if (_ownerFlag) delete _pEntity;
	_pEntity = NULL;
}

Object *Object_wx_DateTime::Clone() const
{
	return NULL;
}

String Object_wx_DateTime::ToString(bool exprFlag)
{
	String rtn("<wx.DateTime:");
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
// Class implementation for wxDateTime
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DateTime)
{
	Gura_AssignFunction(DateTime);
	Gura_AssignMethod(wx_DateTime, ConvertYearToBC);
	Gura_AssignMethod(wx_DateTime, GetAmPmStrings);
	Gura_AssignMethod(wx_DateTime, GetBeginDST);
	Gura_AssignMethod(wx_DateTime, GetCountry);
	Gura_AssignMethod(wx_DateTime, GetCurrentYear);
	Gura_AssignMethod(wx_DateTime, GetCurrentMonth);
	Gura_AssignMethod(wx_DateTime, GetCentury);
	Gura_AssignMethod(wx_DateTime, GetEndDST);
	Gura_AssignMethod(wx_DateTime, GetMonthName);
	Gura_AssignMethod(wx_DateTime, GetNumberOfDaysInYear);
	Gura_AssignMethod(wx_DateTime, GetNumberOfDaysInMonth);
	Gura_AssignMethod(wx_DateTime, GetTimeNow);
	Gura_AssignMethod(wx_DateTime, GetTmNow);
	Gura_AssignMethod(wx_DateTime, GetWeekDayName);
	Gura_AssignMethod(wx_DateTime, IsLeapYear);
	Gura_AssignMethod(wx_DateTime, IsWestEuropeanCountry);
	Gura_AssignMethod(wx_DateTime, IsDSTApplicable);
	Gura_AssignMethod(wx_DateTime, Now);
	Gura_AssignMethod(wx_DateTime, SetCountry);
	Gura_AssignMethod(wx_DateTime, Today);
	Gura_AssignMethod(wx_DateTime, UNow);
	Gura_AssignMethod(wx_DateTime, SetToCurrent);
	Gura_AssignMethod(wx_DateTime, Set);
	Gura_AssignMethod(wx_DateTime, SetJDN);
	Gura_AssignMethod(wx_DateTime, SetHMS);
	Gura_AssignMethod(wx_DateTime, ResetTime);
	Gura_AssignMethod(wx_DateTime, SetYear);
	Gura_AssignMethod(wx_DateTime, SetMonth);
	Gura_AssignMethod(wx_DateTime, SetDay);
	Gura_AssignMethod(wx_DateTime, SetHour);
	Gura_AssignMethod(wx_DateTime, SetMinute);
	Gura_AssignMethod(wx_DateTime, SetSecond);
	Gura_AssignMethod(wx_DateTime, SetMillisecond);
	Gura_AssignMethod(wx_DateTime, IsValid);
	Gura_AssignMethod(wx_DateTime, GetDateOnly);
	Gura_AssignMethod(wx_DateTime, GetTm);
	Gura_AssignMethod(wx_DateTime, GetTicks);
	Gura_AssignMethod(wx_DateTime, GetCentury_1);
	Gura_AssignMethod(wx_DateTime, GetYear);
	Gura_AssignMethod(wx_DateTime, GetMonth);
	Gura_AssignMethod(wx_DateTime, GetDay);
	Gura_AssignMethod(wx_DateTime, GetWeekDay);
	Gura_AssignMethod(wx_DateTime, GetHour);
	Gura_AssignMethod(wx_DateTime, GetMinute);
	Gura_AssignMethod(wx_DateTime, GetSecond);
	Gura_AssignMethod(wx_DateTime, GetMillisecond);
	Gura_AssignMethod(wx_DateTime, GetDayOfYear);
	Gura_AssignMethod(wx_DateTime, GetWeekOfYear);
	Gura_AssignMethod(wx_DateTime, GetWeekOfMonth);
	Gura_AssignMethod(wx_DateTime, IsWorkDay);
	Gura_AssignMethod(wx_DateTime, IsGregorianDate);
	Gura_AssignMethod(wx_DateTime, Set_5);
	Gura_AssignMethod(wx_DateTime, GetAsDOS);
	Gura_AssignMethod(wx_DateTime, IsEqualTo);
	Gura_AssignMethod(wx_DateTime, IsEarlierThan);
	Gura_AssignMethod(wx_DateTime, IsLaterThan);
	Gura_AssignMethod(wx_DateTime, IsStrictlyBetween);
	Gura_AssignMethod(wx_DateTime, IsBetween);
	Gura_AssignMethod(wx_DateTime, IsSameDate);
	Gura_AssignMethod(wx_DateTime, IsSameTime);
	Gura_AssignMethod(wx_DateTime, IsEqualUpTo);
	Gura_AssignMethod(wx_DateTime, Add);
	Gura_AssignMethod(wx_DateTime, Add_1);
	Gura_AssignMethod(wx_DateTime, Add_2);
	Gura_AssignMethod(wx_DateTime, Add_3);
	Gura_AssignMethod(wx_DateTime, Subtract);
	Gura_AssignMethod(wx_DateTime, Subtract_1);
	Gura_AssignMethod(wx_DateTime, Subtract_2);
	Gura_AssignMethod(wx_DateTime, Subtract_3);
	Gura_AssignMethod(wx_DateTime, Subtract_4);
	Gura_AssignMethod(wx_DateTime, ParseRfc822Date);
	Gura_AssignMethod(wx_DateTime, ParseFormat);
	Gura_AssignMethod(wx_DateTime, ParseDateTime);
	Gura_AssignMethod(wx_DateTime, ParseDate);
	Gura_AssignMethod(wx_DateTime, ParseTime);
	Gura_AssignMethod(wx_DateTime, Format);
	Gura_AssignMethod(wx_DateTime, FormatDate);
	Gura_AssignMethod(wx_DateTime, FormatTime);
	Gura_AssignMethod(wx_DateTime, FormatISODate);
	Gura_AssignMethod(wx_DateTime, FormatISOTime);
	Gura_AssignMethod(wx_DateTime, SetToWeekDayInSameWeek);
	Gura_AssignMethod(wx_DateTime, GetWeekDayInSameWeek);
	Gura_AssignMethod(wx_DateTime, SetToNextWeekDay);
	Gura_AssignMethod(wx_DateTime, GetNextWeekDay);
	Gura_AssignMethod(wx_DateTime, SetToPrevWeekDay);
	Gura_AssignMethod(wx_DateTime, GetPrevWeekDay);
	Gura_AssignMethod(wx_DateTime, SetToWeekDay);
	Gura_AssignMethod(wx_DateTime, GetWeekDay_1);
	Gura_AssignMethod(wx_DateTime, SetToLastWeekDay);
	Gura_AssignMethod(wx_DateTime, GetLastWeekDay);
	Gura_AssignMethod(wx_DateTime, SetToWeekOfYear);
	Gura_AssignMethod(wx_DateTime, SetToLastMonthDay);
	Gura_AssignMethod(wx_DateTime, GetLastMonthDay);
	Gura_AssignMethod(wx_DateTime, SetToYearDay);
	Gura_AssignMethod(wx_DateTime, GetYearDay);
	Gura_AssignMethod(wx_DateTime, GetJulianDayNumber);
	Gura_AssignMethod(wx_DateTime, GetJDN);
	Gura_AssignMethod(wx_DateTime, GetModifiedJulianDayNumber);
	Gura_AssignMethod(wx_DateTime, GetMJD);
	Gura_AssignMethod(wx_DateTime, GetRataDie);
	Gura_AssignMethod(wx_DateTime, FromTimezone);
	Gura_AssignMethod(wx_DateTime, ToTimezone);
	Gura_AssignMethod(wx_DateTime, MakeTimezone);
	Gura_AssignMethod(wx_DateTime, MakeFromTimezone);
	Gura_AssignMethod(wx_DateTime, ToUTC);
	Gura_AssignMethod(wx_DateTime, MakeUTC);
	Gura_AssignMethod(wx_DateTime, IsDST);
	// TimeZone
	Gura_AssignClassValue(Local, wxDateTime::Local);
	Gura_AssignClassValue(GMT_12, wxDateTime::GMT_12);
	Gura_AssignClassValue(GMT_11, wxDateTime::GMT_11);
	Gura_AssignClassValue(GMT_10, wxDateTime::GMT_10);
	Gura_AssignClassValue(GMT_9, wxDateTime::GMT_9);
	Gura_AssignClassValue(GMT_8, wxDateTime::GMT_8);
	Gura_AssignClassValue(GMT_7, wxDateTime::GMT_7);
	Gura_AssignClassValue(GMT_6, wxDateTime::GMT_6);
	Gura_AssignClassValue(GMT_5, wxDateTime::GMT_5);
	Gura_AssignClassValue(GMT_4, wxDateTime::GMT_4);
	Gura_AssignClassValue(GMT_3, wxDateTime::GMT_3);
	Gura_AssignClassValue(GMT_2, wxDateTime::GMT_2);
	Gura_AssignClassValue(GMT_1, wxDateTime::GMT_1);
	Gura_AssignClassValue(GMT0, wxDateTime::GMT0);
	Gura_AssignClassValue(GMT1, wxDateTime::GMT1);
	Gura_AssignClassValue(GMT2, wxDateTime::GMT2);
	Gura_AssignClassValue(GMT3, wxDateTime::GMT3);
	Gura_AssignClassValue(GMT4, wxDateTime::GMT4);
	Gura_AssignClassValue(GMT5, wxDateTime::GMT5);
	Gura_AssignClassValue(GMT6, wxDateTime::GMT6);
	Gura_AssignClassValue(GMT7, wxDateTime::GMT7);
	Gura_AssignClassValue(GMT8, wxDateTime::GMT8);
	Gura_AssignClassValue(GMT9, wxDateTime::GMT9);
	Gura_AssignClassValue(GMT10, wxDateTime::GMT10);
	Gura_AssignClassValue(GMT11, wxDateTime::GMT11);
	Gura_AssignClassValue(GMT12, wxDateTime::GMT12);
	Gura_AssignClassValue(GMT13, wxDateTime::GMT13);
	Gura_AssignClassValue(WET, wxDateTime::WET);
	Gura_AssignClassValue(WEST, wxDateTime::WEST);
	Gura_AssignClassValue(CET, wxDateTime::CET);
	Gura_AssignClassValue(CEST, wxDateTime::CEST);
	Gura_AssignClassValue(EET, wxDateTime::EET);
	Gura_AssignClassValue(EEST, wxDateTime::EEST);
	Gura_AssignClassValue(MSK, wxDateTime::MSK);
	Gura_AssignClassValue(MSD, wxDateTime::MSD);
	Gura_AssignClassValue(AST, wxDateTime::AST);
	Gura_AssignClassValue(ADT, wxDateTime::ADT);
	Gura_AssignClassValue(EST, wxDateTime::EST);
	Gura_AssignClassValue(EDT, wxDateTime::EDT);
	Gura_AssignClassValue(CST, wxDateTime::CST);
	Gura_AssignClassValue(CDT, wxDateTime::CDT);
	Gura_AssignClassValue(MST, wxDateTime::MST);
	Gura_AssignClassValue(MDT, wxDateTime::MDT);
	Gura_AssignClassValue(PST, wxDateTime::PST);
	Gura_AssignClassValue(PDT, wxDateTime::PDT);
	Gura_AssignClassValue(HST, wxDateTime::HST);
	Gura_AssignClassValue(AKST, wxDateTime::AKST);
	Gura_AssignClassValue(AKDT, wxDateTime::AKDT);
	Gura_AssignClassValue(A_WST, wxDateTime::A_WST);
	Gura_AssignClassValue(A_CST, wxDateTime::A_CST);
	Gura_AssignClassValue(A_EST, wxDateTime::A_EST);
	Gura_AssignClassValue(A_ESST, wxDateTime::A_ESST);
	Gura_AssignClassValue(NZST, wxDateTime::NZST);
	Gura_AssignClassValue(NZDT, wxDateTime::NZDT);
	Gura_AssignClassValue(UTC, wxDateTime::UTC);
	// Month
	Gura_AssignClassValue(Jan, wxDateTime::Jan);
	Gura_AssignClassValue(Feb, wxDateTime::Feb);
	Gura_AssignClassValue(Mar, wxDateTime::Mar);
	Gura_AssignClassValue(Apr, wxDateTime::Apr);
	Gura_AssignClassValue(May, wxDateTime::May);
	Gura_AssignClassValue(Jun, wxDateTime::Jun);
	Gura_AssignClassValue(Jul, wxDateTime::Jul);
	Gura_AssignClassValue(Aug, wxDateTime::Aug);
	Gura_AssignClassValue(Sep, wxDateTime::Sep);
	Gura_AssignClassValue(Oct, wxDateTime::Oct);
	Gura_AssignClassValue(Nov, wxDateTime::Nov);
	Gura_AssignClassValue(Dec, wxDateTime::Dec);
	// WeekDay
	Gura_AssignClassValue(Sun, wxDateTime::Sun);
	Gura_AssignClassValue(Mon, wxDateTime::Mon);
	Gura_AssignClassValue(Tue, wxDateTime::Tue);
	Gura_AssignClassValue(Wed, wxDateTime::Wed);
	Gura_AssignClassValue(Thu, wxDateTime::Thu);
	Gura_AssignClassValue(Fri, wxDateTime::Fri);
	Gura_AssignClassValue(Sat, wxDateTime::Sat);
	Gura_AssignClassValue(Inv_WeekDay, wxDateTime::Inv_WeekDay);
	// NameFlags
	Gura_AssignClassValue(Name_Full, wxDateTime::Name_Full);
	Gura_AssignClassValue(Name_Abbr, wxDateTime::Name_Abbr);
	// Calendar
	Gura_AssignClassValue(Gregorian, wxDateTime::Gregorian);
	Gura_AssignClassValue(Julian, wxDateTime::Julian);
	// Country
	Gura_AssignClassValue(Country_Unknown, wxDateTime::Country_Unknown);
	Gura_AssignClassValue(Country_Default, wxDateTime::Country_Default);
	Gura_AssignClassValue(Country_WesternEurope_Start, wxDateTime::Country_WesternEurope_Start);
	Gura_AssignClassValue(France, wxDateTime::France);
	Gura_AssignClassValue(Germany, wxDateTime::Germany);
	Gura_AssignClassValue(UK, wxDateTime::UK);
	Gura_AssignClassValue(Country_WesternEurope_End, wxDateTime::Country_WesternEurope_End);
	Gura_AssignClassValue(Russia, wxDateTime::Russia);
	Gura_AssignClassValue(USA, wxDateTime::USA);
	// WeekFlags
	Gura_AssignClassValue(Default_First, wxDateTime::Default_First);
	Gura_AssignClassValue(Monday_First, wxDateTime::Monday_First);
	Gura_AssignClassValue(Sunday_First, wxDateTime::Sunday_First);
}

Gura_ImplementDescendantCreator(wx_DateTime)
{
	return new Object_wx_DateTime((pClass == NULL)? this : pClass, NULL, NULL, OwnerFalse);
}

Gura_EndModuleScope(wx)
