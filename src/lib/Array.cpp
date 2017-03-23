//=============================================================================
// Array
//=============================================================================
#include "stdafx.h"
#include "gura/Array.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Array
//-----------------------------------------------------------------------------
Array::~Array()
{
}

String Array::ToString(bool exprFlag) const
{
	return "";
}

bool Array::DoesContainZero() const
{
	return false;
}

bool Array::DoesContainMinus() const
{
	return false;
}

bool Array::DoesContainZeroOrMinus() const
{
	return false;
}

const char *Array::GetElemTypeName() const
{
	const static char *elemTypeNameTbl[ETYPE_Max] = {
		"",
		ArrayT<Int8>::ElemTypeName,
		ArrayT<UInt8>::ElemTypeName,
		ArrayT<Int16>::ElemTypeName,
		ArrayT<UInt16>::ElemTypeName,
		ArrayT<Int32>::ElemTypeName,
		ArrayT<UInt32>::ElemTypeName,
		ArrayT<Int64>::ElemTypeName,
		ArrayT<UInt64>::ElemTypeName,
		ArrayT<Float>::ElemTypeName,
		ArrayT<Double>::ElemTypeName,
		ArrayT<Complex>::ElemTypeName,
	};
	return elemTypeNameTbl[_elemType];
}

void Array::SetDimension(const Dimension &dim)
{
	_dims.reserve(1);
	_dims.push_back(dim);
	UpdateMetrics();
}

void Array::SetDimensions(const Dimension &dimRow, const Dimension &dimCol)
{
	_dims.reserve(2);
	_dims.push_back(dimRow);
	_dims.push_back(dimCol);
	UpdateMetrics();
}

void Array::SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd)
{
	_dims.reserve(std::distance(pDim, pDimEnd));
	std::copy(pDim, pDimEnd, std::back_inserter(_dims));
	UpdateMetrics();
}

void Array::SetDimensions(const Dimension &dim,
						  Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd)
{
	_dims.reserve(std::distance(pDim, pDimEnd) + 1);
	_dims.push_back(dim);
	_dims.insert(_dims.end(), pDim, pDimEnd);
	UpdateMetrics();
}

void Array::SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
						  const Dimension &dim)
{
	_dims.reserve(std::distance(pDim, pDimEnd) + 1);
	_dims.insert(_dims.end(), pDim, pDimEnd);
	_dims.push_back(dim);
	UpdateMetrics();
}

void Array::SetDimensions(const Dimensions &dims)
{
	_dims = dims;
	UpdateMetrics();
}

void Array::SetDimensions(const ValueList &valList)
{
	_dims.reserve(valList.size());
	foreach_const (ValueList, pValue, valList) {
		_dims.push_back(pValue->GetSizeT());
	}
	UpdateMetrics();
}

void Array::SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
						  const Dimension &dimRow, const Dimension &dimCol)
{
	_dims.reserve(std::distance(pDim, pDimEnd) + 2);
	_dims.insert(_dims.end(), pDim, pDimEnd);
	_dims.push_back(dimRow);
	_dims.push_back(dimCol);
	UpdateMetrics();
}

void Array::UpdateMetrics()
{
	size_t stride = 1;
	foreach_reverse (Dimensions, pDim, _dims) {
		pDim->SetStride(stride);
		stride *= pDim->GetSize();
	}
	_elemNum = stride;
}

bool Array::HasShape(size_t size) const
{
	return (_dims.size() == 1) && _dims[0].GetSize() == size;
}

bool Array::HasShape(size_t sizeRow, size_t sizeCol) const
{
	return (_dims.size() == 2) && _dims[0].GetSize() == sizeRow && _dims[1].GetSize() == sizeCol;
}

bool Array::PrepareModification(Signal &sig)
{
	if (_pMemory->GetCntRef() > 1) {
		_pMemory.reset(_pMemory->Clone());
		if (_pMemory.IsNull()) {
			sig.SetError(ERR_MemoryError, "failed to allocate memory for array");
			return false;
		}
	}
	return true;
}

bool Array::CheckShape(Signal &sig, const Array *pArrayA, const Array *pArrayB)
{
	if (Dimensions::IsSameShape(pArrayA->GetDimensions(), pArrayB->GetDimensions())) {
		return true;
	}
	sig.SetError(ERR_ValueError, "different dimension of arrays");
	return false;
}

bool Array::CheckElemwiseCalculatable(Signal &sig, const Array *pArrayL, const Array *pArrayR)
{
	if (Dimensions::IsElemwiseCalculatable(
			pArrayL->GetDimensions(), pArrayR->GetDimensions())) {
		return true;
	}
	sig.SetError(ERR_ValueError, "dimensions mismatch for the operation");
	return false;
}

Array *Array::ApplyUnaryFunc(Signal &sig, const UnaryFuncPack &pack, const Array *pArray)
{
	UnaryFunc unaryFunc = pack.unaryFuncs[pArray->GetElemType()];
	if (unaryFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*unaryFunc)(sig, pArray);
}

