//
// Object_timedelta
//

#include "stdafx.h"

namespace Gura {

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

bool Object_timedelta::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(days));
	symbols.insert(Gura_Symbol(secs));
	symbols.insert(Gura_Symbol(usecs));
	return true;
}

Value Object_timedelta::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(days))) {
		return Value(static_cast<Number>(_timeDelta.GetDays()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(secs))) {
		return Value(static_cast<Number>(_timeDelta.GetSecsRaw()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(usecs))) {
		return Value(static_cast<Number>(_timeDelta.GetUSecs()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_timedelta::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(days))) {
		_timeDelta = TimeDelta(value.GetLong(), _timeDelta.GetSecs(), _timeDelta.GetUSecs());
		return Value(static_cast<Number>(_timeDelta.GetDays()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(secs))) {
		_timeDelta = TimeDelta(_timeDelta.GetDays(), value.GetLong(), _timeDelta.GetUSecs());
		return Value(static_cast<Number>(_timeDelta.GetSecsRaw()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(usecs))) {
		_timeDelta = TimeDelta(_timeDelta.GetDays(), _timeDelta.GetSecs(), value.GetLong());
		return Value(static_cast<Number>(_timeDelta.GetUSecs()));
	}
	evaluatedFlag = false;
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
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
// Gura interfaces for Object_timedelta
//-----------------------------------------------------------------------------
// timedelta(days:number => 0, secs:number => 0, usecs:number => 0):map {block?}
Gura_DeclareFunction(timedelta)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "days", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "secs", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareArg(env, "usecs", VTYPE_number, OCCUR_Once, FLAG_None, new Expr_Value(0));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_timedelta));
	AddHelp(Gura_Symbol(en), Help::FMT_markdown, 
	"Returns a timedelta instance with specified values. The instance actually\n"
	"holds properties of days, secs and usecs.\n");
}

Gura_ImplementFunction(timedelta)
{
	long days = static_cast<long>(args.GetNumber(0));
	long secs = static_cast<long>(args.GetNumber(1));
	long usecs = static_cast<long>(args.GetNumber(2));
	return ReturnValue(env, sig, args, Value(new Object_timedelta(env, TimeDelta(days, secs, usecs))));
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_timedelta::Class_timedelta(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_timedelta)
{
}

void Class_timedelta::Prepare(Environment &env)
{
	Gura_AssignFunction(timedelta);
}

Object *Class_timedelta::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
