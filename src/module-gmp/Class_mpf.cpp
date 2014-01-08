//=============================================================================
// Gura class: gmp.mpf
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpf
//-----------------------------------------------------------------------------
Object_mpf::Object_mpf(mpf_t num) : Object(Gura_UserClass(mpf)), _num(num)
{
}

bool Object_mpf::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	return true;
}

Value Object_mpf::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Null;
}

String Object_mpf::ToString(bool exprFlag)
{
	mp_exp_t exp;
	return _num.get_str(exp);
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gmp.mpf(value?) {block?}
Gura_DeclareFunction(mpf)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_mpf));
}

Gura_ImplementFunction(mpf)
{
	mpf_t num;
	::mpf_init(num);
	if (args.IsInvalid(0)) {
		// nothing to do
	} else if (args.Is_number(0)) {
		::mpf_set_d(num, args.GetDouble(0));
	} else if (args.Is_string(0)) {
		if (::mpf_set_str(num, args.GetString(0), 0) < 0) {
			::mpf_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
			return Value::Null;
		}
	} else {
		::mpf_clear(num);
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpf(num)));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// string#mpf(base?:number):map {block?}
Gura_DeclareMethod(string, mpf)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, mpf)
{
	const char *strThis = args.GetThis().GetString();
	int base = args.Is_number(0)? args.GetInt(0) : 0;
	mpf_t num;
	::mpf_init(num);
	if (::mpf_set_str(num, strThis, base) < 0) {
		::mpf_clear(num);
		sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
		return false;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpf(num)));
}

//-----------------------------------------------------------------------------
// Implementation of operators
//-----------------------------------------------------------------------------
// operator +
Gura_ImplementBinaryOperator(Add, mpf, mpf)
{
	mpf_class num = Object_mpf::GetEntity(valueLeft) + Object_mpf::GetEntity(valueRight);
	return Value(new Object_mpf(num.get_mpf_t()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mpf)
{
	// function assignment
	Gura_AssignFunction(mpf);
	// method assignment
	Gura_AssignMethodTo(VTYPE_string, string, mpf);
	// operator assignment
	Gura_AssignBinaryOperator(Add, mpf, mpf);
}

Gura_ImplementCastFrom(mpf)
{
	if (value.Is_number()) {
		mpf_t num;
		::mpf_init(num);
		::mpf_set_d(num, value.GetDouble());
		value = Value(new Object_mpf(num));
		return true;
	} else if (value.Is_string()) {
		mpf_t num;
		::mpf_init(num);
		if (::mpf_set_str(num, value.GetString(), 0) < 0) {
			::mpf_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
			return false;
		}
		value = Value(new Object_mpf(num));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(mpf)
{
	if (decl.IsType(VTYPE_number)) {
		double num = Object_mpf::GetEntity(value).get_d();
		value = Value(num);
		return true;
	}
	return false;
}

Gura_EndModuleScope(gmp)
