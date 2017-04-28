//=============================================================================
// Gura class: datetime
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

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
	DeclareArg(env, "hour", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareArg(env, "min", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareArg(env, "sec", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareArg(env, "usec", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareArg(env, "minsoff", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_datetime));
	AddHelp(
		Gura_Symbol(en),
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
	short year = static_cast<short>(arg.GetLong(0));
	char month = static_cast<char>(arg.GetLong(1));
	char day = static_cast<char>(arg.GetLong(2));
	long sec = static_cast<long>(arg.GetLong(3) * 3600 +
								arg.GetLong(4) * 60 + arg.GetLong(5));
	long usec = arg.GetLong(6);
	long secsOffset = 0;
	if (arg.Is_number(7)) {
		secsOffset = arg.GetLong(7) * 60;
	} else {
		secsOffset = OAL::GetSecsOffsetTZ();
	}
	return ReturnValue(env, arg,
		Value(new Object_datetime(env, DateTime(year, month, day, sec, usec, secsOffset))));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// datetime#year
Gura_DeclareProperty_RW(datetime, year)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, year)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	return Value(static_cast<Number>(dateTime.GetYear()));
}

Gura_ImplementPropertySetter(datetime, year)
{
	DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	long num = value.GetLong();
	if (num < 1 || num > 9999) {
		env.SetError(ERR_ValueError, "datetime#year must be betwen 1 and 9999 inclusive");
		return Value::Nil;
	}
	dateTime.SetYear(static_cast<short>(num));
	return Value(num);
}

// datetime#month
Gura_DeclareProperty_RW(datetime, month)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, month)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	return Value(static_cast<Number>(dateTime.GetMonth()));
}

Gura_ImplementPropertySetter(datetime, month)
{
	DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	long num = value.GetLong();
	if (num < 1 || num > 12) {
		env.SetError(ERR_ValueError, "datetime#month must be between 1 and 12 inclusive");
		return Value::Nil;
	}
	dateTime.SetMonth(static_cast<char>(num));
	return Value(num);
}

// datetime#day
Gura_DeclareProperty_RW(datetime, day)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, day)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	return Value(static_cast<Number>(dateTime.GetDay()));
}

Gura_ImplementPropertySetter(datetime, day)
{
	DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	long num = value.GetLong();
	if (num < 1 || num > 31) {
		env.SetError(ERR_ValueError, "datetime#day must be between 1 and 31 inclusive");
		return Value::Nil;
	}
	dateTime.SetDay(static_cast<char>(num));
	return Value(num);
}

// datetime#hour
Gura_DeclareProperty_RW(datetime, hour)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, hour)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	return Value(static_cast<Number>(dateTime.GetHour()));
}

Gura_ImplementPropertySetter(datetime, hour)
{
	DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	long num = value.GetLong();
	if (num < 0 || num > 23) {
		env.SetError(ERR_ValueError, "datetime#hour must be between 0 and 23 inclusive");
		return Value::Nil;
	}
	dateTime.SetHour(static_cast<char>(num));
	return Value(num);
}

// datetime#min
Gura_DeclareProperty_RW(datetime, min)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, min)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	return Value(static_cast<Number>(dateTime.GetMin()));
}

Gura_ImplementPropertySetter(datetime, min)
{
	DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	long num = value.GetLong();
	if (num < 0 || num > 59) {
		env.SetError(ERR_ValueError, "datetime#min must be betwen 0 and 59 inclusive");
		return Value::Nil;
	}
	dateTime.SetMin(static_cast<char>(num));
	return Value(num);
}

// datetime#sec
Gura_DeclareProperty_RW(datetime, sec)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, sec)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	return Value(static_cast<Number>(dateTime.GetSec()));
}

Gura_ImplementPropertySetter(datetime, sec)
{
	DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	long num = value.GetLong();
	if (num < 0 || num > 59) {
		env.SetError(ERR_ValueError, "datetime#sec must be between 0 and 59 inclusive");
		return Value::Nil;
	}
	dateTime.SetSec(static_cast<char>(num));
	return Value(num);
}

// datetime#usec
Gura_DeclareProperty_RW(datetime, usec)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, usec)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	return Value(static_cast<Number>(dateTime.GetUSec()));
}

