//=============================================================================
// Gura class: arrayT
//=============================================================================
#include "stdafx.h"
#include "gura/Class_arrayT.h"

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

template<typename T_Elem>
String Object_arrayT<T_Elem>::ToString(bool exprFlag)
{
	char buff[64];
	String str;
	str += "<";
	str += GetClassName();
	str += ":(";
	const Array::Dimensions &dims = _pArrayT->GetDimensions();
	foreach_const (Array::Dimensions, pDim, dims) {
		::sprintf(buff, (pDim == dims.begin())? "%ld" : ",%ld", pDim->GetCount());
		str += buff;
	}
	str += ")>";
	return str;
}

template<typename T_Elem>
Value Object_arrayT<T_Elem>::IndexGet(Environment &env, const Value &valueIdx)
{
	Signal &sig = GetSignal();
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_ValueError, "index must be a number");
		return Value::Nil;
	}
	const Array::Dimensions &dims = _pArrayT->GetDimensions();
	Array::Dimensions::const_iterator pDim = dims.begin();
	size_t idx = valueIdx.GetSizeT();
	if (idx >= pDim->GetCount()) {
		sig.SetError(ERR_OutOfRangeError, "index is out of range");
		return Value::Nil;
	}
	if (pDim + 1 == dims.end()) {
		return Value(_pArrayT->GetPointer()[idx]);
	}
	AutoPtr<ArrayT<T_Elem> > pArrayRtn(new ArrayT<T_Elem>(_pArrayT->GetMemory().Reference()));
	pArrayRtn->SetSize(pDim + 1, dims.end());
	pArrayRtn->SetOffsetBase(_pArrayT->GetOffsetBase() + pDim->GetStride() * idx);
	return Value(new Object_arrayT(GetClass(), pArrayRtn.release()));
}

template<typename T_Elem>
void Object_arrayT<T_Elem>::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
	Signal &sig = GetSignal();
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_ValueError, "index must be a number");
		return;
	}
	size_t idx = valueIdx.GetSizeT();
	if (idx >= _pArrayT->GetCountTotal()) {
		sig.SetError(ERR_OutOfRangeError, "index is out of range");
		return;
	}
	_pArrayT->GetPointer()[idx] = static_cast<T_Elem>(value.GetNumber());
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
	Value value(new Object_arrayT<T_Elem>(env, _valType, pArrayT.release()));
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
		"The code below creates an `array@uchar` instance that has four elements.\n"
		"\n"
		"    @uchar { 0x01, 0x23, 0x45, 0x67 }\n"
		"\n"
		"The code below creates an `array@ushort` instance that has three elements.\n"
		"\n"
		"    @ushort { 0x0123, 0x4567, 0x89ab }\n"
		);
}

template<typename T_Elem>
Value Func_atT<T_Elem>::DoEval(Environment &env, Argument &arg) const
{
	Signal &sig = env.GetSignal();
	const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
	const ExprOwner &exprOwner = pExprBlock->GetExprOwner();
	AutoPtr<ArrayT<T_Elem> > pArrayT(new ArrayT<T_Elem>(exprOwner.size()));
	T_Elem *p = pArrayT->GetPointer();
	foreach_const (ExprOwner, ppExpr, exprOwner) {
		const Expr *pExpr = *ppExpr;
		if (pExpr->IsBlock()) {
			sig.SetError(ERR_ValueError, "invalid element for array initialization");
			return Value::Nil;
		}
		Value value = pExpr->Exec(env);
		if (!value.Is_number() && !value.Is_boolean()) {
			sig.SetError(ERR_ValueError, "invalid element for array initialization");
			return Value::Nil;
		}
		*p++ = static_cast<T_Elem>(value.GetNumber());
	}
	return Value(new Object_arrayT<T_Elem>(env, _valType, pArrayT.release()));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// array@T#average() {block?}
Gura_DeclareMethod_arrayT(average)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates an average value of elements in the array.\n"
		);
}

Gura_ImplementMethod_arrayT(average)
{
	const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
	size_t cnt = pArrayT->GetCountTotal();
	return ReturnValue(env, arg, Value((cnt == 0)? 0 : pArrayT->Sum() / cnt));
}

