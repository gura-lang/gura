//=============================================================================
// ArrayT
//=============================================================================
#include "stdafx.h"

//------------------------------------------------------------------------------
// Macros
//------------------------------------------------------------------------------
#define ImplementArrayT(T_Elem) \
template<> \
ArrayT<T_Elem>::ArrayT(bool colMajorFlag) : Array(ETYPE_##T_Elem, colMajorFlag) {} \
template class ArrayT<T_Elem>;

namespace Gura {

//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------
template<typename T_Elem> void FormatElem(char *buff, int wdPad, const T_Elem &x);

template<> void FormatElem(char *buff, int wdPad, const Boolean &x) {
	::sprintf(buff, "%*s", wdPad, x? "true" : "false");
}

template<> void FormatElem(char *buff, int wdPad, const Int8 &x) {
	::sprintf(buff, "%*d", wdPad, x);
}

template<> void FormatElem(char *buff, int wdPad, const UInt8 &x) {
	::sprintf(buff, "%*u", wdPad, x);
}

template<> void FormatElem(char *buff, int wdPad, const Int16 &x) {
	::sprintf(buff, "%*d", wdPad, x);
}

template<> void FormatElem(char *buff, int wdPad, const UInt16 &x) {
	::sprintf(buff, "%*u", wdPad, x);
}

template<> void FormatElem(char *buff, int wdPad, const Int32 &x) {
	::sprintf(buff, "%*d", wdPad, x);
}

template<> void FormatElem(char *buff, int wdPad, const UInt32 &x) {
	::sprintf(buff, "%*u", wdPad, x);
}

template<> void FormatElem(char *buff, int wdPad, const Int64 &x) {
	::sprintf(buff, "%*lld", wdPad, x);
}

template<> void FormatElem(char *buff, int wdPad, const UInt64 &x) {
	::sprintf(buff, "%*llu", wdPad, x);
}

template<> void FormatElem(char *buff, int wdPad, const Half &x) {
	::sprintf(buff, "%*g", wdPad, static_cast<Float>(x));
}

template<> void FormatElem(char *buff, int wdPad, const Float &x) {
	::sprintf(buff, "%*g", wdPad, x);
}

template<> void FormatElem(char *buff, int wdPad, const Double &x) {
	::sprintf(buff, "%*g", wdPad, x);
}

template<> void FormatElem(char *buff, int wdPad, const Complex &x) {
	char tmp[128];
	if (x.real() == 0) {
		if (x.imag() == 0) {
			::sprintf(tmp, "0");
		} else {
			::sprintf(tmp, "%gj", x.imag());
		}
	} else {
		if (x.imag() == 0) {
			::sprintf(tmp, "%g", x.real());
		} else {
			::sprintf(tmp, "%g%+gj", x.real(), x.imag());
		}
	}
	::sprintf(buff, "%*s", wdPad, tmp);
}

//------------------------------------------------------------------------------
// ArrayT
//------------------------------------------------------------------------------
template<typename T_Elem>
Array *ArrayT<T_Elem>::Clone() const
{
	return new ArrayT<T_Elem>(*this);
}	

template<typename T_Elem>
void ToString_Sub(String &rtn, size_t colTop, int wdPad, const Array::Dimensions &dims,
				  Array::Dimensions::const_iterator pDim, const T_Elem *pElem)
{
	char buff[128];
	size_t nestLevel = std::distance(dims.begin(), pDim);
	if (pDim + 1 == dims.end()) {
		rtn += "{";
		for (size_t i = 0; i < pDim->GetSize(); i++, pElem += pDim->GetStrides()) {
			if (i > 0) rtn += ", ";
			FormatElem(buff, wdPad, *pElem);
			rtn += buff;
		}
		rtn += "}";
	} else {
		rtn += "{";
		for (size_t i = 0; i < pDim->GetSize(); i++, pElem += pDim->GetStrides()) {
			if (i > 0) {
				rtn += ',';
				rtn += '\n';
				for (size_t j = 0; j < dims.size() - nestLevel - 2; j++) rtn += '\n';
				for (size_t j = 0; j < nestLevel + colTop + 1; j++) rtn += ' ';
			}
			ToString_Sub(rtn, colTop, wdPad, dims, pDim + 1, pElem);
		}
		rtn += "}";
	}
}

template<typename T_Elem>
String ArrayT<T_Elem>::ToString(bool exprFlag) const
{
	String rtn;
	char buff[128];
	const T_Elem *pElem = GetPointer();
	if (IsScalar()) {
		FormatElem(buff, 0, *pElem);
		rtn = buff;
	} else {
		int wdPad = 0;
		for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
			FormatElem(buff, wdPad, *pElem);
			int wdElem = ::strlen(buff);
			if (wdPad < wdElem) wdPad = wdElem;
		}
		pElem = GetPointer();
		if (exprFlag) {
			rtn += ConstructorName;
			rtn += " ";
			ToString_Sub(rtn, rtn.size(), wdPad, _dims, _dims.begin(), pElem);
		} else {
			ToString_Sub(rtn, 0, wdPad, _dims, _dims.begin(), pElem);
		}
	}
	return rtn;
}

template<typename T_Elem, typename T_ElemCast>
void DumpInteger(Signal &sig, Stream &stream, const char *fmt, size_t cols, const T_Elem *p, size_t n)
{
	char buff[128];
	size_t col = 0;
	for (size_t i = 0; i < n; i++, p++) {
		if (col != 0) {
			stream.Printf(sig, " ");
		}
		::sprintf(buff, fmt, static_cast<T_ElemCast>(*p));
		stream.Print(sig, buff);
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
	char buff[128];
	size_t col = 0;
	for (size_t i = 0; i < n; i++, p++) {
		if (col != 0) {
			stream.Printf(sig, " ");
		}
		T_ElemCast num = *reinterpret_cast<const T_ElemCast *>(p);
		::sprintf(buff, fmt, num);
		stream.Print(sig, buff);
		col++;
		if (col == cols) {
			stream.Printf(sig, "\n");
			col = 0;
		}
	}
	if (col != 0) stream.Printf(sig, "\n");
}

template<>
void ArrayT<Boolean>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpInteger<Boolean, UInt8>(sig, stream, upperFlag? "%02X" : "%02x", 24, GetPointer(), GetElemNum());
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

template<>
void ArrayT<UInt32>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
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
void ArrayT<Half>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<Half, UInt16>(sig, stream, upperFlag? "%04X" : "%04x", 16, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Float>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<Float, UInt32>(sig, stream, upperFlag? "%08X" : "%08x", 8, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Double>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<Double, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4, GetPointer(), GetElemNum());
}

template<>
void ArrayT<Complex>::Dump(Signal &sig, Stream &stream, bool upperFlag) const
{
	DumpFloat<Double, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx", 4,
							  reinterpret_cast<const Double *>(GetPointer()), GetElemNum() * 2);
}

template<typename T_Elem>
bool ArrayT<T_Elem>::DoesContainZero() const
{
	const T_Elem *pElem = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
		if (*pElem == 0) return true;
	}
	return false;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::DoesContainMinus() const
{
	const T_Elem *pElem = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
		if (*pElem < 0) return true;
	}
	return false;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::DoesContainZeroOrMinus() const
{
	const T_Elem *pElem = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
		if (*pElem <= 0) return true;
	}
	return false;
}

template<>
bool ArrayT<Complex>::DoesContainZero() const
{
	const Complex *pElem = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
		if (pElem->real() == 0 && pElem->imag() == 0) return true;
	}
	return false;
}

