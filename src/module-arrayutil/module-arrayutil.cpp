//=============================================================================
// Gura module: arrayutil
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleBody(arrayutil)

typedef Value (*MethodT)(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf);

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
template<typename T_ElemResult, typename T_Elem>
ArrayT<T_ElemResult> *CalcSum(const ArrayT<T_Elem> *pArrayT,
							  Array::Dimensions::const_iterator pDimAxis)
{
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(
		ArrayT<T_ElemResult>::Create(dims.begin(), pDimAxis, pDimAxis + 1, dims.end()));
	pArrayTResult->FillZero();
	const T_Elem *pElem = pArrayT->GetPointer();
	T_ElemResult *pElemResult = pArrayTResult->GetPointer();
	if (pDimAxis + 1 == dims.end()) {
		size_t cnt = pArrayT->GetElemNum() / pDimAxis->GetSize();
		while (cnt-- > 0) {
			for (size_t i = 0; i < pDimAxis->GetSize(); i++, pElem++) {
				*pElemResult += *pElem;
			}
			pElemResult++;
		}
	} else {
		size_t stride = pDimAxis->GetStride();
		size_t cnt = pArrayT->GetElemNum() / (pDimAxis->GetSize() * stride);
		while (cnt-- > 0) {
			for (size_t i = 0; i < pDimAxis->GetSize(); i++) {
				for (size_t j = 0; j < stride; j++, pElem++) {
					*(pElemResult + j) += *pElem;
				}
			}
			pElemResult += stride;
		}
	}
	return pArrayTResult.release();
}

template<typename T_ElemResult, typename T_Elem>
T_ElemResult CalcSumFlat(const ArrayT<T_Elem> *pArrayT)
{
	T_ElemResult rtn = 0;
	const T_Elem *p = pArrayT->GetPointer();
	for (size_t i = 0; i < pArrayT->GetElemNum(); i++, p++) {
		rtn += *p;
	}
	return rtn;
}

template<typename T_ElemResult, typename T_Elem>
ArrayT<T_ElemResult> *CalcMean(const ArrayT<T_Elem> *pArrayT,
								  Array::Dimensions::const_iterator pDimAxis)
{
	ArrayT<T_ElemResult> *pArrayTResult = CalcSum<T_ElemResult, T_Elem>(pArrayT, pDimAxis);
	size_t n = pDimAxis->GetSize();
	if (n != 0) {
		T_ElemResult *p = pArrayTResult->GetPointer();
		for (size_t i = 0; i < pArrayTResult->GetElemNum(); i++, p++) {
			*p /= n;
		}
	}
	return pArrayTResult;
}

template<typename T_ElemResult, typename T_Elem>
T_ElemResult CalcMeanFlat(const ArrayT<T_Elem> *pArrayT)
{
	if (pArrayT->GetElemNum() == 0) return 0;
	return static_cast<T_ElemResult>(CalcSumFlat<T_ElemResult, T_Elem>(pArrayT) / pArrayT->GetElemNum());
}

template<>
Complex CalcMeanFlat(const ArrayT<Complex> *pArrayT)
{
	if (pArrayT->GetElemNum() == 0) return 0;
	return CalcSumFlat<Complex, Complex>(pArrayT) / static_cast<double>(pArrayT->GetElemNum());
}

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
// Implementation of array creators
//-----------------------------------------------------------------------------
// array.identity(n:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod(array, identity)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that represents a identity matrix with specified size `n`.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array@double.identity(3)\n"
		"        // array@double {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}\n"
		);
}

Gura_ImplementClassMethod(array, identity)
{
	Array::ElemType elemType = arg.IsValid(1)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(1)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	AutoPtr<Array> pArray(ArrayT<Double>::CreateIdentity(arg.GetSizeT(0)));
	Value value(new Object_array(env, pArray.release()));
	return ReturnValue(env, arg, value);
}

// array.interval(begin:number, end:number, samples:number, elemtype?:symbol):static:map:[open,open_l,open_r] {block?}
Gura_DeclareClassMethod(array, interval)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "begin", VTYPE_number);
	DeclareArg(env, "end", VTYPE_number);
	DeclareArg(env, "samples", VTYPE_number);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(open));
	DeclareAttr(Gura_Symbol(open_l));
	DeclareAttr(Gura_Symbol(open_r));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a one-dimentional array that contains a sequence of numbers\n"
		"by specifying the beginning and ending numbers, and the number of samples between them.\n"
		"\n"
		"In default, it creates a sequence that contains the beginning and ending numbers.\n"
		"Following attributes would generate the following numbers:\n"
		"\n"
		"- `:open` .. Numbers in range of `(begin, end)` that doesn't contain either `begin` or `end`.\n"
		"- `:open_l` .. Numbers in range of `(begin, end]` that doesn't contain `begin`.\n"
		"- `:open_r` .. Numbers in range of `[begin, end)` that doesn't contain `end`.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array@double.interval(0, 3, 7)\n"
		"        // array@double {0, 0.5, 1, 1.5, 2, 2.5, 3}\n"
		);
}

