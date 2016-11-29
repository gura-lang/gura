//=============================================================================
// ArrayT
//=============================================================================
#include "stdafx.h"

//------------------------------------------------------------------------------
// Macros
//------------------------------------------------------------------------------
#define ImplementArrayT(T_Elem) \
template<> \
ArrayT<T_Elem>::ArrayT() : Array(ETYPE_##T_Elem) \
{} \
template<> \
ArrayT<T_Elem>::ArrayT(const ArrayT &src) : Array(ETYPE_##T_Elem, src) \
{} \
template<> \
ArrayT<T_Elem>::ArrayT(Memory *pMemory) : Array(ETYPE_##T_Elem, pMemory) \
{} \
template<> \
ArrayT<T_Elem>::ArrayT(size_t size) : Array(ETYPE_##T_Elem) \
{ \
	SetDimension(Dimension(size)); \
	AllocMemory(); \
} \
template<> \
ArrayT<T_Elem>::ArrayT(size_t sizeRow, size_t sizeCol) : Array(ETYPE_##T_Elem) \
{ \
	SetDimensions(Dimension(sizeRow), Dimension(sizeCol)); \
	AllocMemory(); \
} \
template class ArrayT<T_Elem>;

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

template<typename T_Elem> void FormatElem(char *buff, T_Elem x);

template<> void FormatElem(char *buff, Int8 x)		{ ::sprintf(buff, "%d", x); }
template<> void FormatElem(char *buff, UInt8 x)		{ ::sprintf(buff, "%u", x); }
template<> void FormatElem(char *buff, Int16 x)		{ ::sprintf(buff, "%d", x); }
template<> void FormatElem(char *buff, UInt16 x)	{ ::sprintf(buff, "%u", x); }
template<> void FormatElem(char *buff, Int32 x)		{ ::sprintf(buff, "%d", x); }
template<> void FormatElem(char *buff, UInt32 x)	{ ::sprintf(buff, "%u", x); }
template<> void FormatElem(char *buff, Int64 x)		{ ::sprintf(buff, "%lld", x); }
template<> void FormatElem(char *buff, UInt64 x)	{ ::sprintf(buff, "%llu", x); }
template<> void FormatElem(char *buff, Float x)		{ ::sprintf(buff, "%g", x); }
template<> void FormatElem(char *buff, Double x)	{ ::sprintf(buff, "%g", x); }
template<> void FormatElem(char *buff, Complex x)	{ ::sprintf(buff, "%g,%g", x.real(), x.imag()); }

//------------------------------------------------------------------------------
// ArrayT
//------------------------------------------------------------------------------
template<typename T_Elem>
void ToString_Sub(String &rtn, const Array::Dimensions &dims,
				  Array::Dimensions::const_iterator pDim, const T_Elem *&p)
{
	char buff[128];
	if (pDim + 1 == dims.end()) {
		rtn += "[";
		for (size_t i = 0; i < pDim->GetSize(); i++, p++) {
			if (i > 0) rtn += ", ";
			FormatElem(buff, *p);
			rtn += buff;
		}
		rtn += "]";
	} else {
		rtn += "[";
		for (size_t i = 0; i < pDim->GetSize(); i++) {
			if (i > 0) rtn += ", ";
			ToString_Sub(rtn, dims, pDim + 1, p);
		}
		rtn += "]";
	}
}

template<typename T_Elem>
String ArrayT<T_Elem>::ToString() const
{
	String rtn;
	rtn += LookupConstructorName();
	rtn += "(";
	const T_Elem *p = GetPointer();
	ToString_Sub(rtn, _dims, _dims.begin(), p);
	rtn += ")";
	return rtn;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::DoesContainZero() const
{
	const T_Elem *p = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		if (*p == 0) return true;
	}
	return false;
}

template<>
bool ArrayT<Complex>::DoesContainZero() const
{
	const Complex *p = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, p++) {
		if (p->real() == 0 && p->imag() == 0) return true;
	}
	return false;
}

template<> Array::ElemType ArrayT<Int8>::LookupElemType()		{ return ETYPE_Int8;	}
template<> Array::ElemType ArrayT<UInt8>::LookupElemType()		{ return ETYPE_UInt8;	}
template<> Array::ElemType ArrayT<Int16>::LookupElemType()		{ return ETYPE_Int16;	}
template<> Array::ElemType ArrayT<UInt16>::LookupElemType()		{ return ETYPE_UInt16;	}
template<> Array::ElemType ArrayT<Int32>::LookupElemType()		{ return ETYPE_Int32;	}
template<> Array::ElemType ArrayT<UInt32>::LookupElemType()		{ return ETYPE_UInt32;	}
template<> Array::ElemType ArrayT<Int64>::LookupElemType()		{ return ETYPE_Int64;	}
template<> Array::ElemType ArrayT<UInt64>::LookupElemType()		{ return ETYPE_UInt64;	}
template<> Array::ElemType ArrayT<Float>::LookupElemType()		{ return ETYPE_Float;	}
template<> Array::ElemType ArrayT<Double>::LookupElemType()		{ return ETYPE_Double;	}
template<> Array::ElemType ArrayT<Complex>::LookupElemType()	{ return ETYPE_Complex;	}

template<> const char *ArrayT<Int8>::LookupElemTypeName()		{ return "int8";	}
template<> const char *ArrayT<UInt8>::LookupElemTypeName()		{ return "uint8";	}
template<> const char *ArrayT<Int16>::LookupElemTypeName()		{ return "int16";	}
template<> const char *ArrayT<UInt16>::LookupElemTypeName()		{ return "uint16";	}
template<> const char *ArrayT<Int32>::LookupElemTypeName()		{ return "int32";	}
template<> const char *ArrayT<UInt32>::LookupElemTypeName()		{ return "uint32";	}
template<> const char *ArrayT<Int64>::LookupElemTypeName()		{ return "int64";	}
template<> const char *ArrayT<UInt64>::LookupElemTypeName()		{ return "uint64";	}
template<> const char *ArrayT<Float>::LookupElemTypeName()		{ return "float";	}
template<> const char *ArrayT<Double>::LookupElemTypeName()		{ return "double";	}
template<> const char *ArrayT<Complex>::LookupElemTypeName()	{ return "complex";	}

template<> const char *ArrayT<Int8>::LookupConstructorName()	{ return "array@int8";		}
template<> const char *ArrayT<UInt8>::LookupConstructorName()	{ return "array@uint8";		}
template<> const char *ArrayT<Int16>::LookupConstructorName()	{ return "array@int16";		}
template<> const char *ArrayT<UInt16>::LookupConstructorName()	{ return "array@uint16";	}
template<> const char *ArrayT<Int32>::LookupConstructorName()	{ return "array@int32";		}
template<> const char *ArrayT<UInt32>::LookupConstructorName()	{ return "array@uint32";	}
template<> const char *ArrayT<Int64>::LookupConstructorName()	{ return "array@int64";		}
template<> const char *ArrayT<UInt64>::LookupConstructorName()	{ return "array@uint64";	}
template<> const char *ArrayT<Float>::LookupConstructorName()	{ return "array@float";		}
template<> const char *ArrayT<Double>::LookupConstructorName()	{ return "array@double";	}
template<> const char *ArrayT<Complex>::LookupConstructorName() { return "array@complex";	}

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
void ArrayT<Int8>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Int8, UInt8>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetElemNum());
}

template<>
void ArrayT<UInt8>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt8, UInt8>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Int16>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Int16, UInt16>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetElemNum());
}

