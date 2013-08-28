//
// Object_datetime
//

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

String Object_datetime::ToString(Signal sig, bool exprFlag)
{
	String str;
	str += "<datetime:";
	str += _dateTime.ToString("%Y-%m-%dT%H:%M:%S");
	str += _dateTime.GetTZOffsetStr(true);
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_datetime
//-----------------------------------------------------------------------------
// datetime#format(format => `w3c)
Gura_DeclareMethod(datetime, format)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_any, OCCUR_Once,
								FLAG_None, new Expr_Value(Gura_Symbol(w3c)));
	AddHelp(Gura_Symbol(en), FMT_markdown, 
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
	if (args.IsString(0)) {
		return Value(env, dateTime.ToString(args.GetString(0)).c_str());
	} else if (args.IsSymbol(0)) {
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
		return Value(env, str);
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
	return Value(env, dateTime.ToUTC());
}

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

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_datetime::Class_datetime(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_datetime)
{
}

void Class_datetime::Prepare(Environment &env)
{
	Gura_AssignMethod(datetime, format);
	Gura_AssignMethod(datetime, settzoff);
	Gura_AssignMethod(datetime, clrtzoff);
	Gura_AssignMethod(datetime, utc);
	Gura_AssignMethod(datetime, isleap);
}

Object *Class_datetime::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