Gura_ImplementClassMethod(array, interval)
{
	Array::ElemType elemType = arg.IsValid(3)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	Number numBegin = arg.GetNumber(0);
	Number numEnd = arg.GetNumber(1);
	int numSamples = arg.GetInt(2);
	if (numSamples <= 1) {
		env.SetError(ERR_ValueError, "samples must be more than one");
		return Value::Nil;
	}
	bool openFlag = arg.IsSet(Gura_Symbol(open));
	bool openLeftFlag = arg.IsSet(Gura_Symbol(open_l));
	bool openRightFlag = arg.IsSet(Gura_Symbol(open_r));
	int iFactor = 0;
	Number numDenom = numSamples - 1;
	if (openFlag || (openLeftFlag && openRightFlag)) {
		numDenom = numSamples + 1;
		iFactor = 1;
	} else if (openLeftFlag) {
		numDenom = numSamples;
		iFactor = 1;
	} else if (openRightFlag) {
		numDenom = numSamples;
		iFactor = 0;
	}
	AutoPtr<Array> pArray(ArrayT<Double>::CreateInterval(
										 numBegin, numEnd, numSamples, numDenom, iFactor));
	Value value(new Object_array(env, pArray.release()));
	return ReturnValue(env, arg, value);
}

// array.ones(dims[]:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod(array, ones)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array with the specified dimensions, which elements are initialized by one.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array@double.ones([3, 4])\n"
		"        // array@double {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}\n"
		);
}

Gura_ImplementClassMethod(array, ones)
{
	Array::ElemType elemType = arg.IsValid(1)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(1)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	Value value(new Object_array(env, ArrayT<Double>::CreateOnes(arg.GetList(0))));
	return ReturnValue(env, arg, value);
}

// array.rands(dims[]:number, range?:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod(array, rands)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "range", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array with the specified dimensions, which contains random numbers.\n"
		);
}

Gura_ImplementClassMethod(array, rands)
{
	Array::ElemType elemType = arg.IsValid(2)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(2)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	UInt range = arg.IsValid(1)? arg.GetUInt(1) : 0;
	Value value(new Object_array(env, ArrayT<Double>::CreateRands(arg.GetList(0), range)));
	return ReturnValue(env, arg, value);
}

// array.rands@normal(dims[]:number, mu?:number, sigma?:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethodAlias(array, rands_at_normal, "rands@normal")
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "mu", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "sigma", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array with the specified dimensions,\n"
		"which contains normal distribution random numbers.\n"
		);
}

Gura_ImplementClassMethod(array, rands_at_normal)
{
	Array::ElemType elemType = arg.IsValid(3)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	double mu = arg.IsValid(1)? arg.GetDouble(1) : 0;
	double sigma = arg.IsValid(2)? arg.GetDouble(2) : 1;
	Value value(new Object_array(env, ArrayT<Double>::CreateRandsNormal(
									 arg.GetList(0), mu, sigma)));
	return ReturnValue(env, arg, value);
}

// array.range(num:number, num_end?:number, step?:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod(array, range)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_number);
	DeclareArg(env, "num_end", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "step", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that contains a sequence of integer numbers.\n"
		"\n"
		"This function can be called in three formats that generate following numbers:\n"
		"\n"
		"- `array.range(num)` .. Numbers between `0` and `(num - 1)`.\n"
		"- `array.range(num, num_end)` .. Numbers between `num` and `(num_end - 1)`.\n"
		"- `array.range(num, num_end, step)` .. Numbers between `num` and `(num_end - 1)` incremented by `step`.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array@double.range(5)\n"
        "        // array@double {0, 1, 2, 3, 4}\n"
		"    x = array@double.range(2, 5)\n"
		"        // array@double {2, 3, 4}\n"
		"    x = array@double.range(2, 10, 2)\n"
		"        // array@double {2, 4, 6, 8}\n"
		);
}

Gura_ImplementClassMethod(array, range)
{
	Array::ElemType elemType = arg.IsValid(3)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	Double numBegin = 0.;
	Double numEnd = 0.;
	Double numStep = 1.;
	if (arg.IsValid(1)) {
		numBegin = arg.GetDouble(0);
		numEnd = arg.GetDouble(1);
		if (arg.IsValid(2)) {
			numStep = arg.GetDouble(2);
			if (numStep == 0) {
				env.SetError(ERR_ValueError, "step must not be zero");
				return Value::Nil;
			} else if (numBegin < numEnd && numStep < 0) {
				env.SetError(ERR_ValueError, "step must be positive");
				return Value::Nil;
			} else if (numBegin > numEnd && numStep > 0) {
				env.SetError(ERR_ValueError, "step must be negative");
				return Value::Nil;
			}
		} else if (numBegin > numEnd) {
			numStep = -1.;
		}
	} else {
		numEnd = arg.GetDouble(0);
	}
	AutoPtr<ArrayT<Double> > pArrayT(ArrayT<Double>::CreateRange(numBegin, numEnd, numStep));
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayT.release())));
}

