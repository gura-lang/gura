//=============================================================================
// Gura class: datetime
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_datetime
//-----------------------------------------------------------------------------
Object_datetime::Object_datetime(const Object_datetime &obj) :
										Object(obj), _dateTime(obj._dateTime)
{
}

Object_datetime::~Object_datetime()
{
}

Object *Object_datetime::Clone() const
{
	return new Object_datetime(*this);
}

bool Object_datetime::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(year));
	symbols.insert(Gura_Symbol(month));
	symbols.insert(Gura_Symbol(day));
	symbols.insert(Gura_Symbol(hour));
	symbols.insert(Gura_Symbol(min));
	symbols.insert(Gura_Symbol(sec));
	symbols.insert(Gura_Symbol(usec));
	symbols.insert(Gura_Symbol(wday));
	symbols.insert(Gura_Symbol(week));
	symbols.insert(Gura_Symbol(yday));
	symbols.insert(Gura_Symbol(unixtime));
	return true;
}

Value Object_datetime::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(year))) {
		return Value(static_cast<Number>(_dateTime.GetYear()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(month))) {
		return Value(static_cast<Number>(_dateTime.GetMonth()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(day))) {
		return Value(static_cast<Number>(_dateTime.GetDay()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(hour))) {
		return Value(static_cast<Number>(_dateTime.GetHour()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(min))) {
		return Value(static_cast<Number>(_dateTime.GetMin()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(sec))) {
		return Value(static_cast<Number>(_dateTime.GetSec()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(usec))) {
		return Value(static_cast<Number>(_dateTime.GetUSec()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(wday))) {
		return Value(static_cast<Number>(_dateTime.GetDayOfWeek()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(week))) {
		int wday = _dateTime.GetDayOfWeek();
		const Symbol *pSymbol =
			(wday == 0)? Gura_Symbol(sunday) :
			(wday == 1)? Gura_Symbol(monday) :
			(wday == 2)? Gura_Symbol(tuesday) :
			(wday == 3)? Gura_Symbol(wednesday) :
			(wday == 4)? Gura_Symbol(thursday) :
			(wday == 5)? Gura_Symbol(friday) :
			(wday == 6)? Gura_Symbol(saturday) : NULL;
		if (pSymbol == NULL) return Value::Null; // this must not happen
		return Value(pSymbol);
	} else if (pSymbol->IsIdentical(Gura_Symbol(yday))) {
		return Value(static_cast<Number>(_dateTime.GetDayOfYear() + 1));
	} else if (pSymbol->IsIdentical(Gura_Symbol(unixtime))) {
		return Value(static_cast<Number>(_dateTime.GetUnixTime()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_datetime::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(year))) {
		long num = value.GetLong();
		if (num < 0 || num > 9999) {
			sig.SetError(ERR_ValueError, "invalid number for datetime's year");
			return Value::Null;
		}
		_dateTime.SetYear(static_cast<short>(num));
		return Value(num);
	} else if (pSymbol->IsIdentical(Gura_Symbol(month))) {
		long num = value.GetLong();
		if (num < 1 || num > 12) {
			sig.SetError(ERR_ValueError, "invalid number for datetime's month");
			return Value::Null;
		}
		_dateTime.SetMonth(static_cast<char>(num));
		return Value(num);
	} else if (pSymbol->IsIdentical(Gura_Symbol(day))) {
		long num = value.GetLong();
		if (num < 1 || num > 31) {
			sig.SetError(ERR_ValueError, "invalid number for datetime's day");
			return Value::Null;
		}
		_dateTime.SetDay(static_cast<char>(num));
		return Value(num);
	} else if (pSymbol->IsIdentical(Gura_Symbol(hour))) {
		long num = value.GetLong();
		if (num < 0 || num > 23) {
			sig.SetError(ERR_ValueError, "invalid number for datetime's hour");
			return Value::Null;
		}
		_dateTime.SetHour(static_cast<char>(num));
		return Value(num);
	} else if (pSymbol->IsIdentical(Gura_Symbol(min))) {
		long num = value.GetLong();
		if (num < 0 || num > 59) {
			sig.SetError(ERR_ValueError, "invalid number for datetime's min");
			return Value::Null;
		}
		_dateTime.SetMin(static_cast<char>(num));
		return Value(num);
	} else if (pSymbol->IsIdentical(Gura_Symbol(sec))) {
		long num = value.GetLong();
		if (num < 0 || num > 59) {
			sig.SetError(ERR_ValueError, "invalid number for datetime's sec");
			return Value::Null;
		}
		_dateTime.SetSec(static_cast<char>(num));
		return Value(num);
	} else if (pSymbol->IsIdentical(Gura_Symbol(usec))) {
		long num = value.GetLong();
		if (num < 0 || num > 999999) {
			sig.SetError(ERR_ValueError, "invalid number for datetime's usec");
			return Value::Null;
		}
		_dateTime.SetUSec(num);
		return Value(num);
	}
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

String Object_datetime::ToString(bool exprFlag)
{
	String str;
	str += "<datetime:";
	str += _dateTime.ToString("%Y-%m-%dT%H:%M:%S");
	str += _dateTime.GetTZOffsetStr(true);
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// datetime(year:number, month:number, day:number,
//           hour:number => 0, min:number => 0, sec:number => 0, usec:number => 0,
//           minsoff?:number):map {block?}
Gura_DeclareFunction(datetime)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "month", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "day", VTYPE_number, OCCUR_Once, FLAG_None);
	DeclareArg(env, "hour", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "sec", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "usec", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "minsoff", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_datetime));
}

Gura_ImplementFunction(datetime)
{
	short year = static_cast<short>(args.GetLong(0));
	char month = static_cast<char>(args.GetLong(1));
	char day = static_cast<char>(args.GetLong(2));
	long sec = static_cast<long>(args.GetLong(3) * 3600 +
								args.GetLong(4) * 60 + args.GetLong(5));
	long usec = args.GetLong(6);
	long secsOffset = 0;
	if (args.Is_number(7)) {
		secsOffset = args.GetLong(7) * 60;
	} else {
		secsOffset = OAL::GetSecsOffsetTZ();
	}
	return ReturnValue(env, sig, args,
		Value(new Object_datetime(env, DateTime(year, month, day, sec, usec, secsOffset))));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// datetime.monthdays(year:number, month:number):map
Gura_DeclareClassMethod(datetime, monthdays)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
	DeclareArg(env, "month", VTYPE_number);
}

Gura_ImplementClassMethod(datetime, monthdays)
{
	int year = args.GetInt(0);
	int month = args.GetInt(1);
	return Value(static_cast<Number>(DateTime::GetDaysOfMonth(year, month)));
}

// datetime.weekday(year:number, month:number, day:number):map
Gura_DeclareClassMethod(datetime, weekday)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
	DeclareArg(env, "month", VTYPE_number);
	DeclareArg(env, "day", VTYPE_number);
}

Gura_ImplementClassMethod(datetime, weekday)
{
	int year = args.GetInt(0);
	int month = args.GetInt(1);
	int day = args.GetInt(2);
	return Value(static_cast<Number>(DateTime::GetDayOfWeek(year, month, day)));
}

// datetime.now():[utc]
Gura_DeclareClassMethod(datetime, now)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(utc));
}

Gura_ImplementClassMethod(datetime, now)
{
	DateTime dateTime = OAL::GetCurDateTime(args.IsSet(Gura_Symbol(utc)));
	return Value(new Object_datetime(env, dateTime));
}

// datetime.today():[utc]
Gura_DeclareClassMethod(datetime, today)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(utc));
}

Gura_ImplementClassMethod(datetime, today)
{
	DateTime dateTime = OAL::GetCurDateTime(args.IsSet(Gura_Symbol(utc)));
	dateTime.ClearTime();
	return Value(new Object_datetime(env, dateTime));
}

// datetime.time(hour:number => 0, minute:number => 0, sec:number => 0, usec:number => 0):map
Gura_DeclareClassMethod(datetime, time)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hour", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "minute", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "sec", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "usec", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
}

Gura_ImplementClassMethod(datetime, time)
{
	short year = 0;
	char month = 1;
	char day = 1;
	long sec = static_cast<long>(args.GetNumber(0) * 3600 +
						args.GetNumber(1) * 60 + args.GetNumber(2));
	long usec = args.GetLong(3);
	long secsOffset = OAL::GetSecsOffsetTZ();
	return Value(new Object_datetime(env, DateTime(year, month, day, sec, usec, secsOffset)));
}

// datetime.parse(str:string):map
Gura_DeclareClassMethod(datetime, parse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
}

Gura_ImplementClassMethod(datetime, parse)
{
	DateTime dateTime;
	if (!dateTime.Parse(args.GetString(0))) {
		sig.SetError(ERR_FormatError, "invalid time format");
		return Value::Null;
	}
	return Value(new Object_datetime(env, dateTime));
}

// datetime.isleap(year:number):map
Gura_DeclareClassMethod(datetime, isleap)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
}

