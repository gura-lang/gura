//=============================================================================
// Gura class: arrayT
//=============================================================================
#include "stdafx.h"

#define Gura_DeclareMethodAlias_arrayT(name, nameAlias) \
template<typename T_Elem> class Func_arrayT__##name : public Function { \
private: \
	ValueType _valType; \
public: \
	Func_arrayT__##name(Environment &env, ValueType valType); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
template<typename T_Elem> \
Func_arrayT__##name<T_Elem>::Func_arrayT__##name(Environment &env, ValueType valType) : \
	Function(env, Symbol::Add(nameAlias), FUNCTYPE_Instance, FLAG_None), _valType(valType)

#define Gura_DeclareMethod_arrayT(name) Gura_DeclareMethodAlias_arrayT(name, #name)

#define Gura_DeclareClassMethodAlias_arrayT(name, nameAlias) \
template<typename T_Elem> class Func_arrayT__##name : public Function { \
private: \
	ValueType _valType; \
public: \
	Func_arrayT__##name(Environment &env, ValueType valType); \
	virtual Value DoEval(Environment &env, Argument &arg) const; \
}; \
template<typename T_Elem> \
Func_arrayT__##name<T_Elem>::Func_arrayT__##name(Environment &env, ValueType valType) : \
	Function(env, Symbol::Add(nameAlias), FUNCTYPE_Class, FLAG_None), _valType(valType)

#define Gura_DeclareClassMethod_arrayT(name) Gura_DeclareClassMethodAlias_arrayT(name, #name)

#define Gura_ImplementMethod_arrayT(name) \
template<typename T_Elem> \
Value Func_arrayT__##name<T_Elem>::DoEval(Environment &env, Argument &arg) const

#define Gura_ImplementClassMethod_arrayT(name) Gura_ImplementMethod_arrayT(name)

#define Gura_AssignMethod_arrayT(name) \
AssignFunction(new Func_arrayT__##name<T_Elem>(*this, GetValueType()))

#define Gura_AssignMethodTo_arrayT(pClass, name, T_Elem, valType)	\
pClass->AssignFunction(new Func_arrayT__##name<T_Elem>(*this, valType))

namespace Gura {

//-----------------------------------------------------------------------------
// Object_arrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
Object *Object_arrayT<T_Elem>::Clone() const
{
	return nullptr;
}

template<typename T_Elem>
Value Object_arrayT<T_Elem>::Constructor(Environment &env, Argument &arg)
{
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	if (arg.IsValid(0)) {
		pArrayT.reset(ArrayT<T_Elem>::CreateFromValue(env, arg.GetValue(0)));
	} else if (arg.IsBlockSpecified()) {
		pArrayT.reset(ArrayT<T_Elem>::CreateFromExpr(env, arg.GetBlockCooked(env)));
	} else {
		env.SetError(ERR_SyntaxError, "argument or block must be specified");
		return Value::Nil;
	}
	if (pArrayT.IsNull()) return Value::Nil;
	return Value(new Object_array(env, pArrayT.release()));
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// array@T(src?) {block?}
template<typename T_Elem>
class Func_arrayT : public Function {
private:
	ValueType _valType;
public:
	Func_arrayT(Environment &env, const Symbol *pSymbol, ValueType valType);
	virtual Value DoEval(Environment &env, Argument &arg) const;
};

template<typename T_Elem>
Func_arrayT<T_Elem>::Func_arrayT(Environment &env, const Symbol *pSymbol, ValueType valType) :
	Function(env, pSymbol, FUNCTYPE_Function, FLAG_None), _valType(valType)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src", VTYPE_any, OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(valType));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array@T` instance from a `list` or an `iterator` specified in the argument `src`,\n"
		"or elements described in a block. Below are examples:\n"
		"\n"
		"    array@int32 ([[0, 1, 2], [3, 4, 5]])\n"
		"    array@int32 {{0, 1, 2}, {3, 4, 5}}\n"
		);
}

template<typename T_Elem>
Value Func_arrayT<T_Elem>::DoEval(Environment &env, Argument &arg) const
{
	return Object_arrayT<T_Elem>::Constructor(env, arg);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// array@T.identity(n:number):static:map {block?}
Gura_DeclareClassMethod_arrayT(identity)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that represents a identity matrix with specified size.\n"
		);
}

Gura_ImplementClassMethod_arrayT(identity)
{
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::CreateIdentity(arg.GetSizeT(0)));
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// array@T.interval(begin:number, end:number, samples:number):static:map:[open,open_l,open_r] {block?}
Gura_DeclareClassMethod_arrayT(interval)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "begin", VTYPE_number);
	DeclareArg(env, "end", VTYPE_number);
	DeclareArg(env, "samples", VTYPE_number);
	DeclareAttr(Gura_Symbol(open));
	DeclareAttr(Gura_Symbol(open_l));
	DeclareAttr(Gura_Symbol(open_r));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that contains a sequence of numbers\n"
		"by specifying the beginning and ending numbers, and the number of samples between them.\n"
		"\n"
		"In default, it creates a sequence that contains the beginning and ending numbers.\n"
		"Following attributes would generate the following numbers:\n"
		"\n"
		"- `:open` .. Numbers in range of `(begin, end)` that doesn't contain either `begin` or `end`.\n"
		"- `:open_l` .. Numbers in range of `(begin, end]` that doesn't contain `begin`.\n"
		"- `:open_r` .. Numbers in range of `[begin, end)` that doesn't contain `end`.\n");
}