Value Array::ApplyUnaryFunc(Environment &env, const UnaryFuncPack &pack, const Value &value)
{
	Array *pArray = ApplyUnaryFunc(
		env.GetSignal(), pack, Object_array::GetObject(value)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Value(new Object_array(env, pArray));
}

Array *Array::ApplyBinaryFunc_array_array(
	Signal &sig, const BinaryFuncPack &pack, const Array *pArrayL, const Array *pArrayR)
{
	if (!CheckElemwiseCalculatable(sig, pArrayL, pArrayR)) return nullptr;
	BinaryFunc_array_array binaryFunc_array_array =
		pack.binaryFuncs_array_array[pArrayL->GetElemType()][pArrayR->GetElemType()];
	if (binaryFunc_array_array == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_array_array)(sig, pArrayL, pArrayR);
}

Value Array::ApplyBinaryFunc_array_array(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_array_array(
		env.GetSignal(), pack,
		Object_array::GetObject(valueL)->GetArray(),
		Object_array::GetObject(valueR)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Value(new Object_array(env, pArray));
}

Array *Array::ApplyBinaryFunc_array_number(
	Signal &sig, const BinaryFuncPack &pack, const Array *pArrayL, Number numberR)
{
	BinaryFunc_array_number binaryFunc_array_number =
		pack.binaryFuncs_array_number[pArrayL->GetElemType()];
	if (binaryFunc_array_number == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_array_number)(sig, pArrayL, numberR);
}

Value Array::ApplyBinaryFunc_array_number(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_array_number(
		env.GetSignal(), pack,
		Object_array::GetObject(valueL)->GetArray(), valueR.GetNumber());
	if (pArray == nullptr) return Value::Nil;
	return Value(new Object_array(env, pArray));
}

Array *Array::ApplyBinaryFunc_number_array(
	Signal &sig, const BinaryFuncPack &pack, Number numberL, const Array *pArrayR)
{
	BinaryFunc_number_array binaryFunc_number_array =
		pack.binaryFuncs_number_array[pArrayR->GetElemType()];
	if (binaryFunc_number_array == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_number_array)(sig, numberL, pArrayR);
}

Value Array::ApplyBinaryFunc_number_array(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_number_array(
		env.GetSignal(), pack,
		valueL.GetNumber(), Object_array::GetObject(valueR)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Value(new Object_array(env, pArray));
}

Value Array::Dot(Environment &env, const Array *pArrayL, const Array *pArrayR)
{
	DotFunc dotFunc = dotFuncs[pArrayL->GetElemType()][pArrayR->GetElemType()];
	if (dotFunc == nullptr) {
		env.SetError(ERR_TypeError, "can't apply dot function on these arrays");
		return Value::Nil;
	}
	return (*dotFunc)(env, pArrayL, pArrayR);
}

Array *Array::Invert(Signal &sig, const Array *pArray)
{
	UnaryFunc invertFunc = invertFuncs[pArray->GetElemType()];
	if (invertFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply invert function on this array");
		return nullptr;
	}
	return (*invertFunc)(sig, pArray);
}

//-----------------------------------------------------------------------------
// Array::Dimension
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Array::Dimensions
//-----------------------------------------------------------------------------
bool Array::Dimensions::IsSameShape(const Dimensions &dimsA, const Dimensions &dimsB)
{
	if (dimsA.size() != dimsB.size()) return false;
	Dimensions::const_iterator pDimA = dimsA.begin();
	Dimensions::const_iterator pDimB = dimsB.begin();
	for ( ; pDimA != dimsA.end(); pDimA++, pDimB++) {
		if (pDimA->GetSize() != pDimB->GetSize()) return false;
	}
	return true;
}

bool Array::Dimensions::IsElemwiseCalculatable(const Dimensions &dimsA, const Dimensions &dimsB)
{
	Dimensions::const_reverse_iterator pA = dimsA.rbegin();
	Dimensions::const_reverse_iterator pB = dimsB.rbegin();
	for ( ; pA != dimsA.rend() && pB != dimsB.rend(); pA++, pB++) {
		if (pA->GetSize() != pB->GetSize()) return false;
	}
	return true;
}

//------------------------------------------------------------------------------
// UnaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_Elem, void (*op)(T_ElemResult &, const T_Elem &)>
Array *UnaryFuncTmpl(Signal &sig, const Array *pArray)
{
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(ArrayT<T_ElemResult>::
												CreateLike(pArray->GetDimensions()));
	T_ElemResult *pResult = pArrayResult->GetPointer();
	const T_Elem *pElem = dynamic_cast<const ArrayT<T_Elem> *>(pArray)->GetPointer();
	size_t nElems = pArray->GetElemNum();
	for (size_t i = 0; i < nElems; i++, pResult++, pElem++) {
		op(*pResult, *pElem);
	}
	return pArrayResult.release();
}

template<typename T_ElemResult, typename T_Elem, void (*op)(T_ElemResult &, const T_Elem &)>
Array *UnaryFuncTmpl_ExcludeZero(Signal &sig, const Array *pArray)
{
	if (pArray->DoesContainZero()) {
		sig.SetError(ERR_MathError, "the array contains zero as its element");
		return nullptr;
	}
	return UnaryFuncTmpl<T_ElemResult, T_Elem, op>(sig, pArray);
}

//------------------------------------------------------------------------------
// BinaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemResult &, const T_ElemL &, const T_ElemR &)>
Array *BinaryFuncTmpl_array_array(Signal &sig, const Array *pArrayL, const Array *pArrayR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult;
	if (nElemsL == nElemsR) {
		pArrayResult.reset(ArrayT<T_ElemResult>::CreateLike(pArrayL->GetDimensions()));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		for (size_t offset = 0; offset < nElemsL; offset++, pElemResult++) {
			op(*pElemResult, *(pElemL + offset), *(pElemR + offset));
		}
	} else if (nElemsL < nElemsR) {
		pArrayResult.reset(ArrayT<T_ElemResult>::CreateLike(pArrayR->GetDimensions()));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		size_t offsetL = 0;
		for (size_t offsetR = 0; offsetR < nElemsR; offsetR++, pElemResult++) {
			op(*pElemResult, *(pElemL + offsetL), *(pElemR + offsetR));
			offsetL++;
			if (offsetL >= nElemsL) offsetL = 0;
		}
	} else { // nElemsL > nElemsR
		pArrayResult.reset(ArrayT<T_ElemResult>::CreateLike(pArrayL->GetDimensions()));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		size_t offsetR = 0;
		for (size_t offsetL = 0; offsetL < nElemsL; offsetL++, pElemResult++) {
			op(*pElemResult, *(pElemL + offsetL), *(pElemR + offsetR));
			offsetR++;
			if (offsetR >= nElemsR) offsetR = 0;
		}
	}
	return pArrayResult.release();
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemResult &, const T_ElemL &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_array_array(Signal &sig, const Array *pArrayL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_array<T_ElemResult, T_ElemL, T_ElemR, op>(sig, pArrayL, pArrayR);
}

template<typename T_ElemL, void (*op)(T_ElemL &, const T_ElemL &, const Double &)>
Array *BinaryFuncTmpl_array_number(Signal &sig, const Array *pArrayL, Double numberR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	AutoPtr<ArrayT<T_ElemL> > pArrayResult(ArrayT<T_ElemL>::CreateLike(pArrayL->GetDimensions()));
	T_ElemL *pElemResult = pArrayResult->GetPointer();
	for (size_t i = 0; i < nElemsL; i++, pElemResult++, pElemL++) {
		op(*pElemResult, *pElemL, numberR);
	}
	return pArrayResult.release();
}

template<typename T_ElemL, void (*op)(T_ElemL &, const T_ElemL &, const Double &)>
Array *BinaryFuncTmpl_Div_array_number(Signal &sig, const Array *pArrayL, Double numberR)
{
	if (numberR == 0) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_number<T_ElemL, op>(sig, pArrayL, numberR);
}

template<typename T_ElemR, void (*op)(T_ElemR &, const Double &, const T_ElemR &)>
Array *BinaryFuncTmpl_number_array(Signal &sig, Double numberL, const Array *pArrayR)
{
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemR> > pArrayResult(ArrayT<T_ElemR>::CreateLike(pArrayR->GetDimensions()));
	T_ElemR *pElemResult = pArrayResult->GetPointer();
	for (size_t i = 0; i < nElemsR; i++, pElemResult++, pElemR++) {
		op(*pElemResult, numberL, *pElemR);
	}
	return pArrayResult.release();
}

template<typename T_ElemR, void (*op)(T_ElemR &, const Double &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_number_array(Signal &sig, Double numberL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_number_array<T_ElemR, op>(sig, numberL, pArrayR);
}

//------------------------------------------------------------------------------
// DotFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_1d_2d(T_ElemResult *pElemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR,
					   size_t nRowR, size_t nColR)
{
	const T_ElemR *pElemBaseR = pElemR;
	for (size_t iColR = 0; iColR < nColR; iColR++, pElemBaseR++) {
		const T_ElemL *pElemWorkL = pElemL;
		const T_ElemR *pElemWorkR = pElemBaseR;
		T_ElemResult elemResult = 0;
		for (size_t iRowR = 0; iRowR < nRowR; iRowR++, pElemWorkL++, pElemWorkR += nColR) {
			elemResult +=
				static_cast<T_ElemResult>(*pElemWorkL) *
				static_cast<T_ElemResult>(*pElemWorkR);
		}
		*pElemResult++ = elemResult;
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_2d_1d(T_ElemResult *pElemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR,
					   size_t nRowL, size_t nColL)
{
	const T_ElemL *pElemBaseL = pElemL;
	for (size_t iRowL = 0; iRowL < nRowL; iRowL++, pElemBaseL += nColL) {
		const T_ElemL *pElemWorkL = pElemBaseL;
		const T_ElemR *pElemWorkR = pElemR;
		T_ElemResult elemResult = 0;
		for (size_t iColL = 0; iColL < nColL; iColL++, pElemWorkL++, pElemWorkR++) {
			elemResult +=
				static_cast<T_ElemResult>(*pElemWorkL) *
				static_cast<T_ElemResult>(*pElemWorkR);
		}
		*pElemResult++ = elemResult;
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_2d_2d(T_ElemResult *pElemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR,
					   size_t nRowL, size_t nColL_nRowR, size_t nColR)
{
	const T_ElemL *pElemBaseL = pElemL;
	for (size_t iRow = 0; iRow < nRowL; iRow++, pElemBaseL += nColL_nRowR) {
		const T_ElemR *pElemBaseR = pElemR;
		for (size_t iCol = 0; iCol < nColR; iCol++, pElemBaseR++) {
			const T_ElemL *pElemWorkL = pElemBaseL;
			const T_ElemR *pElemWorkR = pElemBaseR;
			T_ElemResult elemResult = 0;
			for (size_t i = 0; i < nColL_nRowR; i++, pElemWorkL++, pElemWorkR += nColR) {
				elemResult +=
					static_cast<T_ElemResult>(*pElemWorkL) *
					static_cast<T_ElemResult>(*pElemWorkR);
			}
			*pElemResult++ = elemResult;
		}
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_1d_1d(T_ElemResult &elemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR, size_t nColL)
{
	elemResult = 0;
	for (size_t iColL = 0; iColL < nColL; iColL++, pElemL++, pElemR++) {
		elemResult +=
			static_cast<T_ElemResult>(*pElemL) *
			static_cast<T_ElemResult>(*pElemR);
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value DotFuncTmpl(Environment &env, const Array *pArrayL, const Array *pArrayR)
{
	const Array::Dimensions &dimsL = pArrayL->GetDimensions();
	const Array::Dimensions &dimsR = pArrayR->GetDimensions();
	if (dimsL.size() == 1 && dimsR.size() == 1) {
		T_ElemResult elemResult = 0;
		size_t nColL = dimsL[0].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		if (nColL != nRowR) {
			env.SetError(ERR_ValueError, "dimensions mismatch for the dot product");
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		DotFuncTmpl_1d_1d(elemResult, pElemL, pElemR, nColL);
		return Value(elemResult);
	}
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult;
	if (dimsL.size() == 1 && dimsR.size() == 2) {
		size_t nColL = dimsL[0].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		size_t nColR = dimsR[1].GetSize();
		if (nColL != nRowR) {
			env.SetError(ERR_ValueError, "dimensions mismatch for the dot product");
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		pArrayResult.reset(new ArrayT<T_ElemResult>(nColR));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		DotFuncTmpl_1d_2d(pElemResult, pElemL, pElemR, nRowR, nColR);
	} else if (dimsL.size() == 2 && dimsR.size() == 1) {
		size_t nRowL = dimsL[0].GetSize();
		size_t nColL = dimsL[1].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		if (nColL != nRowR) {
			env.SetError(ERR_ValueError, "dimensions mismatch for the dot product");
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		pArrayResult.reset(new ArrayT<T_ElemResult>(nRowL));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		DotFuncTmpl_2d_1d(pElemResult, pElemL, pElemR, nRowL, nColL);
	} else if (dimsL.size() == 2 && dimsR.size() == 2) {
		size_t nRowL = dimsL[0].GetSize();
		size_t nColL = dimsL[1].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		size_t nColR = dimsR[1].GetSize();
		if (nColL != nRowR) {
			env.SetError(ERR_ValueError, "dimensions mismatch for the dot product");
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		pArrayResult.reset(new ArrayT<T_ElemResult>(nRowL, nColR));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		DotFuncTmpl_2d_2d(pElemResult, pElemL, pElemR, nRowL, nColL, nColR);
	} else if (dimsL.size() >= 2 && dimsR.size() >= 2) {
		size_t nRowL = (dimsL.rbegin() + 1)->GetSize();
		size_t nColL = dimsL.rbegin()->GetSize();
		size_t nRowR = (dimsR.rbegin() + 1)->GetSize();
		size_t nColR = dimsR.rbegin()->GetSize();
		if (nColL != nRowR) {
			env.SetError(ERR_ValueError, "dimensions mismatch for the dot product");
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		size_t elemNumL = pArrayL->GetElemNum();
		size_t elemNumR = pArrayR->GetElemNum();
		size_t elemNumMatResult = nRowL * nColR;
		size_t elemNumMatL = nRowL * nColL;
		size_t elemNumMatR = nRowR * nColR;
		size_t offsetL = 0, offsetR = 0;
		if (dimsL.size() < dimsR.size()) {
			pArrayResult.reset(new ArrayT<T_ElemResult>());
			pArrayResult->SetDimensions(dimsR.begin(), dimsR.begin() + dimsR.size() - 2,
										Array::Dimension(nRowL), Array::Dimension(nColR));
			pArrayResult->AllocMemory();
			T_ElemResult *pElemResult = pArrayResult->GetPointer();
			while (offsetR < elemNumR) {
				DotFuncTmpl_2d_2d(pElemResult, pElemL + offsetL, pElemR + offsetR,
								  nRowL, nColL, nColR);
				pElemResult += elemNumMatResult;
				offsetL += elemNumMatL;
				offsetR += elemNumMatR;
				if (offsetL >= elemNumL) offsetL = 0;
			}
		} else { // dimsL.size() >= dimsR.size()
			pArrayResult.reset(new ArrayT<T_ElemResult>());
			pArrayResult->SetDimensions(dimsL.begin(), dimsL.begin() + dimsL.size() - 2,
										Array::Dimension(nRowL), Array::Dimension(nColR));
			pArrayResult->AllocMemory();
			T_ElemResult *pElemResult = pArrayResult->GetPointer();
			while (offsetL < elemNumL) {
				DotFuncTmpl_2d_2d(pElemResult, pElemL + offsetL, pElemR + offsetR,
								  nRowL, nColL, nColR);
				pElemResult += elemNumMatResult;
				offsetL += elemNumMatL;
				offsetR += elemNumMatR;
				if (offsetR >= elemNumR) offsetR = 0;
			}
		}
	} else if (dimsL.size() == 1 && dimsR.size() >= 2) {
		size_t nColL = dimsL[0].GetSize();
		size_t nRowR = (dimsR.rbegin() + 1)->GetSize();
		size_t nColR = dimsR.rbegin()->GetSize();
		if (nColL != nRowR) {
			env.SetError(ERR_ValueError, "dimensions mismatch for the dot product");
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		size_t elemNumR = pArrayR->GetElemNum();
		size_t elemNumMatR = nRowR * nColR;
		size_t offsetR = 0;
		pArrayResult.reset(new ArrayT<T_ElemResult>());
		pArrayResult->SetDimensions(dimsR.begin(), dimsR.begin() + dimsR.size() - 2,
									Array::Dimension(nColR));
		pArrayResult->AllocMemory();
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		while (offsetR < elemNumR) {
			DotFuncTmpl_1d_2d(pElemResult, pElemL, pElemR + offsetR, nRowR, nColR);
			pElemResult += nColR;
			offsetR += elemNumMatR;
		}
	} else if (dimsL.size() >= 2 && dimsR.size() == 1) {
		size_t nRowL = (dimsL.rbegin() + 1)->GetSize();
		size_t nColL = dimsL.rbegin()->GetSize();
		size_t nRowR = dimsR[0].GetSize();
		if (nColL != nRowR) {
			env.SetError(ERR_ValueError, "dimensions mismatch for the dot product");
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		size_t elemNumL = pArrayL->GetElemNum();
		size_t elemNumMatL = nRowL * nColL;
		size_t offsetL = 0;
		pArrayResult.reset(new ArrayT<T_ElemResult>());
		pArrayResult->SetDimensions(dimsL.begin(), dimsL.begin() + dimsL.size() - 2,
									Array::Dimension(nRowL));
		pArrayResult->AllocMemory();
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		while (offsetL < elemNumL) {
			DotFuncTmpl_2d_1d(pElemResult, pElemL + offsetL, pElemR, nRowL, nColL);
			pElemResult += nRowR;
			offsetL += elemNumMatL;
		}
	}
	return Value(new Object_array(env, pArrayResult.release()));
}

//------------------------------------------------------------------------------
// InvertFuncTmpl
//------------------------------------------------------------------------------
template<typename T_Elem> inline T_Elem _Norm(T_Elem num) { return std::abs(num); }
template<> inline Complex _Norm(Complex num) { return std::norm(num); }
template<typename T_Elem> inline T_Elem _NormEpsilon() { return 1.0e-6; }
template<> inline Complex _NormEpsilon() { return _NormEpsilon<Double>() * _NormEpsilon<Double>(); }

template<typename T_Elem>
bool InvertFuncTmpl_Sub(T_Elem *pElemResult, const T_Elem *pElemOrg, size_t nRows,
						T_Elem &det, T_Elem *pElemWork, T_Elem *rows[])
{
	static const T_Elem normEpsilon = _NormEpsilon<T_Elem>();
	size_t nCols = nRows;
	size_t nCols2 = nCols * 2;
	size_t bytesPerRow = nCols * sizeof(T_Elem);
	det = 1;
	do {
		const T_Elem *pElemSrc = pElemOrg;
		T_Elem *pElemDst = pElemWork;
		::memset(pElemWork, 0x00, nRows * nCols2 * sizeof(T_Elem));
		for (size_t iRow = 0; iRow < nRows; iRow++, pElemDst += nCols2, pElemSrc += nCols) {
			::memcpy(pElemDst, pElemSrc, bytesPerRow);
			*(pElemDst + nCols + iRow) = 1;
			rows[iRow] = pElemDst;
		}
	} while (0);
	for (size_t iRowPivot = 0; iRowPivot < nRows; iRowPivot++) {
		size_t iRowMax = iRowPivot;
		T_Elem normMax = _Norm(rows[iRowMax][iRowPivot]);
		for (size_t iRow = iRowMax + 1; iRow < nRows; iRow++) {
			T_Elem norm = _Norm(rows[iRow][iRowPivot]);
			if (normMax < norm) {
				iRowMax = iRow;
				normMax = norm;
			}
		}
		if (normMax < normEpsilon) {
			det = 0;
			return false;
		}
		if (iRowPivot != iRowMax) {
			std::swap(rows[iRowPivot], rows[iRowMax]);
			det = -det;
		}
		do {
			T_Elem *pElemPivot = rows[iRowPivot];
			T_Elem factor = *(pElemPivot + iRowPivot);
			det *= factor;
			for (size_t cnt = nCols2; cnt > 0; cnt--, pElemPivot++) {
				*pElemPivot /= factor;
			}
		} while (0);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			if (iRowPivot == iRow) continue;
			T_Elem *pElemPivot = rows[iRowPivot];
			T_Elem *pElemEach = rows[iRow];
			T_Elem factor = *(pElemEach + iRowPivot);
			for (size_t cnt = nCols2; cnt > 0; cnt--, pElemPivot++, pElemEach++) {
				*pElemEach -= *pElemPivot * factor;
			}
		}
	}
	if (pElemResult != nullptr) {
		T_Elem *pElemDst = pElemResult;
		for (size_t iRow = 0; iRow < nRows; iRow++, pElemDst += nCols) {
			::memcpy(pElemDst, rows[iRow] + nCols, bytesPerRow);
		}
	}
	return true;
}

template<typename T_Elem>
Array *InvertFuncTmpl(Signal &sig, const Array *pArray)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	if (dims.size() < 2) {
		sig.SetError(ERR_ValueError, "inversion can only be calculated with matrix");
		return nullptr;
	}
	size_t nRows = (dims.rbegin() + 1)->GetSize();
	size_t nCols = dims.rbegin()->GetSize();
	if (nRows != nCols) {
		sig.SetError(ERR_ValueError, "inversion can only be applied to square matrix");
		return nullptr;
	}
	std::unique_ptr<T_Elem []> pElemWork(new T_Elem [nRows * nCols * 2]);
	std::unique_ptr<T_Elem *[]> rows(new T_Elem *[nRows]);
	AutoPtr<ArrayT<T_Elem> > pArrayResult(ArrayT<T_Elem>::CreateLike(pArrayT->GetDimensions()));
	size_t elemNumMat = nRows * nCols;
	const T_Elem *pElemOrg = pArrayT->GetPointer();
	T_Elem *pElemResult = pArrayResult->GetPointer();
	for (size_t cnt = pArrayResult->GetElemNum() / elemNumMat; cnt > 0; cnt--) {
		T_Elem det = 0;
		if (!InvertFuncTmpl_Sub(pElemResult, pElemOrg, nRows, det, pElemWork.get(), rows.get())) {
			sig.SetError(ERR_ValueError, "failed to calculate inverted matrix");
			return nullptr;
		}
		pElemResult += elemNumMat;
		pElemOrg += elemNumMat;
	}
	return pArrayResult.release();
}

//------------------------------------------------------------------------------
// Function tables
//------------------------------------------------------------------------------
#define ImplementUnaryFuncPack(op, name, func) \
Array::UnaryFuncPack Array::unaryFuncPack_##op = { \
	name, \
	{ \
		nullptr, \
		&func<Int8,		Int8,	Operator_##op::Calc>,	\
		&func<UInt8,	UInt8,	Operator_##op::Calc>,	\
		&func<Int16,	Int16,	Operator_##op::Calc>,	\
		&func<UInt16,	UInt16,	Operator_##op::Calc>,	\
		&func<Int32,	Int32,	Operator_##op::Calc>,	\
		&func<UInt32,	UInt32,	Operator_##op::Calc>,	\
		&func<Int64,	Int64,	Operator_##op::Calc>,	\
		&func<UInt64,	UInt64,	Operator_##op::Calc>,	\
		&func<Float,	Float,	Operator_##op::Calc>,	\
		&func<Double,	Double,	Operator_##op::Calc>,	\
		nullptr, \
	}, \
}

#define ImplementBinaryFuncPack(op, name, funcPrefix)			 \
Array::BinaryFuncPack Array::binaryFuncPack_##op = { \
	name, \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int8,		Int8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	Int8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Int8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int8,		Double,		Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt8,	UInt8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	UInt8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	UInt8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	UInt8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt8,		Double,		Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int16,	Int16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Int16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int16,		Double,		Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	UInt16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt16,		Double,		Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int32,	Int32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int32,		Double,		Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt32,		Double,		Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int64,	Int64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int64,		Double,		Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt64,		Double,		Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Float,	Float,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Float,		Double,		Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Double,	Double,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Double,		Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, \
	}, { \
		nullptr, \
		&funcPrefix##_array_number<Int8,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt8,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int16,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt16,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int32,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt32,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int64,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt64,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Float,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Double,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_number_array<Int8,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt8,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int16,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt16,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int32,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt32,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int64,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt64,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Float,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Double,	Operator_##op::Calc>, \
		nullptr, \
	} \
}

#define ImplementBinaryFuncPack_BitOp(op, name) \
Array::BinaryFuncPack Array::binaryFuncPack_##op = { \
	name, \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int8,		Int8,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		Int8,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int8,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Int8,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int8,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int8,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int8,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int8,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		UInt8,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt8,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		UInt8,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt8,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt8,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt8,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Int16,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int16,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		Int16,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int16,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int16,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		UInt16,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt16,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt16,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt16,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		Int32,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int32,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int32,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt32,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt32,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int64,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, \
	}, { \
		nullptr, \
		&BinaryFuncTmpl_array_number<Int8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt16,	Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt32,	Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int64,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt64,	Operator_##op::Calc>,	\
		nullptr, \
		nullptr, \
		nullptr, \
	}, { \
		nullptr, \
		&BinaryFuncTmpl_number_array<Int8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt16,	Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt32,	Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int64,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt64,	Operator_##op::Calc>,	\
		nullptr, \
		nullptr, \
		nullptr, \
	} \
}

ImplementUnaryFuncPack(Pos,				"pos",			UnaryFuncTmpl);
ImplementUnaryFuncPack(Neg,				"neg",			UnaryFuncTmpl);

ImplementBinaryFuncPack(Add,			"add",			BinaryFuncTmpl);
ImplementBinaryFuncPack(Sub,			"sub",			BinaryFuncTmpl);
ImplementBinaryFuncPack(Mul,			"mul",			BinaryFuncTmpl);
ImplementBinaryFuncPack(Div,			"div",			BinaryFuncTmpl_Div);
ImplementBinaryFuncPack(Mod,			"mod",			BinaryFuncTmpl_Div);
ImplementBinaryFuncPack(Pow,			"pow",			BinaryFuncTmpl);

ImplementBinaryFuncPack_BitOp(And,		"and");
ImplementBinaryFuncPack_BitOp(Or,		"or");
ImplementBinaryFuncPack_BitOp(Xor,		"xor");
ImplementBinaryFuncPack_BitOp(Shl,		"shl");
ImplementBinaryFuncPack_BitOp(Shr,		"shr");

ImplementUnaryFuncPack(Math_abs,		"math.abs",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_acos,		"math.acos",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_arg,		"math.arg",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_asin,		"math.asin",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_atan,		"math.atan",	UnaryFuncTmpl);
ImplementBinaryFuncPack(Math_atan2,		"math.atan2",	BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_ceil,		"math.ceil",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_conj,		"math.conj",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_cos,		"math.cos",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_cosh,		"math.cosh",	UnaryFuncTmpl);
//ImplementBinaryFuncPack(Math_cross,	"math.cross",	BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_delta,		"math.delta",	UnaryFuncTmpl);
//ImplementBinaryFuncPack(Math_dot,		"math.dot",		BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_exp,		"math.exp",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_floor,		"math.floor",	UnaryFuncTmpl);
ImplementBinaryFuncPack(Math_hypot,		"math.hypot",	BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_imag,		"math.imag",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_log,		"math.log",		UnaryFuncTmpl_ExcludeZero);
ImplementUnaryFuncPack(Math_log10,		"math.log10",	UnaryFuncTmpl_ExcludeZero);
ImplementUnaryFuncPack(Math_norm,		"math.norm",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_ramp,		"math.ramp",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_real,		"math.real",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sin,		"math.sin",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sinh,		"math.sinh",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sqrt,		"math.sqrt",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_tan,		"math.tan",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_tanh,		"math.tanh",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_unitstep,	"math.unitstep",UnaryFuncTmpl);

Array::DotFunc Array::dotFuncs[ETYPE_Max][ETYPE_Max] = {
	{
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int8,		Int8,		Int8	>,
		&DotFuncTmpl<UInt8,		Int8,		UInt8	>,
		&DotFuncTmpl<Int16,		Int8,		Int16	>,
		&DotFuncTmpl<UInt16,	Int8,		UInt16	>,
		&DotFuncTmpl<Int32,		Int8,		Int32	>,
		&DotFuncTmpl<UInt32,	Int8,		UInt32	>,
		&DotFuncTmpl<Int64,		Int8,		Int64	>,
		&DotFuncTmpl<UInt64,	Int8,		UInt64	>,
		&DotFuncTmpl<Float,		Int8,		Float	>,
		&DotFuncTmpl<Double,	Int8,		Double	>,
		//&DotFuncTmpl<Complex,	UInt8,		Complex	>,
	}, {
		nullptr,
		&DotFuncTmpl<UInt8,		UInt8,		Int8	>,
		&DotFuncTmpl<UInt8,		UInt8,		UInt8	>,
		&DotFuncTmpl<Int16,		UInt8,		Int16	>,
		&DotFuncTmpl<UInt16,	UInt8,		UInt16	>,
		&DotFuncTmpl<Int32,		UInt8,		Int32	>,
		&DotFuncTmpl<UInt32,	UInt8,		UInt32	>,
		&DotFuncTmpl<Int64,		UInt8,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt8,		UInt64	>,
		&DotFuncTmpl<Float,		UInt8,		Float	>,
		&DotFuncTmpl<Double,	UInt8,		Double	>,
		//&DotFuncTmpl<Complex,	UInt8,		Complex	>,
	}, {
		nullptr,
		&DotFuncTmpl<Int16,		Int16,		Int8	>,
		&DotFuncTmpl<Int16,		Int16,		UInt8	>,
		&DotFuncTmpl<Int16,		Int16,		Int16	>,
		&DotFuncTmpl<UInt16,	Int16,		UInt16	>,
		&DotFuncTmpl<Int32,		Int16,		Int32	>,
		&DotFuncTmpl<UInt32,	Int16,		UInt32	>,
		&DotFuncTmpl<Int64,		Int16,		Int64	>,
		&DotFuncTmpl<UInt64,	Int16,		UInt64	>,
		&DotFuncTmpl<Float,		Int16,		Float	>,
		&DotFuncTmpl<Double,	Int16,		Double	>,
		//&DotFuncTmpl<Complex,	Int16,		Complex	>,
	}, {
		nullptr,
		&DotFuncTmpl<UInt16,	UInt16,		Int8	>,
		&DotFuncTmpl<UInt16,	UInt16,		UInt8	>,
		&DotFuncTmpl<UInt16,	UInt16,		Int16	>,
		&DotFuncTmpl<UInt16,	UInt16,		UInt16	>,
		&DotFuncTmpl<Int32,		UInt16,		Int32	>,
		&DotFuncTmpl<UInt32,	UInt16,		UInt32	>,
		&DotFuncTmpl<Int64,		UInt16,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt16,		UInt64	>,
		&DotFuncTmpl<Float,		UInt16,		Float	>,
		&DotFuncTmpl<Double,	UInt16,		Double	>,
		//&DotFuncTmpl<Complex,	UInt16,		Complex	>,
	}, {
		nullptr,
		&DotFuncTmpl<Int32,		Int32,		Int8	>,
		&DotFuncTmpl<Int32,		Int32,		UInt8	>,
		&DotFuncTmpl<Int32,		Int32,		Int16	>,
		&DotFuncTmpl<Int32,		Int32,		UInt16	>,
		&DotFuncTmpl<Int32,		Int32,		Int32	>,
		&DotFuncTmpl<UInt32,	Int32,		UInt32	>,
		&DotFuncTmpl<Int64,		Int32,		Int64	>,
		&DotFuncTmpl<UInt64,	Int32,		UInt64	>,
		&DotFuncTmpl<Float,		Int32,		Float	>,
		&DotFuncTmpl<Double,	Int32,		Double	>,
		//&DotFuncTmpl<Complex,	Int32,		Complex	>,
	}, {
		nullptr,
		&DotFuncTmpl<UInt32,	UInt32,		Int8	>,
		&DotFuncTmpl<UInt32,	UInt32,		UInt8	>,
		&DotFuncTmpl<UInt32,	UInt32,		Int16	>,
		&DotFuncTmpl<UInt32,	UInt32,		UInt16	>,
		&DotFuncTmpl<UInt32,	UInt32,		Int32	>,
		&DotFuncTmpl<UInt32,	UInt32,		UInt32	>,
		&DotFuncTmpl<Int64,		UInt32,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt32,		UInt64	>,
		&DotFuncTmpl<Float,		UInt32,		Float	>,
		&DotFuncTmpl<Double,	UInt32,		Double	>,
		//&DotFuncTmpl<Complex,	UInt32,		Complex	>,
	}, {
		nullptr,
		&DotFuncTmpl<Int64,		Int64,		Int8	>,
		&DotFuncTmpl<Int64,		Int64,		UInt8	>,
		&DotFuncTmpl<Int64,		Int64,		Int16	>,
		&DotFuncTmpl<Int64,		Int64,		UInt16	>,
		&DotFuncTmpl<Int64,		Int64,		Int32	>,
		&DotFuncTmpl<Int64,		Int64,		UInt32	>,
		&DotFuncTmpl<Int64,		Int64,		Int64	>,
		&DotFuncTmpl<UInt64,	Int64,		UInt64	>,
		&DotFuncTmpl<Float,		Int64,		Float	>,
		&DotFuncTmpl<Double,	Int64,		Double	>,
		//&DotFuncTmpl<Complex,	Int64,		Complex	>,
	}, {
		nullptr,
		&DotFuncTmpl<UInt64,	UInt64,		Int8	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt8	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int16	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt16	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int32	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt32	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt64	>,
		&DotFuncTmpl<Float,		UInt64,		Float	>,
		&DotFuncTmpl<Double,	UInt64,		Double	>,
		//&DotFuncTmpl<Complex,	UInt64,		Complex	>,
	}, {
		nullptr,
		&DotFuncTmpl<Float,		Float,		Int8	>,
		&DotFuncTmpl<Float,		Float,		UInt8	>,
		&DotFuncTmpl<Float,		Float,		Int16	>,
		&DotFuncTmpl<Float,		Float,		UInt16	>,
		&DotFuncTmpl<Float,		Float,		Int32	>,
		&DotFuncTmpl<Float,		Float,		UInt32	>,
		&DotFuncTmpl<Float,		Float,		Int64	>,
		&DotFuncTmpl<Float,		Float,		UInt64	>,
		&DotFuncTmpl<Float,		Float,		Float	>,
		&DotFuncTmpl<Double,	Float,		Double	>,
		//&DotFuncTmpl<Complex,	Float,		Complex	>,
	}, {
		nullptr,
		&DotFuncTmpl<Double,	Double,		Int8	>,
		&DotFuncTmpl<Double,	Double,		UInt8	>,
		&DotFuncTmpl<Double,	Double,		Int16	>,
		&DotFuncTmpl<Double,	Double,		UInt16	>,
		&DotFuncTmpl<Double,	Double,		Int32	>,
		&DotFuncTmpl<Double,	Double,		UInt32	>,
		&DotFuncTmpl<Double,	Double,		Int64	>,
		&DotFuncTmpl<Double,	Double,		UInt64	>,
		&DotFuncTmpl<Double,	Double,		Float	>,
		&DotFuncTmpl<Double,	Double,		Double	>,
		//&DotFuncTmpl<Complex,	Double,		Complex	>,
	}, {
		nullptr,
		//&DotFuncTmpl<Complex,	Complex,	Int8	>,
		//&DotFuncTmpl<Complex,	Complex,	UInt8	>,
		//&DotFuncTmpl<Complex,	Complex,	Int16	>,
		//&DotFuncTmpl<Complex,	Complex,	UInt16	>,
		//&DotFuncTmpl<Complex,	Complex,	Int32	>,
		//&DotFuncTmpl<Complex,	Complex,	UInt32	>,
		//&DotFuncTmpl<Complex,	Complex,	Int64	>,
		//&DotFuncTmpl<Complex,	Complex,	UInt64	>,
		//&DotFuncTmpl<Complex,	Complex,	Float	>,
		//&DotFuncTmpl<Complex,	Complex,	Double	>,
		//&DotFuncTmpl<Complex,	Complex,	Complex	>,
	},
};

Array::UnaryFunc Array::invertFuncs[ETYPE_Max] = {
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	nullptr,
	&InvertFuncTmpl<Float>,
	&InvertFuncTmpl<Double>,
	nullptr,
};

}