Gura_ImplementClassMethod(datetime, isleap)
{
	return Value(DateTime::IsLeapYear(args.GetShort(0)));
}

// datetime#format(format => `w3c)
Gura_DeclareMethod(datetime, format)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_any, OCCUR_Once,
								FLAG_None, new Expr_Value(Gura_Symbol(w3c)));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a string after converting datetime properties with the specified format.\n"
	"The format can either be a string to specify a user-specific format or a symbol of\n"
	"custom-defined one. A user-specific format contains following specifiers.\n"
	"  %d  day of month\n"
	"  %H  hour in 24-hour format\n"
	"  %I  hour in 12-hour format\n"
	"  %m  month\n"
	"  %M  minute\n"
	"  %S  second\n"
	"  %w  day of week\n"
	"  %y  lower two digits of year\n"
	"  %Y  year\n"
	"A custom-defined format is one of the symbols: `w3c, `http and `asctime.");
}

Gura_ImplementMethod(datetime, format)
{
	static const char *weekNames[] = {
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat",
	};
	static const char *monthNames[] = { "",
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};
	const DateTime &dateTime = Object_datetime::GetThisObj(args)->GetDateTime();
	if (args.Is_string(0)) {
		return Value(dateTime.ToString(args.GetString(0)));
	} else if (args.Is_symbol(0)) {
		const Symbol *pSymbol = args.GetSymbol(0);
		char str[64];
		if (pSymbol->IsIdentical(Gura_Symbol(w3c))) {
			::sprintf(str, "%04d-%02d-%02dT%02d:%02d:%02d%s",
				dateTime.GetYear(), dateTime.GetMonth(), dateTime.GetDay(),
				dateTime.GetHour(), dateTime.GetMin(), dateTime.GetSec(),
				dateTime.GetTZOffsetStr(true).c_str());
		} else if (pSymbol->IsIdentical(Gura_Symbol(http))) {
			String strTZ;
			if (dateTime.HasTZOffset()) {
				strTZ = ' ';
				strTZ += dateTime.GetTZOffsetStr(false);
			}
			::sprintf(str, "%s, %02d %s %04d %02d:%02d:%02d%s",
				weekNames[dateTime.GetDayOfWeek()], dateTime.GetDay(),
				monthNames[dateTime.GetMonth()], dateTime.GetYear(),
				dateTime.GetHour(), dateTime.GetMin(), dateTime.GetSec(),
				strTZ.c_str());
		} else if (pSymbol->IsIdentical(Gura_Symbol(asctime))) {
			String strTZ;
			if (dateTime.HasTZOffset()) {
				strTZ = ' ';
				strTZ += dateTime.GetTZOffsetStr(false);
			}
			::sprintf(str, "%s %s %2d %02d:%02d:%02d%s %04d",
				weekNames[dateTime.GetDayOfWeek()],
				monthNames[dateTime.GetMonth()], dateTime.GetDay(),
				dateTime.GetHour(), dateTime.GetMin(), dateTime.GetSec(),
				strTZ.c_str(), dateTime.GetYear());
		} else {
			sig.SetError(ERR_ValueError, "unknown format symbol `%s", pSymbol->GetName());
			return Value::Null;
		}
		return Value(str);
	}
	SetError_InvalidValType(sig, args.GetValue(0));
	return Value::Null;
}