// array.rotation(angle:number, xtrans?:number, ytrans?:number, elemtype?:symbol):static:map:[deg] {block?}
Gura_DeclareClassMethod(array, rotation)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that rotates 2-D coords by the specified `angle`.\n"
		"\n"
		"The `angle` is specified in radian value.\n"
		"If the attribute `:deg` is specified, the `angle` is specified in degree value.\n"
		"\n"
		"If one or more of `xtrans` or `ytrans` is specified,\n"
		"it would create an array that works as translation as well as rotation.\n"
		);
}

Gura_ImplementClassMethod(array, rotation)
{
	Array::ElemType elemType = arg.IsValid(3)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Array> pArray;
	if (arg.IsValid(1) || arg.IsValid(2)) {
		Double xTrans = arg.IsValid(1)? static_cast<Double>(arg.GetDouble(1)) : 0;
		Double yTrans = arg.IsValid(2)? static_cast<Double>(arg.GetDouble(2)) : 0;
		pArray.reset(ArrayT<Double>::CreateRotation(angle, true, xTrans, yTrans));
	} else {
		pArray.reset(ArrayT<Double>::CreateRotation(angle, false, 0, 0));
	}
	Value value(new Object_array(env, pArray.release()));
	return ReturnValue(env, arg, value);
}

// array.rotation@x(angle:number, xtrans?:number, ytrans?:number, ztrans?:number, elemtype?:symbol):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias(array, rotation_at_x, "rotation@x")
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that rotates 3-D coords around x-axis by the specified `angle`.\n"
		"\n"
		"The `angle` is specified in radian value.\n"
		"If the attribute `:deg` is specified, the `angle` is specified in degree value.\n"
		"\n"
		"If one or more of `xtrans`, `ytrans` or `ztrans` is specified,\n"
		"it would create an array that works as translation as well as rotation.\n"
		);
}

Gura_ImplementClassMethod(array, rotation_at_x)
{
	Array::ElemType elemType = arg.IsValid(4)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(4)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Array> pArray;
	if (arg.IsValid(1) || arg.IsValid(2) || arg.IsValid(3)) {
		Double xTrans = arg.IsValid(1)? static_cast<Double>(arg.GetDouble(1)) : 0;
		Double yTrans = arg.IsValid(2)? static_cast<Double>(arg.GetDouble(2)) : 0;
		Double zTrans = arg.IsValid(3)? static_cast<Double>(arg.GetDouble(3)) : 0;
		pArray.reset(ArrayT<Double>::CreateRotationX(angle, true, xTrans, yTrans, zTrans));
	} else {
		pArray.reset(ArrayT<Double>::CreateRotationX(angle, false, 0, 0, 0));
	}
	Value value(new Object_array(env, pArray.release()));
	return ReturnValue(env, arg, value);
}

// array.rotation@y(angle:number, xtrans?:number, ytrans?:number, ztrans?:number, elemtype?:symbol):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias(array, rotation_at_y, "rotation@y")
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that rotates 3-D coords around y-axis by the specified `angle`.\n"
		"\n"
		"The `angle` is specified in radian value.\n"
		"If the attribute `:deg` is specified, the `angle` is specified in degree value.\n"
		"\n"
		"If one or more of `xtrans`, `ytrans` or `ztrans` is specified,\n"
		"it would create an array that works as translation as well as rotation.\n"
		);
}

Gura_ImplementClassMethod(array, rotation_at_y)
{
	Array::ElemType elemType = arg.IsValid(4)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(4)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Array> pArray;
	if (arg.IsValid(1) || arg.IsValid(2) || arg.IsValid(3)) {
		Double xTrans = arg.IsValid(1)? static_cast<Double>(arg.GetDouble(1)) : 0;
		Double yTrans = arg.IsValid(2)? static_cast<Double>(arg.GetDouble(2)) : 0;
		Double zTrans = arg.IsValid(3)? static_cast<Double>(arg.GetDouble(3)) : 0;
		pArray.reset(ArrayT<Double>::CreateRotationY(angle, true, xTrans, yTrans, zTrans));
	} else {
		pArray.reset(ArrayT<Double>::CreateRotationY(angle, false, 0, 0, 0));
	}
	Value value(new Object_array(env, pArray.release()));
	return ReturnValue(env, arg, value);
}

// array.rotation@z(angle:number, xtrans?:number, ytrans?:number, ztrans?:number, elemtype?:symbol):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias(array, rotation_at_z, "rotation@z")
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that rotates 3-D coords around z-axis by the specified `angle`.\n"
		"\n"
		"The `angle` is specified in radian value.\n"
		"If the attribute `:deg` is specified, the `angle` is specified in degree value.\n"
		"\n"
		"If one or more of `xtrans`, `ytrans` or `ztrans` is specified,\n"
		"it would create an array that works as translation as well as rotation.\n"
		);
}

