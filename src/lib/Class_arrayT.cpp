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

}
