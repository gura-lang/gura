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
// Calculations
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_Elem>
inline void _Pos(T_ElemResult &elemResult, T_Elem elem) {
	elemResult = static_cast<T_ElemResult>(+elem);
}

template<typename T_ElemResult, typename T_Elem>
inline void _Neg(T_ElemResult &elemResult, T_Elem elem) {
	elemResult = static_cast<T_ElemResult>(-elem);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Add(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) + static_cast<T_ElemResult>(elemR);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Sub(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) - static_cast<T_ElemResult>(elemR);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Mul(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) * static_cast<T_ElemResult>(elemR);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Div(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) / static_cast<T_ElemResult>(elemR);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Mod(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) % static_cast<T_ElemResult>(elemR);
}

#define ImplementMod_Float(T_Other) \
template<> \
inline void _Mod<Float, T_Other, Float>(Float &elemResult, T_Other elemL, Float elemR) { \
	elemResult = ::fmodf(static_cast<Float>(elemL), elemR);				\
} \
template<> \
inline void _Mod<Float, Float, T_Other>(Float &elemResult, Float elemL, T_Other elemR) { \
	elemResult = ::fmodf(elemL, static_cast<Float>(elemR));				\
}

#define ImplementMod_Double(T_Other) \
template<> \
inline void _Mod<Double, T_Other, Double>(Double &elemResult, T_Other elemL, Double elemR) { \
	elemResult = ::fmod(static_cast<Double>(elemL), elemR);				\
} \
template<> \
inline void _Mod<Double, Double, T_Other>(Double &elemResult, Double elemL, T_Other elemR) { \
	elemResult = ::fmod(elemL, static_cast<Double>(elemR));				\
}

ImplementMod_Float(Int8)
ImplementMod_Float(UInt8)
ImplementMod_Float(Int16)
ImplementMod_Float(UInt16)
ImplementMod_Float(Int32)
ImplementMod_Float(UInt32)
ImplementMod_Float(Int64)
ImplementMod_Float(UInt64)
ImplementMod_Float(Double)

template<>
inline void _Mod<Float, Float, Float>(Float &elemResult, Float elemL, Float elemR) {
	elemResult = ::fmodf(elemL, elemR);
}

ImplementMod_Double(Int8)
ImplementMod_Double(UInt8)
ImplementMod_Double(Int16)
ImplementMod_Double(UInt16)
ImplementMod_Double(Int32)
ImplementMod_Double(UInt32)
ImplementMod_Double(Int64)
ImplementMod_Double(UInt64)
ImplementMod_Double(Float)

