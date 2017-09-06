//=============================================================================
// Gura class: arrayT
//=============================================================================
#include "stdafx.h"

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
	return Array::ToValue(env, pArrayT.release());
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
		"or from elements described in the block.\n"
		"\n"
		"Example:\n"
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
}

template<typename T_Elem>
bool Class_arrayT<T_Elem>::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
	if (value.Is_list()) {
		AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::CreateFromList(env, value.GetList()));
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
			env.SetError(ERR_TypeError, "incompatible array type");
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
		pArrayT->CopyToList(pObjList);
		return true;
	} else if (decl.IsType(VTYPE_iterator)) {
		const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObject(value)->GetArrayT();
		AutoPtr<Iterator> pIterator(new Iterator_ArrayT_Each<T_Elem>(pArrayT->Reference(), false));
		value = Value(new Object_iterator(env, pIterator.release()));
		return true;
	} else if (decl.IsType(VTYPE_array)) {
		const ArrayT<T_Elem> *pArrayT = Object_arrayT<T_Elem>::GetObject(value)->GetArrayT();
		AutoPtr<Array> pArray(pArrayT->Reference());
		value = Array::ToValue(env, pArray.release());
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
// Realization of Object_arrayT
//------------------------------------------------------------------------------
template class Object_arrayT<Boolean>;
template class Object_arrayT<Int8>;
template class Object_arrayT<UInt8>;
template class Object_arrayT<Int16>;
template class Object_arrayT<UInt16>;
template class Object_arrayT<Int32>;
template class Object_arrayT<UInt32>;
template class Object_arrayT<Int64>;
template class Object_arrayT<UInt64>;
template class Object_arrayT<Half>;
template class Object_arrayT<Float>;
template class Object_arrayT<Double>;
template class Object_arrayT<Complex>;
//template class Object_arrayT<Value>;

//------------------------------------------------------------------------------
// Realization of Class_arrayT
//------------------------------------------------------------------------------
template class Class_arrayT<Boolean>;
template class Class_arrayT<Int8>;
template class Class_arrayT<UInt8>;
template class Class_arrayT<Int16>;
template class Class_arrayT<UInt16>;
template class Class_arrayT<Int32>;
template class Class_arrayT<UInt32>;
template class Class_arrayT<Int64>;
template class Class_arrayT<UInt64>;
template class Class_arrayT<Half>;
template class Class_arrayT<Float>;
template class Class_arrayT<Double>;
template class Class_arrayT<Complex>;
//template class Class_arrayT<Value>;

}
