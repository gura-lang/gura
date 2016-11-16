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
inline void Pos(T_ElemResult &elemResult, T_Elem elem) {
	elemResult = static_cast<T_ElemResult>(+elem);
}

template<typename T_ElemResult, typename T_Elem>
inline void Neg(T_ElemResult &elemResult, T_Elem elem) {
	elemResult = static_cast<T_ElemResult>(-elem);
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void Add(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) + elemR;
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void Sub(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) - elemR;
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void Mul(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) * elemR;
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline bool Div(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) / elemR;
	return true;
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline bool Mod(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) % elemR;
	return true;
}

template<>
inline bool Mod<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = ::fmodf(elemL, elemR);
	return true;
}

template<>
inline bool Mod<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = ::fmod(elemL, elemR);
	return true;
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void Pow(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(
		std::pow(static_cast<double>(elemL), static_cast<double>(elemR)));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void And(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) & elemR;
}

template<>
inline void And<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = static_cast<float>(static_cast<UInt32>(elemL) & static_cast<UInt32>(elemR));
}

template<>
inline void And<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = static_cast<double>(static_cast<UInt32>(elemL) & static_cast<UInt32>(elemR));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void Or(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) | elemR;
}

template<>
inline void Or<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = static_cast<float>(static_cast<UInt32>(elemL) | static_cast<UInt32>(elemR));
}

template<>
inline void Or<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = static_cast<double>(static_cast<UInt32>(elemL) | static_cast<UInt32>(elemR));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void Xor(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) ^ elemR;
}

template<>
inline void Xor<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = static_cast<float>(static_cast<UInt32>(elemL) ^ static_cast<UInt32>(elemR));
}

template<>
inline void Xor<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = static_cast<double>(static_cast<UInt32>(elemL) ^ static_cast<UInt32>(elemR));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void Shl(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) << elemR;
}

template<>
inline void Shl<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = static_cast<float>(static_cast<UInt32>(elemL) << static_cast<Int32>(elemR));
}

template<>
inline void Shl<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = static_cast<double>(static_cast<UInt32>(elemL) << static_cast<Int32>(elemR));
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
inline void Shr(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
	elemResult = static_cast<T_ElemResult>(elemL) >> elemR;
}

template<>
inline void Shr<float, float, float>(float &elemResult, float elemL, float elemR) {
	elemResult = static_cast<float>(static_cast<UInt32>(elemL) >> static_cast<Int32>(elemR));
}

template<>
inline void Shr<double, double, double>(double &elemResult, double elemL, double elemR) {
	elemResult = static_cast<double>(static_cast<UInt32>(elemL) >> static_cast<Int32>(elemR));
}

//template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
//inline void op(T_ElemResult &elemResult, T_ElemL elemL, T_ElemR elemR) {
//}

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
		//&BinaryFunc_ElemWise<Char,		Char,		Char,		&Add<Char, Char, Char> >,
	}
};