template<>
inline void _Mod<Double, Double, Double>(Double &elemResult, Double elemL, Double elemR) {
	elemResult = ::fmod(elemL, elemR);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Pow(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(
		std::pow(static_cast<double>(elemL), static_cast<double>(elemR)));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _And(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) & static_cast<T_ElemResult>(elemR);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Or(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) | static_cast<T_ElemResult>(elemR);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Xor(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) ^ static_cast<T_ElemResult>(elemR);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Shl(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) << static_cast<T_ElemResult>(elemR);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Shr(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) >> static_cast<T_ElemResult>(elemR);
}

//------------------------------------------------------------------------------
// UnaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_Elem, void (*op)(T_ElemResult &, T_Elem)>
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

//------------------------------------------------------------------------------
// BinaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemResult &, T_ElemL, T_ElemR)>
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
		 void (*op)(T_ElemResult &, T_ElemL, T_ElemR)>
Array *BinaryFuncTmpl_Div_array_array(Signal &sig, const Array *pArrayL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_array<T_ElemResult, T_ElemL, T_ElemR, op>(sig, pArrayL, pArrayR);
}

template<typename T_ElemL, void (*op)(T_ElemL &, T_ElemL, Double)>
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

template<typename T_ElemL, void (*op)(T_ElemL &, T_ElemL, Double)>
Array *BinaryFuncTmpl_Div_array_number(Signal &sig, const Array *pArrayL, Double numberR)
{
	if (numberR == 0) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_number<T_ElemL, op>(sig, pArrayL, numberR);
}

template<typename T_ElemR, void (*op)(T_ElemR &, Double, T_ElemR)>
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

template<typename T_ElemR, void (*op)(T_ElemR &, Double, T_ElemR)>
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
template<typename T_Elem>
bool InvertFuncTmpl_Sub(T_Elem *pElem, size_t nSize, T_Elem &det)
{
	static const T_Elem Epsilon = static_cast<T_Elem>(1.0e-6);
	size_t nSize2 = nSize * 2;
	std::unique_ptr<T_Elem *[]> rows(new T_Elem *[nSize]);
	size_t offset = 0;
	det = 1;
	for (size_t iRow = 0; iRow < nSize; iRow++, offset += nSize2) {
		rows[iRow] = pElem + offset;
	}
	for (size_t iPivot = 0; iPivot < nSize; iPivot++) {
		size_t iRowMax = iPivot;
		T_Elem nMax = std::abs(*(rows[iRowMax] + iPivot));
		for (size_t iRow = iRowMax + 1; iRow < nSize; iRow++) {
			T_Elem n = std::abs(*(rows[iRow] + iPivot));
			if (nMax < n) {
				iRowMax = iRow;
				nMax = n;
			}
		}
		if (nMax < Epsilon) return false;
		if (iPivot != iRowMax) {
			T_Elem *p1 = rows[iPivot];
			T_Elem *p2 = rows[iRowMax];
			for (size_t cnt = nSize2; cnt > 0; cnt--, p1++, p2++) {
				std::swap(*p1, *p2);
			}
			det = -det;
		}
		T_Elem *p_i = rows[iPivot];
		T_Elem n = *(p_i + iPivot);
		det *= n;
		for (size_t cnt = nSize2; cnt > 0; cnt--, p_i++) {
			*p_i /= n;
		}
		for (size_t j = 0; j < nSize; j++) {
			if (iPivot == j) continue;
			T_Elem *p_i = rows[iPivot];
			T_Elem *p_j = rows[j];
			T_Elem factor = *(p_j + iPivot);
			for (size_t cnt = nSize2; cnt > 0; cnt--, p_i++, p_j++) {
				*p_j -= *p_i * factor;
			}
		}
	}
	return true;
}

template<typename T_Elem>
Array *InvertFuncTmpl(Signal &sig, const Array *pArray)
{
	const Array::Dimensions &dims = pArray->GetDimensions();
	size_t nRows = (dims.rbegin() + 1)->GetSize();
	size_t nCols = dims.rbegin()->GetSize();
	if (nRows != nCols) {
		sig.SetError(ERR_ValueError, "inversion can only be applied to square matrix");
		return nullptr;
	}
	size_t nCols2 = nCols * 2;
	AutoPtr<ArrayT<T_Elem> > pArrayWork(new ArrayT<T_Elem>(nRows, nCols2));
	pArrayWork->FillZero();
	const T_Elem *pSrc = dynamic_cast<const ArrayT<T_Elem> *>(pArray)->GetPointer();
	T_Elem *pDst = pArrayWork->GetPointer();
	size_t bytesPerRow = nCols * sizeof(T_Elem);
	for (size_t iRow = 0; iRow < nRows; iRow++, pDst += nCols2, pSrc += nCols) {
		::memcpy(pDst, pSrc, bytesPerRow);
		*(pDst + nCols + iRow) = 1;
	}
	T_Elem det = 0;
	if (!InvertFuncTmpl_Sub(pArrayWork->GetPointer(), nRows, det)) {
		sig.SetError(ERR_ValueError, "failed to calculate inverted matrix");
		return nullptr;
	}

	AutoPtr<ArrayT<T_Elem> > pArrayResult(new ArrayT<T_Elem>(nRows, nCols));
	pSrc = pArrayWork->GetPointer() + nCols;
	pDst = pArrayResult->GetPointer();
	for (size_t iRow = 0; iRow < nRows; iRow++, pDst += nCols, pSrc += nCols2) {
		::memcpy(pDst, pSrc, bytesPerRow);
	}
	return pArrayResult.release();
}

//------------------------------------------------------------------------------
// Function tables
//------------------------------------------------------------------------------
Array::UnaryFuncPack Array::unaryFuncPack_Pos = {
	"pos",
	{
		nullptr,
		&UnaryFuncTmpl<Int8,	Int8,	_Pos>,
		&UnaryFuncTmpl<UInt8,	UInt8,	_Pos>,
		&UnaryFuncTmpl<Int16,	Int16,	_Pos>,
		&UnaryFuncTmpl<UInt16,	UInt16,	_Pos>,
		&UnaryFuncTmpl<Int32,	Int32,	_Pos>,
		&UnaryFuncTmpl<UInt32,	UInt32,	_Pos>,
		&UnaryFuncTmpl<Int64,	Int64,	_Pos>,
		&UnaryFuncTmpl<UInt64,	UInt64,	_Pos>,
		&UnaryFuncTmpl<Float,	Float,	_Pos>,
		&UnaryFuncTmpl<Double,	Double,	_Pos>,
		nullptr,
	},
};

Array::UnaryFuncPack Array::unaryFuncPack_Neg = {
	"neg",
	{
		nullptr,
		&UnaryFuncTmpl<Int8,	Int8,	_Neg>,
		&UnaryFuncTmpl<UInt8,	UInt8,	_Neg>,
		&UnaryFuncTmpl<Int16,	Int16,	_Neg>,
		&UnaryFuncTmpl<UInt16,	UInt16,	_Neg>,
		&UnaryFuncTmpl<Int32,	Int32,	_Neg>,
		&UnaryFuncTmpl<UInt32,	UInt32,	_Neg>,
		&UnaryFuncTmpl<Int64,	Int64,	_Neg>,
		&UnaryFuncTmpl<UInt64,	UInt64,	_Neg>,
		&UnaryFuncTmpl<Float,	Float,	_Neg>,
		&UnaryFuncTmpl<Double,	Double,	_Neg>,
		nullptr,
	},
};

#define ImplementBinaryFuncPack(funcPrefix, op, name) \
Array::BinaryFuncPack Array::binaryFuncPack_##op = { \
	name, \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int8,		Int8,		Int8,		_##op>, \
			&funcPrefix##_array_array<UInt8,	Int8,		UInt8,		_##op>, \
			&funcPrefix##_array_array<Int16,	Int8,		Int16,		_##op>, \
			&funcPrefix##_array_array<UInt16,	Int8,		UInt16,		_##op>, \
			&funcPrefix##_array_array<Int32,	Int8,		Int32,		_##op>, \
			&funcPrefix##_array_array<UInt32,	Int8,		UInt32,		_##op>, \
			&funcPrefix##_array_array<Int64,	Int8,		Int64,		_##op>, \
			&funcPrefix##_array_array<UInt64,	Int8,		UInt64,		_##op>, \
			&funcPrefix##_array_array<Float,	Int8,		Float,		_##op>, \
			&funcPrefix##_array_array<Double,	Int8,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt8,	UInt8,		Int8,		_##op>, \
			&funcPrefix##_array_array<UInt8,	UInt8,		UInt8,		_##op>, \
			&funcPrefix##_array_array<Int16,	UInt8,		Int16,		_##op>, \
			&funcPrefix##_array_array<UInt16,	UInt8,		UInt16,		_##op>, \
			&funcPrefix##_array_array<Int32,	UInt8,		Int32,		_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt8,		UInt32,		_##op>, \
			&funcPrefix##_array_array<Int64,	UInt8,		Int64,		_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt8,		UInt64,		_##op>, \
			&funcPrefix##_array_array<Float,	UInt8,		Float,		_##op>, \
			&funcPrefix##_array_array<Double,	UInt8,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int16,	Int16,		Int8,		_##op>, \
			&funcPrefix##_array_array<Int16,	Int16,		UInt8,		_##op>, \
			&funcPrefix##_array_array<Int16,	Int16,		Int16,		_##op>, \
			&funcPrefix##_array_array<UInt16,	Int16,		UInt16,		_##op>, \
			&funcPrefix##_array_array<Int32,	Int16,		Int32,		_##op>, \
			&funcPrefix##_array_array<UInt32,	Int16,		UInt32,		_##op>, \
			&funcPrefix##_array_array<Int64,	Int16,		Int64,		_##op>, \
			&funcPrefix##_array_array<UInt64,	Int16,		UInt64,		_##op>, \
			&funcPrefix##_array_array<Float,	Int16,		Float,		_##op>, \
			&funcPrefix##_array_array<Double,	Int16,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int8,		_##op>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt8,		_##op>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int16,		_##op>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt16,		_##op>, \
			&funcPrefix##_array_array<Int32,	UInt16,		Int32,		_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt16,		UInt32,		_##op>, \
			&funcPrefix##_array_array<Int64,	UInt16,		Int64,		_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt16,		UInt64,		_##op>, \
			&funcPrefix##_array_array<Float,	UInt16,		Float,		_##op>, \
			&funcPrefix##_array_array<Double,	UInt16,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int32,	Int32,		Int8,		_##op>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt8,		_##op>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int16,		_##op>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt16,		_##op>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int32,		_##op>, \
			&funcPrefix##_array_array<UInt32,	Int32,		UInt32,		_##op>, \
			&funcPrefix##_array_array<Int64,	Int32,		Int64,		_##op>, \
			&funcPrefix##_array_array<UInt64,	Int32,		UInt64,		_##op>, \
			&funcPrefix##_array_array<Float,	Int32,		Float,		_##op>, \
			&funcPrefix##_array_array<Double,	Int32,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int8,		_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt8,		_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int16,		_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt16,		_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int32,		_##op>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt32,		_##op>, \
			&funcPrefix##_array_array<Int64,	UInt32,		Int64,		_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt32,		UInt64,		_##op>, \
			&funcPrefix##_array_array<Float,	UInt32,		Float,		_##op>, \
			&funcPrefix##_array_array<Double,	UInt32,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int64,	Int64,		Int8,		_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt8,		_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int16,		_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt16,		_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int32,		_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt32,		_##op>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int64,		_##op>, \
			&funcPrefix##_array_array<UInt64,	Int64,		UInt64,		_##op>, \
			&funcPrefix##_array_array<Float,	Int64,		Float,		_##op>, \
			&funcPrefix##_array_array<Double,	Int64,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int8,		_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt8,		_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int16,		_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt16,		_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int32,		_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt32,		_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int64,		_##op>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt64,		_##op>, \
			&funcPrefix##_array_array<Float,	UInt64,		Float,		_##op>, \
			&funcPrefix##_array_array<Double,	UInt64,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Float,	Float,		Int8,		_##op>, \
			&funcPrefix##_array_array<Float,	Float,		UInt8,		_##op>, \
			&funcPrefix##_array_array<Float,	Float,		Int16,		_##op>, \
			&funcPrefix##_array_array<Float,	Float,		UInt16,		_##op>, \
			&funcPrefix##_array_array<Float,	Float,		Int32,		_##op>, \
			&funcPrefix##_array_array<Float,	Float,		UInt32,		_##op>, \
			&funcPrefix##_array_array<Float,	Float,		Int64,		_##op>, \
			&funcPrefix##_array_array<Float,	Float,		UInt64,		_##op>, \
			&funcPrefix##_array_array<Float,	Float,		Float,		_##op>, \
			&funcPrefix##_array_array<Double,	Float,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Double,	Double,		Int8,		_##op>, \
			&funcPrefix##_array_array<Double,	Double,		UInt8,		_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Int16,		_##op>, \
			&funcPrefix##_array_array<Double,	Double,		UInt16,		_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Int32,		_##op>, \
			&funcPrefix##_array_array<Double,	Double,		UInt32,		_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Int64,		_##op>, \
			&funcPrefix##_array_array<Double,	Double,		UInt64,		_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Float,		_##op>, \
			&funcPrefix##_array_array<Double,	Double,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, \
	}, { \
		nullptr, \
		&funcPrefix##_array_number<Int8,	_##op>, \
		&funcPrefix##_array_number<UInt8,	_##op>, \
		&funcPrefix##_array_number<Int16,	_##op>, \
		&funcPrefix##_array_number<UInt16,	_##op>, \
		&funcPrefix##_array_number<Int32,	_##op>, \
		&funcPrefix##_array_number<UInt32,	_##op>, \
		&funcPrefix##_array_number<Int64,	_##op>, \
		&funcPrefix##_array_number<UInt64,	_##op>, \
		&funcPrefix##_array_number<Float,	_##op>, \
		&funcPrefix##_array_number<Double,	_##op>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_number_array<Int8,	_##op>, \
		&funcPrefix##_number_array<UInt8,	_##op>, \
		&funcPrefix##_number_array<Int16,	_##op>, \
		&funcPrefix##_number_array<UInt16,	_##op>, \
		&funcPrefix##_number_array<Int32,	_##op>, \
		&funcPrefix##_number_array<UInt32,	_##op>, \
		&funcPrefix##_number_array<Int64,	_##op>, \
		&funcPrefix##_number_array<UInt64,	_##op>, \
		&funcPrefix##_number_array<Float,	_##op>, \
		&funcPrefix##_number_array<Double,	_##op>, \
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
			&BinaryFuncTmpl_array_array<Int8,		Int8,		Int8,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt8,		Int8,		UInt8,		_##op>, \
			&BinaryFuncTmpl_array_array<Int16,		Int8,		Int16,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt16,		Int8,		UInt16,		_##op>, \
			&BinaryFuncTmpl_array_array<Int32,		Int8,		Int32,		_##op>, \
			&BinaryFuncTmpl_array_array<Int32,		Int8,		UInt32,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		Int8,		Int64,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		Int8,		UInt64,		_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		Int8,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		UInt8,		_##op>, \
			&BinaryFuncTmpl_array_array<Int16,		UInt8,		Int16,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt8,		UInt16,		_##op>, \
			&BinaryFuncTmpl_array_array<Int32,		UInt8,		Int32,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt8,		UInt32,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt8,		Int64,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt8,		UInt64,		_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Int8,		_##op>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		UInt8,		_##op>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Int16,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt16,		Int16,		UInt16,		_##op>, \
			&BinaryFuncTmpl_array_array<Int32,		Int16,		Int32,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt32,		Int16,		UInt32,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		Int16,		Int64,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int16,		UInt64,		_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int8,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt8,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int16,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt16,		_##op>, \
			&BinaryFuncTmpl_array_array<Int32,		UInt16,		Int32,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt16,		UInt32,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt16,		Int64,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt16,		UInt64,		_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int8,		_##op>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		UInt8,		_##op>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int16,		_##op>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		UInt16,		_##op>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int32,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt32,		Int32,		UInt32,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		Int32,		Int64,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int32,		UInt64,		_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int8,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt8,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int16,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt16,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int32,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt32,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt32,		Int64,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt32,		UInt64,		_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int8,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt8,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int16,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt16,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int32,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt32,		_##op>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int64,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int64,		UInt64,		_##op>, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int8,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt8,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int16,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt16,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int32,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt32,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int64,		_##op>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt64,		_##op>, \
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
		&BinaryFuncTmpl_array_number<Int8,		_##op>, \
		&BinaryFuncTmpl_array_number<UInt8,		_##op>, \
		&BinaryFuncTmpl_array_number<Int16,		_##op>, \
		&BinaryFuncTmpl_array_number<UInt16,	_##op>, \
		&BinaryFuncTmpl_array_number<Int32,		_##op>, \
		&BinaryFuncTmpl_array_number<UInt32,	_##op>, \
		&BinaryFuncTmpl_array_number<Int64,		_##op>, \
		&BinaryFuncTmpl_array_number<UInt64,	_##op>, \
		nullptr, \
		nullptr, \
		nullptr, \
	}, { \
		nullptr, \
		&BinaryFuncTmpl_number_array<Int8,		_##op>, \
		&BinaryFuncTmpl_number_array<UInt8,		_##op>, \
		&BinaryFuncTmpl_number_array<Int16,		_##op>, \
		&BinaryFuncTmpl_number_array<UInt16,	_##op>, \
		&BinaryFuncTmpl_number_array<Int32,		_##op>, \
		&BinaryFuncTmpl_number_array<UInt32,	_##op>, \
		&BinaryFuncTmpl_number_array<Int64,		_##op>, \
		&BinaryFuncTmpl_number_array<UInt64,	_##op>, \
		nullptr, \
		nullptr, \
		nullptr, \
	} \
}

ImplementBinaryFuncPack(BinaryFuncTmpl,		Add, "add");
ImplementBinaryFuncPack(BinaryFuncTmpl,		Sub, "sub");
ImplementBinaryFuncPack(BinaryFuncTmpl,		Mul, "mul");
ImplementBinaryFuncPack(BinaryFuncTmpl_Div,	Div, "div");
ImplementBinaryFuncPack(BinaryFuncTmpl_Div, Mod, "mod");
ImplementBinaryFuncPack(BinaryFuncTmpl,		Pow, "pow");

ImplementBinaryFuncPack_BitOp(And,	"and");
ImplementBinaryFuncPack_BitOp(Or,	"or");
ImplementBinaryFuncPack_BitOp(Xor,	"xor");
ImplementBinaryFuncPack_BitOp(Shl,	"shl");
ImplementBinaryFuncPack_BitOp(Shr,	"Shr");

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
