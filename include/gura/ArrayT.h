//=============================================================================
// ArrayT
//=============================================================================
#ifndef __GURA_ARRAYT_H__
#define __GURA_ARRAYT_H__

#include "Array.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ArrayT
//-----------------------------------------------------------------------------
template<typename T_Elem>
class GURA_DLLDECLARE ArrayT : public Array {
public:
	class GURA_DLLDECLARE Iterator_Each : public Iterator {
	private:
		AutoPtr<ArrayT> _pArrayT;
		bool _flatFlag;
		size_t _idx;
	public:
		inline Iterator_Each(ArrayT *pArrayT, bool flatFlag) :
			Iterator(FinitePredictable), _pArrayT(pArrayT), _flatFlag(flatFlag), _idx(0) {}
		virtual size_t GetLength() const;
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Gura_DeclareReferenceAccessor(ArrayT);
public:
	static ValueType ValueTypeElem;
	static ElemType ElemTypeThis;
	static size_t ElemBytes;
	static const char *ElemTypeName;
	static const char *ConstructorName;
protected:
	inline ArrayT(const ArrayT &src) : Array(src) {}
	ArrayT();
public:
	inline T_Elem *GetPointerOrigin() {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer());
	}
	inline const T_Elem *GetPointerOrigin() const {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer());
	}
	inline T_Elem *GetPointer() { return GetPointerOrigin() + GetOffsetBase(); }
	inline const T_Elem *GetPointer() const { return GetPointerOrigin() + GetOffsetBase(); }
	inline operator T_Elem *() { return GetPointer(); }
	inline operator const T_Elem *() const { return GetPointer(); }
	virtual Array *Clone(bool cloneMemoryFlag) const;
	virtual String ToString(bool exprFlag, size_t nDimsOnHorz) const;
	virtual Array *CreateLike() const;
	virtual void Dump(Signal &sig, Stream &stream, bool upperFlag) const;
	virtual bool DoesContainZero() const;
	virtual bool DoesContainMinus() const;
	virtual bool DoesContainZeroOrMinus() const;
	virtual Double GetScalarNumber() const;
	virtual Complex GetScalarComplex() const;
	virtual void CopyToList(Object_list *pObjList) const;
	virtual void FillRand();
	virtual void FillRandRange(UInt range);
	virtual void FillRandNormal(double mu, double sigma);
	void SetScalar(const T_Elem &num);
	virtual void Fill(Double num);
	virtual void RoundOff(AutoPtr<Array> &pArrayRtn, double threshold) const;
	virtual void Flatten(AutoPtr<Array> &pArrayRtn) const;
	virtual void Transpose(AutoPtr<Array> &pArrayRtn, const IntList &axes) const;
	virtual bool FindMax(Signal &sig, AutoPtr<Array> &pArrayRtn, int axis) const;
	virtual bool FindMin(Signal &sig, AutoPtr<Array> &pArrayRtn, int axis) const;
	virtual bool FindMaxIndex(Signal &sig, AutoPtr<Array> &pArrayRtn, int axis, bool lastFlag) const;
	virtual bool FindMinIndex(Signal &sig, AutoPtr<Array> &pArrayRtn, int axis, bool lastFlag) const;
	virtual bool CalcSum(Signal &sig, AutoPtr<Array> &pArrayRtn, int axis, bool meanFlag) const;
	virtual bool CalcVar(Signal &sig, AutoPtr<Array> &pArrayRtn, int axis, bool populationFlag, bool stdFlag) const;
	template<typename T_KernelScanner>
	static bool ScanKernel1d(
		Signal &sig, ArrayT *pArrayT, const Dimension &dimCol,
		size_t sizeBlock, size_t sizeKernel, size_t stridesKernel, size_t sizePad,
		T_KernelScanner &kernelScanner);
	template<typename T_KernelScanner>
	static bool ScanKernel2d(
		Signal &sig, ArrayT *pArrayT, const Dimension &dimRow, const Dimension &dimCol,
		size_t sizeBlock, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelRow, size_t stridesKernelCol, size_t sizePadRow, size_t sizePadCol,
		T_KernelScanner &kernelScanner);
	template<typename T_KernelScanner>
	static bool ScanKernel3d(
		Signal &sig, ArrayT *pArrayT, const Dimension &dimPlane, const Dimension &dimRow, const Dimension &dimCol,
		size_t sizeBlock, size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol,
		T_KernelScanner &kernelScanner);
	virtual bool ExpandKernelVec1d(
		Signal &sig, AutoPtr<Array> &pArrayVec, size_t *pSize, size_t sizeKernel, size_t stridesKernel,
		size_t sizePad, ChannelPos channelPos, Double padNum) const;
	virtual bool ExpandKernelVec2d(
		Signal &sig, AutoPtr<Array> &pArrayVec, size_t *pSizeRow, size_t *pSizeCol,
		size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelRow, size_t stridesKernelCol, size_t sizePadRow, size_t sizePadCol,
		ChannelPos channelPos, Double padNum) const;
	virtual bool ExpandKernelVec3d(
		Signal &sig, AutoPtr<Array> &pArrayVec, size_t *pSizePlane, size_t *pSizeRow, size_t *pSizeCol,
		size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol,
		ChannelPos channelPos, Double padNum) const;
	virtual bool RestoreKernelVec1d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, size_t size, size_t sizeKernel, size_t stridesKernel,
		size_t sizePad, ChannelPos channelPos) const;
	virtual bool RestoreKernelVec2d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, size_t sizeRow, size_t sizeCol,
		size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadRow, size_t sizePadCol, ChannelPos channelPos) const;
	virtual bool RestoreKernelVec3d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, size_t sizePlane, size_t sizeRow, size_t sizeCol,
		size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol, ChannelPos channelPos) const;
	virtual bool CalcAveragePool1d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, size_t sizeKernel, size_t stridesKernel,
		size_t sizePad, ChannelPos channelPos) const;
	virtual bool CalcAveragePool2d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadRow, size_t sizePadCol, ChannelPos channelPos) const;
	virtual bool CalcAveragePool3d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol, ChannelPos channelPos) const;
	virtual bool CalcMaxPool1d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, size_t sizeKernel, size_t stridesKernel,
		size_t sizePad, ChannelPos channelPos) const;
	virtual bool CalcMaxPool2d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadRow, size_t sizePadCol, ChannelPos channelPos) const;
	virtual bool CalcMaxPool3d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol, ChannelPos channelPos) const;
	virtual bool CalcMaxPoolWithIndex1d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, AutoPtr<Array> &pArrayOfIndex,
		size_t sizeKernel, size_t stridesKernel,
		size_t sizePad, ChannelPos channelPos) const;
	virtual bool CalcMaxPoolWithIndex2d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, AutoPtr<Array> &pArrayOfIndex,
		size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadRow, size_t sizePadCol, ChannelPos channelPos) const;
	virtual bool CalcMaxPoolWithIndex3d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, AutoPtr<Array> &pArrayOfIndex,
		size_t sizeKernelPlane, size_t sizeKernelRow, size_t sizeKernelCol,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol, ChannelPos channelPos) const;
	virtual void AccumMaxPoolBackward(AutoPtr<Array> &pArrayGradDst, const Array *pArrayOfIndex) const;
	virtual bool CalcConv1d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArrayGear, size_t stridesKernel,
		size_t sizePad, ChannelPos channelPos) const;
	virtual bool CalcConv2d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArrayGear,
		size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadRow, size_t sizePadCol, ChannelPos channelPos) const;
	virtual bool CalcConv3d(
		Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArrayGear,
		size_t stridesKernelPlane, size_t stridesKernelRow, size_t stridesKernelCol,
		size_t sizePadPlane, size_t sizePadRow, size_t sizePadCol, ChannelPos channelPos) const;
	virtual Iterator *CreateIteratorEach(bool flatFlag) const;
	// functions to create an ArrayT instance
	static ArrayT *Create();
	static ArrayT *Create(const Dimensions &dims);
	static ArrayT *Create1d(size_t size);
	static ArrayT *Create2d(size_t sizeRow, size_t sizeCol);
	static ArrayT *Create3d(size_t sizePlane, size_t sizeRow, size_t sizeCol);
	static ArrayT *CreateScalar(const T_Elem &num);
	static ArrayT *CreateFromValue(Environment &env, const Value &value);
	static ArrayT *CreateFromList(const ValueList &valList);
	static ArrayT *CreateFromList(Environment &env, const ValueList &valList);
	static ArrayT *CreateFromIterator(Environment &env, Iterator *pIterator);
	static ArrayT *CreateFromExpr(Environment &env, const Expr *pExpr);
	// utilities
	static void FillDouble(T_Elem *pElem, size_t nElems, Double num, size_t strides);
	static void FillComplex(T_Elem *pElem, size_t nElems, const Complex &num, size_t strides) {}
	static bool StoreValueAt(Environment &env, T_Elem *pElem, const Value &value);
