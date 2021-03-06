//=============================================================================
// Gura module: gmp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(gmp)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// gmp.gcd(num1:gmp.mpz, num2:gmp.mpz):map
Gura_DeclareFunction(gcd)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num1", VTYPE_mpz);
	DeclareArg(env, "num2", VTYPE_mpz);
	AddHelp(
		Gura_Symbol(en),
		"Calculates the greatest common divisor, GCD, between `num1` and `num2`\n"
		"and returns the result as `gmp.mpz`.");
}

Gura_ImplementFunction(gcd)
{
	const mpz_class &num1 = Object_mpz::GetEntity(arg, 0);
	const mpz_class &num2 = Object_mpz::GetEntity(arg, 1);
	mpz_t num;
	::mpz_init(num);
	::mpz_gcd(num, num1.get_mpz_t(), num2.get_mpz_t());
	return Value(new Object_mpz(num));
}

// gmp.lcm(num1:gmp.mpz, num2:gmp.mpz):map
Gura_DeclareFunction(lcm)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num1", VTYPE_mpz);
	DeclareArg(env, "num2", VTYPE_mpz);
	AddHelp(
		Gura_Symbol(en),
		"Calculates the least common multiple, LCM, between `num1` and `num2`\n"
		"and returns the result as `gmp.mpz`.");
}

Gura_ImplementFunction(lcm)
{
	const mpz_class &num1 = Object_mpz::GetEntity(arg, 0);
	const mpz_class &num2 = Object_mpz::GetEntity(arg, 1);
	mpz_t num;
	::mpz_init(num);
	::mpz_lcm(num, num1.get_mpz_t(), num2.get_mpz_t());
	return Value(new Object_mpz(num));
}

// gmp.sqrt(num):map
Gura_DeclareFunction(sqrt)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"Calculates the square root of `num`.\n"
		"\n"
		"The type of the argument `num` must be `gmp.mpz`, `gmp.mpq`, `gmp.mpf` or `number`.\n");
}

Gura_ImplementFunction(sqrt)
{
	Signal &sig = env.GetSignal();
	if (arg.IsType(0, VTYPE_mpz)) {
		mpf_class num(Object_mpz::GetEntity(arg, 0));
		mpf_class result = ::sqrt(num);
		return Value(new Object_mpf(result.get_mpf_t()));
	} else if (arg.IsType(0, VTYPE_mpq)) {
		mpf_class num(Object_mpq::GetEntity(arg, 0));
		mpf_class result = ::sqrt(num);
		return Value(new Object_mpf(result.get_mpf_t()));
	} else if (arg.IsType(0, VTYPE_mpf)) {
		const mpf_class &num = Object_mpf::GetEntity(arg, 0);
		mpf_class result = ::sqrt(num);
		return Value(new Object_mpf(result.get_mpf_t()));
	} else if (arg.Is_number(0)) {
		mpf_class num(arg.GetDouble(0));
		mpf_class result = ::sqrt(num);
		return Value(new Object_mpf(result.get_mpf_t()));
	}
	SetError_ArgumentTypeByIndex(env, arg, 0);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Suffix handlers
//-----------------------------------------------------------------------------
Gura_ImplementSuffixMgrForNumber(L)
{
	Signal &sig = env.GetSignal();
	if (::strchr(body, '.') != nullptr || ::strchr(body, 'e') != nullptr || ::strchr(body, 'E') != nullptr) {
		mpf_t numf;
		::mpf_init(numf);
		if (::mpf_set_str(numf, body, 0) == 0) return Value(new Object_mpf(numf));
		::mpf_clear(numf);
	} else {
		mpz_t numz;
		::mpz_init(numz);
		if (::mpz_set_str(numz, body, 0) == 0) return Value(new Object_mpz(numz));
		::mpz_clear(numz);
	}
	sig.SetError(ERR_ValueError, "invalid string format for gmp number");
	return false;
}

Gura_ImplementSuffixMgrForNumber(Lr)
{
	Signal &sig = env.GetSignal();
	mpq_t numq;
	::mpq_init(numq);
	if (::mpq_set_str(numq, body, 0) == 0) return Value(new Object_mpq(numq));
	::mpq_clear(numq);
	sig.SetError(ERR_ValueError, "invalid string format for gmp number");
	return false;
}

//-----------------------------------------------------------------------------
// Module Entries
//-----------------------------------------------------------------------------
Gura_ModuleValidate()
{
	return Version::CheckCoreVersion(GURA_VERSION, nullptr);
}

Gura_ModuleEntry()
{
	// realization of classes
	Gura_RealizeAndPrepareUserClass(mpz, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(mpq, env.LookupClass(VTYPE_object));
	Gura_RealizeAndPrepareUserClass(mpf, env.LookupClass(VTYPE_object));
	// assignment of functions
	Gura_AssignFunction(gcd);
	Gura_AssignFunction(lcm);
	Gura_AssignFunction(sqrt);
	// assignment of operators
	AssignOperators(env);
	// assignment of suffix managers
	Gura_AssignSuffixMgrForNumber(L);
	Gura_AssignSuffixMgrForNumber(Lr);
	return true;
}

Gura_ModuleTerminate()
{
}

//-----------------------------------------------------------------------------
// utility functions
//-----------------------------------------------------------------------------
mpq_class MpqFromRational(const Rational &ratio)
{
	mpq_t num;
	::mpq_init(num);
	::mpz_set_si(mpq_numref(num), ratio.numer);
	::mpz_set_si(mpq_denref(num), ratio.denom);
	return mpq_class(num);
}

mpf_class MpfFromRational(Signal &sig, const Rational &ratio)
{
	if (ratio.denom == 0) {
		Operator::SetError_DivideByZero(sig);
		return mpf_class(0);
	}
	mpq_class numer(ratio.numer);
	mpq_class denom(ratio.denom);
	return numer / denom;
}

mpf_class MpfFromMpq(Signal &sig, const mpq_class &num)
{
	mpf_class numer = num.get_num();
	mpf_class denom = num.get_den();
	if (denom == 0) {
		Operator::SetError_DivideByZero(sig);
		return mpf_class(0);
	}
	return numer / denom;
}

bool _Format_d(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpz_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Zd").c_str(), num.get_mpz_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_u(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpz_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Zu").c_str(), num.get_mpz_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_b(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpz_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Zb").c_str(), num.get_mpz_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_o(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpz_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Zo").c_str(), num.get_mpz_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_x(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpz_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags,
				flags.upperCaseFlag? "ZX" : "Zx").c_str(), num.get_mpz_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_e(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpf_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags,
				flags.upperCaseFlag? "FE" : "Fe").c_str(), num.get_mpf_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_f(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpf_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Ff").c_str(), num.get_mpf_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_g(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpf_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags,
				flags.upperCaseFlag? "FG" : "Fg").c_str(), num.get_mpf_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_d(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpq_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Qd").c_str(), num.get_mpq_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_b(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpq_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Qb").c_str(), num.get_mpq_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_o(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpq_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Qo").c_str(), num.get_mpq_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_x(Signal &sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpq_class &num)
{
	char *str = nullptr;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags,
				flags.upperCaseFlag? "QX" : "Qx").c_str(), num.get_mpq_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

Gura_EndModuleBody(gmp, gmp)

Gura_RegisterModule(gmp)