Gura_ImplementPropertySetter(datetime, usec)
{
	DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	long num = value.GetLong();
	if (num < 0 || num > 999999) {
		env.SetError(ERR_ValueError, "datetime#usec must be between 0 and 999999 inclusive");
		return Value::Nil;
	}
	dateTime.SetUSec(num);
	return Value(num);
}

// datetime#wday
Gura_DeclareProperty_R(datetime, wday)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, wday)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	return Value(static_cast<Number>(dateTime.GetDayOfWeek()));
}

// datetime#week
Gura_DeclareProperty_R(datetime, week)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, week)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	int wday = dateTime.GetDayOfWeek();
	const Symbol *pSymbol =
		(wday == 0)? Gura_Symbol(sunday) :
		(wday == 1)? Gura_Symbol(monday) :
		(wday == 2)? Gura_Symbol(tuesday) :
		(wday == 3)? Gura_Symbol(wednesday) :
		(wday == 4)? Gura_Symbol(thursday) :
		(wday == 5)? Gura_Symbol(friday) :
		(wday == 6)? Gura_Symbol(saturday) : nullptr;
	if (pSymbol == nullptr) return Value::Nil; // this must not happen
	return Value(pSymbol);
}

// datetime#yday
Gura_DeclareProperty_R(datetime, yday)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, yday)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	return Value(static_cast<Number>(dateTime.GetDayOfYear() + 1));
}

// datetime#unixtime
Gura_DeclareProperty_R(datetime, unixtime)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(datetime, unixtime)
{
	const DateTime &dateTime = Object_datetime::GetObject(valueThis)->GetDateTime();
	return Value(static_cast<Number>(dateTime.GetUnixTime()));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// datetime#clrtzoff():reduce
Gura_DeclareMethod(datetime, clrtzoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Eliminates timezone offset information from the instance.");
}

Gura_ImplementMethod(datetime, clrtzoff)
{
	DateTime &dateTime = Object_datetime::GetObjectThis(arg)->GetDateTime();
	dateTime.ClearTZOffset();
	return arg.GetValueThis();
}

// datetime#format(format => `w3c)
Gura_DeclareMethod(datetime, format)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_any, OCCUR_Once,
			   FLAG_None, 0, new Expr_Value(Gura_Symbol(w3c)));
	AddHelp(
		Gura_Symbol(en), 
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
	Signal &sig = env.GetSignal();
	static const char *weekNames[] = {
		"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat",
	};
	static const char *monthNames[] = { "",
		"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
	};
	const DateTime &dateTime = Object_datetime::GetObjectThis(arg)->GetDateTime();
	if (arg.Is_string(0)) {
		return Value(dateTime.ToString(arg.GetString(0)));
	} else if (arg.Is_symbol(0)) {
		const Symbol *pSymbol = arg.GetSymbol(0);
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
			return Value::Nil;
		}
		return Value(str);
	}
	SetError_InvalidValType(sig, arg.GetValue(0));
	return Value::Nil;
}

// datetime.isleap(year:number):map
Gura_DeclareClassMethod(datetime, isleap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the specified year is a leap one.");
}

Gura_ImplementClassMethod(datetime, isleap)
{
	return Value(DateTime::IsLeapYear(arg.GetShort(0)));
}

// datetime.monthdays(year:number, month:number):map {block?}
Gura_DeclareClassMethod(datetime, monthdays)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
	DeclareArg(env, "month", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns a number of days that exists in the specified month.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("n", "number"));
}

Gura_ImplementClassMethod(datetime, monthdays)
{
	int year = arg.GetInt(0);
	int month = arg.GetInt(1);
	return ReturnValue(env, arg,
			Value(static_cast<Number>(DateTime::GetDaysOfMonth(year, month))));
}

// datetime.now():[utc] {block?}
Gura_DeclareClassMethod(datetime, now)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(utc));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `datetime` instance of the current time.\n"
		"\n"
		"In default, the timezone offset is set to one in the system setting.\n"
		"Specifying `:utc` attribute would set the offset to 0.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("dt", "datetime"));
}

Gura_ImplementClassMethod(datetime, now)
{
	DateTime dateTime = OAL::GetCurDateTime(arg.IsSet(Gura_Symbol(utc)));
	return ReturnValue(env, arg, Value(new Object_datetime(env, dateTime)));
}

