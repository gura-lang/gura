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
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num1", VTYPE_mpz);
	DeclareArg(env, "num2", VTYPE_mpz);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementFunction(gcd)
{
	const mpz_class &num1 = Object_mpz::GetEntity(args, 0);
	const mpz_class &num2 = Object_mpz::GetEntity(args, 1);
	mpz_t num;
	::mpz_init(num);
	::mpz_gcd(num, num1.get_mpz_t(), num2.get_mpz_t());
	return Value(new Object_mpz(num));
}

// gmp.lcm(num1:gmp.mpz, num2:gmp.mpz):map
Gura_DeclareFunction(lcm)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num1", VTYPE_mpz);
	DeclareArg(env, "num2", VTYPE_mpz);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementFunction(lcm)
{
	const mpz_class &num1 = Object_mpz::GetEntity(args, 0);
	const mpz_class &num2 = Object_mpz::GetEntity(args, 1);
	mpz_t num;
	::mpz_init(num);
	::mpz_lcm(num, num1.get_mpz_t(), num2.get_mpz_t());
	return Value(new Object_mpz(num));
}

// gmp.sqrt(num):map
Gura_DeclareFunction(sqrt)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_any);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementFunction(sqrt)
{
	if (args.IsType(0, VTYPE_mpz)) {
		mpf_class num(Object_mpz::GetEntity(args, 0));
		mpf_class result = ::sqrt(num);
		return Value(new Object_mpf(result.get_mpf_t()));
	} else if (args.IsType(0, VTYPE_mpq)) {
		mpf_class num(Object_mpq::GetEntity(args, 0));
		mpf_class result = ::sqrt(num);
		return Value(new Object_mpf(result.get_mpf_t()));
	} else if (args.IsType(0, VTYPE_mpf)) {
		const mpf_class &num = Object_mpf::GetEntity(args, 0);
		mpf_class result = ::sqrt(num);
		return Value(new Object_mpf(result.get_mpf_t()));
	} else if (args.Is_number(0)) {
		mpf_class num(args.GetDouble(0));
		mpf_class result = ::sqrt(num);
		return Value(new Object_mpf(result.get_mpf_t()));
	}
	SetError_ArgumentTypeByIndex(sig, args, 0);
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Suffix handlers
//-----------------------------------------------------------------------------
Gura_ImplementSuffixMgrForNumber(L)
{
	if (::strchr(body, '.') != NULL || ::strchr(body, 'e') != NULL || ::strchr(body, 'E') != NULL) {
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
	mpq_t numq;
	::mpq_init(numq);
	if (::mpq_set_str(numq, body, 0) == 0) return Value(new Object_mpq(numq));
	::mpq_clear(numq);
	sig.SetError(ERR_ValueError, "invalid string format for gmp number");
	return false;
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// realization of classes
	Gura_RealizeUserClass(mpz, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(mpq, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(mpf, env.LookupClass(VTYPE_object));
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

mpf_class MpfFromRational(Signal sig, const Rational &ratio)
{
	if (ratio.denom == 0) {
		Operator::SetError_DivideByZero(sig);
		return mpf_class(0);
	}
	mpq_class numer(ratio.numer);
	mpq_class denom(ratio.denom);
	return numer / denom;
}

bool _Format_d(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpz_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Zd").c_str(), num.get_mpz_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_u(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpz_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Zu").c_str(), num.get_mpz_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_b(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpz_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Zb").c_str(), num.get_mpz_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_o(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpz_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Zo").c_str(), num.get_mpz_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_x(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpz_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags,
				flags.upperCaseFlag? "ZX" : "Zx").c_str(), num.get_mpz_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_e(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpf_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags,
				flags.upperCaseFlag? "FE" : "Fe").c_str(), num.get_mpf_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_f(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpf_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Ff").c_str(), num.get_mpf_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_g(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpf_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags,
				flags.upperCaseFlag? "FG" : "Fg").c_str(), num.get_mpf_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_d(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpq_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Qd").c_str(), num.get_mpq_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_b(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpq_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Qb").c_str(), num.get_mpq_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_o(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpq_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags, "Qo").c_str(), num.get_mpq_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

bool _Format_x(Signal sig, Formatter *pFormatter,
					const Formatter::Flags &flags, const mpq_class &num)
{
	char *str = NULL;
	::gmp_asprintf(&str, Formatter::ComposeFlags(flags,
				flags.upperCaseFlag? "QX" : "Qx").c_str(), num.get_mpq_t());
	bool rtn = pFormatter->PutString(sig, str);
	::free(str);
	return rtn;
}

Gura_EndModuleBody(gmp, gmp)

Gura_RegisterModule(gmp)
