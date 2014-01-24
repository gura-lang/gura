//=============================================================================
// Gura class: gmp.mpz
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Object_mpz
//-----------------------------------------------------------------------------
Object_mpz::Object_mpz(mpz_t num) : Object(Gura_UserClass(mpz)), _num(num)
{
}

Object_mpz::Object_mpz(const mpz_class &num) : Object(Gura_UserClass(mpz)), _num(num)
{
}

bool Object_mpz::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	return true;
}

Value Object_mpz::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Null;
}

String Object_mpz::ToString(bool exprFlag)
{
	String str = _num.get_str();
	str += "L";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gmp.mpz(value?) {block?}
Gura_DeclareFunction(mpz)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_mpz));
}

Gura_ImplementFunction(mpz)
{
	mpz_t num;
	::mpz_init(num);
	if (args.IsInvalid(0)) {
		// nothing to do
	} else if (args.Is_number(0)) {
		::mpz_set_d(num, args.GetDouble(0));
	} else if (args.Is_string(0)) {
		if (::mpz_set_str(num, args.GetString(0), 0) < 0) {
			::mpz_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpz");
			return Value::Null;
		}
	} else {
		::mpz_clear(num);
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpz(num)));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// string#mpz(base?:number):map {block?}
Gura_DeclareMethod(string, mpz)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, mpz)
{
	const char *strThis = args.GetThis().GetString();
	int base = args.Is_number(0)? args.GetInt(0) : 0;
	mpz_t num;
	::mpz_init(num);
	if (::mpz_set_str(num, strThis, base) < 0) {
		::mpz_clear(num);
		sig.SetError(ERR_ValueError, "invalid string format for gmp.mpz");
		return false;
	}
	return ReturnValue(env, sig, args, Value(new Object_mpz(num)));
}


//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mpz)
{
	// assignment of functions
	Gura_AssignFunction(mpz);
	// assignment of methods
	Gura_AssignMethodTo(VTYPE_string, string, mpz);
}

Gura_ImplementCastFrom(mpz)
{
	if (value.Is_number()) {
		mpz_t num;
		::mpz_init(num);
		::mpz_set_d(num, value.GetDouble());
		value = Value(new Object_mpz(num));
		return true;
	} else if (value.Is_string()) {
		mpz_t num;
		::mpz_init(num);
		if (::mpz_set_str(num, value.GetString(), 0) < 0) {
			::mpz_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpz");
			return false;
		}
		value = Value(new Object_mpz(num));
		return true;
	}
	return false;
}

Gura_ImplementCastTo(mpz)
{
	if (decl.IsType(VTYPE_number)) {
		double num = Object_mpz::GetEntity(value).get_d();
		value = Value(num);
		return true;
	}
	return false;
}

bool Gura_ClassName(mpz)::Format_d(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const Value &value) const
{
	return false;
}

bool Gura_ClassName(mpz)::Format_u(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const Value &value) const
{
	return false;
}

bool Gura_ClassName(mpz)::Format_b(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const Value &value) const
{
	return false;
}

bool Gura_ClassName(mpz)::Format_o(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const Value &value) const
{
	return false;
}

bool Gura_ClassName(mpz)::Format_x(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const Value &value) const
{
	return false;
}

Gura_EndModuleScope(gmp)
