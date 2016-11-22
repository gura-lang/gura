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

Array *Array::ApplyUnaryFunc(Signal &sig, const UnaryFunc unaryFuncTbl[],
							 const Array *pArray, const char *name)
{
	UnaryFunc unaryFunc = unaryFuncTbl[pArray->GetElemType()];
	if (unaryFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", name);
		return nullptr;
	}
	return (*unaryFunc)(sig, *pArray);
}

Array *Array::ApplyBinaryFunc(Signal &sig, const BinaryFunc binaryFuncTbl[][ETYPE_Max],
							  const Array *pArrayL, const Array *pArrayR, const char *name)
{
	BinaryFunc binaryFunc = binaryFuncTbl[pArrayL->GetElemType()][pArrayR->GetElemType()];
	if (binaryFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", name);
		return nullptr;
	}
	return (*binaryFunc)(sig, *pArrayL, *pArrayR);
}

Value Array::ApplyBinaryFunc(Environment &env, const BinaryFunc binaryFuncTbl[][ETYPE_Max],
							  const Value &valueL, const Value &valueR, const char *name)
{
	Array *pArray = ApplyBinaryFunc(env.GetSignal(), binaryFuncTbl,
									Object_array::GetObject(valueL)->GetArray(),
									Object_array::GetObject(valueR)->GetArray(), name);
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

template<>
inline void _And<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = static_cast<float>(static_cast<UInt32>(elemL) & static_cast<UInt32>(elemR));
}

template<>
inline void _And<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = static_cast<double>(static_cast<UInt32>(elemL) & static_cast<UInt32>(elemR));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Or(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) | static_cast<T_ElemResult>(elemR);
}

template<>
inline void _Or<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = static_cast<float>(static_cast<UInt32>(elemL) | static_cast<UInt32>(elemR));
}

template<>
inline void _Or<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = static_cast<double>(static_cast<UInt32>(elemL) | static_cast<UInt32>(elemR));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Xor(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) ^ static_cast<T_ElemResult>(elemR);
}

template<>
inline void _Xor<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = static_cast<float>(static_cast<UInt32>(elemL) ^ static_cast<UInt32>(elemR));
}

template<>
inline void _Xor<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = static_cast<double>(static_cast<UInt32>(elemL) ^ static_cast<UInt32>(elemR));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Shl(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) << static_cast<T_ElemResult>(elemR);
}

template<>
inline void _Shl<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = static_cast<float>(static_cast<UInt32>(elemL) << static_cast<Int32>(elemR));
}

template<>
inline void _Shl<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = static_cast<double>(static_cast<UInt32>(elemL) << static_cast<Int32>(elemR));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void _Shr(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) >> static_cast<T_ElemResult>(elemR);
}

template<>
inline void _Shr<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = static_cast<float>(static_cast<UInt32>(elemL) >> static_cast<Int32>(elemR));
}

template<>
inline void _Shr<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = static_cast<double>(static_cast<UInt32>(elemL) >> static_cast<Int32>(elemR));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemResult &, T_ElemL, T_ElemR)>
Array *BinaryFunc_ElemWise(Signal &sig, const Array &arrayL, const Array &arrayR)
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

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void CalcDotProduct(T_ElemResult *pElemResult, const T_ElemL *pElemL, const T_ElemR *pElemR,
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
		CalcDotProduct(pElemResult, pElemL, pElemR, rowL, colL_rowR, colR);
	} else if (dimsL.size() < dimsR.size()) {
		size_t elemNumMatR = colL_rowR * colR;
		for (size_t cnt = elemNumR / elemNumMatR; cnt > 0; cnt--) {
			CalcDotProduct(pElemResult, pElemL, pElemR, rowL, colL_rowR, colR);
			pElemResult += elemNumResult;
			pElemR += elemNumR;
		}
	} else { // dimsL.size() > dimsR.size()
		size_t elemNumMatL = rowL * colL_rowR;
		for (size_t cnt = elemNumL / elemNumMatL; cnt > 0; cnt--) {
			CalcDotProduct(pElemResult, pElemL, pElemR, rowL, colL_rowR, colR);
			pElemResult += elemNumResult;
			pElemL += elemNumL;
		}
	}
	return pArrayResult.release();
}