Gura_ImplementClassMethod(array, rotation_at_z)
{
	Array::ElemType elemType = arg.IsValid(4)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(4)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Array> pArray;
	if (arg.IsValid(1) || arg.IsValid(2) || arg.IsValid(3)) {
		Double xTrans = arg.IsValid(1)? static_cast<Double>(arg.GetDouble(1)) : 0;
		Double yTrans = arg.IsValid(2)? static_cast<Double>(arg.GetDouble(2)) : 0;
		Double zTrans = arg.IsValid(3)? static_cast<Double>(arg.GetDouble(3)) : 0;
		pArray.reset(ArrayT<Double>::CreateRotationZ(angle, true, xTrans, yTrans, zTrans));
	} else {
		pArray.reset(ArrayT<Double>::CreateRotationZ(angle, false, 0, 0, 0));
	}
	Value value(new Object_array(env, pArray.release()));
	return ReturnValue(env, arg, value);
}

// array.scaling(xscale:number, yscale:number, zscale?:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod(array, scaling)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "xscale", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "yscale", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "zscale", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that scales coords.\n"
		"If the argument `zscale` is specified, it would create an array that works with 3-D coords.\n"
		"Otherwise, it would create what works with 2-D coord.n"
		);
}

Gura_ImplementClassMethod(array, scaling)
{
	Array::ElemType elemType = arg.IsValid(3)?
		Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	Double xScale = static_cast<Double>(arg.GetDouble(0));
	Double yScale = static_cast<Double>(arg.GetDouble(1));
	AutoPtr<Array> pArray;
	if (arg.IsValid(2)) {
		Double zScale = static_cast<Double>(arg.GetDouble(2));
		pArray.reset(ArrayT<Double>::CreateScaling3D(xScale, yScale, zScale));
	} else {
		pArray.reset(ArrayT<Double>::CreateScaling2D(xScale, yScale));
	}
	Value value(new Object_array(env, pArray.release()));
	return ReturnValue(env, arg, value);
}

// array.translation(xtrans:number, ytrans:number, ztrans?:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod(array, translation)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that translates coords.\n"
		"If the argument `ztrans` is specified, it would create an array that works with 3-D coords.\n"
		"Otherwise, it would create what works with 2-D coords.n"
		);
}

Gura_ImplementClassMethod(array, translation)
{
	Double xTrans = static_cast<Double>(arg.GetDouble(0));
	Double yTrans = static_cast<Double>(arg.GetDouble(1));
	AutoPtr<Array> pArray;
	if (arg.IsValid(2)) {
		Double zTrans = static_cast<Double>(arg.GetDouble(2));
		pArray.reset(ArrayT<Double>::CreateTranslation3D(xTrans, yTrans, zTrans));
	} else {
		pArray.reset(ArrayT<Double>::CreateTranslation2D(xTrans, yTrans));
	}
	Value value(new Object_array(env, pArray.release()));
	return ReturnValue(env, arg, value);
}

// array.zeros(dims[]:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod(array, zeros)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array with the specified dimensions, which elements are initialized by zero.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array@double.zeros([3, 4])\n"
		"        // array@double {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}\n"
		);
}

Gura_ImplementClassMethod(array, zeros)
{
	Value value(new Object_array(env, ArrayT<Double>::CreateZeros(arg.GetList(0))));
	return ReturnValue(env, arg, value);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// array.dot(a:array, b:array):static:map {block?}
Gura_DeclareClassMethod(array, dot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_array);
	DeclareArg(env, "b", VTYPE_array);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a dot product between two arrays that have one or two dimensions.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementClassMethod(array, dot)
{
	const Array *pArrayL = Object_array::GetObject(arg, 0)->GetArray();
	const Array *pArrayR = Object_array::GetObject(arg, 1)->GetArray();
	Value valResult = CalcDot(env, pArrayL, pArrayR);
	if (env.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, valResult);
}

// array#dump():void
Gura_DeclareMethod(array, dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(upper));
	AddHelp(
		Gura_Symbol(en),
		"Prints out a binary dump of the array's content.\n"
		);
}

template<typename T_Elem>
Value Method_dump(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	bool upperFlag = arg.IsSet(Gura_Symbol(upper));
	Stream *pStream = arg.IsValid(0)?
		&Object_stream::GetObject(arg, 0)->GetStream() : env.GetConsole();
	pArrayT->Dump(sig, *pStream, upperFlag);
	return Value::Nil;
}

Gura_ImplementMethod(array, dump)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_dump<Boolean>,
		&Method_dump<Int8>,
		&Method_dump<UInt8>,
		&Method_dump<Int16>,
		&Method_dump<UInt16>,
		&Method_dump<Int32>,
		&Method_dump<UInt32>,
		&Method_dump<Int64>,
		&Method_dump<UInt64>,
		&Method_dump<Half>,
		&Method_dump<Float>,
		&Method_dump<Double>,
		&Method_dump<Complex>,
		//&Method_dump<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#each():[flat] {block?}
Gura_DeclareMethod(array, each)
{
	SetFuncAttr(VTYPE_iterator, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(flat));
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that iterates each element in the array.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en()
		"\n"
		"The block parameter is `|elem:number, idx:number|`\n"
		"where `elem` is the element value.\n"
		);
}

template<typename T_Elem>
Value Method_each(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	AutoPtr<Iterator> pIterator(new Iterator_ArrayT_Each<T_Elem>(
									pArrayT->Reference(), arg.IsSet(Gura_Symbol(flat))));
	return pFunc->ReturnIterator(env, arg, pIterator.release());
}

