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

String Array::ToString() const
{
	return "";
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

bool Array::CheckShape(Signal &sig, const Array &arrayA, const Array &arrayB)
{
	if (Dimensions::IsSameShape(arrayA.GetDimensions(), arrayB.GetDimensions())) {
		return true;
	}
	sig.SetError(ERR_ValueError, "different dimension of arrays");
	return false;
}

bool Array::CheckElemwiseCalculatable(Signal &sig, const Array &arrayA, const Array &arrayB)
{
	if (Dimensions::IsElemwiseCalculatable(
			arrayA.GetDimensions(), arrayB.GetDimensions())) {
		return true;
	}
	sig.SetError(ERR_ValueError, "dimensions mismatch for the operation");
	return false;
}

bool Array::CheckDotProductCalculatable(Signal &sig, const Array &arrayA, const Array &arrayB)
{
	if (Dimensions::IsDotProductCalculatable(
			arrayA.GetDimensions(), arrayB.GetDimensions())) {
		return true;
	}
	sig.SetError(ERR_ValueError, "dimensions mismatch for the dot product");
	return false;
}

Array *Array::ApplyUnaryFunc(Signal &sig, const UnaryFuncPack &pack, const Array *pArray)
{
	UnaryFunc unaryFunc = pack.unaryFuncs[pArray->GetElemType()];
	if (unaryFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*unaryFunc)(sig, *pArray);
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
	BinaryFunc_array_array binaryFunc_array_array =
		pack.binaryFuncs_array_array[pArrayL->GetElemType()][pArrayR->GetElemType()];
	if (binaryFunc_array_array == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_array_array)(sig, *pArrayL, *pArrayR);
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
	return (*binaryFunc_array_number)(sig, *pArrayL, numberR);
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
	return (*binaryFunc_number_array)(sig, numberL, *pArrayR);
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

bool Array::Dimensions::IsDotProductCalculatable(const Dimensions &dimsA, const Dimensions &dimsB)
{
	if (dimsA.size() < 2 || dimsB.size() < 2) return false;
	Dimensions::const_reverse_iterator pA = dimsA.rbegin();
	Dimensions::const_reverse_iterator pB = dimsB.rbegin();
	if (pA->GetSize() != (pB + 1)->GetSize()) return false;
	pA += 2, pB += 2;
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

template<>
inline void _Mod<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = ::fmodf(elemL, elemR);
}

template<>
inline void _Mod<double, double, double>(double &elemResult, double elemL, double elemR) {
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

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemResult &, T_ElemL, T_ElemR)>
Array *BinaryFuncTmpl_array_array(Signal &sig, const Array &arrayL, const Array &arrayR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(&arrayL)->GetPointer();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(&arrayR)->GetPointer();
	size_t nElemsL = arrayL.GetElemNum();
	size_t nElemsR = arrayR.GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult;
	if (nElemsL == nElemsR) {
		pArrayResult.reset(ArrayT<T_ElemResult>::CreateLike(arrayL.GetDimensions()));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		for (size_t i = 0; i < nElemsL; i++, pElemResult++, pElemL++, pElemR++) {
			op(*pElemResult, *pElemL, *pElemR);
		}
	} else if (nElemsL < nElemsR) {
		pArrayResult.reset(ArrayT<T_ElemResult>::CreateLike(arrayR.GetDimensions()));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		size_t j = 0;
		const T_ElemL *pElemLOrg = pElemL;
		for (size_t i = 0; i < nElemsR; i++, pElemResult++, pElemL++, pElemR++) {
			op(*pElemResult, *pElemL, *pElemR);
			if (++j >= nElemsL) {
				pElemL = pElemLOrg;
				j = 0;
			}
		}
	} else { // nElemsL > nElemsR
		pArrayResult.reset(ArrayT<T_ElemResult>::CreateLike(arrayL.GetDimensions()));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		size_t j = 0;
		const T_ElemR *pElemROrg = pElemR;
		for (size_t i = 0; i < nElemsL; i++, pElemResult++, pElemL++, pElemR++) {
			op(*pElemResult, *pElemL, *pElemR);
			if (++j >= nElemsR) {
				pElemR = pElemROrg;
				j = 0;
			}
		}
	}
	return pArrayResult.release();
}

template<typename T_ElemL, void (*op)(T_ElemL &, T_ElemL, Double)>
Array *BinaryFuncTmpl_array_number(Signal &sig, const Array &arrayL, Double numberR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(&arrayL)->GetPointer();
	size_t nElemsL = arrayL.GetElemNum();
	AutoPtr<ArrayT<T_ElemL> > pArrayResult(ArrayT<T_ElemL>::CreateLike(arrayL.GetDimensions()));
	T_ElemL *pElemResult = pArrayResult->GetPointer();
	for (size_t i = 0; i < nElemsL; i++, pElemResult++, pElemL++) {
		op(*pElemResult, *pElemL, numberR);
	}
	return pArrayResult.release();
}

template<typename T_ElemR, void (*op)(T_ElemR &, Double, T_ElemR)>
Array *BinaryFuncTmpl_number_array(Signal &sig, Double numberL, const Array &arrayR)
{
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(&arrayR)->GetPointer();
	size_t nElemsR = arrayR.GetElemNum();
	AutoPtr<ArrayT<T_ElemR> > pArrayResult(ArrayT<T_ElemR>::CreateLike(arrayR.GetDimensions()));
	T_ElemR *pElemResult = pArrayResult->GetPointer();
	for (size_t i = 0; i < nElemsR; i++, pElemResult++, pElemR++) {
		op(*pElemResult, numberL, *pElemR);
	}
	return pArrayResult.release();
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void BinaryFuncTmpl_Dot(T_ElemResult *pElemResult, const T_ElemL *pElemL, const T_ElemR *pElemR,
						size_t rowL, size_t colL_rowR, size_t colR)
{
	const T_ElemL *pElemBaseL = pElemL;
	for (size_t iRow = 0; iRow < rowL; iRow++, pElemBaseL += colL_rowR) {
		const T_ElemR *pElemBaseR = pElemR;
		for (size_t iCol = 0; iCol < colR; iCol++, pElemBaseR++) {
			const T_ElemL *pElemWorkL = pElemBaseL;
			const T_ElemR *pElemWorkR = pElemBaseR;
			T_ElemResult elemResult = 0;
			for (size_t i = 0; i < colL_rowR; i++, pElemWorkL++, pElemWorkR += colR) {
				elemResult += static_cast<T_ElemResult>(*pElemWorkL) * *pElemWorkR;
			}
			*pElemResult++ = elemResult;
		}
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Array *BinaryFunc_Dot(Signal &sig, const Array &arrayL, const Array &arrayR)
{
	const Array::Dimensions &dimsL = arrayL.GetDimensions();
	const Array::Dimensions &dimsR = arrayR.GetDimensions();
	size_t rowL = dimsL[0].GetSize();
	size_t colL_rowR = dimsL[1].GetSize();
	size_t colR = dimsR[1].GetSize();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(new ArrayT<T_ElemResult>(rowL, colR));
	size_t elemNumResult = pArrayResult->GetElemNum();
	size_t elemNumL = arrayL.GetElemNum();
	size_t elemNumR = arrayR.GetElemNum();
	T_ElemResult *pElemResult = pArrayResult->GetPointer();
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(&arrayL)->GetPointer();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(&arrayR)->GetPointer();
	if (dimsL.size() == dimsR.size()) {
		BinaryFuncTmpl_Dot(pElemResult, pElemL, pElemR, rowL, colL_rowR, colR);
	} else if (dimsL.size() < dimsR.size()) {
		size_t elemNumMatR = colL_rowR * colR;
		for (size_t cnt = elemNumR / elemNumMatR; cnt > 0; cnt--) {
			BinaryFuncTmpl_Dot(pElemResult, pElemL, pElemR, rowL, colL_rowR, colR);
			pElemResult += elemNumResult;
			pElemR += elemNumR;
		}
	} else { // dimsL.size() > dimsR.size()
		size_t elemNumMatL = rowL * colL_rowR;
		for (size_t cnt = elemNumL / elemNumMatL; cnt > 0; cnt--) {
			BinaryFuncTmpl_Dot(pElemResult, pElemL, pElemR, rowL, colL_rowR, colR);
			pElemResult += elemNumResult;
			pElemL += elemNumL;
		}
	}
	return pArrayResult.release();
}

Array::UnaryFuncPack Array::unaryFuncPack_Pos = {
	"",
	{},
};

Array::UnaryFuncPack Array::unaryFuncPack_Neg = {
	"",
	{},
};

#define ImplementBinaryFuncPack(op, name) \
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
			&BinaryFuncTmpl_array_array<Float,		Int8,		Float,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Int8,		Double,		_##op>, \
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
			&BinaryFuncTmpl_array_array<Float,		UInt8,		Float,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		UInt8,		Double,		_##op>, \
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
			&BinaryFuncTmpl_array_array<Float,		Int16,		Float,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Int16,		Double,		_##op>, \
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
			&BinaryFuncTmpl_array_array<Float,		UInt16,		Float,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		UInt16,		Double,		_##op>, \
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
			&BinaryFuncTmpl_array_array<Float,		Int32,		Float,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Int32,		Double,		_##op>, \
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
			&BinaryFuncTmpl_array_array<Float,		UInt32,		Float,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		UInt32,		Double,		_##op>, \
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
			&BinaryFuncTmpl_array_array<Float,		Int64,		Float,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Int64,		Double,		_##op>, \
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
			&BinaryFuncTmpl_array_array<Float,		UInt64,		Float,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		UInt64,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Float,		Float,		Int8,		_##op>, \
			&BinaryFuncTmpl_array_array<Float,		Float,		UInt8,		_##op>, \
			&BinaryFuncTmpl_array_array<Float,		Float,		Int16,		_##op>, \
			&BinaryFuncTmpl_array_array<Float,		Float,		UInt16,		_##op>, \
			&BinaryFuncTmpl_array_array<Float,		Float,		Int32,		_##op>, \
			&BinaryFuncTmpl_array_array<Float,		Float,		UInt32,		_##op>, \
			&BinaryFuncTmpl_array_array<Float,		Float,		Int64,		_##op>, \
			&BinaryFuncTmpl_array_array<Float,		Float,		UInt64,		_##op>, \
			&BinaryFuncTmpl_array_array<Float,		Float,		Float,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Float,		Double,		_##op>, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Double,		Double,		Int8,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Double,		UInt8,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Double,		Int16,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Double,		UInt16,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Double,		Int32,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Double,		UInt32,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Double,		Int64,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Double,		UInt64,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Double,		Float,		_##op>, \
			&BinaryFuncTmpl_array_array<Double,		Double,		Double,		_##op>, \
			nullptr, \
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
		&BinaryFuncTmpl_array_number<Float,		_##op>, \
		&BinaryFuncTmpl_array_number<Double,	_##op>, \
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
		&BinaryFuncTmpl_number_array<Float,		_##op>, \
		&BinaryFuncTmpl_number_array<Double,	_##op>, \
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

ImplementBinaryFuncPack(Add, "add");
ImplementBinaryFuncPack(Sub, "sub");
ImplementBinaryFuncPack(Mul, "mul");
ImplementBinaryFuncPack(Div, "div");
//ImplementBinaryFuncPack(Mod, "mod");
ImplementBinaryFuncPack(Pow, "pow");
ImplementBinaryFuncPack_BitOp(And, "and");
ImplementBinaryFuncPack_BitOp(Or, "or");
ImplementBinaryFuncPack_BitOp(Xor, "xor");
ImplementBinaryFuncPack_BitOp(Shl, "shl");
ImplementBinaryFuncPack_BitOp(Shr, "Shr");

Array::BinaryFuncPack Array::binaryFuncPack_Mod = {
};

Array::BinaryFuncPack Array::binaryFuncPack_Dot = {
	"",
	{
		{
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, {
			nullptr,
			&BinaryFunc_Dot<Int8,		Int8,		Int8	>,
			&BinaryFunc_Dot<UInt8,		Int8,		UInt8	>,
			&BinaryFunc_Dot<Int16,		Int8,		Int16	>,
			&BinaryFunc_Dot<UInt16,		Int8,		UInt16	>,
			&BinaryFunc_Dot<Int32,		Int8,		Int32	>,
			&BinaryFunc_Dot<UInt32,		Int8,		UInt32	>,
			&BinaryFunc_Dot<Int64,		Int8,		Int64	>,
			&BinaryFunc_Dot<UInt64,		Int8,		UInt64	>,
			&BinaryFunc_Dot<Float,		Int8,		Float	>,
			&BinaryFunc_Dot<Double,		Int8,		Double	>,
			//&BinaryFunc_Dot<Complex,	UInt8,		Complex	>,
		}, {
			nullptr,
			&BinaryFunc_Dot<UInt8,		UInt8,		Int8	>,
			&BinaryFunc_Dot<UInt8,		UInt8,		UInt8	>,
			&BinaryFunc_Dot<Int16,		UInt8,		Int16	>,
			&BinaryFunc_Dot<UInt16,		UInt8,		UInt16	>,
			&BinaryFunc_Dot<Int32,		UInt8,		Int32	>,
			&BinaryFunc_Dot<UInt32,		UInt8,		UInt32	>,
			&BinaryFunc_Dot<Int64,		UInt8,		Int64	>,
			&BinaryFunc_Dot<UInt64,		UInt8,		UInt64	>,
			&BinaryFunc_Dot<Float,		UInt8,		Float	>,
			&BinaryFunc_Dot<Double,		UInt8,		Double	>,
			//&BinaryFunc_Dot<Complex,	UInt8,		Complex	>,
		}, {
			nullptr,
			&BinaryFunc_Dot<Int16,		Int16,		Int8	>,
			&BinaryFunc_Dot<Int16,		Int16,		UInt8	>,
			&BinaryFunc_Dot<Int16,		Int16,		Int16	>,
			&BinaryFunc_Dot<UInt16,		Int16,		UInt16	>,
			&BinaryFunc_Dot<Int32,		Int16,		Int32	>,
			&BinaryFunc_Dot<UInt32,		Int16,		UInt32	>,
			&BinaryFunc_Dot<Int64,		Int16,		Int64	>,
			&BinaryFunc_Dot<UInt64,		Int16,		UInt64	>,
			&BinaryFunc_Dot<Float,		Int16,		Float	>,
			&BinaryFunc_Dot<Double,		Int16,		Double	>,
			//&BinaryFunc_Dot<Complex,	Int16,		Complex	>,
		}, {
			nullptr,
			&BinaryFunc_Dot<UInt16,		UInt16,		Int8	>,
			&BinaryFunc_Dot<UInt16,		UInt16,		UInt8	>,
			&BinaryFunc_Dot<UInt16,		UInt16,		Int16	>,
			&BinaryFunc_Dot<UInt16,		UInt16,		UInt16	>,
			&BinaryFunc_Dot<Int32,		UInt16,		Int32	>,
			&BinaryFunc_Dot<UInt32,		UInt16,		UInt32	>,
			&BinaryFunc_Dot<Int64,		UInt16,		Int64	>,
			&BinaryFunc_Dot<UInt64,		UInt16,		UInt64	>,
			&BinaryFunc_Dot<Float,		UInt16,		Float	>,
			&BinaryFunc_Dot<Double,		UInt16,		Double	>,
			//&BinaryFunc_Dot<Complex,	UInt16,		Complex	>,
		}, {
			nullptr,
			&BinaryFunc_Dot<Int32,		Int32,		Int8	>,
			&BinaryFunc_Dot<Int32,		Int32,		UInt8	>,
			&BinaryFunc_Dot<Int32,		Int32,		Int16	>,
			&BinaryFunc_Dot<Int32,		Int32,		UInt16	>,
			&BinaryFunc_Dot<Int32,		Int32,		Int32	>,
			&BinaryFunc_Dot<UInt32,		Int32,		UInt32	>,
			&BinaryFunc_Dot<Int64,		Int32,		Int64	>,
			&BinaryFunc_Dot<UInt64,		Int32,		UInt64	>,
			&BinaryFunc_Dot<Float,		Int32,		Float	>,
			&BinaryFunc_Dot<Double,		Int32,		Double	>,
			//&BinaryFunc_Dot<Complex,	Int32,		Complex	>,
		}, {
			nullptr,
			&BinaryFunc_Dot<UInt32,		UInt32,		Int8	>,
			&BinaryFunc_Dot<UInt32,		UInt32,		UInt8	>,
			&BinaryFunc_Dot<UInt32,		UInt32,		Int16	>,
			&BinaryFunc_Dot<UInt32,		UInt32,		UInt16	>,
			&BinaryFunc_Dot<UInt32,		UInt32,		Int32	>,
			&BinaryFunc_Dot<UInt32,		UInt32,		UInt32	>,
			&BinaryFunc_Dot<Int64,		UInt32,		Int64	>,
			&BinaryFunc_Dot<UInt64,		UInt32,		UInt64	>,
			&BinaryFunc_Dot<Float,		UInt32,		Float	>,
			&BinaryFunc_Dot<Double,		UInt32,		Double	>,
			//&BinaryFunc_Dot<Complex,	UInt32,		Complex	>,
		}, {
			nullptr,
			&BinaryFunc_Dot<Int64,		Int64,		Int8	>,
			&BinaryFunc_Dot<Int64,		Int64,		UInt8	>,
			&BinaryFunc_Dot<Int64,		Int64,		Int16	>,
			&BinaryFunc_Dot<Int64,		Int64,		UInt16	>,
			&BinaryFunc_Dot<Int64,		Int64,		Int32	>,
			&BinaryFunc_Dot<Int64,		Int64,		UInt32	>,
			&BinaryFunc_Dot<Int64,		Int64,		Int64	>,
			&BinaryFunc_Dot<UInt64,		Int64,		UInt64	>,
			&BinaryFunc_Dot<Float,		Int64,		Float	>,
			&BinaryFunc_Dot<Double,		Int64,		Double	>,
			//&BinaryFunc_Dot<Complex,	Int64,		Complex	>,
		}, {
			nullptr,
			&BinaryFunc_Dot<UInt64,		UInt64,		Int8	>,
			&BinaryFunc_Dot<UInt64,		UInt64,		UInt8	>,
			&BinaryFunc_Dot<UInt64,		UInt64,		Int16	>,
			&BinaryFunc_Dot<UInt64,		UInt64,		UInt16	>,
			&BinaryFunc_Dot<UInt64,		UInt64,		Int32	>,
			&BinaryFunc_Dot<UInt64,		UInt64,		UInt32	>,
			&BinaryFunc_Dot<UInt64,		UInt64,		Int64	>,
			&BinaryFunc_Dot<UInt64,		UInt64,		UInt64	>,
			&BinaryFunc_Dot<Float,		UInt64,		Float	>,
			&BinaryFunc_Dot<Double,		UInt64,		Double	>,
			//&BinaryFunc_Dot<Complex,	UInt64,		Complex	>,
		}, {
			nullptr,
			&BinaryFunc_Dot<Float,		Float,		Int8	>,
			&BinaryFunc_Dot<Float,		Float,		UInt8	>,
			&BinaryFunc_Dot<Float,		Float,		Int16	>,
			&BinaryFunc_Dot<Float,		Float,		UInt16	>,
			&BinaryFunc_Dot<Float,		Float,		Int32	>,
			&BinaryFunc_Dot<Float,		Float,		UInt32	>,
			&BinaryFunc_Dot<Float,		Float,		Int64	>,
			&BinaryFunc_Dot<Float,		Float,		UInt64	>,
			&BinaryFunc_Dot<Float,		Float,		Float	>,
			&BinaryFunc_Dot<Double,		Float,		Double	>,
			//&BinaryFunc_Dot<Complex,	Float,		Complex	>,
		}, {
			nullptr,
			&BinaryFunc_Dot<Double,		Double,		Int8	>,
			&BinaryFunc_Dot<Double,		Double,		UInt8	>,
			&BinaryFunc_Dot<Double,		Double,		Int16	>,
			&BinaryFunc_Dot<Double,		Double,		UInt16	>,
			&BinaryFunc_Dot<Double,		Double,		Int32	>,
			&BinaryFunc_Dot<Double,		Double,		UInt32	>,
			&BinaryFunc_Dot<Double,		Double,		Int64	>,
			&BinaryFunc_Dot<Double,		Double,		UInt64	>,
			&BinaryFunc_Dot<Double,		Double,		Float	>,
			&BinaryFunc_Dot<Double,		Double,		Double	>,
			//&BinaryFunc_Dot<Complex,	Double,		Complex	>,
		}, {
			nullptr,
			//&BinaryFunc_Dot<Complex,	Complex,	Int8	>,
			//&BinaryFunc_Dot<Complex,	Complex,	UInt8	>,
			//&BinaryFunc_Dot<Complex,	Complex,	Int16	>,
			//&BinaryFunc_Dot<Complex,	Complex,	UInt16	>,
			//&BinaryFunc_Dot<Complex,	Complex,	Int32	>,
			//&BinaryFunc_Dot<Complex,	Complex,	UInt32	>,
			//&BinaryFunc_Dot<Complex,	Complex,	Int64	>,
			//&BinaryFunc_Dot<Complex,	Complex,	UInt64	>,
			//&BinaryFunc_Dot<Complex,	Complex,	Float	>,
			//&BinaryFunc_Dot<Complex,	Complex,	Double	>,
			//&BinaryFunc_Dot<Complex,	Complex,	Complex	>,
		},
	}, {
	}, {
	}
};

}
