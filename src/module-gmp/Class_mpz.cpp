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
	String str = _num.get_str().c_str();
	str += "L";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gmp.mpz(value?):map {block?}
Gura_DeclareFunction(mpz)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_mpz));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `gmp.mpz` instance.\n"
		"\n"
		"If the argument `value` is specified, it would be casted to `gmp.mpz`.\n"
		"Acceptable types for `value` are: `number`, `string`,\n"
		"`gmp.mpf` and `gmp.mpz`.\n");
}

Gura_ImplementFunction(mpz)
{
	Value value;
	if (args.IsInvalid(0)) {
		value = Value(new Object_mpz(mpz_class(0)));
	} else if (args.Is_number(0)) {
		value = Value(new Object_mpz(mpz_class(args.GetDouble(0))));
	} else if (args.Is_string(0)) {
		mpz_class num;
		if (num.set_str(args.GetString(0), 0) < 0) {
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpz");
			return Value::Null;
		}
		value = Value(new Object_mpz(num));
	} else if (args.IsType(0, VTYPE_mpz)) {
		value = args.GetValue(0); // no change
	} else if (args.IsType(0, VTYPE_mpf)) {
		mpz_class num(Object_mpf::GetEntity(args, 0));
		value = Value(new Object_mpz(num));
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, value);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// string#cast@mpz(base?:number):map {block?}
Gura_DeclareMethodAlias(string, cast_mpz, "cast@mpz")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Casts the string to `gmp.mpz`.\n"
		"\n"
		"You can specify the basement of the number format by the argument `base`.\n"
		"If it's omitted, the basement would be decided by the prefix described in the string\n"
		"such as \"`0`\" and \"`0x`\".\n"
		"\n"
		GURA_BLOCK_HELP("num", "gmp.mpz"));
}

Gura_ImplementMethod(string, cast_mpz)
{
	const char *strThis = args.GetThis().GetString();
	int base = args.Is_number(0)? args.GetInt(0) : 0;
	mpz_class num;
	if (num.set_str(strThis, base) < 0) {
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
	Gura_AssignMethodTo(VTYPE_string, string, cast_mpz);
}

Gura_ImplementCastFrom(mpz)
{
	if (value.Is_number()) {
		mpz_class num = value.GetDouble();
		value = Value(new Object_mpz(num));
		return true;
	} else if (value.Is_string()) {
		mpz_class num;
		if (num.set_str(value.GetString(), 0) < 0) {
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
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_d(sig, pFormatter, flags, Object_mpz::GetEntity(value));
}

bool Gura_ClassName(mpz)::Format_u(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_u(sig, pFormatter, flags, Object_mpz::GetEntity(value));
}

bool Gura_ClassName(mpz)::Format_b(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	//return _Format_b(sig, pFormatter, flags, Object_mpz::GetEntity(value));
	return Class::Format_b(sig, pFormatter, flags, value);
}

bool Gura_ClassName(mpz)::Format_o(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_o(sig, pFormatter, flags, Object_mpz::GetEntity(value));
}

bool Gura_ClassName(mpz)::Format_x(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_x(sig, pFormatter, flags, Object_mpz::GetEntity(value));
}

bool Gura_ClassName(mpz)::Format_e(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_e(sig, pFormatter, flags, Object_mpz::GetEntity(value));
}

bool Gura_ClassName(mpz)::Format_f(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_f(sig, pFormatter, flags, Object_mpz::GetEntity(value));
}

bool Gura_ClassName(mpz)::Format_g(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_g(sig, pFormatter, flags, Object_mpz::GetEntity(value));
}

Gura_EndModuleScope(gmp)
