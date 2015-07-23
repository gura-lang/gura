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

bool Object_datetime::DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols)
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

Value Object_datetime::DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
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
			(wday == 6)? Gura_Symbol(saturday) : nullptr;
		if (pSymbol == nullptr) return Value::Null; // this must not happen
		return Value(pSymbol);
	} else if (pSymbol->IsIdentical(Gura_Symbol(yday))) {
		return Value(static_cast<Number>(_dateTime.GetDayOfYear() + 1));
	} else if (pSymbol->IsIdentical(Gura_Symbol(unixtime))) {
		return Value(static_cast<Number>(_dateTime.GetUnixTime()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_datetime::DoSetProp(Environment &env, Signal &sig, const Symbol *pSymbol, const Value &value,
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
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates an instance of `datetime` class based on the specified arguments.\n"
		"\n"
		"Explanations of the arguments are shown below:\n"
		"\n"
		"- `year` .. Christian year.\n"
		"- `month` .. Month starting from 1. Numbers from 1 to 12 correspond to January to December.\n"
		"- `day` .. Day in a month starting from 1.\n"
		"- `hour` .. Hour in a day between 0 and 23.\n"
		"- `min` .. Minute in an hour between 0 and 59.\n"
		"- `sec` .. Second in a minute between 0 and 59.\n"
		"- `usec` .. Millisecond in a second between 0 and 999.\n"
		"- `minsoff` .. Timezone offset in minutes.\n"
		"\n"
		"In default, the instance has a timezone offset based on the current system settings.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("dt", "datetime"));
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
	return ReturnValue(env, args,
		Value(new Object_datetime(env, DateTime(year, month, day, sec, usec, secsOffset))));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// datetime#clrtzoff():reduce
Gura_DeclareMethod(datetime, clrtzoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Eliminates timezone offset information from the instance.");
}

Gura_ImplementMethod(datetime, clrtzoff)
{
	DateTime &dateTime = Object_datetime::GetThisObj(args)->GetDateTime();
	dateTime.ClearTZOffset();
	return args.GetThis();
}

// datetime#format(format => `w3c)
Gura_DeclareMethod(datetime, format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_any, OCCUR_Once,
								FLAG_None, new Expr_Value(Gura_Symbol(w3c)));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown, 
		"Returns a string of the datetime properties based on the specified format.\n"
		"For the argument `format`, you can specify either a string of user-specific format\n"
		"or a symbol of predefined style.\n"
		"\n"
		"A string of user-specific format contains following specifiers:\n"
		"\n"
		"- `%d` .. day of month\n"
		"- `%H` .. hour in 24-hour format\n"
		"- `%I` .. hour in 12-hour format\n"
		"- `%m` .. month\n"
		"- `%M` .. minute\n"
		"- `%S` .. second\n"
		"- `%w` .. week number starting from 0 for Sunday.\n"
		"- `%y` .. lower two digits of year\n"
		"- `%Y` .. four digits of year\n"
		"\n"
		"Below are the symbols of predefined styles:\n"
		"\n"
		"- `` `w3c`` .. W3C style. eg) `'2015-01-01T12:34:56+09:00'`\n"
		"- `` `http`` .. a style used in HTTP protocol. eg) `'Thu, 01 Jan 2015 12:34:56 +0900'`\n"
		"- `` `asctime`` .. a style used by the C function `asctime()`.\n"
		"                    eg) `'Thu Jan  1 12:34:56 +0900 2015'`\n");
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
				weekNames[static_cast<int>(dateTime.GetDayOfWeek())], dateTime.GetDay(),
				monthNames[static_cast<int>(dateTime.GetMonth())], dateTime.GetYear(),
				dateTime.GetHour(), dateTime.GetMin(), dateTime.GetSec(),
				strTZ.c_str());
		} else if (pSymbol->IsIdentical(Gura_Symbol(asctime))) {
			String strTZ;
			if (dateTime.HasTZOffset()) {
				strTZ = ' ';
				strTZ += dateTime.GetTZOffsetStr(false);
			}
			::sprintf(str, "%s %s %2d %02d:%02d:%02d%s %04d",
				weekNames[static_cast<int>(dateTime.GetDayOfWeek())],
				monthNames[static_cast<int>(dateTime.GetMonth())], dateTime.GetDay(),
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

// datetime.isleap(year:number):map
Gura_DeclareClassMethod(datetime, isleap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `true` if the specified year is a leap one.");
}

Gura_ImplementClassMethod(datetime, isleap)
{
	return Value(DateTime::IsLeapYear(args.GetShort(0)));
}

// datetime.monthdays(year:number, month:number):map {block?}
Gura_DeclareClassMethod(datetime, monthdays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
	DeclareArg(env, "month", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a number of days that exists in the specified month.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("n", "number"));
}

Gura_ImplementClassMethod(datetime, monthdays)
{
	int year = args.GetInt(0);
	int month = args.GetInt(1);
	return ReturnValue(env, args,
			Value(static_cast<Number>(DateTime::GetDaysOfMonth(year, month))));
}

// datetime.now():[utc] {block?}
Gura_DeclareClassMethod(datetime, now)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(utc));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `datetime` instance of the current time.\n"
		"\n"
		"In default, the timezone offset is set to one in the system setting.\n"
		"Specifying `:utc` attribute would set the offset to 0.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("dt", "datetime"));
}

Gura_ImplementClassMethod(datetime, now)
{
	DateTime dateTime = OAL::GetCurDateTime(args.IsSet(Gura_Symbol(utc)));
	return ReturnValue(env, args, Value(new Object_datetime(env, dateTime)));
}

// datetime.parse(str:string):map {block?}
Gura_DeclareClassMethod(datetime, parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Parses a string that describs date and time information\n"
		"and returns the `datetime` instance.\n"
		"\n"
		"It is capable of parsing the following style:\n"
		"\n"
		"- RFC1123 style. eg) `'Sat, 06 Nov 2010 08:49:37 GMT'`\n"
		"- RFC1036 style. eg) `'Saturday, 06-Nov-10 08:49:37 GMT'`\n"
		"- C's `asctime()` style. eg) `'Sat Nov  6 08:49:37 2010'`,\n"
		"                             `'Sat Nov  6 08:49:37 +0000 2010'`\n"
		"- W3C style. eg) `'2010-11-06T08:49:37Z'`\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("dt", "datetime"));
}

Gura_ImplementClassMethod(datetime, parse)
{
	DateTime dateTime;
	if (!dateTime.Parse(args.GetString(0))) {
		sig.SetError(ERR_FormatError, "invalid time format");
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_datetime(env, dateTime)));
}

