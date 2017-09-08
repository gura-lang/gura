//=============================================================================
// Creator.cpp
// Implementation of functions that create array instances.
//=============================================================================
#include "stdafx.h"

//-----------------------------------------------------------------------------
// macros
//-----------------------------------------------------------------------------
#define Gura_DeclareClassMethodAlias_Array(className, funcName, funcNameAlias) \
class Func_##className##__##funcName : public Function { \
private: \
	Array::ElemType _elemType; \
public: \
	Func_##className##__##funcName(Environment &env, Array::ElemType elemType); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
Func_##className##__##funcName::Func_##className##__##funcName(Environment &env, Array::ElemType elemType) : \
	Function(env, Symbol::Add(funcNameAlias), FUNCTYPE_Class, FLAG_None), _elemType(elemType)

#define Gura_DeclareClassMethod_Array(className, funcName) Gura_DeclareClassMethodAlias_Array(className, funcName, #funcName)

#define Gura_AssignMethod_Array(valType, className, name, elemType)	\
do { \
	Class *pClass = env.LookupClass(valType); \
	pClass->AssignFunction(new Func_##className##__##name(*pClass, elemType));	\
} while (0) \

#define Gura_AssignMethodMultiple_Array(className, name) \
Gura_AssignMethod_Array(VTYPE_array, className, name, Array::ETYPE_None); \
Gura_AssignMethod_Array(VTYPE_array_at_boolean, className, name, Array::ETYPE_Boolean); \
Gura_AssignMethod_Array(VTYPE_array_at_int8, className, name, Array::ETYPE_Int8); \
Gura_AssignMethod_Array(VTYPE_array_at_uint8, className, name, Array::ETYPE_UInt8); \
Gura_AssignMethod_Array(VTYPE_array_at_int16, className, name, Array::ETYPE_Int16); \
Gura_AssignMethod_Array(VTYPE_array_at_uint16, className, name, Array::ETYPE_UInt16); \
Gura_AssignMethod_Array(VTYPE_array_at_int32, className, name, Array::ETYPE_Int32); \
Gura_AssignMethod_Array(VTYPE_array_at_uint32, className, name, Array::ETYPE_UInt32); \
Gura_AssignMethod_Array(VTYPE_array_at_int64, className, name, Array::ETYPE_Int64); \
Gura_AssignMethod_Array(VTYPE_array_at_uint64, className, name, Array::ETYPE_UInt64); \
Gura_AssignMethod_Array(VTYPE_array_at_half, className, name, Array::ETYPE_Half); \
Gura_AssignMethod_Array(VTYPE_array_at_float, className, name, Array::ETYPE_Float); \
Gura_AssignMethod_Array(VTYPE_array_at_double, className, name, Array::ETYPE_Double); \
Gura_AssignMethod_Array(VTYPE_array_at_complex, className, name, Array::ETYPE_Complex);

Gura_BeginModuleScope(arrayt)

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
void SetError_CreationError(Environment &env, Array::ElemType elemType)
{
	env.SetError(ERR_ValueError, "can't create an array of %s",
				 Array::GetElemTypeName(elemType));
}

//-----------------------------------------------------------------------------
// Implementation of array creators
//-----------------------------------------------------------------------------
// array.identity(n:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod_Array(array, identity)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array of `double` type of elements\n"
		"that represents an identity matrix with specified size `n`.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.identity(3)\n"
		"    // x is array@double {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `int32` elements:\n"
		"\n"
		"    array.identity(3, elemtype => `int32)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.identity` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@int32.identity(3)\n");
}

template<typename T_Elem> Array *FuncTmpl_identity(size_t n)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, n, n));
	pArrayT->FillZero();
	T_Elem *p = pArrayT->GetPointer();
	size_t stride = n + 1;
	for (size_t i = 0; i < n; i++, p += stride) *p = 1;
	return pArrayT.release();
}


Gura_ImplementClassMethod(array, identity)
{
	typedef Array *(*FuncT)(size_t n);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_identity);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(1)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(1)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
	AutoPtr<Array> pArray((*func)(arg.GetSizeT(0)));
	return ReturnValue(env, arg, new Object_array(env, pArray.release()));
}