// datetime.parse(str:string):map {block?}
Gura_DeclareClassMethod(datetime, parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
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
	Signal &sig = env.GetSignal();
	DateTime dateTime;
	if (!dateTime.Parse(arg.GetString(0))) {
		sig.SetError(ERR_FormatError, "invalid time format");
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_datetime(env, dateTime)));
}

// datetime#settzoff(mins:number):reduce
Gura_DeclareMethod(datetime, settzoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "mins", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Sets timezone offset in minutes.");
}

Gura_ImplementMethod(datetime, settzoff)
{
	DateTime &dateTime = Object_datetime::GetObjectThis(arg)->GetDateTime();
	dateTime.SetTZOffset(arg.GetLong(0) * 60);
	return arg.GetValueThis();
}

// datetime.time(hour:number => 0, minute:number => 0, sec:number => 0, usec:number => 0):map {block?}
Gura_DeclareClassMethod(datetime, time)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hour", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareArg(env, "minute", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareArg(env, "sec", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareArg(env, "usec", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
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
	long sec = static_cast<long>(arg.GetNumber(0) * 3600 +
						arg.GetNumber(1) * 60 + arg.GetNumber(2));
	long usec = arg.GetLong(3);
	long secsOffset = OAL::GetSecsOffsetTZ();
	return ReturnValue(env, arg,
		Value(new Object_datetime(env, DateTime(year, month, day, sec, usec, secsOffset))));
}

// datetime.today():[utc] {block?}
Gura_DeclareClassMethod(datetime, today)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_Symbol(utc));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a `datetime` instance of today. All the time information are cleared to 0.\n"
		"\n"
		"In default, the timezone offset is set to one in the system setting.\n"
		"Specifying `:utc` attribute would set the offset to 0.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("dt", "datetime"));
}

Gura_ImplementClassMethod(datetime, today)
{
	DateTime dateTime = OAL::GetCurDateTime(arg.IsSet(Gura_Symbol(utc)));
	dateTime.ClearTime();
	return ReturnValue(env, arg, Value(new Object_datetime(env, dateTime)));
}

// datetime#utc()
Gura_DeclareMethod(datetime, utc)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Calculates UTC time of the target `datetime` instance.\n"
		"An error occurs if the instance has no timezone offset\n");
}

Gura_ImplementMethod(datetime, utc)
{
	Signal &sig = env.GetSignal();
	const DateTime &dateTime = Object_datetime::GetObjectThis(arg)->GetDateTime();
	if (!dateTime.HasTZOffset()) {
		sig.SetError(ERR_ValueError, "datetime has no timezone offset");
		return Value::Nil;
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
		Gura_Symbol(en),
		"Returns a week number for the specified date, which starts from 0 for Sunday.\n");
}

Gura_ImplementClassMethod(datetime, weekday)
{
	int year = arg.GetInt(0);
	int month = arg.GetInt(1);
	int day = arg.GetInt(2);
	return Value(static_cast<Number>(DateTime::GetDayOfWeek(year, month, day)));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_datetime::Class_datetime(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_datetime)
{
}

void Class_datetime::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(datetime);
	// Assignment of properties
	Gura_AssignProperty(datetime, year);
	Gura_AssignProperty(datetime, month);
	Gura_AssignProperty(datetime, day);
	Gura_AssignProperty(datetime, hour);
	Gura_AssignProperty(datetime, min);
	Gura_AssignProperty(datetime, sec);
	Gura_AssignProperty(datetime, usec);
	Gura_AssignProperty(datetime, wday);
	Gura_AssignProperty(datetime, week);
	Gura_AssignProperty(datetime, yday);
	Gura_AssignProperty(datetime, unixtime);
	// Assignment of methods
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
	// Assignment of values
	Gura_AssignClassValue(Sunday,		Value(0));
	Gura_AssignClassValue(Monday,		Value(1));
	Gura_AssignClassValue(Tuesday,		Value(2));
	Gura_AssignClassValue(Wednesday,	Value(3));
	Gura_AssignClassValue(Thursday,		Value(4));
	Gura_AssignClassValue(Friday,		Value(5));
	Gura_AssignClassValue(Saturday,		Value(6));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_datetime::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
