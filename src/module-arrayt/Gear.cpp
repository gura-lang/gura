//=============================================================================
// Gear.cpp
// Implementation of gear functions.
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
// GearFuncTmpl_Conv1d
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, typename T_ElemGear>
bool GearFuncTmpl_Conv1d(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Gear_Conv1d *pGear)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	pArrayRtn.reset(ArrayT<T_Elem>::Create(dims));
	return true;
}

//------------------------------------------------------------------------------
// GearFuncTmpl_Conv2d
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, typename T_ElemGear>
bool GearFuncTmpl_Conv2d(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Gear_Conv2d *pGear)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	pArrayRtn.reset(ArrayT<T_Elem>::Create(dims));
	return true;
}

//------------------------------------------------------------------------------
// GearFuncTmpl_Conv3d
//------------------------------------------------------------------------------
template<typename T_ElemRtn, typename T_Elem, typename T_ElemGear>
bool GearFuncTmpl_Conv3d(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Gear_Conv3d *pGear)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	pArrayRtn.reset(ArrayT<T_Elem>::Create(dims));
	return true;
}

//------------------------------------------------------------------------------
// GearFuncTmpl_Relu
//------------------------------------------------------------------------------
template<typename T_Elem>
bool GearFuncTmpl_Relu(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Gear_Relu *pGear)
{
	return Array::ApplyUnaryFunc(sig, Array::unaryFuncPack_Math_relu, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// GearFuncTmpl_Sigmoid
//------------------------------------------------------------------------------
template<typename T_Elem>
bool GearFuncTmpl_Sigmoid(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Gear_Sigmoid *pGear)
{
	return Array::ApplyUnaryFunc(sig, Array::unaryFuncPack_Math_sigmoid, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// GearFuncTmpl_Softmax
//------------------------------------------------------------------------------
template<typename T_Elem>
bool GearFuncTmpl_Softmax(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Gear_Softmax *pGear)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	size_t axis = pGear->GetAxis();
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
// GearFuncTmpl_Tanh
//------------------------------------------------------------------------------
template<typename T_Elem>
bool GearFuncTmpl_Tanh(Signal &sig, AutoPtr<Array> &pArrayRtn, const Array *pArray, const Gear_Tanh *pGear)
{
	return Array::ApplyUnaryFunc(sig, Array::unaryFuncPack_Math_tanh, pArrayRtn, pArray);
}

//------------------------------------------------------------------------------
// Function tables
//------------------------------------------------------------------------------
Gear_Conv1d::GearFuncTable g_GearFuncTable_Conv1d = {
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
			&GearFuncTmpl_Conv1d<Half,		Half,		Half	>,
			&GearFuncTmpl_Conv1d<Half,		Half,		Float	>,
			&GearFuncTmpl_Conv1d<Half,		Half,		Double	>,
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
			&GearFuncTmpl_Conv1d<Float,		Float,		Half	>,
			&GearFuncTmpl_Conv1d<Float,		Float,		Float	>,
			&GearFuncTmpl_Conv1d<Float,		Float,		Double	>,
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
			&GearFuncTmpl_Conv1d<Double,		Double,		Half	>,
			&GearFuncTmpl_Conv1d<Double,		Double,		Float	>,
			&GearFuncTmpl_Conv1d<Double,		Double,		Double	>,
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

Gear_Conv2d::GearFuncTable g_GearFuncTable_Conv2d = {
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
			&GearFuncTmpl_Conv2d<Half,		Half,		Half	>,
			&GearFuncTmpl_Conv2d<Half,		Half,		Float	>,
			&GearFuncTmpl_Conv2d<Half,		Half,		Double	>,
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
			&GearFuncTmpl_Conv2d<Float,		Float,		Half	>,
			&GearFuncTmpl_Conv2d<Float,		Float,		Float	>,
			&GearFuncTmpl_Conv2d<Float,		Float,		Double	>,
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
			&GearFuncTmpl_Conv2d<Double,		Double,		Half	>,
			&GearFuncTmpl_Conv2d<Double,		Double,		Float	>,
			&GearFuncTmpl_Conv2d<Double,		Double,		Double	>,
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

Gear_Conv3d::GearFuncTable g_GearFuncTable_Conv3d = {
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
			&GearFuncTmpl_Conv3d<Half,		Half,		Half	>,
			&GearFuncTmpl_Conv3d<Half,		Half,		Float	>,
			&GearFuncTmpl_Conv3d<Half,		Half,		Double	>,
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
			&GearFuncTmpl_Conv3d<Float,		Float,		Half	>,
			&GearFuncTmpl_Conv3d<Float,		Float,		Float	>,
			&GearFuncTmpl_Conv3d<Float,		Float,		Double	>,
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
			&GearFuncTmpl_Conv3d<Double,		Double,		Half	>,
			&GearFuncTmpl_Conv3d<Double,		Double,		Float	>,
			&GearFuncTmpl_Conv3d<Double,		Double,		Double	>,
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

Gear_Relu::GearFuncTable g_GearFuncTable_Relu = {
	{
		nullptr,
		&GearFuncTmpl_Relu<Boolean>,
		&GearFuncTmpl_Relu<Int8>,
		&GearFuncTmpl_Relu<UInt8>,
		&GearFuncTmpl_Relu<Int16>,
		&GearFuncTmpl_Relu<UInt16>,
		&GearFuncTmpl_Relu<Int32>,
		&GearFuncTmpl_Relu<UInt32>,
		&GearFuncTmpl_Relu<Int64>,
		&GearFuncTmpl_Relu<UInt64>,
		&GearFuncTmpl_Relu<Half>,
		&GearFuncTmpl_Relu<Float>,
		&GearFuncTmpl_Relu<Double>,
		nullptr,
		nullptr,
	}
};

Gear_Sigmoid::GearFuncTable g_GearFuncTable_Sigmoid = {
	{
		nullptr,
		&GearFuncTmpl_Sigmoid<Boolean>,
		&GearFuncTmpl_Sigmoid<Int8>,
		&GearFuncTmpl_Sigmoid<UInt8>,
		&GearFuncTmpl_Sigmoid<Int16>,
		&GearFuncTmpl_Sigmoid<UInt16>,
		&GearFuncTmpl_Sigmoid<Int32>,
		&GearFuncTmpl_Sigmoid<UInt32>,
		&GearFuncTmpl_Sigmoid<Int64>,
		&GearFuncTmpl_Sigmoid<UInt64>,
		&GearFuncTmpl_Sigmoid<Half>,
		&GearFuncTmpl_Sigmoid<Float>,
		&GearFuncTmpl_Sigmoid<Double>,
		nullptr,
		nullptr,
	}
};

Gear_Softmax::GearFuncTable g_GearFuncTable_Softmax = {
	{
		nullptr,
		&GearFuncTmpl_Softmax<Boolean>,
		&GearFuncTmpl_Softmax<Int8>,
		&GearFuncTmpl_Softmax<UInt8>,
		&GearFuncTmpl_Softmax<Int16>,
		&GearFuncTmpl_Softmax<UInt16>,
		&GearFuncTmpl_Softmax<Int32>,
		&GearFuncTmpl_Softmax<UInt32>,
		&GearFuncTmpl_Softmax<Int64>,
		&GearFuncTmpl_Softmax<UInt64>,
		&GearFuncTmpl_Softmax<Half>,
		&GearFuncTmpl_Softmax<Float>,
		&GearFuncTmpl_Softmax<Double>,
		nullptr,
		nullptr,
	}
};

Gear_Tanh::GearFuncTable g_GearFuncTable_Tanh = {
	{
		nullptr,
		&GearFuncTmpl_Tanh<Boolean>,
		&GearFuncTmpl_Tanh<Int8>,
		&GearFuncTmpl_Tanh<UInt8>,
		&GearFuncTmpl_Tanh<Int16>,
		&GearFuncTmpl_Tanh<UInt16>,
		&GearFuncTmpl_Tanh<Int32>,
		&GearFuncTmpl_Tanh<UInt32>,
		&GearFuncTmpl_Tanh<Int64>,
		&GearFuncTmpl_Tanh<UInt64>,
		&GearFuncTmpl_Tanh<Half>,
		&GearFuncTmpl_Tanh<Float>,
		&GearFuncTmpl_Tanh<Double>,
		nullptr,
		nullptr,
	}
};

void AssignGears(Environment &env)
{
	Gear_Conv1d::gearFuncTable =			g_GearFuncTable_Conv1d;
	Gear_Conv2d::gearFuncTable =			g_GearFuncTable_Conv2d;
	Gear_Conv3d::gearFuncTable =			g_GearFuncTable_Conv3d;
	Gear_Relu::gearFuncTable =				g_GearFuncTable_Relu;
	Gear_Sigmoid::gearFuncTable =			g_GearFuncTable_Sigmoid;
	Gear_Softmax::gearFuncTable =			g_GearFuncTable_Softmax;
	Gear_Tanh::gearFuncTable =				g_GearFuncTable_Tanh;
}

Gura_EndModuleScope(arrayt)