// array.interval(begin:number, end:number, samples:number, elemtype?:symbol):static:map:[open,open_l,open_r] {block?}
Gura_DeclareClassMethod_Array(array, interval)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "begin", VTYPE_number);
	DeclareArg(env, "end", VTYPE_number);
	DeclareArg(env, "samples", VTYPE_number);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareAttr(Gura_Symbol(open));
	DeclareAttr(Gura_Symbol(open_l));
	DeclareAttr(Gura_Symbol(open_r));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates a one-dimentional array with `double` type of element\n"
		"that contains a sequence of numbers\n"
		"according to the beginning, ending numbers and the number of samples between them.\n"
		"\n"
		"In default, it creates a sequence with a range of `[begin, end]`\n"
		"meaning that the sequence contains the beginning and ending numbers.\n"
		"Following attributes would control the range:\n"
		"\n"
		"- `:open` .. Numbers in range of `(begin, end)` that doesn't contain either `begin` or `end`.\n"
		"- `:open_l` .. Numbers in range of `(begin, end]` that doesn't contain `begin`.\n"
		"- `:open_r` .. Numbers in range of `[begin, end)` that doesn't contain `end`.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.interval(0, 3, 7)\n"
		"    // x is array@double {0, 0.5, 1, 1.5, 2, 2.5, 3}\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `float` elements:\n"
		"\n"
		"    array.interval(0, 3, 7, elemtype => `float)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.interval` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@float.interval(0, 3, 7)\n");
}

template<typename T_Elem> Array *FuncTmpl_interval(
	Double numBegin, Double numEnd, int numSamples, Double numDenom, int iFactor)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, numSamples));
	T_Elem *p = pArrayT->GetPointer();
	for (int i = 0; i < numSamples; i++, iFactor++) {
		p[i] = static_cast<T_Elem>((numEnd - numBegin) * iFactor / numDenom + numBegin);
	}
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, interval)
{
	typedef Array *(*FuncT)(Double numBegin, Double numEnd, int numSamples,
							Double numDenom, int iFactor);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_interval);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(3)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
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
	AutoPtr<Array> pArray((*func)(numBegin, numEnd, numSamples, numDenom, iFactor));
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.ones(dims[]:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod_Array(array, ones)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array of `double` type of elements, which are initialized with one.\n"
		"The argument `dims` specifies the dimension of the created array.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.ones([3, 4])\n"
		"    // x is array@double {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `int32` elements:\n"
		"\n"
		"    array.ones([3, 4], elemtype => `int32)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.ones` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@int32.ones([3, 4])\n");
}

template<typename T_Elem> Array *FuncTmpl_ones(const ValueList &valList)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(new ArrayT<T_Elem>(colMajorFlag));
	pArrayT->SetDimensions(valList);
	pArrayT->AllocMemory();
	pArrayT->Fill(1);
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, ones)
{
	typedef Array *(*FuncT)(const ValueList &valList);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_ones);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(1)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(1)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
	AutoPtr<Array> pArray((*func)(arg.GetList(0)));
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.rands(dims[]:number, range?:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod_Array(array, rands)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "range", VTYPE_number, OCCUR_ZeroOrOnce);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array of `double` type of elements which are initialized with random numbers.\n"
		"The argument `dims` specifies the dimension of the created array.\n"
		"When the argument `range` is specified, the generated are all integer numbers\n"
		"that are ranged within `[0, range)`.\n"
		"Otherwise, the generated are real numbers ranged within `[0, 1)`.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.rands([3, 4], 10)\n"
		"    // x is like array@double {{6, 7, 6, 9}, {3, 3, 6, 0}, {7, 9, 5, 5}}\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `int32` elements:\n"
		"\n"
		"    array.rands([3, 4], 10, elemtype => `int32)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.rands` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@int32.rands([3, 4], 10)\n");
}

