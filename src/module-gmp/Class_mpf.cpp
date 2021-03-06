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
// Implementation of properties
//-----------------------------------------------------------------------------
// gmp.mpf#prec
Gura_DeclareProperty_RW(mpf, prec)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(mpf, prec)
{
	const mpf_class &num = Object_mpf::GetObject(valueThis)->GetEntity();
	return Value(num.get_prec());
}

Gura_ImplementPropertySetter(mpf, prec)
{
	mpf_class &num = Object_mpf::GetObject(valueThis)->GetEntity();
	ULong prec = value.GetULong();
	num.set_prec(prec);
	return Value(prec);
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
		Gura_Symbol(en),
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
	Signal &sig = env.GetSignal();
	Value value;
	ULong prec = arg.Is_number(1)? arg.GetInt(1) : ::mpf_get_default_prec();
	if (arg.IsInvalid(0)) {
		value = Value(new Object_mpf(mpf_class(0, prec)));
	} else if (arg.Is_number(0)) {
		value = Value(new Object_mpf(mpf_class(arg.GetDouble(0), prec)));
	} else if (arg.Is_string(0)) {
		mpf_class num;
		num.set_prec(prec);
		if (num.set_str(arg.GetString(0), 0) < 0) {
			sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
			return Value::Nil;
		}
		value = Value(new Object_mpf(num));
	} else if (arg.IsType(0, VTYPE_mpf)) {
		value = arg.GetValue(0); // no change
	} else if (arg.IsType(0, VTYPE_mpz)) {
		mpf_class num(Object_mpz::GetEntity(arg, 0), prec);
		value = Value(new Object_mpf(num));
	} else if (arg.IsType(0, VTYPE_mpq)) {
		mpq_class num(Object_mpq::GetEntity(arg, 0));
		mpf_class numResult = MpfFromMpq(sig, num);
		if (sig.IsSignalled()) return Value::Nil;
		value = Value(new Object_mpf(numResult));
	} else {
		SetError_ArgumentTypeByIndex(env, arg, 0);
		return Value::Nil;
	}
	return ReturnValue(env, arg, value);
}

//-----------------------------------------------------------------------------
// Implementation of class methods
//-----------------------------------------------------------------------------
// gmp.mpf.get_defaul_prec()
Gura_DeclareClassMethod(mpf, get_default_prec)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
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
		Gura_Symbol(en),
		"Sets the default precision for `gmp.mpf`.\n");
}

Gura_ImplementClassMethod(mpf, set_default_prec)
{
	ULong prec = arg.GetULong(0);
	::mpf_set_default_prec(prec);
	return Value::Nil;
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
	const mpf_class &num = Object_mpf::GetThisEntity(arg);
	mpz_class numCasted(num);
	return ReturnValue(env, arg, Value(new Object_mpz(numCasted)));
}

// string#cast@mpf(prec?:number) {block?}
Gura_DeclareMethodAlias(string, cast_mpf, "cast@mpf")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "prec", VTYPE_number, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Casts the string to `gmp.mpf`.\n"
		"\n"
		"You can specify the precision of the number by the argument `prec`.\n"
		"If it's omitted, a default precision would be applied.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("num", "gmp.mpf"));
}

Gura_ImplementMethod(string, cast_mpf)
{
	Signal &sig = env.GetSignal();
	const char *strThis = arg.GetValueThis().GetString();
	int base = 0;
	ULong prec = arg.Is_number(0)? arg.GetInt(0) : ::mpf_get_default_prec();
	mpf_class num;
	num.set_prec(prec);
	if (num.set_str(strThis, base) < 0) {
		sig.SetError(ERR_ValueError, "invalid string format for gmp.mpf");
		return Value::Nil;
	}
	return ReturnValue(env, arg, Value(new Object_mpf(num)));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClassWithCast(mpf)
{
	// Assignment of properties
	Gura_AssignProperty(mpf, prec);
	// Assignment of function
	Gura_AssignFunction(mpf);
	// Assignment of class methods
	Gura_AssignMethod(mpf, get_default_prec);
	Gura_AssignMethod(mpf, set_default_prec);
	// Assignment of instance methods
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

bool Gura_ClassName(mpf)::Format_d(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_d(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_u(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_u(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_b(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	//mpz_class num(Object_mpf::GetEntity(value));
	//return _Format_b(sig, pFormatter, flags, num);
	return Class::Format_b(pFormatter, flags, value);
}

bool Gura_ClassName(mpf)::Format_o(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_o(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_x(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	mpz_class num(Object_mpf::GetEntity(value));
	return _Format_x(sig, pFormatter, flags, num);
}

bool Gura_ClassName(mpf)::Format_e(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return _Format_e(sig, pFormatter, flags, Object_mpf::GetEntity(value));
}

bool Gura_ClassName(mpf)::Format_f(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return _Format_f(sig, pFormatter, flags, Object_mpf::GetEntity(value));
}

bool Gura_ClassName(mpf)::Format_g(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	return _Format_g(sig, pFormatter, flags, Object_mpf::GetEntity(value));
}

Gura_EndModuleScope(gmp)