#if 0
Array::BinaryFunc Array::_binaryFuncTbl_Add[ETYPE_Max][ETYPE_Max] = {
	{
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		Char,		Char,		Add>,
		&BinaryFunc_ElemWise<Char,		Char,		UChar,		Add>,
		&BinaryFunc_ElemWise<Short,		Char,		Short,		Add>,
		&BinaryFunc_ElemWise<Short,		Char,		UShort,		Add>,
		&BinaryFunc_ElemWise<Int32,		Char,		Int32,		Add>,
		&BinaryFunc_ElemWise<Int32,		Char,		UInt32,		Add>,
		&BinaryFunc_ElemWise<Int64,		Char,		Int64,		Add>,
		&BinaryFunc_ElemWise<Int64,		Char,		UInt64,		Add>,
		&BinaryFunc_ElemWise<Float,		Char,		Float,		Add>,
		&BinaryFunc_ElemWise<Double,	Char,		Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	UChar,		Complex,	Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		UChar,		Char,		Add>,
		&BinaryFunc_ElemWise<UChar,		UChar,		UChar,		Add>,
		&BinaryFunc_ElemWise<Short,		UChar,		Short,		Add>,
		&BinaryFunc_ElemWise<UShort,	UChar,		UShort,		Add>,
		&BinaryFunc_ElemWise<Int32,		UChar,		Int32,		Add>,
		&BinaryFunc_ElemWise<UInt32,	UChar,		UInt32,		Add>,
		&BinaryFunc_ElemWise<Int64,		UChar,		Int64,		Add>,
		&BinaryFunc_ElemWise<UInt64,	UChar,		UInt64,		Add>,
		&BinaryFunc_ElemWise<Float,		UChar,		Float,		Add>,
		&BinaryFunc_ElemWise<Double,	UChar,		Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	UChar,		Complex,	Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		Short,		Char,		Add>,
		&BinaryFunc_ElemWise<UChar,		Short,		UChar,		Add>,
		&BinaryFunc_ElemWise<Short,		Short,		Short,		Add>,
		&BinaryFunc_ElemWise<UShort,	Short,		UShort,		Add>,
		&BinaryFunc_ElemWise<Int32,		Short,		Int32,		Add>,
		&BinaryFunc_ElemWise<UInt32,	Short,		UInt32,		Add>,
		&BinaryFunc_ElemWise<Int64,		Short,		Int64,		Add>,
		&BinaryFunc_ElemWise<UInt64,	Short,		UInt64,		Add>,
		&BinaryFunc_ElemWise<Float,		Short,		Float,		Add>,
		&BinaryFunc_ElemWise<Double,	Short,		Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	Short,		Complex,	Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		UShort,		Char,		Add>,
		&BinaryFunc_ElemWise<UChar,		UShort,		UChar,		Add>,
		&BinaryFunc_ElemWise<Short,		UShort,		Short,		Add>,
		&BinaryFunc_ElemWise<UShort,	UShort,		UShort,		Add>,
		&BinaryFunc_ElemWise<Int32,		UShort,		Int32,		Add>,
		&BinaryFunc_ElemWise<UInt32,	UShort,		UInt32,		Add>,
		&BinaryFunc_ElemWise<Int64,		UShort,		Int64,		Add>,
		&BinaryFunc_ElemWise<UInt64,	UShort,		UInt64,		Add>,
		&BinaryFunc_ElemWise<Float,		UShort,		Float,		Add>,
		&BinaryFunc_ElemWise<Double,	UShort,		Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	UShort,		Complex,	Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		Int32,		Char,		Add>,
		&BinaryFunc_ElemWise<UChar,		Int32,		UChar,		Add>,
		&BinaryFunc_ElemWise<Short,		Int32,		Short,		Add>,
		&BinaryFunc_ElemWise<UShort,	Int32,		UShort,		Add>,
		&BinaryFunc_ElemWise<Int32,		Int32,		Int32,		Add>,
		&BinaryFunc_ElemWise<UInt32,	Int32,		UInt32,		Add>,
		&BinaryFunc_ElemWise<Int64,		Int32,		Int64,		Add>,
		&BinaryFunc_ElemWise<UInt64,	Int32,		UInt64,		Add>,
		&BinaryFunc_ElemWise<Float,		Int32,		Float,		Add>,
		&BinaryFunc_ElemWise<Double,	Int32,		Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	Int32,		Complex,	Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		UInt32,		Char,		Add>,
		&BinaryFunc_ElemWise<UChar,		UInt32,		UChar,		Add>,
		&BinaryFunc_ElemWise<Short,		UInt32,		Short,		Add>,
		&BinaryFunc_ElemWise<UShort,	UInt32,		UShort,		Add>,
		&BinaryFunc_ElemWise<Int32,		UInt32,		Int32,		Add>,
		&BinaryFunc_ElemWise<UInt32,	UInt32,		UInt32,		Add>,
		&BinaryFunc_ElemWise<Int64,		UInt32,		Int64,		Add>,
		&BinaryFunc_ElemWise<UInt64,	UInt32,		UInt64,		Add>,
		&BinaryFunc_ElemWise<Float,		UInt32,		Float,		Add>,
		&BinaryFunc_ElemWise<Double,	UInt32,		Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	UInt32,		Complex,	Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		Int64,		Char,		Add>,
		&BinaryFunc_ElemWise<UChar,		Int64,		UChar,		Add>,
		&BinaryFunc_ElemWise<Short,		Int64,		Short,		Add>,
		&BinaryFunc_ElemWise<UShort,	Int64,		UShort,		Add>,
		&BinaryFunc_ElemWise<Int32,		Int64,		Int32,		Add>,
		&BinaryFunc_ElemWise<UInt32,	Int64,		UInt32,		Add>,
		&BinaryFunc_ElemWise<Int64,		Int64,		Int64,		Add>,
		&BinaryFunc_ElemWise<UInt64,	Int64,		UInt64,		Add>,
		&BinaryFunc_ElemWise<Float,		Int64,		Float,		Add>,
		&BinaryFunc_ElemWise<Double,	Int64,		Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	Int64,		Complex,	Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		UInt64,		Char,		Add>,
		&BinaryFunc_ElemWise<UChar,		UInt64,		UChar,		Add>,
		&BinaryFunc_ElemWise<Short,		UInt64,		Short,		Add>,
		&BinaryFunc_ElemWise<UShort,	UInt64,		UShort,		Add>,
		&BinaryFunc_ElemWise<Int32,		UInt64,		Int32,		Add>,
		&BinaryFunc_ElemWise<UInt32,	UInt64,		UInt32,		Add>,
		&BinaryFunc_ElemWise<Int64,		UInt64,		Int64,		Add>,
		&BinaryFunc_ElemWise<UInt64,	UInt64,		UInt64,		Add>,
		&BinaryFunc_ElemWise<Float,		UInt64,		Float,		Add>,
		&BinaryFunc_ElemWise<Double,	UInt64,		Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	UInt64,		Complex,	Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		Float,		Char,		Add>,
		&BinaryFunc_ElemWise<UChar,		Float,		UChar,		Add>,
		&BinaryFunc_ElemWise<Short,		Float,		Short,		Add>,
		&BinaryFunc_ElemWise<UShort,	Float,		UShort,		Add>,
		&BinaryFunc_ElemWise<Int32,		Float,		Int32,		Add>,
		&BinaryFunc_ElemWise<UInt32,	Float,		UInt32,		Add>,
		&BinaryFunc_ElemWise<Int64,		Float,		Int64,		Add>,
		&BinaryFunc_ElemWise<UInt64,	Float,		UInt64,		Add>,
		&BinaryFunc_ElemWise<Float,		Float,		Float,		Add>,
		&BinaryFunc_ElemWise<Double,	Float,		Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	Float,		Complex,	Add>,
	}, {
		nullptr,
		&BinaryFunc_ElemWise<Char,		Double,		Char,		Add>,
		&BinaryFunc_ElemWise<UChar,		Double,		UChar,		Add>,
		&BinaryFunc_ElemWise<Short,		Double,		Short,		Add>,
		&BinaryFunc_ElemWise<UShort,	Double,		UShort,		Add>,
		&BinaryFunc_ElemWise<Int32,		Double,		Int32,		Add>,
		&BinaryFunc_ElemWise<UInt32,	Double,		UInt32,		Add>,
		&BinaryFunc_ElemWise<Int64,		Double,		Int64,		Add>,
		&BinaryFunc_ElemWise<UInt64,	Double,		UInt64,		Add>,
		&BinaryFunc_ElemWise<Float,		Double,		Float,		Add>,
		&BinaryFunc_ElemWise<Double,	Double,		Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	Double,		Complex,	Add>,
	}, {
		nullptr,
		//&BinaryFunc_ElemWise<Char,	Complex,	Char,		Add>,
		//&BinaryFunc_ElemWise<UChar,	Complex,	UChar,		Add>,
		//&BinaryFunc_ElemWise<Short,	Complex,	Short,		Add>,
		//&BinaryFunc_ElemWise<UShort	Complex,	UShort,		Add>,
		//&BinaryFunc_ElemWise<Int32,	Complex,	Int32,		Add>,
		//&BinaryFunc_ElemWise<UInt32	Complex,	UInt32,		Add>,
		//&BinaryFunc_ElemWise<Int64,	Complex,	Int64,		Add>,
		//&BinaryFunc_ElemWise<UInt64	Complex,	UInt64,		Add>,
		//&BinaryFunc_ElemWise<Float,	Complex,	Float,		Add>,
		//&BinaryFunc_ElemWise<Double	Complex,	Double,		Add>,
		//&BinaryFunc_ElemWise<Complex,	Complex,	Complex,	Add>,
	},
};
#endif

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
		&BinaryFunc_Dot<Char,		Char,		UChar	>,
		&BinaryFunc_Dot<Short,		Char,		Short	>,
		&BinaryFunc_Dot<Short,		Char,		UShort	>,
		&BinaryFunc_Dot<Int32,		Char,		Int32	>,
		&BinaryFunc_Dot<Int32,		Char,		UInt32	>,
		&BinaryFunc_Dot<Int64,		Char,		Int64	>,
		&BinaryFunc_Dot<Int64,		Char,		UInt64	>,
		&BinaryFunc_Dot<Float,		Char,		Float	>,
		&BinaryFunc_Dot<Double,		Char,		Double	>,
		//&BinaryFunc_Dot<Complex,	UChar,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Char,		UChar,		Char	>,
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
		&BinaryFunc_Dot<Char,		Short,		Char	>,
		&BinaryFunc_Dot<UChar,		Short,		UChar	>,
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
		&BinaryFunc_Dot<Char,		UShort,		Char	>,
		&BinaryFunc_Dot<UChar,		UShort,		UChar	>,
		&BinaryFunc_Dot<Short,		UShort,		Short	>,
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
		&BinaryFunc_Dot<Char,		Int32,		Char	>,
		&BinaryFunc_Dot<UChar,		Int32,		UChar	>,
		&BinaryFunc_Dot<Short,		Int32,		Short	>,
		&BinaryFunc_Dot<UShort,		Int32,		UShort	>,
		&BinaryFunc_Dot<Int32,		Int32,		Int32	>,
		&BinaryFunc_Dot<UInt32,		Int32,		UInt32	>,
		&BinaryFunc_Dot<Int64,		Int32,		Int64	>,
		&BinaryFunc_Dot<UInt64,		Int32,		UInt64	>,
		&BinaryFunc_Dot<Float,		Int32,		Float	>,
		&BinaryFunc_Dot<Double,		Int32,		Double	>,
		//&BinaryFunc_Dot<Complex,	Int32,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Char,		UInt32,		Char	>,
		&BinaryFunc_Dot<UChar,		UInt32,		UChar	>,
		&BinaryFunc_Dot<Short,		UInt32,		Short	>,
		&BinaryFunc_Dot<UShort,		UInt32,		UShort	>,
		&BinaryFunc_Dot<Int32,		UInt32,		Int32	>,
		&BinaryFunc_Dot<UInt32,		UInt32,		UInt32	>,
		&BinaryFunc_Dot<Int64,		UInt32,		Int64	>,
		&BinaryFunc_Dot<UInt64,		UInt32,		UInt64	>,
		&BinaryFunc_Dot<Float,		UInt32,		Float	>,
		&BinaryFunc_Dot<Double,		UInt32,		Double	>,
		//&BinaryFunc_Dot<Complex,	UInt32,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Char,		Int64,		Char	>,
		&BinaryFunc_Dot<UChar,		Int64,		UChar	>,
		&BinaryFunc_Dot<Short,		Int64,		Short	>,
		&BinaryFunc_Dot<UShort,		Int64,		UShort	>,
		&BinaryFunc_Dot<Int32,		Int64,		Int32	>,
		&BinaryFunc_Dot<UInt32,		Int64,		UInt32	>,
		&BinaryFunc_Dot<Int64,		Int64,		Int64	>,
		&BinaryFunc_Dot<UInt64,		Int64,		UInt64	>,
		&BinaryFunc_Dot<Float,		Int64,		Float	>,
		&BinaryFunc_Dot<Double,		Int64,		Double	>,
		//&BinaryFunc_Dot<Complex,	Int64,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Char,		UInt64,		Char	>,
		&BinaryFunc_Dot<UChar,		UInt64,		UChar	>,
		&BinaryFunc_Dot<Short,		UInt64,		Short	>,
		&BinaryFunc_Dot<UShort,		UInt64,		UShort	>,
		&BinaryFunc_Dot<Int32,		UInt64,		Int32	>,
		&BinaryFunc_Dot<UInt32,		UInt64,		UInt32	>,
		&BinaryFunc_Dot<Int64,		UInt64,		Int64	>,
		&BinaryFunc_Dot<UInt64,		UInt64,		UInt64	>,
		&BinaryFunc_Dot<Float,		UInt64,		Float	>,
		&BinaryFunc_Dot<Double,		UInt64,		Double	>,
		//&BinaryFunc_Dot<Complex,	UInt64,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Char,		Float,		Char	>,
		&BinaryFunc_Dot<UChar,		Float,		UChar	>,
		&BinaryFunc_Dot<Short,		Float,		Short	>,
		&BinaryFunc_Dot<UShort,		Float,		UShort	>,
		&BinaryFunc_Dot<Int32,		Float,		Int32	>,
		&BinaryFunc_Dot<UInt32,		Float,		UInt32	>,
		&BinaryFunc_Dot<Int64,		Float,		Int64	>,
		&BinaryFunc_Dot<UInt64,		Float,		UInt64	>,
		&BinaryFunc_Dot<Float,		Float,		Float	>,
		&BinaryFunc_Dot<Double,		Float,		Double	>,
		//&BinaryFunc_Dot<Complex,	Float,		Complex	>,
	}, {
		nullptr,
		&BinaryFunc_Dot<Char,		Double,		Char	>,
		&BinaryFunc_Dot<UChar,		Double,		UChar	>,
		&BinaryFunc_Dot<Short,		Double,		Short	>,
		&BinaryFunc_Dot<UShort,		Double,		UShort	>,
		&BinaryFunc_Dot<Int32,		Double,		Int32	>,
		&BinaryFunc_Dot<UInt32,		Double,		UInt32	>,
		&BinaryFunc_Dot<Int64,		Double,		Int64	>,
		&BinaryFunc_Dot<UInt64,		Double,		UInt64	>,
		&BinaryFunc_Dot<Float,		Double,		Float	>,
		&BinaryFunc_Dot<Double,		Double,		Double	>,
		//&BinaryFunc_Dot<Complex,	Double,		Complex	>,
	}, {
		nullptr,
		//&BinaryFunc_Dot<Char,		Complex,	Char	>,
		//&BinaryFunc_Dot<UChar,	Complex,	UChar	>,
		//&BinaryFunc_Dot<Short,	Complex,	Short	>,
		//&BinaryFunc_Dot<UShort	Complex,	UShort	>,
		//&BinaryFunc_Dot<Int32,	Complex,	Int32	>,
		//&BinaryFunc_Dot<UInt32	Complex,	UInt32	>,
		//&BinaryFunc_Dot<Int64,	Complex,	Int64	>,
		//&BinaryFunc_Dot<UInt64	Complex,	UInt64	>,
		//&BinaryFunc_Dot<Float,	Complex,	Float	>,
		//&BinaryFunc_Dot<Double	Complex,	Double	>,
		//&BinaryFunc_Dot<Complex,	Complex,	Complex	>,
	},
};

}