template<>
void ArrayT<UInt16>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<UInt16, UInt16>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetElemNum());
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

template<>
void ArrayT<Complex>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<Complex, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetElemNum() * 2);
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
	return static_cast<T_Elem>(Sum() / GetElemNum());
}

template<>
Complex ArrayT<Complex>::Average() const
{
	if (GetElemNum() == 0) return 0;
	return Sum() / static_cast<double>(GetElemNum());
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Flatten() const
{
	AutoPtr<ArrayT> pArrayRtn(new ArrayT(_pMemory->Reference()));
	pArrayRtn->SetOffsetBase(_offsetBase);
	pArrayRtn->SetDimension(Dimension(_elemNum));
	return pArrayRtn.release();
}

// functions to create an ArrayT instance
template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateLike(const Array::Dimensions &dims)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT());
	pArrayT->SetDimensions(dims);
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
bool CreateFromList_Sub(Signal &sig, Array::Dimensions &dims,
						Array::Dimensions::const_iterator pDim,
						T_Elem *&p, const ValueList &valList)
{
	if (pDim->GetSize() != valList.size()) {
		sig.SetError(ERR_ValueError, "incorrect number of elements");
		return false;
	}
	if (pDim + 1 == dims.end()) {
		if (valList.GetValueTypeOfElements() != VTYPE_number) {
			sig.SetError(ERR_ValueError, "invalid format of array initializer");
			return false;
		}
		foreach_const (ValueList, pValue, valList) {
			*p++ = static_cast<T_Elem>(pValue->GetNumber());
		}
	} else {
		if (valList.GetValueTypeOfElements() != VTYPE_list) {
			sig.SetError(ERR_ValueError, "invalid format of array initializer");
			return false;
		}
		foreach_const (ValueList, pValue, valList) {
			if (!CreateFromList_Sub(sig, dims, pDim + 1, p, pValue->GetList())) return false;
		}
	}
	return true;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromList(Signal &sig, const ValueList &valList)
{
	Array::Dimensions dims;
	for (const ValueList *pValList = &valList; ; ) {
		dims.push_back(Array::Dimension(pValList->size()));
		if (!pValList->front().Is_list()) break;
		pValList = &pValList->front().GetList();
	}
	AutoPtr<ArrayT> pArrayT(ArrayT::CreateLike(dims));
	T_Elem *p = pArrayT->GetPointer();
	if (!CreateFromList_Sub(sig, dims, dims.begin(), p, valList)) return nullptr;
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

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateInterval(
	Double numBegin, Double numEnd, int numSamples, Double numDenom, int iFactor)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(numSamples));
	T_Elem *p = pArrayT->GetPointer();
	for (int i = 0; i < numSamples; i++, iFactor++) {
		p[i] = static_cast<T_Elem>((numEnd - numBegin) * iFactor / numDenom + numBegin);
	}
	return pArrayT.release();
}

