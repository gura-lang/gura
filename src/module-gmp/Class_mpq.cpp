//=============================================================================
// Gura class: gmp.mpq
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpq
//-----------------------------------------------------------------------------
Object_mpq::Object_mpq(mpq_t num) : Object(Gura_UserClass(mpq)), _num(num)
{
}

bool Object_mpq::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	return true;
}

Value Object_mpq::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Null;
}

String Object_mpq::ToString(bool exprFlag)
{
	return _num.get_str();
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gmp.mpq(numer?, denom?) {block?}
Gura_DeclareFunction(mpq)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "numer", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "denom", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_mpq));
}

Gura_ImplementFunction(mpq)
{
	mpq_t num;
	::mpq_init(num);
	if (args.IsInvalid(0)) {
		// nothing to do
	} else if (args.Is_number(0)) {
		::mpq_set_d(num, args.GetDouble(0));
	} else if (args.Is_string(0)) {
		if (::mpq_set_str(num, args.GetString(0), 0) < 0) {
			::mpq_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpq");
			return Value::Null;
		}
	} else {
		::mpq_clear(num);
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpq(num)));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// string#mpq(base?:number):map {block?}
Gura_DeclareMethod(string, mpq)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, mpq)
{
	const char *strThis = args.GetThis().GetString();
	int base = args.Is_number(0)? args.GetInt(0) : 0;
	mpq_t num;
	::mpq_init(num);
	if (::mpq_set_str(num, strThis, base) < 0) {
		::mpq_clear(num);
		sig.SetError(ERR_ValueError, "invalid string format for gmp.mpq");
		return false;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpq(num)));
}

//-----------------------------------------------------------------------------
// Implementation of operators
//-----------------------------------------------------------------------------
// operator +
Gura_ImplementBinaryOperator(Add, mpq, mpq)
{
	mpq_class num = Object_mpq::GetEntity(valueLeft) + Object_mpq::GetEntity(valueRight);
	return Value(new Object_mpq(num.get_mpq_t()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mpq)
{
	// function assignment
	Gura_AssignFunction(mpq);
	// method assignment
	Gura_AssignMethodTo(VTYPE_string, string, mpq);
	// operator assignment
	Gura_AssignBinaryOperator(Add, mpq, mpq);
}

Gura_ImplementCastFrom(mpq)
{
	if (value.Is_number()) {
		mpq_t num;
		::mpq_init(num);
		::mpq_set_d(num, value.GetDouble());
		value = Value(new Object_mpq(num));
		return true;
	} else if (value.Is_string()) {
		mpq_t num;
		::mpq_init(num);
		if (::mpq_set_str(num, value.GetString(), 0) < 0) {
			::mpq_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpq");
			return false;
		}
		value = Value(new Object_mpq(num));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(mpq)
{
	if (decl.IsType(VTYPE_number)) {
		double num = Object_mpq::GetEntity(value).get_d();
		value = Value(num);
		return true;
	}
	return false;
}

Gura_EndModuleScope(gmp)
