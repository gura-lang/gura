//=============================================================================
// ArrayT
//=============================================================================
#include "stdafx.h"

namespace Gura {

//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------
template<typename T_Elem, typename T_ElemCast>
void DumpInteger(Signal &sig, Stream &stream, const char *fmt, size_t cols, const T_Elem *p, size_t n)
{
	size_t col = 0;
	for (size_t i = 0; i < n; i++, p++) {
		if (col != 0) {
			stream.Printf(sig, " ");
		}
		stream.Printf(sig, fmt, static_cast<T_ElemCast>(*p));
		col++;
		if (col == cols) {
			stream.Printf(sig, "\n");
			col = 0;
		}
	}
	if (col != 0) stream.Printf(sig, "\n");
}

template<typename T_Elem, typename T_ElemCast>
void DumpFloat(Signal &sig, Stream &stream, const char *fmt, size_t cols, const T_Elem *p, size_t n)
{
	size_t col = 0;
	for (size_t i = 0; i < n; i++, p++) {
		if (col != 0) {
			stream.Printf(sig, " ");
		}
		T_ElemCast num = *reinterpret_cast<const T_ElemCast *>(p);
		stream.Printf(sig, "%llx", num);
		stream.Printf(sig, fmt, num);
		col++;
		if (col == cols) {
			stream.Printf(sig, "\n");
			col = 0;
		}
	}
	if (col != 0) stream.Printf(sig, "\n");
}

//------------------------------------------------------------------------------
// ArrayT
//------------------------------------------------------------------------------
template<typename T_Elem>
ArrayT<T_Elem>::ArrayT() : Array()
{}

template<typename T_Elem>
ArrayT<T_Elem>::ArrayT(const ArrayT &src) : Array(src)
{}

template<typename T_Elem>
ArrayT<T_Elem>::ArrayT(Memory *pMemory) : Array(pMemory)
{}

template<typename T_Elem>
ArrayT<T_Elem>::ArrayT(size_t size) : Array()
{
	SetDimension(Dimension(size));
	AllocMemory();
}

template<typename T_Elem>
ArrayT<T_Elem>::ArrayT(size_t sizeRow, size_t sizeCol) : Array()
{
	SetDimension(Dimension(sizeRow), Dimension(sizeCol));
	AllocMemory();
}

template<typename T_Elem>
void ArrayT<T_Elem>::Fill(const T_Elem &num)
{
	T_Elem *p = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		*p = num;
	}
}

template<typename T_Elem>
void ArrayT<T_Elem>::FillZero()
{
	::memset(GetPointer(), 0x00, sizeof(T_Elem) * GetElemNum());
}

template<typename T_Elem>
bool ArrayT<T_Elem>::Paste(Signal &sig, size_t offset, const ArrayT *pArrayTSrc)
{
	if (GetElemNum() < offset + pArrayTSrc->GetElemNum()) {
		sig.SetError(ERR_OutOfRangeError, "out of range");
		return false;
	}
	::memcpy(GetPointer() + offset, pArrayTSrc->GetPointer(),
			 sizeof(T_Elem) * pArrayTSrc->GetElemNum());
	return true;
}

template<>
void ArrayT<Char>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Char, UChar>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetElemNum());
}

template<>
void ArrayT<UChar>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UChar, UChar>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Short>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Short, UShort>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetElemNum());
}

template<>
void ArrayT<UShort>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UShort, UShort>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Int32>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Int32, UInt32>(sig, stream, upperFlag? "%08X" : "%08x", 8, GetPointer(), GetElemNum());
}

template<> void ArrayT<UInt32>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt32, UInt32>(sig, stream, upperFlag? "%08X" : "%08x", 8, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Int64>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Int64, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetElemNum());
}

template<>
void ArrayT<UInt64>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt64, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetElemNum());
}

template<>
void ArrayT<float>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<float, ULong>(sig, stream, upperFlag? "%08lX" : "%08lx", 8, GetPointer(), GetElemNum());
}

template<>
void ArrayT<double>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<double, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetElemNum());
}

template<typename T_Elem>
void ArrayT<T_Elem>::CopyToList(ValueList &valList) const
{
	if (valList.empty()) valList.reserve(GetElemNum());
	const T_Elem *p = GetPointer();
	for (size_t nElems = GetElemNum(); nElems > 0; nElems--, p++) {
		valList.push_back(Value(*p));
	}
}