template<typename T_Elem> Array *FuncTmpl_rands(const ValueList &valList, UInt range)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(new ArrayT<T_Elem>(colMajorFlag));
	pArrayT->SetDimensions(valList);
	pArrayT->AllocMemory();
	pArrayT->FillRand(range);
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, rands)
{
	typedef Array *(*FuncT)(const ValueList &valList, UInt range);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_rands);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(2)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(2)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
	UInt range = arg.IsValid(1)? arg.GetUInt(1) : 0;
	AutoPtr<Array> pArray((*func)(arg.GetList(0), range));
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.rands@normal(dims[]:number, mu?:number, sigma?:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethodAlias_Array(array, rands_at_normal, "rands@normal")
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "mu", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "sigma", VTYPE_number, OCCUR_ZeroOrOnce);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array of `double` type of elements which are initialized with normal distribution random numbers.\n"
		"The argument `dims` specifies the dimension of the created array.\n"
		"The arguments `mu` and `sigma` supply parameters for normal distribution\n"
		"where `mu` specifies the mean value and `sigma` the standard deviation.\n"
		"In default, the `mu` is zero and `sigma` one.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.rands@normal([3, 4], 1, 3)\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `float` elements:\n"
		"\n"
		"    array.rands@normal([3, 4], 1, 3, elemtype => `float)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.rands@normal` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@int32.rands@normal([3, 4], 1, 3)\n");
}

template<typename T_Elem> Array *FuncTmpl_rands_at_normal(const ValueList &valList, double mu, double sigma)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(new ArrayT<T_Elem>(colMajorFlag));
	pArrayT->SetDimensions(valList);
	pArrayT->AllocMemory();
	pArrayT->FillRandNormal(mu, sigma);
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, rands_at_normal)
{
	typedef Array *(*FuncT)(const ValueList &valList, double mu, double sigma);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_rands_at_normal);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(3)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
	double mu = arg.IsValid(1)? arg.GetDouble(1) : 0;
	double sigma = arg.IsValid(2)? arg.GetDouble(2) : 1;
	AutoPtr<Array> pArray((*func)(arg.GetList(0), mu, sigma));
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.range(num:number, num_end?:number, step?:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod_Array(array, range)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_number);
	DeclareArg(env, "num_end", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "step", VTYPE_number, OCCUR_ZeroOrOnce);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array of `double` type of elements\n"
		"that are initialized with a sequence of integer numbers.\n"
		"\n"
		"This function can generate three types of sequence like below:\n"
		"\n"
		"- `array.range(num)` .. between `0` and `(num - 1)`.\n"
		"- `array.range(num, num_end)` .. between `num` and `(num_end - 1)`.\n"
		"- `array.range(num, num_end, step)` .. between `num` and `(num_end - 1)` incremented by `step`.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.range(5)\n"
        "    // x is array@double {0, 1, 2, 3, 4}\n"
		"    x = array.range(2, 5)\n"
		"    // x is array@double {2, 3, 4}\n"
		"    x = array.range(2, 10, 2)\n"
		"    // x is array@double {2, 4, 6, 8}\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `int32` elements:\n"
		"\n"
		"    array.range(5, elemtype => `int32)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.range` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@int32.range(5)\n");
}

