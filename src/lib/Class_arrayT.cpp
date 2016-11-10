//=============================================================================
// Gura class: arrayT
//=============================================================================
#include "stdafx.h"
#include "gura/Class_arrayT.h"

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
// Class_arrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
void Class_arrayT<T_Elem>::Prepare(Environment &env)
{
	do {
		const Symbol *pSymbol = ValueTypePool::GetInstance()->
			Lookup(GetValueType())->GetSymbol();
		env.AssignFunction(new Func_Constructor(env, pSymbol, GetValueType()));
	} while (0);
	do {
		String funcName;
		funcName += "@";
		funcName += _elemName;
		const Symbol *pSymbol = Symbol::Add(funcName.c_str());
		env.AssignFunction(new Func_Initializer(env, pSymbol, GetValueType()));
	} while (0);
	AssignFunction(new Func_average(*this, GetValueType()));
	AssignFunction(new Func_dump(*this, GetValueType()));
	AssignFunction(new Func_each(*this, GetValueType()));
	AssignFunction(new Func_fill(*this, GetValueType()));
	AssignFunction(new Func_head(*this, GetValueType()));
	AssignFunction(new Func_offset(*this, GetValueType()));
	AssignFunction(new Func_ones(*this, GetValueType()));
	AssignFunction(new Func_paste(*this, GetValueType()));
	AssignFunction(new Func_sum(*this, GetValueType()));
	AssignFunction(new Func_tail(*this, GetValueType()));
	AssignFunction(new Func_zeros(*this, GetValueType()));
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
