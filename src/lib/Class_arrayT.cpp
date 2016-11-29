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

namespace Gura {

//-----------------------------------------------------------------------------
// Object_arrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
Object *Object_arrayT<T_Elem>::Clone() const
{
	return nullptr;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// array@T(src) {block?}
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
	DeclareArg(env, "src", VTYPE_any, OCCUR_Once);
	SetClassToConstruct(env.LookupClass(valType));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array@T` instance.\n"
		"You can call this function in the following formats:\n"
		"\n"
		"- `array@T(list:list)` .. Creates an `array@T` instance initialized with\n"
		"  numbers contained in the `list`.\n"
		"- `array@T(iter:iterator)` .. Creates an `array@T` instance initialized with\n"
		"  numbers generated by the `iterator`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array@T")
		);
}

template<typename T_Elem>
Value Func_arrayT<T_Elem>::DoEval(Environment &env, Argument &arg) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	if (arg.Is_list(0)) {
		const ValueList &valList = arg.GetList(0);
		pArrayT.reset(ArrayT<T_Elem>::CreateFromList(sig, valList));
		if (pArrayT.IsNull()) return Value::Nil;
	} else if (arg.Is_iterator(0)) {
		Iterator *pIterator = arg.GetIterator(0);
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return false;
		}
		pArrayT.reset(ArrayT<T_Elem>::CreateFromIterator(env, pIterator));
		if (pArrayT.IsNull()) return false;
	} else {
		Declaration::SetError_InvalidArgument(env);
		return Value::Nil;
	}
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// @T() {block}
template<typename T_Elem>
class Func_atT : public Function {
private:
	ValueType _valType;
public:
	Func_atT(Environment &env, const Symbol *pSymbol, ValueType valType);
	virtual Value DoEval(Environment &env, Argument &arg) const;
};
	
template<typename T_Elem>
Func_atT<T_Elem>::Func_atT(Environment &env, const Symbol *pSymbol, ValueType valType) :
	Function(env, pSymbol, FUNCTYPE_Function, FLAG_None), _valType(valType)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array@T` instance that is initialized with values described in `block`.\n"
		"\n"
		"The code below creates an `array@uint8` instance that has four elements.\n"
		"\n"
		"    @uint8 { 0x01, 0x23, 0x45, 0x67 }\n"
		"\n"
		"The code below creates an `array@uint16` instance that has three elements.\n"
		"\n"
		"    @uint16 { 0x0123, 0x4567, 0x89ab }\n"
		);
}

template<typename T_Elem>
Value Func_atT<T_Elem>::DoEval(Environment &env, Argument &arg) const
{
	Signal &sig = env.GetSignal();
	const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
	AutoPtr<Environment> pEnvLister(env.Derive(ENVTYPE_lister));
	Value result = pExprBlock->Exec(*pEnvLister, nullptr);
	if (!result.Is_list()) return Value::Nil;
	const ValueList &valList = result.GetList();
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::CreateFromList(sig, valList));
	if (pArrayT.IsNull()) return Value::Nil;
	//return Value(new Object_arrayT<T_Elem>(env, _valType, pArrayT.release()));
	return Value(new Object_array(env, pArrayT.release()));
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

// array@T.ones(dim+:number):static:map {block?}
Gura_DeclareClassMethod_arrayT(ones)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dim", VTYPE_number, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array with the specified dimensions, which elements are initialized by one.\n"
		);
}

Gura_ImplementClassMethod_arrayT(ones)
{
	AutoPtr<ArrayT<T_Elem> > pArrayT(new ArrayT<T_Elem>());
	Array::Dimensions &dims = pArrayT->GetDimensions();
	const ValueList &valList = arg.GetList(0);
	dims.reserve(dims.size());
	foreach_const (ValueList, pValue, valList) {
		dims.push_back(pValue->GetSizeT());
	}
	pArrayT->UpdateMetrics();
	pArrayT->AllocMemory();
	pArrayT->Fill(1);
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// array@T.zeros(dim+:number):static:map {block?}
Gura_DeclareClassMethod_arrayT(zeros)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "dim", VTYPE_number, OCCUR_OnceOrMore);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array with the specified dimensions, which elements are initialized by zero.\n"
		);
}

Gura_ImplementClassMethod_arrayT(zeros)
{
	AutoPtr<ArrayT<T_Elem> > pArrayT(new ArrayT<T_Elem>());
	Array::Dimensions &dims = pArrayT->GetDimensions();
	const ValueList &valList = arg.GetList(0);
	dims.reserve(dims.size());
	foreach_const (ValueList, pValue, valList) {
		dims.push_back(pValue->GetSizeT());
	}
	pArrayT->UpdateMetrics();
	pArrayT->AllocMemory();
	pArrayT->FillZero();
	Value value(new Object_array(env, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
template<typename T_Elem>
Class_arrayT<T_Elem>::Class_arrayT(Environment *pEnvOuter, ValueType valType) :
	Class(pEnvOuter, valType)
{
}

template<typename T_Elem>
void Class_arrayT<T_Elem>::Prepare(Environment &env)
{
	do {
		const Symbol *pSymbol = ValueTypePool::GetInstance()->
			Lookup(GetValueType())->GetSymbol();
		env.AssignFunction(new Func_arrayT<T_Elem>(env, pSymbol, GetValueType()));
	} while (0);
	do {
		String funcName;
		funcName += "@";
		funcName += ArrayT<T_Elem>::LookupElemTypeName();
		const Symbol *pSymbol = Symbol::Add(funcName.c_str());
		env.AssignFunction(new Func_atT<T_Elem>(env, pSymbol, GetValueType()));
	} while (0);
	Gura_AssignMethod_arrayT(identity);
	Gura_AssignMethod_arrayT(interval);
	Gura_AssignMethod_arrayT(ones);
	Gura_AssignMethod_arrayT(zeros);
}

template<typename T_Elem>
bool Class_arrayT<T_Elem>::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
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
		if (pArray->GetElemType() != ArrayT<T_Elem>::LookupElemType()) {
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
// Instantiation of Object_arrayT
//------------------------------------------------------------------------------
template class Object_arrayT<Int8>;
template class Object_arrayT<UInt8>;
template class Object_arrayT<Int16>;
template class Object_arrayT<UInt16>;
template class Object_arrayT<Int32>;
template class Object_arrayT<UInt32>;
template class Object_arrayT<Int64>;
template class Object_arrayT<UInt64>;
template class Object_arrayT<Float>;
template class Object_arrayT<Double>;

//------------------------------------------------------------------------------
// Instantiation of Class_arrayT
//------------------------------------------------------------------------------
template class Class_arrayT<Int8>;
template class Class_arrayT<UInt8>;
template class Class_arrayT<Int16>;
template class Class_arrayT<UInt16>;
template class Class_arrayT<Int32>;
template class Class_arrayT<UInt32>;
template class Class_arrayT<Int64>;
template class Class_arrayT<UInt64>;
template class Class_arrayT<Float>;
template class Class_arrayT<Double>;

}