Gura_ImplementClassMethod_arrayT(interval)
{
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
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::CreateInterval(
										 numBegin, numEnd, numSamples, numDenom, iFactor));
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// array@T.ones(dims[]:number):static:map {block?}
Gura_DeclareClassMethod_arrayT(ones)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array with the specified dimensions, which elements are initialized by one.\n"
		);
}

Gura_ImplementClassMethod_arrayT(ones)
{
	Value value(new Object_array(env, ArrayT<T_Elem>::CreateOnes(arg.GetList(0))));
	return ReturnValue(env, arg, value);
}

// array@T.rands(dims[]:number, range?:number):static:map {block?}
Gura_DeclareClassMethod_arrayT(rands)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "range", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array with the specified dimensions, which contains random numbers.\n"
		);
}

Gura_ImplementClassMethod_arrayT(rands)
{
	UInt range = arg.IsValid(1)? arg.GetUInt(1) : 0;
	Value value(new Object_array(env, ArrayT<T_Elem>::CreateRands(arg.GetList(0), range)));
	return ReturnValue(env, arg, value);
}

// array@T.rands@normal(dims[]:number, mu?:number, sigma?:number):static:map {block?}
Gura_DeclareClassMethodAlias_arrayT(rands_at_normal, "rands@normal")
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "mu", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "sigma", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array with the specified dimensions,\n"
		"which contains normal distribution random numbers.\n"
		);
}

Gura_ImplementClassMethod_arrayT(rands_at_normal)
{
	double mu = arg.IsValid(1)? arg.GetDouble(1) : 0;
	double sigma = arg.IsValid(2)? arg.GetDouble(2) : 1;
	Value value(new Object_array(env, ArrayT<T_Elem>::CreateRandsNormal(
									 arg.GetList(0), mu, sigma)));
	return ReturnValue(env, arg, value);
}

// array@T.range(num:number, num_end?:number, step?:number):static:map {block?}
Gura_DeclareClassMethod_arrayT(range)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "num", VTYPE_number);
	DeclareArg(env, "num_end", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "step", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that contains a sequence of integer numbers.\n"
		"\n"
		"This function can be called in three formats that generate following numbers:\n"
		"\n"
		"- array@T.range(num) .. Numbers between 0 and (num - 1).\n"
		"- array@T.range(num, num_end) .. Numbers between num and (num_end - 1).\n"
		"- array@T.range(num, num_end, step) .. Numbers between num and (num_end - 1) incremented by step.\n");
}

Gura_ImplementClassMethod_arrayT(range)
{
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
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::CreateRange(numBegin, numEnd, numStep));
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayT.release())));
}

// array@T.rotation(angle:number, xtrans?:number, ytrans?:number):static:map:[deg] {block?}
Gura_DeclareClassMethod_arrayT(rotation)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
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