Gura_ImplementMethod(array, each)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_each<Boolean>,
		&Method_each<Int8>,
		&Method_each<UInt8>,
		&Method_each<Int16>,
		&Method_each<UInt16>,
		&Method_each<Int32>,
		&Method_each<UInt32>,
		&Method_each<Int64>,
		&Method_each<UInt64>,
		&Method_each<Half>,
		&Method_each<Float>,
		&Method_each<Double>,
		&Method_each<Complex>,
		//&Method_each<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#elemcast(elemtype:symbol) {block?}
Gura_DeclareMethod(array, elemcast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "elemtype", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Cast value type of contained elements.\n"
		"\n"
		"Available symbols for `elemtype` are as follows:\n"
		"\n"
		"- `` `boolean``\n"
		"- `` `int8``\n"
		"- `` `uint8``\n"
		"- `` `int16``\n"
		"- `` `uint16``\n"
		"- `` `int32``\n"
		"- `` `uint32``\n"
		"- `` `int64``\n"
		"- `` `uint64``\n"
		"- `` `half``\n"
		"- `` `float``\n"
		"- `` `double``\n"
		"- `` `complex``\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, elemcast)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	Array::ElemType elemType = Array::SymbolToElemTypeWithError(env, arg.GetSymbol(0));
	if (env.IsSignalled()) return Value::Nil;
	Value value;
	if (pArraySelf->GetElemType() == elemType) {
		value = Value(new Object_array(env, pArraySelf->Clone()));
	} else {
		AutoPtr<Array> pArrayDst(Array::Create(elemType, pArraySelf->GetDimensions()));
		if (!Array::CopyElements(env, pArrayDst.get(), pArraySelf)) return Value::Nil;
		value = Value(new Object_array(env, pArrayDst.release()));
	}
	return ReturnValue(env, arg, value);
}

// array#fill(value:number):void
Gura_DeclareMethod(array, fill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Fills array with a specified value.\n"
		);
}

template<typename T_Elem>
Value Method_fill(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	if (!pArrayT->PrepareModification(env.GetSignal())) return Value::Nil;
	pArrayT->Fill(static_cast<T_Elem>(arg.GetNumber(0)));
	return Value::Nil;
}

Gura_ImplementMethod(array, fill)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_fill<Boolean>,
		&Method_fill<Int8>,
		&Method_fill<UInt8>,
		&Method_fill<Int16>,
		&Method_fill<UInt16>,
		&Method_fill<Int32>,
		&Method_fill<UInt32>,
		&Method_fill<Int64>,
		&Method_fill<UInt64>,
		&Method_fill<Half>,
		&Method_fill<Float>,
		&Method_fill<Double>,
		&Method_fill<Complex>,
		//&Method_fill<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#flatten() {block?}
Gura_DeclareMethod(array, flatten)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has flattened elements in the target `array`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

template<typename T_Elem>
Value Method_flatten(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	AutoPtr<Array> pArrayTRtn(pArrayT->Flatten());
	return pFunc->ReturnValue(env, arg, Value(new Object_array(env, pArrayTRtn.release())));
}

Gura_ImplementMethod(array, flatten)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_flatten<Boolean>,
		&Method_flatten<Int8>,
		&Method_flatten<UInt8>,
		&Method_flatten<Int16>,
		&Method_flatten<UInt16>,
		&Method_flatten<Int32>,
		&Method_flatten<UInt32>,
		&Method_flatten<Int64>,
		&Method_flatten<UInt64>,
		&Method_flatten<Half>,
		&Method_flatten<Float>,
		&Method_flatten<Double>,
		&Method_flatten<Complex>,
		//&Method_flatten<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#head(n:number):map {block?}
Gura_DeclareMethod(array, head)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has extracted `n` elements from the beginning of the target `array`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

