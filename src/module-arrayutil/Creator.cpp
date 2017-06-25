#include "stdafx.h"

Gura_BeginModuleScope(arrayutil)

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

void AssignCreators(Environment &env)
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
}

Gura_EndModuleScope(arrayutil)