template<>
bool ArrayT<Complex>::DoesContainMinus() const
{
	return false;
}

template<>
bool ArrayT<Complex>::DoesContainZeroOrMinus() const
{
	return DoesContainZero();
}

template<typename T_Elem>
Double ArrayT<T_Elem>::GetScalarNumber() const
{
	return static_cast<Double>(*GetPointer());
}

template<>
Double ArrayT<Complex>::GetScalarNumber() const
{
	return 0;
}

template<typename T_Elem>
Complex ArrayT<T_Elem>::GetScalarComplex() const
{
	return Complex(static_cast<Double>(*GetPointer()));
}

template<>
Complex ArrayT<Complex>::GetScalarComplex() const
{
	return *GetPointer();
}

template<> ValueType ArrayT<Boolean>::ValueTypeElem			= VTYPE_boolean;
template<> ValueType ArrayT<Int8>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<UInt8>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<Int16>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<UInt16>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<Int32>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<UInt32>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<Int64>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<UInt64>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<Half>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<Float>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<Double>::ValueTypeElem			= VTYPE_number;
template<> ValueType ArrayT<Complex>::ValueTypeElem			= VTYPE_complex;
//template<> ValueType ArrayT<Value>::ValueTypeElem			= VTYPE_any;

template<> Array::ElemType ArrayT<Boolean>::ElemTypeThis	= ETYPE_Boolean;
template<> Array::ElemType ArrayT<Int8>::ElemTypeThis		= ETYPE_Int8;
template<> Array::ElemType ArrayT<UInt8>::ElemTypeThis		= ETYPE_UInt8;
template<> Array::ElemType ArrayT<Int16>::ElemTypeThis		= ETYPE_Int16;
template<> Array::ElemType ArrayT<UInt16>::ElemTypeThis		= ETYPE_UInt16;
template<> Array::ElemType ArrayT<Int32>::ElemTypeThis		= ETYPE_Int32;
template<> Array::ElemType ArrayT<UInt32>::ElemTypeThis		= ETYPE_UInt32;
template<> Array::ElemType ArrayT<Int64>::ElemTypeThis		= ETYPE_Int64;
template<> Array::ElemType ArrayT<UInt64>::ElemTypeThis		= ETYPE_UInt64;
template<> Array::ElemType ArrayT<Half>::ElemTypeThis		= ETYPE_Half;
template<> Array::ElemType ArrayT<Float>::ElemTypeThis		= ETYPE_Float;
template<> Array::ElemType ArrayT<Double>::ElemTypeThis		= ETYPE_Double;
template<> Array::ElemType ArrayT<Complex>::ElemTypeThis	= ETYPE_Complex;
//template<> Array::ElemType ArrayT<Value>::ElemTypeThis	= ETYPE_Value;

template<> size_t ArrayT<Boolean>::ElemBytes				= sizeof(Boolean);
template<> size_t ArrayT<Int8>::ElemBytes					= sizeof(Int8);
template<> size_t ArrayT<UInt8>::ElemBytes					= sizeof(UInt8);
template<> size_t ArrayT<Int16>::ElemBytes					= sizeof(Int16);
template<> size_t ArrayT<UInt16>::ElemBytes					= sizeof(UInt16);
template<> size_t ArrayT<Int32>::ElemBytes					= sizeof(Int32);
template<> size_t ArrayT<UInt32>::ElemBytes					= sizeof(UInt32);
template<> size_t ArrayT<Int64>::ElemBytes					= sizeof(Int64);
template<> size_t ArrayT<UInt64>::ElemBytes					= sizeof(UInt64);
template<> size_t ArrayT<Half>::ElemBytes					= sizeof(Half);
template<> size_t ArrayT<Float>::ElemBytes					= sizeof(Float);
template<> size_t ArrayT<Double>::ElemBytes					= sizeof(Double);
template<> size_t ArrayT<Complex>::ElemBytes				= sizeof(Complex);
//template<> size_t ArrayT<Value>::ElemBytes				= sizeof(Value);

template<> const char *ArrayT<Boolean>::ElemTypeName		= "boolean";
template<> const char *ArrayT<Int8>::ElemTypeName			= "int8";
template<> const char *ArrayT<UInt8>::ElemTypeName			= "uint8";
template<> const char *ArrayT<Int16>::ElemTypeName			= "int16";
template<> const char *ArrayT<UInt16>::ElemTypeName			= "uint16";
template<> const char *ArrayT<Int32>::ElemTypeName			= "int32";
template<> const char *ArrayT<UInt32>::ElemTypeName			= "uint32";
template<> const char *ArrayT<Int64>::ElemTypeName			= "int64";
template<> const char *ArrayT<UInt64>::ElemTypeName			= "uint64";
template<> const char *ArrayT<Half>::ElemTypeName			= "half";
template<> const char *ArrayT<Float>::ElemTypeName			= "float";
template<> const char *ArrayT<Double>::ElemTypeName			= "double";
template<> const char *ArrayT<Complex>::ElemTypeName		= "complex";
//template<> const char *ArrayT<Value>::ElemTypeName		= "value";

template<> const char *ArrayT<Boolean>::ConstructorName		= "array@boolean";
template<> const char *ArrayT<Int8>::ConstructorName		= "array@int8";
template<> const char *ArrayT<UInt8>::ConstructorName		= "array@uint8";
template<> const char *ArrayT<Int16>::ConstructorName		= "array@int16";
template<> const char *ArrayT<UInt16>::ConstructorName		= "array@uint16";
template<> const char *ArrayT<Int32>::ConstructorName		= "array@int32";
template<> const char *ArrayT<UInt32>::ConstructorName		= "array@uint32";
template<> const char *ArrayT<Int64>::ConstructorName		= "array@int64";
template<> const char *ArrayT<UInt64>::ConstructorName		= "array@uint64";
template<> const char *ArrayT<Half>::ConstructorName		= "array@half";
template<> const char *ArrayT<Float>::ConstructorName		= "array@float";
template<> const char *ArrayT<Double>::ConstructorName		= "array@double";
template<> const char *ArrayT<Complex>::ConstructorName 	= "array@complex";
//template<> const char *ArrayT<Value>::ConstructorName 	= "array@value";

template<typename T_Elem>
void CopyToList_Sub(Object_list *pObjList, const T_Elem *pElem,
					Array::Dimensions::const_iterator pDim, Array::Dimensions::const_iterator pDimEnd)
{
	Environment &env = *pObjList;
	if (pObjList->Empty()) pObjList->Reserve(pDim->GetSize());
	if (pDim + 1 == pDimEnd) {
		for (size_t i = 0; i < pDim->GetSize(); i++, pElem += pDim->GetStrides()) {
			pObjList->AddFast(Value(*pElem));
		}
		pObjList->SetValueType(ArrayT<T_Elem>::ValueTypeElem);
	} else {
		for (size_t i = 0; i < pDim->GetSize(); i++, pElem += pDim->GetStrides()) {
			Value value;
			Object_list *pObjListSub = value.InitAsList(env, pDim->GetSize());
			pObjList->AddFast(value);
			CopyToList_Sub(pObjListSub, pElem, pDim + 1, pDimEnd);
		}
		pObjList->SetValueType(VTYPE_list);
	}
}

template<typename T_Elem>
void ArrayT<T_Elem>::CopyToList(Object_list *pObjList) const
{
	const Dimensions &dims = GetDimensions();
	CopyToList_Sub(pObjList, GetPointer(), dims.begin(), dims.end());
}