template<typename T_Elem> Array *FuncTmpl_range(Double numBegin, Double numEnd, Double numStep)
{
	int numSamples = 0;
	if (numEnd > numBegin) {
		Double numRange = numEnd - numBegin;
		numSamples = static_cast<int>((numRange - 1) / numStep) + 1;
	} else {
		Double numRange = numBegin - numEnd;
		numSamples = static_cast<int>(-(numRange - 1) / numStep) + 1;
	}
	if (numSamples < 0) numSamples = 0;
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, numSamples));
	T_Elem *p = pArrayT->GetPointer();
	for (size_t i = 0; i < numSamples; i++) {
		p[i] = static_cast<T_Elem>(numBegin + numStep * i);
	}
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, range)
{
	typedef Array *(*FuncT)(Double numBegin, Double numEnd, Double numStep);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_range);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(3)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
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
	AutoPtr<Array> pArray((*func)(numBegin, numEnd, numStep));
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.rotation(angle:number, xtrans?:number, ytrans?:number, elemtype?:symbol):static:map:[deg] {block?}
Gura_DeclareClassMethod_Array(array, rotation)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` of `double` type of elements representing a matrix to rotate a 2-D coord.\n"
		"\n"
		"The rotation `angle` is specified in radian value.\n"
		"If the attribute `:deg` is specified, the `angle` is specified in degree value.\n"
		"\n"
		"If one or both of `xtrans` and `ytrans` are specified,\n"
		"it would create an array that works as translation as well as rotation.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.rotation(math.pi / 6)\n"
		"    // x is a matrix to rotate by pi/6.\n"
		"    x = array.rotation(30):deg\n"
		"    // x is a matrix to rotate by 30 degree, which is pi/6 in radian.\n"
		"    x = array.rotation(math.pi / 6, 3, 5)\n"
		"    // x is a matrix to rotate by pi/6 and translate by [3, 5].\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `float` elements:\n"
		"\n"
		"    array.rotation(math.pi / 6, elemtype => `float)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.rotation` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@float.rotation(math.pi / 6)\n");
}

template<typename T_Elem> Array *FuncTmpl_rotation(double rad, bool transFlag, double xTrans, double yTrans)
{
	bool colMajorFlag = false;
	int sizeMat = transFlag? 3 : 2;
	T_Elem numCos = static_cast<T_Elem>(::cos(rad));
	T_Elem numSin = static_cast<T_Elem>(::sin(rad));
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, sizeMat, sizeMat));
	T_Elem *p = pArrayT->GetPointer();
	// row-1
	*p++ = numCos;
	*p++ = -numSin;
	if (transFlag) *p++ = static_cast<T_Elem>(xTrans);
	// row-2
	*p++ = numSin;
	*p++ = numCos;
	if (transFlag) {
		*p++ = static_cast<T_Elem>(yTrans);
		// row-3
		*p++ = 0;
		*p++ = 0;
		*p++ = 1;
	}
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, rotation)
{
	typedef Array *(*FuncT)(double rad, bool transFlag, double xTrans, double yTrans);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_rotation);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(3)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Array> pArray;
	if (arg.IsValid(1) || arg.IsValid(2)) {
		Double xTrans = arg.IsValid(1)? arg.GetDouble(1) : 0;
		Double yTrans = arg.IsValid(2)? arg.GetDouble(2) : 0;
		pArray.reset((*func)(angle, true, xTrans, yTrans));
	} else {
		pArray.reset((*func)(angle, false, 0, 0));
	}
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.rotation@x(angle:number, xtrans?:number, ytrans?:number, ztrans?:number, elemtype?:symbol):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias_Array(array, rotation_at_x, "rotation@x")
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` of `double` type of elements representing a matrix to rotate a 3-D coord around x-axis.\n"
		"\n"
		"The rotation `angle` is specified in radian value.\n"
		"If the attribute `:deg` is specified, the `angle` is specified in degree value.\n"
		"\n"
		"If one or more of `xtrans`, `ytrans` and `ztrans` are specified,\n"
		"it would create an array that works as translation as well as rotation.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.rotation@x(math.pi / 6)\n"
		"    // x is a matrix to rotate by pi/6.\n"
		"    x = array.rotation@x(30):deg\n"
		"    // x is a matrix to rotate by 30 degree, which is pi/6 in radian.\n"
		"    x = array.rotation@x(math.pi / 6, 3, -2, 5)\n"
		"    // x is a matrix to rotate by pi/6 and translate by [3, -2, 5].\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `float` elements:\n"
		"\n"
		"    array.rotation@x(math.pi / 6, elemtype => `float)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.rotation@x` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@float.rotation@x(math.pi / 6)\n");
}