// array@T#each() {block?}
Gura_DeclareMethod_arrayT(each)
{
	SetFuncAttr(VTYPE_iterator, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
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

Gura_ImplementMethod_arrayT(each)
{
	const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
	AutoPtr<Iterator> pIterator(new Iterator_ArrayT_Each<T_Elem>(pArrayT->Reference()));
	return ReturnIterator(env, arg, pIterator.release());
}

// array@T#dump():void
Gura_DeclareMethod_arrayT(dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(upper));
	AddHelp(
		Gura_Symbol(en),
		"Prints out a binary dump of the array's content.\n"
		);
}

Gura_ImplementMethod_arrayT(dump)
{
	Signal &sig = env.GetSignal();
	const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
	bool upperFlag = arg.IsSet(Gura_Symbol(upper));
	Stream *pStream = arg.IsValid(0)?
		&Object_stream::GetObject(arg, 0)->GetStream() : env.GetConsole();
	pArrayT->Dump(sig, *pStream, upperFlag);
	return Value::Nil;
}

// array@T#fill(value:number):void
Gura_DeclareMethod_arrayT(fill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Fills array with a specified value.\n"
		);
}

Gura_ImplementMethod_arrayT(fill)
{
	ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
	pArrayT->Fill(static_cast<T_Elem>(arg.GetNumber(0)));
	return Value::Nil;
}

// array@T#head(n:number):map {block?}
Gura_DeclareMethod_arrayT(head)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that has extracted specified number of elements\n"
		"from the beginning of the source.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter\n"
		"`|array:array@T|`, where `array` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n"
		);
}

Gura_ImplementMethod_arrayT(head)
{
	Signal &sig = env.GetSignal();
	const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
	size_t n = arg.GetSizeT(0);
	if (n > pArrayT->GetCountTotal()) {
		sig.SetError(ERR_OutOfRangeError, "offset is out of range");
		return Value::Nil;
	}
	size_t offsetBase = pArrayT->GetOffsetBase();
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(new ArrayT<T_Elem>(pArrayT->GetMemory().Reference()));
	pArrayTRtn->SetSize1D(n);
	pArrayTRtn->SetOffsetBase(offsetBase);
	Value value(new Object_arrayT<T_Elem>(env, _valType, pArrayTRtn.release()));
	return ReturnValue(env, arg, value);
}

// array@T#offset(n:number):map {block?}
Gura_DeclareMethod_arrayT(offset)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that has extracted elements of the source\n"
		"after skipping the first `n` elements.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter\n"
		"`|array:array@T|`, where `array` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n"
		);
}

Gura_ImplementMethod_arrayT(offset)
{
	Signal &sig = env.GetSignal();
	const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
	size_t n = arg.GetSizeT(0);
	if (n > pArrayT->GetCountTotal()) {
		sig.SetError(ERR_OutOfRangeError, "offset is out of range");
		return Value::Nil;
		}
	size_t cnt = pArrayT->GetCountTotal() - n;
	size_t offsetBase = pArrayT->GetOffsetBase() + n;
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(
		new ArrayT<T_Elem>(pArrayT->GetMemory().Reference()));
	pArrayTRtn->SetSize1D(cnt);
	pArrayTRtn->SetOffsetBase(offsetBase);
	Value value(new Object_arrayT<T_Elem>(env, _valType, pArrayTRtn.release()));
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
	Value value(new Object_arrayT<T_Elem>(env, _valType, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

// array@T#paste(offset:number, src:array):map:void
Gura_DeclareMethod_arrayT(paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "src", valType, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Pastes elements of `src` into the target `array` instance.\n"
		"\n"
		"The argument `offset` specifies the posision where elements are pasted in\n"
		);
}

Gura_ImplementMethod_arrayT(paste)
{
	Signal &sig = env.GetSignal();
	ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
	size_t offset = arg.GetSizeT(0);
	const ArrayT<T_Elem> *pArrayTSrc = Object_arrayT<T_Elem>::GetObject(arg, 1)->GetArrayT();
	pArrayT->Paste(sig, offset, pArrayTSrc);
	return Value::Nil;
}

// array@T#sum() {block?}
Gura_DeclareMethod_arrayT(sum)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a summation value of elements in the array.\n"
		);
}