Array::BinaryFunc Array::_binaryFuncTbl_Add[ETYPE_Max][ETYPE_Max] = {
	{
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		Char,		Char,		_Add>,
		&BinaryFunc_ElemWise<UChar,		Char,		UChar,		_Add>,
		&BinaryFunc_ElemWise<Short,		Char,		Short,		_Add>,
		&BinaryFunc_ElemWise<UShort,	Char,		UShort,		_Add>,
		&BinaryFunc_ElemWise<Int32,		Char,		Int32,		_Add>,
		&BinaryFunc_ElemWise<Int32,		Char,		UInt32,		_Add>,
		&BinaryFunc_ElemWise<Int64,		Char,		Int64,		_Add>,
		&BinaryFunc_ElemWise<Int64,		Char,		UInt64,		_Add>,
		&BinaryFunc_ElemWise<Float,		Char,		Float,		_Add>,
		&BinaryFunc_ElemWise<Double,	Char,		Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Char,		Complex,	_Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<UChar,		UChar,		Char,		_Add>,
		&BinaryFunc_ElemWise<UChar,		UChar,		UChar,		_Add>,
		&BinaryFunc_ElemWise<Short,		UChar,		Short,		_Add>,
		&BinaryFunc_ElemWise<UShort,	UChar,		UShort,		_Add>,
		&BinaryFunc_ElemWise<Int32,		UChar,		Int32,		_Add>,
		&BinaryFunc_ElemWise<UInt32,	UChar,		UInt32,		_Add>,
		&BinaryFunc_ElemWise<Int64,		UChar,		Int64,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	UChar,		UInt64,		_Add>,
		&BinaryFunc_ElemWise<Float,		UChar,		Float,		_Add>,
		&BinaryFunc_ElemWise<Double,	UChar,		Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	UChar,		Complex,	_Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Short,		Short,		Char,		_Add>,
		&BinaryFunc_ElemWise<Short,		Short,		UChar,		_Add>,
		&BinaryFunc_ElemWise<Short,		Short,		Short,		_Add>,
		&BinaryFunc_ElemWise<UShort,	Short,		UShort,		_Add>,
		&BinaryFunc_ElemWise<Int32,		Short,		Int32,		_Add>,
		&BinaryFunc_ElemWise<UInt32,	Short,		UInt32,		_Add>,
		&BinaryFunc_ElemWise<Int64,		Short,		Int64,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	Short,		UInt64,		_Add>,
		&BinaryFunc_ElemWise<Float,		Short,		Float,		_Add>,
		&BinaryFunc_ElemWise<Double,	Short,		Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Short,		Complex,	_Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<UShort,	UShort,		Char,		_Add>,
		&BinaryFunc_ElemWise<UShort,	UShort,		UChar,		_Add>,
		&BinaryFunc_ElemWise<UShort,	UShort,		Short,		_Add>,
		&BinaryFunc_ElemWise<UShort,	UShort,		UShort,		_Add>,
		&BinaryFunc_ElemWise<Int32,		UShort,		Int32,		_Add>,
		&BinaryFunc_ElemWise<UInt32,	UShort,		UInt32,		_Add>,
		&BinaryFunc_ElemWise<Int64,		UShort,		Int64,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	UShort,		UInt64,		_Add>,
		&BinaryFunc_ElemWise<Float,		UShort,		Float,		_Add>,
		&BinaryFunc_ElemWise<Double,	UShort,		Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	UShort,		Complex,	_Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Int32,		Int32,		Char,		_Add>,
		&BinaryFunc_ElemWise<Int32,		Int32,		UChar,		_Add>,
		&BinaryFunc_ElemWise<Int32,		Int32,		Short,		_Add>,
		&BinaryFunc_ElemWise<Int32,		Int32,		UShort,		_Add>,
		&BinaryFunc_ElemWise<Int32,		Int32,		Int32,		_Add>,
		&BinaryFunc_ElemWise<UInt32,	Int32,		UInt32,		_Add>,
		&BinaryFunc_ElemWise<Int64,		Int32,		Int64,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	Int32,		UInt64,		_Add>,
		&BinaryFunc_ElemWise<Float,		Int32,		Float,		_Add>,
		&BinaryFunc_ElemWise<Double,	Int32,		Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Int32,		Complex,	_Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<UInt32,	UInt32,		Char,		_Add>,
		&BinaryFunc_ElemWise<UInt32,	UInt32,		UChar,		_Add>,
		&BinaryFunc_ElemWise<UInt32,	UInt32,		Short,		_Add>,
		&BinaryFunc_ElemWise<UInt32,	UInt32,		UShort,		_Add>,
		&BinaryFunc_ElemWise<UInt32,	UInt32,		Int32,		_Add>,
		&BinaryFunc_ElemWise<UInt32,	UInt32,		UInt32,		_Add>,
		&BinaryFunc_ElemWise<Int64,		UInt32,		Int64,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	UInt32,		UInt64,		_Add>,
		&BinaryFunc_ElemWise<Float,		UInt32,		Float,		_Add>,
		&BinaryFunc_ElemWise<Double,	UInt32,		Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	UInt32,		Complex,	_Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Int64,		Int64,		Char,		_Add>,
		&BinaryFunc_ElemWise<Int64,		Int64,		UChar,		_Add>,
		&BinaryFunc_ElemWise<Int64,		Int64,		Short,		_Add>,
		&BinaryFunc_ElemWise<Int64,		Int64,		UShort,		_Add>,
		&BinaryFunc_ElemWise<Int64,		Int64,		Int32,		_Add>,
		&BinaryFunc_ElemWise<Int64,		Int64,		UInt32,		_Add>,
		&BinaryFunc_ElemWise<Int64,		Int64,		Int64,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	Int64,		UInt64,		_Add>,
		&BinaryFunc_ElemWise<Float,		Int64,		Float,		_Add>,
		&BinaryFunc_ElemWise<Double,	Int64,		Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Int64,		Complex,	_Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<UInt64,	UInt64,		Char,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	UInt64,		UChar,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	UInt64,		Short,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	UInt64,		UShort,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	UInt64,		Int32,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	UInt64,		UInt32,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	UInt64,		Int64,		_Add>,
		&BinaryFunc_ElemWise<UInt64,	UInt64,		UInt64,		_Add>,
		&BinaryFunc_ElemWise<Float,		UInt64,		Float,		_Add>,
		&BinaryFunc_ElemWise<Double,	UInt64,		Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	UInt64,		Complex,	_Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Float,		Float,		Char,		_Add>,
		&BinaryFunc_ElemWise<Float,		Float,		UChar,		_Add>,
		&BinaryFunc_ElemWise<Float,		Float,		Short,		_Add>,
		&BinaryFunc_ElemWise<Float,		Float,		UShort,		_Add>,
		&BinaryFunc_ElemWise<Float,		Float,		Int32,		_Add>,
		&BinaryFunc_ElemWise<Float,		Float,		UInt32,		_Add>,
		&BinaryFunc_ElemWise<Float,		Float,		Int64,		_Add>,
		&BinaryFunc_ElemWise<Float,		Float,		UInt64,		_Add>,
		&BinaryFunc_ElemWise<Float,		Float,		Float,		_Add>,
		&BinaryFunc_ElemWise<Double,	Float,		Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Float,		Complex,	_Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Double,	Double,		Char,		_Add>,
		&BinaryFunc_ElemWise<Double,	Double,		UChar,		_Add>,
		&BinaryFunc_ElemWise<Double,	Double,		Short,		_Add>,
		&BinaryFunc_ElemWise<Double,	Double,		UShort,		_Add>,
		&BinaryFunc_ElemWise<Double,	Double,		Int32,		_Add>,
		&BinaryFunc_ElemWise<Double,	Double,		UInt32,		_Add>,
		&BinaryFunc_ElemWise<Double,	Double,		Int64,		_Add>,
		&BinaryFunc_ElemWise<Double,	Double,		UInt64,		_Add>,
		&BinaryFunc_ElemWise<Double,	Double,		Float,		_Add>,
		&BinaryFunc_ElemWise<Double,	Double,		Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Double,		Complex,	_Add>,
	}, {
		nullptr,
//		&BinaryFunc_ElemWise<Complex,	Complex,	Char,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Complex,	UChar,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Complex,	Short,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Complex,	UShort,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Complex,	Int32,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Complex,	UInt32,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Complex,	Int64,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Complex,	UInt64,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Complex,	Float,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Complex,	Double,		_Add>,
//		&BinaryFunc_ElemWise<Complex,	Complex,	Complex,	_Add>,
	},
};