// datetime#settzoff(mins:number):reduce
Gura_DeclareMethod(datetime, settzoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "mins", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets timezone offset in minutes.");
}

Gura_ImplementMethod(datetime, settzoff)
{
	DateTime &dateTime = Object_datetime::GetThisObj(args)->GetDateTime();
	dateTime.SetTZOffset(args.GetLong(0) * 60);
	return args.GetThis();
}

// datetime.time(hour:number => 0, minute:number => 0, sec:number => 0, usec:number => 0):map {block?}
Gura_DeclareClassMethod(datetime, time)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hour", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "minute", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "sec", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "usec", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `datetime` instance from time information.\n"
		"The date inforomation is set as 1st of January in the Christian year of 0.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("dt", "datetime"));
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
	return ReturnValue(env, args,
		Value(new Object_datetime(env, DateTime(year, month, day, sec, usec, secsOffset))));
}

// datetime.today():[utc] {block?}
Gura_DeclareClassMethod(datetime, today)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(utc));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `datetime` instance of today. All the time information are cleared to 0.\n"
		"\n"
		"In default, the timezone offset is set to one in the system setting.\n"
		"Specifying `:utc` attribute would set the offset to 0.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("dt", "datetime"));
}

Gura_ImplementClassMethod(datetime, today)
{
	DateTime dateTime = OAL::GetCurDateTime(args.IsSet(Gura_Symbol(utc)));
	dateTime.ClearTime();
	return ReturnValue(env, args, Value(new Object_datetime(env, dateTime)));
}

// datetime#utc()
Gura_DeclareMethod(datetime, utc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Calculates UTC time of the target `datetime` instance.\n"
		"An error occurs if the instance has no timezone offset\n");
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

// datetime.weekday(year:number, month:number, day:number):map
Gura_DeclareClassMethod(datetime, weekday)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
	DeclareArg(env, "month", VTYPE_number);
	DeclareArg(env, "day", VTYPE_number);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a week number for the specified date, which starts from 0 for Sunday.\n");
}

Gura_ImplementClassMethod(datetime, weekday)
{
	int year = args.GetInt(0);
	int month = args.GetInt(1);
	int day = args.GetInt(2);
	return Value(static_cast<Number>(DateTime::GetDayOfWeek(year, month, day)));
}

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
	Gura_AssignMethod(datetime, clrtzoff);
	Gura_AssignMethod(datetime, format);
	Gura_AssignMethod(datetime, isleap);
	Gura_AssignMethod(datetime, monthdays);
	Gura_AssignMethod(datetime, now);
	Gura_AssignMethod(datetime, parse);
	Gura_AssignMethod(datetime, settzoff);
	Gura_AssignMethod(datetime, time);
	Gura_AssignMethod(datetime, today);
	Gura_AssignMethod(datetime, utc);
	Gura_AssignMethod(datetime, weekday);
}

Object *Class_datetime::CreateDescendant(Environment &env, Signal &sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