template<typename T_Elem>
Value Method_head(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t n = arg.GetSizeT(0);
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(pArrayT->Head(sig, n));
	if (pArrayTRtn.IsNull()) return Value::Nil;
	Value value(new Object_array(env, pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_ImplementMethod(array, head)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_head<Boolean>,
		&Method_head<Int8>,
		&Method_head<UInt8>,
		&Method_head<Int16>,
		&Method_head<UInt16>,
		&Method_head<Int32>,
		&Method_head<UInt32>,
		&Method_head<Int64>,
		&Method_head<UInt64>,
		&Method_head<Half>,
		&Method_head<Float>,
		&Method_head<Double>,
		&Method_head<Complex>,
		//&Method_head<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#invert(eps?:number) {block?}
Gura_DeclareMethod(array, invert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "eps", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has elements of inverted matrix of the target `array`."
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

template<typename T_Elem>
Value Method_invert(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	Double epsilon = arg.IsValid(0)? arg.GetDouble(0) : 1.0e-6;
	AutoPtr<Array> pArrayRtn(Array::Invert(sig, pArrayT, epsilon));
	if (pArrayRtn.IsNull()) return Value::Nil;
	Value value(new Object_array(env, pArrayRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_ImplementMethod(array, invert)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_invert<Boolean>,
		&Method_invert<Int8>,
		&Method_invert<UInt8>,
		&Method_invert<Int16>,
		&Method_invert<UInt16>,
		&Method_invert<Int32>,
		&Method_invert<UInt32>,
		&Method_invert<Int64>,
		&Method_invert<UInt64>,
		&Method_invert<Half>,
		&Method_invert<Float>,
		&Method_invert<Double>,
		&Method_invert<Complex>,
		//&Method_invert<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#iselemsame(array:array)
Gura_DeclareMethod(array, iselemsame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "array", VTYPE_array);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target `array` instance has the same elements\n"
		"with the specified `array`.\n");
}

Gura_ImplementMethod(array, iselemsame)
{
	Array *pArray = Object_array::GetObjectThis(arg)->GetArray();
	Array *pArrayCmp = Object_array::GetObject(arg, 0)->GetArray();
	return Value(pArray->HasSameElements(*pArrayCmp));
}

// array#issquare()
Gura_DeclareMethod(array, issquare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target `array` consists square matrices.");
}

Gura_ImplementMethod(array, issquare)
{
	Array *pArray = Object_array::GetObjectThis(arg)->GetArray();
	return Value(pArray->IsSquare());
}

// array#mean(axis?:number) {block?}
Gura_DeclareMethod(array, mean)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates an mean value of elements in the array.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

template<typename T_ElemResult, typename T_Elem>
Value Method_mean(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Value valueRtn;
	if (arg.IsValid(0)) {
		size_t axis = arg.GetSizeT(0);
		const Array::Dimensions &dims = pArrayT->GetDimensions();
		if (axis >= dims.size()) {
			env.SetError(ERR_OutOfRangeError, "specified axis is out of range");
			return Value::Nil;
		} else if (axis == 0 && dims.size() == 1) {
			valueRtn = Value(CalcMeanFlat<T_ElemResult, T_Elem>(pArrayT));
		} else {
			Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
			ArrayT<T_ElemResult> *pArrayTResult = CalcMean<T_ElemResult, T_Elem>(pArrayT, pDimAxis);
			if (pArrayTResult == nullptr) return Value::Nil;
			valueRtn = Value(new Object_array(env, pArrayTResult));
		}
	} else {
		valueRtn = Value(CalcMeanFlat<T_ElemResult, T_Elem>(pArrayT));
	}
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, mean)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_mean<UInt32, Boolean>,
		&Method_mean<Int8, Int8>,
		&Method_mean<UInt8, UInt8>,
		&Method_mean<Int16, Int16>,
		&Method_mean<UInt16, UInt16>,
		&Method_mean<Int32, Int32>,
		&Method_mean<UInt32, UInt32>,
		&Method_mean<Int64, Int64>,
		&Method_mean<UInt64, UInt64>,
		&Method_mean<Half, Half>,
		&Method_mean<Float, Float>,
		&Method_mean<Double, Double>,
		&Method_mean<Complex, Complex>,
		//&Method_mean<Value, Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#offset(n:number):map {block?}
Gura_DeclareMethod(array, offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has extracted elements of the target `array` after skipping its first `n` elements.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

template<typename T_Elem>
Value Method_offset(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t n = arg.GetSizeT(0);
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(pArrayT->Offset(sig, n));
	if (pArrayTRtn.IsNull()) return Value::Nil;
	Value value(new Object_array(env, pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_ImplementMethod(array, offset)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_offset<Boolean>,
		&Method_offset<Int8>,
		&Method_offset<UInt8>,
		&Method_offset<Int16>,
		&Method_offset<UInt16>,
		&Method_offset<Int32>,
		&Method_offset<UInt32>,
		&Method_offset<Int64>,
		&Method_offset<UInt64>,
		&Method_offset<Half>,
		&Method_offset<Float>,
		&Method_offset<Double>,
		&Method_offset<Complex>,
		//&Method_offset<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#paste(offset:number, src:array):map:void
Gura_DeclareMethod(array, paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "src", VTYPE_array, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Pastes elements of `src` into the target `array` instance.\n"
		"\n"
		"The argument `offset` specifies the posision where elements are pasted in\n"
		);
}

template<typename T_Elem>
Value Method_paste(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t offset = arg.GetSizeT(0);
	const Array *pArraySrc = Object_array::GetObject(arg, 1)->GetArray();
	if (pArraySrc->GetElemType() != ArrayT<T_Elem>::ElemTypeThis) {
		sig.SetError(ERR_TypeError,
					 "source and destination array must cosist of elements of the same type");
		return Value::Nil;
	}
	const ArrayT<T_Elem> *pArrayTSrc = dynamic_cast<const ArrayT<T_Elem> *>(pArraySrc);
	if (!pArrayT->PrepareModification(sig)) return Value::Nil;
	pArrayT->Paste(sig, offset, pArrayTSrc);
	return Value::Nil;
}

Gura_ImplementMethod(array, paste)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_paste<Boolean>,
		&Method_paste<Int8>,
		&Method_paste<UInt8>,
		&Method_paste<Int16>,
		&Method_paste<UInt16>,
		&Method_paste<Int32>,
		&Method_paste<UInt32>,
		&Method_paste<Int64>,
		&Method_paste<UInt64>,
		&Method_paste<Half>,
		&Method_paste<Float>,
		&Method_paste<Double>,
		&Method_paste<Complex>,
		//&Method_paste<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#reshape(dims[]:number:nil) {block?}
Gura_DeclareMethod(array, reshape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar | FLAG_Nil);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has reshaped the target `array` according to a list of\n"
		"dimension size specified by `dims`.\n"
		"\n"
		"Below are examples:\n"
		"\n"
		"    x = array(1..24)\n"
		"    a = x.reshape([6, 4])    // a is an array of 6x4.\n"
		"    b = x.reshape([2, 3, 4]) // b is an array of 2x3x4.\n"
		"\n"
		"A value of `nil` in the list of dimension means it would be calculated from the whole size\n"
		"and other dimension sizes. Only one `nil` is allowed to exist.\n"
		"\n"
		"    x = array(1..24)\n"
		"    b = x.reshape([2, nil, 4]) // b is an array of 2x3x4.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

template<typename T_Elem>
Value Method_reshape(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	Signal &sig = env.GetSignal();
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	AutoPtr<Array> pArrayTRtn(pArrayT->Reshape(sig, arg.GetList(0)));
	if (pArrayTRtn.IsNull()) return Value::Nil;
	return pFunc->ReturnValue(env, arg, Value(new Object_array(env, pArrayTRtn.release())));
}

Gura_ImplementMethod(array, reshape)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_reshape<Boolean>,
		&Method_reshape<Int8>,
		&Method_reshape<UInt8>,
		&Method_reshape<Int16>,
		&Method_reshape<UInt16>,
		&Method_reshape<Int32>,
		&Method_reshape<UInt32>,
		&Method_reshape<Int64>,
		&Method_reshape<UInt64>,
		&Method_reshape<Half>,
		&Method_reshape<Float>,
		&Method_reshape<Double>,
		&Method_reshape<Complex>,
		//&Method_reshape<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#roundoff(threshold?:number) {block?}
Gura_DeclareMethod(array, roundoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has rounded off elements less than `threshold` to zero in the target `array`.\n"
		"The default value for `threshold` is `1.0e-6` when omitted.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

template<typename T_Elem>
Value Method_roundoff(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	double threshold = arg.IsValid(0)? arg.GetDouble(0) : 1.e-6;
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	AutoPtr<Array> pArrayTRtn(pArrayT->RoundOff(threshold));
	return pFunc->ReturnValue(env, arg, Value(new Object_array(env, pArrayTRtn.release())));
}

Gura_ImplementMethod(array, roundoff)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_roundoff<Boolean>,
		&Method_roundoff<Int8>,
		&Method_roundoff<UInt8>,
		&Method_roundoff<Int16>,
		&Method_roundoff<UInt16>,
		&Method_roundoff<Int32>,
		&Method_roundoff<UInt32>,
		&Method_roundoff<Int64>,
		&Method_roundoff<UInt64>,
		&Method_roundoff<Half>,
		&Method_roundoff<Float>,
		&Method_roundoff<Double>,
		&Method_roundoff<Complex>,
		//&Method_roundoff<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#sum(axis?:number) {block?}
Gura_DeclareMethod(array, sum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a summation value of elements in the target `array`.\n");
}

template<typename T_ElemResult, typename T_Elem>
Value Method_sum(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Value valueRtn;
	if (arg.IsValid(0)) {
		size_t axis = arg.GetSizeT(0);
		const Array::Dimensions &dims = pArrayT->GetDimensions();
		if (axis >= dims.size()) {
			env.SetError(ERR_OutOfRangeError, "specified axis is out of range");
			return Value::Nil;
		} else if (axis == 0 && dims.size() == 1) {
			valueRtn = Value(CalcSumFlat<T_ElemResult, T_Elem>(pArrayT));
		} else {
			Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
			ArrayT<T_ElemResult> *pArrayTResult = CalcSum<T_ElemResult, T_Elem>(pArrayT, pDimAxis);
			if (pArrayTResult == nullptr) return Value::Nil;
			valueRtn = Value(new Object_array(env, pArrayTResult));
		}
	} else {
		valueRtn = Value(CalcSumFlat<T_ElemResult, T_Elem>(pArrayT));
	}
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, sum)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_sum<UInt32, Boolean>,
		&Method_sum<Int8, Int8>,
		&Method_sum<UInt8, UInt8>,
		&Method_sum<Int16, Int16>,
		&Method_sum<UInt16, UInt16>,
		&Method_sum<Int32, Int32>,
		&Method_sum<UInt32, UInt32>,
		&Method_sum<Int64, Int64>,
		&Method_sum<UInt64, UInt64>,
		&Method_sum<Half, Half>,
		&Method_sum<Float, Float>,
		&Method_sum<Double, Double>,
		&Method_sum<Complex, Complex>,
		//&Method_sum<Value, Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#tail(n:number):map {block?}
Gura_DeclareMethod(array, tail)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has extracted `n` elements from the bottom of the target `array`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

template<typename T_Elem>
Value Method_tail(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t n = arg.GetSizeT(0);
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(pArrayT->Tail(sig, n));
	if (pArrayTRtn.IsNull()) return Value::Nil;
	Value value(new Object_array(env, pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_ImplementMethod(array, tail)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_tail<Boolean>,
		&Method_tail<Int8>,
		&Method_tail<UInt8>,
		&Method_tail<Int16>,
		&Method_tail<UInt16>,
		&Method_tail<Int32>,
		&Method_tail<UInt32>,
		&Method_tail<Int64>,
		&Method_tail<UInt64>,
		&Method_tail<Half>,
		&Method_tail<Float>,
		&Method_tail<Double>,
		&Method_tail<Complex>,
		//&Method_tail<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#transpose(axes[]?:number) {block?}
Gura_DeclareMethod(array, transpose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "axes", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array instance that transposes axes of the original array\n"
		"according to the specified argument `axes`.\n"
		"\n"
		"If the argument is not specified, two axes at the lowest rank, which correspond to\n"
		"row and column for a matrix, would be transposed.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

template<typename T_Elem>
Value Method_transpose(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	AutoPtr<Array> pArrayTRtn;
	if (arg.IsValid(0)) {
		pArrayTRtn.reset(pArrayT->Transpose(sig, arg.GetList(0)));
		if (pArrayTRtn.IsNull()) return Value::Nil;
	} else {
		pArrayTRtn.reset(pArrayT->Transpose());
	}
	return pFunc->ReturnValue(env, arg, Value(new Object_array(env, pArrayTRtn.release())));
}

Gura_ImplementMethod(array, transpose)
{
	static const MethodT methods[Array::ETYPE_Max] = {
		nullptr,
		&Method_transpose<Boolean>,
		&Method_transpose<Int8>,
		&Method_transpose<UInt8>,
		&Method_transpose<Int16>,
		&Method_transpose<UInt16>,
		&Method_transpose<Int32>,
		&Method_transpose<UInt32>,
		&Method_transpose<Int64>,
		&Method_transpose<UInt64>,
		&Method_transpose<Half>,
		&Method_transpose<Float>,
		&Method_transpose<Double>,
		&Method_transpose<Complex>,
		//&Method_transpose<Value>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
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
	// assignment of array creators
	Gura_AssignMethodTo(VTYPE_array, array, identity);
	Gura_AssignMethodTo(VTYPE_array, array, interval);
	Gura_AssignMethodTo(VTYPE_array, array, ones);
	Gura_AssignMethodTo(VTYPE_array, array, rands);
	Gura_AssignMethodTo(VTYPE_array, array, rands_at_normal);
	Gura_AssignMethodTo(VTYPE_array, array, range);
	Gura_AssignMethodTo(VTYPE_array, array, rotation);
	Gura_AssignMethodTo(VTYPE_array, array, rotation_at_x);
	Gura_AssignMethodTo(VTYPE_array, array, rotation_at_y);
	Gura_AssignMethodTo(VTYPE_array, array, rotation_at_z);
	Gura_AssignMethodTo(VTYPE_array, array, scaling);
	Gura_AssignMethodTo(VTYPE_array, array, translation);
	Gura_AssignMethodTo(VTYPE_array, array, zeros);
#if 0
	do {
		Class *pClass = env.LookupClass(VTYPE_array);
		Gura_AssignMethodTo_arrayT(pClass, identity,		Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, interval,		Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, ones,			Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, rands,			Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, rands_at_normal,	Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, range,			Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, rotation,		Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, rotation_at_x,	Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, rotation_at_y,	Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, rotation_at_z,	Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, scaling,			Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, translation,		Double, VTYPE_array_at_double);
		Gura_AssignMethodTo_arrayT(pClass, zeros,			Double, VTYPE_array_at_double);
	} while (0);
#endif
	// Assignment of methods
	Gura_AssignMethodTo(VTYPE_array, array, dot);
	Gura_AssignMethodTo(VTYPE_array, array, dump);
	Gura_AssignMethodTo(VTYPE_array, array, each);
	Gura_AssignMethodTo(VTYPE_array, array, elemcast);
	Gura_AssignMethodTo(VTYPE_array, array, fill);
	Gura_AssignMethodTo(VTYPE_array, array, flatten);
	Gura_AssignMethodTo(VTYPE_array, array, head);
	Gura_AssignMethodTo(VTYPE_array, array, invert);
	Gura_AssignMethodTo(VTYPE_array, array, iselemsame);
	Gura_AssignMethodTo(VTYPE_array, array, issquare);
	Gura_AssignMethodTo(VTYPE_array, array, mean);
	Gura_AssignMethodTo(VTYPE_array, array, offset);
	Gura_AssignMethodTo(VTYPE_array, array, paste);
	Gura_AssignMethodTo(VTYPE_array, array, reshape);
	Gura_AssignMethodTo(VTYPE_array, array, roundoff);
	Gura_AssignMethodTo(VTYPE_array, array, sum);
	Gura_AssignMethodTo(VTYPE_array, array, tail);
	Gura_AssignMethodTo(VTYPE_array, array, transpose);
	// Assignment of operator
	AssignOperators(env);
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(arrayutil, arrayutil)

Gura_RegisterModule(arrayutil)