template<typename T_Elem>
void ArrayT<T_Elem>::FillRand()
{
	T_Elem *pElem = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
		*pElem = static_cast<T_Elem>(Random::Uniform_CloseOpen());
	}
}

template<typename T_Elem>
void ArrayT<T_Elem>::FillRandRange(UInt range)
{
	T_Elem *pElem = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
		*pElem = static_cast<T_Elem>(static_cast<UInt>(Random::Uniform_CloseOpen() * range));
	}
}

template<typename T_Elem>
void ArrayT<T_Elem>::FillRandNormal(double mu, double sigma)
{
	T_Elem *pElem = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
		*pElem = static_cast<T_Elem>(mu + Random::Normal() * sigma);
	}
}

template<typename T_Elem>
void ArrayT<T_Elem>::SetScalar(const T_Elem &num)
{
	_elemNum = 1;
	AllocMemory();
	*GetPointer() = num;
}

template<typename T_Elem>
void ArrayT<T_Elem>::Fill(Double num)
{
	T_Elem *pElem = GetPointer();
	T_Elem numCasted = static_cast<T_Elem>(num);
	for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
		*pElem = numCasted;
	}
}

template<typename T_Elem>
void ArrayT<T_Elem>::RoundOff(AutoPtr<Array> &pArrayRtn, double threshold) const
{
	const Array::Dimensions &dims = GetDimensions();
	bool colMajorFlag = false;
	pArrayRtn.reset(ArrayT::Create(colMajorFlag, GetDimensions()));
	const T_Elem *pElem = GetPointer();
	T_Elem *pElemRtn = dynamic_cast<ArrayT<T_Elem> *>(pArrayRtn.get())->GetPointer();
	if (IsRowMajor() || dims.size() < 2) {
		for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
			*pElemRtn++ = (*pElem < threshold)? 0 : *pElem;
		}
	} else {
		const Array::Dimension &dimRow = dims.GetRow();
		const Array::Dimension &dimCol = dims.GetCol();
		size_t nMats = GetElemNum() / dimRow.GetSizeProd();
		const T_Elem *pElemMat = pElem;
		for (size_t iMat = 0; iMat < nMats; iMat++, pElemMat += dimRow.GetSizeProd()) {
			const T_Elem *pElemRow = pElemMat;
			for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++,
					 pElemRow += dimRow.GetStrides()) {
				const T_Elem *pElemCol = pElemRow;
				for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++,
						 pElemCol += dimCol.GetStrides()) {
					*pElemRtn++ = (*pElemCol < threshold)? 0 : *pElemCol;
				}
			}
		}
	}
}

template<>
void ArrayT<Complex>::RoundOff(AutoPtr<Array> &pArrayRtn, double threshold) const
{
	typedef Complex T_Elem;
	const Array::Dimensions &dims = GetDimensions();
	double threshold2 = threshold * threshold;
	bool colMajorFlag = false;
	pArrayRtn.reset(ArrayT::Create(colMajorFlag, GetDimensions()));
	const T_Elem *pElem = GetPointer();
	T_Elem *pElemRtn = dynamic_cast<ArrayT<T_Elem> *>(pArrayRtn.get())->GetPointer();
	if (IsRowMajor() || dims.size() < 2) {
		for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
			*pElemRtn++ = (std::norm(*pElem) < threshold2)? 0 : *pElem;
		}
	} else {
		const Array::Dimension &dimRow = dims.GetRow();
		const Array::Dimension &dimCol = dims.GetCol();
		size_t nMats = GetElemNum() / dimRow.GetSizeProd();
		const T_Elem *pElemMat = pElem;
		for (size_t iMat = 0; iMat < nMats; iMat++, pElemMat += dimRow.GetSizeProd()) {
			const T_Elem *pElemRow = pElemMat;
			for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++,
					 pElemRow += dimRow.GetStrides()) {
				const T_Elem *pElemCol = pElemRow;
				for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++,
						 pElemCol += dimCol.GetStrides()) {
					*pElemRtn++ = (std::norm(*pElemCol) < threshold2)? 0 : *pElemCol;
				}
			}
		}
	}
}

template<typename T_Elem>
void ArrayT<T_Elem>::Flatten(AutoPtr<Array> &pArrayRtn) const
{
	bool colMajorFlag = false;
	const Array::Dimensions &dims = GetDimensions();
	pArrayRtn.reset(Create(colMajorFlag));
	pArrayRtn->SetDimension(GetElemNum());
	if (IsRowMajor() || dims.size() < 2) {
		pArrayRtn->SetMemory(GetMemory().Reference(), GetOffsetBase());
	} else {
		pArrayRtn->AllocMemory();
		const T_Elem *pElem = GetPointer();
		T_Elem *pElemRtn = dynamic_cast<ArrayT<T_Elem> *>(pArrayRtn.get())->GetPointer();
		const Array::Dimension &dimRow = dims.GetRow();
		const Array::Dimension &dimCol = dims.GetCol();
		size_t nMats = GetElemNum() / dimRow.GetSizeProd();
		const T_Elem *pElemMat = pElem;
		for (size_t iMat = 0; iMat < nMats; iMat++, pElemMat += dimRow.GetSizeProd()) {
			const T_Elem *pElemRow = pElemMat;
			for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++,
					 pElemRow += dimRow.GetStrides()) {
				const T_Elem *pElemCol = pElemRow;
				for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++,
						 pElemCol += dimCol.GetStrides()) {
					*pElemRtn++ = *pElemCol;
				}
			}
		}
	}
}

template<typename T_Elem>
void TransposeSub(void **ppElemDstRaw, const void *pElemSrcRaw, const Array::Dimensions &dimsSrc,
				  SizeTList::const_iterator pAxis, SizeTList::const_iterator pAxisEnd)
{
	T_Elem *&pElemDst = *reinterpret_cast<T_Elem **>(ppElemDstRaw);
	const T_Elem *pElemSrc = reinterpret_cast<const T_Elem *>(pElemSrcRaw);
	const Array::Dimension &dimSrc = dimsSrc[*pAxis];
	if (pAxis + 1 == pAxisEnd) {
		for (size_t i = 0; i < dimSrc.GetSize(); i++, pElemSrc += dimSrc.GetStrides(), pElemDst++) {
			*pElemDst = *pElemSrc;
		}
	} else {
		for (size_t i = 0; i < dimSrc.GetSize(); i++, pElemSrc += dimSrc.GetStrides()) {
			TransposeSub<T_Elem>(reinterpret_cast<void **>(&pElemDst),
								 reinterpret_cast<const void *>(pElemSrc), dimsSrc, pAxis + 1, pAxisEnd);
		}
	}
}

