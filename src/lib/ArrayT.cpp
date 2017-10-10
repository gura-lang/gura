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
void ArrayT<T_Elem>::SetScalar(const T_Elem &num)
{
	_elemNum = 1;
	AllocMemory();
	*GetPointer() = num;
}

template<typename T_Elem>
void ArrayT<T_Elem>::Fill(const T_Elem &num)
{
	T_Elem *pElem = GetPointer();
	for (size_t i = 0; i < GetElemNum(); i++, pElem++) {
		*pElem = num;
	}
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
ArrayT<T_Elem> *ArrayT<T_Elem>::Flatten() const
{
	bool colMajorFlag = false;
	const Array::Dimensions &dims = GetDimensions();
	AutoPtr<ArrayT> pArrayRtn;
	if (IsRowMajor() || dims.size() < 2) {
		pArrayRtn.reset(new ArrayT(colMajorFlag));
		pArrayRtn->SetDimension(GetElemNum());
		pArrayRtn->SetMemory(GetMemory().Reference(), GetOffsetBase());
	} else {
		bool colMajorFlag = false;
		pArrayRtn.reset(ArrayT::Create1d(colMajorFlag, GetElemNum()));
		const T_Elem *pElem = GetPointer();
		T_Elem *pElemRtn = pArrayRtn->GetPointer();
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
	return pArrayRtn.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Reshape(Signal &sig, const ValueList &valList) const
{
	bool unfixedFlag = false;
	size_t nElems = 1;
	foreach_const (ValueList, pValue, valList) {
		if (pValue->Is_number() && pValue->GetNumber() >= 0) {
			nElems *= pValue->GetSizeT();
		} else if (unfixedFlag) {
			sig.SetError(ERR_ValueError, "only one dimension can be specified as an unfixed");
			return nullptr;
		} else {
			unfixedFlag = true;
		}
	}
	if ((unfixedFlag && (GetElemNum() % nElems != 0)) ||
		(!unfixedFlag && (nElems != GetElemNum()))) {
		sig.SetError(ERR_ValueError, "incorrect shape specified");
		return nullptr;
	}
	AutoPtr<ArrayT> pArrayTRtn(new ArrayT(GetColMajorFlag()));
	Dimensions &dims = pArrayTRtn->GetDimensions();
	dims.reserve(valList.size());
	foreach_const (ValueList, pValue, valList) {
		if (pValue->Is_number() && pValue->GetNumber() >= 0) {
			dims.push_back(Dimension(pValue->GetSizeT()));
		} else {
			dims.push_back(Dimension(GetElemNum() / nElems));
		}
	}	
	pArrayTRtn->UpdateMetrics();
	pArrayTRtn->SetMemory(GetMemory().Reference(), GetOffsetBase());
	return pArrayTRtn.release();
}

template<typename T_Elem>
void TransposeSub(T_Elem *&pElemDst, const T_Elem *pElemSrc, const Array::Dimensions &dimsSrc,
				  SizeTList::const_iterator pAxis, SizeTList::const_iterator pAxisEnd)
{
	const Array::Dimension &dimSrc = dimsSrc[*pAxis];
	if (pAxis + 1 == pAxisEnd) {
		for (size_t i = 0; i < dimSrc.GetSize(); i++, pElemSrc += dimSrc.GetStrides(), pElemDst++) {
			*pElemDst = *pElemSrc;
		}
	} else {
		for (size_t i = 0; i < dimSrc.GetSize(); i++, pElemSrc += dimSrc.GetStrides()) {
			TransposeSub(pElemDst, pElemSrc, dimsSrc, pAxis + 1, pAxisEnd);
		}
	}
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Transpose(Signal &sig, const ValueList &valList, Array *pArrayRtn) const
{
	if (GetDimensions().size() != valList.size()) {
		sig.SetError(ERR_ValueError, "mismatched number of axes to transpose");
		return nullptr;
	}
	SizeTList axes;
	foreach_const (ValueList, pValue, valList) {
		size_t axis = pValue->GetSizeT();
		if (std::find(axes.begin(), axes.end(), axis) != axes.end()) {
			sig.SetError(ERR_ValueError, "duplicated axis is specified");
			return nullptr;
		}
		if (axis >= GetDimensions().size()) {
			sig.SetError(ERR_ValueError, "specified axis is out of range");
			return nullptr;
		}
		axes.push_back(axis);
	}
	return Transpose(axes, pArrayRtn);
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Transpose(const SizeTList &axes, Array *pArrayRtn) const
{
	if (axes.size() < 2) return new ArrayT<T_Elem>(*this);
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
	AutoPtr<ArrayT> pArrayTRtn;
	if (pArrayRtn == nullptr) {
		bool colMajorFlag = false;
		pArrayTRtn.reset(new ArrayT(colMajorFlag));
		Dimensions &dimsDst = pArrayTRtn->GetDimensions();
		dimsDst.reserve(GetDimensions().size());
		foreach_const (SizeTList, pAxis, axes) {
			const Dimension &dimSrc = GetDimensions()[*pAxis];
			dimsDst.push_back(Dimension(dimSrc.GetSize()));
		}
		pArrayTRtn->UpdateMetrics();
		if (memorySharableFlag) {
			pArrayTRtn->SetMemory(GetMemory().Reference(), GetOffsetBase());
		} else {
			pArrayTRtn->AllocMemory();
			T_Elem *pElemDst = pArrayTRtn->GetPointer();
			TransposeSub(pElemDst, GetPointer(), GetDimensions(), axes.begin(), axes.end());
		}
	} else {
		pArrayTRtn.reset(dynamic_cast<ArrayT<T_Elem> *>(pArrayRtn->Reference()));
		if (!memorySharableFlag) {
			T_Elem *pElemDst = pArrayTRtn->GetPointer();
			TransposeSub(pElemDst, GetPointer(), GetDimensions(), axes.begin(), axes.end());
		}
	}
	return pArrayTRtn.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::RoundOff(double threshold) const
{
	const Array::Dimensions &dims = GetDimensions();
	bool colMajorFlag = false;
	AutoPtr<ArrayT> pArrayRtn(ArrayT::Create(colMajorFlag, GetDimensions()));
	const T_Elem *pElem = GetPointer();
	T_Elem *pElemRtn = pArrayRtn->GetPointer();
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
	return pArrayRtn.release();
}

template<>
ArrayT<Complex> *ArrayT<Complex>::RoundOff(double threshold) const
{
	typedef Complex T_Elem;
	const Array::Dimensions &dims = GetDimensions();
	double threshold2 = threshold * threshold;
	bool colMajorFlag = false;
	AutoPtr<ArrayT> pArrayRtn(ArrayT::Create(colMajorFlag, GetDimensions()));
	const T_Elem *pElem = GetPointer();
	T_Elem *pElemRtn = pArrayRtn->GetPointer();
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
	return pArrayRtn.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Im2col(size_t htKernel, size_t wdKernel, size_t strides, size_t padding) const
{
	return nullptr;
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Col2im(size_t htKernel, size_t wdKernel, size_t strides, size_t padding) const
{
	return nullptr;
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
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(bool colMajorFlag, Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetDimensions(pDim, pDimEnd);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(bool colMajorFlag, size_t size,
									   Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetDimensions(size, pDim, pDimEnd);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(bool colMajorFlag,
									   Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
									   size_t size)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetDimensions(pDim, pDimEnd, size);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(bool colMajorFlag,
									   Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
									   size_t sizeRow, size_t sizeCol)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetDimensions(pDim, pDimEnd, sizeRow, sizeCol);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(bool colMajorFlag,
									   Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
									   size_t sizePlane, size_t sizeRow, size_t sizeCol)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetDimensions(pDim, pDimEnd, sizePlane, sizeRow, sizeCol);
	pArrayT->AllocMemory();
	return pArrayT.release();
}

template<typename T_Elem>
ArrayT<T_Elem> *ArrayT<T_Elem>::Create(bool colMajorFlag,
									   Dimensions::const_iterator pDim1, Dimensions::const_iterator pDim1End,
									   Dimensions::const_iterator pDim2, Dimensions::const_iterator pDim2End)
{
	AutoPtr<ArrayT> pArrayT(new ArrayT(colMajorFlag));
	pArrayT->SetDimensions(pDim1, pDim1End, pDim2, pDim2End);
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
			if (!StoreValueAt(env, pElem, *pValue)) return false;
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

template<>
void FillComplex(Complex *pElem, size_t nElems, const Complex &num, size_t strides)
{
	for (size_t i = 0; i < nElems; i++, pElem += strides) *pElem = num;
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

}