Array::BinaryFunc Array::_binaryFuncTbl_Sub[ETYPE_Max][ETYPE_Max] = {
};

Array::BinaryFunc Array::_binaryFuncTbl_Mul[ETYPE_Max][ETYPE_Max] = {
};

Array::BinaryFunc Array::_binaryFuncTbl_Div[ETYPE_Max][ETYPE_Max] = {
};

Array::BinaryFunc Array::_binaryFuncTbl_Mod[ETYPE_Max][ETYPE_Max] = {
};

Array::BinaryFunc Array::_binaryFuncTbl_Pow[ETYPE_Max][ETYPE_Max] = {
};

Array::BinaryFunc Array::_binaryFuncTbl_And[ETYPE_Max][ETYPE_Max] = {
};

Array::BinaryFunc Array::_binaryFuncTbl_Or[ETYPE_Max][ETYPE_Max] = {
};

Array::BinaryFunc Array::_binaryFuncTbl_Xor[ETYPE_Max][ETYPE_Max] = {
};

Array::BinaryFunc Array::_binaryFuncTbl_Shl[ETYPE_Max][ETYPE_Max] = {
};

Array::BinaryFunc Array::_binaryFuncTbl_Shr[ETYPE_Max][ETYPE_Max] = {
};


Array::BinaryFunc Array::_binaryFuncTbl_Dot[ETYPE_Max][ETYPE_Max] = {
	{
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
	}, {
		nullptr,
		&BinaryFunc_Dot<Char,		Char,		Char	>,
		&BinaryFunc_Dot<UChar,		Char,		UChar	>,
		&BinaryFunc_Dot<Short,		Char,		Short	>,
		&BinaryFunc_Dot<UShort,		Char,		UShort	>,
		&BinaryFunc_Dot<Int32,		Char,		Int32	>,
		&BinaryFunc_Dot<UInt32,		Char,		UInt32	>,
		&BinaryFunc_Dot<Int64,		Char,		Int64	>,
		&BinaryFunc_Dot<UInt64,		Char,		UInt64	>,
		&BinaryFunc_Dot<Float,		Char,		Float	>,
		&BinaryFunc_Dot<Double,		Char,		Double	>,
		//&BinaryFunc_Dot<Complex,	UChar,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<UChar,		UChar,		Char	>,
		&BinaryFunc_Dot<UChar,		UChar,		UChar	>,
		&BinaryFunc_Dot<Short,		UChar,		Short	>,
		&BinaryFunc_Dot<UShort,		UChar,		UShort	>,
		&BinaryFunc_Dot<Int32,		UChar,		Int32	>,
		&BinaryFunc_Dot<UInt32,		UChar,		UInt32	>,
		&BinaryFunc_Dot<Int64,		UChar,		Int64	>,
		&BinaryFunc_Dot<UInt64,		UChar,		UInt64	>,
		&BinaryFunc_Dot<Float,		UChar,		Float	>,
		&BinaryFunc_Dot<Double,		UChar,		Double	>,
		//&BinaryFunc_Dot<Complex,	UChar,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Short,		Short,		Char	>,
		&BinaryFunc_Dot<Short,		Short,		UChar	>,
		&BinaryFunc_Dot<Short,		Short,		Short	>,
		&BinaryFunc_Dot<UShort,		Short,		UShort	>,
		&BinaryFunc_Dot<Int32,		Short,		Int32	>,
		&BinaryFunc_Dot<UInt32,		Short,		UInt32	>,
		&BinaryFunc_Dot<Int64,		Short,		Int64	>,
		&BinaryFunc_Dot<UInt64,		Short,		UInt64	>,
		&BinaryFunc_Dot<Float,		Short,		Float	>,
		&BinaryFunc_Dot<Double,		Short,		Double	>,
		//&BinaryFunc_Dot<Complex,	Short,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<UShort,		UShort,		Char	>,
		&BinaryFunc_Dot<UShort,		UShort,		UChar	>,
		&BinaryFunc_Dot<UShort,		UShort,		Short	>,
		&BinaryFunc_Dot<UShort,		UShort,		UShort	>,
		&BinaryFunc_Dot<Int32,		UShort,		Int32	>,
		&BinaryFunc_Dot<UInt32,		UShort,		UInt32	>,
		&BinaryFunc_Dot<Int64,		UShort,		Int64	>,
		&BinaryFunc_Dot<UInt64,		UShort,		UInt64	>,
		&BinaryFunc_Dot<Float,		UShort,		Float	>,
		&BinaryFunc_Dot<Double,		UShort,		Double	>,
		//&BinaryFunc_Dot<Complex,	UShort,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Int32,		Int32,		Char	>,
		&BinaryFunc_Dot<Int32,		Int32,		UChar	>,
		&BinaryFunc_Dot<Int32,		Int32,		Short	>,
		&BinaryFunc_Dot<Int32,		Int32,		UShort	>,
		&BinaryFunc_Dot<Int32,		Int32,		Int32	>,
		&BinaryFunc_Dot<UInt32,		Int32,		UInt32	>,
		&BinaryFunc_Dot<Int64,		Int32,		Int64	>,
		&BinaryFunc_Dot<UInt64,		Int32,		UInt64	>,
		&BinaryFunc_Dot<Float,		Int32,		Float	>,
		&BinaryFunc_Dot<Double,		Int32,		Double	>,
		//&BinaryFunc_Dot<Complex,	Int32,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<UInt32,		UInt32,		Char	>,
		&BinaryFunc_Dot<UInt32,		UInt32,		UChar	>,
		&BinaryFunc_Dot<UInt32,		UInt32,		Short	>,
		&BinaryFunc_Dot<UInt32,		UInt32,		UShort	>,
		&BinaryFunc_Dot<UInt32,		UInt32,		Int32	>,
		&BinaryFunc_Dot<UInt32,		UInt32,		UInt32	>,
		&BinaryFunc_Dot<Int64,		UInt32,		Int64	>,
		&BinaryFunc_Dot<UInt64,		UInt32,		UInt64	>,
		&BinaryFunc_Dot<Float,		UInt32,		Float	>,
		&BinaryFunc_Dot<Double,		UInt32,		Double	>,
		//&BinaryFunc_Dot<Complex,	UInt32,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Int64,		Int64,		Char	>,
		&BinaryFunc_Dot<Int64,		Int64,		UChar	>,
		&BinaryFunc_Dot<Int64,		Int64,		Short	>,
		&BinaryFunc_Dot<Int64,		Int64,		UShort	>,
		&BinaryFunc_Dot<Int64,		Int64,		Int32	>,
		&BinaryFunc_Dot<Int64,		Int64,		UInt32	>,
		&BinaryFunc_Dot<Int64,		Int64,		Int64	>,
		&BinaryFunc_Dot<UInt64,		Int64,		UInt64	>,
		&BinaryFunc_Dot<Float,		Int64,		Float	>,
		&BinaryFunc_Dot<Double,		Int64,		Double	>,
		//&BinaryFunc_Dot<Complex,	Int64,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<UInt64,		UInt64,		Char	>,
		&BinaryFunc_Dot<UInt64,		UInt64,		UChar	>,
		&BinaryFunc_Dot<UInt64,		UInt64,		Short	>,
		&BinaryFunc_Dot<UInt64,		UInt64,		UShort	>,
		&BinaryFunc_Dot<UInt64,		UInt64,		Int32	>,
		&BinaryFunc_Dot<UInt64,		UInt64,		UInt32	>,
		&BinaryFunc_Dot<UInt64,		UInt64,		Int64	>,
		&BinaryFunc_Dot<UInt64,		UInt64,		UInt64	>,
		&BinaryFunc_Dot<Float,		UInt64,		Float	>,
		&BinaryFunc_Dot<Double,		UInt64,		Double	>,
		//&BinaryFunc_Dot<Complex,	UInt64,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Float,		Float,		Char	>,
		&BinaryFunc_Dot<Float,		Float,		UChar	>,
		&BinaryFunc_Dot<Float,		Float,		Short	>,
		&BinaryFunc_Dot<Float,		Float,		UShort	>,
		&BinaryFunc_Dot<Float,		Float,		Int32	>,
		&BinaryFunc_Dot<Float,		Float,		UInt32	>,
		&BinaryFunc_Dot<Float,		Float,		Int64	>,
		&BinaryFunc_Dot<Float,		Float,		UInt64	>,
		&BinaryFunc_Dot<Float,		Float,		Float	>,
		&BinaryFunc_Dot<Double,		Float,		Double	>,
		//&BinaryFunc_Dot<Complex,	Float,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Double,		Double,		Char	>,
		&BinaryFunc_Dot<Double,		Double,		UChar	>,
		&BinaryFunc_Dot<Double,		Double,		Short	>,
		&BinaryFunc_Dot<Double,		Double,		UShort	>,
		&BinaryFunc_Dot<Double,		Double,		Int32	>,
		&BinaryFunc_Dot<Double,		Double,		UInt32	>,
		&BinaryFunc_Dot<Double,		Double,		Int64	>,
		&BinaryFunc_Dot<Double,		Double,		UInt64	>,
		&BinaryFunc_Dot<Double,		Double,		Float	>,
		&BinaryFunc_Dot<Double,		Double,		Double	>,
		//&BinaryFunc_Dot<Complex,	Double,		Complex	>,
	}, {
		nullptr,
		//&BinaryFunc_Dot<Complex,	Complex,	Char	>,
		//&BinaryFunc_Dot<Complex,	Complex,	UChar	>,
		//&BinaryFunc_Dot<Complex,	Complex,	Short	>,
		//&BinaryFunc_Dot<Complex,	Complex,	UShort	>,
		//&BinaryFunc_Dot<Complex,	Complex,	Int32	>,
		//&BinaryFunc_Dot<Complex,	Complex,	UInt32	>,
		//&BinaryFunc_Dot<Complex,	Complex,	Int64	>,
		//&BinaryFunc_Dot<Complex,	Complex,	UInt64	>,
		//&BinaryFunc_Dot<Complex,	Complex,	Float	>,
		//&BinaryFunc_Dot<Complex,	Complex,	Double	>,
		//&BinaryFunc_Dot<Complex,	Complex,	Complex	>,
	},
};

}