private:
	inline ~ArrayT() {}
};

//------------------------------------------------------------------------------
// UnaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, typename T_Operator>
bool Array::UnaryFuncTmpl(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray)
{
	const Dimensions &dims = pArray->GetDims();
	if (pArrayRtn.IsNull()) pArrayRtn.reset(ArrayT<T_ElemRtn>::Create(dims));
	T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
	const T_Elem *pElem = dynamic_cast<const ArrayT<T_Elem> *>(pArray)->GetPointer();
	if (pArray->IsRowMajor() || dims.size() < 2) {
		size_t nElems = pArray->GetElemNum();
		for (size_t i = 0; i < nElems; i++, pElem++) {
			T_Operator::Calc(*pElemRtn, *pElem);
			pElemRtn++;
		}
	} else { // pArray->IsColMajor() && dims.size() >= 2
		const Dimension &dimRow = dims.GetRow();
		const Dimension &dimCol = dims.GetCol();
		size_t nMats = pArray->GetElemNum() / dimRow.GetSizeProd();
		const T_Elem *pElemMat = pElem;
		for (size_t iMat = 0; iMat < nMats; iMat++, pElemMat += dimRow.GetSizeProd()) {
			const T_Elem *pElemRow = pElemMat;
			for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++,
					 pElemRow += dimRow.GetStrides()) {
				const T_Elem *pElemCol = pElemRow;
				for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++,
						 pElemCol += dimCol.GetStrides()) {
					T_Operator::Calc(*pElemRtn, *pElemCol);
					pElemRtn++;
				}
			}
		}
	}
	return true;
}

