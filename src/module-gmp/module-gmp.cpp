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
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
	AddHelp(Gura_Symbol(en), Help::FMT_markdown,
	"This function adds two numbers and returns the result."
	);
}

Gura_ImplementFunction(test)
{
	mpz_t a, b;
	::mpz_init_set_str(a, "13342", 10);
	::mpz_init_set_str(b, "123445", 10);
	::mpz_add(a, a, b);
	::printf("%s\n", ::mpz_get_str(NULL, 10, a));
	return Value(args.GetNumber(0) + args.GetNumber(1));
}

//-----------------------------------------------------------------------------
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// function assignment
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(gmp, gmp)

Gura_RegisterModule(gmp)