template<typename T_Elem> Array *FuncTmpl_rotation_at_x(Double rad, bool transFlag, Double xTrans, Double yTrans, Double zTrans)
{
	bool colMajorFlag = false;
	int sizeMat = transFlag? 4 : 3;
	T_Elem numCos = static_cast<T_Elem>(::cos(rad));
	T_Elem numSin = static_cast<T_Elem>(::sin(rad));
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, sizeMat, sizeMat));
	T_Elem *p = pArrayT->GetPointer();
	// row-1
	*p++ = 1;
	*p++ = 0;
	*p++ = 0;
	if (transFlag) {
		*p++ = static_cast<T_Elem>(xTrans);
	}
	// row-2
	*p++ = 0;
	*p++ = numCos;
	*p++ = -numSin;
	if (transFlag) {
		*p++ = static_cast<T_Elem>(yTrans);
	}
	// row-3
	*p++ = 0;
	*p++ = numSin;
	*p++ = numCos;
	if (transFlag) {
		*p++ = static_cast<T_Elem>(zTrans);
		// row-4
		*p++ = 0;
		*p++ = 0;
		*p++ = 0;
		*p++ = 1;
	}
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, rotation_at_x)
{
	typedef Array *(*FuncT)(Double rad, bool transFlag, Double xTrans, Double yTrans, Double zTrans);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_rotation_at_x);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(4)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(4)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Array> pArray;
	if (arg.IsValid(1) || arg.IsValid(2) || arg.IsValid(3)) {
		Double xTrans = arg.IsValid(1)? static_cast<Double>(arg.GetDouble(1)) : 0;
		Double yTrans = arg.IsValid(2)? static_cast<Double>(arg.GetDouble(2)) : 0;
		Double zTrans = arg.IsValid(3)? static_cast<Double>(arg.GetDouble(3)) : 0;
		pArray.reset((*func)(angle, true, xTrans, yTrans, zTrans));
	} else {
		pArray.reset((*func)(angle, false, 0, 0, 0));
	}
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.rotation@y(angle:number, xtrans?:number, ytrans?:number, ztrans?:number, elemtype?:symbol):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias_Array(array, rotation_at_y, "rotation@y")
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` of `double` type of elements representing a matrix to rotate a 3-D coord around y-axis.\n"
		"\n"
		"The rotation `angle` is specified in radian value.\n"
		"If the attribute `:deg` is specified, the `angle` is specified in degree value.\n"
		"\n"
		"If one or more of `xtrans`, `ytrans` and `ztrans` are specified,\n"
		"it would create an array that works as translation as well as rotation.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.rotation@y(math.pi / 6)\n"
		"    // x is a matrix to rotate by pi/6.\n"
		"    x = array.rotation@y(30):deg\n"
		"    // x is a matrix to rotate by 30 degree, which is pi/6 in radian.\n"
		"    x = array.rotation@y(math.pi / 6, 3, -2, 5)\n"
		"    // x is a matrix to rotate by pi/6 and translate by [3, -2, 5].\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `float` elements:\n"
		"\n"
		"    array.rotation@y(math.pi / 6, elemtype => `float)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.rotation@y` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@float.rotation@y(math.pi / 6)\n");
}

template<typename T_Elem> Array *FuncTmpl_rotation_at_y(Double rad, bool transFlag, Double xTrans, Double yTrans, Double zTrans)
{
	bool colMajorFlag = false;
	typedef Array *(*FuncT)(Double rad, bool transFlag, Double xTrans, Double yTrans, Double zTrans);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_rotation_at_y);
	int sizeMat = transFlag? 4 : 3;
	T_Elem numCos = static_cast<T_Elem>(::cos(rad));
	T_Elem numSin = static_cast<T_Elem>(::sin(rad));
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, sizeMat, sizeMat));
	T_Elem *p = pArrayT->GetPointer();
	// row-1
	*p++ = numCos;
	*p++ = 0;
	*p++ = numSin;
	if (transFlag) {
		*p++ = static_cast<T_Elem>(xTrans);
	}
	// row-2
	*p++ = 0;
	*p++ = 1;
	*p++ = 0;
	if (transFlag) {
		*p++ = static_cast<T_Elem>(yTrans);
	}
	// row-3
	*p++ = -numSin;
	*p++ = 0;
	*p++ = numCos;
	if (transFlag) {
		*p++ = static_cast<T_Elem>(zTrans);
		// row-4
		*p++ = 0;
		*p++ = 0;
		*p++ = 0;
		*p++ = 1;
	}
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, rotation_at_y)
{
	typedef Array *(*FuncT)(Double rad, bool transFlag, Double xTrans, Double yTrans, Double zTrans);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_rotation_at_y);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(4)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(4)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Array> pArray;
	if (arg.IsValid(1) || arg.IsValid(2) || arg.IsValid(3)) {
		Double xTrans = arg.IsValid(1)? static_cast<Double>(arg.GetDouble(1)) : 0;
		Double yTrans = arg.IsValid(2)? static_cast<Double>(arg.GetDouble(2)) : 0;
		Double zTrans = arg.IsValid(3)? static_cast<Double>(arg.GetDouble(3)) : 0;
		pArray.reset((*func)(angle, true, xTrans, yTrans, zTrans));
	} else {
		pArray.reset((*func)(angle, false, 0, 0, 0));
	}
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.rotation@z(angle:number, xtrans?:number, ytrans?:number, ztrans?:number, elemtype?:symbol):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias_Array(array, rotation_at_z, "rotation@z")
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareAttr(Gura_Symbol(deg));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` of `double` type of elements representing a matrix to rotate a 3-D coord around z-axis.\n"
		"\n"
		"The rotation `angle` is specified in radian value.\n"
		"If the attribute `:deg` is specified, the `angle` is specified in degree value.\n"
		"\n"
		"If one or more of `xtrans`, `ytrans` and `ztrans` are specified,\n"
		"it would create an array that works as translation as well as rotation.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.rotation@z(math.pi / 6)\n"
		"    // x is a matrix to rotate by pi/6.\n"
		"    x = array.rotation@z(30):deg\n"
		"    // x is a matrix to rotate by 30 degree, which is pi/6 in radian.\n"
		"    x = array.rotation@z(math.pi / 6, 3, -2, 5)\n"
		"    // x is a matrix to rotate by pi/6 and translate by [3, -2, 5].\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `float` elements:\n"
		"\n"
		"    array.rotation@z(math.pi / 6, elemtype => `float)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.rotation@z` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@float.rotation@z(math.pi / 6)\n");
}

