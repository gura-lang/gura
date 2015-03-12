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

Object_mpq::Object_mpq(const mpq_class &num) : Object(Gura_UserClass(mpq)), _num(num)
{
}

bool Object_mpq::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(numer));
	symbols.insert(Gura_Symbol(denom));
	return true;
}

Value Object_mpq::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(numer))) {
		return Value(new Object_mpz(_num.get_num_mpz_t()));
	} else if (pSymbol->IsIdentical(Gura_Symbol(denom))) {
		return Value(new Object_mpz(_num.get_den_mpz_t()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_mpq::ToString(bool exprFlag)
{
	String str;
	str += _num.get_num().get_str().c_str();
	if (_num.get_den() != 1) {
		str += "/";
		str += _num.get_den().get_str().c_str();
	}
	str += "Lr";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gmp.mpq(numer?, denom?:number):map {block?}
Gura_DeclareFunction(mpq)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "numer", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "denom", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_mpq));
}

Gura_ImplementFunction(mpq)
{
	Value value;
	if (args.IsInvalid(0)) {
		// nothing to do
	} else if (args.Is_number(0)) {
		mpq_t num;
		::mpq_init(num);
		::mpz_set_si(mpq_numref(num), args.GetInt(0));
		if (args.Is_number(1)) {
			::mpz_set_si(mpq_denref(num), args.GetInt(1));
		}
		value = Value(new Object_mpq(num));
	} else if (args.Is_string(0)) {
		mpq_t num;
		::mpq_init(num);
		if (::mpq_set_str(num, args.GetString(0), 0) < 0) {
			::mpq_clear(num);
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpq");
			return Value::Null;
		}
		value = Value(new Object_mpq(num));
	} else if (args.IsType(0, VTYPE_mpq)) {
		value = args.GetValue(0); // no change
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, value);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// gmp.mpq#cast@mpf() {block?}
Gura_DeclareMethodAlias(mpq, cast_mpf, "cast@mpf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(mpq, cast_mpf)
{
	const mpq_class &num = Object_mpq::GetThisEntity(args);
	mpf_class numResult = MpfFromMpq(sig, num);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(new Object_mpf(numResult)));
}

// string#cast@mpq(base?:number):map {block?}
Gura_DeclareMethodAlias(string, cast_mpq, "cast@mpq")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "base", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(string, cast_mpq)
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
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mpq)
{
	// assignment of functions
	Gura_AssignFunction(mpq);
	// assignment of methods
	Gura_AssignMethod(mpq, cast_mpf);
	Gura_AssignMethodTo(VTYPE_string, string, cast_mpq);
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
	} else if (value.Is_rational()) {
		mpq_class num = MpqFromRational(value.GetRational());
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

bool Gura_ClassName(mpq)::Format_d(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_d(sig, pFormatter, flags, Object_mpq::GetEntity(value));
}

bool Gura_ClassName(mpq)::Format_b(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	//return _Format_b(sig, pFormatter, flags, Object_mpq::GetEntity(value));
	return Class::Format_b(sig, pFormatter, flags, value);
}

bool Gura_ClassName(mpq)::Format_o(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_o(sig, pFormatter, flags, Object_mpq::GetEntity(value));
}

bool Gura_ClassName(mpq)::Format_x(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_x(sig, pFormatter, flags, Object_mpq::GetEntity(value));
}

Gura_EndModuleScope(gmp)