template<typename T_Elem>
T_Elem ArrayT<T_Elem>::Sum() const
{
	T_Elem rtn = 0;
	const T_Elem *p = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		rtn += *p;
	}
	return rtn;
}

template<typename T_Elem>
T_Elem ArrayT<T_Elem>::Average() const
{
	if (GetElemNum() == 0) return 0;
	return Sum() / GetElemNum();
}

// functions to create an ArrayT instance
template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateLike(const Array::Dimensions &dims)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimension(dims);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromList(const ValueList &valList)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(valList.size()));
	T_Elem *p = pArrayT->GetPointer();
	foreach_const (ValueList, pValue, valList) {
		*p++ = static_cast<T_Elem>(pValue->GetNumber());
	}
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromList(Signal &sig, const ValueList &valList)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(valList.size()));
	T_Elem *p = pArrayT->GetPointer();
	foreach_const (ValueList, pValue, valList) {
		if (!pValue->Is_number() && !pValue->Is_boolean()) {
			sig.SetError(ERR_ValueError, "element must be a number or a boolean");
			return nullptr;
		}
		*p++ = static_cast<T_Elem>(pValue->GetNumber());
	}
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromIterator(Environment &env, Iterator *pIterator)
{
	size_t len = pIterator->GetLengthEx(env);
	if (env.IsSignalled()) return nullptr;
	AutoPtr<ArrayT> pArrayT(new ArrayT(len));
	AutoPtr<Iterator> pIteratorWork(pIterator->Clone());
	T_Elem *p = pArrayT->GetPointer();
	Value value;
	while (pIteratorWork->Next(env, value)) {
		if (!value.Is_number() && !value.Is_boolean()) {
			env.SetError(ERR_ValueError, "element must be a number or a boolean");
			return nullptr;
		}
		*p++ = static_cast<T_Elem>(value.GetNumber());
	}
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateIdentity(size_t n)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(n, n));
	pArrayT->FillZero();
	T_Elem *p = pArrayT->GetPointer();
	size_t stride = n + 1;
	for (size_t i = 0; i < n; i++, p += stride) *p = 1;
	return pArrayT.release();
}

//-----------------------------------------------------------------------------
// Iterator_ArrayT_Each
//-----------------------------------------------------------------------------
template<typename T_Elem>
size_t Iterator_ArrayT_Each<T_Elem>::GetLength() const
{
	return _pArrayT->GetElemNum();
}

template<typename T_Elem>
Iterator *Iterator_ArrayT_Each<T_Elem>::GetSource()
{
	return nullptr;
}

template<typename T_Elem>
bool Iterator_ArrayT_Each<T_Elem>::DoNext(Environment &env, Value &value)
{
	if (_idx >= _pArrayT->GetElemNum()) return false;
	value = Value(*(_pArrayT->GetPointer() + _idx));
	_idx++;
	return true;
}

template<typename T_Elem>
String Iterator_ArrayT_Each<T_Elem>::ToString() const
{
	String rtn;
	rtn = "array";
	return rtn;
}

template<typename T_Elem>
void Iterator_ArrayT_Each<T_Elem>::GatherFollower(
	Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//------------------------------------------------------------------------------
// Instantiation of ArrayT
//------------------------------------------------------------------------------
template class ArrayT<Char>;
template class ArrayT<UChar>;
template class ArrayT<Short>;
template class ArrayT<UShort>;
template class ArrayT<Int32>;
template class ArrayT<UInt32>;
template class ArrayT<Int64>;
template class ArrayT<UInt64>;
template class ArrayT<Float>;
template class ArrayT<Double>;

//------------------------------------------------------------------------------
// Instantiation of Iterator_ArrayT_Each
//------------------------------------------------------------------------------
template class Iterator_ArrayT_Each<Char>;
template class Iterator_ArrayT_Each<UChar>;
template class Iterator_ArrayT_Each<Short>;
template class Iterator_ArrayT_Each<UShort>;
template class Iterator_ArrayT_Each<Int32>;
template class Iterator_ArrayT_Each<UInt32>;
template class Iterator_ArrayT_Each<Int64>;
template class Iterator_ArrayT_Each<UInt64>;
template class Iterator_ArrayT_Each<Float>;
template class Iterator_ArrayT_Each<Double>;

}