template<typename T_Elem> Array *FuncTmpl_rotation_at_z(Double rad, bool transFlag, Double xTrans, Double yTrans, Double zTrans)
{
	bool colMajorFlag = false;
	int sizeMat = transFlag? 4 : 3;
	T_Elem numCos = static_cast<T_Elem>(::cos(rad));
	T_Elem numSin = static_cast<T_Elem>(::sin(rad));
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, sizeMat, sizeMat));
	T_Elem *p = pArrayT->GetPointer();
	// row-1
	*p++ = numCos;
	*p++ = -numSin;
	*p++ = 0;
	if (transFlag) {
		*p++ = static_cast<T_Elem>(xTrans);
	}
	// row-2
	*p++ = numSin;
	*p++ = numCos;
	*p++ = 0;
	if (transFlag) {
		*p++ = static_cast<T_Elem>(yTrans);
	}
	// row-3
	*p++ = 0;
	*p++ = 0;
	*p++ = 1;
	if (transFlag) {
		*p++ = static_cast<T_Elem>(zTrans);
		// row-4
		*p++ = 0;
		*p++ = 0;
		*p++ = 0;
		*p++ = 1;
	}
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, rotation_at_z)
{
	typedef Array *(*FuncT)(Double rad, bool transFlag, Double xTrans, Double yTrans, Double zTrans);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_rotation_at_z);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(4)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(4)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<Array> pArray;
	if (arg.IsValid(1) || arg.IsValid(2) || arg.IsValid(3)) {
		Double xTrans = arg.IsValid(1)? static_cast<Double>(arg.GetDouble(1)) : 0;
		Double yTrans = arg.IsValid(2)? static_cast<Double>(arg.GetDouble(2)) : 0;
		Double zTrans = arg.IsValid(3)? static_cast<Double>(arg.GetDouble(3)) : 0;
		pArray.reset((*func)(angle, true, xTrans, yTrans, zTrans));
	} else {
		pArray.reset((*func)(angle, false, 0, 0, 0));
	}
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.scaling(xscale:number, yscale:number, zscale?:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod_Array(array, scaling)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "xscale", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "yscale", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "zscale", VTYPE_number, OCCUR_ZeroOrOnce);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` of `double` type of elements representing a matrix to scale a coord.\n"
		"\n"
		"It creates a matrix that works on a 2-D coord if `xscale` and `yscale` are specified\n"
		"while it creates a matrix on a 3-D coord if `xscale`, `yscale` and `zscale` are specified.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.scaling(3, 4)\n"
		"    // x is a matrix to scale a 2-D coord by [3, 4].\n"
		"    x = array.scaling(3, 4, -2)\n"
		"    // x is a matrix to scale a 3-D coord by [3, 4, -2].\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `float` elements:\n"
		"\n"
		"    array.scaling(3, 4, elemtype => `float)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.scaling` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@float.scaling(3, 4\n");
}

template<typename T_Elem> Array *FuncTmpl_scaling2D(Double xScale, Double yScale)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, 3, 3));
	T_Elem *p = pArrayT->GetPointer();
	// row-1
	*p++ = static_cast<T_Elem>(xScale);
	*p++ = 0;
	*p++ = 0;
	// row-2
	*p++ = 0;
	*p++ = static_cast<T_Elem>(yScale);
	*p++ = 0;
	// row-3
	*p++ = 0;
	*p++ = 0;
	*p++ = 1;
	return pArrayT.release();
}

template<typename T_Elem> Array *FuncTmpl_scaling3D(Double xScale, Double yScale, Double zScale)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, 4, 4));
	T_Elem *p = pArrayT->GetPointer();
	// row-1
	*p++ = static_cast<T_Elem>(xScale);
	*p++ = 0;
	*p++ = 0;
	*p++ = 0;
	// row-2
	*p++ = 0;
	*p++ = static_cast<T_Elem>(yScale);
	*p++ = 0;
	*p++ = 0;
	// row-3
	*p++ = 0;
	*p++ = 0;
	*p++ = static_cast<T_Elem>(zScale);
	*p++ = 0;
	// row-4
	*p++ = 0;
	*p++ = 0;
	*p++ = 0;
	*p++ = 1;
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, scaling)
{
	typedef Array *(*FuncT2D)(Double xTrans, Double yTrans);
	typedef Array *(*FuncT3D)(Double xTrans, Double yTrans, Double zTrans);
	DeclareFunctionTable1D(FuncT2D, funcTbl2D, FuncTmpl_scaling2D);
	DeclareFunctionTable1D(FuncT3D, funcTbl3D, FuncTmpl_scaling3D);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(3)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	Double xScale = static_cast<Double>(arg.GetDouble(0));
	Double yScale = static_cast<Double>(arg.GetDouble(1));
	AutoPtr<Array> pArray;
	if (arg.IsValid(2)) {
		FuncT3D func = funcTbl3D[elemType];
		if (func == nullptr) {
			SetError_CreationError(env, elemType);
			return Value::Nil;
		}
		Double zScale = static_cast<Double>(arg.GetDouble(2));
		pArray.reset((*func)(xScale, yScale, zScale));
	} else {
		FuncT2D func = funcTbl2D[elemType];
		if (func == nullptr) {
			SetError_CreationError(env, elemType);
			return Value::Nil;
		}
		pArray.reset((*func)(xScale, yScale));
	}
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.translation(xtrans:number, ytrans:number, ztrans?:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod_Array(array, translation)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` of `double` type of elements representing a matrix to translate a coord.\n"
		"\n"
		"It creates a matrix that works on a 2-D coord if `xtrans` and `ytrans` are specified\n"
		"while it creates a matrix on a 3-D coord if `xtrans`, `ytrans` and `ztrans` are specified.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.translation(3, 4)\n"
		"    // x is a matrix to translate a 2-D coord by [3, 4].\n"
		"    x = array.translation(3, 4, -2)\n"
		"    // x is a matrix to translate a 3-D coord by [3, 4, -2].\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `float` elements:\n"
		"\n"
		"    array.translation(3, 4, elemtype => `float)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.translation` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@float.translation(3, 4\n");
}