template<typename T_Elem>
bool ArrayT<T_Elem>::Transpose(AutoPtr<Array> &pArrayRtn, const SizeTList &axes) const
{
	if (axes.size() < 2) {
		pArrayRtn.reset(Clone());
		return true;
	}
	Dimensions::const_reverse_iterator pDim = GetDimensions().rbegin();
	bool memorySharableFlag = false;
	if (pDim->GetSize() == 1 || (pDim + 1)->GetSize() == 1) {
		memorySharableFlag = true;
		SizeTList::const_iterator pAxis = axes.begin();
		SizeTList::const_iterator pAxisEnd = axes.begin() + axes.size() - 2;
		for (size_t axisInc = 0; pAxis != pAxisEnd; pAxis++, axisInc++) {
			if (*pAxis != axisInc) {
				memorySharableFlag = false;
				break;
			}
		}
	}
	if (pArrayRtn.IsNull()) {
		bool colMajorFlag = false;
		pArrayRtn.reset(Create(colMajorFlag));
		Dimensions &dimsDst = pArrayRtn->GetDimensions();
		dimsDst.reserve(GetDimensions().size());
		foreach_const (SizeTList, pAxis, axes) {
			const Dimension &dimSrc = GetDimensions()[*pAxis];
			dimsDst.push_back(Dimension(dimSrc.GetSize()));
		}
		pArrayRtn->UpdateMetrics();
		if (memorySharableFlag) {
			pArrayRtn->SetMemory(GetMemory().Reference(), GetOffsetBase());
		} else {
			pArrayRtn->AllocMemory();
			void *pElemDstRaw = pArrayRtn->GetPointerRaw();
			TransposeSub<T_Elem>(&pElemDstRaw, GetPointerRaw(), GetDimensions(), axes.begin(), axes.end());
		}
	} else {
		if (!memorySharableFlag) {
			void *pElemDstRaw = pArrayRtn->GetPointerRaw();
			TransposeSub<T_Elem>(&pElemDstRaw, GetPointerRaw(), GetDimensions(), axes.begin(), axes.end());
		}
	}
	return true;
}

template<typename T_Elem, bool (*op)(T_Elem, T_Elem)>
Array *FindMinMax(const ArrayT<T_Elem> *pArrayT, size_t axis)
{
	bool colMajorFlag = false;
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
	AutoPtr<ArrayT<T_Elem> > pArrayTValue(ArrayT<T_Elem>::Create(colMajorFlag));
	pArrayTValue->SetDimensions(dims.begin(), pDimAxis, pDimAxis + 1, dims.end());
	pArrayTValue->AllocMemory();
	pArrayTValue->FillZero();
	const T_Elem *pElem = pArrayT->GetPointer();
	T_Elem *pElemValue = pArrayTValue->GetPointer();
	size_t sizeSub = pDimAxis->GetStrides() * pDimAxis->GetSize();
	if (pArrayT->IsRowMajor() || axis + 2 >= dims.size()) {
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += sizeSub) {
			do {
				// first element
				T_Elem *pElemValueEach = pElemValue;
				for (size_t j = 0; j < pDimAxis->GetStrides(); j++, pElem++) {
					*pElemValueEach = *pElem;
					pElemValueEach++;
				}
			} while (0);
			for (size_t i = 1; i < pDimAxis->GetSize(); i++) {
				T_Elem *pElemValueEach = pElemValue;
				for (size_t j = 0; j < pDimAxis->GetStrides(); j++, pElem++) {
					if ((*op)(*pElemValueEach, *pElem)) *pElemValueEach = *pElem;
					pElemValueEach++;
				}
			}
			pElemValue += pDimAxis->GetStrides();
		}
	} else { // pArrayT->IsColMajor() && axis + 2 < dim.size()
		const Array::Dimension &dimRow = dims.GetRow();
		const Array::Dimension &dimCol = dims.GetCol();
		size_t nMats = pDimAxis->GetStrides() / dimRow.GetSizeProd();
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += sizeSub) {
			do {
				// first element
				T_Elem *pElemValueEach = pElemValue;
				for (size_t iMat = 0; iMat < nMats; iMat++, pElem += dimRow.GetSizeProd()) {
					const T_Elem *pElemRow = pElem;
					for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++, pElemRow += dimRow.GetStrides()) {
						const T_Elem *pElemCol = pElemRow;
						for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++, pElemCol += dimCol.GetStrides()) {
							*pElemValueEach = *pElemCol;
							pElemValueEach++;
						}
					}
				}
			} while (0);
			for (size_t i = 1; i < pDimAxis->GetSize(); i++) {
				T_Elem *pElemValueEach = pElemValue;
				for (size_t iMat = 0; iMat < nMats; iMat++, pElem += dimRow.GetSizeProd()) {
					const T_Elem *pElemRow = pElem;
					for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++, pElemRow += dimRow.GetStrides()) {
						const T_Elem *pElemCol = pElemRow;
						for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++, pElemCol += dimCol.GetStrides()) {
							if ((*op)(*pElemValueEach, *pElemCol)) *pElemValueEach = *pElemCol;
							pElemValueEach++;
						}
					}
				}
			}
			pElemValue += pDimAxis->GetStrides();
		}
	}
	return pArrayTValue.release();
}

template<typename T_Elem, bool (*op)(T_Elem, T_Elem)>
T_Elem FindMinMaxFlat(const ArrayT<T_Elem> *pArrayT)
{
	const T_Elem *pElem = pArrayT->GetPointer();
	T_Elem rtn = *pElem++;
	for (size_t i = 1; i < pArrayT->GetElemNum(); i++, pElem++) {
		if ((*op)(rtn, *pElem)) rtn = *pElem;
	}
	return rtn;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::FindMax(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis) const
{
	const Array::Dimensions &dims = GetDimensions();
	if (GetElemNum() == 0) {
		// nothing to do
	} else if (axis < 0 || (axis == 0 && dims.size() == 1)) {
		pArrayRtn.reset(ArrayT<T_Elem>::CreateScalar(FindMinMaxFlat<T_Elem, CompareLt>(this)));
	} else if (axis >= dims.size()) {
		sig.SetError(ERR_OutOfRangeError, "specified axis is out of range");
		return false;
	} else {
		pArrayRtn.reset(FindMinMax<T_Elem, CompareLt>(this, axis));
	}
	return true;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::FindMin(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis) const
{
	const Array::Dimensions &dims = GetDimensions();
	if (GetElemNum() == 0) {
		// nothing to do
	} else if (axis < 0 || (axis == 0 && dims.size() == 1)) {
		pArrayRtn.reset(ArrayT<T_Elem>::CreateScalar(FindMinMaxFlat<T_Elem, CompareGt>(this)));
	} else if (axis >= dims.size()) {
		sig.SetError(ERR_OutOfRangeError, "specified axis is out of range");
		return false;
	} else {
		pArrayRtn.reset(FindMinMax<T_Elem, CompareGt>(this, axis));
	}
	return true;
}

template<typename T_Elem, bool (*op)(T_Elem, T_Elem)>
Array *FindMinMaxIndex(const ArrayT<T_Elem> *pArrayT, size_t axis)
{
	bool colMajorFlag = false;
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
	AutoPtr<ArrayT<UInt32> > pArrayTIndex(ArrayT<UInt32>::Create(colMajorFlag));
	pArrayTIndex->SetDimensions(dims.begin(), pDimAxis, pDimAxis + 1, dims.end());
	pArrayTIndex->AllocMemory();
	AutoPtr<Memory> pMemoryValue(new MemoryHeap(pArrayTIndex->GetElemNum() * sizeof(T_Elem)));
	pArrayTIndex->FillZero();
	const T_Elem *pElem = pArrayT->GetPointer();
	UInt32 *pElemIndex = pArrayTIndex->GetPointer();
	T_Elem *pElemValue = reinterpret_cast<T_Elem *>(pMemoryValue->GetPointer());
	size_t sizeSub = pDimAxis->GetStrides() * pDimAxis->GetSize();
	if (pArrayT->IsRowMajor() || axis + 2 >= dims.size()) {
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += sizeSub) {
			do {
				UInt32 *pElemIndexEach = pElemIndex;
				T_Elem *pElemValueEach = pElemValue;
				for (size_t j = 0; j < pDimAxis->GetStrides(); j++, pElem++) {
					*pElemIndexEach = 0;
					*pElemValueEach = *pElem;
					pElemIndexEach++;
					pElemValueEach++;
				}
			} while (0);
			for (size_t i = 1; i < pDimAxis->GetSize(); i++) {
				UInt32 *pElemIndexEach = pElemIndex;
				T_Elem *pElemValueEach = pElemValue;
				for (size_t j = 0; j < pDimAxis->GetStrides(); j++, pElem++) {
					if ((*op)(*pElemValueEach, *pElem)) {
						*pElemIndexEach = static_cast<UInt32>(i);
						*pElemValueEach = *pElem;
					}
					pElemIndexEach++;
					pElemValueEach++;
				}
			}
			pElemIndex += pDimAxis->GetStrides();
			pElemValue += pDimAxis->GetStrides();
		}
	} else { // pArrayT->IsColMajor() && axis + 2 < dim.size()
		const Array::Dimension &dimRow = dims.GetRow();
		const Array::Dimension &dimCol = dims.GetCol();
		size_t nMats = pDimAxis->GetStrides() / dimRow.GetSizeProd();
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += sizeSub) {
			do {
				// first element
				UInt32 *pElemIndexEach = pElemIndex;
				T_Elem *pElemValueEach = pElemValue;
				for (size_t iMat = 0; iMat < nMats; iMat++, pElem += dimRow.GetSizeProd()) {
					const T_Elem *pElemRow = pElem;
					for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++, pElemRow += dimRow.GetStrides()) {
						const T_Elem *pElemCol = pElemRow;
						for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++, pElemCol += dimCol.GetStrides()) {
							*pElemIndexEach = 0;
							*pElemValueEach = *pElemCol;
							pElemIndexEach++;
							pElemValueEach++;
						}
					}
				}
			} while (0);
			for (size_t i = 1; i < pDimAxis->GetSize(); i++) {
				UInt32 *pElemIndexEach = pElemIndex;
				T_Elem *pElemValueEach = pElemValue;
				for (size_t iMat = 0; iMat < nMats; iMat++, pElem += dimRow.GetSizeProd()) {
					const T_Elem *pElemRow = pElem;
					for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++, pElemRow += dimRow.GetStrides()) {
						const T_Elem *pElemCol = pElemRow;
						for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++, pElemCol += dimCol.GetStrides()) {
							if ((*op)(*pElemValueEach, *pElemCol)) {
								*pElemIndexEach = static_cast<UInt32>(i);
								*pElemValueEach = *pElemCol;
							}
							pElemIndexEach++;
							pElemValueEach++;
						}
					}
				}
			}
			pElemIndex += pDimAxis->GetStrides();
			pElemValue += pDimAxis->GetStrides();
		}
	}
	return pArrayTIndex.release();
}

