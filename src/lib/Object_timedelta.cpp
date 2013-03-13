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

String Object_timedelta::ToString(Signal sig, bool exprFlag)
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

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_timedelta::Class_timedelta(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_timedelta)
{
}

Object *Class_timedelta::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_timedelta::OnModuleEntry(Environment &env, Signal sig)
{
}

}