template<typename T_ElemRtn, typename T_Elem, typename T_Operator>
bool Array::UnaryFuncTmpl_ExcludeZero(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray)
{
	if (pArray->DoesContainZero()) {
		sig.SetError(ERR_MathError, "the array contains zero as its element");
		return false;
	}
	return UnaryFuncTmpl<T_ElemRtn, T_Elem, T_Operator>(sig, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// Unary2OutFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemRtnA, typename T_ElemRtnB, typename T_Elem, typename T_Operator>
bool Array::Unary2OutFuncTmpl(Signal &sig, AutoPtr<Array> &pArrayRtnA,
							  AutoPtr<Array> &pArrayRtnB, const Array *pArray)
{
	const Dimensions &dims = pArray->GetDims();
	if (pArrayRtnA.IsNull()) pArrayRtnA.reset(ArrayT<T_ElemRtnA>::Create(dims));
	if (pArrayRtnB.IsNull()) pArrayRtnB.reset(ArrayT<T_ElemRtnB>::Create(dims));
	T_ElemRtnA *pElemRtnA = dynamic_cast<ArrayT<T_ElemRtnA> *>(pArrayRtnA.get())->GetPointer();
	T_ElemRtnB *pElemRtnB = dynamic_cast<ArrayT<T_ElemRtnB> *>(pArrayRtnB.get())->GetPointer();
	const T_Elem *pElem = dynamic_cast<const ArrayT<T_Elem> *>(pArray)->GetPointer();
	if (pArray->IsRowMajor() || dims.size() < 2) {
		size_t nElems = pArray->GetElemNum();
		for (size_t i = 0; i < nElems; i++, pElem++) {
			T_Operator::Calc(*pElemRtnA, *pElemRtnB, *pElem);
			pElemRtnA++, pElemRtnB++;
		}
	} else { // pArray->IsColMajor() && dims.size() >= 2
		const Dimension &dimRow = dims.GetRow();
		const Dimension &dimCol = dims.GetCol();
		size_t nMats = pArray->GetElemNum() / dimRow.GetSizeProd();
		const T_Elem *pElemMat = pElem;
		for (size_t iMat = 0; iMat < nMats; iMat++, pElemMat += dimRow.GetSizeProd()) {
			const T_Elem *pElemRow = pElemMat;
			for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++,
					 pElemRow += dimRow.GetStrides()) {
				const T_Elem *pElemCol = pElemRow;
				for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++,
						 pElemCol += dimCol.GetStrides()) {
					T_Operator::Calc(*pElemRtnA, *pElemRtnB, *pElemCol);
					pElemRtnA++, pElemRtnB++;
				}
			}
		}
	}
	return true;
}