Gura_ImplementClassMethod_arrayT(rotation)
{
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	if (arg.IsValid(1) || arg.IsValid(2)) {
		T_Elem xTrans = arg.IsValid(1)? static_cast<T_Elem>(arg.GetDouble(1)) : 0;
		T_Elem yTrans = arg.IsValid(2)? static_cast<T_Elem>(arg.GetDouble(2)) : 0;
		pArrayT.reset(ArrayT<T_Elem>::CreateRotation(angle, true, xTrans, yTrans));
	} else {
		pArrayT.reset(ArrayT<T_Elem>::CreateRotation(angle, false, 0, 0));
	}
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// array@T.rotation@x(angle:number, xtrans?:number, ytrans?:number, ztrans?:number):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias_arrayT(rotation_at_x, "rotation@x")
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
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

Gura_ImplementClassMethod_arrayT(rotation_at_x)
{
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	if (arg.IsValid(1) || arg.IsValid(2) || arg.IsValid(3)) {
		T_Elem xTrans = arg.IsValid(1)? static_cast<T_Elem>(arg.GetDouble(1)) : 0;
		T_Elem yTrans = arg.IsValid(2)? static_cast<T_Elem>(arg.GetDouble(2)) : 0;
		T_Elem zTrans = arg.IsValid(3)? static_cast<T_Elem>(arg.GetDouble(3)) : 0;
		pArrayT.reset(ArrayT<T_Elem>::CreateRotationX(angle, true, xTrans, yTrans, zTrans));
	} else {
		pArrayT.reset(ArrayT<T_Elem>::CreateRotationX(angle, false, 0, 0, 0));
	}
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// array@T.rotation@y(angle:number, xtrans?:number, ytrans?:number, ztrans?:number):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias_arrayT(rotation_at_y, "rotation@y")
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
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

Gura_ImplementClassMethod_arrayT(rotation_at_y)
{
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	if (arg.IsValid(1) || arg.IsValid(2) || arg.IsValid(3)) {
		T_Elem xTrans = arg.IsValid(1)? static_cast<T_Elem>(arg.GetDouble(1)) : 0;
		T_Elem yTrans = arg.IsValid(2)? static_cast<T_Elem>(arg.GetDouble(2)) : 0;
		T_Elem zTrans = arg.IsValid(3)? static_cast<T_Elem>(arg.GetDouble(3)) : 0;
		pArrayT.reset(ArrayT<T_Elem>::CreateRotationY(angle, true, xTrans, yTrans, zTrans));
	} else {
		pArrayT.reset(ArrayT<T_Elem>::CreateRotationY(angle, false, 0, 0, 0));
	}
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// array@T.rotation@z(angle:number, xtrans?:number, ytrans?:number, ztrans?:number):static:map:[deg] {block?}
Gura_DeclareClassMethodAlias_arrayT(rotation_at_z, "rotation@z")
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "angle", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
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

Gura_ImplementClassMethod_arrayT(rotation_at_z)
{
	double angle = arg.GetDouble(0);
	if (arg.IsSet(Gura_Symbol(deg))) angle = DegToRad(angle);
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	if (arg.IsValid(1) || arg.IsValid(2) || arg.IsValid(3)) {
		T_Elem xTrans = arg.IsValid(1)? static_cast<T_Elem>(arg.GetDouble(1)) : 0;
		T_Elem yTrans = arg.IsValid(2)? static_cast<T_Elem>(arg.GetDouble(2)) : 0;
		T_Elem zTrans = arg.IsValid(3)? static_cast<T_Elem>(arg.GetDouble(3)) : 0;
		pArrayT.reset(ArrayT<T_Elem>::CreateRotationZ(angle, true, xTrans, yTrans, zTrans));
	} else {
		pArrayT.reset(ArrayT<T_Elem>::CreateRotationZ(angle, false, 0, 0, 0));
	}
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// array@T.scaling(xscale:number, yscale:number, zscale?:number):static:map {block?}
Gura_DeclareClassMethod_arrayT(scaling)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "xscale", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "yscale", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "zscale", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that scales coords.\n"
		"If the argument `zscale` is specified, it would create an array that works with 3-D coords.\n"
		"Otherwise, it would create what works with 2-D coord.n"
		);
}

Gura_ImplementClassMethod_arrayT(scaling)
{
	T_Elem xScale = static_cast<T_Elem>(arg.GetDouble(0));
	T_Elem yScale = static_cast<T_Elem>(arg.GetDouble(1));
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	if (arg.IsValid(2)) {
		T_Elem zScale = static_cast<T_Elem>(arg.GetDouble(2));
		pArrayT.reset(ArrayT<T_Elem>::CreateScaling3D(xScale, yScale, zScale));
	} else {
		pArrayT.reset(ArrayT<T_Elem>::CreateScaling2D(xScale, yScale));
	}
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// array@T.translation(xtrans:number, ytrans:number, ztrans?:number):static:map {block?}
Gura_DeclareClassMethod_arrayT(translation)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "xtrans", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ytrans", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "ztrans", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that translates coords.\n"
		"If the argument `ztrans` is specified, it would create an array that works with 3-D coords.\n"
		"Otherwise, it would create what works with 2-D coords.n"
		);
}

Gura_ImplementClassMethod_arrayT(translation)
{
	T_Elem xTrans = static_cast<T_Elem>(arg.GetDouble(0));
	T_Elem yTrans = static_cast<T_Elem>(arg.GetDouble(1));
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	if (arg.IsValid(2)) {
		T_Elem zTrans = static_cast<T_Elem>(arg.GetDouble(2));
		pArrayT.reset(ArrayT<T_Elem>::CreateTranslation3D(xTrans, yTrans, zTrans));
	} else {
		pArrayT.reset(ArrayT<T_Elem>::CreateTranslation2D(xTrans, yTrans));
	}
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// array@T.zeros(dims[]:number):static:map {block?}
Gura_DeclareClassMethod_arrayT(zeros)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array with the specified dimensions, which elements are initialized by zero.\n"
		);
}