template<typename T_Elem, bool (*op)(T_Elem, T_Elem)>
UInt32 FindMinMaxIndexFlat(const ArrayT<T_Elem> *pArrayT)
{
	const T_Elem *pElem = pArrayT->GetPointer();
	size_t index = 0;
	T_Elem value = *pElem++;
	for (size_t i = 1; i < pArrayT->GetElemNum(); i++, pElem++) {
		if ((*op)(value, *pElem)) {
			index = i;
			value = *pElem;
		}
	}
	return static_cast<UInt32>(index);
}

template<typename T_Elem>
bool ArrayT<T_Elem>::FindMaxIndex(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis, bool lastFlag) const
{
	const Array::Dimensions &dims = GetDimensions();
	if (GetElemNum() == 0) {
		// nothing to do
	} else if (axis < 0 || (axis == 0 && dims.size() == 1)) {
		pArrayRtn.reset(ArrayT<UInt32>::CreateScalar(
							lastFlag? 
							FindMinMaxIndexFlat<T_Elem, CompareLe>(this) :
							FindMinMaxIndexFlat<T_Elem, CompareLt>(this)));
	} else if (axis >= dims.size()) {
		sig.SetError(ERR_OutOfRangeError, "specified axis is out of range");
		return false;
	} else {
		pArrayRtn.reset(lastFlag?
						FindMinMaxIndex<T_Elem, CompareLe>(this, axis) :
						FindMinMaxIndex<T_Elem, CompareLt>(this, axis));
	}
	return true;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::FindMinIndex(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis, bool lastFlag) const
{
	const Array::Dimensions &dims = GetDimensions();
	if (GetElemNum() == 0) {
		// nothing to do
	} else if (axis < 0 || (axis == 0 && dims.size() == 1)) {
		pArrayRtn.reset(ArrayT<UInt32>::CreateScalar(
							lastFlag? 
							FindMinMaxIndexFlat<T_Elem, CompareGe>(this) :
							FindMinMaxIndexFlat<T_Elem, CompareGt>(this)));
	} else if (axis >= dims.size()) {
		sig.SetError(ERR_OutOfRangeError, "specified axis is out of range");
		return false;
	} else {
		pArrayRtn.reset(lastFlag?
						FindMinMaxIndex<T_Elem, CompareGe>(this, axis) :
						FindMinMaxIndex<T_Elem, CompareGt>(this, axis));
	}
	return true;
}

template<typename T_ElemRtn, typename T_Elem>
ArrayT<T_ElemRtn> *CalcSum(const ArrayT<T_Elem> *pArrayT, size_t axis, bool meanFlag)
{
	bool colMajorFlag = false;
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
	AutoPtr<ArrayT<T_ElemRtn> > pArrayTRtn(ArrayT<T_ElemRtn>::Create(colMajorFlag));
	pArrayTRtn->SetDimensions(dims.begin(), pDimAxis, pDimAxis + 1, dims.end());
	pArrayTRtn->AllocMemory();
	pArrayTRtn->FillZero();
	Double numDenom = static_cast<Double>(pDimAxis->GetSize());
	const T_Elem *pElemTop = pArrayT->GetPointer();
	T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
	size_t sizeSub = pDimAxis->GetStrides() * pDimAxis->GetSize();
	if (pArrayT->IsRowMajor() || axis + 2 >= dims.size()) {
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += sizeSub) {
			const T_Elem *pElemBlock = pElemTop + offset;
			for (size_t j = 0; j < pDimAxis->GetStrides(); j++, pElemBlock++) {
				T_ElemRtn numAccum = 0;
				const T_Elem *pElemEach = pElemBlock;
				for (size_t i = 0; i < pDimAxis->GetSize(); i++, pElemEach += pDimAxis->GetStrides()) {
					numAccum += *pElemEach;
				}
				*pElemRtn++ = meanFlag? numAccum / numDenom : numAccum;
			}
		}
	} else { // pArrayT->IsColMajor() && axis + 2 < dim.size()
		const Array::Dimension &dimRow = dims.GetRow();
		const Array::Dimension &dimCol = dims.GetCol();
		size_t nMats = pDimAxis->GetStrides() / dimRow.GetSizeProd();
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += sizeSub) {
			const T_Elem *pElemMat = pElemTop + offset;
			for (size_t iMat = 0; iMat < nMats; iMat++, pElemMat += dimRow.GetSizeProd()) {
				const T_Elem *pElemRow = pElemMat;
				for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++, pElemRow += dimRow.GetStrides()) {
					const T_Elem *pElemCol = pElemRow;
					for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++, pElemCol += dimCol.GetStrides()) {
						T_ElemRtn numAccum = 0;
						const T_Elem *pElemEach = pElemCol;
						for (size_t i = 0; i < pDimAxis->GetSize(); i++, pElemEach += pDimAxis->GetStrides()) {
							numAccum += *pElemEach;
						}
						*pElemRtn++ = meanFlag? numAccum / numDenom : numAccum;
					}
				}
			}
		}
	}
	return pArrayTRtn.release();
}

