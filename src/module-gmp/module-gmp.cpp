//=============================================================================
// Gura module: gmp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(gmp)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// gmp.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetMode(RSLTMODE_Normal, FLAG_None);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	""
	);
}

Gura_ImplementFunction(test)
{
	mpz_class a, b, c;
	a = 1234;
	b = "-5678";
	c = a + b;
	::printf("%s\n", c.get_str().c_str());
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Suffix handlers
//-----------------------------------------------------------------------------
class SuffixHandler_Number_L : public SuffixHandler {
public:
	virtual Value DoEval(Environment &env, Signal sig, const char *body) const;
};

Value SuffixHandler_Number_L::DoEval(Environment &env, Signal sig, const char *body) const
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

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeUserClass(mpz, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(mpq, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(mpf, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(test);
	// suffix handler registration
	SuffixHandler::RegisterForNumber(env, Symbol::Add("L"), new SuffixHandler_Number_L());
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(gmp, gmp)

Gura_RegisterModule(gmp)