Gura_ImplementMethod_arrayT(sum)
{
	const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
	return ReturnValue(env, arg, Value(pArrayT->Sum()));
}

// array@T#tail(n:number):map {block?}
Gura_DeclareMethod_arrayT(tail)
{
	SetFuncAttr(valType, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that has extracted specified number of elements\n"
		"from the bottom of the source.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter\n"
		"`|array:array@T|`, where `array` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n"
		);
}

Gura_ImplementMethod_arrayT(tail)
{
	Signal &sig = env.GetSignal();
	const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObjectThis(arg)->GetArrayT();
	size_t n = arg.GetSizeT(0);
	if (n > pArrayT->GetCountTotal()) {
		sig.SetError(ERR_OutOfRangeError, "offset is out of range");
		return Value::Nil;
	}
	size_t offsetBase = pArrayT->GetOffsetBase() + pArrayT->GetCountTotal() - n;
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(
		new ArrayT<T_Elem>(pArrayT->GetMemory().Reference()));
	pArrayTRtn->SetSize1D(n);
	pArrayTRtn->SetOffsetBase(offsetBase);
	Value value(new Object_arrayT<T_Elem>(env, _valType, pArrayTRtn.release()));
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
	Value value(new Object_arrayT<T_Elem>(env, _valType, pArrayT.release()));
	return ReturnValue(env, arg, value);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
template<typename T_Elem>
Class_arrayT<T_Elem>::Class_arrayT(
	Environment *pEnvOuter, ValueType valType, const String &elemName) :
	Class(pEnvOuter, valType), _elemName(elemName)
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
		funcName += _elemName;
		const Symbol *pSymbol = Symbol::Add(funcName.c_str());
		env.AssignFunction(new Func_atT<T_Elem>(env, pSymbol, GetValueType()));
	} while (0);
	Gura_AssignMethod_arrayT(average);
	Gura_AssignMethod_arrayT(dump);
	Gura_AssignMethod_arrayT(each);
	Gura_AssignMethod_arrayT(fill);
	Gura_AssignMethod_arrayT(head);
	Gura_AssignMethod_arrayT(offset);
	Gura_AssignMethod_arrayT(ones);
	Gura_AssignMethod_arrayT(paste);
	Gura_AssignMethod_arrayT(sum);
	Gura_AssignMethod_arrayT(tail);
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
		//pObjList->Reserve(pArrayT->GetCountTotal());
		pArrayT->CopyToList(pObjList->GetListForModify());
		pObjList->SetValueType(VTYPE_number);
		return true;
	} else if (decl.IsType(VTYPE_iterator)) {
		const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObject(value)->GetArrayT();
		AutoPtr<Iterator> pIterator(new Iterator_ArrayT_Each<T_Elem>(pArrayT->Reference()));
		value = Value(new Object_iterator(env, pIterator.release()));
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
// Instantiation of Object_arrayT
//------------------------------------------------------------------------------
template class Object_arrayT<Char>;
template class Object_arrayT<UChar>;
template class Object_arrayT<Short>;
template class Object_arrayT<UShort>;
template class Object_arrayT<Int32>;
template class Object_arrayT<UInt32>;
template class Object_arrayT<Int64>;
template class Object_arrayT<UInt64>;
template class Object_arrayT<float>;
template class Object_arrayT<double>;

//------------------------------------------------------------------------------
// Instantiation of Class_arrayT
//------------------------------------------------------------------------------
template class Class_arrayT<Char>;
template class Class_arrayT<UChar>;
template class Class_arrayT<Short>;
template class Class_arrayT<UShort>;
template class Class_arrayT<Int32>;
template class Class_arrayT<UInt32>;
template class Class_arrayT<Int64>;
template class Class_arrayT<UInt64>;
template class Class_arrayT<float>;
template class Class_arrayT<double>;

}
