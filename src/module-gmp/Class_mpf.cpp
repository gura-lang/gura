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

bool Object_mpf::DoDirProp(Environment &env, Signal &__to_delete__, SymbolSet &symbols)
{
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(prec));
	return true;
}

Value Object_mpf::DoGetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(prec))) {
		return Value(_num.get_prec());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_mpf::DoSetProp(Environment &env, Signal &__to_delete__, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	Signal &sig = GetSignal();
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
	char *p = nullptr;
	::gmp_asprintf(&p, "%.Ff", _num.get_mpf_t());
	String str = p;
	if (::strchr(p, '.') == nullptr) str += '.';
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
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `gmp.mpf` instance.\n"
		"\n"
		"If the argument `value` is specified, it would be casted to `gmp.mpf`.\n"
		"Acceptable types for `value` are: `number`, `string`,\n"
		"`gmp.mpf`, `gmp.mpz` and `gmp.mpq`.\n"
		"\n"
		"You can specify the precision of the number by the argument `prec`.\n"
		"If it's omitted, a default precision would be applied.\n");
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
	} else if (args.IsType(0, VTYPE_mpq)) {
		mpq_class num(Object_mpq::GetEntity(args, 0));
		mpf_class numResult = MpfFromMpq(sig, num);
		if (sig.IsSignalled()) return Value::Null;
		value = Value(new Object_mpf(numResult));
	} else {
		SetError_ArgumentTypeByIndex(sig, args, 0);
		return Value::Null;
	}
	return ReturnValue(env, args, value);
}

//-----------------------------------------------------------------------------
// Implementation of class methods
//-----------------------------------------------------------------------------
// gmp.mpf.get_defaul_prec()
Gura_DeclareClassMethod(mpf, get_default_prec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Gets the default precision for `gmp.mpf`.\n");
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
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Sets the default precision for `gmp.mpf`.\n");
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
// gmp.mpf#cast@mpz() {block?}
Gura_DeclareMethodAlias(mpf, cast_mpz, "cast@mpz")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(mpf, cast_mpz)
{
	const mpf_class &num = Object_mpf::GetThisEntity(args);
	mpz_class numCasted(num);
	return ReturnValue(env, args, Value(new Object_mpz(numCasted)));
}

// string#cast@mpf(prec?:number) {block?}
Gura_DeclareMethodAlias(string, cast_mpf, "cast@mpf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "prec", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Casts the string to `gmp.mpf`.\n"
		"\n"
		"You can specify the precision of the number by the argument `prec`.\n"
		"If it's omitted, a default precision would be applied.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("num", "gmp.mpf"));
}

Gura_ImplementMethod(string, cast_mpf)
{
	const char *strThis = args.GetThis().GetString();
	int base = 0;
	ULong prec = args.Is_number(0)? args.GetInt(0) : ::mpf_get_default_prec();
	mpf_class num;
	num.set_prec(prec);
	if (num.set_str(strThis, base) < 0) {
		sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
		return Value::Null;
	}
	return ReturnValue(env, args, Value(new Object_mpf(num)));
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
	Gura_AssignMethod(mpf, cast_mpz);
	Gura_AssignMethodTo(VTYPE_string, string, cast_mpf);
}

Gura_ImplementCastFrom(mpf)
{
	Signal &sig = GetSignal();
	if (value.Is_number()) {
		mpf_class num = value.GetDouble();
		value = Value(new Object_mpf(num));
		return true;
	} else if (value.Is_string()) {
		mpf_class num;
		if (num.set_str(value.GetString(), 0) < 0) {
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
			return false;
		}
		value = Value(new Object_mpf(num));
		return true;
	} else if (value.IsType(VTYPE_mpz)) {
		mpf_class num = Object_mpz::GetEntity(value);
		value = Value(new Object_mpf(num));
		return true;
	} else if (value.IsType(VTYPE_mpq)) {
		mpq_class num(Object_mpq::GetEntity(value));
		mpf_class numResult = MpfFromMpq(sig, num);
		if (sig.IsSignalled()) return false;
		value = Value(new Object_mpf(numResult));
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

bool Gura_ClassName(mpf)::Format_d(Signal &__to_delete__, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_d(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_u(Signal &__to_delete__, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_u(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_b(Signal &__to_delete__, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	//mpz_class num(Object_mpf::GetEntity(value));
	//return _Format_b(sig, pFormatter, flags, num);
	return Class::Format_b(sig, pFormatter, flags, value);
}

bool Gura_ClassName(mpf)::Format_o(Signal &__to_delete__, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_o(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_x(Signal &__to_delete__, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_x(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_e(Signal &__to_delete__, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return _Format_e(sig, pFormatter, flags, Object_mpf::GetEntity(value));
}

bool Gura_ClassName(mpf)::Format_f(Signal &__to_delete__, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return _Format_f(sig, pFormatter, flags, Object_mpf::GetEntity(value));
}

bool Gura_ClassName(mpf)::Format_g(Signal &__to_delete__, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return _Format_g(sig, pFormatter, flags, Object_mpf::GetEntity(value));
}

Gura_EndModuleScope(gmp)