template<typename T_Elem> Array *FuncTmpl_translation2D(Double xTrans, Double yTrans)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, 3, 3));
	T_Elem *p = pArrayT->GetPointer();
	// row-1
	*p++ = 1;
	*p++ = 0;
	*p++ = xTrans;
	// row-2
	*p++ = 0;
	*p++ = 1;
	*p++ = yTrans;
	// row-3
	*p++ = 0;
	*p++ = 0;
	*p++ = 1;
	return pArrayT.release();
}

template<typename T_Elem> Array *FuncTmpl_translation3D(Double xTrans, Double yTrans, Double zTrans)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, 4, 4));
	T_Elem *p = pArrayT->GetPointer();
	// row-1
	*p++ = 1;
	*p++ = 0;
	*p++ = 0;
	*p++ = xTrans;
	// row-2
	*p++ = 0;
	*p++ = 1;
	*p++ = 0;
	*p++ = yTrans;
	// row-3
	*p++ = 0;
	*p++ = 0;
	*p++ = 1;
	*p++ = zTrans;
	// row-4
	*p++ = 0;
	*p++ = 0;
	*p++ = 0;
	*p++ = 1;
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, translation)
{
	typedef Array *(*FuncT2D)(Double xTrans, Double yTrans);
	typedef Array *(*FuncT3D)(Double xTrans, Double yTrans, Double zTrans);
	DeclareFunctionTable1D(FuncT2D, funcTbl2D, FuncTmpl_translation2D);
	DeclareFunctionTable1D(FuncT3D, funcTbl3D, FuncTmpl_translation3D);
	Double xTrans = arg.GetDouble(0);
	Double yTrans = arg.GetDouble(1);
	AutoPtr<Array> pArray;
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(3)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(3)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	if (arg.IsValid(2)) {
		FuncT3D func = funcTbl3D[elemType];
		if (func == nullptr) {
			SetError_CreationError(env, elemType);
			return Value::Nil;
		}
		Double zTrans = arg.GetDouble(2);
		pArray.reset((*func)(xTrans, yTrans, zTrans));
	} else {
		FuncT2D func = funcTbl2D[elemType];
		if (func == nullptr) {
			SetError_CreationError(env, elemType);
			return Value::Nil;
		}
		pArray.reset((*func)(xTrans, yTrans));
	}
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

// array.zeros(dims[]:number, elemtype?:symbol):static:map {block?}
Gura_DeclareClassMethod_Array(array, zeros)
{
	SetFuncAttr(VTYPE_array, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	if (_elemType == Array::ETYPE_None) {
		DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	}
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array of `double` type of elements, which are initialized with zero.\n"
		"The argument `dims` specifies the dimension of the created array.\n"
		"\n"
		"Example:\n"
		"\n"
		"    x = array.zeros([3, 4])\n"
		"    // x is array@double {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array")
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The followings examples create an `array` instance of `int32` elements:\n"
		"\n"
		"    array.zeros([3, 4], elemtype => `int32)\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Methods named `array@T.zeros` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@int32.zeros([3, 4])\n");
}