template<typename T_ElemRtn, typename T_Elem>
T_ElemRtn CalcSumFlat(const ArrayT<T_Elem> *pArrayT, bool meanFlag)
{
	Double numDenom = static_cast<Double>(pArrayT->GetElemNum());
	if (numDenom == 0) return 0;
	T_ElemRtn numAccum = 0;
	const T_Elem *pElem = pArrayT->GetPointer();
	for (size_t i = 0; i < pArrayT->GetElemNum(); i++, pElem++) {
		numAccum += *pElem;
	}
	return meanFlag? numAccum / numDenom : numAccum;
}

template<typename T_ElemRtn, typename T_Elem>
bool CalcSumSub(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArraySelf, ssize_t axis, bool meanFlag)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArraySelf);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	if (axis < 0 || (axis == 0 && dims.size() == 1)) {
		pArrayRtn.reset(ArrayT<T_ElemRtn>::CreateScalar(CalcSumFlat<T_ElemRtn, T_Elem>(pArrayT, meanFlag)));
	} else if (axis >= dims.size()) {
		sig.SetError(ERR_OutOfRangeError, "specified axis is out of range");
		return false;
	} else {
		pArrayRtn.reset(CalcSum<T_ElemRtn, T_Elem>(pArrayT, axis, meanFlag));
	}
	return true;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::CalcSum(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis, bool meanFlag) const
{
	return CalcSumSub<T_Elem, T_Elem>(sig, pArrayRtn, this, axis, meanFlag);
}

template<>
bool ArrayT<Boolean>::CalcSum(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis, bool meanFlag) const
{
	return CalcSumSub<UInt32, Boolean>(sig, pArrayRtn, this, axis, meanFlag);
}

template<typename T_ElemRtn, typename T_Elem>
ArrayT<T_ElemRtn> *CalcVar(const ArrayT<T_Elem> *pArrayT, size_t axis, bool populationFlag, bool stdFlag)
{
	bool colMajorFlag = false;
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
	AutoPtr<ArrayT<T_ElemRtn> > pArrayTRtn(ArrayT<T_ElemRtn>::Create(colMajorFlag));
	pArrayTRtn->SetDimensions(dims.begin(), pDimAxis, pDimAxis + 1, dims.end());
	pArrayTRtn->AllocMemory();
	pArrayTRtn->FillZero();
	Double numDenom = static_cast<Double>(pDimAxis->GetSize());
	Double numDenomVar = (numDenom <= 1)? 1 : populationFlag? numDenom : numDenom - 1;
	const T_Elem *pElemTop = pArrayT->GetPointer();
	T_ElemRtn *pElemRtn = pArrayTRtn->GetPointer();
	size_t sizeSub = pDimAxis->GetStrides() * pDimAxis->GetSize();
	if (pArrayT->IsRowMajor() || axis + 2 >= dims.size()) {
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += sizeSub) {
			const T_Elem *pElemBlock = pElemTop + offset;
			for (size_t j = 0; j < pDimAxis->GetStrides(); j++, pElemBlock++) {
				// calculates a mean value numMean
				T_ElemRtn numMean = 0;
				const T_Elem *pElemEach = pElemBlock;
				for (size_t i = 0; i < pDimAxis->GetSize(); i++, pElemEach += pDimAxis->GetStrides()) {
					numMean += *pElemEach;
				}
				numMean /= numDenom;
				// accumulates values of ((*pElemEach - numMean) ** 2)
				T_ElemRtn numAccum = 0;
				pElemEach = pElemBlock;
				for (size_t i = 0; i < pDimAxis->GetSize(); i++, pElemEach += pDimAxis->GetStrides()) {
					T_ElemRtn tmp = *pElemEach - numMean;
					numAccum += tmp * tmp;
				}
				numAccum /= numDenomVar;
				if (stdFlag) Operator_Math_sqrt::Calc(numAccum, numAccum);
				*pElemRtn++ = numAccum;
			}
		}
	} else { // pArrayT->IsColMajor() && axis + 2 < dim.size()
		const Array::Dimension &dimRow = dims.GetRow();
		const Array::Dimension &dimCol = dims.GetCol();
		size_t nMats = pDimAxis->GetStrides() / dimRow.GetSizeProd();
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += sizeSub) {
			const T_Elem *pElemMat = pElemTop + offset;
			for (size_t iMat = 0; iMat < nMats; iMat++, pElemMat += dimRow.GetSizeProd()) {
				const T_Elem *pElemRow = pElemMat;
				for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++, pElemRow += dimRow.GetStrides()) {
					const T_Elem *pElemCol = pElemRow;
					for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++, pElemCol += dimCol.GetStrides()) {
						// calculates a mean value numMean
						T_ElemRtn numMean = 0;
						const T_Elem *pElemEach = pElemCol;
						for (size_t i = 0; i < pDimAxis->GetSize(); i++, pElemEach += pDimAxis->GetStrides()) {
							numMean += *pElemEach;
						}
						numMean /= numDenom;
						// accumulates values of ((*pElemEach - numMean) ** 2)
						T_ElemRtn numAccum = 0;
						pElemEach = pElemCol;
						for (size_t i = 0; i < pDimAxis->GetSize(); i++, pElemEach += pDimAxis->GetStrides()) {
							T_ElemRtn tmp = *pElemEach - numMean;
							numAccum += tmp * tmp;
						}
						numAccum /= numDenomVar;
						if (stdFlag) Operator_Math_sqrt::Calc(numAccum, numAccum);
						*pElemRtn++ = numAccum;
					}
				}
			}
		}
	}
	return pArrayTRtn.release();
}

template<typename T_ElemRtn, typename T_Elem>
T_ElemRtn CalcVarFlat(const ArrayT<T_Elem> *pArrayT, bool populationFlag, bool stdFlag)
{
	Double numDenom = static_cast<Double>(pArrayT->GetElemNum());
	if (numDenom == 0) return 0;
	Double numDenomVar = (numDenom <= 1)? 1 : populationFlag? numDenom : numDenom - 1;
	T_ElemRtn numMean = 0;
	const T_Elem *pElem = pArrayT->GetPointer();
	for (size_t i = 0; i < pArrayT->GetElemNum(); i++, pElem++) {
		numMean += *pElem;
	}
	numMean /= numDenom;
	T_ElemRtn numAccum = 0;
	pElem = pArrayT->GetPointer();
	for (size_t i = 0; i < pArrayT->GetElemNum(); i++, pElem++) {
		T_ElemRtn tmp = *pElem - numMean;
		numAccum += tmp * tmp;
	}
	numAccum /= numDenomVar;
	if (stdFlag) Operator_Math_sqrt::Calc(numAccum, numAccum);
	return numAccum;
}

template<typename T_ElemRtn, typename T_Elem>
bool CalcVarSub(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArraySelf,
				 ssize_t axis, bool populationFlag, bool stdFlag)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArraySelf);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	if (axis < 0 || (axis == 0 && dims.size() == 1)) {
		pArrayRtn.reset(ArrayT<T_ElemRtn>::CreateScalar(CalcVarFlat<T_ElemRtn, T_Elem>(
															pArrayT, populationFlag, stdFlag)));
	} else if (axis >= dims.size()) {
		sig.SetError(ERR_OutOfRangeError, "specified axis is out of range");
		return false;
	} else {
		pArrayRtn.reset(CalcVar<T_ElemRtn, T_Elem>(pArrayT, axis, populationFlag, stdFlag));
	}
	return true;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::CalcVar(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis, bool populationFlag, bool stdFlag) const
{
	return CalcVarSub<T_Elem, T_Elem>(sig, pArrayRtn, this, axis, populationFlag, stdFlag);
}

