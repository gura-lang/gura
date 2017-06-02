//=============================================================================
// Gura module: fftw
//=============================================================================
#include "stdafx.h"
#include "fftw3.h"

Gura_BeginModuleBody(fftw)

//-----------------------------------------------------------------------------
// Module functions
//-----------------------------------------------------------------------------
// fftw.test(num1:number, num2:number)
Gura_DeclareFunction(test)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "num1", VTYPE_number);
	DeclareArg(env, "num2", VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"This function adds two numbers and returns the result.\n");
}

Gura_ImplementFunction(test)
{
	int N = 256;
	fftw_complex *in = (fftw_complex*)::fftw_malloc(sizeof(fftw_complex) * N);
	fftw_complex *out = (fftw_complex*)::fftw_malloc(sizeof(fftw_complex) * N);
	fftw_plan p = ::fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

	::fftw_execute(p); /* repeat as needed */

	::fftw_destroy_plan(p);
	::fftw_free(in);
	::fftw_free(out);
	return Value::Nil;
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
	// function assignment
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(fftw, fftw)

Gura_RegisterModule(fftw)