template<typename T_Elem> Array *FuncTmpl_zeros(const ValueList &valList)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(new ArrayT<T_Elem>(colMajorFlag));
	pArrayT->SetDimensions(valList);
	pArrayT->AllocMemory();
	pArrayT->FillZero();
	return pArrayT.release();
}

Gura_ImplementClassMethod(array, zeros)
{
	typedef Array *(*FuncT)(const ValueList &valList);
	DeclareFunctionTable1D(FuncT, funcTbl, FuncTmpl_zeros);
	Array::ElemType elemType = (_elemType != Array::ETYPE_None)? _elemType :
		arg.IsValid(1)? Array::SymbolToElemTypeWithError(env, arg.GetSymbol(1)) :
		Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	FuncT func = funcTbl[elemType];
	if (func == nullptr) {
		SetError_CreationError(env, elemType);
		return Value::Nil;
	}
	AutoPtr<Array> pArray((*func)(arg.GetList(0)));
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

void AssignCreators(Environment &env)
{
	// assignment of array creators
	Gura_AssignMethodMultiple_Array(array, identity);
	Gura_AssignMethodMultiple_Array(array, interval);
	Gura_AssignMethodMultiple_Array(array, ones);
	Gura_AssignMethodMultiple_Array(array, rands);
	Gura_AssignMethodMultiple_Array(array, rands_at_normal);
	Gura_AssignMethodMultiple_Array(array, range);
	Gura_AssignMethodMultiple_Array(array, rotation);
	Gura_AssignMethodMultiple_Array(array, rotation_at_x);
	Gura_AssignMethodMultiple_Array(array, rotation_at_y);
	Gura_AssignMethodMultiple_Array(array, rotation_at_z);
	Gura_AssignMethodMultiple_Array(array, scaling);
	Gura_AssignMethodMultiple_Array(array, translation);
	Gura_AssignMethodMultiple_Array(array, zeros);
}

Gura_EndModuleScope(arrayt)