template<>
bool ArrayT<Boolean>::CalcVar(Signal &sig, AutoPtr<Array> &pArrayRtn, ssize_t axis, bool populationFlag, bool stdFlag) const
{
	return CalcVarSub<UInt32, Boolean>(sig, pArrayRtn, this, axis, populationFlag, stdFlag);
}

template<typename T_Elem>
void ArrayT<T_Elem>::ExpandKernelVec1d(
	AutoPtr<Array> &pArrayVec, size_t sizeKernel, size_t stridesKernel, size_t sizePad) const
{
	const bool colMajorFlag = false;
	const Dimensions &dims = GetDimensions();
	if (dims.size() < 1) return;
	pArrayVec.reset(Create(colMajorFlag));
	size_t nKernels = (dims.GetCol().GetSize() + sizePad - sizeKernel + stridesKernel) / stridesKernel;
	pArrayVec->SetDimensions(dims.begin(), dims.begin() + dims.size() - 1, nKernels, sizeKernel);
	
}

template<typename T_Elem>
void ArrayT<T_Elem>::StoreKernelVec1d(
	const Array *pArrayVec, size_t sizeKernel, size_t stridesKernel, size_t sizePad)
{
}

template<typename T_Elem>
void ArrayT<T_Elem>::ExpandKernelVec2d(
	AutoPtr<Array> &pArrayVec, size_t sizeKernelRow, size_t sizeKernelCol,
	size_t stridesKernelRow, size_t stridesKernelCol, size_t sizePadRow, size_t sizePadCol) const
{
	const bool colMajorFlag = false;
	const Dimensions &dims = GetDimensions();
	if (dims.size() < 2) return;
	size_t stridesRow = dims.GetRow().GetStrides();
	size_t stridesCol = dims.GetCol().GetStrides();
	size_t nRowsPadded = dims.GetRow().GetSize() + sizePadRow;
	size_t nColsPadded = dims.GetCol().GetSize() + sizePadCol;
	size_t sizePadRowHead = sizePadRow / 2;
	size_t sizePadRowTail = sizePadRow - sizePadRowHead;
	size_t sizePadColHead = sizePadCol / 2;
	size_t sizePadColTail = sizePadCol - sizePadColHead;
	size_t iRowMin = sizePadRowHead;
	size_t iRowMax = nRowsPadded - sizePadRowTail;
	size_t iColMin = sizePadColHead;
	size_t iColMax = nColsPadded - sizePadColTail;
	size_t nKernelsRow = (nRowsPadded - sizeKernelRow + stridesKernelRow) / stridesKernelRow;
	size_t nKernelsCol = (nColsPadded - sizeKernelCol + stridesKernelCol) / stridesKernelCol;
	size_t sizeBlock = dims.GetRow().GetSizeProd();
	size_t nBlocks = GetElemNum() / sizeBlock;
	pArrayVec.reset(Create(colMajorFlag));
	pArrayVec->SetDimensions(dims.begin(), dims.begin() + dims.size() - 2,
							 nKernelsRow * nKernelsCol, sizeKernelRow * sizeKernelCol);
	const T_Elem *pElemSrc = GetPointer();
	T_Elem *pElemDst = dynamic_cast<ArrayT<T_Elem> *>(pArrayVec.get())->GetPointer();
	const T_Elem *pElemBlock = pElemSrc;
	for (size_t iBlock = 0; iBlock < nBlocks; iBlock++, pElemBlock += sizeBlock) {
		for (size_t iKernelRow = 0; iKernelRow < nKernelsRow; iKernelRow++) {
			size_t iRowHead = iKernelRow * stridesKernelRow;
			size_t iRowTail = iRowHead + sizeKernelRow;
			size_t iRowLim = ChooseMin(iRowTail, iRowMax);
			const T_Elem *pElemKernelRow = pElemBlock + iRowHead * stridesRow;
			for (size_t iKernelCol = 0; iKernelCol < nKernelsCol; iKernelCol++) {
				size_t iColHead = iKernelCol * stridesCol;
				size_t iColTail = iColHead + sizeKernelCol;
				size_t iColLim = ChooseMin(iColTail, iColMax);
				const T_Elem *pElemRow = pElemKernelRow + iColHead * stridesCol;
				size_t iRow = iRowHead;
				for ( ; iRow < iRowMin; iRow++) {
					for (size_t iCol = iColHead; iCol < iColTail; iCol++) {
						*pElemDst++ = 0;
					}
				}
				for ( ; iRow < iRowLim; iRow++, pElemRow += stridesRow) {
					const T_Elem *pElemCol = pElemRow;
					size_t iCol = iColHead;
					for ( ; iCol < iColMin; iCol++) {
						*pElemDst++ = 0;
					}
					for ( ; iCol < iColLim; iCol++, pElemCol += stridesCol) {
						*pElemDst++ = *pElemCol;
					}
					for ( ; iCol < iColTail; iCol++) {
						*pElemDst++ = 0;
					}
				}
				for ( ; iRow < iRowTail; iRow++) {
					for (size_t iCol = iColHead; iCol < iColTail; iCol++) {
						*pElemDst++ = 0;
					}
				}
			}
		}
	}
}

template<typename T_Elem>
void ArrayT<T_Elem>::StoreKernelVec2d(
	const Array *pArrayVec, size_t sizeKernelRow, size_t sizeKernelCol,
	size_t stridesKernelRow, size_t stridesKernelCol, size_t sizePadRow, size_t sizePadCol)
{
}

template<typename T_Elem>
void ArrayT<T_Elem>::ExpandKernelVec3d(
	AutoPtr<Array> &pArrayVec, size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
	size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
	size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol) const
{
	const bool colMajorFlag = false;
	const Dimensions &dims = GetDimensions();
	if (dims.size() < 3) return;
	pArrayVec.reset(Create(colMajorFlag));
	pArrayVec->SetDimensions(dims.begin(), dims.begin() + dims.size() - 3,
							 sizeKernelPlane * sizeKernelRow * sizeKernelCol);
}

template<typename T_Elem>
void ArrayT<T_Elem>::StoreKernelVec3d(
	const Array *pArrayVec, size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
	size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
	size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol)
{
}

template<typename T_Elem>
Iterator *ArrayT<T_Elem>::CreateIteratorEach(bool flatFlag) const
{
	return new Iterator_Each(Reference(), flatFlag);
}