Gura_ImplementClassMethod_arrayT(zeros)
{
	Value value(new Object_array(env, ArrayT<T_Elem>::CreateZeros(arg.GetList(0))));
	return ReturnValue(env, arg, value);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
template<typename T_Elem>
Class_arrayT<T_Elem>::Class_arrayT(Environment *pEnvOuter, ValueType valType) :
	ClassFundamental(pEnvOuter, valType)
{
}

template<typename T_Elem>
void Class_arrayT<T_Elem>::DoPrepare(Environment &env)
{
	do {
		const Symbol *pSymbol = ValueTypePool::GetInstance()->
			Lookup(GetValueType())->GetSymbol();
		env.AssignFunction(new Func_arrayT<T_Elem>(env, pSymbol, GetValueType()));
	} while (0);
	Gura_AssignMethod_arrayT(identity);
	Gura_AssignMethod_arrayT(interval);
	Gura_AssignMethod_arrayT(ones);
	Gura_AssignMethod_arrayT(rands);
	Gura_AssignMethod_arrayT(rands_at_normal);
	Gura_AssignMethod_arrayT(range);
	Gura_AssignMethod_arrayT(rotation);
	Gura_AssignMethod_arrayT(rotation_at_x);
	Gura_AssignMethod_arrayT(rotation_at_y);
	Gura_AssignMethod_arrayT(rotation_at_z);
	Gura_AssignMethod_arrayT(scaling);
	Gura_AssignMethod_arrayT(translation);
	Gura_AssignMethod_arrayT(zeros);
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
}

template<typename T_Elem>
bool Class_arrayT<T_Elem>::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
	if (value.Is_list()) {
		AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::CreateFromList(sig, value.GetList()));
		if (pArrayT.IsNull()) return false;
		value = Value(new Object_arrayT<T_Elem>(env, GetValueType(), pArrayT.release()));
		return true;
	} else if (value.Is_iterator()) {
		Iterator *pIterator = value.GetIterator();
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return false;
		}
		AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::CreateFromIterator(
											 env, pIterator));
		if (pArrayT.IsNull()) return false;
		value = Value(new Object_arrayT<T_Elem>(env, GetValueType(), pArrayT.release()));
		return true;
	} else if (value.Is_array()) {
		AutoPtr<Array> pArray(Object_array::GetObject(value)->GetArray()->Reference());
		if (pArray->GetElemType() != ArrayT<T_Elem>::ElemTypeThis) {
			sig.SetError(ERR_TypeError, "incompatible array type");
			return false;
		}
		value = Value(new Object_arrayT<T_Elem>(env, GetValueType(), pArray.release()));
		return true;
	}
	return false;
}

template<typename T_Elem>
bool Class_arrayT<T_Elem>::CastTo(Environment &env, Value &value, const Declaration &decl)
{
	if (decl.IsType(VTYPE_list)) {
		AutoPtr<ArrayT<T_Elem> > pArrayT(
			Object_arrayT<T_Elem>::GetObject(value)->GetArrayT()->Reference());
		Object_list *pObjList = value.InitAsList(env);
		pArrayT->CopyToList(pObjList->GetListForModify());
		pObjList->SetValueType(VTYPE_number);
		return true;
	} else if (decl.IsType(VTYPE_iterator)) {
		const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObject(value)->GetArrayT();
		AutoPtr<Iterator> pIterator(new Iterator_ArrayT_Each<T_Elem>(pArrayT->Reference(), false));
		value = Value(new Object_iterator(env, pIterator.release()));
		return true;
	} else if (decl.IsType(VTYPE_array)) {
		const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObject(value)->GetArrayT();
		AutoPtr<Array> pArray(pArrayT->Reference());
		value = Value(new Object_array(env, pArray.release()));
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
// Realization of Object_arrayT
//------------------------------------------------------------------------------
template class Object_arrayT<Int8>;
template class Object_arrayT<UInt8>;
template class Object_arrayT<Int16>;
template class Object_arrayT<UInt16>;
template class Object_arrayT<Int32>;
template class Object_arrayT<UInt32>;
template class Object_arrayT<Int64>;
template class Object_arrayT<UInt64>;
//template class Object_arrayT<Half>;
template class Object_arrayT<Float>;
template class Object_arrayT<Double>;
template class Object_arrayT<Complex>;

//------------------------------------------------------------------------------
// Realization of Class_arrayT
//------------------------------------------------------------------------------
template class Class_arrayT<Int8>;
template class Class_arrayT<UInt8>;
template class Class_arrayT<Int16>;
template class Class_arrayT<UInt16>;
template class Class_arrayT<Int32>;
template class Class_arrayT<UInt32>;
template class Class_arrayT<Int64>;
template class Class_arrayT<UInt64>;
//template class Class_arrayT<Half>;
template class Class_arrayT<Float>;
template class Class_arrayT<Double>;
template class Class_arrayT<Complex>;

}
