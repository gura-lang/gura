//=============================================================================
// Filter.cpp
// Implementation of filter functions.
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(arrayt)

//------------------------------------------------------------------------------
// PairFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemRtnA, typename T_ElemRtnB,
		 typename T_Elem, void (*op)(T_ElemRtnA &, T_ElemRtnB &, const T_Elem &)>
void PairFuncTmpl(Signal &sig, Array **ppArrayRtnA, Array **ppArrayRtnB, const Array *pArray)
{
	const Array::Dimensions &dims = pArray->GetDimensions();
	AutoPtr<ArrayT<T_ElemRtnA> > pArrayTRtnA(
		(*ppArrayRtnA == nullptr)? ArrayT<T_ElemRtnA>::Create(dims) :
		dynamic_cast<ArrayT<T_ElemRtnA> *>((*ppArrayRtnA)->Reference()));
	AutoPtr<ArrayT<T_ElemRtnB> > pArrayTRtnB(
		(*ppArrayRtnB == nullptr)? ArrayT<T_ElemRtnB>::Create(dims) :
		dynamic_cast<ArrayT<T_ElemRtnB> *>((*ppArrayRtnB)->Reference()));
	T_ElemRtnA *pElemRtnA = pArrayTRtnA->GetPointer();
	T_ElemRtnB *pElemRtnB = pArrayTRtnB->GetPointer();
	const T_Elem *pElem = dynamic_cast<const ArrayT<T_Elem> *>(pArray)->GetPointer();
	if (pArray->IsRowMajor() || dims.size() < 2) {
		size_t nElems = pArray->GetElemNum();
		for (size_t i = 0; i < nElems; i++, pElem++) {
			op(*pElemRtnA, *pElemRtnB, *pElem);
			pElemRtnA++, pElemRtnB++;
		}
	} else { // pArray->IsColMajor() && dims.size() >= 2
		const Array::Dimension &dimRow = dims.GetRow();
		const Array::Dimension &dimCol = dims.GetCol();
		size_t nMats = pArray->GetElemNum() / dimRow.GetSizeProd();
		const T_Elem *pElemMat = pElem;
		for (size_t iMat = 0; iMat < nMats; iMat++, pElemMat += dimRow.GetSizeProd()) {
			const T_Elem *pElemRow = pElemMat;
			for (size_t iRow = 0; iRow < dimRow.GetSize(); iRow++,
					 pElemRow += dimRow.GetStrides()) {
				const T_Elem *pElemCol = pElemRow;
				for (size_t iCol = 0; iCol < dimCol.GetSize(); iCol++,
						 pElemCol += dimCol.GetStrides()) {
					op(*pElemRtnA, *pElemRtnB, *pElemCol);
					pElemRtnA++, pElemRtnB++;
				}
			}
		}
	}
	*ppArrayRtnA = pArrayTRtnA.release();
	*ppArrayRtnB = pArrayTRtnB.release();
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Conv1d
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, typename T_ElemFilter>
bool FilterFuncTmpl_Conv1d(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Filter_Conv1d *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	pArrayRtn.reset(ArrayT<T_Elem>::Create(dims));
	return true;
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Conv2d
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, typename T_ElemFilter>
bool FilterFuncTmpl_Conv2d(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Filter_Conv2d *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	pArrayRtn.reset(ArrayT<T_Elem>::Create(dims));
	return true;
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Conv3d
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, typename T_ElemFilter>
bool FilterFuncTmpl_Conv3d(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Filter_Conv3d *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	pArrayRtn.reset(ArrayT<T_Elem>::Create(dims));
	return true;
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_MaxPool1d
//------------------------------------------------------------------------------
template<typename T_Elem>
bool FilterFuncTmpl_MaxPool1d(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Filter_MaxPool1d *pFilter)
{
	size_t sizeFilter = pFilter->GetSize();
	size_t strides = pFilter->GetStrides();
	Filter::PaddingType paddingType = pFilter->GetPaddingType();
	Filter::ChannelAt channelAt = pFilter->GetChannelAt();
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	size_t nDims = dims.size();
	if (channelAt == Filter::CHANNELAT_First || nDims < 2) {
		const Array::Dimension &dimCol = dims[nDims - 1];
		size_t sizeIn = dimCol.GetSize();
		size_t sizeOut = 0, sizePadHead = 0, sizePadTail = 0;
		Filter::CalcPadding(sizeIn, sizeFilter, strides, paddingType, &sizeOut, &sizePadHead, &sizePadTail);
		if (nDims < 2) {
			pArrayRtn.reset(ArrayT<T_Elem>::Create1d(sizeOut));
		} else {
			pArrayRtn.reset(ArrayT<T_Elem>::Create());
			pArrayRtn->SetDimensions(dims.begin(), dims.begin() + nDims - 1, sizeOut);
			pArrayRtn->AllocMemory();
		}
		const T_Elem *pElemSrc = pArrayT->GetPointer();
		T_Elem *pElemRtn = dynamic_cast<ArrayT<T_Elem> *>(pArrayRtn.get())->GetPointer();
		size_t cnt = pArray->GetElemNum() / sizeIn;
		for (size_t j = 0; j < cnt; j++) {
			for (size_t i = 0; i < sizeOut; i++) {
				size_t colBegin = i * strides;
				size_t colEnd = colBegin + sizeFilter;
				if (colBegin < sizePadHead) {
					colBegin = 0;
					colEnd -= sizePadHead - colBegin;
				} else {
					colBegin -= sizePadHead;
					colEnd -= sizePadHead;
				}
				if (colEnd > sizeIn) colEnd = sizeIn;
				const T_Elem *pElemSrcWk = pElemSrc + colBegin;
				bool firstFlag = true;
				T_Elem numMax = 0;
				for (size_t col = colBegin; col < colEnd; col++, pElemSrcWk++) {
					if (firstFlag || numMax < *pElemSrcWk) {
						firstFlag = false;
						numMax = *pElemSrcWk;
					}
				}
				*(pElemRtn + i) = numMax;
			}
			pElemSrc += sizeIn;
			pElemRtn += sizeOut;
		}
	} else {
		const Array::Dimension &dimChannel = dims[nDims - 1];
		const Array::Dimension &dimCol = dims[nDims - 2];
		size_t sizeIn = dimCol.GetSize();
		size_t sizeChannel = dimChannel.GetSize();
		size_t sizeOut = 0, sizePadHead = 0, sizePadTail = 0;
		Filter::CalcPadding(sizeIn, sizeFilter, strides, paddingType, &sizeOut, &sizePadHead, &sizePadTail);
		pArrayRtn.reset(ArrayT<T_Elem>::Create());
		pArrayRtn->SetDimensions(dims.begin(), dims.begin() + nDims - 2, sizeOut, sizeChannel);
		pArrayRtn->AllocMemory();
		const T_Elem *pElemSrc = pArrayT->GetPointer();
		T_Elem *pElemRtn = dynamic_cast<ArrayT<T_Elem> *>(pArrayRtn.get())->GetPointer();
		size_t cnt = pArray->GetElemNum() / (sizeIn * sizeChannel);
		for (size_t j = 0; j < cnt; j++) {
			for (size_t i = 0; i < sizeOut; i++) {
				size_t colBegin = i * strides;
				size_t colEnd = colBegin + sizeFilter;
				if (colBegin < sizePadHead) {
					colBegin = 0;
					colEnd -= sizePadHead - colBegin;
				} else {
					colBegin -= sizePadHead;
					colEnd -= sizePadHead;
				}
				if (colEnd > sizeIn) colEnd = sizeIn;
				for (size_t iChannel = 0; iChannel < sizeChannel; iChannel++) {
					const T_Elem *pElemSrcWk = pElemSrc + colBegin * sizeChannel + iChannel;
					bool firstFlag = true;
					T_Elem numMax = 0;
					for (size_t col = colBegin; col < colEnd; col++, pElemSrcWk += sizeChannel) {
						if (firstFlag || numMax < *pElemSrcWk) {
							firstFlag = false;
							numMax = *pElemSrcWk;
						}
					}
					*(pElemRtn + i * sizeChannel + iChannel) = numMax;
				}
			}
			pElemSrc += sizeIn * sizeChannel;
			pElemRtn += sizeOut * sizeChannel;
		}
	}		
	return true;
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_MaxPool2d
//------------------------------------------------------------------------------
template<typename T_Elem>
bool FilterFuncTmpl_MaxPool2d(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Filter_MaxPool2d *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	pArrayRtn.reset(ArrayT<T_Elem>::Create(dims));
	return true;
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_MaxPool3d
//------------------------------------------------------------------------------
template<typename T_Elem>
bool FilterFuncTmpl_MaxPool3d(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Filter_MaxPool3d *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	pArrayRtn.reset(ArrayT<T_Elem>::Create(dims));
	return true;
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Relu
//------------------------------------------------------------------------------
template<typename T_Elem>
bool FilterFuncTmpl_Relu(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Filter_Relu *pFilter)
{
	return Array::ApplyUnaryFunc(sig, Array::unaryFuncPack_Math_relu, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Sigmoid
//------------------------------------------------------------------------------
template<typename T_Elem>
bool FilterFuncTmpl_Sigmoid(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Filter_Sigmoid *pFilter)
{
	return Array::ApplyUnaryFunc(sig, Array::unaryFuncPack_Math_sigmoid, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Softmax
//------------------------------------------------------------------------------
template<typename T_Elem>
bool FilterFuncTmpl_Softmax(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Filter_Softmax *pFilter)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	size_t axis = pFilter->GetAxis();
	if (axis > dims.size() - 1) axis = dims.size() - 1;
	Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
	if (pArrayRtn.IsNull()) pArrayRtn.reset(ArrayT<T_Elem>::Create(dims));
	pArrayRtn->FillZero();
	const T_Elem *pElemTop = pArrayT->GetPointer();
	T_Elem *pElemRtn = dynamic_cast<ArrayT<T_Elem> *>(pArrayRtn.get())->GetPointer();
	if (pDimAxis + 1 == dims.end()) {
		size_t axisSize = pDimAxis->GetSize();
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += axisSize) {
			const T_Elem *pElemHead = pElemTop + offset;
			T_Elem *pElemRtnHead = pElemRtn + offset;
			T_Elem numMax = 0;
			do {
				const T_Elem *pElemWk = pElemHead;
				numMax = *pElemWk;
				pElemWk++;
				for (size_t i = 1; i < axisSize; i++, pElemWk++) {
					if (numMax < *pElemWk) numMax = *pElemWk;
				}
			} while (0);
			T_Elem numSum = 0;
			do {
				const T_Elem *pElemWk = pElemHead;
				T_Elem *pElemRtnWk = pElemRtnHead;
				for (size_t i = 0; i < axisSize; i++, pElemWk++, pElemRtnWk++) {
					//T_Elem num = *pElemWk;
					T_Elem num = static_cast<T_Elem>(::exp(static_cast<Double>(*pElemWk - numMax)));
					*pElemRtnWk = num;
					numSum += num;
				}
			} while (0);
			do {
				const T_Elem *pElemWk = pElemHead;
				T_Elem *pElemRtnWk = pElemRtnHead;
				for (size_t i = 0; i < axisSize; i++, pElemWk++, pElemRtnWk++) {
					*pElemRtnWk /= numSum;
				}
			} while (0);
		}
	} else {
		size_t strides = pDimAxis->GetStrides();
		size_t axisSize = pDimAxis->GetSize();
		size_t stepSize = pDimAxis->GetSize() * strides;
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += stepSize) {
			for (size_t j = 0; j < strides; j++) {
				const T_Elem *pElemHead = pElemTop + offset + j;
				T_Elem *pElemRtnHead = pElemRtn + offset + j;
				T_Elem numMax = 0;
				do {
					const T_Elem *pElemWk = pElemHead;
					numMax = *pElemWk;
					pElemWk += strides;
					for (size_t i = 1; i < axisSize; i++, pElemWk += strides) {
						if (numMax < *pElemWk) numMax = *pElemWk;
					}
				} while (0);
				T_Elem numSum = 0;
				do {
					const T_Elem *pElemWk = pElemHead;
					T_Elem *pElemRtnWk = pElemRtnHead;
					for (size_t i = 0; i < axisSize; i++, pElemWk += strides, pElemRtnWk += strides) {
						//T_Elem num = *pElemWk;
						T_Elem num = static_cast<T_Elem>(::exp(static_cast<Double>(*pElemWk - numMax)));
						*pElemRtnWk = num;
						numSum += num;
					}
				} while (0);
				do {
					const T_Elem *pElemWk = pElemHead;
					T_Elem *pElemRtnWk = pElemRtnHead;
					for (size_t i = 0; i < axisSize; i++, pElemWk += strides, pElemRtnWk += strides) {
						*pElemRtnWk /= numSum;
					}
				} while (0);
			}
		}
	}
	return true;
}

//------------------------------------------------------------------------------
// FilterFuncTmpl_Tanh
//------------------------------------------------------------------------------
template<typename T_Elem>
bool FilterFuncTmpl_Tanh(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Filter_Tanh *pFilter)
{
	return Array::ApplyUnaryFunc(sig, Array::unaryFuncPack_Math_tanh, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// Function tables
//------------------------------------------------------------------------------
Filter_Conv1d::FilterFuncTable g_FilterFuncTable_Conv1d = {
	{
		{ // None |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Boolean |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int64 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Half |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv1d<Half,		Half,		Half	>,
			&FilterFuncTmpl_Conv1d<Half,		Half,		Float	>,
			&FilterFuncTmpl_Conv1d<Half,		Half,		Double	>,
			nullptr,
			nullptr,
		}, { // Float |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv1d<Float,		Float,		Half	>,
			&FilterFuncTmpl_Conv1d<Float,		Float,		Float	>,
			&FilterFuncTmpl_Conv1d<Float,		Float,		Double	>,
			nullptr,
			nullptr,
		}, { // Double |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv1d<Double,		Double,		Half	>,
			&FilterFuncTmpl_Conv1d<Double,		Double,		Float	>,
			&FilterFuncTmpl_Conv1d<Double,		Double,		Double	>,
			nullptr,
			nullptr,
		}, { // Complex |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // reserved1 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}
	}
};

Filter_Conv2d::FilterFuncTable g_FilterFuncTable_Conv2d = {
	{
		{ // None |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Boolean |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int64 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Half |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv2d<Half,		Half,		Half	>,
			&FilterFuncTmpl_Conv2d<Half,		Half,		Float	>,
			&FilterFuncTmpl_Conv2d<Half,		Half,		Double	>,
			nullptr,
			nullptr,
		}, { // Float |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv2d<Float,		Float,		Half	>,
			&FilterFuncTmpl_Conv2d<Float,		Float,		Float	>,
			&FilterFuncTmpl_Conv2d<Float,		Float,		Double	>,
			nullptr,
			nullptr,
		}, { // Double |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv2d<Double,		Double,		Half	>,
			&FilterFuncTmpl_Conv2d<Double,		Double,		Float	>,
			&FilterFuncTmpl_Conv2d<Double,		Double,		Double	>,
			nullptr,
			nullptr,
		}, { // Complex |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // reserved1 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}
	}
};

Filter_Conv3d::FilterFuncTable g_FilterFuncTable_Conv3d = {
	{
		{ // None |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Boolean |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt8 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt16 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // UInt32 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Int64 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // Half |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv3d<Half,		Half,		Half	>,
			&FilterFuncTmpl_Conv3d<Half,		Half,		Float	>,
			&FilterFuncTmpl_Conv3d<Half,		Half,		Double	>,
			nullptr,
			nullptr,
		}, { // Float |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv3d<Float,		Float,		Half	>,
			&FilterFuncTmpl_Conv3d<Float,		Float,		Float	>,
			&FilterFuncTmpl_Conv3d<Float,		Float,		Double	>,
			nullptr,
			nullptr,
		}, { // Double |*| any
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			nullptr,
			&FilterFuncTmpl_Conv3d<Double,		Double,		Half	>,
			&FilterFuncTmpl_Conv3d<Double,		Double,		Float	>,
			&FilterFuncTmpl_Conv3d<Double,		Double,		Double	>,
			nullptr,
			nullptr,
		}, { // Complex |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, { // reserved1 |*| any
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}
	}
};

Filter_MaxPool1d::FilterFuncTable g_FilterFuncTable_MaxPool1d = {
	{
		nullptr,
		&FilterFuncTmpl_MaxPool1d<Boolean>,
		&FilterFuncTmpl_MaxPool1d<Int8>,
		&FilterFuncTmpl_MaxPool1d<UInt8>,
		&FilterFuncTmpl_MaxPool1d<Int16>,
		&FilterFuncTmpl_MaxPool1d<UInt16>,
		&FilterFuncTmpl_MaxPool1d<Int32>,
		&FilterFuncTmpl_MaxPool1d<UInt32>,
		&FilterFuncTmpl_MaxPool1d<Int64>,
		&FilterFuncTmpl_MaxPool1d<UInt64>,
		&FilterFuncTmpl_MaxPool1d<Half>,
		&FilterFuncTmpl_MaxPool1d<Float>,
		&FilterFuncTmpl_MaxPool1d<Double>,
		nullptr,
		nullptr,
	}
};

Filter_MaxPool2d::FilterFuncTable g_FilterFuncTable_MaxPool2d = {
	{
		nullptr,
		&FilterFuncTmpl_MaxPool2d<Boolean>,
		&FilterFuncTmpl_MaxPool2d<Int8>,
		&FilterFuncTmpl_MaxPool2d<UInt8>,
		&FilterFuncTmpl_MaxPool2d<Int16>,
		&FilterFuncTmpl_MaxPool2d<UInt16>,
		&FilterFuncTmpl_MaxPool2d<Int32>,
		&FilterFuncTmpl_MaxPool2d<UInt32>,
		&FilterFuncTmpl_MaxPool2d<Int64>,
		&FilterFuncTmpl_MaxPool2d<UInt64>,
		&FilterFuncTmpl_MaxPool2d<Half>,
		&FilterFuncTmpl_MaxPool2d<Float>,
		&FilterFuncTmpl_MaxPool2d<Double>,
		nullptr,
		nullptr,
	}
};

Filter_MaxPool3d::FilterFuncTable g_FilterFuncTable_MaxPool3d = {
	{
		nullptr,
		&FilterFuncTmpl_MaxPool3d<Boolean>,
		&FilterFuncTmpl_MaxPool3d<Int8>,
		&FilterFuncTmpl_MaxPool3d<UInt8>,
		&FilterFuncTmpl_MaxPool3d<Int16>,
		&FilterFuncTmpl_MaxPool3d<UInt16>,
		&FilterFuncTmpl_MaxPool3d<Int32>,
		&FilterFuncTmpl_MaxPool3d<UInt32>,
		&FilterFuncTmpl_MaxPool3d<Int64>,
		&FilterFuncTmpl_MaxPool3d<UInt64>,
		&FilterFuncTmpl_MaxPool3d<Half>,
		&FilterFuncTmpl_MaxPool3d<Float>,
		&FilterFuncTmpl_MaxPool3d<Double>,
		nullptr,
		nullptr,
	}
};

Filter_Relu::FilterFuncTable g_FilterFuncTable_Relu = {
	{
		nullptr,
		&FilterFuncTmpl_Relu<Boolean>,
		&FilterFuncTmpl_Relu<Int8>,
		&FilterFuncTmpl_Relu<UInt8>,
		&FilterFuncTmpl_Relu<Int16>,
		&FilterFuncTmpl_Relu<UInt16>,
		&FilterFuncTmpl_Relu<Int32>,
		&FilterFuncTmpl_Relu<UInt32>,
		&FilterFuncTmpl_Relu<Int64>,
		&FilterFuncTmpl_Relu<UInt64>,
		&FilterFuncTmpl_Relu<Half>,
		&FilterFuncTmpl_Relu<Float>,
		&FilterFuncTmpl_Relu<Double>,
		nullptr,
		nullptr,
	}
};

Filter_Sigmoid::FilterFuncTable g_FilterFuncTable_Sigmoid = {
	{
		nullptr,
		&FilterFuncTmpl_Sigmoid<Boolean>,
		&FilterFuncTmpl_Sigmoid<Int8>,
		&FilterFuncTmpl_Sigmoid<UInt8>,
		&FilterFuncTmpl_Sigmoid<Int16>,
		&FilterFuncTmpl_Sigmoid<UInt16>,
		&FilterFuncTmpl_Sigmoid<Int32>,
		&FilterFuncTmpl_Sigmoid<UInt32>,
		&FilterFuncTmpl_Sigmoid<Int64>,
		&FilterFuncTmpl_Sigmoid<UInt64>,
		&FilterFuncTmpl_Sigmoid<Half>,
		&FilterFuncTmpl_Sigmoid<Float>,
		&FilterFuncTmpl_Sigmoid<Double>,
		nullptr,
		nullptr,
	}
};

Filter_Softmax::FilterFuncTable g_FilterFuncTable_Softmax = {
	{
		nullptr,
		&FilterFuncTmpl_Softmax<Boolean>,
		&FilterFuncTmpl_Softmax<Int8>,
		&FilterFuncTmpl_Softmax<UInt8>,
		&FilterFuncTmpl_Softmax<Int16>,
		&FilterFuncTmpl_Softmax<UInt16>,
		&FilterFuncTmpl_Softmax<Int32>,
		&FilterFuncTmpl_Softmax<UInt32>,
		&FilterFuncTmpl_Softmax<Int64>,
		&FilterFuncTmpl_Softmax<UInt64>,
		&FilterFuncTmpl_Softmax<Half>,
		&FilterFuncTmpl_Softmax<Float>,
		&FilterFuncTmpl_Softmax<Double>,
		nullptr,
		nullptr,
	}
};

Filter_Tanh::FilterFuncTable g_FilterFuncTable_Tanh = {
	{
		nullptr,
		&FilterFuncTmpl_Tanh<Boolean>,
		&FilterFuncTmpl_Tanh<Int8>,
		&FilterFuncTmpl_Tanh<UInt8>,
		&FilterFuncTmpl_Tanh<Int16>,
		&FilterFuncTmpl_Tanh<UInt16>,
		&FilterFuncTmpl_Tanh<Int32>,
		&FilterFuncTmpl_Tanh<UInt32>,
		&FilterFuncTmpl_Tanh<Int64>,
		&FilterFuncTmpl_Tanh<UInt64>,
		&FilterFuncTmpl_Tanh<Half>,
		&FilterFuncTmpl_Tanh<Float>,
		&FilterFuncTmpl_Tanh<Double>,
		nullptr,
		nullptr,
	}
};

void AssignFilters(Environment &env)
{
	Filter_Conv1d::filterFuncTable =			g_FilterFuncTable_Conv1d;
	Filter_Conv2d::filterFuncTable =			g_FilterFuncTable_Conv2d;
	Filter_Conv3d::filterFuncTable =			g_FilterFuncTable_Conv3d;
	Filter_MaxPool1d::filterFuncTable =			g_FilterFuncTable_MaxPool1d;
	Filter_MaxPool2d::filterFuncTable =			g_FilterFuncTable_MaxPool2d;
	Filter_MaxPool3d::filterFuncTable =			g_FilterFuncTable_MaxPool3d;
	Filter_Relu::filterFuncTable =				g_FilterFuncTable_Relu;
	Filter_Sigmoid::filterFuncTable =			g_FilterFuncTable_Sigmoid;
	Filter_Softmax::filterFuncTable =			g_FilterFuncTable_Softmax;
	Filter_Tanh::filterFuncTable =				g_FilterFuncTable_Tanh;
}

Gura_EndModuleScope(arrayt)