/// functions to create an ArrayT instance
template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(bool colMajorFlag)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(bool colMajorFlag, const Array::Dimensions &dims)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetDimensions(dims);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create1d(bool colMajorFlag, size_t size)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetDimension(size);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create2d(bool colMajorFlag, size_t sizeRow, size_t sizeCol)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetDimensions(sizeRow, sizeCol);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create3d(bool colMajorFlag, size_t sizePlane, size_t sizeRow, size_t sizeCol)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetDimensions(sizePlane, sizeRow, sizeCol);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateScalar(const T_Elem &num)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetScalar(num);
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromValue(Environment &env, bool colMajorFlag, const Value &value)
{
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	Signal &sig = env.GetSignal();
	if (value.Is_list()) {
		const ValueList &valList = value.GetList();
		pArrayT.reset(ArrayT<T_Elem>::CreateFromList(env, colMajorFlag, valList));
		if (pArrayT.IsNull()) return nullptr;
	} else if (value.Is_iterator()) {
		Iterator *pIterator = value.GetIterator();
		if (pIterator->IsInfinite()) {
			Iterator::SetError_InfiniteNotAllowed(sig);
			return nullptr;
		}
		pArrayT.reset(ArrayT<T_Elem>::CreateFromIterator(env, colMajorFlag, pIterator));
		if (pArrayT.IsNull()) return nullptr;
	} else {
		Declaration::SetError_InvalidArgument(env);
		return nullptr;
	}
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromList(bool colMajorFlag, const ValueList &valList)
{
	AutoPtr<ArrayT> pArrayT(ArrayT::Create1d(colMajorFlag, valList.size()));
	T_Elem *pElem = pArrayT->GetPointer();
	foreach_const (ValueList, pValue, valList) {
		*pElem++ = static_cast<T_Elem>(pValue->GetNumber());
	}
	return pArrayT.release();
}

template<typename T_Elem>
bool CreateFromList_Sub(Environment &env, Array::Dimensions &dims,
						Array::Dimensions::const_iterator pDim,
						T_Elem *&pElem, const ValueList &valList)
{
	if (pDim->GetSize() != valList.size()) {
		env.SetError(ERR_ValueError, "incorrect number of elements");
		return false;
	}
	if (pDim + 1 == dims.end()) {
		foreach_const (ValueList, pValue, valList) {
			if (!ArrayT<T_Elem>::StoreValueAt(env, pElem, *pValue)) return false;
			pElem++;
		}
	} else {
		if (valList.GetValueTypeOfElements() != VTYPE_list) {
			env.SetError(ERR_ValueError, "invalid format of array initializer");
			return false;
		}
		foreach_const (ValueList, pValue, valList) {
			if (!CreateFromList_Sub(env, dims, pDim + 1, pElem, pValue->GetList())) return false;
		}
	}
	return true;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromList(Environment &env, bool colMajorFlag, const ValueList &valList)
{
	Array::Dimensions dims;
	for (const ValueList *pValList = &valList; ; ) {
		dims.push_back(Array::Dimension(pValList->size()));
		if (pValList->empty() || !pValList->front().Is_list()) break;
		pValList = &pValList->front().GetList();
	}
	AutoPtr<ArrayT> pArrayT(ArrayT::Create(colMajorFlag, dims));
	T_Elem *pElem = pArrayT->GetPointer();
	if (!CreateFromList_Sub(env, dims, dims.begin(), pElem, valList)) return nullptr;
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromIterator(Environment &env, bool colMajorFlag, Iterator *pIterator)
{
	size_t len = pIterator->GetLengthEx(env);
	if (env.IsSignalled()) return nullptr;
	AutoPtr<ArrayT> pArrayT(ArrayT::Create1d(colMajorFlag, len));
	AutoPtr<Iterator> pIteratorWork(pIterator->Clone());
	T_Elem *pElem = pArrayT->GetPointer();
	Value value;
	while (pIteratorWork->Next(env, value)) {
		if (!StoreValueAt(env, pElem, value)) return nullptr;
		pElem++;
	}
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::CreateFromExpr(Environment &env, bool colMajorFlag, const Expr *pExpr)
{
	AutoPtr<Environment> pEnvLister(env.Derive(ENVTYPE_lister));
	Value result = pExpr->Exec(*pEnvLister);
	if (!result.Is_list()) return nullptr;
	return ArrayT<T_Elem>::CreateFromList(env, colMajorFlag, result.GetList());
}

// utilities
template<typename T_Elem>
void ArrayT<T_Elem>::FillDouble(T_Elem *pElem, size_t nElems, Double num, size_t strides)
{
	T_Elem numCasted = static_cast<T_Elem>(num);
	for (size_t i = 0; i < nElems; i++, pElem += strides) *pElem = numCasted;
}

template<>
void ArrayT<Complex>::FillComplex(Complex *pElem, size_t nElems, const Complex &num, size_t strides)
{
	for (size_t i = 0; i < nElems; i++, pElem += strides) *pElem = num;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::StoreValueAt(Environment &env, T_Elem *pElem, const Value &value)
{
	if (value.Is_number() || value.Is_boolean()) {
		*pElem = static_cast<T_Elem>(value.GetDouble());
	} else {
		Array::SetError_UnacceptableValueAsElement(env, value);
		return false;
	}
	return true;
}

template<>
bool ArrayT<Complex>::StoreValueAt(Environment &env, Complex *pElem, const Value &value)
{
	if (value.Is_number() || value.Is_boolean()) {
		*pElem = static_cast<Complex>(value.GetDouble());
	} else if (value.Is_complex()) {
		*pElem = value.GetComplex();
	} else {
		Array::SetError_UnacceptableValueAsElement(env, value);
		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// ArrayT::Iterator_Each
//-----------------------------------------------------------------------------
template<typename T_Elem>
size_t ArrayT<T_Elem>::Iterator_Each::GetLength() const
{
	return _flatFlag? _pArrayT->GetElemNum() : _pArrayT->GetDimensions().front().GetSize();
}

template<typename T_Elem>
Iterator *ArrayT<T_Elem>::Iterator_Each::GetSource()
{
	return nullptr;
}

template<typename T_Elem>
bool ArrayT<T_Elem>::Iterator_Each::DoNext(Environment &env, Value &value)
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
			size_t offsetBase = _pArrayT->GetOffsetBase() + pDim->GetStrides() * _idx;
			AutoPtr<ArrayT<T_Elem> > pArrayRtn(new ArrayT<T_Elem>(_pArrayT->GetColMajorFlag()));
			pArrayRtn->SetDimensions(pDim + 1, dims.end());
			pArrayRtn->SetMemory(_pArrayT->GetMemory().Reference(), offsetBase);
			value = Array::ToValue(env, pArrayRtn.release());
		}
	}
	_idx++;
	return true;
}

template<typename T_Elem>
String ArrayT<T_Elem>::Iterator_Each::ToString() const
{
	String rtn;
	rtn = "array";
	return rtn;
}

template<typename T_Elem>
void ArrayT<T_Elem>::Iterator_Each::GatherFollower(
	Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//------------------------------------------------------------------------------
// Realization of ArrayT
//------------------------------------------------------------------------------
ImplementArrayT(Boolean)
ImplementArrayT(Int8)
ImplementArrayT(UInt8)
ImplementArrayT(Int16)
ImplementArrayT(UInt16)
ImplementArrayT(Int32)
ImplementArrayT(UInt32)
ImplementArrayT(Int64)
ImplementArrayT(UInt64)
ImplementArrayT(Half)
ImplementArrayT(Float)
ImplementArrayT(Double)
ImplementArrayT(Complex)
//ImplementArrayT(Value)

//------------------------------------------------------------------------------
// Realization of Iterator_ArrayT_Each
//------------------------------------------------------------------------------
#if 0
template class Iterator_ArrayT_Each<Boolean>;
template class Iterator_ArrayT_Each<Int8>;
template class Iterator_ArrayT_Each<UInt8>;
template class Iterator_ArrayT_Each<Int16>;
template class Iterator_ArrayT_Each<UInt16>;
template class Iterator_ArrayT_Each<Int32>;
template class Iterator_ArrayT_Each<UInt32>;
template class Iterator_ArrayT_Each<Int64>;
template class Iterator_ArrayT_Each<UInt64>;
template class Iterator_ArrayT_Each<Half>;
template class Iterator_ArrayT_Each<Float>;
template class Iterator_ArrayT_Each<Double>;
template class Iterator_ArrayT_Each<Complex>;
//template class Iterator_ArrayT_Each<Value>;
#endif

}