//------------------------------------------------------------------------------
// BinaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR, typename T_Operator>
bool Array::BinaryFuncTmpl_array_array(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArrayL, const Array *pArrayR)
{
	const Dimensions &dimsL = pArrayL->GetDims();
	const Dimensions &dimsR = pArrayR->GetDims();
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	size_t nElemsR = pArrayR->GetElemNum();
	if (nElemsL == nElemsR) {
		if (pArrayRtn.IsNull()) pArrayRtn.reset(ArrayT<T_ElemRtn>::Create(pArrayL->GetDims()));
		T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
		if (dimsL.size() == 1) { // dimsL.size() == 1 && dimsR.size() == 1
			for (size_t offset = 0; offset < nElemsL; offset++) {
				T_Operator::Calc(*pElemRtn, *(pElemL + offset), *(pElemR + offset));
				pElemRtn++;
			}
		} else { // dimsL.size() >= 2 && dimsR.size() >= 2
			const Dimension &dimRowL = dimsL.GetRow();
			const Dimension &dimColL = dimsL.GetCol();
			const Dimension &dimRowR = dimsR.GetRow();
			const Dimension &dimColR = dimsR.GetCol();
			size_t nMats = pArrayL->GetElemNum() / dimRowL.GetSizeProd();
			const T_ElemL *pElemMatL = pElemL;
			const T_ElemR *pElemMatR = pElemR;
			for (size_t iMat = 0; iMat < nMats; iMat++,
					 pElemMatL += dimRowL.GetSizeProd(), pElemMatR += dimRowR.GetSizeProd()) {
				const T_ElemL *pElemRowL = pElemMatL;
				const T_ElemR *pElemRowR = pElemMatR;
				for (size_t iRow = 0; iRow < dimRowL.GetSize(); iRow++,
						 pElemRowL += dimRowL.GetStrides(), pElemRowR += dimRowR.GetStrides()) {
					const T_ElemL *pElemColL = pElemRowL;
					const T_ElemR *pElemColR = pElemRowR;
					for (size_t iCol = 0; iCol < dimColL.GetSize(); iCol++,
							 pElemColL += dimColL.GetStrides(), pElemColR += dimColR.GetStrides()) {
						T_Operator::Calc(*pElemRtn, *pElemColL, *pElemColR);
						pElemRtn++;
					}
				}
			}
		}
	} else if (nElemsL < nElemsR) {
		if (pArrayRtn.IsNull()) pArrayRtn.reset(ArrayT<T_ElemRtn>::Create(pArrayR->GetDims()));
		T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
		if ((pArrayL->IsRowMajor() && pArrayR->IsRowMajor()) || (dimsL.size() == 1)) {
			size_t nBlks = nElemsR / nElemsL;
			const T_ElemR *pElemBlkR = pElemR;
			for (size_t iBlk = 0; iBlk < nBlks; iBlk++, pElemBlkR += nElemsL) {
				const T_ElemL *pElemIterL = pElemL;
				const T_ElemR *pElemIterR = pElemBlkR;
				for (size_t iElem = 0; iElem < nElemsL; iElem++,
						 pElemIterL++, pElemIterR++) {
					T_Operator::Calc(*pElemRtn, *pElemIterL, *pElemIterR);
					pElemRtn++;
				}
			}
		} else { // (pArrayL->IsColMajor() || pArrayR->IsColMajor()) && (dimsL.size() >= 2 && dimsR.size() >= 2)
			const Dimension &dimRowL = dimsL.GetRow();
			const Dimension &dimColL = dimsL.GetCol();
			const Dimension &dimRowR = dimsR.GetRow();
			const Dimension &dimColR = dimsR.GetCol();
			size_t nBlks = nElemsR / nElemsL;
			size_t nMats = pArrayL->GetElemNum() / dimRowL.GetSizeProd();
			const T_ElemR *pElemBlkR = pElemR;
			for (size_t iBlk = 0; iBlk < nBlks; iBlk++, pElemBlkR += nElemsL) {
				const T_ElemL *pElemMatL = pElemL;
				const T_ElemR *pElemMatR = pElemBlkR;
				for (size_t iMat = 0; iMat < nMats; iMat++,
						 pElemMatL += dimRowL.GetSizeProd(), pElemMatR += dimRowR.GetSizeProd()) {
					const T_ElemL *pElemRowL = pElemMatL;
					const T_ElemR *pElemRowR = pElemMatR;
					for (size_t iRow = 0; iRow < dimRowL.GetSize(); iRow++,
							 pElemRowL += dimRowL.GetStrides(), pElemRowR += dimRowR.GetStrides()) {
						const T_ElemL *pElemColL = pElemRowL;
						const T_ElemR *pElemColR = pElemRowR;
						for (size_t iCol = 0; iCol < dimColL.GetSize(); iCol++,
								 pElemColL += dimColL.GetStrides(), pElemColR += dimColR.GetStrides()) {
							T_Operator::Calc(*pElemRtn, *pElemColL, *pElemColR);
							pElemRtn++;
						}
					}
				}
			}
		}
	} else { // nElemsL > nElemsR
		if (pArrayRtn.IsNull()) pArrayRtn.reset(ArrayT<T_ElemRtn>::Create(pArrayL->GetDims()));
		T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
		if ((pArrayL->IsRowMajor() && pArrayR->IsRowMajor()) || (dimsR.size() == 1)) {
			size_t nBlks = nElemsL / nElemsR;
			const T_ElemL *pElemBlkL = pElemL;
			for (size_t iBlk = 0; iBlk < nBlks; iBlk++, pElemBlkL += nElemsR) {
				const T_ElemL *pElemIterL = pElemBlkL;
				const T_ElemR *pElemIterR = pElemR;
				for (size_t iElem = 0; iElem < nElemsR; iElem++,
						 pElemIterL++, pElemIterR++) {
					T_Operator::Calc(*pElemRtn, *pElemIterL, *pElemIterR);
					pElemRtn++;
				}
			}
		} else { // (pArrayL->IsColMajor() || pArrayR->IsColMajor()) && (dimsL.size() >= 2 && dimsR.size() >= 2)
			const Dimension &dimRowL = dimsL.GetRow();
			const Dimension &dimColL = dimsL.GetCol();
			const Dimension &dimRowR = dimsR.GetRow();
			const Dimension &dimColR = dimsR.GetCol();
			size_t nBlks = nElemsL / nElemsR;
			size_t nMats = pArrayR->GetElemNum() / dimRowR.GetSizeProd();
			const T_ElemL *pElemBlkL = pElemL;
			for (size_t iBlk = 0; iBlk < nBlks; iBlk++, pElemBlkL += nElemsR) {
				const T_ElemL *pElemMatL = pElemBlkL;
				const T_ElemR *pElemMatR = pElemR;
				for (size_t iMat = 0; iMat < nMats; iMat++,
						 pElemMatL += dimRowL.GetSizeProd(), pElemMatR += dimRowR.GetSizeProd()) {
					const T_ElemL *pElemRowL = pElemMatL;
					const T_ElemR *pElemRowR = pElemMatR;
					for (size_t iRow = 0; iRow < dimRowL.GetSize(); iRow++,
							 pElemRowL += dimRowL.GetStrides(), pElemRowR += dimRowR.GetStrides()) {
						const T_ElemL *pElemColL = pElemRowL;
						const T_ElemR *pElemColR = pElemRowR;
						for (size_t iCol = 0; iCol < dimColL.GetSize(); iCol++,
								 pElemColL += dimColL.GetStrides(), pElemColR += dimColR.GetStrides()) {
							T_Operator::Calc(*pElemRtn, *pElemColL, *pElemColR);
							pElemRtn++;
						}
					}
				}
			}
		}
	}
	return true;
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR, typename T_Operator>
bool Array::BinaryFuncTmpl_array_scalar(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArrayL, const T_ElemR &elemR)
{
	const Dimensions &dimsL = pArrayL->GetDims();
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	if (pArrayRtn.IsNull()) pArrayRtn.reset(ArrayT<T_ElemRtn>::Create(dimsL));
	T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
	if (pArrayL->IsRowMajor() || dimsL.size() < 2) {
		size_t nElemsL = pArrayL->GetElemNum();
		for (size_t i = 0; i < nElemsL; i++, pElemL++) {
			T_Operator::Calc(*pElemRtn, *pElemL, elemR);
			pElemRtn++;
		}
	} else { // pArrayL->IsColMajor() && dimsL.size() >= 2
		const Dimension &dimRowL = dimsL.GetRow();
		const Dimension &dimColL = dimsL.GetCol();
		size_t nMats = pArrayL->GetElemNum() / dimRowL.GetSizeProd();
		const T_ElemL *pElemMatL = pElemL;
		for (size_t iMat = 0; iMat < nMats; iMat++, pElemMatL += dimRowL.GetSizeProd()) {
			const T_ElemL *pElemRowL = pElemMatL;
			for (size_t iRow = 0; iRow < dimRowL.GetSize(); iRow++,
					 pElemRowL += dimRowL.GetStrides()) {
				const T_ElemL *pElemColL = pElemRowL;
				for (size_t iCol = 0; iCol < dimColL.GetSize(); iCol++,
						 pElemColL += dimColL.GetStrides()) {
					T_Operator::Calc(*pElemRtn, *pElemColL, elemR);
					pElemRtn++;
				}
			}
		}
	}
	return true;
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR, typename T_Operator>
bool Array::BinaryFuncTmpl_scalar_array(Signal &sig, AutoPtr<Array> &pArrayRtn, const T_ElemL &elemL, const Array *pArrayR)
{
	const Dimensions &dimsR = pArrayR->GetDims();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	if (pArrayRtn.IsNull()) pArrayRtn.reset(ArrayT<T_ElemRtn>::Create(dimsR));
	T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
	if (pArrayR->IsRowMajor() || dimsR.size() < 2) {
		size_t nElemsR = pArrayR->GetElemNum();
		for (size_t i = 0; i < nElemsR; i++, pElemR++) {
			T_Operator::Calc(*pElemRtn, elemL, *pElemR);
			pElemRtn++;
		}
	} else { // pArrayR->IsColMajor() && dimsR.size() >= 2
		const Dimension &dimRowR = dimsR.GetRow();
		const Dimension &dimColR = dimsR.GetCol();
		size_t nMats = pArrayR->GetElemNum() / dimRowR.GetSizeProd();
		const T_ElemR *pElemMatR = pElemR;
		for (size_t iMat = 0; iMat < nMats; iMat++, pElemMatR += dimRowR.GetSizeProd()) {
			const T_ElemR *pElemRowR = pElemMatR;
			for (size_t iRow = 0; iRow < dimRowR.GetSize(); iRow++,
					 pElemRowR += dimRowR.GetStrides()) {
				const T_ElemR *pElemColR = pElemRowR;
				for (size_t iCol = 0; iCol < dimColR.GetSize(); iCol++,
						 pElemColR += dimColR.GetStrides()) {
					T_Operator::Calc(*pElemRtn, elemL, *pElemColR);
					pElemRtn++;
				}
			}
		}
	}
	return true;
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR, typename T_Operator>
bool Array::BinaryFuncTmpl_scalar_scalar(Signal &sig, AutoPtr<Array> &pArrayRtn, const T_ElemL &elemL, const T_ElemR &elemR)
{
	if (pArrayRtn.IsNull()) pArrayRtn.reset(ArrayT<T_ElemRtn>::CreateScalar(0));
	T_Operator::Calc(*dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer(), elemL, elemR);
	return true;
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR, typename T_Operator>
bool Array::BinaryFuncTmpl_Div_array_array(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArrayL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return false;
	}
	return BinaryFuncTmpl_array_array<T_ElemRtn, T_ElemL, T_ElemR, T_Operator>(sig, pArrayRtn, pArrayL, pArrayR);
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR, typename T_Operator>
bool Array::BinaryFuncTmpl_Div_array_scalar(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArrayL, const T_ElemR &elemR)
{
	if (IsZero(elemR)) {
		Operator::SetError_DivideByZero(sig);
		return false;
	}
	return BinaryFuncTmpl_array_scalar<T_ElemRtn, T_ElemL, T_ElemR, T_Operator>(sig, pArrayRtn, pArrayL, elemR);
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR, typename T_Operator>
bool Array::BinaryFuncTmpl_Div_scalar_array(Signal &sig, AutoPtr<Array> &pArrayRtn, const T_ElemL &elemL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return false;
	}
	return BinaryFuncTmpl_scalar_array<T_ElemRtn, T_ElemL, T_ElemR, T_Operator>(sig, pArrayRtn, elemL, pArrayR);
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR, typename T_Operator>
bool Array::BinaryFuncTmpl_Div_scalar_scalar(Signal &sig, AutoPtr<Array> &pArrayRtn, const T_ElemL &elemL, const T_ElemR &elemR)
{
	if (IsZero(elemR)) {
		Operator::SetError_DivideByZero(sig);
		return false;
	}
	return BinaryFuncTmpl_scalar_scalar<T_ElemRtn, T_ElemL, T_ElemR, T_Operator>(sig, pArrayRtn, elemL, elemR);
}

//------------------------------------------------------------------------------
// DotFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR>
void Array::DotFuncTmpl_1d_1d(T_ElemRtn *pElemRtn, const T_ElemL *pElemL, const T_ElemR *pElemR, size_t size)
{
	T_ElemRtn elemRtn = 0;
	for (size_t i = 0; i < size; i++, pElemL++, pElemR++) {
		elemRtn += static_cast<T_ElemRtn>(*pElemL) * static_cast<T_ElemRtn>(*pElemR);
	}
	*pElemRtn = elemRtn;
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR>
void Array::DotFuncTmpl_1d_2d(T_ElemRtn *pElemRtn,
					   const T_ElemL *pElemL, const Dimension &dimColL,
					   const T_ElemR *pElemR, const Dimension &dimRowR, const Dimension &dimColR)
{
	const T_ElemR *pElemColR = pElemR;
	for (size_t iColR = 0; iColR < dimColR.GetSize(); iColR++,
			 pElemColR += dimColR.GetStrides()) {
		const T_ElemL *pElemColL = pElemL;
		const T_ElemR *pElemRowR = pElemColR;
		T_ElemRtn elemRtn = 0;
		for (size_t iRowR = 0; iRowR < dimRowR.GetSize(); iRowR++,
				 pElemColL += dimColL.GetStrides(), pElemRowR += dimRowR.GetStrides()) {
			elemRtn += static_cast<T_ElemRtn>(*pElemColL) * static_cast<T_ElemRtn>(*pElemRowR);
		}
		*pElemRtn++ = elemRtn;
	}
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR>
void Array::DotFuncTmpl_2d_1d(T_ElemRtn *pElemRtn,
					   const T_ElemL *pElemL, const Dimension &dimRowL, const Dimension &dimColL,
					   const T_ElemR *pElemR, const Dimension &dimRowR)
{
	const T_ElemL *pElemRowL = pElemL;
	for (size_t iRowL = 0; iRowL < dimRowL.GetSize(); iRowL++,
			 pElemRowL += dimRowL.GetStrides()) {
		const T_ElemL *pElemColL = pElemRowL;
		const T_ElemR *pElemRowR = pElemR;
		T_ElemRtn elemRtn = 0;
		for (size_t iColL = 0; iColL < dimColL.GetSize(); iColL++,
				 pElemColL += dimColL.GetStrides(), pElemRowR += dimRowR.GetStrides()) {
			elemRtn += static_cast<T_ElemRtn>(*pElemColL) * static_cast<T_ElemRtn>(*pElemRowR);
		}
		*pElemRtn++ = elemRtn;
	}
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR>
void Array::DotFuncTmpl_2d_2d(T_ElemRtn *pElemRtn,
					   const T_ElemL *pElemL, const Dimension &dimRowL, const Dimension &dimColL,
					   const T_ElemR *pElemR, const Dimension &dimRowR, const Dimension &dimColR)
{
	const T_ElemL *pElemRowL = pElemL;
	for (size_t iRowL = 0; iRowL < dimRowL.GetSize(); iRowL++,
			 pElemRowL += dimRowL.GetStrides()) {
		const T_ElemR *pElemColR = pElemR;
		for (size_t iColR = 0; iColR < dimColR.GetSize(); iColR++,
				 pElemColR += dimColR.GetStrides()) {
			const T_ElemL *pElemColL = pElemRowL;
			const T_ElemR *pElemRowR = pElemColR;
			T_ElemRtn elemRtn = 0;
			for (size_t iColL = 0; iColL < dimColL.GetSize(); iColL++,
					 pElemColL += dimColL.GetStrides(), pElemRowR += dimRowR.GetStrides()) {
				elemRtn += static_cast<T_ElemRtn>(*pElemColL) * static_cast<T_ElemRtn>(*pElemRowR);
			}
			*pElemRtn++ = elemRtn;
		}
	}
}

template<typename T_ElemRtn, typename T_ElemL, typename T_ElemR>
bool Array::BinaryFuncTmpl_Dot(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArrayL, const Array *pArrayR)
{
	const Dimensions &dimsL = pArrayL->GetDims();
	const Dimensions &dimsR = pArrayR->GetDims();
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	if (dimsL.size() == 1 && dimsR.size() == 1) {
		const Dimension &dimL = dimsL.GetCol();
		const Dimension &dimR = dimsR.GetCol();
		if (dimL.GetSize() != dimR.GetSize()) goto error_done;
		if (pArrayRtn.IsNull()) pArrayRtn.reset(ArrayT<T_ElemRtn>::CreateScalar(0));
		T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
		DotFuncTmpl_1d_1d(pElemRtn, pElemL, pElemR, dimL.GetSize());
	} else if (dimsL.size() == 1 && dimsR.size() >= 2) {
		const Dimension &dimRowR = dimsR.GetRow();
		const Dimension &dimColL = dimsL.GetCol();
		const Dimension &dimColR = dimsR.GetCol();
		if (dimColL.GetSize() != dimRowR.GetSize()) goto error_done;
		size_t elemNumMatR = dimRowR.GetSizeProd();
		size_t elemNumRtn = dimColR.GetSize();
		size_t offsetR = 0;
		if (pArrayRtn.IsNull()) {
			pArrayRtn.reset(ArrayT<T_ElemRtn>::Create());
			pArrayRtn->SetDims(dimsR.begin(), dimsR.begin() + dimsR.size() - 2, elemNumRtn);
			pArrayRtn->AllocMemory();
		}
		T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
		while (offsetR < pArrayR->GetElemNum()) {
			DotFuncTmpl_1d_2d(pElemRtn, pElemL, dimColL, pElemR + offsetR, dimRowR, dimColR);
			pElemRtn += elemNumRtn;
			offsetR += elemNumMatR;
		}
	} else if (dimsL.size() >= 2 && dimsR.size() == 1) {
		const Dimension &dimRowL = dimsL.GetRow();
		const Dimension &dimColL = dimsL.GetCol();
		const Dimension &dimRowR = dimsR.GetCol();	// takes a column as a row
		if (dimColL.GetSize() != dimRowR.GetSize()) goto error_done;
		size_t elemNumMatL = dimRowL.GetSizeProd();
		size_t elemNumRtn = dimRowL.GetSize();
		size_t offsetL = 0;
		if (pArrayRtn.IsNull()) {
			pArrayRtn.reset(ArrayT<T_ElemRtn>::Create());
			pArrayRtn->SetDims(dimsL.begin(), dimsL.begin() + dimsL.size() - 2, elemNumRtn, 1);
			pArrayRtn->AllocMemory();
		}
		T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
		while (offsetL < pArrayL->GetElemNum()) {
			DotFuncTmpl_2d_1d(pElemRtn, pElemL + offsetL, dimRowL, dimColL, pElemR, dimRowR);
			pElemRtn += elemNumRtn;
			offsetL += elemNumMatL;
		}
	} else if (dimsL.size() == 2 && dimsR.size() == 2) {
		const Dimension &dimRowL = dimsL.GetRow();
		const Dimension &dimColL = dimsL.GetCol();
		const Dimension &dimRowR = dimsR.GetRow();
		const Dimension &dimColR = dimsR.GetCol();
		if (dimColL.GetSize() != dimRowR.GetSize()) goto error_done;
		if (pArrayRtn.IsNull()) {
			pArrayRtn.reset(ArrayT<T_ElemRtn>::Create2d(dimRowL.GetSize(), dimColR.GetSize()));
		}
		T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
		DotFuncTmpl_2d_2d(pElemRtn, pElemL, dimRowL, dimColL, pElemR, dimRowR, dimColR);
	} else { // dimsL.size() >= 2 && dimsR.size() >= 2
		const Dimension &dimRowL = dimsL.GetRow();
		const Dimension &dimColL = dimsL.GetCol();
		const Dimension &dimRowR = dimsR.GetRow();
		const Dimension &dimColR = dimsR.GetCol();
		if (dimColL.GetSize() != dimRowR.GetSize()) goto error_done;
		size_t elemNumMatRtn = dimRowL.GetSize() * dimColR.GetSize();
		size_t offsetL = 0, offsetR = 0;
		if (dimsL.size() < dimsR.size()) {
			if (pArrayRtn.IsNull()) {
				pArrayRtn.reset(ArrayT<T_ElemRtn>::Create());
				pArrayRtn->SetDims(dimsR.begin(), dimsR.begin() + dimsR.size() - 2,
										 dimRowL.GetSize(), dimColR.GetSize());
				pArrayRtn->AllocMemory();
			}
			T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
			while (offsetR < pArrayR->GetElemNum()) {
				DotFuncTmpl_2d_2d(pElemRtn, pElemL + offsetL, dimRowL, dimColL, pElemR + offsetR, dimRowR, dimColR);
				pElemRtn += elemNumMatRtn;
				offsetL += dimRowL.GetSizeProd();
				offsetR += dimRowR.GetSizeProd();
				if (offsetL >= pArrayL->GetElemNum()) offsetL = 0;
			}
		} else { // dimsL.size() >= dimsR.size()
			if (pArrayRtn.IsNull()) {
				pArrayRtn.reset(ArrayT<T_ElemRtn>::Create());
				pArrayRtn->SetDims(dimsL.begin(), dimsL.begin() + dimsL.size() - 2,
										 dimRowL.GetSize(), dimColR.GetSize());
				pArrayRtn->AllocMemory();
			}
			T_ElemRtn *pElemRtn = dynamic_cast<ArrayT<T_ElemRtn> *>(pArrayRtn.get())->GetPointer();
			while (offsetL < pArrayL->GetElemNum()) {
				DotFuncTmpl_2d_2d(pElemRtn, pElemL + offsetL, dimRowL, dimColL, pElemR + offsetR, dimRowR, dimColR);
				pElemRtn += elemNumMatRtn;
				offsetL += dimRowL.GetSizeProd();
				offsetR += dimRowR.GetSizeProd();
				if (offsetR >= pArrayR->GetElemNum()) offsetR = 0;
			}
		}
	}
	return true;
error_done:
	sig.SetError(ERR_ValueError,
				 "failed in array calculation: (%s) |.| (%s)",
				 pArrayL->GetDims().ToString().c_str(),
				 pArrayR->GetDims().ToString().c_str());
	return false;
}

}

#endif
