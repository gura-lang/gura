//=============================================================================
// Gura module: fftw
//=============================================================================
#include "stdafx.h"
#include "fftw3.h"

Gura_BeginModuleBody(fftw)

typedef Value (*MethodT)(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf);

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Value CallMethod(Environment &env, Argument &arg, const MethodT methods[],
				 const Function *pFunc, Array *pArraySelf)
{
	MethodT pMethod = methods[pArraySelf->GetElemType()];
	if (pMethod == nullptr) {
		env.SetError(ERR_TypeError, "no methods implemented");
		return Value::Nil;
	}
	return (*pMethod)(env, arg, pFunc, pArraySelf);
}

//-----------------------------------------------------------------------------
// Implementation of array methods
//-----------------------------------------------------------------------------
// array#dft() {block?}
Gura_DeclareMethod(array, dft)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

template<typename T_Elem>
Value Method_array_dft(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	Value valueRtn;
	return pFunc->ReturnValue(env, arg, valueRtn);
}

template<>
Value Method_array_dft<Double>(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<Double> *pArrayTSelf = dynamic_cast<ArrayT<Double> *>(pArraySelf);
	AutoPtr<ArrayT<Complex> > pArrayTRtn(new ArrayT<Complex>());
	const Array::Dimensions &dims = pArrayTSelf->GetDimensions();
	pArrayTRtn->SetDimensions(dims.begin(), dims.begin() + dims.size() - 1,
							  Array::Dimension(dims.back().GetSize() / 2 + 1));
	pArrayTRtn->AllocMemory();
	int rank = static_cast<int>(dims.size());
	std::unique_ptr<int []> n(new int [rank]);
	size_t i = 0;
	foreach_const (Array::Dimensions, pDim, dims) {
		n[i++] = static_cast<int>(pDim->GetSize());
	}
	double *in = pArrayTSelf->GetPointer();
	fftw_complex *out = reinterpret_cast<fftw_complex *>(pArrayTRtn->GetPointer());
	unsigned flags = FFTW_ESTIMATE;
	fftw_plan plan = ::fftw_plan_dft_r2c(rank, n.get(), in, out, flags);
	::fftw_execute(plan);
	::fftw_destroy_plan(plan);
	Value valueRtn(new Object_array(env, pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, valueRtn);
}

template<>
Value Method_array_dft<Complex>(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<Complex> *pArrayTSelf = dynamic_cast<ArrayT<Complex> *>(pArraySelf);
	AutoPtr<ArrayT<Complex> > pArrayTRtn(new ArrayT<Complex>());
	const Array::Dimensions &dims = pArrayTSelf->GetDimensions();
	pArrayTRtn->SetDimensions(dims.begin(), dims.begin() + dims.size() - 1,
							  Array::Dimension(dims.back().GetSize() / 2 + 1));
	pArrayTRtn->AllocMemory();
	int rank = static_cast<int>(dims.size());
	std::unique_ptr<int []> n(new int [rank]);
	size_t i = 0;
	foreach_const (Array::Dimensions, pDim, dims) {
		n[i++] = static_cast<int>(pDim->GetSize());
	}
	fftw_complex *in = reinterpret_cast<fftw_complex *>(pArrayTSelf->GetPointer());
	fftw_complex *out = reinterpret_cast<fftw_complex *>(pArrayTRtn->GetPointer());
	int sign = FFTW_FORWARD;
	unsigned flags = FFTW_ESTIMATE;
	fftw_plan plan = ::fftw_plan_dft(rank, n.get(), in, out, sign, flags);
	::fftw_execute(plan);
	::fftw_destroy_plan(plan);
	Value valueRtn(new Object_array(env, pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, dft)
{
	static const MethodT methods[] = {
		nullptr,
		&Method_array_dft<Int8>,
		&Method_array_dft<UInt8>,
		&Method_array_dft<Int16>,
		&Method_array_dft<UInt16>,
		&Method_array_dft<Int32>,
		&Method_array_dft<UInt32>,
		&Method_array_dft<Int64>,
		&Method_array_dft<UInt64>,
		&Method_array_dft<Half>,
		&Method_array_dft<Float>,
		&Method_array_dft<Double>,
		&Method_array_dft<Complex>,
		//&Method_array_dft<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

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
	int n0 = 256;
	fftw_complex *in = (fftw_complex*)::fftw_malloc(sizeof(fftw_complex) * n0);
	fftw_complex *out = (fftw_complex*)::fftw_malloc(sizeof(fftw_complex) * n0);
	int sign = FFTW_FORWARD;
	unsigned flags = FFTW_ESTIMATE;

	fftw_plan plan = ::fftw_plan_dft_1d(n0, in, out, sign, flags);

	::fftw_execute(plan); /* repeat as needed */

	::fftw_destroy_plan(plan);
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
	// method assignment to array
	Gura_AssignMethodTo(VTYPE_array, array, dft);
	// function assignment
	Gura_AssignFunction(test);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(fftw, fftw)

Gura_RegisterModule(fftw)
