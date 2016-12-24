//=============================================================================
// Gura class: timedelta
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_timedelta
//-----------------------------------------------------------------------------
Object_timedelta::Object_timedelta(const Object_timedelta &obj) :
										Object(obj), _timeDelta(obj._timeDelta)
{
}

Object_timedelta::~Object_timedelta()
{
}

Object *Object_timedelta::Clone() const
{
	return new Object_timedelta(*this);
}

String Object_timedelta::ToString(bool exprFlag)
{
	String str;
	str += "<timedelta:";
	str += _timeDelta.ToString();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// timedelta(days:number => 0, secs:number => 0, usecs:number => 0):map {block?}
Gura_DeclareFunction(timedelta)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "days", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareArg(env, "secs", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareArg(env, "usecs", VTYPE_number, OCCUR_Once, FLAG_None, 0, new Expr_Value(0));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_timedelta));
	AddHelp(
		Gura_Symbol(en), 
		"Returns a timedelta instance with specified values. The instance actually\n"
		"holds properties of days, secs and usecs.\n");
}

Gura_ImplementFunction(timedelta)
{
	long days = static_cast<long>(arg.GetNumber(0));
	long secs = static_cast<long>(arg.GetNumber(1));
	long usecs = static_cast<long>(arg.GetNumber(2));
	return ReturnValue(env, arg, Value(new Object_timedelta(env, TimeDelta(days, secs, usecs))));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// timedelta#days
Gura_DeclareProperty_RW(timedelta, days)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(timedelta, days)
{
	const TimeDelta &timeDelta = Object_timedelta::GetObject(valueThis)->GetTimeDelta();
	return Value(timeDelta.GetDays());
}

Gura_ImplementPropertySetter(timedelta, days)
{
	TimeDelta &timeDelta = Object_timedelta::GetObject(valueThis)->GetTimeDelta();
	timeDelta = TimeDelta(value.GetLong(), timeDelta.GetSecs(), timeDelta.GetUSecs());
	return value;
}

// timedelta#secs
Gura_DeclareProperty_RW(timedelta, secs)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(timedelta, secs)
{
	const TimeDelta &timeDelta = Object_timedelta::GetObject(valueThis)->GetTimeDelta();
	return Value(timeDelta.GetSecsRaw());
}

Gura_ImplementPropertySetter(timedelta, secs)
{
	TimeDelta &timeDelta = Object_timedelta::GetObject(valueThis)->GetTimeDelta();
	timeDelta = TimeDelta(timeDelta.GetDays(), value.GetLong(), timeDelta.GetUSecs());
	return value;
}

// timedelta#usecs
Gura_DeclareProperty_RW(timedelta, usecs)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(timedelta, usecs)
{
	const TimeDelta &timeDelta = Object_timedelta::GetObject(valueThis)->GetTimeDelta();
	return Value(timeDelta.GetUSecs());
}

Gura_ImplementPropertySetter(timedelta, usecs)
{
	TimeDelta &timeDelta = Object_timedelta::GetObject(valueThis)->GetTimeDelta();
	timeDelta = TimeDelta(timeDelta.GetDays(), timeDelta.GetSecs(), value.GetLong());
	return value;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_timedelta::Class_timedelta(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_timedelta)
{
}

void Class_timedelta::DoPrepare(Environment &env)
{
	// Assignment of function
	Gura_AssignFunction(timedelta);
	// Assignment of properties
	Gura_AssignProperty(timedelta, days);
	Gura_AssignProperty(timedelta, secs);
	Gura_AssignProperty(timedelta, usecs);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Object *Class_timedelta::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