// datetime#settzoff(mins:number):reduce
Gura_DeclareMethod(datetime, settzoff)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "mins", VTYPE_number);
}

Gura_ImplementMethod(datetime, settzoff)
{
	DateTime &dateTime = Object_datetime::GetThisObj(args)->GetDateTime();
	dateTime.SetTZOffset(args.GetLong(0) * 60);
	return args.GetThis();
}

// datetime#clrtzoff():reduce
Gura_DeclareMethod(datetime, clrtzoff)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
}

Gura_ImplementMethod(datetime, clrtzoff)
{
	DateTime &dateTime = Object_datetime::GetThisObj(args)->GetDateTime();
	dateTime.ClearTZOffset();
	return args.GetThis();
}

// datetime#utc()
Gura_DeclareMethod(datetime, utc)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(datetime, utc)
{
	const DateTime &dateTime = Object_datetime::GetThisObj(args)->GetDateTime();
	if (!dateTime.HasTZOffset()) {
		sig.SetError(ERR_ValueError, "datetime has no timezone offset");
		return Value::Null;
	}
	return Value(new Object_datetime(env, dateTime.ToUTC()));
}

#if 0
// datetime#isleap()
Gura_DeclareMethod(datetime, isleap)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(datetime, isleap)
{
	const DateTime &dateTime = Object_datetime::GetThisObj(args)->GetDateTime();
	return Value(dateTime.IsLeapYear());
}
#endif

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_datetime::Class_datetime(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_datetime)
{
}

void Class_datetime::Prepare(Environment &env)
{
	// function assignment
	Gura_AssignFunction(datetime);
	// value assignment
	Gura_AssignClassValue(Sunday,		Value(0));
	Gura_AssignClassValue(Monday,		Value(1));
	Gura_AssignClassValue(Tuesday,		Value(2));
	Gura_AssignClassValue(Wednesday,	Value(3));
	Gura_AssignClassValue(Thursday,		Value(4));
	Gura_AssignClassValue(Friday,		Value(5));
	Gura_AssignClassValue(Saturday,		Value(6));
	Gura_AssignMethod(datetime, monthdays);
	Gura_AssignMethod(datetime, weekday);
	Gura_AssignMethod(datetime, now);
	Gura_AssignMethod(datetime, today);
	Gura_AssignMethod(datetime, time);
	Gura_AssignMethod(datetime, parse);
	Gura_AssignMethod(datetime, isleap);
	Gura_AssignMethod(datetime, format);
	Gura_AssignMethod(datetime, settzoff);
	Gura_AssignMethod(datetime, clrtzoff);
	Gura_AssignMethod(datetime, utc);
	//Gura_AssignMethod(datetime, isleap);
}

Object *Class_datetime::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