//-----------------------------------------------------------------------------
// Iterator_ArrayT_Each
//-----------------------------------------------------------------------------
template<typename T_Elem>
size_t Iterator_ArrayT_Each<T_Elem>::GetLength() const
{
	return _flatFlag? _pArrayT->GetElemNum() : _pArrayT->GetDimensions().front().GetSize();
}

template<typename T_Elem>
Iterator *Iterator_ArrayT_Each<T_Elem>::GetSource()
{
	return nullptr;
}

template<typename T_Elem>
bool Iterator_ArrayT_Each<T_Elem>::DoNext(Environment &env, Value &value)
{
	if (_flatFlag) {
		if (_idx >= _pArrayT->GetElemNum()) return false;
		value = Value(_pArrayT->GetPointer()[_idx]);
	} else {
		const Array::Dimensions &dims = _pArrayT->GetDimensions();
		Array::Dimensions::const_iterator pDim = dims.begin();
		if (_idx >= pDim->GetSize()) return false;
		if (pDim + 1 == dims.end()) {
			value = Value(_pArrayT->GetPointer()[_idx]);
		} else {
			AutoPtr<ArrayT<T_Elem> > pArrayRtn(new ArrayT<T_Elem>(_pArrayT->GetMemory().Reference()));
			pArrayRtn->SetDimensions(pDim + 1, dims.end());
			pArrayRtn->SetOffsetBase(_pArrayT->GetOffsetBase() + pDim->GetStride() * _idx);
			value = Value(new Object_array(env, pArrayRtn.release()));
		}
	}
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
// Implementation of ArrayT
//------------------------------------------------------------------------------
ImplementArrayT(Int8)
ImplementArrayT(UInt8)
ImplementArrayT(Int16)
ImplementArrayT(UInt16)
ImplementArrayT(Int32)
ImplementArrayT(UInt32)
ImplementArrayT(Int64)
ImplementArrayT(UInt64)
ImplementArrayT(Float)
ImplementArrayT(Double)
ImplementArrayT(Complex)

//------------------------------------------------------------------------------
// Implementation of Iterator_ArrayT_Each
//------------------------------------------------------------------------------
template class Iterator_ArrayT_Each<Int8>;
template class Iterator_ArrayT_Each<UInt8>;
template class Iterator_ArrayT_Each<Int16>;
template class Iterator_ArrayT_Each<UInt16>;
template class Iterator_ArrayT_Each<Int32>;
template class Iterator_ArrayT_Each<UInt32>;
template class Iterator_ArrayT_Each<Int64>;
template class Iterator_ArrayT_Each<UInt64>;
template class Iterator_ArrayT_Each<Float>;
template class Iterator_ArrayT_Each<Double>;

}
