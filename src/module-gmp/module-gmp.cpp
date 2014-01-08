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
// Module entry
//-----------------------------------------------------------------------------
Gura_ModuleEntry()
{
	// class realization
	Gura_RealizeUserClass(mpz, env.LookupClass(VTYPE_object));
	Gura_RealizeUserClass(mpf, env.LookupClass(VTYPE_object));
	// function assignment
	Gura_AssignFunction(test);
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(gmp, gmp)

Gura_RegisterModule(gmp)
