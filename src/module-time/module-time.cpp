//-----------------------------------------------------------------------------
// Gura time module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(time)

Gura_DeclarePrivUserSymbol(utc);

//-----------------------------------------------------------------------------
// Gura module functions: time
//-----------------------------------------------------------------------------
// time.monthdays(year:number, month:number):map
Gura_DeclareFunction(monthdays)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
	DeclareArg(env, "month", VTYPE_number);
}

Gura_ImplementFunction(monthdays)
{
	int year = args.GetInt(0);
	int month = args.GetInt(1);
	return Value(static_cast<Number>(DateTime::GetDaysOfMonth(year, month)));
}

// time.weekday(year:number, month:number, day:number):map
Gura_DeclareFunction(weekday)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
	DeclareArg(env, "month", VTYPE_number);
	DeclareArg(env, "day", VTYPE_number);
}

Gura_ImplementFunction(weekday)
{
	int year = args.GetInt(0);
	int month = args.GetInt(1);
	int day = args.GetInt(2);
	return Value(static_cast<Number>(DateTime::GetDayOfWeek(year, month, day)));
}

// time.now():[utc]
Gura_DeclareFunction(now)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_UserSymbol(utc));
}

Gura_ImplementFunction(now)
{
	DateTime dateTime = OAL::GetCurDateTime(args.IsSet(Gura_UserSymbol(utc)));
	return Value(env, dateTime);
}

// time.today():[utc]
Gura_DeclareFunction(today)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareAttr(Gura_UserSymbol(utc));
}

Gura_ImplementFunction(today)
{
	DateTime dateTime = OAL::GetCurDateTime(args.IsSet(Gura_UserSymbol(utc)));
	dateTime.ClearTime();
	return Value(env, dateTime);
}

// time.time(hour:number => 0, minute:number => 0, sec:number => 0, usec:number => 0):map
Gura_DeclareFunction(time)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "hour", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "minute", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "sec", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "usec", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
}

Gura_ImplementFunction(time)
{
	short year = 0;
	char month = 1;
	char day = 1;
	long sec = static_cast<long>(args.GetNumber(0) * 3600 +
						args.GetNumber(1) * 60 + args.GetNumber(2));
	long usec = args.GetLong(3);
	long secsOffset = OAL::GetSecsOffsetTZ();
	return Value(env, DateTime(year, month, day, sec, usec, secsOffset));
}

// time.parse(str:string):map
Gura_DeclareFunction(parse)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "str", VTYPE_string);
}

Gura_ImplementFunction(parse)
{
	DateTime dateTime;
	if (!dateTime.Parse(args.GetString(0))) {
		sig.SetError(ERR_FormatError, "invalid time format");
		return Value::Null;
	}
	return Value(env, dateTime);
}

// time.isleap(year:number):map
Gura_DeclareFunction(isleap)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "year", VTYPE_number);
}

Gura_ImplementFunction(isleap)
{
	return Value(DateTime::IsLeapYear(args.GetShort(0)));
}

Gura_ModuleEntry()
{
	Gura_RealizeUserSymbol(utc);
	// value assignment
	Gura_AssignValue(Sunday,	Value(0));
	Gura_AssignValue(Monday,	Value(1));
	Gura_AssignValue(Tuesday,	Value(2));
	Gura_AssignValue(Wednesday,	Value(3));
	Gura_AssignValue(Thursday,	Value(4));
	Gura_AssignValue(Friday,	Value(5));
	Gura_AssignValue(Saturday,	Value(6));
	// function assignment
	Gura_AssignFunction(monthdays);
	Gura_AssignFunction(weekday);
	Gura_AssignFunction(now);
	Gura_AssignFunction(today);
	Gura_AssignFunction(time);
	Gura_AssignFunction(parse);
	Gura_AssignFunction(isleap);
}

Gura_ModuleTerminate()
{
}


Gura_EndModuleBody(time, time)

Gura_RegisterModule(time)
