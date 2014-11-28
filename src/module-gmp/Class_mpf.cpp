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

Object_mpf::Object_mpf(const mpf_class &num) : Object(Gura_UserClass(mpf)), _num(num)
{
}

bool Object_mpf::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(prec));
	return true;
}

Value Object_mpf::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(prec))) {
		return Value(_num.get_prec());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_mpf::DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(prec))) {
		if (!value.MustBe_number(sig)) return Value::Null;
		ULong prec = value.GetULong();
		_num.set_prec(prec);
		return Value(prec);
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_mpf::ToString(bool exprFlag)
{
	char *p = NULL;
	::gmp_asprintf(&p, "%.Ff", _num.get_mpf_t());
	String str = p;
	if (::strchr(p, '.') == NULL) str += '.';
	str += 'L';
	::free(p);
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// gmp.mpf(value?, prec?:number):map {block?}
Gura_DeclareFunction(mpf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "value", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "prec", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_mpf));
}

Gura_ImplementFunction(mpf)
{
	Value value;
	ULong prec = args.Is_number(1)? args.GetInt(1) : ::mpf_get_default_prec();
	if (args.IsInvalid(0)) {
		value = Value(new Object_mpf(mpf_class(0, prec)));
	} else if (args.Is_number(0)) {
		value = Value(new Object_mpf(mpf_class(args.GetDouble(0), prec)));
	} else if (args.Is_string(0)) {
		mpf_class num;
		num.set_prec(prec);
		if (num.set_str(args.GetString(0), 0) < 0) {
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
			return Value::Null;
		}
		value = Value(new Object_mpf(num));
	} else if (args.IsType(0, VTYPE_mpf)) {
		value = args.GetValue(0); // no change
	} else if (args.IsType(0, VTYPE_mpz)) {
		mpf_class num(Object_mpz::GetEntity(args, 0), prec);
		value = Value(new Object_mpf(num));
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, sig, args, value);
}

//-----------------------------------------------------------------------------
// Implementation of class methods
//-----------------------------------------------------------------------------
// gmp.mpf.get_defaul_prec()
Gura_DeclareClassMethod(mpf, get_default_prec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementClassMethod(mpf, get_default_prec)
{
	ULong prec = static_cast<ULong>(::mpf_get_default_prec());
	return Value(prec);
}

// gmp.mpf.set_defaul_prec(prec:number):void
Gura_DeclareClassMethod(mpf, set_default_prec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "prec", VTYPE_number);
}

Gura_ImplementClassMethod(mpf, set_default_prec)
{
	ULong prec = args.GetULong(0);
	::mpf_set_default_prec(prec);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Implementation of instance methods
//-----------------------------------------------------------------------------
// string#mpf(base?:number):map {block?}
Gura_DeclareMethod(string, mpf)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
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
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mpf)
{
	// assignment of function
	Gura_AssignFunction(mpf);
	// assignment of class methods
	Gura_AssignMethod(mpf, get_default_prec);
	Gura_AssignMethod(mpf, set_default_prec);
	// assignment of instance methods
	
	Gura_AssignMethodTo(VTYPE_string, string, mpf);
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
	} else if (value.IsType(VTYPE_mpz)) {
		
	} else if (value.IsType(VTYPE_mpq)) {
		
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

bool Gura_ClassName(mpf)::Format_d(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_d(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_u(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_u(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_b(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	//mpz_class num(Object_mpf::GetEntity(value));
	//return _Format_b(sig, pFormatter, flags, num);
	return Class::Format_b(sig, pFormatter, flags, value);
}

bool Gura_ClassName(mpf)::Format_o(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_o(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_x(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_x(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_e(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_e(sig, pFormatter, flags, Object_mpf::GetEntity(value));
}

bool Gura_ClassName(mpf)::Format_f(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_f(sig, pFormatter, flags, Object_mpf::GetEntity(value));
}

bool Gura_ClassName(mpf)::Format_g(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	return _Format_g(sig, pFormatter, flags, Object_mpf::GetEntity(value));
}

Gura_EndModuleScope(gmp)
